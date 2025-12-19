#include <sys/asm.h>
#include <PR/rcp.h>
.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.data

EXPORT(__osHwIntTable)
.word 0x0, 0x0, 0x0, 0x0, 0x0

.rdata
#define REDISPATCH 0x00
#define SW1 0x04
#define SW2 0x08
#define RCP 0x0c
#define CART 0x10
#define PRENMI 0x14
#define IP6_HDLR 0x18
#define IP7_HDLR 0x1c
#define COUNTER 0x20
__osIntOffTable:
.byte REDISPATCH
.byte PRENMI 
.byte IP6_HDLR 
.byte IP6_HDLR 
.byte IP7_HDLR 
.byte IP7_HDLR
.byte IP7_HDLR 
.byte IP7_HDLR 
.byte COUNTER 
.byte COUNTER 
.byte IP6_HDLR 
.byte IP6_HDLR 
.byte IP7_HDLR 
.byte IP7_HDLR 
.byte IP7_HDLR 
.byte IP7_HDLR 
.byte REDISPATCH 
.byte SW1 
.byte SW2 
.byte SW2 
.byte RCP 
.byte RCP 
.byte RCP 
.byte RCP 
.byte CART 
.byte CART 
.byte CART 
.byte CART 
.byte CART 
.byte CART 
.byte CART 
.byte CART
__osIntTable:
.word redispatch, sw1, sw2, rcp, cart, prenmi, IP6_Hdlr, IP7_Hdlr, counter

.text

glabel __osExceptionPreamble
    lui        $k0, %hi(D_80002280)
    addiu      $k0, $k0, %lo(D_80002280)
    jr         $k0
     nop
    lui        $k0, %hi(D_80002280)
    addiu      $k0, $k0, %lo(D_80002280)
    jr         $k0
     nop
D_80002280:
    lui        $k0, %hi(__osThreadSave)
    addiu      $k0, $k0, %lo(__osThreadSave)
    sd         $at, 0x20($k0)
    mfc0       $k1, $12
    sw         $k1, 0x118($k0)
    addiu      $at, $zero, -0x4
    and        $k1, $k1, $at
    mtc0       $k1, $12
    sd         $t0, 0x58($k0)
    sd         $t1, 0x60($k0)
    sd         $t2, 0x68($k0)
    sw         $zero, 0x18($k0)
    mfc0       $t0, $13
    or         $t0, $k0, $zero
    lui        $k0, %hi(__osRunningThread)
    lw         $k0, %lo(__osRunningThread)($k0)
    ld         $t1, 0x20($t0)
    sd         $t1, 0x20($k0)
    ld         $t1, 0x118($t0)
    sd         $t1, 0x118($k0)
    ld         $t1, 0x58($t0)
    sd         $t1, 0x58($k0)
    ld         $t1, 0x60($t0)
    sd         $t1, 0x60($k0)
    ld         $t1, 0x68($t0)
    sd         $t1, 0x68($k0)
    lw         $k1, 0x118($k0)
    mflo       $t0
    sd         $t0, 0x108($k0)
    mfhi       $t0
    andi       $t1, $k1, 0xFF00
    sd         $v0, 0x28($k0)
    sd         $v1, 0x30($k0)
    sd         $a0, 0x38($k0)
    sd         $a1, 0x40($k0)
    sd         $a2, 0x48($k0)
    sd         $a3, 0x50($k0)
    sd         $t3, 0x70($k0)
    sd         $t4, 0x78($k0)
    sd         $t5, 0x80($k0)
    sd         $t6, 0x88($k0)
    sd         $t7, 0x90($k0)
    sd         $s0, 0x98($k0)
    sd         $s1, 0xA0($k0)
    sd         $s2, 0xA8($k0)
    sd         $s3, 0xB0($k0)
    sd         $s4, 0xB8($k0)
    sd         $s5, 0xC0($k0)
    sd         $s6, 0xC8($k0)
    sd         $s7, 0xD0($k0)
    sd         $t8, 0xD8($k0)
    sd         $t9, 0xE0($k0)
    sd         $gp, 0xE8($k0)
    sd         $sp, 0xF0($k0)
    sd         $fp, 0xF8($k0)
    sd         $ra, 0x100($k0)
    beqz       $t1, .L80002398
     sd        $t0, 0x110($k0)
    lui        $t0, %hi(__OSGlobalIntMask)
    addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    lw         $t0, 0x0($t0)
    addiu      $at, $zero, -0x1
    xor        $t0, $t0, $at
    lui        $at, (0xFFFF00FF >> 16)
    andi       $t0, $t0, 0xFF00
    ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    or         $t1, $t1, $t0
    and        $k1, $k1, $at
    or         $k1, $k1, $t1
    sw         $k1, 0x118($k0)
