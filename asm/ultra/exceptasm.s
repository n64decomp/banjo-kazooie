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
/* 2E60 80002260 3C1A8000 */  lui        $k0, %hi(__osException)
/* 2E64 80002264 275A2280 */  addiu      $k0, $k0, %lo(__osException)
/* 2E68 80002268 03400008 */  jr         $k0
/* 2E6C 8000226C 00000000 */   nop
endlabel __osExceptionPreamble

# What is this?
glabel __osExceptionPreamble2
/* 2E70 80002270 3C1A8000 */  lui        $k0, %hi(__osException)
/* 2E74 80002274 275A2280 */  addiu      $k0, $k0, %lo(__osException)
/* 2E78 80002278 03400008 */  jr         $k0
/* 2E7C 8000227C 00000000 */   nop
endlabel __osExceptionPreamble2

glabel __osException
/* 2E80 80002280 3C1A8000 */  lui        $k0, %hi(__osThreadSave)
/* 2E84 80002284 275A72C0 */  addiu      $k0, $k0, %lo(__osThreadSave)
/* 2E88 80002288 FF410020 */  sd         $at, 0x20($k0)
/* 2E8C 8000228C 401B6000 */  mfc0       $k1, $12
/* 2E90 80002290 AF5B0118 */  sw         $k1, 0x118($k0)
/* 2E94 80002294 2401FFFC */  addiu      $at, $zero, -4
/* 2E98 80002298 0361D824 */  and        $k1, $k1, $at
/* 2E9C 8000229C 409B6000 */  mtc0       $k1, $12
/* 2EA0 800022A0 FF480058 */  sd         $t0, 0x58($k0)
/* 2EA4 800022A4 FF490060 */  sd         $t1, 0x60($k0)
/* 2EA8 800022A8 FF4A0068 */  sd         $t2, 0x68($k0)
/* 2EAC 800022AC AF400018 */  sw         $zero, 0x18($k0)
/* 2EB0 800022B0 40086800 */  mfc0       $t0, $13
/* 2EB4 800022B4 03404025 */  or         $t0, $k0, $zero
/* 2EB8 800022B8 3C1A8000 */  lui        $k0, %hi(__osRunningThread)
/* 2EBC 800022BC 8F5A5130 */  lw         $k0, %lo(__osRunningThread)($k0)
/* 2EC0 800022C0 DD090020 */  ld         $t1, 0x20($t0)
/* 2EC4 800022C4 FF490020 */  sd         $t1, 0x20($k0)
/* 2EC8 800022C8 DD090118 */  ld         $t1, 0x118($t0)
/* 2ECC 800022CC FF490118 */  sd         $t1, 0x118($k0)
/* 2ED0 800022D0 DD090058 */  ld         $t1, 0x58($t0)
/* 2ED4 800022D4 FF490058 */  sd         $t1, 0x58($k0)
/* 2ED8 800022D8 DD090060 */  ld         $t1, 0x60($t0)
/* 2EDC 800022DC FF490060 */  sd         $t1, 0x60($k0)
/* 2EE0 800022E0 DD090068 */  ld         $t1, 0x68($t0)
/* 2EE4 800022E4 FF490068 */  sd         $t1, 0x68($k0)
/* 2EE8 800022E8 8F5B0118 */  lw         $k1, 0x118($k0)
/* 2EEC 800022EC 00004012 */  mflo       $t0
/* 2EF0 800022F0 FF480108 */  sd         $t0, 0x108($k0)
/* 2EF4 800022F4 00004010 */  mfhi       $t0
/* 2EF8 800022F8 3369FF00 */  andi       $t1, $k1, 0xff00
/* 2EFC 800022FC FF420028 */  sd         $v0, 0x28($k0)
/* 2F00 80002300 FF430030 */  sd         $v1, 0x30($k0)
/* 2F04 80002304 FF440038 */  sd         $a0, 0x38($k0)
/* 2F08 80002308 FF450040 */  sd         $a1, 0x40($k0)
/* 2F0C 8000230C FF460048 */  sd         $a2, 0x48($k0)
/* 2F10 80002310 FF470050 */  sd         $a3, 0x50($k0)
/* 2F14 80002314 FF4B0070 */  sd         $t3, 0x70($k0)
/* 2F18 80002318 FF4C0078 */  sd         $t4, 0x78($k0)
/* 2F1C 8000231C FF4D0080 */  sd         $t5, 0x80($k0)
/* 2F20 80002320 FF4E0088 */  sd         $t6, 0x88($k0)
/* 2F24 80002324 FF4F0090 */  sd         $t7, 0x90($k0)
/* 2F28 80002328 FF500098 */  sd         $s0, 0x98($k0)
/* 2F2C 8000232C FF5100A0 */  sd         $s1, 0xa0($k0)
/* 2F30 80002330 FF5200A8 */  sd         $s2, 0xa8($k0)
/* 2F34 80002334 FF5300B0 */  sd         $s3, 0xb0($k0)
/* 2F38 80002338 FF5400B8 */  sd         $s4, 0xb8($k0)
/* 2F3C 8000233C FF5500C0 */  sd         $s5, 0xc0($k0)
/* 2F40 80002340 FF5600C8 */  sd         $s6, 0xc8($k0)
/* 2F44 80002344 FF5700D0 */  sd         $s7, 0xd0($k0)
/* 2F48 80002348 FF5800D8 */  sd         $t8, 0xd8($k0)
/* 2F4C 8000234C FF5900E0 */  sd         $t9, 0xe0($k0)
/* 2F50 80002350 FF5C00E8 */  sd         $gp, 0xe8($k0)
/* 2F54 80002354 FF5D00F0 */  sd         $sp, 0xf0($k0)
/* 2F58 80002358 FF5E00F8 */  sd         $fp, 0xf8($k0)
/* 2F5C 8000235C FF5F0100 */  sd         $ra, 0x100($k0)
/* 2F60 80002360 1120000D */  beqz       $t1, .L80002398
/* 2F64 80002364 FF480110 */   sd        $t0, 0x110($k0)
/* 2F68 80002368 3C088000 */  lui        $t0, %hi(__OSGlobalIntMask)
/* 2F6C 8000236C 250850F0 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
/* 2F70 80002370 8D080000 */  lw         $t0, ($t0)
/* 2F74 80002374 2401FFFF */  addiu      $at, $zero, -1
/* 2F78 80002378 01014026 */  xor        $t0, $t0, $at
/* 2F7C 8000237C 3C01FFFF */  lui        $at, 0xffff
/* 2F80 80002380 3108FF00 */  andi       $t0, $t0, 0xff00
/* 2F84 80002384 342100FF */  ori        $at, $at, 0xff
/* 2F88 80002388 01284825 */  or         $t1, $t1, $t0
/* 2F8C 8000238C 0361D824 */  and        $k1, $k1, $at
/* 2F90 80002390 0369D825 */  or         $k1, $k1, $t1
/* 2F94 80002394 AF5B0118 */  sw         $k1, 0x118($k0)
.L80002398:
/* 2F98 80002398 3C09A430 */  lui        $t1, %hi(PHYS_TO_K1(MI_INTR_MASK_REG))
/* 2F9C 8000239C 8D29000C */  lw         $t1, %lo(PHYS_TO_K1(MI_INTR_MASK_REG))($t1)
/* 2FA0 800023A0 5120000C */  beql       $t1, $zero, .L800023D4
/* 2FA4 800023A4 AF490128 */   sw        $t1, 0x128($k0)
/* 2FA8 800023A8 3C088000 */  lui        $t0, %hi(__OSGlobalIntMask)
/* 2FAC 800023AC 250850F0 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
/* 2FB0 800023B0 8D080000 */  lw         $t0, ($t0)
/* 2FB4 800023B4 8F4C0128 */  lw         $t4, 0x128($k0)
/* 2FB8 800023B8 2401FFFF */  addiu      $at, $zero, -1
/* 2FBC 800023BC 00084402 */  srl        $t0, $t0, 0x10
/* 2FC0 800023C0 01014026 */  xor        $t0, $t0, $at
/* 2FC4 800023C4 3108003F */  andi       $t0, $t0, 0x3f
/* 2FC8 800023C8 010C4024 */  and        $t0, $t0, $t4
/* 2FCC 800023CC 01284825 */  or         $t1, $t1, $t0
/* 2FD0 800023D0 AF490128 */  sw         $t1, 0x128($k0)
.L800023D4:
/* 2FD4 800023D4 40087000 */  mfc0       $t0, $14
/* 2FD8 800023D8 AF48011C */  sw         $t0, 0x11c($k0)
/* 2FDC 800023DC 8F480018 */  lw         $t0, 0x18($k0)
/* 2FE0 800023E0 11000014 */  beqz       $t0, .L80002434
/* 2FE4 800023E4 00000000 */   nop
/* 2FE8 800023E8 4448F800 */  cfc1       $t0, $31
/* 2FEC 800023EC 00000000 */  nop
/* 2FF0 800023F0 AF48012C */  sw         $t0, 0x12c($k0)
/* 2FF4 800023F4 F7400130 */  sdc1       $f0, 0x130($k0)
/* 2FF8 800023F8 F7420138 */  sdc1       $f2, 0x138($k0)
/* 2FFC 800023FC F7440140 */  sdc1       $f4, 0x140($k0)
/* 3000 80002400 F7460148 */  sdc1       $f6, 0x148($k0)
/* 3004 80002404 F7480150 */  sdc1       $f8, 0x150($k0)
/* 3008 80002408 F74A0158 */  sdc1       $f10, 0x158($k0)
/* 300C 8000240C F74C0160 */  sdc1       $f12, 0x160($k0)
/* 3010 80002410 F74E0168 */  sdc1       $f14, 0x168($k0)
/* 3014 80002414 F7500170 */  sdc1       $f16, 0x170($k0)
/* 3018 80002418 F7520178 */  sdc1       $f18, 0x178($k0)
/* 301C 8000241C F7540180 */  sdc1       $f20, 0x180($k0)
/* 3020 80002420 F7560188 */  sdc1       $f22, 0x188($k0)
/* 3024 80002424 F7580190 */  sdc1       $f24, 0x190($k0)
/* 3028 80002428 F75A0198 */  sdc1       $f26, 0x198($k0)
/* 302C 8000242C F75C01A0 */  sdc1       $f28, 0x1a0($k0)
/* 3030 80002430 F75E01A8 */  sdc1       $f30, 0x1a8($k0)
.L80002434:
/* 3034 80002434 40086800 */  mfc0       $t0, $13
/* 3038 80002438 AF480120 */  sw         $t0, 0x120($k0)
/* 303C 8000243C 24090002 */  addiu      $t1, $zero, 2
/* 3040 80002440 A7490010 */  sh         $t1, 0x10($k0)
/* 3044 80002444 3109007C */  andi       $t1, $t0, 0x7c
/* 3048 80002448 240A0024 */  addiu      $t2, $zero, 0x24
/* 304C 8000244C 512A00B1 */  beql       $t1, $t2, handle_break
/* 3050 80002450 24090001 */   addiu     $t1, $zero, 1
/* 3054 80002454 240A002C */  addiu      $t2, $zero, 0x2c
/* 3058 80002458 112A00FF */  beq        $t1, $t2, handle_CpU
/* 305C 8000245C 00000000 */   nop
/* 3060 80002460 240A0000 */  addiu      $t2, $zero, 0
/* 3064 80002464 152A00C3 */  bne        $t1, $t2, .L80002774
/* 3068 80002468 00000000 */   nop
/* 306C 8000246C 03688024 */  and        $s0, $k1, $t0
next_interrupt:
/* 3070 80002470 3209FF00 */  andi       $t1, $s0, 0xff00
/* 3074 80002474 00095302 */  srl        $t2, $t1, 0xc
/* 3078 80002478 15400003 */  bnez       $t2, .L80002488
/* 307C 8000247C 00000000 */   nop
/* 3080 80002480 00095202 */  srl        $t2, $t1, 8
/* 3084 80002484 214A0010 */  addi       $t2, $t2, 0x10
.L80002488:
/* 3088 80002488 3C018000 */  lui        $at, %hi(__osIntOffTable)
/* 308C 8000248C 002A0821 */  addu       $at, $at, $t2
/* 3090 80002490 902A5180 */  lbu        $t2, %lo(__osIntOffTable)($at)
/* 3094 80002494 3C018000 */  lui        $at, %hi(__osIntTable)
/* 3098 80002498 002A0821 */  addu       $at, $at, $t2
/* 309C 8000249C 8C2A51A0 */  lw         $t2, %lo(__osIntTable)($at)
/* 30A0 800024A0 01400008 */  jr         $t2
/* 30A4 800024A4 00000000 */   nop
IP6_Hdlr:
/* 30A8 800024A8 2401DFFF */  addiu      $at, $zero, -0x2001
/* 30AC 800024AC 1000FFF0 */  b          next_interrupt
/* 30B0 800024B0 02018024 */   and       $s0, $s0, $at
IP7_Hdlr:
/* 30B4 800024B4 2401BFFF */  addiu      $at, $zero, -0x4001
/* 30B8 800024B8 1000FFED */  b          next_interrupt
/* 30BC 800024BC 02018024 */   and       $s0, $s0, $at
counter:
/* 30C0 800024C0 40095800 */  mfc0       $t1, $11
/* 30C4 800024C4 40895800 */  mtc0       $t1, $11
/* 30C8 800024C8 0C0009E9 */  jal        send_mesg
/* 30CC 800024CC 24040018 */   addiu     $a0, $zero, 0x18
/* 30D0 800024D0 3C01FFFF */  lui        $at, 0xffff
/* 30D4 800024D4 34217FFF */  ori        $at, $at, 0x7fff
/* 30D8 800024D8 1000FFE5 */  b          next_interrupt
/* 30DC 800024DC 02018024 */   and       $s0, $s0, $at
cart:
/* 30E0 800024E0 2401F7FF */  addiu      $at, $zero, -0x801
/* 30E4 800024E4 02018024 */  and        $s0, $s0, $at
/* 30E8 800024E8 240A0004 */  addiu      $t2, $zero, 4
/* 30EC 800024EC 3C018000 */  lui        $at, %hi(__osHwIntTable)
/* 30F0 800024F0 002A0821 */  addu       $at, $at, $t2
/* 30F4 800024F4 8C2A5100 */  lw         $t2, %lo(__osHwIntTable)($at)
/* 30F8 800024F8 3C1D8000 */  lui        $sp, %hi(leoDiskStack)
/* 30FC 800024FC 27BD7470 */  addiu      $sp, $sp, %lo(leoDiskStack)
/* 3100 80002500 24040010 */  addiu      $a0, $zero, 0x10
/* 3104 80002504 11400007 */  beqz       $t2, .L80002524
/* 3108 80002508 27BD0FF0 */   addiu     $sp, $sp, 0xff0
/* 310C 8000250C 0140F809 */  jalr       $t2
/* 3110 80002510 00000000 */   nop
/* 3114 80002514 10400003 */  beqz       $v0, .L80002524
/* 3118 80002518 00000000 */   nop
/* 311C 8000251C 10000082 */  b          redispatch
/* 3120 80002520 00000000 */   nop
.L80002524:
/* 3124 80002524 0C0009E9 */  jal        send_mesg
/* 3128 80002528 00000000 */   nop
/* 312C 8000252C 1000FFD1 */  b          next_interrupt + 4
/* 3130 80002530 3209FF00 */   andi      $t1, $s0, 0xff00
rcp:
/* 3134 80002534 3C088000 */  lui        $t0, %hi(__OSGlobalIntMask)
/* 3138 80002538 250850F0 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
/* 313C 8000253C 8D080000 */  lw         $t0, ($t0)
/* 3140 80002540 3C11A430 */  lui        $s1, %hi(PHYS_TO_K1(MI_INTR_REG))
/* 3144 80002544 8E310008 */  lw         $s1, %lo(PHYS_TO_K1(MI_INTR_REG))($s1)
/* 3148 80002548 00084402 */  srl        $t0, $t0, 0x10
/* 314C 8000254C 02288824 */  and        $s1, $s1, $t0
/* 3150 80002550 32290001 */  andi       $t1, $s1, 1
/* 3154 80002554 51200014 */  beql       $t1, $zero, .L800025A8
/* 3158 80002558 32290008 */   andi      $t1, $s1, 8
/* 315C 8000255C 3C0CA404 */  lui        $t4, %hi(PHYS_TO_K1(SP_STATUS_REG))
/* 3160 80002560 8D8C0010 */  lw         $t4, %lo(PHYS_TO_K1(SP_STATUS_REG))($t4)
/* 3164 80002564 24090008 */  addiu      $t1, $zero, 8
/* 3168 80002568 3C01A404 */  lui        $at, %hi(PHYS_TO_K1(SP_STATUS_REG))
/* 316C 8000256C 318C0300 */  andi       $t4, $t4, 0x300
/* 3170 80002570 3231003E */  andi       $s1, $s1, 0x3e
/* 3174 80002574 11800007 */  beqz       $t4, .L80002594
/* 3178 80002578 AC290010 */   sw        $t1, %lo(PHYS_TO_K1(SP_STATUS_REG))($at)
/* 317C 8000257C 0C0009E9 */  jal        send_mesg
/* 3180 80002580 24040020 */   addiu     $a0, $zero, 0x20
/* 3184 80002584 52200039 */  beql       $s1, $zero, .L8000266C
/* 3188 80002588 2401FBFF */   addiu     $at, $zero, -0x401
/* 318C 8000258C 10000006 */  b          .L800025A8
/* 3190 80002590 32290008 */   andi      $t1, $s1, 8
.L80002594:
/* 3194 80002594 0C0009E9 */  jal        send_mesg
/* 3198 80002598 24040058 */   addiu     $a0, $zero, 0x58
/* 319C 8000259C 52200033 */  beql       $s1, $zero, .L8000266C
/* 31A0 800025A0 2401FBFF */   addiu     $at, $zero, -0x401
/* 31A4 800025A4 32290008 */  andi       $t1, $s1, 8
.L800025A8:
/* 31A8 800025A8 11200007 */  beqz       $t1, .L800025C8
/* 31AC 800025AC 3C01A440 */   lui       $at, %hi(PHYS_TO_K1(VI_CURRENT_REG))
/* 31B0 800025B0 32310037 */  andi       $s1, $s1, 0x37
/* 31B4 800025B4 AC200010 */  sw         $zero, %lo(PHYS_TO_K1(VI_CURRENT_REG))($at)
/* 31B8 800025B8 0C0009E9 */  jal        send_mesg
/* 31BC 800025BC 24040038 */   addiu     $a0, $zero, 0x38
/* 31C0 800025C0 5220002A */  beql       $s1, $zero, .L8000266C
/* 31C4 800025C4 2401FBFF */   addiu     $at, $zero, -0x401
.L800025C8:
/* 31C8 800025C8 32290004 */  andi       $t1, $s1, 4
/* 31CC 800025CC 5120000A */  beql       $t1, $zero, .L800025F8
/* 31D0 800025D0 32290002 */   andi      $t1, $s1, 2
/* 31D4 800025D4 24090001 */  addiu      $t1, $zero, 1
/* 31D8 800025D8 3C01A450 */  lui        $at, %hi(PHYS_TO_K1(AI_STATUS_REG))
/* 31DC 800025DC 3231003B */  andi       $s1, $s1, 0x3b
/* 31E0 800025E0 AC29000C */  sw         $t1, %lo(PHYS_TO_K1(AI_STATUS_REG))($at)
/* 31E4 800025E4 0C0009E9 */  jal        send_mesg
/* 31E8 800025E8 24040030 */   addiu     $a0, $zero, 0x30
/* 31EC 800025EC 5220001F */  beql       $s1, $zero, .L8000266C
/* 31F0 800025F0 2401FBFF */   addiu     $at, $zero, -0x401
/* 31F4 800025F4 32290002 */  andi       $t1, $s1, 2
.L800025F8:
/* 31F8 800025F8 11200007 */  beqz       $t1, .L80002618
/* 31FC 800025FC 3C01A480 */   lui       $at, %hi(PHYS_TO_K1(SI_STATUS_REG))
/* 3200 80002600 3231003D */  andi       $s1, $s1, 0x3d
/* 3204 80002604 AC200018 */  sw         $zero, %lo(PHYS_TO_K1(SI_STATUS_REG))($at)
/* 3208 80002608 0C0009E9 */  jal        send_mesg
/* 320C 8000260C 24040028 */   addiu     $a0, $zero, 0x28
/* 3210 80002610 52200016 */  beql       $s1, $zero, .L8000266C
/* 3214 80002614 2401FBFF */   addiu     $at, $zero, -0x401
.L80002618:
/* 3218 80002618 32290010 */  andi       $t1, $s1, 0x10
/* 321C 8000261C 5120000A */  beql       $t1, $zero, .L80002648
/* 3220 80002620 32290020 */   andi      $t1, $s1, 0x20
/* 3224 80002624 24090002 */  addiu      $t1, $zero, 2
/* 3228 80002628 3C01A460 */  lui        $at, %hi(PHYS_TO_K1(PI_STATUS_REG))
/* 322C 8000262C 3231002F */  andi       $s1, $s1, 0x2f
/* 3230 80002630 AC290010 */  sw         $t1, %lo(PHYS_TO_K1(PI_STATUS_REG))($at)
/* 3234 80002634 0C0009E9 */  jal        send_mesg
/* 3238 80002638 24040040 */   addiu     $a0, $zero, 0x40
/* 323C 8000263C 5220000B */  beql       $s1, $zero, .L8000266C
/* 3240 80002640 2401FBFF */   addiu     $at, $zero, -0x401
/* 3244 80002644 32290020 */  andi       $t1, $s1, 0x20
.L80002648:
/* 3248 80002648 51200008 */  beql       $t1, $zero, .L8000266C
/* 324C 8000264C 2401FBFF */   addiu     $at, $zero, -0x401
/* 3250 80002650 24090800 */  addiu      $t1, $zero, 0x800
/* 3254 80002654 3C01A430 */  lui        $at, 0xa430
/* 3258 80002658 3231001F */  andi       $s1, $s1, 0x1f
/* 325C 8000265C AC290000 */  sw         $t1, ($at)
/* 3260 80002660 0C0009E9 */  jal        send_mesg
/* 3264 80002664 24040048 */   addiu     $a0, $zero, 0x48
/* 3268 80002668 2401FBFF */  addiu      $at, $zero, -0x401
.L8000266C:
/* 326C 8000266C 1000FF80 */  b          next_interrupt
/* 3270 80002670 02018024 */   and       $s0, $s0, $at
prenmi:
/* 3274 80002674 8F5B0118 */  lw         $k1, 0x118($k0)
/* 3278 80002678 2401EFFF */  addiu      $at, $zero, -0x1001
/* 327C 8000267C 3C098000 */  lui        $t1, %hi(__osShutdown)
/* 3280 80002680 0361D824 */  and        $k1, $k1, $at
/* 3284 80002684 AF5B0118 */  sw         $k1, 0x118($k0)
/* 3288 80002688 252950EC */  addiu      $t1, $t1, %lo(__osShutdown)
/* 328C 8000268C 8D2A0000 */  lw         $t2, ($t1)
/* 3290 80002690 11400003 */  beqz       $t2, firstnmi
/* 3294 80002694 2401EFFF */   addiu     $at, $zero, -0x1001
/* 3298 80002698 10000023 */  b          redispatch
/* 329C 8000269C 02018024 */   and       $s0, $s0, $at
firstnmi:
/* 32A0 800026A0 240A0001 */  addiu      $t2, $zero, 1
/* 32A4 800026A4 AD2A0000 */  sw         $t2, ($t1)
/* 32A8 800026A8 0C0009E9 */  jal        send_mesg
/* 32AC 800026AC 24040070 */   addiu     $a0, $zero, 0x70
/* 32B0 800026B0 3C0A8000 */  lui        $t2, %hi(__osRunQueue)
/* 32B4 800026B4 8D4A5128 */  lw         $t2, %lo(__osRunQueue)($t2)
/* 32B8 800026B8 2401EFFF */  addiu      $at, $zero, -0x1001
/* 32BC 800026BC 02018024 */  and        $s0, $s0, $at
/* 32C0 800026C0 8D5B0118 */  lw         $k1, 0x118($t2)
/* 32C4 800026C4 0361D824 */  and        $k1, $k1, $at
/* 32C8 800026C8 10000017 */  b          redispatch
/* 32CC 800026CC AD5B0118 */   sw        $k1, 0x118($t2)
sw2:
/* 32D0 800026D0 2401FDFF */  addiu      $at, $zero, -0x201
/* 32D4 800026D4 01014024 */  and        $t0, $t0, $at
/* 32D8 800026D8 40886800 */  mtc0       $t0, $13
/* 32DC 800026DC 0C0009E9 */  jal        send_mesg
/* 32E0 800026E0 24040008 */   addiu     $a0, $zero, 8
/* 32E4 800026E4 2401FDFF */  addiu      $at, $zero, -0x201
/* 32E8 800026E8 1000FF61 */  b          next_interrupt
/* 32EC 800026EC 02018024 */   and       $s0, $s0, $at
sw1:
/* 32F0 800026F0 2401FEFF */  addiu      $at, $zero, -0x101
/* 32F4 800026F4 01014024 */  and        $t0, $t0, $at
/* 32F8 800026F8 40886800 */  mtc0       $t0, $13
/* 32FC 800026FC 0C0009E9 */  jal        send_mesg
/* 3300 80002700 24040000 */   addiu     $a0, $zero, 0
/* 3304 80002704 2401FEFF */  addiu      $at, $zero, -0x101
/* 3308 80002708 1000FF59 */  b          next_interrupt
/* 330C 8000270C 02018024 */   and       $s0, $s0, $at
/* 3310 80002710 24090001 */  addiu      $t1, $zero, 1
handle_break:
/* 3314 80002714 A7490012 */  sh         $t1, 0x12($k0)
/* 3318 80002718 0C0009E9 */  jal        send_mesg
/* 331C 8000271C 24040050 */   addiu     $a0, $zero, 0x50
/* 3320 80002720 10000001 */  b          redispatch
/* 3324 80002724 00000000 */   nop
redispatch:
/* 3328 80002728 3C0A8000 */  lui        $t2, %hi(__osRunQueue)
/* 332C 8000272C 8D4A5128 */  lw         $t2, %lo(__osRunQueue)($t2)
/* 3330 80002730 8F490004 */  lw         $t1, 4($k0)
/* 3334 80002734 8D4B0004 */  lw         $t3, 4($t2)
/* 3338 80002738 012B082A */  slt        $at, $t1, $t3
/* 333C 8000273C 10200007 */  beqz       $at, enqueueRunning
/* 3340 80002740 00000000 */   nop
/* 3344 80002744 3C048000 */  lui        $a0, %hi(__osRunQueue)
/* 3348 80002748 03402825 */  or         $a1, $k0, $zero
/* 334C 8000274C 0C000A63 */  jal        __osEnqueueThread
/* 3350 80002750 24845128 */   addiu     $a0, $a0, %lo(__osRunQueue)
/* 3354 80002754 08000A79 */  j          __osDispatchThread
/* 3358 80002758 00000000 */   nop
enqueueRunning:
/* 335C 8000275C 3C098000 */  lui        $t1, %hi(__osRunQueue)
/* 3360 80002760 25295128 */  addiu      $t1, $t1, %lo(__osRunQueue)
/* 3364 80002764 8D2A0000 */  lw         $t2, ($t1)
/* 3368 80002768 AF4A0000 */  sw         $t2, ($k0)
/* 336C 8000276C 08000A79 */  j          __osDispatchThread
/* 3370 80002770 AD3A0000 */   sw        $k0, ($t1)
.L80002774:
/* 3374 80002774 3C018000 */  lui        $at, %hi(__osFaultedThread)
/* 3378 80002778 AC3A5134 */  sw         $k0, %lo(__osFaultedThread)($at)
/* 337C 8000277C 24090001 */  addiu      $t1, $zero, 1
/* 3380 80002780 A7490010 */  sh         $t1, 0x10($k0)
/* 3384 80002784 24090002 */  addiu      $t1, $zero, 2
/* 3388 80002788 A7490012 */  sh         $t1, 0x12($k0)
/* 338C 8000278C 400A4000 */  mfc0       $t2, $8
/* 3390 80002790 AF4A0124 */  sw         $t2, 0x124($k0)
/* 3394 80002794 0C0009E9 */  jal        send_mesg
/* 3398 80002798 24040060 */   addiu     $a0, $zero, 0x60
/* 339C 8000279C 08000A79 */  j          __osDispatchThread
/* 33A0 800027A0 00000000 */   nop
endlabel __osException

