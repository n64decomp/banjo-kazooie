#include "PRinternal/macros.h"
#include "PR/os_internal.h"
#include "PR/os_version.h"
#include "PRinternal/controller.h"
#include "PR/rmon.h"

#if BUILD_VERSION >= VERSION_J
__OSInode __osPfsInodeCache ALIGNED(0x8);
s32 __osPfsInodeCacheChannel = -1;
u8 __osPfsInodeCacheBank = 250;
#endif

u16 __osSumcalc(u8* ptr, int length) {
    int i;
    u32 sum = 0;
    u8* tmp = ptr;

    for (i = 0; i < length; i++) {
        sum += *tmp++;
#if BUILD_VERSION < VERSION_J
        sum = sum & 0xFFFF;
#endif
    }

#if BUILD_VERSION >= VERSION_J
    return sum & 0xFFFF;
#else
    return sum;
#endif
}

s32 __osIdCheckSum(u16* ptr, u16* csum, u16* icsum) {
    u16 data = 0;
    u32 j;

    *csum = *icsum = 0;

    for (j = 0; j < ((sizeof(__OSPackId) - sizeof(u32)) / sizeof(u8)); j += 2) {
        data = *(u16*)((u32)ptr + j);
        *csum += data;
        *icsum += ~data;
    }

    return 0;
}

s32 __osRepairPackId(OSPfs* pfs, __OSPackId* badid, __OSPackId* newid) {
    s32 ret = 0;
    u8 temp[BLOCKSIZE];
    u8 comp[BLOCKSIZE];
    u8 mask = 0;
    int i;
    int j;
    u16 index[4];

#if BUILD_VERSION >= VERSION_J
    j = 0;
#else
    SET_ACTIVEBANK_TO_ZERO();
#endif

    newid->repaired = -1;
    newid->random = osGetCount();
    newid->serial_mid = badid->serial_mid;
    newid->serial_low = badid->serial_low;

#if BUILD_VERSION >= VERSION_J
    SET_ACTIVEBANK_TO_ZERO();
#else
    j = 0;
#endif
    do {
        ERRCK(SELECT_BANK(pfs, j));
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, temp));

        temp[0] = j | 0x80;

        for (i = 1; i < BLOCKSIZE; i++) {
            temp[i] = ~temp[i];
        }

        ERRCK(__osContRamWrite(pfs->queue, pfs->channel, 0, temp, FALSE));
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, comp));

        for (i = 0; i < BLOCKSIZE; i++) {
            if (comp[i] != temp[i]) {
                break;
            }
        }

        if (i != BLOCKSIZE) {
            break;
        }

        if (j > 0) {
            ERRCK(SELECT_BANK(pfs, 0));
            ERRCK(__osContRamRead(pfs->queue, pfs->channel, 0, (u8*)temp));

            if (temp[0] != 0x80) {
                break;
            }
        }

        j++;
    } while (j < PFS_MAX_BANKS);

#if BUILD_VERSION >= VERSION_J
    SET_ACTIVEBANK_TO_ZERO();
#else
    ERRCK(SELECT_BANK(pfs, 0));
#endif

    mask = (j > 0) ? 1 : 0;

    newid->deviceid = (badid->deviceid & (u16)~1) | mask;
    newid->banks = j;
    newid->version = badid->version;
    __osIdCheckSum((u16*)newid, &newid->checksum, &newid->inverted_checksum);
    index[0] = PFS_ID_0AREA;
    index[1] = PFS_ID_1AREA;
    index[2] = PFS_ID_2AREA;
    index[3] = PFS_ID_3AREA;

    for (i = 0; i < ARRLEN(index); i++) {
        ERRCK(__osContRamWrite(pfs->queue, pfs->channel, index[i], (u8*)newid, TRUE));
    }

    ERRCK(__osContRamRead(pfs->queue, pfs->channel, PFS_ID_0AREA, (u8*)temp));

    for (i = 0; i < BLOCKSIZE; i++) {
        if (temp[i] != ((u8*)newid)[i]) {
#if BUILD_VERSION >= VERSION_J
            return PFS_ERR_DEVICE;
#else
            return PFS_ERR_ID_FATAL;
#endif
        }
    }
    return 0;
}