.L80002398:
    lui        $t1, %hi(PHYS_TO_K1(MI_INTR_MASK_REG))
    lw         $t1, %lo(PHYS_TO_K1(MI_INTR_MASK_REG))($t1)
    beql       $t1, $zero, .L800023D4
     sw        $t1, 0x128($k0)
    lui        $t0, %hi(__OSGlobalIntMask)
    addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    lw         $t0, 0x0($t0)
    lw         $t4, 0x128($k0)
    addiu      $at, $zero, -0x1
    srl        $t0, $t0, 16
    xor        $t0, $t0, $at
    andi       $t0, $t0, 0x3F
    and        $t0, $t0, $t4
    or         $t1, $t1, $t0
    sw         $t1, 0x128($k0)
.L800023D4:
    mfc0       $t0, $14
    sw         $t0, 0x11C($k0)
    lw         $t0, 0x18($k0)
    beqz       $t0, .L80002434
     nop
    cfc1       $t0, $31
    nop
    sw         $t0, 0x12C($k0)
    sdc1       $f0, 0x130($k0)
    sdc1       $f2, 0x138($k0)
    sdc1       $f4, 0x140($k0)
    sdc1       $f6, 0x148($k0)
    sdc1       $f8, 0x150($k0)
    sdc1       $f10, 0x158($k0)
    sdc1       $f12, 0x160($k0)
    sdc1       $f14, 0x168($k0)
    sdc1       $f16, 0x170($k0)
    sdc1       $f18, 0x178($k0)
    sdc1       $f20, 0x180($k0)
    sdc1       $f22, 0x188($k0)
    sdc1       $f24, 0x190($k0)
    sdc1       $f26, 0x198($k0)
    sdc1       $f28, 0x1A0($k0)
    sdc1       $f30, 0x1A8($k0)
.L80002434:
    mfc0       $t0, $13
    sw         $t0, 0x120($k0)
    addiu      $t1, $zero, 0x2
    sh         $t1, 0x10($k0)
    andi       $t1, $t0, 0x7C
    addiu      $t2, $zero, 0x24
    beql       $t1, $t2, handle_break
     addiu     $t1, $zero, 0x1
    addiu      $t2, $zero, 0x2C
    beq        $t1, $t2, handle_CpU
     nop
    addiu      $t2, $zero, 0x0
    bne        $t1, $t2, .L80002774
     nop
    and        $s0, $k1, $t0
next_interrupt:
    andi       $t1, $s0, 0xFF00
next_interrupt_4:
    srl        $t2, $t1, 12
    bnez       $t2, .L80002488
     nop
    srl        $t2, $t1, 8
    addi       $t2, $t2, 0x10
.L80002488:
    lui        $at, %hi(__osIntOffTable)
    addu       $at, $at, $t2
    lbu        $t2, %lo(__osIntOffTable)($at)
    lui        $at, %hi(__osIntTable)
    addu       $at, $at, $t2
    lw         $t2, %lo(__osIntTable)($at)
    jr         $t2
     nop
IP6_Hdlr:
    addiu      $at, $zero, -0x2001
    b          next_interrupt
     and       $s0, $s0, $at
IP7_Hdlr:
    addiu      $at, $zero, -0x4001
    b          next_interrupt
     and       $s0, $s0, $at
counter:
    mfc0       $t1, $11
    mtc0       $t1, $11
    jal        send_mesg
     addiu     $a0, $zero, 0x18
    lui        $at, (0xFFFF7FFF >> 16)
    ori        $at, $at, (0xFFFF7FFF & 0xFFFF)
    b          next_interrupt
     and       $s0, $s0, $at
cart:
    addiu      $at, $zero, -0x801
    and        $s0, $s0, $at
    addiu      $t2, $zero, 4
    lui        $at, %hi(__osHwIntTable)
    addu       $at, $at, $t2
    lw         $t2, %lo(__osHwIntTable)($at)
    lui        $sp, %hi(leoDiskStack)
    addiu      $sp, $sp, %lo(leoDiskStack)
    addiu      $a0, $zero, 0x10
    beqz       $t2, .L80002524
     addiu     $sp, $sp, 0xff0
    jalr       $t2
     nop
    beqz       $v0, .L80002524
     nop
    b          redispatch
     nop