glabel send_mesg
/* 33A4 800027A4 3C0A8001 */  lui        $t2, %hi(__osEventStateTab)
/* 33A8 800027A8 254A8470 */  addiu      $t2, $t2, %lo(__osEventStateTab)
/* 33AC 800027AC 01445021 */  addu       $t2, $t2, $a0
/* 33B0 800027B0 8D490000 */  lw         $t1, ($t2)
/* 33B4 800027B4 03E09025 */  or         $s2, $ra, $zero
/* 33B8 800027B8 11200025 */  beqz       $t1, send_done
/* 33BC 800027BC 00000000 */   nop
/* 33C0 800027C0 8D2B0008 */  lw         $t3, 8($t1)
/* 33C4 800027C4 8D2C0010 */  lw         $t4, 0x10($t1)
/* 33C8 800027C8 016C082A */  slt        $at, $t3, $t4
/* 33CC 800027CC 10200020 */  beqz       $at, send_done
/* 33D0 800027D0 00000000 */   nop
/* 33D4 800027D4 8D2D000C */  lw         $t5, 0xc($t1)
/* 33D8 800027D8 01AB6821 */  addu       $t5, $t5, $t3
/* 33DC 800027DC 01AC001A */  div        $zero, $t5, $t4
/* 33E0 800027E0 15800002 */  bnez       $t4, .L800027EC
/* 33E4 800027E4 00000000 */   nop
/* 33E8 800027E8 0007000D */  break      7
.L800027EC:
/* 33EC 800027EC 2401FFFF */   addiu     $at, $zero, -1
/* 33F0 800027F0 15810004 */  bne        $t4, $at, .L80002804
/* 33F4 800027F4 3C018000 */   lui       $at, 0x8000
/* 33F8 800027F8 15A10002 */  bne        $t5, $at, .L80002804
/* 33FC 800027FC 00000000 */   nop
/* 3400 80002800 0006000D */  break      6
.L80002804:
/* 3404 80002804 8D2C0014 */   lw        $t4, 0x14($t1)
/* 3408 80002808 00006810 */  mfhi       $t5
/* 340C 8000280C 000D6880 */  sll        $t5, $t5, 2
/* 3410 80002810 018D6021 */  addu       $t4, $t4, $t5
/* 3414 80002814 8D4D0004 */  lw         $t5, 4($t2)
/* 3418 80002818 256A0001 */  addiu      $t2, $t3, 1
/* 341C 8000281C AD8D0000 */  sw         $t5, ($t4)
/* 3420 80002820 AD2A0008 */  sw         $t2, 8($t1)
/* 3424 80002824 8D2A0000 */  lw         $t2, ($t1)
/* 3428 80002828 8D4B0000 */  lw         $t3, ($t2)
/* 342C 8000282C 11600008 */  beqz       $t3, send_done
/* 3430 80002830 00000000 */   nop
/* 3434 80002834 0C000A75 */  jal        __osPopThread
/* 3438 80002838 01202025 */   or        $a0, $t1, $zero
/* 343C 8000283C 00405025 */  or         $t2, $v0, $zero
/* 3440 80002840 3C048000 */  lui        $a0, %hi(__osRunQueue)
/* 3444 80002844 01402825 */  or         $a1, $t2, $zero
/* 3448 80002848 0C000A63 */  jal        __osEnqueueThread
/* 344C 8000284C 24845128 */   addiu     $a0, $a0, %lo(__osRunQueue)
send_done:
/* 3450 80002850 02400008 */  jr         $s2
/* 3454 80002854 00000000 */   nop
endlabel send_mesg

