#include "PRinternal/macros.h"
#include "PR/os_internal.h"
#include "PRinternal/controller.h"

s32 corrupted_init(OSPfs* pfs, __OSInodeCache* cache);
s32 corrupted(OSPfs* pfs, __OSInodeUnit fpage, __OSInodeCache* cache);

#define CHECK_IPAGE(p)                                                                                        \
    (((p).ipage >= pfs->inode_start_page) && ((p).inode_t.bank < pfs->banks) && ((p).inode_t.page >= 0x01) && \
     ((p).inode_t.page < 0x80))

s32 osPfsChecker(OSPfs* pfs) {
    int j;
    s32 ret;
    __OSInodeUnit next_page;
    __OSInode checked_inode;
    __OSInode tmp_inode;
    __OSDir tmp_dir;
    __OSInodeUnit file_next_node[16];
    __OSInodeCache cache;
    int fixed = 0;
    u8 bank;
#if BUILD_VERSION >= VERSION_J
    u8 oldbank = 254;
#endif
    s32 cc;
    s32 cl;
    int offset;

    ret = __osCheckId(pfs);

    if (ret == PFS_ERR_NEW_PACK) {
        ret = __osGetId(pfs);
    }

    if (ret != 0) {
        return ret;
    }

    ERRCK(corrupted_init(pfs, &cache));

    for (j = 0; j < pfs->dir_size; j++) {
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, pfs->dir_table + j, (u8*)&tmp_dir));

#if BUILD_VERSION >= VERSION_J
        if (tmp_dir.company_code != 0 || tmp_dir.game_code != 0) {
            if (tmp_dir.company_code == 0 || tmp_dir.game_code == 0) {
                cc = -1;
            } else {
                next_page = tmp_dir.start_page;
                cl = cc = 0;
                bank = 255;

                while (CHECK_IPAGE(next_page)) {
                    if (bank != next_page.inode_t.bank) {
                        bank = next_page.inode_t.bank;

                        if (oldbank != bank) {
                            ret = __osPfsRWInode(pfs, &tmp_inode, PFS_READ, bank);
                            oldbank = bank;
                        }

                        if (ret != 0 && ret != PFS_ERR_INCONSISTENT) {
                            return ret;
                        }
                    }

                    if ((cc = corrupted(pfs, next_page, &cache) - cl) != 0) {
                        break;
                    }

                    cl = 1;
                    next_page = tmp_inode.inode_page[next_page.inode_t.page];
                }
            }

            if (cc != 0 || next_page.ipage != PFS_EOF) {
                bzero(&tmp_dir, sizeof(__OSDir));

                SET_ACTIVEBANK_TO_ZERO();
                ERRCK(__osContRamWrite(pfs->queue, pfs->channel, pfs->dir_table + j, (u8*)&tmp_dir, FALSE));
                fixed++;
            }
        }
#else
        if (tmp_dir.company_code != 0 && tmp_dir.game_code != 0) {
            next_page = tmp_dir.start_page;
            cl = cc = 0;
            bank = 255;

            while (CHECK_IPAGE(next_page)) {
                if (bank != next_page.inode_t.bank) {
                    bank = next_page.inode_t.bank;
                    ret = __osPfsRWInode(pfs, &tmp_inode, PFS_READ, bank);
                    if (ret != 0 && ret != PFS_ERR_INCONSISTENT) {
                        return ret;
                    }
                }
                
                if ((cc = corrupted(pfs, next_page, &cache) - cl) != 0) {
                    break;
                }

                cl = 1;
                next_page = tmp_inode.inode_page[next_page.inode_t.page];
            }

            if (cc != 0 || next_page.ipage != PFS_EOF) {
                tmp_dir.company_code = 0;
                tmp_dir.game_code = 0;
                tmp_dir.start_page.ipage = 0;
                tmp_dir.status = DIR_STATUS_EMPTY;
                tmp_dir.data_sum = 0;

                SET_ACTIVEBANK_TO_ZERO();
                ERRCK(__osContRamWrite(pfs->queue, pfs->channel, pfs->dir_table + j, (u8*)&tmp_dir, FALSE));
                fixed++;
            }
        } else {
            if (tmp_dir.company_code != 0 || tmp_dir.game_code != 0) {
                tmp_dir.company_code = 0;
                tmp_dir.game_code = 0;
                tmp_dir.start_page.ipage = 0;
                tmp_dir.status = DIR_STATUS_EMPTY;
                tmp_dir.data_sum = 0;

                SET_ACTIVEBANK_TO_ZERO();
                ERRCK(__osContRamWrite(pfs->queue, pfs->channel, pfs->dir_table + j, (u8*)&tmp_dir, FALSE));
                fixed++;
            }
        }