.L80002524:
    jal        send_mesg
     nop
    b          next_interrupt_4
     andi      $t1, $s0, 0xff00
rcp:
    lui        $t0, %hi(__OSGlobalIntMask)
    addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    lw         $t0, ($t0)
    lui        $s1, %hi(PHYS_TO_K1(MI_INTR_REG))
    lw         $s1, %lo(PHYS_TO_K1(MI_INTR_REG))($s1)
    srl        $t0, $t0, 0x10
    and        $s1, $s1, $t0
    andi       $t1, $s1, 1
    beql       $t1, $zero, .L800025A8
     andi      $t1, $s1, 8
    lui        $t4, %hi(PHYS_TO_K1(SP_STATUS_REG))
    lw         $t4, %lo(PHYS_TO_K1(SP_STATUS_REG))($t4)
    addiu      $t1, $zero, 8
    lui        $at, %hi(PHYS_TO_K1(SP_STATUS_REG))
    andi       $t4, $t4, 0x300
    andi       $s1, $s1, 0x3e
    beqz       $t4, .L80002594
     sw        $t1, %lo(PHYS_TO_K1(SP_STATUS_REG))($at)
    jal        send_mesg
     addiu     $a0, $zero, 0x20
    beql       $s1, $zero, .L8000266C
     addiu     $at, $zero, -0x401
    b          .L800025A8
     andi      $t1, $s1, 8
.L80002594:
    jal        send_mesg
     addiu     $a0, $zero, 0x58
    beql       $s1, $zero, .L8000266C
     addiu     $at, $zero, -0x401
    andi       $t1, $s1, 8
.L800025A8:
    beqz       $t1, .L800025C8
     lui       $at, %hi(PHYS_TO_K1(VI_CURRENT_REG))
    andi       $s1, $s1, 0x37
    sw         $zero, %lo(PHYS_TO_K1(VI_CURRENT_REG))($at)
    jal        send_mesg
     addiu     $a0, $zero, 0x38
    beql       $s1, $zero, .L8000266C
     addiu     $at, $zero, -0x401
.L800025C8:
    andi       $t1, $s1, 4
    beql       $t1, $zero, .L800025F8
     andi      $t1, $s1, 2
    addiu      $t1, $zero, 1
    lui        $at, %hi(PHYS_TO_K1(AI_STATUS_REG))
    andi       $s1, $s1, 0x3b
    sw         $t1, %lo(PHYS_TO_K1(AI_STATUS_REG))($at)
    jal        send_mesg
     addiu     $a0, $zero, 0x30
    beql       $s1, $zero, .L8000266C
     addiu     $at, $zero, -0x401
    andi       $t1, $s1, 2
.L800025F8:
    beqz       $t1, .L80002618
     lui       $at, %hi(PHYS_TO_K1(SI_STATUS_REG))
    andi       $s1, $s1, 0x3d
    sw         $zero, %lo(PHYS_TO_K1(SI_STATUS_REG))($at)
    jal        send_mesg
     addiu     $a0, $zero, 0x28
    beql       $s1, $zero, .L8000266C
     addiu     $at, $zero, -0x401
.L80002618:
    andi       $t1, $s1, 0x10
    beql       $t1, $zero, .L80002648
     andi      $t1, $s1, 0x20
    addiu      $t1, $zero, 2
    lui        $at, %hi(PHYS_TO_K1(PI_STATUS_REG))
    andi       $s1, $s1, 0x2f
    sw         $t1, %lo(PHYS_TO_K1(PI_STATUS_REG))($at)
    jal        send_mesg
     addiu     $a0, $zero, 0x40
    beql       $s1, $zero, .L8000266C
     addiu     $at, $zero, -0x401
    andi       $t1, $s1, 0x20
.L80002648:
    beql       $t1, $zero, .L8000266C
     addiu     $at, $zero, -0x401
    addiu      $t1, $zero, 0x800
    lui        $at, 0xa430
    andi       $s1, $s1, 0x1f
    sw         $t1, ($at)
    jal        send_mesg
     addiu     $a0, $zero, 0x48
    addiu      $at, $zero, -0x401
.L8000266C:
    b          next_interrupt
     and       $s0, $s0, $at
prenmi:
    lw         $k1, 0x118($k0)
    addiu      $at, $zero, -0x1001
    lui        $t1, %hi(__osShutdown)
    and        $k1, $k1, $at
    sw         $k1, 0x118($k0)
    addiu      $t1, $t1, %lo(__osShutdown)
    lw         $t2, ($t1)
    beqz       $t2, firstnmi
     addiu     $at, $zero, -0x1001
    b          redispatch
     and       $s0, $s0, $at