glabel handle_CpU
/* 3458 80002858 3C013000 */  lui        $at, 0x3000
/* 345C 8000285C 01014824 */  and        $t1, $t0, $at
/* 3460 80002860 00094F02 */  srl        $t1, $t1, 0x1c
/* 3464 80002864 240A0001 */  addiu      $t2, $zero, 1
/* 3468 80002868 152AFFC2 */  bne        $t1, $t2, .L80002774
/* 346C 8000286C 00000000 */   nop
/* 3470 80002870 8F5B0118 */  lw         $k1, 0x118($k0)
/* 3474 80002874 3C012000 */  lui        $at, 0x2000
/* 3478 80002878 24090001 */  addiu      $t1, $zero, 1
/* 347C 8000287C 0361D825 */  or         $k1, $k1, $at
/* 3480 80002880 AF490018 */  sw         $t1, 0x18($k0)
/* 3484 80002884 1000FFB5 */  b          enqueueRunning
/* 3488 80002888 AF5B0118 */   sw        $k1, 0x118($k0)
endlabel handle_CpU

glabel __osEnqueueAndYield
/* 348C 8000288C 3C058000 */  lui        $a1, %hi(__osRunningThread)
/* 3490 80002890 8CA55130 */  lw         $a1, %lo(__osRunningThread)($a1)
/* 3494 80002894 40086000 */  mfc0       $t0, $12
/* 3498 80002898 8CBB0018 */  lw         $k1, 0x18($a1)
/* 349C 8000289C 35080002 */  ori        $t0, $t0, 2
/* 34A0 800028A0 ACA80118 */  sw         $t0, 0x118($a1)
/* 34A4 800028A4 FCB00098 */  sd         $s0, 0x98($a1)
/* 34A8 800028A8 FCB100A0 */  sd         $s1, 0xa0($a1)
/* 34AC 800028AC FCB200A8 */  sd         $s2, 0xa8($a1)
/* 34B0 800028B0 FCB300B0 */  sd         $s3, 0xb0($a1)
/* 34B4 800028B4 FCB400B8 */  sd         $s4, 0xb8($a1)
/* 34B8 800028B8 FCB500C0 */  sd         $s5, 0xc0($a1)
/* 34BC 800028BC FCB600C8 */  sd         $s6, 0xc8($a1)
/* 34C0 800028C0 FCB700D0 */  sd         $s7, 0xd0($a1)
/* 34C4 800028C4 FCBC00E8 */  sd         $gp, 0xe8($a1)
/* 34C8 800028C8 FCBD00F0 */  sd         $sp, 0xf0($a1)
/* 34CC 800028CC FCBE00F8 */  sd         $fp, 0xf8($a1)
/* 34D0 800028D0 FCBF0100 */  sd         $ra, 0x100($a1)
/* 34D4 800028D4 13600009 */  beqz       $k1, .L800028FC
/* 34D8 800028D8 ACBF011C */   sw        $ra, 0x11c($a1)
/* 34DC 800028DC 445BF800 */  cfc1       $k1, $31
/* 34E0 800028E0 F4B40180 */  sdc1       $f20, 0x180($a1)
/* 34E4 800028E4 F4B60188 */  sdc1       $f22, 0x188($a1)
/* 34E8 800028E8 F4B80190 */  sdc1       $f24, 0x190($a1)
/* 34EC 800028EC F4BA0198 */  sdc1       $f26, 0x198($a1)
/* 34F0 800028F0 F4BC01A0 */  sdc1       $f28, 0x1a0($a1)
/* 34F4 800028F4 F4BE01A8 */  sdc1       $f30, 0x1a8($a1)
/* 34F8 800028F8 ACBB012C */  sw         $k1, 0x12c($a1)
.L800028FC:
/* 34FC 800028FC 8CBB0118 */  lw         $k1, 0x118($a1)
/* 3500 80002900 3369FF00 */  andi       $t1, $k1, 0xff00
/* 3504 80002904 5120000E */  beql       $t1, $zero, .L80002940
/* 3508 80002908 3C1BA430 */   lui       $k1, 0xa430
/* 350C 8000290C 3C088000 */  lui        $t0, %hi(__OSGlobalIntMask)
/* 3510 80002910 250850F0 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
/* 3514 80002914 8D080000 */  lw         $t0, ($t0)
/* 3518 80002918 2401FFFF */  addiu      $at, $zero, -1
/* 351C 8000291C 01014026 */  xor        $t0, $t0, $at
/* 3520 80002920 3C01FFFF */  lui        $at, 0xffff
/* 3524 80002924 3108FF00 */  andi       $t0, $t0, 0xff00
/* 3528 80002928 342100FF */  ori        $at, $at, 0xff
/* 352C 8000292C 01284825 */  or         $t1, $t1, $t0
/* 3530 80002930 0361D824 */  and        $k1, $k1, $at
/* 3534 80002934 0369D825 */  or         $k1, $k1, $t1
/* 3538 80002938 ACBB0118 */  sw         $k1, 0x118($a1)
/* 353C 8000293C 3C1BA430 */  lui        $k1, %hi(PHYS_TO_K1(MI_INTR_MASK_REG))
.L80002940:
/* 3540 80002940 8F7B000C */  lw         $k1, %lo(PHYS_TO_K1(MI_INTR_MASK_REG))($k1)
/* 3544 80002944 1360000B */  beqz       $k1, .L80002974
/* 3548 80002948 00000000 */   nop
/* 354C 8000294C 3C1A8000 */  lui        $k0, %hi(__OSGlobalIntMask)
/* 3550 80002950 275A50F0 */  addiu      $k0, $k0, %lo(__OSGlobalIntMask)
/* 3554 80002954 8F5A0000 */  lw         $k0, ($k0)
/* 3558 80002958 8CA80128 */  lw         $t0, 0x128($a1)
/* 355C 8000295C 2401FFFF */  addiu      $at, $zero, -1
/* 3560 80002960 001AD402 */  srl        $k0, $k0, 0x10
/* 3564 80002964 0341D026 */  xor        $k0, $k0, $at
/* 3568 80002968 335A003F */  andi       $k0, $k0, 0x3f
/* 356C 8000296C 0348D024 */  and        $k0, $k0, $t0
/* 3570 80002970 037AD825 */  or         $k1, $k1, $k0
.L80002974:
/* 3574 80002974 10800003 */  beqz       $a0, .L80002984
/* 3578 80002978 ACBB0128 */   sw        $k1, 0x128($a1)
/* 357C 8000297C 0C000A63 */  jal        __osEnqueueThread
/* 3580 80002980 00000000 */   nop
.L80002984:
/* 3584 80002984 08000A79 */  j          __osDispatchThread
/* 3588 80002988 00000000 */   nop
endlabel __osEnqueueAndYield

