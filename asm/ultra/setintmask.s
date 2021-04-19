#include <sys/asm.h>
.include "macro.inc"
# assembler directives
.set noat      # allow manual use of $at
.set gp=64     # allow use of 64-bit general purpose registers

.rdata

#define MI_INTR_MASK 0x3f
#define CLR_SP 0x0001
#define SET_SP 0x0002
#define CLR_SI 0x0004
#define SET_SI 0x0008
#define CLR_AI 0x0010
#define SET_AI 0x0020
#define CLR_VI 0x0040
#define SET_VI 0x0080
#define CLR_PI 0x0100
#define SET_PI 0x0200
#define CLR_DP 0x0400
#define SET_DP 0x0800

EXPORT(__osRcpImTable)
/* LUT to convert between MI_INTR and MI_INTR_MASK */
/* MI_INTR is status for each interrupt whereas    */
/* MI_INTR_MASK has seperate bits for set/clr      */
.half CLR_SP | CLR_SI | CLR_AI | CLR_VI | CLR_PI | CLR_DP
.half SET_SP | CLR_SI | CLR_AI | CLR_VI | CLR_PI | CLR_DP
.half CLR_SP | SET_SI | CLR_AI | CLR_VI | CLR_PI | CLR_DP
.half SET_SP | SET_SI | CLR_AI | CLR_VI | CLR_PI | CLR_DP
.half CLR_SP | CLR_SI | SET_AI | CLR_VI | CLR_PI | CLR_DP
.half SET_SP | CLR_SI | SET_AI | CLR_VI | CLR_PI | CLR_DP
.half CLR_SP | SET_SI | SET_AI | CLR_VI | CLR_PI | CLR_DP
.half SET_SP | SET_SI | SET_AI | CLR_VI | CLR_PI | CLR_DP
.half CLR_SP | CLR_SI | CLR_AI | SET_VI | CLR_PI | CLR_DP
.half SET_SP | CLR_SI | CLR_AI | SET_VI | CLR_PI | CLR_DP
.half CLR_SP | SET_SI | CLR_AI | SET_VI | CLR_PI | CLR_DP
.half SET_SP | SET_SI | CLR_AI | SET_VI | CLR_PI | CLR_DP
.half CLR_SP | CLR_SI | SET_AI | SET_VI | CLR_PI | CLR_DP
.half SET_SP | CLR_SI | SET_AI | SET_VI | CLR_PI | CLR_DP
.half CLR_SP | SET_SI | SET_AI | SET_VI | CLR_PI | CLR_DP
.half SET_SP | SET_SI | SET_AI | SET_VI | CLR_PI | CLR_DP
.half CLR_SP | CLR_SI | CLR_AI | CLR_VI | SET_PI | CLR_DP
.half SET_SP | CLR_SI | CLR_AI | CLR_VI | SET_PI | CLR_DP
.half CLR_SP | SET_SI | CLR_AI | CLR_VI | SET_PI | CLR_DP
.half SET_SP | SET_SI | CLR_AI | CLR_VI | SET_PI | CLR_DP
.half CLR_SP | CLR_SI | SET_AI | CLR_VI | SET_PI | CLR_DP
.half SET_SP | CLR_SI | SET_AI | CLR_VI | SET_PI | CLR_DP
.half CLR_SP | SET_SI | SET_AI | CLR_VI | SET_PI | CLR_DP
.half SET_SP | SET_SI | SET_AI | CLR_VI | SET_PI | CLR_DP
.half CLR_SP | CLR_SI | CLR_AI | SET_VI | SET_PI | CLR_DP
.half SET_SP | CLR_SI | CLR_AI | SET_VI | SET_PI | CLR_DP
.half CLR_SP | SET_SI | CLR_AI | SET_VI | SET_PI | CLR_DP
.half SET_SP | SET_SI | CLR_AI | SET_VI | SET_PI | CLR_DP
.half CLR_SP | CLR_SI | SET_AI | SET_VI | SET_PI | CLR_DP
.half SET_SP | CLR_SI | SET_AI | SET_VI | SET_PI | CLR_DP
.half CLR_SP | SET_SI | SET_AI | SET_VI | SET_PI | CLR_DP
.half SET_SP | SET_SI | SET_AI | SET_VI | SET_PI | CLR_DP
.half CLR_SP | CLR_SI | CLR_AI | CLR_VI | CLR_PI | SET_DP
.half SET_SP | CLR_SI | CLR_AI | CLR_VI | CLR_PI | SET_DP
.half CLR_SP | SET_SI | CLR_AI | CLR_VI | CLR_PI | SET_DP
.half SET_SP | SET_SI | CLR_AI | CLR_VI | CLR_PI | SET_DP
.half CLR_SP | CLR_SI | SET_AI | CLR_VI | CLR_PI | SET_DP
.half SET_SP | CLR_SI | SET_AI | CLR_VI | CLR_PI | SET_DP
.half CLR_SP | SET_SI | SET_AI | CLR_VI | CLR_PI | SET_DP
.half SET_SP | SET_SI | SET_AI | CLR_VI | CLR_PI | SET_DP
.half CLR_SP | CLR_SI | CLR_AI | SET_VI | CLR_PI | SET_DP
.half SET_SP | CLR_SI | CLR_AI | SET_VI | CLR_PI | SET_DP
.half CLR_SP | SET_SI | CLR_AI | SET_VI | CLR_PI | SET_DP
.half SET_SP | SET_SI | CLR_AI | SET_VI | CLR_PI | SET_DP
.half CLR_SP | CLR_SI | SET_AI | SET_VI | CLR_PI | SET_DP
.half SET_SP | CLR_SI | SET_AI | SET_VI | CLR_PI | SET_DP
.half CLR_SP | SET_SI | SET_AI | SET_VI | CLR_PI | SET_DP
.half SET_SP | SET_SI | SET_AI | SET_VI | CLR_PI | SET_DP
.half CLR_SP | CLR_SI | CLR_AI | CLR_VI | SET_PI | SET_DP
.half SET_SP | CLR_SI | CLR_AI | CLR_VI | SET_PI | SET_DP
.half CLR_SP | SET_SI | CLR_AI | CLR_VI | SET_PI | SET_DP
.half SET_SP | SET_SI | CLR_AI | CLR_VI | SET_PI | SET_DP
.half CLR_SP | CLR_SI | SET_AI | CLR_VI | SET_PI | SET_DP
.half SET_SP | CLR_SI | SET_AI | CLR_VI | SET_PI | SET_DP
.half CLR_SP | SET_SI | SET_AI | CLR_VI | SET_PI | SET_DP
.half SET_SP | SET_SI | SET_AI | CLR_VI | SET_PI | SET_DP
.half CLR_SP | CLR_SI | CLR_AI | SET_VI | SET_PI | SET_DP
.half SET_SP | CLR_SI | CLR_AI | SET_VI | SET_PI | SET_DP
.half CLR_SP | SET_SI | CLR_AI | SET_VI | SET_PI | SET_DP
.half SET_SP | SET_SI | CLR_AI | SET_VI | SET_PI | SET_DP
.half CLR_SP | CLR_SI | SET_AI | SET_VI | SET_PI | SET_DP
.half SET_SP | CLR_SI | SET_AI | SET_VI | SET_PI | SET_DP
.half CLR_SP | SET_SI | SET_AI | SET_VI | SET_PI | SET_DP
.half SET_SP | SET_SI | SET_AI | SET_VI | SET_PI | SET_DP
.text
.set noreorder
glabel func_80003A30
/* 4630 80003A30 400C6000 */  mfc0       $t4, $12
/* 4634 80003A34 3182FF01 */  andi       $v0, $t4, 0xff01
/* 4638 80003A38 3C088000 */  lui        $t0, %hi(__OSGlobalIntMask)
/* 463C 80003A3C 250850F0 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
/* 4640 80003A40 8D0B0000 */  lw         $t3, ($t0)
/* 4644 80003A44 2401FFFF */  addiu      $at, $zero, -1
/* 4648 80003A48 01614026 */  xor        $t0, $t3, $at
/* 464C 80003A4C 3108FF00 */  andi       $t0, $t0, 0xff00
/* 4650 80003A50 00481025 */  or         $v0, $v0, $t0
/* 4654 80003A54 3C0AA430 */  lui        $t2, %hi(D_A430000C)
/* 4658 80003A58 8D4A000C */  lw         $t2, %lo(D_A430000C)($t2)
/* 465C 80003A5C 11400005 */  beqz       $t2, .L80003A74
/* 4660 80003A60 000B4C02 */   srl       $t1, $t3, 0x10
/* 4664 80003A64 2401FFFF */  addiu      $at, $zero, -1
/* 4668 80003A68 01214826 */  xor        $t1, $t1, $at
/* 466C 80003A6C 3129003F */  andi       $t1, $t1, 0x3f
/* 4670 80003A70 01495025 */  or         $t2, $t2, $t1
.L80003A74:
/* 4674 80003A74 000A5400 */  sll        $t2, $t2, 0x10
/* 4678 80003A78 004A1025 */  or         $v0, $v0, $t2
/* 467C 80003A7C 3C01003F */  lui        $at, 0x3f
/* 4680 80003A80 00814024 */  and        $t0, $a0, $at
/* 4684 80003A84 010B4024 */  and        $t0, $t0, $t3
/* 4688 80003A88 000843C2 */  srl        $t0, $t0, 0xf
/* 468C 80003A8C 3C0A8000 */  lui        $t2, %hi(__osRcpImTable)
/* 4690 80003A90 01485021 */  addu       $t2, $t2, $t0
/* 4694 80003A94 954A51D0 */  lhu        $t2, %lo(__osRcpImTable)($t2)
/* 4698 80003A98 3C01A430 */  lui        $at, %hi(D_A430000C)
/* 469C 80003A9C AC2A000C */  sw         $t2, %lo(D_A430000C)($at)
/* 46A0 80003AA0 3088FF01 */  andi       $t0, $a0, 0xff01
/* 46A4 80003AA4 3169FF00 */  andi       $t1, $t3, 0xff00
/* 46A8 80003AA8 01094024 */  and        $t0, $t0, $t1
/* 46AC 80003AAC 3C01FFFF */  lui        $at, 0xffff
/* 46B0 80003AB0 342100FF */  ori        $at, $at, 0xff
/* 46B4 80003AB4 01816024 */  and        $t4, $t4, $at
/* 46B8 80003AB8 01886025 */  or         $t4, $t4, $t0
/* 46BC 80003ABC 408C6000 */  mtc0       $t4, $12
/* 46C0 80003AC0 00000000 */  nop
/* 46C4 80003AC4 00000000 */  nop
/* 46C8 80003AC8 03E00008 */  jr         $ra
/* 46CC 80003ACC 00000000 */   nop
endlabel func_80003A30