firstnmi:
    addiu      $t2, $zero, 1
    sw         $t2, ($t1)
    jal        send_mesg
     addiu     $a0, $zero, 0x70
    lui        $t2, %hi(__osRunQueue)
    lw         $t2, %lo(__osRunQueue)($t2)
    addiu      $at, $zero, -0x1001
    and        $s0, $s0, $at
    lw         $k1, 0x118($t2)
    and        $k1, $k1, $at
    b          redispatch
     sw        $k1, 0x118($t2)
sw2:
    addiu      $at, $zero, -0x201
    and        $t0, $t0, $at
    mtc0       $t0, $13
    jal        send_mesg
     addiu     $a0, $zero, 8
    addiu      $at, $zero, -0x201
    b          next_interrupt
     and       $s0, $s0, $at
sw1:
    addiu      $at, $zero, -0x101
    and        $t0, $t0, $at
    mtc0       $t0, $13
    jal        send_mesg
     addiu     $a0, $zero, 0
    addiu      $at, $zero, -0x101
    b          next_interrupt
     and       $s0, $s0, $at
    addiu      $t1, $zero, 1
handle_break:
    sh         $t1, 0x12($k0)
    jal        send_mesg
     addiu     $a0, $zero, 0x50
    b          redispatch
     nop
redispatch:
    lui        $t2, %hi(__osRunQueue)
    lw         $t2, %lo(__osRunQueue)($t2)
    lw         $t1, 4($k0)
    lw         $t3, 4($t2)
    slt        $at, $t1, $t3
    beqz       $at, enqueueRunning
     nop
    lui        $a0, %hi(__osRunQueue)
    or         $a1, $k0, $zero
    jal        __osEnqueueThread
     addiu     $a0, $a0, %lo(__osRunQueue)
    j          __osDispatchThread
     nop
enqueueRunning:
    lui        $t1, %hi(__osRunQueue)
    addiu      $t1, $t1, %lo(__osRunQueue)
    lw         $t2, ($t1)
    sw         $t2, ($k0)
    j          __osDispatchThread
     sw        $k0, ($t1)
.L80002774:
    lui        $at, %hi(__osFaultedThread)
    sw         $k0, %lo(__osFaultedThread)($at)
    addiu      $t1, $zero, 1
    sh         $t1, 0x10($k0)
    addiu      $t1, $zero, 2
    sh         $t1, 0x12($k0)
    mfc0       $t2, $8
    sw         $t2, 0x124($k0)
    jal        send_mesg
     addiu     $a0, $zero, 0x60
    j          __osDispatchThread
     nop
endlabel __osExceptionPreamble

glabel send_mesg
    lui        $t2, %hi(__osEventStateTab)
    addiu      $t2, $t2, %lo(__osEventStateTab)
    addu       $t2, $t2, $a0
    lw         $t1, ($t2)
    or         $s2, $ra, $zero
    beqz       $t1, send_done
     nop
    lw         $t3, 8($t1)
    lw         $t4, 0x10($t1)
    slt        $at, $t3, $t4
    beqz       $at, send_done
     nop
    lw         $t5, 0xc($t1)
    addu       $t5, $t5, $t3
    div        $zero, $t5, $t4
    bnez       $t4, .L800027EC
     nop
    break      7
.L800027EC:
     addiu     $at, $zero, -1
    bne        $t4, $at, .L80002804
     lui       $at, 0x8000
    bne        $t5, $at, .L80002804
     nop
    break      6
.L80002804:
     lw        $t4, 0x14($t1)
    mfhi       $t5
    sll        $t5, $t5, 2
    addu       $t4, $t4, $t5
    lw         $t5, 0x4($t2)
    addiu      $t2, $t3, 0x1
    sw         $t5, 0x0($t4)
    sw         $t2, 0x8($t1)
    lw         $t2, 0x0($t1)
    lw         $t3, 0x0($t2)
    beqz       $t3, send_done
     nop
    jal        __osPopThread
     or        $a0, $t1, $zero
    or         $t2, $v0, $zero
    lui        $a0, %hi(__osRunQueue)
    or         $a1, $t2, $zero
    jal        __osEnqueueThread
     addiu     $a0, $a0, %lo(__osRunQueue)
send_done:
    jr         $s2
     nop
endlabel send_mesg