glabel __osEnqueueThread
/* 358C 8000298C 8C980000 */  lw         $t8, ($a0)
/* 3590 80002990 8CAF0004 */  lw         $t7, 4($a1)
/* 3594 80002994 0080C825 */  or         $t9, $a0, $zero
/* 3598 80002998 8F0E0004 */  lw         $t6, 4($t8)
/* 359C 8000299C 01CF082A */  slt        $at, $t6, $t7
/* 35A0 800029A0 54200008 */  bnel       $at, $zero, .L800029C4
/* 35A4 800029A4 8F380000 */   lw        $t8, ($t9)
/* 35A8 800029A8 0300C825 */  or         $t9, $t8, $zero
.L800029AC:
/* 35AC 800029AC 8F180000 */  lw         $t8, ($t8)
/* 35B0 800029B0 8F0E0004 */  lw         $t6, 4($t8)
/* 35B4 800029B4 01CF082A */  slt        $at, $t6, $t7
/* 35B8 800029B8 5020FFFC */  beql       $at, $zero, .L800029AC
/* 35BC 800029BC 0300C825 */   or        $t9, $t8, $zero
/* 35C0 800029C0 8F380000 */  lw         $t8, ($t9)
.L800029C4:
/* 35C4 800029C4 ACB80000 */  sw         $t8, ($a1)
/* 35C8 800029C8 AF250000 */  sw         $a1, ($t9)
/* 35CC 800029CC 03E00008 */  jr         $ra
/* 35D0 800029D0 ACA40008 */   sw        $a0, 8($a1)
endlabel __osEnqueueThread