#endif
    }
    for (j = 0; j < pfs->dir_size; j++) {
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, pfs->dir_table + j, (u8*)&tmp_dir));

        if (tmp_dir.company_code != 0 && tmp_dir.game_code != 0 &&
            tmp_dir.start_page.ipage >= (u16)pfs->inode_start_page) {
            file_next_node[j].ipage = tmp_dir.start_page.ipage;
        } else {
            file_next_node[j].ipage = 0;
        }
    }

    for (bank = 0; bank < pfs->banks; bank++) {
        ret = __osPfsRWInode(pfs, &tmp_inode, PFS_READ, bank);

        if (ret != 0 && ret != PFS_ERR_INCONSISTENT) {
            return ret;
        }

        offset = (bank > 0) ? 1 : pfs->inode_start_page;

        for (j = 0; j < offset; j++) {
            checked_inode.inode_page[j].ipage = tmp_inode.inode_page[j].ipage;
        }

        for (; j < 128; j++) {
            checked_inode.inode_page[j].ipage = PFS_PAGE_NOT_USED;
        }

        for (j = 0; j < pfs->dir_size; j++) {
            while (file_next_node[j].inode_t.bank == bank && file_next_node[j].ipage >= (u16)pfs->inode_start_page) {
                u8 pp = file_next_node[j].inode_t.page;
                file_next_node[j] = checked_inode.inode_page[pp] = tmp_inode.inode_page[pp];
            }
        }
        ERRCK(__osPfsRWInode(pfs, &checked_inode, PFS_WRITE, bank));
    }

    if (fixed) {
        pfs->status |= PFS_CORRUPTED;
    } else {
        pfs->status &= ~PFS_CORRUPTED;
    }

    return 0;
}

s32 corrupted_init(OSPfs* pfs, __OSInodeCache* cache) {
    int i;
    int n;
    int offset;
    u8 bank;
    __OSInodeUnit tpage;
    __OSInode tmp_inode;
    s32 ret;

    for (i = 0; i < PFS_INODE_DIST_MAP; i++) {
        cache->map[i] = 0;
    }

    cache->bank = -1;
    for (bank = 0; bank < pfs->banks; bank++) {
        offset = bank > 0 ? 1 : pfs->inode_start_page;

        ret = __osPfsRWInode(pfs, &tmp_inode, PFS_READ, bank);

        if (ret != 0 && ret != PFS_ERR_INCONSISTENT) {
            return ret;
        }

        for (i = offset; i < ARRLEN(tmp_inode.inode_page); i++) {
            tpage = tmp_inode.inode_page[i];

            if (tpage.ipage >= pfs->inode_start_page && tpage.inode_t.bank != bank) {
#if BUILD_VERSION >= VERSION_J
                n = ((tpage.inode_t.page & 0x7F) / PFS_SECTOR_SIZE) +
                    ((tpage.inode_t.bank % PFS_BANK_LAPPED_BY) * BLOCKSIZE);
#else
                n = ((tpage.inode_t.page) / PFS_SECTOR_SIZE) +
                    ((tpage.inode_t.bank % PFS_BANK_LAPPED_BY) * BLOCKSIZE);
#endif
                cache->map[n] |= 1 << (bank % PFS_BANK_LAPPED_BY);
            }
        }
    }
    return 0;
}

s32 corrupted(OSPfs* pfs, __OSInodeUnit fpage, __OSInodeCache* cache) {
    int j;
    int n;
    int hit;
    u8 bank;
    int offset;
    s32 ret;

    hit = 0;
    ret = 0;
    n = (fpage.inode_t.page / PFS_SECTOR_SIZE) + (fpage.inode_t.bank % PFS_BANK_LAPPED_BY) * BLOCKSIZE;

    for (bank = 0; bank < pfs->banks; bank++) {
        offset = bank > 0 ? 1 : pfs->inode_start_page;

        if (bank == fpage.inode_t.bank || cache->map[n] & (1 << (bank % PFS_BANK_LAPPED_BY))) {
            if (bank != cache->bank) {
                ret = __osPfsRWInode(pfs, &cache->inode, PFS_READ, bank);

                if (ret != 0 && ret != PFS_ERR_INCONSISTENT) {
                    return ret;
                }

                cache->bank = bank;
            }

            for (j = offset; hit < 2 && (j < ARRLEN(cache->inode.inode_page)); j++) {
                if (cache->inode.inode_page[j].ipage == fpage.ipage) {
                    hit++;
                }
            }

            if (hit >= 2) {
                return PFS_ERR_NEW_PACK;
            }
        }
    }
    return hit;
}