s32 __osCheckPackId(OSPfs* pfs, __OSPackId* temp) {
    u16 index[4];
    s32 ret = 0;
    u16 sum;
    u16 isum;
    int i;
    int j;

    SET_ACTIVEBANK_TO_ZERO();
    index[0] = PFS_ID_0AREA;
    index[1] = PFS_ID_1AREA;
    index[2] = PFS_ID_2AREA;
    index[3] = PFS_ID_3AREA;
    for (i = 1; i < ARRLEN(index); i++) {
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, index[i], (u8*)temp));
        __osIdCheckSum((u16*)temp, &sum, &isum);
        if (temp->checksum == sum && temp->inverted_checksum == isum) {
            break;
        }
    }

    if (i == ARRLEN(index)) {
        return PFS_ERR_ID_FATAL;
    }

    for (j = 0; j < ARRLEN(index); j++) {
        if (j != i) {
            ERRCK(__osContRamWrite(pfs->queue, pfs->channel, index[j], (u8*)temp, TRUE));
        }
    }

    return 0;
}

s32 __osGetId(OSPfs* pfs) {
#if BUILD_VERSION < VERSION_J
    int k;
#endif
    u16 sum;
    u16 isum;
    u8 temp[BLOCKSIZE];
    __OSPackId newid;
    s32 ret;
    __OSPackId* id;

    SET_ACTIVEBANK_TO_ZERO();
    ERRCK(__osContRamRead(pfs->queue, pfs->channel, PFS_ID_0AREA, (u8*)temp));
    __osIdCheckSum((u16*)temp, &sum, &isum);
    id = (__OSPackId*)temp;

    if (id->checksum != sum || id->inverted_checksum != isum) {
        ret = __osCheckPackId(pfs, id);

        if (ret == PFS_ERR_ID_FATAL) {
            ERRCK(__osRepairPackId(pfs, id, &newid));
            id = &newid;
        } else if (ret != 0) {
            return ret;
        }
    }

    if ((id->deviceid & 1) == 0) {
        ERRCK(__osRepairPackId(pfs, id, &newid));
        id = &newid;

        if ((id->deviceid & 1) == 0) {
            return PFS_ERR_DEVICE;
        }
    }

#if BUILD_VERSION >= VERSION_J
    bcopy(id, pfs->id, BLOCKSIZE);
#else
    for (k = 0; k < ARRLEN(pfs->id); k++) {
        pfs->id[k] = ((u8 *)id)[k];
    }
#endif
    pfs->version = id->version;
    pfs->banks = id->banks;
    pfs->inode_start_page = 1 + DEF_DIR_PAGES + (2 * pfs->banks);
    pfs->dir_size = 16;
    pfs->inode_table = PFS_ONE_PAGE;
    pfs->minode_table = (1 + pfs->banks) * PFS_ONE_PAGE;
    pfs->dir_table = pfs->minode_table + pfs->banks * PFS_ONE_PAGE;
    ERRCK(__osContRamRead(pfs->queue, pfs->channel, PFS_LABEL_AREA, pfs->label));
    return 0;
}

s32 __osCheckId(OSPfs* pfs) {
#if BUILD_VERSION < VERSION_J
    int k;
#endif
    u8 temp[BLOCKSIZE];
    s32 ret;

#if BUILD_VERSION >= VERSION_J
    if (pfs->activebank != 0) {
        ret = __osPfsSelectBank(pfs, 0);

        if (ret == PFS_ERR_NEW_PACK) {
            ret = __osPfsSelectBank(pfs, 0);
        }

        if (ret != 0) {
            return ret;
        }
    }
#else
    SET_ACTIVEBANK_TO_ZERO();
#endif

    ret = __osContRamRead(pfs->queue, pfs->channel, PFS_ID_0AREA, (u8*)temp);

    if (ret != 0) {
        if (ret != PFS_ERR_NEW_PACK) {
            return ret;
        }
        ERRCK(__osContRamRead(pfs->queue, pfs->channel, PFS_ID_0AREA, (u8*)temp));
    }

#if BUILD_VERSION >= VERSION_J
    if (bcmp(pfs->id, temp, BLOCKSIZE) != 0) {
        return PFS_ERR_NEW_PACK;
    }
#else
    for (k = 0; k < ARRLEN(temp); k++) {
        if (pfs->id[k] != temp[k])
            return PFS_ERR_NEW_PACK;
    }
#endif

    return 0;
}