glabel handle_CpU
    lui        $at, (0x30000000 >> 16)
    and        $t1, $t0, $at
    srl        $t1, $t1, 28
    addiu      $t2, $zero, 0x1
    bne        $t1, $t2, .L80002774
     nop
    lw         $k1, 0x118($k0)
    lui        $at, (0x20000000 >> 16)
    addiu      $t1, $zero, 0x1
    or         $k1, $k1, $at
    sw         $t1, 0x18($k0)
    b          enqueueRunning
     sw        $k1, 0x118($k0)
endlabel handle_CpU

glabel __osEnqueueAndYield
    lui        $a1, %hi(__osRunningThread)
    lw         $a1, %lo(__osRunningThread)($a1)
    mfc0       $t0, $12
    lw         $k1, 0x18($a1)
    ori        $t0, $t0, 0x2
    sw         $t0, 0x118($a1)
    sd         $s0, 0x98($a1)
    sd         $s1, 0xA0($a1)
    sd         $s2, 0xA8($a1)
    sd         $s3, 0xB0($a1)
    sd         $s4, 0xB8($a1)
    sd         $s5, 0xC0($a1)
    sd         $s6, 0xC8($a1)
    sd         $s7, 0xD0($a1)
    sd         $gp, 0xE8($a1)
    sd         $sp, 0xF0($a1)
    sd         $fp, 0xF8($a1)
    sd         $ra, 0x100($a1)
    beqz       $k1, .L800028FC
     sw        $ra, 0x11C($a1)
    cfc1       $k1, $31
    sdc1       $f20, 0x180($a1)
    sdc1       $f22, 0x188($a1)
    sdc1       $f24, 0x190($a1)
    sdc1       $f26, 0x198($a1)
    sdc1       $f28, 0x1A0($a1)
    sdc1       $f30, 0x1A8($a1)
    sw         $k1, 0x12C($a1)
.L800028FC:
    lw         $k1, 0x118($a1)
    andi       $t1, $k1, 0xFF00
    beql       $t1, $zero, .L80002940
     lui       $k1, %hi(PHYS_TO_K1(MI_INTR_MASK_REG))
    lui        $t0, %hi(__OSGlobalIntMask)
    addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    lw         $t0, 0x0($t0)
    addiu      $at, $zero, -0x1
    xor        $t0, $t0, $at
    lui        $at, (0xFFFF00FF >> 16)
    andi       $t0, $t0, 0xFF00
    ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    or         $t1, $t1, $t0
    and        $k1, $k1, $at
    or         $k1, $k1, $t1
    sw         $k1, 0x118($a1)
    lui        $k1, %hi(PHYS_TO_K1(MI_INTR_MASK_REG))
.L80002940:
    lw         $k1, %lo(PHYS_TO_K1(MI_INTR_MASK_REG))($k1)
    beqz       $k1, .L80002974
     nop
    lui        $k0, %hi(__OSGlobalIntMask)
    addiu      $k0, $k0, %lo(__OSGlobalIntMask)
    lw         $k0, 0x0($k0)
    lw         $t0, 0x128($a1)
    addiu      $at, $zero, -0x1
    srl        $k0, $k0, 16
    xor        $k0, $k0, $at
    andi       $k0, $k0, 0x3F
    and        $k0, $k0, $t0
    or         $k1, $k1, $k0
.L80002974:
    beqz       $a0, .L80002984
     sw        $k1, 0x128($a1)
    jal        __osEnqueueThread
     nop
.L80002984:
    j          __osDispatchThread
     nop
endlabel __osEnqueueAndYield

glabel __osEnqueueThread
    lw         $t8, 0x0($a0)
    lw         $t7, 0x4($a1)
    or         $t9, $a0, $zero
    lw         $t6, 0x4($t8)
    slt        $at, $t6, $t7
    bnel       $at, $zero, .L800029C4
     lw        $t8, 0x0($t9)
    or         $t9, $t8, $zero
.L800029AC:
    lw         $t8, 0x0($t8)
    lw         $t6, 0x4($t8)
    slt        $at, $t6, $t7
    beql       $at, $zero, .L800029AC
     or        $t9, $t8, $zero
    lw         $t8, 0x0($t9)
.L800029C4:
    sw         $t8, 0x0($a1)
    sw         $a1, 0x0($t9)
    jr         $ra
     sw        $a0, 0x8($a1)
endlabel __osEnqueueThread

glabel __osPopThread
    lw         $v0, 0x0($a0)
    lw         $t9, 0x0($v0)
    jr         $ra
     sw        $t9, 0x0($a0)