glabel __osPopThread
/* 35D4 800029D4 8C820000 */  lw         $v0, ($a0)
/* 35D8 800029D8 8C590000 */  lw         $t9, ($v0)
/* 35DC 800029DC 03E00008 */  jr         $ra
/* 35E0 800029E0 AC990000 */   sw        $t9, ($a0)
endlabel __osPopThread

glabel __osDispatchThread
/* 35E4 800029E4 3C048000 */  lui        $a0, %hi(__osRunQueue)
/* 35E8 800029E8 0C000A75 */  jal        __osPopThread
/* 35EC 800029EC 24845128 */   addiu     $a0, $a0, %lo(__osRunQueue)
/* 35F0 800029F0 3C018000 */  lui        $at, %hi(__osRunningThread)
/* 35F4 800029F4 AC225130 */  sw         $v0, %lo(__osRunningThread)($at)
/* 35F8 800029F8 24080004 */  addiu      $t0, $zero, 4
/* 35FC 800029FC A4480010 */  sh         $t0, 0x10($v0)
/* 3600 80002A00 0040D025 */  or         $k0, $v0, $zero
/* 3604 80002A04 3C088000 */  lui        $t0, %hi(__OSGlobalIntMask)
/* 3608 80002A08 8F5B0118 */  lw         $k1, 0x118($k0)
/* 360C 80002A0C 250850F0 */  addiu      $t0, $t0, %lo(__OSGlobalIntMask)
/* 3610 80002A10 8D080000 */  lw         $t0, ($t0)
/* 3614 80002A14 3C01FFFF */  lui        $at, 0xffff
/* 3618 80002A18 3369FF00 */  andi       $t1, $k1, 0xff00
/* 361C 80002A1C 342100FF */  ori        $at, $at, 0xff
/* 3620 80002A20 3108FF00 */  andi       $t0, $t0, 0xff00
/* 3624 80002A24 01284824 */  and        $t1, $t1, $t0
/* 3628 80002A28 0361D824 */  and        $k1, $k1, $at
/* 362C 80002A2C 0369D825 */  or         $k1, $k1, $t1
/* 3630 80002A30 409B6000 */  mtc0       $k1, $12
/* 3634 80002A34 DF5B0108 */  ld         $k1, 0x108($k0)
/* 3638 80002A38 DF410020 */  ld         $at, 0x20($k0)
/* 363C 80002A3C DF420028 */  ld         $v0, 0x28($k0)
/* 3640 80002A40 03600013 */  mtlo       $k1
/* 3644 80002A44 DF5B0110 */  ld         $k1, 0x110($k0)
/* 3648 80002A48 DF430030 */  ld         $v1, 0x30($k0)
/* 364C 80002A4C DF440038 */  ld         $a0, 0x38($k0)
/* 3650 80002A50 DF450040 */  ld         $a1, 0x40($k0)
/* 3654 80002A54 DF460048 */  ld         $a2, 0x48($k0)
/* 3658 80002A58 DF470050 */  ld         $a3, 0x50($k0)
/* 365C 80002A5C DF480058 */  ld         $t0, 0x58($k0)
/* 3660 80002A60 DF490060 */  ld         $t1, 0x60($k0)
/* 3664 80002A64 DF4A0068 */  ld         $t2, 0x68($k0)
/* 3668 80002A68 DF4B0070 */  ld         $t3, 0x70($k0)
/* 366C 80002A6C DF4C0078 */  ld         $t4, 0x78($k0)
/* 3670 80002A70 DF4D0080 */  ld         $t5, 0x80($k0)
/* 3674 80002A74 DF4E0088 */  ld         $t6, 0x88($k0)
/* 3678 80002A78 DF4F0090 */  ld         $t7, 0x90($k0)
/* 367C 80002A7C DF500098 */  ld         $s0, 0x98($k0)
/* 3680 80002A80 DF5100A0 */  ld         $s1, 0xa0($k0)
/* 3684 80002A84 DF5200A8 */  ld         $s2, 0xa8($k0)
/* 3688 80002A88 DF5300B0 */  ld         $s3, 0xb0($k0)
/* 368C 80002A8C DF5400B8 */  ld         $s4, 0xb8($k0)
/* 3690 80002A90 DF5500C0 */  ld         $s5, 0xc0($k0)
/* 3694 80002A94 DF5600C8 */  ld         $s6, 0xc8($k0)
/* 3698 80002A98 DF5700D0 */  ld         $s7, 0xd0($k0)
/* 369C 80002A9C DF5800D8 */  ld         $t8, 0xd8($k0)
/* 36A0 80002AA0 DF5900E0 */  ld         $t9, 0xe0($k0)
/* 36A4 80002AA4 DF5C00E8 */  ld         $gp, 0xe8($k0)
/* 36A8 80002AA8 03600011 */  mthi       $k1
/* 36AC 80002AAC DF5D00F0 */  ld         $sp, 0xf0($k0)
/* 36B0 80002AB0 DF5E00F8 */  ld         $fp, 0xf8($k0)
/* 36B4 80002AB4 DF5F0100 */  ld         $ra, 0x100($k0)
/* 36B8 80002AB8 8F5B011C */  lw         $k1, 0x11c($k0)
/* 36BC 80002ABC 409B7000 */  mtc0       $k1, $14
/* 36C0 80002AC0 8F5B0018 */  lw         $k1, 0x18($k0)
/* 36C4 80002AC4 13600013 */  beqz       $k1, .L80002B14
/* 36C8 80002AC8 00000000 */   nop
/* 36CC 80002ACC 8F5B012C */  lw         $k1, 0x12c($k0)
/* 36D0 80002AD0 44DBF800 */  ctc1       $k1, $31
/* 36D4 80002AD4 D7400130 */  ldc1       $f0, 0x130($k0)
/* 36D8 80002AD8 D7420138 */  ldc1       $f2, 0x138($k0)
/* 36DC 80002ADC D7440140 */  ldc1       $f4, 0x140($k0)
/* 36E0 80002AE0 D7460148 */  ldc1       $f6, 0x148($k0)
/* 36E4 80002AE4 D7480150 */  ldc1       $f8, 0x150($k0)
/* 36E8 80002AE8 D74A0158 */  ldc1       $f10, 0x158($k0)
/* 36EC 80002AEC D74C0160 */  ldc1       $f12, 0x160($k0)
/* 36F0 80002AF0 D74E0168 */  ldc1       $f14, 0x168($k0)
/* 36F4 80002AF4 D7500170 */  ldc1       $f16, 0x170($k0)
/* 36F8 80002AF8 D7520178 */  ldc1       $f18, 0x178($k0)
/* 36FC 80002AFC D7540180 */  ldc1       $f20, 0x180($k0)
/* 3700 80002B00 D7560188 */  ldc1       $f22, 0x188($k0)
/* 3704 80002B04 D7580190 */  ldc1       $f24, 0x190($k0)
/* 3708 80002B08 D75A0198 */  ldc1       $f26, 0x198($k0)
/* 370C 80002B0C D75C01A0 */  ldc1       $f28, 0x1a0($k0)
/* 3710 80002B10 D75E01A8 */  ldc1       $f30, 0x1a8($k0)
.L80002B14:
/* 3714 80002B14 8F5B0128 */  lw         $k1, 0x128($k0)
/* 3718 80002B18 3C1A8000 */  lui        $k0, %hi(__OSGlobalIntMask)
/* 371C 80002B1C 275A50F0 */  addiu      $k0, $k0, %lo(__OSGlobalIntMask)
/* 3720 80002B20 8F5A0000 */  lw         $k0, ($k0)
/* 3724 80002B24 001AD402 */  srl        $k0, $k0, 0x10
/* 3728 80002B28 037AD824 */  and        $k1, $k1, $k0
/* 372C 80002B2C 001BD840 */  sll        $k1, $k1, 1
/* 3730 80002B30 3C1A8000 */  lui        $k0, %hi(__osRcpImTable)
/* 3734 80002B34 275A51D0 */  addiu      $k0, $k0, %lo(__osRcpImTable)
/* 3738 80002B38 037AD821 */  addu       $k1, $k1, $k0
/* 373C 80002B3C 977B0000 */  lhu        $k1, ($k1)
/* 3740 80002B40 3C1AA430 */  lui        $k0, %hi(PHYS_TO_K1(MI_INTR_MASK_REG))
/* 3744 80002B44 275A000C */  addiu      $k0, $k0, %lo(PHYS_TO_K1(MI_INTR_MASK_REG))
/* 3748 80002B48 AF5B0000 */  sw         $k1, ($k0)
/* 374C 80002B4C 00000000 */  nop
/* 3750 80002B50 00000000 */  nop
/* 3754 80002B54 00000000 */  nop
/* 3758 80002B58 00000000 */  nop
/* 375C 80002B5C 42000018 */  eret
endlabel __osDispatchThread

glabel __osCleanupThread
/* 3760 80002B60 0C000EB4 */  jal        osDestroyThread
/* 3764 80002B64 00002025 */   or        $a0, $zero, $zero
/* 3768 80002B68 00000000 */  nop
/* 376C 80002B6C 00000000 */  nop
endlabel __osCleanupThread