s32 __osPfsRWInode(OSPfs* pfs, __OSInode* inode, u8 flag, u8 bank) {
    u8 sum;
    int j;
    s32 ret;
    int offset;
    u8 *addr;

#if BUILD_VERSION >= VERSION_J
    if (flag == PFS_READ && bank == __osPfsInodeCacheBank && (pfs->channel == __osPfsInodeCacheChannel)) {
        bcopy(&__osPfsInodeCache, inode, sizeof(__OSInode));
        return 0;
    }
#endif

    SET_ACTIVEBANK_TO_ZERO();

    offset = (bank > 0) ? 1 : pfs->inode_start_page;

    if (flag == PFS_WRITE) {
        inode->inode_page[0].inode_t.page =
            __osSumcalc((u8*)&inode->inode_page[offset], (PFS_INODE_SIZE_PER_PAGE - offset) * 2);
    }

    for (j = 0; j < PFS_ONE_PAGE; j++) {
        addr = ((u8*)inode->inode_page + j * BLOCKSIZE);

        if (flag == PFS_WRITE) {
            ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->inode_table + bank * PFS_ONE_PAGE + j, addr, FALSE);
            ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->minode_table + bank * PFS_ONE_PAGE + j, addr, FALSE);
        } else {
            ret = __osContRamRead(pfs->queue, pfs->channel, pfs->inode_table + bank * PFS_ONE_PAGE + j, addr);
        }

        if (ret != 0) {
            return ret;
        }
    }

    if (flag == PFS_READ) {
        sum = __osSumcalc((u8*)&inode->inode_page[offset], (PFS_INODE_SIZE_PER_PAGE - offset) * 2);
        if (sum != inode->inode_page[0].inode_t.page) {
            for (j = 0; j < PFS_ONE_PAGE; j++) {
                addr = ((u8*)inode->inode_page + j * BLOCKSIZE);
                ret = __osContRamRead(pfs->queue, pfs->channel, pfs->minode_table + bank * PFS_ONE_PAGE + j, addr);
            }

#if BUILD_VERSION >= VERSION_J
            sum = __osSumcalc((u8*)&inode->inode_page[offset], (PFS_INODE_SIZE_PER_PAGE - offset) * 2);
#endif

            if (sum != inode->inode_page[0].inode_t.page) {
                return PFS_ERR_INCONSISTENT;
            }

            for (j = 0; j < PFS_ONE_PAGE; j++) {
                addr = ((u8*)inode->inode_page + j * BLOCKSIZE);
                ret =
                    __osContRamWrite(pfs->queue, pfs->channel, pfs->inode_table + bank * PFS_ONE_PAGE + j, addr, FALSE);
            }
        }
#if BUILD_VERSION < VERSION_J
        else
        {
            for (j = 0; j < PFS_ONE_PAGE; j++)
            {
                addr = ((u8 *)inode->inode_page + j * 32);
                ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->minode_table + bank * PFS_ONE_PAGE + j, addr, FALSE);
            }
        }
#endif
    }

#if BUILD_VERSION >= VERSION_J
    __osPfsInodeCacheBank = bank;
    bcopy(inode, &__osPfsInodeCache, sizeof(__OSInode));
    __osPfsInodeCacheChannel = pfs->channel;
#endif

    return 0;
}

// This was moved into it's own file in 2.0J
#if BUILD_VERSION < VERSION_J
s32 __osPfsSelectBank(OSPfs* pfs) {
    u8 temp[BLOCKSIZE];
    int i;
    s32 ret = 0;

    for (i = 0; i < BLOCKSIZE; i++) {
        temp[i] = pfs->activebank;
    }

    ret = __osContRamWrite(pfs->queue, pfs->channel, CONT_BLOCK_DETECT, temp, FALSE);
    return ret;
}
#endif

#ifdef _DEBUG
s32 __osDumpId(OSPfs* pfs) {
    u8 id[BLOCKSIZE];
    __OSPackId* temp;
    s32 ret;

    ERRCK(__osContRamRead(pfs->queue, pfs->channel, PFS_ID_0AREA, id));

    temp = (__OSPackId*)id;
    rmonPrintf("repaired %x\n", temp->repaired);
    rmonPrintf("random %x\n", temp->random);
    rmonPrintf("serial_mid %llu\n", temp->serial_mid);
    rmonPrintf("serial_low %llu\n", temp->serial_low);
    rmonPrintf("deviceid %x\n", temp->deviceid);
    rmonPrintf("banks %x\n", temp->banks);
    rmonPrintf("version %x\n", temp->version);
    rmonPrintf("checksum %x\n", temp->checksum);
    rmonPrintf("inverted_checksum %x\n", temp->inverted_checksum);
    return 0;
}
#endif
