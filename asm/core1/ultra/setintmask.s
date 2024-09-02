#include <sys/asm.h>
#include <PR/rcp.h>
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
glabel osSetIntMask
    mfc0       $t4, $12
    andi       $v0, $t4, 0xff01
    lui        $t0, %hi(__OSGlobalIntMask)
    addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    lw         $t3, ($t0)
    addiu      $at, $zero, -1
    xor        $t0, $t3, $at
    andi       $t0, $t0, 0xff00
    or         $v0, $v0, $t0
    lui        $t2, %hi(PHYS_TO_K1(MI_INTR_MASK_REG))
    lw         $t2, %lo(PHYS_TO_K1(MI_INTR_MASK_REG))($t2)
    beqz       $t2, setintmask_1
     srl       $t1, $t3, 0x10
    addiu      $at, $zero, -1
    xor        $t1, $t1, $at
    andi       $t1, $t1, 0x3f
    or         $t2, $t2, $t1
setintmask_1:
    sll        $t2, $t2, 0x10
    or         $v0, $v0, $t2
    lui        $at, 0x3f
    and        $t0, $a0, $at
    and        $t0, $t0, $t3
    srl        $t0, $t0, 0xf
    lui        $t2, %hi(__osRcpImTable)
    addu       $t2, $t2, $t0
    lhu        $t2, %lo(__osRcpImTable)($t2)
    lui        $at, %hi(PHYS_TO_K1(MI_INTR_MASK_REG))
    sw         $t2, %lo(PHYS_TO_K1(MI_INTR_MASK_REG))($at)
    andi       $t0, $a0, 0xff01
    andi       $t1, $t3, 0xff00
    and        $t0, $t0, $t1
    lui        $at, 0xffff
    ori        $at, $at, 0xff
    and        $t4, $t4, $at
    or         $t4, $t4, $t0
    mtc0       $t4, $12
    nop
    nop
    jr         $ra
     nop
endlabel osSetIntMask