endlabel __osPopThread

glabel __osDispatchThread
    lui        $a0, %hi(__osRunQueue)
    jal        __osPopThread
     addiu     $a0, $a0, %lo(__osRunQueue)
    lui        $at, %hi(__osRunningThread)
    sw         $v0, %lo(__osRunningThread)($at)
    addiu      $t0, $zero, 0x4
    sh         $t0, 0x10($v0)
    or         $k0, $v0, $zero
    lui        $t0, %hi(__OSGlobalIntMask)
    lw         $k1, 0x118($k0)
    addiu      $t0, $t0, %lo(__OSGlobalIntMask)
    lw         $t0, 0x0($t0)
    lui        $at, (0xFFFF00FF >> 16)
    andi       $t1, $k1, 0xFF00
    ori        $at, $at, (0xFFFF00FF & 0xFFFF)
    andi       $t0, $t0, 0xFF00
    and        $t1, $t1, $t0
    and        $k1, $k1, $at
    or         $k1, $k1, $t1
    mtc0       $k1, $12
    ld         $k1, 0x108($k0)
    ld         $at, 0x20($k0)
    ld         $v0, 0x28($k0)
    mtlo       $k1
    ld         $k1, 0x110($k0)
    ld         $v1, 0x30($k0)
    ld         $a0, 0x38($k0)
    ld         $a1, 0x40($k0)
    ld         $a2, 0x48($k0)
    ld         $a3, 0x50($k0)
    ld         $t0, 0x58($k0)
    ld         $t1, 0x60($k0)
    ld         $t2, 0x68($k0)
    ld         $t3, 0x70($k0)
    ld         $t4, 0x78($k0)
    ld         $t5, 0x80($k0)
    ld         $t6, 0x88($k0)
    ld         $t7, 0x90($k0)
    ld         $s0, 0x98($k0)
    ld         $s1, 0xA0($k0)
    ld         $s2, 0xA8($k0)
    ld         $s3, 0xB0($k0)
    ld         $s4, 0xB8($k0)
    ld         $s5, 0xC0($k0)
    ld         $s6, 0xC8($k0)
    ld         $s7, 0xD0($k0)
    ld         $t8, 0xD8($k0)
    ld         $t9, 0xE0($k0)
    ld         $gp, 0xE8($k0)
    mthi       $k1
    ld         $sp, 0xF0($k0)
    ld         $fp, 0xF8($k0)
    ld         $ra, 0x100($k0)
    lw         $k1, 0x11C($k0)
    mtc0       $k1, $14
    lw         $k1, 0x18($k0)
    beqz       $k1, .L80002B14
     nop
    lw         $k1, 0x12C($k0)
    ctc1       $k1, $31
    ldc1       $f0, 0x130($k0)
    ldc1       $f2, 0x138($k0)
    ldc1       $f4, 0x140($k0)
    ldc1       $f6, 0x148($k0)
    ldc1       $f8, 0x150($k0)
    ldc1       $f10, 0x158($k0)
    ldc1       $f12, 0x160($k0)
    ldc1       $f14, 0x168($k0)
    ldc1       $f16, 0x170($k0)
    ldc1       $f18, 0x178($k0)
    ldc1       $f20, 0x180($k0)
    ldc1       $f22, 0x188($k0)
    ldc1       $f24, 0x190($k0)
    ldc1       $f26, 0x198($k0)
    ldc1       $f28, 0x1A0($k0)
    ldc1       $f30, 0x1A8($k0)
.L80002B14:
    lw         $k1, 0x128($k0)
    lui        $k0, %hi(__OSGlobalIntMask)
    addiu      $k0, $k0, %lo(__OSGlobalIntMask)
    lw         $k0, 0x0($k0)
    srl        $k0, $k0, 16
    and        $k1, $k1, $k0
    sll        $k1, $k1, 1
    lui        $k0, %hi(__osRcpImTable)
    addiu      $k0, $k0, %lo(__osRcpImTable)
    addu       $k1, $k1, $k0
    lhu        $k1, 0x0($k1)
    lui        $k0, %hi(PHYS_TO_K1(MI_INTR_MASK_REG))
    addiu      $k0, $k0, %lo(PHYS_TO_K1(MI_INTR_MASK_REG))
    sw         $k1, 0x0($k0)
    nop
    nop
    nop
    nop
    eret
endlabel __osDispatchThread

glabel __osCleanupThread
    jal        osDestroyThread
     or        $a0, $zero, $zero
    nop
    nop
endlabel __osCleanupThread
