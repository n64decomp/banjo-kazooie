glabel func_80386570
/* 180 80386570 27BDFFE0 */  addiu      $sp, $sp, -0x20
/* 184 80386574 AFBF0014 */  sw         $ra, 0x14($sp)
/* 188 80386578 AFA40020 */  sw         $a0, 0x20($sp)
/* 18C 8038657C AFA50024 */  sw         $a1, 0x24($sp)
/* 190 80386580 AFA60028 */  sw         $a2, 0x28($sp)
/* 194 80386584 0C0CA656 */  jal        marker_getActor
/* 198 80386588 AFA7002C */   sw        $a3, 0x2c($sp)
/* 19C 8038658C 244E007C */  addiu      $t6, $v0, 0x7c
/* 1A0 80386590 AFAE0018 */  sw         $t6, 0x18($sp)
/* 1A4 80386594 90450089 */  lbu        $a1, 0x89($v0)
/* 1A8 80386598 0C0CE917 */  jal        func_8033A45C
/* 1AC 8038659C 24040003 */   addiu     $a0, $zero, 3
/* 1B0 803865A0 8FAF0018 */  lw         $t7, 0x18($sp)
/* 1B4 803865A4 24040004 */  addiu      $a0, $zero, 4
/* 1B8 803865A8 0C0CE917 */  jal        func_8033A45C
/* 1BC 803865AC 91E5000E */   lbu       $a1, 0xe($t7)
/* 1C0 803865B0 8FB80018 */  lw         $t8, 0x18($sp)
/* 1C4 803865B4 24040005 */  addiu      $a0, $zero, 5
/* 1C8 803865B8 0C0CE917 */  jal        func_8033A45C
/* 1CC 803865BC 9305000C */   lbu       $a1, 0xc($t8)
/* 1D0 803865C0 8FB90018 */  lw         $t9, 0x18($sp)
/* 1D4 803865C4 24010001 */  addiu      $at, $zero, 1
/* 1D8 803865C8 93280000 */  lbu        $t0, ($t9)
/* 1DC 803865CC 55010004 */  bnel       $t0, $at, .L803865E0
/* 1E0 803865D0 8FA40020 */   lw        $a0, 0x20($sp)
/* 1E4 803865D4 0C0CE897 */  jal        func_8033A25C
/* 1E8 803865D8 00002025 */   or        $a0, $zero, $zero
/* 1EC 803865DC 8FA40020 */  lw         $a0, 0x20($sp)
.L803865E0:
/* 1F0 803865E0 8FA50024 */  lw         $a1, 0x24($sp)
/* 1F4 803865E4 8FA60028 */  lw         $a2, 0x28($sp)
/* 1F8 803865E8 0C0C9622 */  jal        func_80325888
/* 1FC 803865EC 8FA7002C */   lw        $a3, 0x2c($sp)
/* 200 803865F0 8FBF0014 */  lw         $ra, 0x14($sp)
/* 204 803865F4 27BD0020 */  addiu      $sp, $sp, 0x20
/* 208 803865F8 03E00008 */  jr         $ra
/* 20C 803865FC 00000000 */   nop
glabel func_80386600
/* 210 80386600 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 214 80386604 AFBF0014 */  sw         $ra, 0x14($sp)
/* 218 80386608 0C0CA656 */  jal        marker_getActor
/* 21C 8038660C AFA5001C */   sw        $a1, 0x1c($sp)
/* 220 80386610 8FAE001C */  lw         $t6, 0x1c($sp)
/* 224 80386614 A04E0088 */  sb         $t6, 0x88($v0)
/* 228 80386618 8FBF0014 */  lw         $ra, 0x14($sp)
/* 22C 8038661C 27BD0018 */  addiu      $sp, $sp, 0x18
/* 230 80386620 03E00008 */  jr         $ra
/* 234 80386624 00000000 */   nop
glabel func_80386628
/* 238 80386628 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 23C 8038662C AFBF0014 */  sw         $ra, 0x14($sp)
/* 240 80386630 0C0CA656 */  jal        marker_getActor
/* 244 80386634 AFA5001C */   sw        $a1, 0x1c($sp)
/* 248 80386638 8FA3001C */  lw         $v1, 0x1c($sp)
/* 24C 8038663C A0430089 */  sb         $v1, 0x89($v0)
/* 250 80386640 A043008A */  sb         $v1, 0x8a($v0)
/* 254 80386644 8FBF0014 */  lw         $ra, 0x14($sp)
/* 258 80386648 27BD0018 */  addiu      $sp, $sp, 0x18
/* 25C 8038664C 03E00008 */  jr         $ra
/* 260 80386650 00000000 */   nop
glabel func_80386654
/* 264 80386654 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 268 80386658 AFBF0014 */  sw         $ra, 0x14($sp)
/* 26C 8038665C E7AC0018 */  swc1       $f12, 0x18($sp)
/* 270 80386660 AFA5001C */  sw         $a1, 0x1c($sp)
/* 274 80386664 AFA60020 */  sw         $a2, 0x20($sp)
/* 278 80386668 0C0D314A */  jal        func_8034C528
/* 27C 8038666C 24040190 */   addiu     $a0, $zero, 0x190
/* 280 80386670 10400005 */  beqz       $v0, .L80386688
/* 284 80386674 00402025 */   or        $a0, $v0, $zero
/* 288 80386678 8FA5001C */  lw         $a1, 0x1c($sp)
/* 28C 8038667C 8FA60020 */  lw         $a2, 0x20($sp)
/* 290 80386680 0C0D37CC */  jal        func_8034DF30
/* 294 80386684 8FA70018 */   lw        $a3, 0x18($sp)
.L80386688:
/* 298 80386688 8FBF0014 */  lw         $ra, 0x14($sp)
/* 29C 8038668C 27BD0018 */  addiu      $sp, $sp, 0x18
/* 2A0 80386690 03E00008 */  jr         $ra
/* 2A4 80386694 00000000 */   nop
glabel func_80386698
/* 2A8 80386698 27BDFFE0 */  addiu      $sp, $sp, -0x20
/* 2AC 8038669C AFBF001C */  sw         $ra, 0x1c($sp)
/* 2B0 803866A0 E7AC0020 */  swc1       $f12, 0x20($sp)
/* 2B4 803866A4 0C0D314A */  jal        func_8034C528
/* 2B8 803866A8 2404019A */   addiu     $a0, $zero, 0x19a
/* 2BC 803866AC 10400009 */  beqz       $v0, .L803866D4
/* 2C0 803866B0 00402025 */   or        $a0, $v0, $zero
/* 2C4 803866B4 3C058039 */  lui        $a1, %hi(D_80391524)
/* 2C8 803866B8 3C068039 */  lui        $a2, %hi(D_80391530)
/* 2CC 803866BC 240E0001 */  addiu      $t6, $zero, 1
/* 2D0 803866C0 AFAE0010 */  sw         $t6, 0x10($sp)
/* 2D4 803866C4 24C61530 */  addiu      $a2, $a2, %lo(D_80391530)
/* 2D8 803866C8 24A51524 */  addiu      $a1, $a1, %lo(D_80391524)
/* 2DC 803866CC 0C0D377C */  jal        func_8034DDF0
/* 2E0 803866D0 8FA70020 */   lw        $a3, 0x20($sp)
.L803866D4:
/* 2E4 803866D4 8FBF001C */  lw         $ra, 0x1c($sp)
/* 2E8 803866D8 27BD0020 */  addiu      $sp, $sp, 0x20
/* 2EC 803866DC 03E00008 */  jr         $ra
/* 2F0 803866E0 00000000 */   nop
glabel func_803866E4
/* 2F4 803866E4 27BDFFD0 */  addiu      $sp, $sp, -0x30
/* 2F8 803866E8 AFBF002C */  sw         $ra, 0x2c($sp)
/* 2FC 803866EC AFA40030 */  sw         $a0, 0x30($sp)
/* 300 803866F0 AFB00028 */  sw         $s0, 0x28($sp)
/* 304 803866F4 AFA50034 */  sw         $a1, 0x34($sp)
/* 308 803866F8 AFA60038 */  sw         $a2, 0x38($sp)
/* 30C 803866FC 0C0BC2F4 */  jal        partEmitList_pushNew
/* 310 80386700 00C02025 */   or        $a0, $a2, $zero
/* 314 80386704 00408025 */  or         $s0, $v0, $zero
/* 318 80386708 00402025 */  or         $a0, $v0, $zero
/* 31C 8038670C 0C0BBEB2 */  jal        particleEmitter_setModel
/* 320 80386710 8FA50034 */   lw        $a1, 0x34($sp)
/* 324 80386714 02002025 */  or         $a0, $s0, $zero
/* 328 80386718 0C0BBED5 */  jal        particleEmitter_setPosition
/* 32C 8038671C 8FA50030 */   lw        $a1, 0x30($sp)
/* 330 80386720 3C01C396 */  lui        $at, 0xc396
/* 334 80386724 44810000 */  mtc1       $at, $f0
/* 338 80386728 3C014396 */  lui        $at, 0x4396
/* 33C 8038672C 44811000 */  mtc1       $at, $f2
/* 340 80386730 44050000 */  mfc1       $a1, $f0
/* 344 80386734 44060000 */  mfc1       $a2, $f0
/* 348 80386738 44070000 */  mfc1       $a3, $f0
/* 34C 8038673C 02002025 */  or         $a0, $s0, $zero
/* 350 80386740 E7A20010 */  swc1       $f2, 0x10($sp)
/* 354 80386744 E7A20014 */  swc1       $f2, 0x14($sp)
/* 358 80386748 0C0BBF89 */  jal        func_802EFE24
/* 35C 8038674C E7A20018 */   swc1      $f2, 0x18($sp)
/* 360 80386750 3C058039 */  lui        $a1, %hi(D_80391564)
/* 364 80386754 24A51564 */  addiu      $a1, $a1, %lo(D_80391564)
/* 368 80386758 0C0BBF5F */  jal        particleEmitter_setPositionVelocityAndAccelerationRanges
/* 36C 8038675C 02002025 */   or        $a0, $s0, $zero
/* 370 80386760 3C058039 */  lui        $a1, %hi(D_8039153C)
/* 374 80386764 24A5153C */  addiu      $a1, $a1, %lo(D_8039153C)
/* 378 80386768 0C0BBEE6 */  jal        func_802EFB98
/* 37C 8038676C 02002025 */   or        $a0, $s0, $zero
/* 380 80386770 02002025 */  or         $a0, $s0, $zero
/* 384 80386774 0C0BBE9E */  jal        func_802EFA78
/* 388 80386778 24050001 */   addiu     $a1, $zero, 1
/* 38C 8038677C 02002025 */  or         $a0, $s0, $zero
/* 390 80386780 0C0BBD72 */  jal        particleEmitter_emitN
/* 394 80386784 8FA50038 */   lw        $a1, 0x38($sp)
/* 398 80386788 8FBF002C */  lw         $ra, 0x2c($sp)
/* 39C 8038678C 8FB00028 */  lw         $s0, 0x28($sp)
/* 3A0 80386790 27BD0030 */  addiu      $sp, $sp, 0x30
/* 3A4 80386794 03E00008 */  jr         $ra
/* 3A8 80386798 00000000 */   nop
glabel func_8038679C
/* 3AC 8038679C 27BDFFE0 */  addiu      $sp, $sp, -0x20
/* 3B0 803867A0 AFBF001C */  sw         $ra, 0x1c($sp)
/* 3B4 803867A4 AFA40020 */  sw         $a0, 0x20($sp)
/* 3B8 803867A8 AFB00018 */  sw         $s0, 0x18($sp)
/* 3BC 803867AC AFA50024 */  sw         $a1, 0x24($sp)
/* 3C0 803867B0 AFA60028 */  sw         $a2, 0x28($sp)
/* 3C4 803867B4 0C0BC2F4 */  jal        partEmitList_pushNew
/* 3C8 803867B8 00A02025 */   or        $a0, $a1, $zero
/* 3CC 803867BC 00408025 */  or         $s0, $v0, $zero
/* 3D0 803867C0 00402025 */  or         $a0, $v0, $zero
/* 3D4 803867C4 0C0BBE54 */  jal        particleEmitter_setSprite
/* 3D8 803867C8 2405070E */   addiu     $a1, $zero, 0x70e
/* 3DC 803867CC 3C058039 */  lui        $a1, %hi(D_803915AC)
/* 3E0 803867D0 24A515AC */  addiu      $a1, $a1, %lo(D_803915AC)
/* 3E4 803867D4 0C0BBFEA */  jal        func_802EFFA8
/* 3E8 803867D8 02002025 */   or        $a0, $s0, $zero
/* 3EC 803867DC 02002025 */  or         $a0, $s0, $zero
/* 3F0 803867E0 00002825 */  or         $a1, $zero, $zero
/* 3F4 803867E4 0C0BBEA4 */  jal        particleEmitter_setStartingFrameRange
/* 3F8 803867E8 24060007 */   addiu     $a2, $zero, 7
/* 3FC 803867EC 02002025 */  or         $a0, $s0, $zero
/* 400 803867F0 0C0BBED5 */  jal        particleEmitter_setPosition
/* 404 803867F4 8FA50020 */   lw        $a1, 0x20($sp)
/* 408 803867F8 3C058039 */  lui        $a1, %hi(D_803915B8)
/* 40C 803867FC 24A515B8 */  addiu      $a1, $a1, %lo(D_803915B8)
/* 410 80386800 0C0BBF40 */  jal        particleEmitter_setPositionAndVelocityRanges
/* 414 80386804 02002025 */   or        $a0, $s0, $zero
/* 418 80386808 8FA20028 */  lw         $v0, 0x28($sp)
/* 41C 8038680C 02002025 */  or         $a0, $s0, $zero
/* 420 80386810 8C450000 */  lw         $a1, ($v0)
/* 424 80386814 0C0BBEDC */  jal        func_802EFB70
/* 428 80386818 8C460004 */   lw        $a2, 4($v0)
/* 42C 8038681C 8FAE0028 */  lw         $t6, 0x28($sp)
/* 430 80386820 02002025 */  or         $a0, $s0, $zero
/* 434 80386824 8DC50008 */  lw         $a1, 8($t6)
/* 438 80386828 0C0BBEE1 */  jal        func_802EFB84
/* 43C 8038682C 8DC6000C */   lw        $a2, 0xc($t6)
/* 440 80386830 3C063C23 */  lui        $a2, 0x3c23
/* 444 80386834 34C6D70A */  ori        $a2, $a2, 0xd70a
/* 448 80386838 02002025 */  or         $a0, $s0, $zero
/* 44C 8038683C 0C0BBF97 */  jal        particleEmitter_setSpawnIntervalRange
/* 450 80386840 24050000 */   addiu     $a1, $zero, 0
/* 454 80386844 3C054033 */  lui        $a1, 0x4033
/* 458 80386848 3C06404C */  lui        $a2, 0x404c
/* 45C 8038684C 34C6CCCD */  ori        $a2, $a2, 0xcccd
/* 460 80386850 34A53333 */  ori        $a1, $a1, 0x3333
/* 464 80386854 0C0BBFB0 */  jal        func_802EFEC0
/* 468 80386858 02002025 */   or        $a0, $s0, $zero
/* 46C 8038685C 3C053E99 */  lui        $a1, 0x3e99
/* 470 80386860 3C063ECC */  lui        $a2, 0x3ecc
/* 474 80386864 34C6CCCD */  ori        $a2, $a2, 0xcccd
/* 478 80386868 34A5999A */  ori        $a1, $a1, 0x999a
/* 47C 8038686C 0C0BBE97 */  jal        func_802EFA5C
/* 480 80386870 02002025 */   or        $a0, $s0, $zero
/* 484 80386874 02002025 */  or         $a0, $s0, $zero
/* 488 80386878 0C0BBE9E */  jal        func_802EFA78
/* 48C 8038687C 24050001 */   addiu     $a1, $zero, 1
/* 490 80386880 02002025 */  or         $a0, $s0, $zero
/* 494 80386884 0C0BBD72 */  jal        particleEmitter_emitN
/* 498 80386888 8FA50024 */   lw        $a1, 0x24($sp)
/* 49C 8038688C 8FBF001C */  lw         $ra, 0x1c($sp)
/* 4A0 80386890 8FB00018 */  lw         $s0, 0x18($sp)
/* 4A4 80386894 27BD0020 */  addiu      $sp, $sp, 0x20
/* 4A8 80386898 03E00008 */  jr         $ra
/* 4AC 8038689C 00000000 */   nop
glabel func_803868A0
/* 4B0 803868A0 27BDFFE0 */  addiu      $sp, $sp, -0x20
/* 4B4 803868A4 AFBF001C */  sw         $ra, 0x1c($sp)
/* 4B8 803868A8 AFA40020 */  sw         $a0, 0x20($sp)
/* 4BC 803868AC AFB00018 */  sw         $s0, 0x18($sp)
/* 4C0 803868B0 AFA50024 */  sw         $a1, 0x24($sp)
/* 4C4 803868B4 0C0BC2F4 */  jal        partEmitList_pushNew
/* 4C8 803868B8 24040001 */   addiu     $a0, $zero, 1
/* 4CC 803868BC 00408025 */  or         $s0, $v0, $zero
/* 4D0 803868C0 00402025 */  or         $a0, $v0, $zero
/* 4D4 803868C4 0C0BBE54 */  jal        particleEmitter_setSprite
/* 4D8 803868C8 2405045A */   addiu     $a1, $zero, 0x45a
/* 4DC 803868CC 02002025 */  or         $a0, $s0, $zero
/* 4E0 803868D0 24050002 */  addiu      $a1, $zero, 2
/* 4E4 803868D4 0C0BBEA4 */  jal        particleEmitter_setStartingFrameRange
/* 4E8 803868D8 24060002 */   addiu     $a2, $zero, 2
/* 4EC 803868DC 02002025 */  or         $a0, $s0, $zero
/* 4F0 803868E0 0C0BBFEA */  jal        func_802EFFA8
/* 4F4 803868E4 8FA50024 */   lw        $a1, 0x24($sp)
/* 4F8 803868E8 02002025 */  or         $a0, $s0, $zero
/* 4FC 803868EC 0C0BBED5 */  jal        particleEmitter_setPosition
/* 500 803868F0 8FA50020 */   lw        $a1, 0x20($sp)
/* 504 803868F4 02002025 */  or         $a0, $s0, $zero
/* 508 803868F8 0C0BBE9E */  jal        func_802EFA78
/* 50C 803868FC 24050001 */   addiu     $a1, $zero, 1
/* 510 80386900 3C058039 */  lui        $a1, %hi(D_80391618)
/* 514 80386904 24A51618 */  addiu      $a1, $a1, %lo(D_80391618)
/* 518 80386908 0C0BBF40 */  jal        particleEmitter_setPositionAndVelocityRanges
/* 51C 8038690C 02002025 */   or        $a0, $s0, $zero
/* 520 80386910 3C058039 */  lui        $a1, %hi(D_803915E8)
/* 524 80386914 24A515E8 */  addiu      $a1, $a1, %lo(D_803915E8)
/* 528 80386918 0C0BBF0A */  jal        func_802EFC28
/* 52C 8038691C 02002025 */   or        $a0, $s0, $zero
/* 530 80386920 8FBF001C */  lw         $ra, 0x1c($sp)
/* 534 80386924 8FB00018 */  lw         $s0, 0x18($sp)
/* 538 80386928 27BD0020 */  addiu      $sp, $sp, 0x20
/* 53C 8038692C 03E00008 */  jr         $ra
/* 540 80386930 00000000 */   nop
glabel func_80386934
/* 544 80386934 27BDFFE0 */  addiu      $sp, $sp, -0x20
/* 548 80386938 AFBF001C */  sw         $ra, 0x1c($sp)
/* 54C 8038693C AFA40020 */  sw         $a0, 0x20($sp)
/* 550 80386940 AFB00018 */  sw         $s0, 0x18($sp)
/* 554 80386944 AFA50024 */  sw         $a1, 0x24($sp)
/* 558 80386948 0C0BC2F4 */  jal        partEmitList_pushNew
/* 55C 8038694C 24040001 */   addiu     $a0, $zero, 1
/* 560 80386950 00408025 */  or         $s0, $v0, $zero
/* 564 80386954 00402025 */  or         $a0, $v0, $zero
/* 568 80386958 0C0BBE54 */  jal        particleEmitter_setSprite
/* 56C 8038695C 8FA50024 */   lw        $a1, 0x24($sp)
/* 570 80386960 02002025 */  or         $a0, $s0, $zero
/* 574 80386964 24050001 */  addiu      $a1, $zero, 1
/* 578 80386968 0C0BBEA4 */  jal        particleEmitter_setStartingFrameRange
/* 57C 8038696C 24060006 */   addiu     $a2, $zero, 6
/* 580 80386970 02002025 */  or         $a0, $s0, $zero
/* 584 80386974 0C0BBED5 */  jal        particleEmitter_setPosition
/* 588 80386978 8FA50020 */   lw        $a1, 0x20($sp)
/* 58C 8038697C 02002025 */  or         $a0, $s0, $zero
/* 590 80386980 0C0BBE9E */  jal        func_802EFA78
/* 594 80386984 24050001 */   addiu     $a1, $zero, 1
/* 598 80386988 3C058039 */  lui        $a1, %hi(D_80391678)
/* 59C 8038698C 24A51678 */  addiu      $a1, $a1, %lo(D_80391678)
/* 5A0 80386990 0C0BBF5F */  jal        particleEmitter_setPositionVelocityAndAccelerationRanges
/* 5A4 80386994 02002025 */   or        $a0, $s0, $zero
/* 5A8 80386998 3C058039 */  lui        $a1, %hi(D_80391648)
/* 5AC 8038699C 24A51648 */  addiu      $a1, $a1, %lo(D_80391648)
/* 5B0 803869A0 0C0BBF0A */  jal        func_802EFC28
/* 5B4 803869A4 02002025 */   or        $a0, $s0, $zero
/* 5B8 803869A8 8FBF001C */  lw         $ra, 0x1c($sp)
/* 5BC 803869AC 8FB00018 */  lw         $s0, 0x18($sp)
/* 5C0 803869B0 27BD0020 */  addiu      $sp, $sp, 0x20
/* 5C4 803869B4 03E00008 */  jr         $ra
/* 5C8 803869B8 00000000 */   nop
glabel func_803869BC
/* 5CC 803869BC 27BDFFC0 */  addiu      $sp, $sp, -0x40
/* 5D0 803869C0 AFBF0014 */  sw         $ra, 0x14($sp)
/* 5D4 803869C4 AFA40040 */  sw         $a0, 0x40($sp)
/* 5D8 803869C8 8C8F0000 */  lw         $t7, ($a0)
/* 5DC 803869CC 8DF80014 */  lw         $t8, 0x14($t7)
/* 5E0 803869D0 00185280 */  sll        $t2, $t8, 0xa
/* 5E4 803869D4 0543005C */  bgezl      $t2, .L80386B48
/* 5E8 803869D8 8FBF0014 */   lw        $ra, 0x14($sp)
/* 5EC 803869DC 0C08F6D7 */  jal        func_8023DB5C
/* 5F0 803869E0 00000000 */   nop
/* 5F4 803869E4 8FA90040 */  lw         $t1, 0x40($sp)
/* 5F8 803869E8 00404025 */  or         $t0, $v0, $zero
/* 5FC 803869EC 3C028039 */  lui        $v0, %hi(D_803916CC)
/* 600 803869F0 8D230010 */  lw         $v1, 0x10($t1)
/* 604 803869F4 24010006 */  addiu      $at, $zero, 6
/* 608 803869F8 244216CC */  addiu      $v0, $v0, %lo(D_803916CC)
/* 60C 803869FC 00035E82 */  srl        $t3, $v1, 0x1a
/* 610 80386A00 11610004 */  beq        $t3, $at, .L80386A14
/* 614 80386A04 01601825 */   or        $v1, $t3, $zero
/* 618 80386A08 24010007 */  addiu      $at, $zero, 7
/* 61C 80386A0C 5561000A */  bnel       $t3, $at, .L80386A38
/* 620 80386A10 24010008 */   addiu     $at, $zero, 8
.L80386A14:
/* 624 80386A14 8C4C0000 */  lw         $t4, ($v0)
/* 628 80386A18 8C4D0004 */  lw         $t5, 4($v0)
/* 62C 80386A1C 8C4E0008 */  lw         $t6, 8($v0)
/* 630 80386A20 24070715 */  addiu      $a3, $zero, 0x715
/* 634 80386A24 AFAC0030 */  sw         $t4, 0x30($sp)
/* 638 80386A28 AFAD0034 */  sw         $t5, 0x34($sp)
/* 63C 80386A2C 10000018 */  b          .L80386A90
/* 640 80386A30 AFAE0038 */   sw        $t6, 0x38($sp)
/* 644 80386A34 24010008 */  addiu      $at, $zero, 8
.L80386A38:
/* 648 80386A38 10610002 */  beq        $v1, $at, .L80386A44
/* 64C 80386A3C 24010009 */   addiu     $at, $zero, 9
/* 650 80386A40 1461000A */  bne        $v1, $at, .L80386A6C
.L80386A44:
/* 654 80386A44 3C028039 */   lui       $v0, %hi(D_803916D8)
/* 658 80386A48 244216D8 */  addiu      $v0, $v0, %lo(D_803916D8)
/* 65C 80386A4C 8C4F0000 */  lw         $t7, ($v0)
/* 660 80386A50 8C580004 */  lw         $t8, 4($v0)
/* 664 80386A54 8C590008 */  lw         $t9, 8($v0)
/* 668 80386A58 00003825 */  or         $a3, $zero, $zero
/* 66C 80386A5C AFAF0030 */  sw         $t7, 0x30($sp)
/* 670 80386A60 AFB80034 */  sw         $t8, 0x34($sp)
/* 674 80386A64 1000000A */  b          .L80386A90
/* 678 80386A68 AFB90038 */   sw        $t9, 0x38($sp)
.L80386A6C:
/* 67C 80386A6C 3C028039 */  lui        $v0, %hi(D_803916C0)
/* 680 80386A70 244216C0 */  addiu      $v0, $v0, %lo(D_803916C0)
/* 684 80386A74 8C4A0000 */  lw         $t2, ($v0)
/* 688 80386A78 8C4B0004 */  lw         $t3, 4($v0)
/* 68C 80386A7C 8C4C0008 */  lw         $t4, 8($v0)
/* 690 80386A80 24070713 */  addiu      $a3, $zero, 0x713
/* 694 80386A84 AFAA0030 */  sw         $t2, 0x30($sp)
/* 698 80386A88 AFAB0034 */  sw         $t3, 0x34($sp)
/* 69C 80386A8C AFAC0038 */  sw         $t4, 0x38($sp)
.L80386A90:
/* 6A0 80386A90 8D2D0000 */  lw         $t5, ($t1)
/* 6A4 80386A94 24050007 */  addiu      $a1, $zero, 7
/* 6A8 80386A98 27A60020 */  addiu      $a2, $sp, 0x20
/* 6AC 80386A9C 8DA40044 */  lw         $a0, 0x44($t5)
/* 6B0 80386AA0 AFA8003C */  sw         $t0, 0x3c($sp)
/* 6B4 80386AA4 0C0D285D */  jal        func_8034A174
/* 6B8 80386AA8 AFA7002C */   sw        $a3, 0x2c($sp)
/* 6BC 80386AAC 8FA7002C */  lw         $a3, 0x2c($sp)
/* 6C0 80386AB0 8FA8003C */  lw         $t0, 0x3c($sp)
/* 6C4 80386AB4 24010715 */  addiu      $at, $zero, 0x715
/* 6C8 80386AB8 14E10002 */  bne        $a3, $at, .L80386AC4
/* 6CC 80386ABC 310E0001 */   andi      $t6, $t0, 1
/* 6D0 80386AC0 15C00004 */  bnez       $t6, .L80386AD4
.L80386AC4:
/* 6D4 80386AC4 24010713 */   addiu     $at, $zero, 0x713
/* 6D8 80386AC8 14E10007 */  bne        $a3, $at, .L80386AE8
/* 6DC 80386ACC 310F0003 */   andi      $t7, $t0, 3
/* 6E0 80386AD0 15E00005 */  bnez       $t7, .L80386AE8
.L80386AD4:
/* 6E4 80386AD4 27A40020 */   addiu     $a0, $sp, 0x20
/* 6E8 80386AD8 27A50030 */  addiu      $a1, $sp, 0x30
/* 6EC 80386ADC 0C0E1A28 */  jal        func_803868A0
/* 6F0 80386AE0 AFA7002C */   sw        $a3, 0x2c($sp)
/* 6F4 80386AE4 8FA7002C */  lw         $a3, 0x2c($sp)
.L80386AE8:
/* 6F8 80386AE8 14E00006 */  bnez       $a3, .L80386B04
/* 6FC 80386AEC 8FA40040 */   lw        $a0, 0x40($sp)
/* 700 80386AF0 3C058039 */  lui        $a1, %hi(D_803916E4)
/* 704 80386AF4 24A516E4 */  addiu      $a1, $a1, %lo(D_803916E4)
/* 708 80386AF8 0C0E215B */  jal        func_8038856C
/* 70C 80386AFC AFA7002C */   sw        $a3, 0x2c($sp)
/* 710 80386B00 8FA7002C */  lw         $a3, 0x2c($sp)
.L80386B04:
/* 714 80386B04 10E0000F */  beqz       $a3, .L80386B44
/* 718 80386B08 24010715 */   addiu     $at, $zero, 0x715
/* 71C 80386B0C 50E1000B */  beql       $a3, $at, .L80386B3C
/* 720 80386B10 27A40020 */   addiu     $a0, $sp, 0x20
/* 724 80386B14 0C0D28E4 */  jal        randf
/* 728 80386B18 AFA7002C */   sw        $a3, 0x2c($sp)
/* 72C 80386B1C 3C018039 */  lui        $at, %hi(D_803920C0)
/* 730 80386B20 D42620C0 */  ldc1       $f6, %lo(D_803920C0)($at)
/* 734 80386B24 46000121 */  cvt.d.s    $f4, $f0
/* 738 80386B28 8FA7002C */  lw         $a3, 0x2c($sp)
/* 73C 80386B2C 4626203C */  c.lt.d     $f4, $f6
/* 740 80386B30 00000000 */  nop
/* 744 80386B34 45000003 */  bc1f       .L80386B44
/* 748 80386B38 27A40020 */   addiu     $a0, $sp, 0x20
.L80386B3C:
/* 74C 80386B3C 0C0E1A4D */  jal        func_80386934
/* 750 80386B40 00E02825 */   or        $a1, $a3, $zero
.L80386B44:
/* 754 80386B44 8FBF0014 */  lw         $ra, 0x14($sp)
.L80386B48:
/* 758 80386B48 27BD0040 */  addiu      $sp, $sp, 0x40
/* 75C 80386B4C 03E00008 */  jr         $ra
/* 760 80386B50 00000000 */   nop
glabel func_80386B54
/* 764 80386B54 44856000 */  mtc1       $a1, $f12
/* 768 80386B58 27BDFFC8 */  addiu      $sp, $sp, -0x38
/* 76C 80386B5C AFBF0014 */  sw         $ra, 0x14($sp)
/* 770 80386B60 AFA40038 */  sw         $a0, 0x38($sp)
/* 774 80386B64 0C0CF767 */  jal        time_getDelta
/* 778 80386B68 E7AC003C */   swc1      $f12, 0x3c($sp)
/* 77C 80386B6C 27A40028 */  addiu      $a0, $sp, 0x28
/* 780 80386B70 0C0A3A69 */  jal        player_getPosition
/* 784 80386B74 E7A00034 */   swc1      $f0, 0x34($sp)
/* 788 80386B78 3C078039 */  lui        $a3, %hi(D_80392788)
/* 78C 80386B7C C7A20034 */  lwc1       $f2, 0x34($sp)
/* 790 80386B80 C7AC003C */  lwc1       $f12, 0x3c($sp)
/* 794 80386B84 24E72788 */  addiu      $a3, $a3, %lo(D_80392788)
/* 798 80386B88 00002025 */  or         $a0, $zero, $zero
/* 79C 80386B8C 8FA30038 */  lw         $v1, 0x38($sp)
/* 7A0 80386B90 27A20028 */  addiu      $v0, $sp, 0x28
/* 7A4 80386B94 27A60034 */  addiu      $a2, $sp, 0x34
/* 7A8 80386B98 27A5002C */  addiu      $a1, $sp, 0x2c
.L80386B9C:
/* 7AC 80386B9C 14450004 */  bne        $v0, $a1, .L80386BB0
/* 7B0 80386BA0 00E47021 */   addu      $t6, $a3, $a0
/* 7B4 80386BA4 C4440000 */  lwc1       $f4, ($v0)
/* 7B8 80386BA8 10000008 */  b          .L80386BCC
/* 7BC 80386BAC E4640000 */   swc1      $f4, ($v1)
.L80386BB0:
/* 7C0 80386BB0 C4400000 */  lwc1       $f0, ($v0)
/* 7C4 80386BB4 C5C60000 */  lwc1       $f6, ($t6)
/* 7C8 80386BB8 46060201 */  sub.s      $f8, $f0, $f6
/* 7CC 80386BBC 460C4282 */  mul.s      $f10, $f8, $f12
/* 7D0 80386BC0 46025403 */  div.s      $f16, $f10, $f2
/* 7D4 80386BC4 46008480 */  add.s      $f18, $f16, $f0
/* 7D8 80386BC8 E4720000 */  swc1       $f18, ($v1)
.L80386BCC:
/* 7DC 80386BCC 24420004 */  addiu      $v0, $v0, 4
/* 7E0 80386BD0 24840004 */  addiu      $a0, $a0, 4
/* 7E4 80386BD4 1446FFF1 */  bne        $v0, $a2, .L80386B9C
/* 7E8 80386BD8 24630004 */   addiu     $v1, $v1, 4
/* 7EC 80386BDC 8FBF0014 */  lw         $ra, 0x14($sp)
/* 7F0 80386BE0 27BD0038 */  addiu      $sp, $sp, 0x38
/* 7F4 80386BE4 03E00008 */  jr         $ra
/* 7F8 80386BE8 00000000 */   nop
glabel func_80386BEC
/* 7FC 80386BEC 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 800 80386BF0 AFBF0014 */  sw         $ra, 0x14($sp)
/* 804 80386BF4 AFA5001C */  sw         $a1, 0x1c($sp)
/* 808 80386BF8 0C0CA5E1 */  jal        func_80329784
/* 80C 80386BFC AFA40018 */   sw        $a0, 0x18($sp)
/* 810 80386C00 44822000 */  mtc1       $v0, $f4
/* 814 80386C04 8FA40018 */  lw         $a0, 0x18($sp)
/* 818 80386C08 468021A0 */  cvt.s.w    $f6, $f4
/* 81C 80386C0C E4860064 */  swc1       $f6, 0x64($a0)
/* 820 80386C10 0C0CA3EC */  jal        func_80328FB0
/* 824 80386C14 8FA5001C */   lw        $a1, 0x1c($sp)
/* 828 80386C18 8FA40018 */  lw         $a0, 0x18($sp)
/* 82C 80386C1C C7AC001C */  lwc1       $f12, 0x1c($sp)
/* 830 80386C20 8FBF0014 */  lw         $ra, 0x14($sp)
/* 834 80386C24 C4820050 */  lwc1       $f2, 0x50($a0)
/* 838 80386C28 C4800064 */  lwc1       $f0, 0x64($a0)
/* 83C 80386C2C 00001025 */  or         $v0, $zero, $zero
/* 840 80386C30 460C1200 */  add.s      $f8, $f2, $f12
/* 844 80386C34 4608003C */  c.lt.s     $f0, $f8
/* 848 80386C38 00000000 */  nop
/* 84C 80386C3C 45000008 */  bc1f       .L80386C60
/* 850 80386C40 00000000 */   nop
/* 854 80386C44 460C1281 */  sub.s      $f10, $f2, $f12
/* 858 80386C48 4600503C */  c.lt.s     $f10, $f0
/* 85C 80386C4C 00000000 */  nop
/* 860 80386C50 45000003 */  bc1f       .L80386C60
/* 864 80386C54 00000000 */   nop
/* 868 80386C58 10000001 */  b          .L80386C60
/* 86C 80386C5C 24020001 */   addiu     $v0, $zero, 1
.L80386C60:
/* 870 80386C60 03E00008 */  jr         $ra
/* 874 80386C64 27BD0018 */   addiu     $sp, $sp, 0x18
glabel func_80386C68
/* 878 80386C68 27BDFFC8 */  addiu      $sp, $sp, -0x38
/* 87C 80386C6C AFB00018 */  sw         $s0, 0x18($sp)
/* 880 80386C70 00808025 */  or         $s0, $a0, $zero
/* 884 80386C74 AFBF001C */  sw         $ra, 0x1c($sp)
/* 888 80386C78 AFA5003C */  sw         $a1, 0x3c($sp)
/* 88C 80386C7C 0C0E44A7 */  jal        func_8039129C
/* 890 80386C80 27A4002C */   addiu     $a0, $sp, 0x2c
/* 894 80386C84 02002025 */  or         $a0, $s0, $zero
/* 898 80386C88 0C0CA5F2 */  jal        func_803297C8
/* 89C 80386C8C 27A5002C */   addiu     $a1, $sp, 0x2c
/* 8A0 80386C90 44822000 */  mtc1       $v0, $f4
/* 8A4 80386C94 02002025 */  or         $a0, $s0, $zero
/* 8A8 80386C98 468021A0 */  cvt.s.w    $f6, $f4
/* 8AC 80386C9C E6060064 */  swc1       $f6, 0x64($s0)
/* 8B0 80386CA0 0C0CA3EC */  jal        func_80328FB0
/* 8B4 80386CA4 8FA5003C */   lw        $a1, 0x3c($sp)
/* 8B8 80386CA8 C6020050 */  lwc1       $f2, 0x50($s0)
/* 8BC 80386CAC C7A8003C */  lwc1       $f8, 0x3c($sp)
/* 8C0 80386CB0 C6000064 */  lwc1       $f0, 0x64($s0)
/* 8C4 80386CB4 8FBF001C */  lw         $ra, 0x1c($sp)
/* 8C8 80386CB8 46081280 */  add.s      $f10, $f2, $f8
/* 8CC 80386CBC 00001025 */  or         $v0, $zero, $zero
/* 8D0 80386CC0 460A003C */  c.lt.s     $f0, $f10
/* 8D4 80386CC4 00000000 */  nop
/* 8D8 80386CC8 45000008 */  bc1f       .L80386CEC
/* 8DC 80386CCC 00000000 */   nop
/* 8E0 80386CD0 46081401 */  sub.s      $f16, $f2, $f8
/* 8E4 80386CD4 4600803C */  c.lt.s     $f16, $f0
/* 8E8 80386CD8 00000000 */  nop
/* 8EC 80386CDC 45000003 */  bc1f       .L80386CEC
/* 8F0 80386CE0 00000000 */   nop
/* 8F4 80386CE4 10000001 */  b          .L80386CEC
/* 8F8 80386CE8 24020001 */   addiu     $v0, $zero, 1
.L80386CEC:
/* 8FC 80386CEC 8FB00018 */  lw         $s0, 0x18($sp)
/* 900 80386CF0 03E00008 */  jr         $ra
/* 904 80386CF4 27BD0038 */   addiu     $sp, $sp, 0x38
glabel func_80386CF8
/* 908 80386CF8 27BDFFA8 */  addiu      $sp, $sp, -0x58
/* 90C 80386CFC AFBF0024 */  sw         $ra, 0x24($sp)
/* 910 80386D00 00803825 */  or         $a3, $a0, $zero
/* 914 80386D04 C4E40004 */  lwc1       $f4, 4($a3)
/* 918 80386D08 3C01435C */  lui        $at, 0x435c
/* 91C 80386D0C 44800000 */  mtc1       $zero, $f0
/* 920 80386D10 E7A40028 */  swc1       $f4, 0x28($sp)
/* 924 80386D14 C4E60008 */  lwc1       $f6, 8($a3)
/* 928 80386D18 44812000 */  mtc1       $at, $f4
/* 92C 80386D1C 3C01447A */  lui        $at, 0x447a
/* 930 80386D20 E7A6002C */  swc1       $f6, 0x2c($sp)
/* 934 80386D24 C4E8000C */  lwc1       $f8, 0xc($a3)
/* 938 80386D28 C7AA002C */  lwc1       $f10, 0x2c($sp)
/* 93C 80386D2C 27A40034 */  addiu      $a0, $sp, 0x34
/* 940 80386D30 E7A80030 */  swc1       $f8, 0x30($sp)
/* 944 80386D34 46045180 */  add.s      $f6, $f10, $f4
/* 948 80386D38 44814000 */  mtc1       $at, $f8
/* 94C 80386D3C E7A00038 */  swc1       $f0, 0x38($sp)
/* 950 80386D40 E7A00034 */  swc1       $f0, 0x34($sp)
/* 954 80386D44 E7A6002C */  swc1       $f6, 0x2c($sp)
/* 958 80386D48 E7A8003C */  swc1       $f8, 0x3c($sp)
/* 95C 80386D4C 8CE60050 */  lw         $a2, 0x50($a3)
/* 960 80386D50 0C095A40 */  jal        ml_vec3f_yaw_rotate_copy
/* 964 80386D54 00802825 */   or        $a1, $a0, $zero
/* 968 80386D58 C7AC0028 */  lwc1       $f12, 0x28($sp)
/* 96C 80386D5C C7AA0034 */  lwc1       $f10, 0x34($sp)
/* 970 80386D60 C7A00030 */  lwc1       $f0, 0x30($sp)
/* 974 80386D64 C7AE002C */  lwc1       $f14, 0x2c($sp)
/* 978 80386D68 C7A40038 */  lwc1       $f4, 0x38($sp)
/* 97C 80386D6C C7A6003C */  lwc1       $f6, 0x3c($sp)
/* 980 80386D70 460C5080 */  add.s      $f2, $f10, $f12
/* 984 80386D74 27AE0040 */  addiu      $t6, $sp, 0x40
/* 988 80386D78 27AF0044 */  addiu      $t7, $sp, 0x44
/* 98C 80386D7C 460E2400 */  add.s      $f16, $f4, $f14
/* 990 80386D80 44071000 */  mfc1       $a3, $f2
/* 994 80386D84 44060000 */  mfc1       $a2, $f0
/* 998 80386D88 46003480 */  add.s      $f18, $f6, $f0
/* 99C 80386D8C E7B00010 */  swc1       $f16, 0x10($sp)
/* 9A0 80386D90 E7B00050 */  swc1       $f16, 0x50($sp)
/* 9A4 80386D94 AFAF001C */  sw         $t7, 0x1c($sp)
/* 9A8 80386D98 E7B20014 */  swc1       $f18, 0x14($sp)
/* 9AC 80386D9C E7B20054 */  swc1       $f18, 0x54($sp)
/* 9B0 80386DA0 AFAE0018 */  sw         $t6, 0x18($sp)
/* 9B4 80386DA4 0C095C9F */  jal        func_8025727C
/* 9B8 80386DA8 E7A2004C */   swc1      $f2, 0x4c($sp)
/* 9BC 80386DAC 3C0143B4 */  lui        $at, 0x43b4
/* 9C0 80386DB0 44814000 */  mtc1       $at, $f8
/* 9C4 80386DB4 C7AA0040 */  lwc1       $f10, 0x40($sp)
/* 9C8 80386DB8 44803000 */  mtc1       $zero, $f6
/* 9CC 80386DBC 27A4004C */  addiu      $a0, $sp, 0x4c
/* 9D0 80386DC0 460A4101 */  sub.s      $f4, $f8, $f10
/* 9D4 80386DC4 27A50040 */  addiu      $a1, $sp, 0x40
/* 9D8 80386DC8 E7A60048 */  swc1       $f6, 0x48($sp)
/* 9DC 80386DCC 0C0AEB9B */  jal        func_802BAE6C
/* 9E0 80386DD0 E7A40040 */   swc1      $f4, 0x40($sp)
/* 9E4 80386DD4 8FBF0024 */  lw         $ra, 0x24($sp)
/* 9E8 80386DD8 27BD0058 */  addiu      $sp, $sp, 0x58
/* 9EC 80386DDC 03E00008 */  jr         $ra
/* 9F0 80386DE0 00000000 */   nop
glabel func_80386DE4
/* 9F4 80386DE4 27BDFFE0 */  addiu      $sp, $sp, -0x20
/* 9F8 80386DE8 AFBF0014 */  sw         $ra, 0x14($sp)
/* 9FC 80386DEC 0C0CA656 */  jal        marker_getActor
/* A00 80386DF0 00000000 */   nop
/* A04 80386DF4 3C058039 */  lui        $a1, %hi(D_803916F4)
/* A08 80386DF8 AFA2001C */  sw         $v0, 0x1c($sp)
/* A0C 80386DFC 24A516F4 */  addiu      $a1, $a1, %lo(D_803916F4)
/* A10 80386E00 0C0CA5F2 */  jal        func_803297C8
/* A14 80386E04 00402025 */   or        $a0, $v0, $zero
/* A18 80386E08 44822000 */  mtc1       $v0, $f4
/* A1C 80386E0C 0C0B23DC */  jal        func_802C8F70
/* A20 80386E10 46802320 */   cvt.s.w   $f12, $f4
/* A24 80386E14 8FA5001C */  lw         $a1, 0x1c($sp)
/* A28 80386E18 24040014 */  addiu      $a0, $zero, 0x14
/* A2C 80386E1C 0C0B24DF */  jal        func_802C937C
/* A30 80386E20 24A50004 */   addiu     $a1, $a1, 4
/* A34 80386E24 8FBF0014 */  lw         $ra, 0x14($sp)
/* A38 80386E28 27BD0020 */  addiu      $sp, $sp, 0x20
/* A3C 80386E2C 03E00008 */  jr         $ra
/* A40 80386E30 00000000 */   nop
glabel func_80386E34
/* A44 80386E34 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* A48 80386E38 AFBF0014 */  sw         $ra, 0x14($sp)
/* A4C 80386E3C 3C048039 */  lui        $a0, %hi(D_803927A8)
/* A50 80386E40 0C0CA0BD */  jal        marker_despawn
/* A54 80386E44 8C8427A8 */   lw        $a0, %lo(D_803927A8)($a0)
/* A58 80386E48 8FBF0014 */  lw         $ra, 0x14($sp)
/* A5C 80386E4C 3C018039 */  lui        $at, %hi(D_803927A8)
/* A60 80386E50 AC2027A8 */  sw         $zero, %lo(D_803927A8)($at)
/* A64 80386E54 03E00008 */  jr         $ra
/* A68 80386E58 27BD0018 */   addiu     $sp, $sp, 0x18
glabel func_80386E5C
/* A6C 80386E5C 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* A70 80386E60 AFBF0014 */  sw         $ra, 0x14($sp)
/* A74 80386E64 AFA40018 */  sw         $a0, 0x18($sp)
/* A78 80386E68 3C058039 */  lui        $a1, %hi(D_80391700)
/* A7C 80386E6C 3C068039 */  lui        $a2, %hi(D_8039170C)
/* A80 80386E70 8CC6170C */  lw         $a2, %lo(D_8039170C)($a2)
/* A84 80386E74 24A51700 */  addiu      $a1, $a1, %lo(D_80391700)
/* A88 80386E78 0C0CA04F */  jal        func_8032813C
/* A8C 80386E7C 2404039F */   addiu     $a0, $zero, 0x39f
/* A90 80386E80 8C430124 */  lw         $v1, 0x124($v0)
/* A94 80386E84 94480038 */  lhu        $t0, 0x38($v0)
/* A98 80386E88 8C4B0000 */  lw         $t3, ($v0)
/* A9C 80386E8C 00037302 */  srl        $t6, $v1, 0xc
/* AA0 80386E90 000E7E00 */  sll        $t7, $t6, 0x18
/* AA4 80386E94 000FC302 */  srl        $t8, $t7, 0xc
/* AA8 80386E98 3109003F */  andi       $t1, $t0, 0x3f
/* AAC 80386E9C 352A0180 */  ori        $t2, $t1, 0x180
/* AB0 80386EA0 0303C826 */  xor        $t9, $t8, $v1
/* AB4 80386EA4 AC590124 */  sw         $t9, 0x124($v0)
/* AB8 80386EA8 A44A0038 */  sh         $t2, 0x38($v0)
/* ABC 80386EAC 8FBF0014 */  lw         $ra, 0x14($sp)
/* AC0 80386EB0 3C018039 */  lui        $at, %hi(D_803927A8)
/* AC4 80386EB4 27BD0018 */  addiu      $sp, $sp, 0x18
/* AC8 80386EB8 03E00008 */  jr         $ra
/* ACC 80386EBC AC2B27A8 */   sw        $t3, %lo(D_803927A8)($at)
glabel func_80386EC0
/* AD0 80386EC0 27BDFFD8 */  addiu      $sp, $sp, -0x28
/* AD4 80386EC4 AFBF001C */  sw         $ra, 0x1c($sp)
/* AD8 80386EC8 AFA40028 */  sw         $a0, 0x28($sp)
/* ADC 80386ECC 3C058039 */  lui        $a1, %hi(D_80392758)
/* AE0 80386ED0 24A52758 */  addiu      $a1, $a1, %lo(D_80392758)
/* AE4 80386ED4 2404038A */  addiu      $a0, $zero, 0x38a
/* AE8 80386ED8 0C0CA04F */  jal        func_8032813C
/* AEC 80386EDC 00003025 */   or        $a2, $zero, $zero
/* AF0 80386EE0 3C018039 */  lui        $at, %hi(D_803920C8)
/* AF4 80386EE4 8C4E0000 */  lw         $t6, ($v0)
/* AF8 80386EE8 C42C20C8 */  lwc1       $f12, %lo(D_803920C8)($at)
/* AFC 80386EEC 3C018039 */  lui        $at, %hi(D_803920CC)
/* B00 80386EF0 C42E20CC */  lwc1       $f14, %lo(D_803920CC)($at)
/* B04 80386EF4 0C0D29D5 */  jal        randf2
/* B08 80386EF8 AFAE0024 */   sw        $t6, 0x24($sp)
/* B0C 80386EFC 3C018039 */  lui        $at, %hi(D_803920D0)
/* B10 80386F00 C42420D0 */  lwc1       $f4, %lo(D_803920D0)($at)
/* B14 80386F04 3C018039 */  lui        $at, %hi(D_803920D4)
/* B18 80386F08 C42620D4 */  lwc1       $f6, %lo(D_803920D4)($at)
/* B1C 80386F0C 44050000 */  mfc1       $a1, $f0
/* B20 80386F10 3C078039 */  lui        $a3, %hi(D_80392758)
/* B24 80386F14 24E72758 */  addiu      $a3, $a3, %lo(D_80392758)
/* B28 80386F18 24040147 */  addiu      $a0, $zero, 0x147
/* B2C 80386F1C 24067D00 */  addiu      $a2, $zero, 0x7d00
/* B30 80386F20 E7A40010 */  swc1       $f4, 0x10($sp)
/* B34 80386F24 0C0C3A1E */  jal        func_8030E878
/* B38 80386F28 E7A60014 */   swc1      $f6, 0x14($sp)
/* B3C 80386F2C 3C028039 */  lui        $v0, %hi(D_80392768)
/* B40 80386F30 24422768 */  addiu      $v0, $v0, %lo(D_80392768)
/* B44 80386F34 3C058039 */  lui        $a1, %hi(D_80392758)
/* B48 80386F38 24A52758 */  addiu      $a1, $a1, %lo(D_80392758)
/* B4C 80386F3C 8C460004 */  lw         $a2, 4($v0)
/* B50 80386F40 8C470008 */  lw         $a3, 8($v0)
/* B54 80386F44 0C0E4037 */  jal        func_803900DC
/* B58 80386F48 8FA40024 */   lw        $a0, 0x24($sp)
/* B5C 80386F4C 8FBF001C */  lw         $ra, 0x1c($sp)
/* B60 80386F50 27BD0028 */  addiu      $sp, $sp, 0x28
/* B64 80386F54 03E00008 */  jr         $ra
/* B68 80386F58 00000000 */   nop
glabel func_80386F5C
/* B6C 80386F5C 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* B70 80386F60 AFBF0014 */  sw         $ra, 0x14($sp)
/* B74 80386F64 AFA40018 */  sw         $a0, 0x18($sp)
/* B78 80386F68 AFA5001C */  sw         $a1, 0x1c($sp)
/* B7C 80386F6C 3C0142C8 */  lui        $at, 0x42c8
/* B80 80386F70 44813000 */  mtc1       $at, $f6
/* B84 80386F74 C4A40004 */  lwc1       $f4, 4($a1)
/* B88 80386F78 C4AA0000 */  lwc1       $f10, ($a1)
/* B8C 80386F7C 3C028039 */  lui        $v0, %hi(D_80392758)
/* B90 80386F80 46062200 */  add.s      $f8, $f4, $f6
/* B94 80386F84 24422758 */  addiu      $v0, $v0, %lo(D_80392758)
/* B98 80386F88 44866000 */  mtc1       $a2, $f12
/* B9C 80386F8C 44877000 */  mtc1       $a3, $f14
/* BA0 80386F90 E4A80004 */  swc1       $f8, 4($a1)
/* BA4 80386F94 E44A0000 */  swc1       $f10, ($v0)
/* BA8 80386F98 C4B00004 */  lwc1       $f16, 4($a1)
/* BAC 80386F9C 3C038039 */  lui        $v1, %hi(D_80392768)
/* BB0 80386FA0 24632768 */  addiu      $v1, $v1, %lo(D_80392768)
/* BB4 80386FA4 E4500004 */  swc1       $f16, 4($v0)
/* BB8 80386FA8 C4B20008 */  lwc1       $f18, 8($a1)
/* BBC 80386FAC 3C048038 */  lui        $a0, %hi(func_80386EC0)
/* BC0 80386FB0 24846EC0 */  addiu      $a0, $a0, %lo(func_80386EC0)
/* BC4 80386FB4 8FA50018 */  lw         $a1, 0x18($sp)
/* BC8 80386FB8 E46C0004 */  swc1       $f12, 4($v1)
/* BCC 80386FBC E46E0008 */  swc1       $f14, 8($v1)
/* BD0 80386FC0 0C0B0F22 */  jal        func_802C3C88
/* BD4 80386FC4 E4520008 */   swc1      $f18, 8($v0)
/* BD8 80386FC8 8FBF0014 */  lw         $ra, 0x14($sp)
/* BDC 80386FCC 27BD0018 */  addiu      $sp, $sp, 0x18
/* BE0 80386FD0 03E00008 */  jr         $ra
/* BE4 80386FD4 00000000 */   nop
glabel func_80386FD8
/* BE8 80386FD8 27BDFFD8 */  addiu      $sp, $sp, -0x28
/* BEC 80386FDC AFBF001C */  sw         $ra, 0x1c($sp)
/* BF0 80386FE0 AFA40028 */  sw         $a0, 0x28($sp)
/* BF4 80386FE4 3C058039 */  lui        $a1, %hi(D_80392758)
/* BF8 80386FE8 24A52758 */  addiu      $a1, $a1, %lo(D_80392758)
/* BFC 80386FEC 24040389 */  addiu      $a0, $zero, 0x389
/* C00 80386FF0 0C0CA04F */  jal        func_8032813C
/* C04 80386FF4 00003025 */   or        $a2, $zero, $zero
/* C08 80386FF8 3C018039 */  lui        $at, %hi(D_803920D8)
/* C0C 80386FFC 8C4E0000 */  lw         $t6, ($v0)
/* C10 80387000 C42C20D8 */  lwc1       $f12, %lo(D_803920D8)($at)
/* C14 80387004 3C018039 */  lui        $at, %hi(D_803920DC)
/* C18 80387008 C42E20DC */  lwc1       $f14, %lo(D_803920DC)($at)
/* C1C 8038700C 0C0D29D5 */  jal        randf2
/* C20 80387010 AFAE0024 */   sw        $t6, 0x24($sp)
/* C24 80387014 3C018039 */  lui        $at, %hi(D_803920E0)
/* C28 80387018 C42420E0 */  lwc1       $f4, %lo(D_803920E0)($at)
/* C2C 8038701C 3C018039 */  lui        $at, %hi(D_803920E4)
/* C30 80387020 C42620E4 */  lwc1       $f6, %lo(D_803920E4)($at)
/* C34 80387024 44050000 */  mfc1       $a1, $f0
/* C38 80387028 3C078039 */  lui        $a3, %hi(D_80392758)
/* C3C 8038702C 24E72758 */  addiu      $a3, $a3, %lo(D_80392758)
/* C40 80387030 24040146 */  addiu      $a0, $zero, 0x146
/* C44 80387034 24067D00 */  addiu      $a2, $zero, 0x7d00
/* C48 80387038 E7A40010 */  swc1       $f4, 0x10($sp)
/* C4C 8038703C 0C0C3A1E */  jal        func_8030E878
/* C50 80387040 E7A60014 */   swc1      $f6, 0x14($sp)
/* C54 80387044 3C058039 */  lui        $a1, %hi(D_80392758)
/* C58 80387048 3C068039 */  lui        $a2, %hi(D_80392768)
/* C5C 8038704C 3C078039 */  lui        $a3, %hi(D_80392778)
/* C60 80387050 24E72778 */  addiu      $a3, $a3, %lo(D_80392778)
/* C64 80387054 24C62768 */  addiu      $a2, $a2, %lo(D_80392768)
/* C68 80387058 24A52758 */  addiu      $a1, $a1, %lo(D_80392758)
/* C6C 8038705C 0C0E3EE1 */  jal        func_8038FB84
/* C70 80387060 8FA40024 */   lw        $a0, 0x24($sp)
/* C74 80387064 8FBF001C */  lw         $ra, 0x1c($sp)
/* C78 80387068 27BD0028 */  addiu      $sp, $sp, 0x28
/* C7C 8038706C 03E00008 */  jr         $ra
/* C80 80387070 00000000 */   nop
glabel func_80387074
/* C84 80387074 27BDFFD8 */  addiu      $sp, $sp, -0x28
/* C88 80387078 AFBF001C */  sw         $ra, 0x1c($sp)
/* C8C 8038707C AFA40028 */  sw         $a0, 0x28($sp)
/* C90 80387080 3C058039 */  lui        $a1, %hi(D_80392758)
/* C94 80387084 24A52758 */  addiu      $a1, $a1, %lo(D_80392758)
/* C98 80387088 240403AA */  addiu      $a0, $zero, 0x3aa
/* C9C 8038708C 0C0CA04F */  jal        func_8032813C
/* CA0 80387090 00003025 */   or        $a2, $zero, $zero
/* CA4 80387094 3C018039 */  lui        $at, %hi(D_803920E8)
/* CA8 80387098 8C4E0000 */  lw         $t6, ($v0)
/* CAC 8038709C C42C20E8 */  lwc1       $f12, %lo(D_803920E8)($at)
/* CB0 803870A0 3C018039 */  lui        $at, %hi(D_803920EC)
/* CB4 803870A4 C42E20EC */  lwc1       $f14, %lo(D_803920EC)($at)
/* CB8 803870A8 0C0D29D5 */  jal        randf2
/* CBC 803870AC AFAE0024 */   sw        $t6, 0x24($sp)
/* CC0 803870B0 3C018039 */  lui        $at, %hi(D_803920F0)
/* CC4 803870B4 C42420F0 */  lwc1       $f4, %lo(D_803920F0)($at)
/* CC8 803870B8 3C018039 */  lui        $at, %hi(D_803920F4)
/* CCC 803870BC C42620F4 */  lwc1       $f6, %lo(D_803920F4)($at)
/* CD0 803870C0 44050000 */  mfc1       $a1, $f0
/* CD4 803870C4 3C078039 */  lui        $a3, %hi(D_80392758)
/* CD8 803870C8 24E72758 */  addiu      $a3, $a3, %lo(D_80392758)
/* CDC 803870CC 24040146 */  addiu      $a0, $zero, 0x146
/* CE0 803870D0 24067D00 */  addiu      $a2, $zero, 0x7d00
/* CE4 803870D4 E7A40010 */  swc1       $f4, 0x10($sp)
/* CE8 803870D8 0C0C3A1E */  jal        func_8030E878
/* CEC 803870DC E7A60014 */   swc1      $f6, 0x14($sp)
/* CF0 803870E0 3C058039 */  lui        $a1, %hi(D_80392758)
/* CF4 803870E4 3C068039 */  lui        $a2, %hi(D_80392768)
/* CF8 803870E8 3C078039 */  lui        $a3, %hi(D_80392778)
/* CFC 803870EC 24E72778 */  addiu      $a3, $a3, %lo(D_80392778)
/* D00 803870F0 24C62768 */  addiu      $a2, $a2, %lo(D_80392768)
/* D04 803870F4 24A52758 */  addiu      $a1, $a1, %lo(D_80392758)
/* D08 803870F8 0C0E3EE1 */  jal        func_8038FB84
/* D0C 803870FC 8FA40024 */   lw        $a0, 0x24($sp)
/* D10 80387100 8FBF001C */  lw         $ra, 0x1c($sp)
/* D14 80387104 27BD0028 */  addiu      $sp, $sp, 0x28
/* D18 80387108 03E00008 */  jr         $ra
/* D1C 8038710C 00000000 */   nop
glabel func_80387110
/* D20 80387110 27BDFFC0 */  addiu      $sp, $sp, -0x40
/* D24 80387114 44866000 */  mtc1       $a2, $f12
/* D28 80387118 AFBF0014 */  sw         $ra, 0x14($sp)
/* D2C 8038711C AFA40040 */  sw         $a0, 0x40($sp)
/* D30 80387120 AFA50044 */  sw         $a1, 0x44($sp)
/* D34 80387124 AFA7004C */  sw         $a3, 0x4c($sp)
/* D38 80387128 0C0CA656 */  jal        marker_getActor
/* D3C 8038712C E7AC0048 */   swc1      $f12, 0x48($sp)
/* D40 80387130 8FA80044 */  lw         $t0, 0x44($sp)
/* D44 80387134 3C038039 */  lui        $v1, %hi(D_80392758)
/* D48 80387138 24632758 */  addiu      $v1, $v1, %lo(D_80392758)
/* D4C 8038713C C5040000 */  lwc1       $f4, ($t0)
/* D50 80387140 3C0142A0 */  lui        $at, 0x42a0
/* D54 80387144 44818000 */  mtc1       $at, $f16
/* D58 80387148 E4640000 */  swc1       $f4, ($v1)
/* D5C 8038714C C5060004 */  lwc1       $f6, 4($t0)
/* D60 80387150 8FA9004C */  lw         $t1, 0x4c($sp)
/* D64 80387154 C7AC0048 */  lwc1       $f12, 0x48($sp)
/* D68 80387158 E4660004 */  swc1       $f6, 4($v1)
/* D6C 8038715C C46A0004 */  lwc1       $f10, 4($v1)
/* D70 80387160 C5080008 */  lwc1       $f8, 8($t0)
/* D74 80387164 27A4002C */  addiu      $a0, $sp, 0x2c
/* D78 80387168 46105480 */  add.s      $f18, $f10, $f16
/* D7C 8038716C E4680008 */  swc1       $f8, 8($v1)
/* D80 80387170 15200008 */  bnez       $t1, .L80387194
/* D84 80387174 E4720004 */   swc1      $f18, 4($v1)
/* D88 80387178 44056000 */  mfc1       $a1, $f12
/* D8C 8038717C 0C0E1AD5 */  jal        func_80386B54
/* D90 80387180 E7AC0048 */   swc1      $f12, 0x48($sp)
/* D94 80387184 8FA80044 */  lw         $t0, 0x44($sp)
/* D98 80387188 8FA9004C */  lw         $t1, 0x4c($sp)
/* D9C 8038718C 10000015 */  b          .L803871E4
/* DA0 80387190 C7AC0048 */   lwc1      $f12, 0x48($sp)
.L80387194:
/* DA4 80387194 904E0083 */  lbu        $t6, 0x83($v0)
/* DA8 80387198 3C028039 */  lui        $v0, %hi(D_80391710)
/* DAC 8038719C 24421710 */  addiu      $v0, $v0, %lo(D_80391710)
/* DB0 803871A0 15C00008 */  bnez       $t6, .L803871C4
/* DB4 803871A4 00000000 */   nop
/* DB8 803871A8 C4440000 */  lwc1       $f4, ($v0)
/* DBC 803871AC C4460004 */  lwc1       $f6, 4($v0)
/* DC0 803871B0 C4480008 */  lwc1       $f8, 8($v0)
/* DC4 803871B4 E7A4002C */  swc1       $f4, 0x2c($sp)
/* DC8 803871B8 E7A60030 */  swc1       $f6, 0x30($sp)
/* DCC 803871BC 10000009 */  b          .L803871E4
/* DD0 803871C0 E7A80034 */   swc1      $f8, 0x34($sp)
.L803871C4:
/* DD4 803871C4 3C028039 */  lui        $v0, %hi(D_8039171C)
/* DD8 803871C8 2442171C */  addiu      $v0, $v0, %lo(D_8039171C)
/* DDC 803871CC C44A0000 */  lwc1       $f10, ($v0)
/* DE0 803871D0 C4500004 */  lwc1       $f16, 4($v0)
/* DE4 803871D4 C4520008 */  lwc1       $f18, 8($v0)
/* DE8 803871D8 E7AA002C */  swc1       $f10, 0x2c($sp)
/* DEC 803871DC E7B00030 */  swc1       $f16, 0x30($sp)
/* DF0 803871E0 E7B20034 */  swc1       $f18, 0x34($sp)
.L803871E4:
/* DF4 803871E4 44800000 */  mtc1       $zero, $f0
/* DF8 803871E8 3C068039 */  lui        $a2, %hi(D_80392778)
/* DFC 803871EC 24C62778 */  addiu      $a2, $a2, %lo(D_80392778)
/* E00 803871F0 15200006 */  bnez       $t1, .L8038720C
/* E04 803871F4 E4C00000 */   swc1      $f0, ($a2)
/* E08 803871F8 3C018039 */  lui        $at, %hi(D_803920F8)
/* E0C 803871FC D42420F8 */  ldc1       $f4, %lo(D_803920F8)($at)
/* E10 80387200 462021A0 */  cvt.s.d    $f6, $f4
/* E14 80387204 10000005 */  b          .L8038721C
/* E18 80387208 E4C60004 */   swc1      $f6, 4($a2)
.L8038720C:
/* E1C 8038720C 3C018039 */  lui        $at, %hi(D_80392100)
/* E20 80387210 D4282100 */  ldc1       $f8, %lo(D_80392100)($at)
/* E24 80387214 462042A0 */  cvt.s.d    $f10, $f8
/* E28 80387218 E4CA0004 */  swc1       $f10, 4($a2)
.L8038721C:
/* E2C 8038721C E4C00008 */  swc1       $f0, 8($a2)
/* E30 80387220 3C014000 */  lui        $at, 0x4000
/* E34 80387224 3C068039 */  lui        $a2, 0x8039
/* E38 80387228 3C038039 */  lui        $v1, %hi(D_80392768)
/* E3C 8038722C 3C028039 */  lui        $v0, %hi(D_80392778)
/* E40 80387230 44810000 */  mtc1       $at, $f0
/* E44 80387234 24422778 */  addiu      $v0, $v0, %lo(D_80392778)
/* E48 80387238 24632768 */  addiu      $v1, $v1, %lo(D_80392768)
/* E4C 8038723C 24C62784 */  addiu      $a2, $a2, 0x2784
/* E50 80387240 27A4002C */  addiu      $a0, $sp, 0x2c
/* E54 80387244 01002825 */  or         $a1, $t0, $zero
/* E58 80387248 C4480000 */  lwc1       $f8, ($v0)
/* E5C 8038724C 24420004 */  addiu      $v0, $v0, 4
/* E60 80387250 C4900000 */  lwc1       $f16, ($a0)
/* E64 80387254 460C4482 */  mul.s      $f18, $f8, $f12
/* E68 80387258 10460010 */  beq        $v0, $a2, .L8038729C
/* E6C 8038725C C4AE0000 */   lwc1      $f14, ($a1)
/* E70 80387260 46009283 */  div.s      $f10, $f18, $f0
.L80387264:
/* E74 80387264 C4480000 */  lwc1       $f8, ($v0)
/* E78 80387268 24420004 */  addiu      $v0, $v0, 4
/* E7C 8038726C 24630004 */  addiu      $v1, $v1, 4
/* E80 80387270 460C4482 */  mul.s      $f18, $f8, $f12
/* E84 80387274 460E8201 */  sub.s      $f8, $f16, $f14
/* E88 80387278 C4900004 */  lwc1       $f16, 4($a0)
/* E8C 8038727C 24840004 */  addiu      $a0, $a0, 4
/* E90 80387280 24A50004 */  addiu      $a1, $a1, 4
/* E94 80387284 460C4203 */  div.s      $f8, $f8, $f12
/* E98 80387288 460A4281 */  sub.s      $f10, $f8, $f10
/* E9C 8038728C E46AFFFC */  swc1       $f10, -4($v1)
/* EA0 80387290 C4AE0000 */  lwc1       $f14, ($a1)
/* EA4 80387294 5446FFF3 */  bnel       $v0, $a2, .L80387264
/* EA8 80387298 46009283 */   div.s     $f10, $f18, $f0
.L8038729C:
/* EAC 8038729C 460E8201 */  sub.s      $f8, $f16, $f14
/* EB0 803872A0 24630004 */  addiu      $v1, $v1, 4
/* EB4 803872A4 24840004 */  addiu      $a0, $a0, 4
/* EB8 803872A8 46009283 */  div.s      $f10, $f18, $f0
/* EBC 803872AC 24A50004 */  addiu      $a1, $a1, 4
/* EC0 803872B0 460C4203 */  div.s      $f8, $f8, $f12
/* EC4 803872B4 460A4281 */  sub.s      $f10, $f8, $f10
/* EC8 803872B8 E46AFFFC */  swc1       $f10, -4($v1)
/* ECC 803872BC 15200007 */  bnez       $t1, .L803872DC
/* ED0 803872C0 3C048038 */   lui       $a0, 0x8038
/* ED4 803872C4 3C048038 */  lui        $a0, %hi(func_80386FD8)
/* ED8 803872C8 24846FD8 */  addiu      $a0, $a0, %lo(func_80386FD8)
/* EDC 803872CC 0C0B0F22 */  jal        func_802C3C88
/* EE0 803872D0 8FA50040 */   lw        $a1, 0x40($sp)
/* EE4 803872D4 10000005 */  b          .L803872EC
/* EE8 803872D8 8FBF0014 */   lw        $ra, 0x14($sp)
.L803872DC:
/* EEC 803872DC 24847074 */  addiu      $a0, $a0, 0x7074
/* EF0 803872E0 0C0B0F22 */  jal        func_802C3C88
/* EF4 803872E4 8FA50040 */   lw        $a1, 0x40($sp)
/* EF8 803872E8 8FBF0014 */  lw         $ra, 0x14($sp)
.L803872EC:
/* EFC 803872EC 27BD0040 */  addiu      $sp, $sp, 0x40
/* F00 803872F0 03E00008 */  jr         $ra
/* F04 803872F4 00000000 */   nop
glabel func_803872F8
/* F08 803872F8 27BDFFD8 */  addiu      $sp, $sp, -0x28
/* F0C 803872FC AFBF0014 */  sw         $ra, 0x14($sp)
/* F10 80387300 AFA40028 */  sw         $a0, 0x28($sp)
/* F14 80387304 8C8F0000 */  lw         $t7, ($a0)
/* F18 80387308 27A6001C */  addiu      $a2, $sp, 0x1c
/* F1C 8038730C 2405000A */  addiu      $a1, $zero, 0xa
/* F20 80387310 0C0D285D */  jal        func_8034A174
/* F24 80387314 8DE40044 */   lw        $a0, 0x44($t7)
/* F28 80387318 8FB80028 */  lw         $t8, 0x28($sp)
/* F2C 8038731C 27A5001C */  addiu      $a1, $sp, 0x1c
/* F30 80387320 3C064040 */  lui        $a2, 0x4040
/* F34 80387324 24070001 */  addiu      $a3, $zero, 1
/* F38 80387328 0C0E1C44 */  jal        func_80387110
/* F3C 8038732C 8F040000 */   lw        $a0, ($t8)
/* F40 80387330 8FBF0014 */  lw         $ra, 0x14($sp)
/* F44 80387334 27BD0028 */  addiu      $sp, $sp, 0x28
/* F48 80387338 03E00008 */  jr         $ra
/* F4C 8038733C 00000000 */   nop
glabel func_80387340
/* F50 80387340 27BDFFD0 */  addiu      $sp, $sp, -0x30
/* F54 80387344 AFBF001C */  sw         $ra, 0x1c($sp)
/* F58 80387348 AFB00018 */  sw         $s0, 0x18($sp)
/* F5C 8038734C AFA50034 */  sw         $a1, 0x34($sp)
/* F60 80387350 00808025 */  or         $s0, $a0, $zero
/* F64 80387354 0C0CA21B */  jal        actor_animationIsAt
/* F68 80387358 3C053F00 */   lui       $a1, 0x3f00
/* F6C 8038735C 5040001A */  beql       $v0, $zero, .L803873C8
/* F70 80387360 00001025 */   or        $v0, $zero, $zero
/* F74 80387364 8E020000 */  lw         $v0, ($s0)
/* F78 80387368 24050005 */  addiu      $a1, $zero, 5
/* F7C 8038736C 27A60024 */  addiu      $a2, $sp, 0x24
/* F80 80387370 8C4E0014 */  lw         $t6, 0x14($v0)
/* F84 80387374 000EC280 */  sll        $t8, $t6, 0xa
/* F88 80387378 07030006 */  bgezl      $t8, .L80387394
/* F8C 8038737C C6040004 */   lwc1      $f4, 4($s0)
/* F90 80387380 0C0D285D */  jal        func_8034A174
/* F94 80387384 8C440044 */   lw        $a0, 0x44($v0)
/* F98 80387388 10000008 */  b          .L803873AC
/* F9C 8038738C 8E040000 */   lw        $a0, ($s0)
/* FA0 80387390 C6040004 */  lwc1       $f4, 4($s0)
.L80387394:
/* FA4 80387394 E7A40024 */  swc1       $f4, 0x24($sp)
/* FA8 80387398 C6060008 */  lwc1       $f6, 8($s0)
/* FAC 8038739C E7A60028 */  swc1       $f6, 0x28($sp)
/* FB0 803873A0 C608000C */  lwc1       $f8, 0xc($s0)
/* FB4 803873A4 E7A8002C */  swc1       $f8, 0x2c($sp)
/* FB8 803873A8 8E040000 */  lw         $a0, ($s0)
.L803873AC:
/* FBC 803873AC 27A50024 */  addiu      $a1, $sp, 0x24
/* FC0 803873B0 8FA60034 */  lw         $a2, 0x34($sp)
/* FC4 803873B4 0C0E1C44 */  jal        func_80387110
/* FC8 803873B8 00003825 */   or        $a3, $zero, $zero
/* FCC 803873BC 10000002 */  b          .L803873C8
/* FD0 803873C0 24020001 */   addiu     $v0, $zero, 1
/* FD4 803873C4 00001025 */  or         $v0, $zero, $zero
.L803873C8:
/* FD8 803873C8 8FBF001C */  lw         $ra, 0x1c($sp)
/* FDC 803873CC 8FB00018 */  lw         $s0, 0x18($sp)
/* FE0 803873D0 27BD0030 */  addiu      $sp, $sp, 0x30
/* FE4 803873D4 03E00008 */  jr         $ra
/* FE8 803873D8 00000000 */   nop
glabel func_803873DC
/* FEC 803873DC 27BDFFD0 */  addiu      $sp, $sp, -0x30
/* FF0 803873E0 AFBF001C */  sw         $ra, 0x1c($sp)
/* FF4 803873E4 AFB00018 */  sw         $s0, 0x18($sp)
/* FF8 803873E8 AFA50034 */  sw         $a1, 0x34($sp)
/* FFC 803873EC 00808025 */  or         $s0, $a0, $zero
/* 1000 803873F0 AFA60038 */  sw         $a2, 0x38($sp)
/* 1004 803873F4 0C0CA21B */  jal        actor_animationIsAt
/* 1008 803873F8 3C053F00 */   lui       $a1, 0x3f00
/* 100C 803873FC 50400018 */  beql       $v0, $zero, .L80387460
/* 1010 80387400 8FBF001C */   lw        $ra, 0x1c($sp)
/* 1014 80387404 8E020000 */  lw         $v0, ($s0)
/* 1018 80387408 24050006 */  addiu      $a1, $zero, 6
/* 101C 8038740C 27A60024 */  addiu      $a2, $sp, 0x24
/* 1020 80387410 8C4E0014 */  lw         $t6, 0x14($v0)
/* 1024 80387414 000EC280 */  sll        $t8, $t6, 0xa
/* 1028 80387418 07030006 */  bgezl      $t8, .L80387434
/* 102C 8038741C C6040004 */   lwc1      $f4, 4($s0)
/* 1030 80387420 0C0D285D */  jal        func_8034A174
/* 1034 80387424 8C440044 */   lw        $a0, 0x44($v0)
/* 1038 80387428 10000008 */  b          .L8038744C
/* 103C 8038742C 8E040000 */   lw        $a0, ($s0)
/* 1040 80387430 C6040004 */  lwc1       $f4, 4($s0)
.L80387434:
/* 1044 80387434 E7A40024 */  swc1       $f4, 0x24($sp)
/* 1048 80387438 C6060008 */  lwc1       $f6, 8($s0)
/* 104C 8038743C E7A60028 */  swc1       $f6, 0x28($sp)
/* 1050 80387440 C608000C */  lwc1       $f8, 0xc($s0)
/* 1054 80387444 E7A8002C */  swc1       $f8, 0x2c($sp)
/* 1058 80387448 8E040000 */  lw         $a0, ($s0)
.L8038744C:
/* 105C 8038744C 27A50024 */  addiu      $a1, $sp, 0x24
/* 1060 80387450 8FA60034 */  lw         $a2, 0x34($sp)
/* 1064 80387454 0C0E1BD7 */  jal        func_80386F5C
/* 1068 80387458 8FA70038 */   lw        $a3, 0x38($sp)
/* 106C 8038745C 8FBF001C */  lw         $ra, 0x1c($sp)
.L80387460:
/* 1070 80387460 8FB00018 */  lw         $s0, 0x18($sp)
/* 1074 80387464 27BD0030 */  addiu      $sp, $sp, 0x30
/* 1078 80387468 03E00008 */  jr         $ra
/* 107C 8038746C 00000000 */   nop
glabel func_80387470
/* 1080 80387470 27BDFF98 */  addiu      $sp, $sp, -0x68
/* 1084 80387474 AFBF002C */  sw         $ra, 0x2c($sp)
/* 1088 80387478 AFB00028 */  sw         $s0, 0x28($sp)
/* 108C 8038747C 00808025 */  or         $s0, $a0, $zero
/* 1090 80387480 F7B40020 */  sdc1       $f20, 0x20($sp)
/* 1094 80387484 AFA5006C */  sw         $a1, 0x6c($sp)
/* 1098 80387488 AFA60070 */  sw         $a2, 0x70($sp)
/* 109C 8038748C 0C0CF767 */  jal        time_getDelta
/* 10A0 80387490 AFA70074 */   sw        $a3, 0x74($sp)
/* 10A4 80387494 8FA6006C */  lw         $a2, 0x6c($sp)
/* 10A8 80387498 C6060004 */  lwc1       $f6, 4($s0)
/* 10AC 8038749C C7A20074 */  lwc1       $f2, 0x74($sp)
/* 10B0 803874A0 C4C40000 */  lwc1       $f4, ($a2)
/* 10B4 803874A4 46000506 */  mov.s      $f20, $f0
/* 10B8 803874A8 26040004 */  addiu      $a0, $s0, 4
/* 10BC 803874AC 46062201 */  sub.s      $f8, $f4, $f6
/* 10C0 803874B0 00C02825 */  or         $a1, $a2, $zero
/* 10C4 803874B4 E7A80058 */  swc1       $f8, 0x58($sp)
/* 10C8 803874B8 C6100008 */  lwc1       $f16, 8($s0)
/* 10CC 803874BC C4CA0004 */  lwc1       $f10, 4($a2)
/* 10D0 803874C0 46105481 */  sub.s      $f18, $f10, $f16
/* 10D4 803874C4 44808000 */  mtc1       $zero, $f16
/* 10D8 803874C8 C7AA007C */  lwc1       $f10, 0x7c($sp)
/* 10DC 803874CC E7B2005C */  swc1       $f18, 0x5c($sp)
/* 10E0 803874D0 C606000C */  lwc1       $f6, 0xc($s0)
/* 10E4 803874D4 C4C40008 */  lwc1       $f4, 8($a2)
/* 10E8 803874D8 46105032 */  c.eq.s     $f10, $f16
/* 10EC 803874DC 46062201 */  sub.s      $f8, $f4, $f6
/* 10F0 803874E0 45010017 */  bc1t       .L80387540
/* 10F4 803874E4 E7A80060 */   swc1      $f8, 0x60($sp)
/* 10F8 803874E8 0C095819 */  jal        ml_vec3f_distance
/* 10FC 803874EC AFA4003C */   sw        $a0, 0x3c($sp)
/* 1100 803874F0 C7B2007C */  lwc1       $f18, 0x7c($sp)
/* 1104 803874F4 C7A20074 */  lwc1       $f2, 0x74($sp)
/* 1108 803874F8 3C014080 */  lui        $at, 0x4080
/* 110C 803874FC 4612003C */  c.lt.s     $f0, $f18
/* 1110 80387500 00000000 */  nop
/* 1114 80387504 4502000A */  bc1fl      .L80387530
/* 1118 80387508 44051000 */   mfc1      $a1, $f2
/* 111C 8038750C 44812000 */  mtc1       $at, $f4
/* 1120 80387510 27A40058 */  addiu      $a0, $sp, 0x58
/* 1124 80387514 46041182 */  mul.s      $f6, $f2, $f4
/* 1128 80387518 44053000 */  mfc1       $a1, $f6
/* 112C 8038751C 0C095A89 */  jal        ml_vec3f_set_length
/* 1130 80387520 00000000 */   nop
/* 1134 80387524 1000000C */  b          .L80387558
/* 1138 80387528 C600002C */   lwc1      $f0, 0x2c($s0)
/* 113C 8038752C 44051000 */  mfc1       $a1, $f2
.L80387530:
/* 1140 80387530 0C095A89 */  jal        ml_vec3f_set_length
/* 1144 80387534 27A40058 */   addiu     $a0, $sp, 0x58
/* 1148 80387538 10000007 */  b          .L80387558
/* 114C 8038753C C600002C */   lwc1      $f0, 0x2c($s0)
.L80387540:
/* 1150 80387540 44051000 */  mfc1       $a1, $f2
/* 1154 80387544 0C095A89 */  jal        ml_vec3f_set_length
/* 1158 80387548 27A40058 */   addiu     $a0, $sp, 0x58
/* 115C 8038754C 260E0004 */  addiu      $t6, $s0, 4
/* 1160 80387550 AFAE003C */  sw         $t6, 0x3c($sp)
/* 1164 80387554 C600002C */  lwc1       $f0, 0x2c($s0)
.L80387558:
/* 1168 80387558 C7AA0058 */  lwc1       $f10, 0x58($sp)
/* 116C 8038755C C6060004 */  lwc1       $f6, 4($s0)
/* 1170 80387560 46140202 */  mul.s      $f8, $f0, $f20
/* 1174 80387564 C6020030 */  lwc1       $f2, 0x30($s0)
/* 1178 80387568 C60E0034 */  lwc1       $f14, 0x34($s0)
/* 117C 8038756C 46145402 */  mul.s      $f16, $f10, $f20
/* 1180 80387570 00000000 */  nop
/* 1184 80387574 46148482 */  mul.s      $f18, $f16, $f20
/* 1188 80387578 46124100 */  add.s      $f4, $f8, $f18
/* 118C 8038757C 46141402 */  mul.s      $f16, $f2, $f20
/* 1190 80387580 46043280 */  add.s      $f10, $f6, $f4
/* 1194 80387584 E60A0004 */  swc1       $f10, 4($s0)
/* 1198 80387588 C7A8005C */  lwc1       $f8, 0x5c($sp)
/* 119C 8038758C C60A0008 */  lwc1       $f10, 8($s0)
/* 11A0 80387590 46144482 */  mul.s      $f18, $f8, $f20
/* 11A4 80387594 00000000 */  nop
/* 11A8 80387598 46149182 */  mul.s      $f6, $f18, $f20
/* 11AC 8038759C 46068100 */  add.s      $f4, $f16, $f6
/* 11B0 803875A0 46147482 */  mul.s      $f18, $f14, $f20
/* 11B4 803875A4 46045200 */  add.s      $f8, $f10, $f4
/* 11B8 803875A8 E6080008 */  swc1       $f8, 8($s0)
/* 11BC 803875AC C7B00060 */  lwc1       $f16, 0x60($sp)
/* 11C0 803875B0 C608000C */  lwc1       $f8, 0xc($s0)
/* 11C4 803875B4 46148182 */  mul.s      $f6, $f16, $f20
/* 11C8 803875B8 00000000 */  nop
/* 11CC 803875BC 46143282 */  mul.s      $f10, $f6, $f20
/* 11D0 803875C0 460A9100 */  add.s      $f4, $f18, $f10
/* 11D4 803875C4 46044400 */  add.s      $f16, $f8, $f4
/* 11D8 803875C8 E610000C */  swc1       $f16, 0xc($s0)
/* 11DC 803875CC C7A60058 */  lwc1       $f6, 0x58($sp)
/* 11E0 803875D0 46143482 */  mul.s      $f18, $f6, $f20
/* 11E4 803875D4 46120280 */  add.s      $f10, $f0, $f18
/* 11E8 803875D8 E60A002C */  swc1       $f10, 0x2c($s0)
/* 11EC 803875DC C7A8005C */  lwc1       $f8, 0x5c($sp)
/* 11F0 803875E0 C600002C */  lwc1       $f0, 0x2c($s0)
/* 11F4 803875E4 46144102 */  mul.s      $f4, $f8, $f20
/* 11F8 803875E8 46041400 */  add.s      $f16, $f2, $f4
/* 11FC 803875EC E6100030 */  swc1       $f16, 0x30($s0)
/* 1200 803875F0 C7A60060 */  lwc1       $f6, 0x60($sp)
/* 1204 803875F4 C6020030 */  lwc1       $f2, 0x30($s0)
/* 1208 803875F8 46143482 */  mul.s      $f18, $f6, $f20
/* 120C 803875FC 46127280 */  add.s      $f10, $f14, $f18
/* 1210 80387600 46000202 */  mul.s      $f8, $f0, $f0
/* 1214 80387604 00000000 */  nop
/* 1218 80387608 46021102 */  mul.s      $f4, $f2, $f2
/* 121C 8038760C E60A0034 */  swc1       $f10, 0x34($s0)
/* 1220 80387610 C60E0034 */  lwc1       $f14, 0x34($s0)
/* 1224 80387614 460E7182 */  mul.s      $f6, $f14, $f14
/* 1228 80387618 46044400 */  add.s      $f16, $f8, $f4
/* 122C 8038761C 0C0994D4 */  jal        gu_sqrtf
/* 1230 80387620 46103300 */   add.s     $f12, $f6, $f16
/* 1234 80387624 C7A20070 */  lwc1       $f2, 0x70($sp)
/* 1238 80387628 4600103C */  c.lt.s     $f2, $f0
/* 123C 8038762C 00000000 */  nop
/* 1240 80387630 45020005 */  bc1fl      .L80387648
/* 1244 80387634 C612002C */   lwc1      $f18, 0x2c($s0)
/* 1248 80387638 44051000 */  mfc1       $a1, $f2
/* 124C 8038763C 0C095A89 */  jal        ml_vec3f_set_length
/* 1250 80387640 2604002C */   addiu     $a0, $s0, 0x2c
/* 1254 80387644 C612002C */  lwc1       $f18, 0x2c($s0)
.L80387648:
/* 1258 80387648 C60A0004 */  lwc1       $f10, 4($s0)
/* 125C 8038764C 3C0142B4 */  lui        $at, 0x42b4
/* 1260 80387650 27AF0050 */  addiu      $t7, $sp, 0x50
/* 1264 80387654 460A9200 */  add.s      $f8, $f18, $f10
/* 1268 80387658 27B8004C */  addiu      $t8, $sp, 0x4c
/* 126C 8038765C 8FA4003C */  lw         $a0, 0x3c($sp)
/* 1270 80387660 27A60040 */  addiu      $a2, $sp, 0x40
/* 1274 80387664 E7A80040 */  swc1       $f8, 0x40($sp)
/* 1278 80387668 C6060008 */  lwc1       $f6, 8($s0)
/* 127C 8038766C C6040030 */  lwc1       $f4, 0x30($s0)
/* 1280 80387670 27A70054 */  addiu      $a3, $sp, 0x54
/* 1284 80387674 46062400 */  add.s      $f16, $f4, $f6
/* 1288 80387678 44813000 */  mtc1       $at, $f6
/* 128C 8038767C E7B00044 */  swc1       $f16, 0x44($sp)
/* 1290 80387680 C60A000C */  lwc1       $f10, 0xc($s0)
/* 1294 80387684 C6120034 */  lwc1       $f18, 0x34($s0)
/* 1298 80387688 460A9200 */  add.s      $f8, $f18, $f10
/* 129C 8038768C E7A80048 */  swc1       $f8, 0x48($sp)
/* 12A0 80387690 C6040050 */  lwc1       $f4, 0x50($s0)
/* 12A4 80387694 AFB80014 */  sw         $t8, 0x14($sp)
/* 12A8 80387698 AFAF0010 */  sw         $t7, 0x10($sp)
/* 12AC 8038769C 46062401 */  sub.s      $f16, $f4, $f6
/* 12B0 803876A0 44058000 */  mfc1       $a1, $f16
/* 12B4 803876A4 0C096293 */  jal        func_80258A4C
/* 12B8 803876A8 00000000 */   nop
/* 12BC 803876AC C7B20078 */  lwc1       $f18, 0x78($sp)
/* 12C0 803876B0 C7AA004C */  lwc1       $f10, 0x4c($sp)
/* 12C4 803876B4 C6060050 */  lwc1       $f6, 0x50($s0)
/* 12C8 803876B8 460A9202 */  mul.s      $f8, $f18, $f10
/* 12CC 803876BC 00000000 */  nop
/* 12D0 803876C0 46144102 */  mul.s      $f4, $f8, $f20
/* 12D4 803876C4 46043400 */  add.s      $f16, $f6, $f4
/* 12D8 803876C8 E6100050 */  swc1       $f16, 0x50($s0)
/* 12DC 803876CC 8FA5006C */  lw         $a1, 0x6c($sp)
/* 12E0 803876D0 0C095819 */  jal        ml_vec3f_distance
/* 12E4 803876D4 8FA4003C */   lw        $a0, 0x3c($sp)
/* 12E8 803876D8 C7B20080 */  lwc1       $f18, 0x80($sp)
/* 12EC 803876DC 8FBF002C */  lw         $ra, 0x2c($sp)
/* 12F0 803876E0 00001025 */  or         $v0, $zero, $zero
/* 12F4 803876E4 4612003C */  c.lt.s     $f0, $f18
/* 12F8 803876E8 00000000 */  nop
/* 12FC 803876EC 45000003 */  bc1f       .L803876FC
/* 1300 803876F0 00000000 */   nop
/* 1304 803876F4 10000001 */  b          .L803876FC
/* 1308 803876F8 24020001 */   addiu     $v0, $zero, 1
.L803876FC:
/* 130C 803876FC D7B40020 */  ldc1       $f20, 0x20($sp)
/* 1310 80387700 8FB00028 */  lw         $s0, 0x28($sp)
/* 1314 80387704 03E00008 */  jr         $ra
/* 1318 80387708 27BD0068 */   addiu     $sp, $sp, 0x68
glabel func_8038770C
/* 131C 8038770C A080007D */  sb         $zero, 0x7d($a0)
/* 1320 80387710 A080007E */  sb         $zero, 0x7e($a0)
/* 1324 80387714 A080007F */  sb         $zero, 0x7f($a0)
/* 1328 80387718 A0800080 */  sb         $zero, 0x80($a0)
/* 132C 8038771C A0800082 */  sb         $zero, 0x82($a0)
/* 1330 80387720 03E00008 */  jr         $ra
/* 1334 80387724 A0800086 */   sb        $zero, 0x86($a0)
glabel func_80387728
/* 1338 80387728 27BDFFD8 */  addiu      $sp, $sp, -0x28
/* 133C 8038772C AFBF0024 */  sw         $ra, 0x24($sp)
/* 1340 80387730 AFB10020 */  sw         $s1, 0x20($sp)
/* 1344 80387734 AFB0001C */  sw         $s0, 0x1c($sp)
/* 1348 80387738 0C0CA656 */  jal        marker_getActor
/* 134C 8038773C AFA5002C */   sw        $a1, 0x2c($sp)
/* 1350 80387740 8FAE002C */  lw         $t6, 0x2c($sp)
/* 1354 80387744 00408025 */  or         $s0, $v0, $zero
/* 1358 80387748 2451007C */  addiu      $s1, $v0, 0x7c
/* 135C 8038774C 00402025 */  or         $a0, $v0, $zero
/* 1360 80387750 0C0E1DC3 */  jal        func_8038770C
/* 1364 80387754 A04E007C */   sb        $t6, 0x7c($v0)
/* 1368 80387758 8E040000 */  lw         $a0, ($s0)
/* 136C 8038775C 0C0E1980 */  jal        func_80386600
/* 1370 80387760 00002825 */   or        $a1, $zero, $zero
/* 1374 80387764 8E040000 */  lw         $a0, ($s0)
/* 1378 80387768 0C0E198A */  jal        func_80386628
/* 137C 8038776C 24050001 */   addiu     $a1, $zero, 1
/* 1380 80387770 8FAF002C */  lw         $t7, 0x2c($sp)
/* 1384 80387774 2DE10006 */  sltiu      $at, $t7, 6
/* 1388 80387778 102000CF */  beqz       $at, .L80387AB8
/* 138C 8038777C 000F7880 */   sll       $t7, $t7, 2
/* 1390 80387780 3C018039 */  lui        $at, %hi(D_80392108)
/* 1394 80387784 002F0821 */  addu       $at, $at, $t7
/* 1398 80387788 8C2F2108 */  lw         $t7, %lo(D_80392108)($at)
/* 139C 8038778C 01E00008 */  jr         $t7
/* 13A0 80387790 00000000 */   nop
/* 13A4 80387794 3C0638D1 */  lui        $a2, 0x38d1
/* 13A8 80387798 34C6B717 */  ori        $a2, $a2, 0xb717
/* 13AC 8038779C 02002025 */  or         $a0, $s0, $zero
/* 13B0 803877A0 24050001 */  addiu      $a1, $zero, 1
/* 13B4 803877A4 0C0CA2E3 */  jal        func_80328B8C
/* 13B8 803877A8 24070001 */   addiu     $a3, $zero, 1
/* 13BC 803877AC 44806000 */  mtc1       $zero, $f12
/* 13C0 803877B0 0C0C9398 */  jal        timed_setCameraToNode
/* 13C4 803877B4 00002825 */   or        $a1, $zero, $zero
/* 13C8 803877B8 3C014000 */  lui        $at, 0x4000
/* 13CC 803877BC 44816000 */  mtc1       $at, $f12
/* 13D0 803877C0 0C0C93A2 */  jal        func_80324E88
/* 13D4 803877C4 00000000 */   nop
/* 13D8 803877C8 3C014000 */  lui        $at, 0x4000
/* 13DC 803877CC 44816000 */  mtc1       $at, $f12
/* 13E0 803877D0 0C0C9398 */  jal        timed_setCameraToNode
/* 13E4 803877D4 24050001 */   addiu     $a1, $zero, 1
/* 13E8 803877D8 3C014000 */  lui        $at, 0x4000
/* 13EC 803877DC 44816000 */  mtc1       $at, $f12
/* 13F0 803877E0 3C058039 */  lui        $a1, %hi(func_8038B780)
/* 13F4 803877E4 24A5B780 */  addiu      $a1, $a1, %lo(func_8038B780)
/* 13F8 803877E8 0C0C93B9 */  jal        timedFunc_set_1
/* 13FC 803877EC 8E060000 */   lw        $a2, ($s0)
/* 1400 803877F0 100000B2 */  b          .L80387ABC
/* 1404 803877F4 8FBF0024 */   lw        $ra, 0x24($sp)
/* 1408 803877F8 3C0638D1 */  lui        $a2, 0x38d1
/* 140C 803877FC 34C6B717 */  ori        $a2, $a2, 0xb717
/* 1410 80387800 02002025 */  or         $a0, $s0, $zero
/* 1414 80387804 24050002 */  addiu      $a1, $zero, 2
/* 1418 80387808 0C0CA2E3 */  jal        func_80328B8C
/* 141C 8038780C 24070001 */   addiu     $a3, $zero, 1
/* 1420 80387810 3C018039 */  lui        $at, %hi(D_80392120)
/* 1424 80387814 C42C2120 */  lwc1       $f12, %lo(D_80392120)($at)
/* 1428 80387818 3C018039 */  lui        $at, %hi(D_80392124)
/* 142C 8038781C 0C0D29D5 */  jal        randf2
/* 1430 80387820 C42E2124 */   lwc1      $f14, %lo(D_80392124)($at)
/* 1434 80387824 3C018039 */  lui        $at, %hi(D_80392128)
/* 1438 80387828 C4242128 */  lwc1       $f4, %lo(D_80392128)($at)
/* 143C 8038782C 3C018039 */  lui        $at, %hi(D_8039212C)
/* 1440 80387830 C426212C */  lwc1       $f6, %lo(D_8039212C)($at)
/* 1444 80387834 44050000 */  mfc1       $a1, $f0
/* 1448 80387838 240400EA */  addiu      $a0, $zero, 0xea
/* 144C 8038783C 24067D00 */  addiu      $a2, $zero, 0x7d00
/* 1450 80387840 26070004 */  addiu      $a3, $s0, 4
/* 1454 80387844 E7A40010 */  swc1       $f4, 0x10($sp)
/* 1458 80387848 0C0C3A1E */  jal        func_8030E878
/* 145C 8038784C E7A60014 */   swc1      $f6, 0x14($sp)
/* 1460 80387850 2402000C */  addiu      $v0, $zero, 0xc
/* 1464 80387854 301800FF */  andi       $t8, $zero, 0xff
/* 1468 80387858 03020019 */  multu      $t8, $v0
/* 146C 8038785C 3C038039 */  lui        $v1, %hi(D_803927D0)
/* 1470 80387860 246327D0 */  addiu      $v1, $v1, %lo(D_803927D0)
/* 1474 80387864 A2200005 */  sb         $zero, 5($s1)
/* 1478 80387868 0000C812 */  mflo       $t9
/* 147C 8038786C 00794021 */  addu       $t0, $v1, $t9
/* 1480 80387870 C5080000 */  lwc1       $f8, ($t0)
/* 1484 80387874 E608001C */  swc1       $f8, 0x1c($s0)
/* 1488 80387878 92290005 */  lbu        $t1, 5($s1)
/* 148C 8038787C 01220019 */  multu      $t1, $v0
/* 1490 80387880 00005012 */  mflo       $t2
/* 1494 80387884 006A5821 */  addu       $t3, $v1, $t2
/* 1498 80387888 C56A0004 */  lwc1       $f10, 4($t3)
/* 149C 8038788C E60A0020 */  swc1       $f10, 0x20($s0)
/* 14A0 80387890 922C0005 */  lbu        $t4, 5($s1)
/* 14A4 80387894 01820019 */  multu      $t4, $v0
/* 14A8 80387898 00006812 */  mflo       $t5
/* 14AC 8038789C 006D7021 */  addu       $t6, $v1, $t5
/* 14B0 803878A0 C5D00008 */  lwc1       $f16, 8($t6)
/* 14B4 803878A4 E6100024 */  swc1       $f16, 0x24($s0)
/* 14B8 803878A8 AE200010 */  sw         $zero, 0x10($s1)
/* 14BC 803878AC 920F0044 */  lbu        $t7, 0x44($s0)
/* 14C0 803878B0 55E00082 */  bnel       $t7, $zero, .L80387ABC
/* 14C4 803878B4 8FBF0024 */   lw        $ra, 0x24($sp)
/* 14C8 803878B8 0C0C3643 */  jal        func_8030D90C
/* 14CC 803878BC 00000000 */   nop
/* 14D0 803878C0 A2020044 */  sb         $v0, 0x44($s0)
/* 14D4 803878C4 304400FF */  andi       $a0, $v0, 0xff
/* 14D8 803878C8 0C0C36A0 */  jal        sfxsource_setSfxId
/* 14DC 803878CC 24050152 */   addiu     $a1, $zero, 0x152
/* 14E0 803878D0 92040044 */  lbu        $a0, 0x44($s0)
/* 14E4 803878D4 0C0C3745 */  jal        func_8030DD14
/* 14E8 803878D8 24050003 */   addiu     $a1, $zero, 3
/* 14EC 803878DC 92040044 */  lbu        $a0, 0x44($s0)
/* 14F0 803878E0 0C0C36ED */  jal        func_8030DBB4
/* 14F4 803878E4 3C053F80 */   lui       $a1, 0x3f80
/* 14F8 803878E8 92040044 */  lbu        $a0, 0x44($s0)
/* 14FC 803878EC 0C0C36AF */  jal        sfxsource_setSampleRate
/* 1500 803878F0 24057D00 */   addiu     $a1, $zero, 0x7d00
/* 1504 803878F4 10000071 */  b          .L80387ABC
/* 1508 803878F8 8FBF0024 */   lw        $ra, 0x24($sp)
/* 150C 803878FC 3C0638D1 */  lui        $a2, 0x38d1
/* 1510 80387900 34C6B717 */  ori        $a2, $a2, 0xb717
/* 1514 80387904 02002025 */  or         $a0, $s0, $zero
/* 1518 80387908 2405000E */  addiu      $a1, $zero, 0xe
/* 151C 8038790C 0C0CA2E3 */  jal        func_80328B8C
/* 1520 80387910 24070001 */   addiu     $a3, $zero, 1
/* 1524 80387914 24180008 */  addiu      $t8, $zero, 8
/* 1528 80387918 2402000C */  addiu      $v0, $zero, 0xc
/* 152C 8038791C 331900FF */  andi       $t9, $t8, 0xff
/* 1530 80387920 03220019 */  multu      $t9, $v0
/* 1534 80387924 3C038039 */  lui        $v1, %hi(D_803927D0)
/* 1538 80387928 246327D0 */  addiu      $v1, $v1, %lo(D_803927D0)
/* 153C 8038792C A2380005 */  sb         $t8, 5($s1)
/* 1540 80387930 00002025 */  or         $a0, $zero, $zero
/* 1544 80387934 24050005 */  addiu      $a1, $zero, 5
/* 1548 80387938 00004012 */  mflo       $t0
/* 154C 8038793C 00684821 */  addu       $t1, $v1, $t0
/* 1550 80387940 C5320000 */  lwc1       $f18, ($t1)
/* 1554 80387944 E612001C */  swc1       $f18, 0x1c($s0)
/* 1558 80387948 922A0005 */  lbu        $t2, 5($s1)
/* 155C 8038794C 01420019 */  multu      $t2, $v0
/* 1560 80387950 00005812 */  mflo       $t3
/* 1564 80387954 006B6021 */  addu       $t4, $v1, $t3
/* 1568 80387958 C5840004 */  lwc1       $f4, 4($t4)
/* 156C 8038795C E6040020 */  swc1       $f4, 0x20($s0)
/* 1570 80387960 922D0005 */  lbu        $t5, 5($s1)
/* 1574 80387964 01A20019 */  multu      $t5, $v0
/* 1578 80387968 00007012 */  mflo       $t6
/* 157C 8038796C 006E7821 */  addu       $t7, $v1, $t6
/* 1580 80387970 C5E60008 */  lwc1       $f6, 8($t7)
/* 1584 80387974 0C0D29EF */  jal        randi2
/* 1588 80387978 E6060024 */   swc1      $f6, 0x24($s0)
/* 158C 8038797C 24441106 */  addiu      $a0, $v0, 0x1106
/* 1590 80387980 24050004 */  addiu      $a1, $zero, 4
/* 1594 80387984 00003025 */  or         $a2, $zero, $zero
/* 1598 80387988 00003825 */  or         $a3, $zero, $zero
/* 159C 8038798C AFA00010 */  sw         $zero, 0x10($sp)
/* 15A0 80387990 0C0C4520 */  jal        func_80311480
/* 15A4 80387994 AFA00014 */   sw        $zero, 0x14($sp)
/* 15A8 80387998 10000048 */  b          .L80387ABC
/* 15AC 8038799C 8FBF0024 */   lw        $ra, 0x24($sp)
/* 15B0 803879A0 3C0638D1 */  lui        $a2, 0x38d1
/* 15B4 803879A4 34C6B717 */  ori        $a2, $a2, 0xb717
/* 15B8 803879A8 02002025 */  or         $a0, $s0, $zero
/* 15BC 803879AC 24050015 */  addiu      $a1, $zero, 0x15
/* 15C0 803879B0 0C0CA2E3 */  jal        func_80328B8C
/* 15C4 803879B4 24070001 */   addiu     $a3, $zero, 1
/* 15C8 803879B8 2402000C */  addiu      $v0, $zero, 0xc
/* 15CC 803879BC 305800FF */  andi       $t8, $v0, 0xff
/* 15D0 803879C0 03020019 */  multu      $t8, $v0
/* 15D4 803879C4 3C038039 */  lui        $v1, %hi(D_803927D0)
/* 15D8 803879C8 246327D0 */  addiu      $v1, $v1, %lo(D_803927D0)
/* 15DC 803879CC A2220005 */  sb         $v0, 5($s1)
/* 15E0 803879D0 3C014170 */  lui        $at, 0x4170
/* 15E4 803879D4 44819000 */  mtc1       $at, $f18
/* 15E8 803879D8 0000C812 */  mflo       $t9
/* 15EC 803879DC 00794021 */  addu       $t0, $v1, $t9
/* 15F0 803879E0 C5080000 */  lwc1       $f8, ($t0)
/* 15F4 803879E4 E608001C */  swc1       $f8, 0x1c($s0)
/* 15F8 803879E8 92290005 */  lbu        $t1, 5($s1)
/* 15FC 803879EC 01220019 */  multu      $t1, $v0
/* 1600 803879F0 00005012 */  mflo       $t2
/* 1604 803879F4 006A5821 */  addu       $t3, $v1, $t2
/* 1608 803879F8 C56A0004 */  lwc1       $f10, 4($t3)
/* 160C 803879FC E60A0020 */  swc1       $f10, 0x20($s0)
/* 1610 80387A00 922C0005 */  lbu        $t4, 5($s1)
/* 1614 80387A04 01820019 */  multu      $t4, $v0
/* 1618 80387A08 00006812 */  mflo       $t5
/* 161C 80387A0C 006D7021 */  addu       $t6, $v1, $t5
/* 1620 80387A10 C5D00008 */  lwc1       $f16, 8($t6)
/* 1624 80387A14 E6120060 */  swc1       $f18, 0x60($s0)
/* 1628 80387A18 10000027 */  b          .L80387AB8
/* 162C 80387A1C E6100024 */   swc1      $f16, 0x24($s0)
/* 1630 80387A20 3C0638D1 */  lui        $a2, 0x38d1
/* 1634 80387A24 34C6B717 */  ori        $a2, $a2, 0xb717
/* 1638 80387A28 02002025 */  or         $a0, $s0, $zero
/* 163C 80387A2C 2405001C */  addiu      $a1, $zero, 0x1c
/* 1640 80387A30 0C0CA2E3 */  jal        func_80328B8C
/* 1644 80387A34 24070001 */   addiu     $a3, $zero, 1
/* 1648 80387A38 240F0010 */  addiu      $t7, $zero, 0x10
/* 164C 80387A3C 2402000C */  addiu      $v0, $zero, 0xc
/* 1650 80387A40 31F800FF */  andi       $t8, $t7, 0xff
/* 1654 80387A44 03020019 */  multu      $t8, $v0
/* 1658 80387A48 3C038039 */  lui        $v1, %hi(D_803927D0)
/* 165C 80387A4C 246327D0 */  addiu      $v1, $v1, %lo(D_803927D0)
/* 1660 80387A50 A22F0005 */  sb         $t7, 5($s1)
/* 1664 80387A54 0000C812 */  mflo       $t9
/* 1668 80387A58 00794021 */  addu       $t0, $v1, $t9
/* 166C 80387A5C C5040000 */  lwc1       $f4, ($t0)
/* 1670 80387A60 E604001C */  swc1       $f4, 0x1c($s0)
/* 1674 80387A64 92290005 */  lbu        $t1, 5($s1)
/* 1678 80387A68 01220019 */  multu      $t1, $v0
/* 167C 80387A6C 00005012 */  mflo       $t2
/* 1680 80387A70 006A5821 */  addu       $t3, $v1, $t2
/* 1684 80387A74 C5660004 */  lwc1       $f6, 4($t3)
/* 1688 80387A78 E6060020 */  swc1       $f6, 0x20($s0)
/* 168C 80387A7C 922C0005 */  lbu        $t4, 5($s1)
/* 1690 80387A80 01820019 */  multu      $t4, $v0
/* 1694 80387A84 00006812 */  mflo       $t5
/* 1698 80387A88 006D7021 */  addu       $t6, $v1, $t5
/* 169C 80387A8C C5C80008 */  lwc1       $f8, 8($t6)
/* 16A0 80387A90 10000009 */  b          .L80387AB8
/* 16A4 80387A94 E6080024 */   swc1      $f8, 0x24($s0)
/* 16A8 80387A98 8E040000 */  lw         $a0, ($s0)
/* 16AC 80387A9C 0C0E198A */  jal        func_80386628
/* 16B0 80387AA0 00002825 */   or        $a1, $zero, $zero
/* 16B4 80387AA4 02002025 */  or         $a0, $s0, $zero
/* 16B8 80387AA8 0C0E2B22 */  jal        func_8038AC88
/* 16BC 80387AAC 24050024 */   addiu     $a1, $zero, 0x24
/* 16C0 80387AB0 0C0CA636 */  jal        actor_loopAnimation
/* 16C4 80387AB4 02002025 */   or        $a0, $s0, $zero
.L80387AB8:
/* 16C8 80387AB8 8FBF0024 */  lw         $ra, 0x24($sp)
.L80387ABC:
/* 16CC 80387ABC 8FB0001C */  lw         $s0, 0x1c($sp)
/* 16D0 80387AC0 8FB10020 */  lw         $s1, 0x20($sp)
/* 16D4 80387AC4 03E00008 */  jr         $ra
/* 16D8 80387AC8 27BD0028 */   addiu     $sp, $sp, 0x28
glabel func_80387ACC
/* 16DC 80387ACC 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 16E0 80387AD0 AFBF0014 */  sw         $ra, 0x14($sp)
/* 16E4 80387AD4 AFA5001C */  sw         $a1, 0x1c($sp)
/* 16E8 80387AD8 AFA40018 */  sw         $a0, 0x18($sp)
/* 16EC 80387ADC 0C0CA32A */  jal        func_80328CA8
/* 16F0 80387AE0 00002825 */   or        $a1, $zero, $zero
/* 16F4 80387AE4 8FA40018 */  lw         $a0, 0x18($sp)
/* 16F8 80387AE8 0C0CA3FC */  jal        func_80328FF0
/* 16FC 80387AEC 8FA5001C */   lw        $a1, 0x1c($sp)
/* 1700 80387AF0 8FBF0014 */  lw         $ra, 0x14($sp)
/* 1704 80387AF4 27BD0018 */  addiu      $sp, $sp, 0x18
/* 1708 80387AF8 03E00008 */  jr         $ra
/* 170C 80387AFC 00000000 */   nop
glabel func_80387B00
/* 1710 80387B00 27BDFFC8 */  addiu      $sp, $sp, -0x38
/* 1714 80387B04 AFB00018 */  sw         $s0, 0x18($sp)
/* 1718 80387B08 00808025 */  or         $s0, $a0, $zero
/* 171C 80387B0C AFBF001C */  sw         $ra, 0x1c($sp)
/* 1720 80387B10 3C053F4C */  lui        $a1, 0x3f4c
/* 1724 80387B14 34A5CCCD */  ori        $a1, $a1, 0xcccd
/* 1728 80387B18 0C0E1AD5 */  jal        func_80386B54
/* 172C 80387B1C 27A40028 */   addiu     $a0, $sp, 0x28
/* 1730 80387B20 C7A40028 */  lwc1       $f4, 0x28($sp)
/* 1734 80387B24 44807000 */  mtc1       $zero, $f14
/* 1738 80387B28 C60A0004 */  lwc1       $f10, 4($s0)
/* 173C 80387B2C E604001C */  swc1       $f4, 0x1c($s0)
/* 1740 80387B30 C7A6002C */  lwc1       $f6, 0x2c($sp)
/* 1744 80387B34 C6040008 */  lwc1       $f4, 8($s0)
/* 1748 80387B38 E6060020 */  swc1       $f6, 0x20($s0)
/* 174C 80387B3C C7A80030 */  lwc1       $f8, 0x30($sp)
/* 1750 80387B40 E60E0020 */  swc1       $f14, 0x20($s0)
/* 1754 80387B44 E6080024 */  swc1       $f8, 0x24($s0)
/* 1758 80387B48 C7B00028 */  lwc1       $f16, 0x28($sp)
/* 175C 80387B4C 46105481 */  sub.s      $f18, $f10, $f16
/* 1760 80387B50 C60A000C */  lwc1       $f10, 0xc($s0)
/* 1764 80387B54 E612002C */  swc1       $f18, 0x2c($s0)
/* 1768 80387B58 C7A6002C */  lwc1       $f6, 0x2c($sp)
/* 176C 80387B5C C602002C */  lwc1       $f2, 0x2c($s0)
/* 1770 80387B60 46062201 */  sub.s      $f8, $f4, $f6
/* 1774 80387B64 46021102 */  mul.s      $f4, $f2, $f2
/* 1778 80387B68 E6080030 */  swc1       $f8, 0x30($s0)
/* 177C 80387B6C C7B00030 */  lwc1       $f16, 0x30($sp)
/* 1780 80387B70 460E7182 */  mul.s      $f6, $f14, $f14
/* 1784 80387B74 E60E0030 */  swc1       $f14, 0x30($s0)
/* 1788 80387B78 46105481 */  sub.s      $f18, $f10, $f16
/* 178C 80387B7C E6120034 */  swc1       $f18, 0x34($s0)
/* 1790 80387B80 C6000034 */  lwc1       $f0, 0x34($s0)
/* 1794 80387B84 46062200 */  add.s      $f8, $f4, $f6
/* 1798 80387B88 46000282 */  mul.s      $f10, $f0, $f0
/* 179C 80387B8C 0C0994D4 */  jal        gu_sqrtf
/* 17A0 80387B90 46085300 */   add.s     $f12, $f10, $f8
/* 17A4 80387B94 2602007C */  addiu      $v0, $s0, 0x7c
/* 17A8 80387B98 E4400014 */  swc1       $f0, 0x14($v0)
/* 17AC 80387B9C AFA20024 */  sw         $v0, 0x24($sp)
/* 17B0 80387BA0 0C095914 */  jal        ml_vec3f_normalize
/* 17B4 80387BA4 2604002C */   addiu     $a0, $s0, 0x2c
/* 17B8 80387BA8 C60C002C */  lwc1       $f12, 0x2c($s0)
/* 17BC 80387BAC 0C095C57 */  jal        func_8025715C
/* 17C0 80387BB0 C60E0034 */   lwc1      $f14, 0x34($s0)
/* 17C4 80387BB4 3C014334 */  lui        $at, 0x4334
/* 17C8 80387BB8 44818000 */  mtc1       $at, $f16
/* 17CC 80387BBC 8FA20024 */  lw         $v0, 0x24($sp)
/* 17D0 80387BC0 C6040008 */  lwc1       $f4, 8($s0)
/* 17D4 80387BC4 46100480 */  add.s      $f18, $f0, $f16
/* 17D8 80387BC8 E6120064 */  swc1       $f18, 0x64($s0)
/* 17DC 80387BCC E4440018 */  swc1       $f4, 0x18($v0)
/* 17E0 80387BD0 C7A6002C */  lwc1       $f6, 0x2c($sp)
/* 17E4 80387BD4 C4500014 */  lwc1       $f16, 0x14($v0)
/* 17E8 80387BD8 460032A1 */  cvt.d.s    $f10, $f6
/* 17EC 80387BDC E4500020 */  swc1       $f16, 0x20($v0)
/* 17F0 80387BE0 46205220 */  cvt.s.d    $f8, $f10
/* 17F4 80387BE4 E448001C */  swc1       $f8, 0x1c($v0)
/* 17F8 80387BE8 8FBF001C */  lw         $ra, 0x1c($sp)
/* 17FC 80387BEC 8FB00018 */  lw         $s0, 0x18($sp)
/* 1800 80387BF0 27BD0038 */  addiu      $sp, $sp, 0x38
/* 1804 80387BF4 03E00008 */  jr         $ra
/* 1808 80387BF8 00000000 */   nop
glabel func_80387BFC
/* 180C 80387BFC 27BDFFA0 */  addiu      $sp, $sp, -0x60
/* 1810 80387C00 AFBF001C */  sw         $ra, 0x1c($sp)
/* 1814 80387C04 AFB00018 */  sw         $s0, 0x18($sp)
/* 1818 80387C08 AFA50064 */  sw         $a1, 0x64($sp)
/* 181C 80387C0C C4900090 */  lwc1       $f16, 0x90($a0)
/* 1820 80387C10 C482009C */  lwc1       $f2, 0x9c($a0)
/* 1824 80387C14 00808025 */  or         $s0, $a0, $zero
/* 1828 80387C18 46108382 */  mul.s      $f14, $f16, $f16
/* 182C 80387C1C 46001021 */  cvt.d.s    $f0, $f2
/* 1830 80387C20 46021102 */  mul.s      $f4, $f2, $f2
/* 1834 80387C24 E7A40054 */  swc1       $f4, 0x54($sp)
/* 1838 80387C28 C4880098 */  lwc1       $f8, 0x98($a0)
/* 183C 80387C2C C4860094 */  lwc1       $f6, 0x94($a0)
/* 1840 80387C30 E7AE0058 */  swc1       $f14, 0x58($sp)
/* 1844 80387C34 46083281 */  sub.s      $f10, $f6, $f8
/* 1848 80387C38 46200180 */  add.d      $f6, $f0, $f0
/* 184C 80387C3C E7AA0050 */  swc1       $f10, 0x50($sp)
/* 1850 80387C40 C7A40050 */  lwc1       $f4, 0x50($sp)
/* 1854 80387C44 460024A1 */  cvt.d.s    $f18, $f4
/* 1858 80387C48 46323202 */  mul.d      $f8, $f6, $f18
/* 185C 80387C4C F7B20038 */  sdc1       $f18, 0x38($sp)
/* 1860 80387C50 0C095C57 */  jal        func_8025715C
/* 1864 80387C54 46204320 */   cvt.s.d   $f12, $f8
/* 1868 80387C58 4600028D */  trunc.w.s  $f10, $f0
/* 186C 80387C5C 02002025 */  or         $a0, $s0, $zero
/* 1870 80387C60 44055000 */  mfc1       $a1, $f10
/* 1874 80387C64 0C0CA32A */  jal        func_80328CA8
/* 1878 80387C68 00000000 */   nop
/* 187C 80387C6C 02002025 */  or         $a0, $s0, $zero
/* 1880 80387C70 0C0CA3FC */  jal        func_80328FF0
/* 1884 80387C74 8FA50064 */   lw        $a1, 0x64($sp)
/* 1888 80387C78 2602007C */  addiu      $v0, $s0, 0x7c
/* 188C 80387C7C C4440020 */  lwc1       $f4, 0x20($v0)
/* 1890 80387C80 C602002C */  lwc1       $f2, 0x2c($s0)
/* 1894 80387C84 C608001C */  lwc1       $f8, 0x1c($s0)
/* 1898 80387C88 C7AE0058 */  lwc1       $f14, 0x58($sp)
/* 189C 80387C8C 46041182 */  mul.s      $f6, $f2, $f4
/* 18A0 80387C90 D7B20038 */  ldc1       $f18, 0x38($sp)
/* 18A4 80387C94 C6040030 */  lwc1       $f4, 0x30($s0)
/* 18A8 80387C98 27A40044 */  addiu      $a0, $sp, 0x44
/* 18AC 80387C9C 46083280 */  add.s      $f10, $f6, $f8
/* 18B0 80387CA0 E60A0004 */  swc1       $f10, 4($s0)
/* 18B4 80387CA4 C4460020 */  lwc1       $f6, 0x20($v0)
/* 18B8 80387CA8 C60A0020 */  lwc1       $f10, 0x20($s0)
/* 18BC 80387CAC 46062202 */  mul.s      $f8, $f4, $f6
/* 18C0 80387CB0 C6060034 */  lwc1       $f6, 0x34($s0)
/* 18C4 80387CB4 460A4100 */  add.s      $f4, $f8, $f10
/* 18C8 80387CB8 E6040008 */  swc1       $f4, 8($s0)
/* 18CC 80387CBC C4480020 */  lwc1       $f8, 0x20($v0)
/* 18D0 80387CC0 C6040024 */  lwc1       $f4, 0x24($s0)
/* 18D4 80387CC4 46083282 */  mul.s      $f10, $f6, $f8
/* 18D8 80387CC8 46045180 */  add.s      $f6, $f10, $f4
/* 18DC 80387CCC E606000C */  swc1       $f6, 0xc($s0)
/* 18E0 80387CD0 C7AA0054 */  lwc1       $f10, 0x54($sp)
/* 18E4 80387CD4 C7A80050 */  lwc1       $f8, 0x50($sp)
/* 18E8 80387CD8 460A4102 */  mul.s      $f4, $f8, $f10
/* 18EC 80387CDC C448001C */  lwc1       $f8, 0x1c($v0)
/* 18F0 80387CE0 460E2183 */  div.s      $f6, $f4, $f14
/* 18F4 80387CE4 460E1102 */  mul.s      $f4, $f2, $f14
/* 18F8 80387CE8 46064280 */  add.s      $f10, $f8, $f6
/* 18FC 80387CEC E60A0008 */  swc1       $f10, 8($s0)
/* 1900 80387CF0 E7A40044 */  swc1       $f4, 0x44($sp)
/* 1904 80387CF4 C4480020 */  lwc1       $f8, 0x20($v0)
/* 1908 80387CF8 46004021 */  cvt.d.s    $f0, $f8
/* 190C 80387CFC 46200180 */  add.d      $f6, $f0, $f0
/* 1910 80387D00 46323282 */  mul.d      $f10, $f6, $f18
/* 1914 80387D04 46205120 */  cvt.s.d    $f4, $f10
/* 1918 80387D08 E7A40048 */  swc1       $f4, 0x48($sp)
/* 191C 80387D0C C6080034 */  lwc1       $f8, 0x34($s0)
/* 1920 80387D10 460E4182 */  mul.s      $f6, $f8, $f14
/* 1924 80387D14 0C095914 */  jal        ml_vec3f_normalize
/* 1928 80387D18 E7A6004C */   swc1      $f6, 0x4c($sp)
/* 192C 80387D1C C7AA0044 */  lwc1       $f10, 0x44($sp)
/* 1930 80387D20 C6040028 */  lwc1       $f4, 0x28($s0)
/* 1934 80387D24 C7A60048 */  lwc1       $f6, 0x48($sp)
/* 1938 80387D28 8FBF001C */  lw         $ra, 0x1c($sp)
/* 193C 80387D2C 46045202 */  mul.s      $f8, $f10, $f4
/* 1940 80387D30 E7A80044 */  swc1       $f8, 0x44($sp)
/* 1944 80387D34 C60A0028 */  lwc1       $f10, 0x28($s0)
/* 1948 80387D38 8FB00018 */  lw         $s0, 0x18($sp)
/* 194C 80387D3C 460A3102 */  mul.s      $f4, $f6, $f10
/* 1950 80387D40 E7A40048 */  swc1       $f4, 0x48($sp)
/* 1954 80387D44 03E00008 */  jr         $ra
/* 1958 80387D48 27BD0060 */   addiu     $sp, $sp, 0x60
glabel func_80387D4C
/* 195C 80387D4C 27BDFFD0 */  addiu      $sp, $sp, -0x30
/* 1960 80387D50 AFBF0014 */  sw         $ra, 0x14($sp)
/* 1964 80387D54 C480009C */  lwc1       $f0, 0x9c($a0)
/* 1968 80387D58 C482002C */  lwc1       $f2, 0x2c($a0)
/* 196C 80387D5C C486001C */  lwc1       $f6, 0x1c($a0)
/* 1970 80387D60 C48A0034 */  lwc1       $f10, 0x34($a0)
/* 1974 80387D64 46001102 */  mul.s      $f4, $f2, $f0
/* 1978 80387D68 C4920024 */  lwc1       $f18, 0x24($a0)
/* 197C 80387D6C 3C0142C8 */  lui        $at, 0x42c8
/* 1980 80387D70 46005402 */  mul.s      $f16, $f10, $f0
/* 1984 80387D74 00802825 */  or         $a1, $a0, $zero
/* 1988 80387D78 46062200 */  add.s      $f8, $f4, $f6
/* 198C 80387D7C C4860098 */  lwc1       $f6, 0x98($a0)
/* 1990 80387D80 46128100 */  add.s      $f4, $f16, $f18
/* 1994 80387D84 E4880004 */  swc1       $f8, 4($a0)
/* 1998 80387D88 C48800A8 */  lwc1       $f8, 0xa8($a0)
/* 199C 80387D8C C4920090 */  lwc1       $f18, 0x90($a0)
/* 19A0 80387D90 E484000C */  swc1       $f4, 0xc($a0)
/* 19A4 80387D94 46004282 */  mul.s      $f10, $f8, $f0
/* 19A8 80387D98 44814000 */  mtc1       $at, $f8
/* 19AC 80387D9C 3C01C000 */  lui        $at, 0xc000
/* 19B0 80387DA0 46121102 */  mul.s      $f4, $f2, $f18
/* 19B4 80387DA4 44809000 */  mtc1       $zero, $f18
/* 19B8 80387DA8 44819800 */  mtc1       $at, $f19
/* 19BC 80387DAC 460A3401 */  sub.s      $f16, $f6, $f10
/* 19C0 80387DB0 E4900008 */  swc1       $f16, 8($a0)
/* 19C4 80387DB4 E7A40020 */  swc1       $f4, 0x20($sp)
/* 19C8 80387DB8 C4860098 */  lwc1       $f6, 0x98($a0)
/* 19CC 80387DBC 46064281 */  sub.s      $f10, $f8, $f6
/* 19D0 80387DC0 46005421 */  cvt.d.s    $f16, $f10
/* 19D4 80387DC4 46328102 */  mul.d      $f4, $f16, $f18
/* 19D8 80387DC8 46202220 */  cvt.s.d    $f8, $f4
/* 19DC 80387DCC E7A80024 */  swc1       $f8, 0x24($sp)
/* 19E0 80387DD0 C48A0090 */  lwc1       $f10, 0x90($a0)
/* 19E4 80387DD4 C4860034 */  lwc1       $f6, 0x34($a0)
/* 19E8 80387DD8 AFA50030 */  sw         $a1, 0x30($sp)
/* 19EC 80387DDC 27A40020 */  addiu      $a0, $sp, 0x20
/* 19F0 80387DE0 460A3402 */  mul.s      $f16, $f6, $f10
/* 19F4 80387DE4 0C095914 */  jal        ml_vec3f_normalize
/* 19F8 80387DE8 E7B00028 */   swc1      $f16, 0x28($sp)
/* 19FC 80387DEC 8FA50030 */  lw         $a1, 0x30($sp)
/* 1A00 80387DF0 C7B20020 */  lwc1       $f18, 0x20($sp)
/* 1A04 80387DF4 C7A60024 */  lwc1       $f6, 0x24($sp)
/* 1A08 80387DF8 C4A40028 */  lwc1       $f4, 0x28($a1)
/* 1A0C 80387DFC 8FBF0014 */  lw         $ra, 0x14($sp)
/* 1A10 80387E00 46049202 */  mul.s      $f8, $f18, $f4
/* 1A14 80387E04 E7A80020 */  swc1       $f8, 0x20($sp)
/* 1A18 80387E08 C4AA0028 */  lwc1       $f10, 0x28($a1)
/* 1A1C 80387E0C 460A3402 */  mul.s      $f16, $f6, $f10
/* 1A20 80387E10 E7B00024 */  swc1       $f16, 0x24($sp)
/* 1A24 80387E14 03E00008 */  jr         $ra
/* 1A28 80387E18 27BD0030 */   addiu     $sp, $sp, 0x30
glabel func_80387E1C
/* 1A2C 80387E1C 3C018039 */  lui        $at, %hi(D_80392130)
/* 1A30 80387E20 3C068039 */  lui        $a2, %hi(D_803927D0)
/* 1A34 80387E24 3C078039 */  lui        $a3, %hi(D_803927D0)
/* 1A38 80387E28 C4202130 */  lwc1       $f0, %lo(D_80392130)($at)
/* 1A3C 80387E2C 24E727D0 */  addiu      $a3, $a3, %lo(D_803927D0)
/* 1A40 80387E30 24C627D0 */  addiu      $a2, $a2, %lo(D_803927D0)
/* 1A44 80387E34 00001825 */  or         $v1, $zero, $zero
/* 1A48 80387E38 24090008 */  addiu      $t1, $zero, 8
/* 1A4C 80387E3C 2408000C */  addiu      $t0, $zero, 0xc
.L80387E40:
/* 1A50 80387E40 C48C0004 */  lwc1       $f12, 4($a0)
/* 1A54 80387E44 C4C40000 */  lwc1       $f4, ($a2)
/* 1A58 80387E48 C490000C */  lwc1       $f16, 0xc($a0)
/* 1A5C 80387E4C C4C60008 */  lwc1       $f6, 8($a2)
/* 1A60 80387E50 460C2081 */  sub.s      $f2, $f4, $f12
/* 1A64 80387E54 306E00FF */  andi       $t6, $v1, 0xff
/* 1A68 80387E58 46103381 */  sub.s      $f14, $f6, $f16
/* 1A6C 80387E5C 46021202 */  mul.s      $f8, $f2, $f2
/* 1A70 80387E60 00000000 */  nop
/* 1A74 80387E64 460E7282 */  mul.s      $f10, $f14, $f14
/* 1A78 80387E68 460A4480 */  add.s      $f18, $f8, $f10
/* 1A7C 80387E6C 4600903C */  c.lt.s     $f18, $f0
/* 1A80 80387E70 00000000 */  nop
/* 1A84 80387E74 45000017 */  bc1f       .L80387ED4
/* 1A88 80387E78 00000000 */   nop
/* 1A8C 80387E7C 01C80019 */  multu      $t6, $t0
/* 1A90 80387E80 2482007C */  addiu      $v0, $a0, 0x7c
/* 1A94 80387E84 A0430005 */  sb         $v1, 5($v0)
/* 1A98 80387E88 46009006 */  mov.s      $f0, $f18
/* 1A9C 80387E8C 00007812 */  mflo       $t7
/* 1AA0 80387E90 00EFC021 */  addu       $t8, $a3, $t7
/* 1AA4 80387E94 C7040000 */  lwc1       $f4, ($t8)
/* 1AA8 80387E98 E4A40000 */  swc1       $f4, ($a1)
/* 1AAC 80387E9C 90590005 */  lbu        $t9, 5($v0)
/* 1AB0 80387EA0 03280019 */  multu      $t9, $t0
/* 1AB4 80387EA4 00005012 */  mflo       $t2
/* 1AB8 80387EA8 00EA5821 */  addu       $t3, $a3, $t2
/* 1ABC 80387EAC C5660004 */  lwc1       $f6, 4($t3)
/* 1AC0 80387EB0 E4A60004 */  swc1       $f6, 4($a1)
/* 1AC4 80387EB4 904C0005 */  lbu        $t4, 5($v0)
/* 1AC8 80387EB8 01880019 */  multu      $t4, $t0
/* 1ACC 80387EBC 00006812 */  mflo       $t5
/* 1AD0 80387EC0 00ED7021 */  addu       $t6, $a3, $t5
/* 1AD4 80387EC4 C5C80008 */  lwc1       $f8, 8($t6)
/* 1AD8 80387EC8 E4A80008 */  swc1       $f8, 8($a1)
/* 1ADC 80387ECC C490000C */  lwc1       $f16, 0xc($a0)
/* 1AE0 80387ED0 C48C0004 */  lwc1       $f12, 4($a0)
.L80387ED4:
/* 1AE4 80387ED4 C4CA000C */  lwc1       $f10, 0xc($a2)
/* 1AE8 80387ED8 C4C40014 */  lwc1       $f4, 0x14($a2)
/* 1AEC 80387EDC 246F0001 */  addiu      $t7, $v1, 1
/* 1AF0 80387EE0 460C5081 */  sub.s      $f2, $f10, $f12
/* 1AF4 80387EE4 31F800FF */  andi       $t8, $t7, 0xff
/* 1AF8 80387EE8 46102381 */  sub.s      $f14, $f4, $f16
/* 1AFC 80387EEC 46021182 */  mul.s      $f6, $f2, $f2
/* 1B00 80387EF0 00000000 */  nop
/* 1B04 80387EF4 460E7202 */  mul.s      $f8, $f14, $f14
/* 1B08 80387EF8 46083480 */  add.s      $f18, $f6, $f8
/* 1B0C 80387EFC 4600903C */  c.lt.s     $f18, $f0
/* 1B10 80387F00 00000000 */  nop
/* 1B14 80387F04 45000015 */  bc1f       .L80387F5C
/* 1B18 80387F08 00000000 */   nop
/* 1B1C 80387F0C 03080019 */  multu      $t8, $t0
/* 1B20 80387F10 2482007C */  addiu      $v0, $a0, 0x7c
/* 1B24 80387F14 A04F0005 */  sb         $t7, 5($v0)
/* 1B28 80387F18 46009006 */  mov.s      $f0, $f18
/* 1B2C 80387F1C 0000C812 */  mflo       $t9
/* 1B30 80387F20 00F95021 */  addu       $t2, $a3, $t9
/* 1B34 80387F24 C54A0000 */  lwc1       $f10, ($t2)
/* 1B38 80387F28 E4AA0000 */  swc1       $f10, ($a1)
/* 1B3C 80387F2C 904B0005 */  lbu        $t3, 5($v0)
/* 1B40 80387F30 01680019 */  multu      $t3, $t0
/* 1B44 80387F34 00006012 */  mflo       $t4
/* 1B48 80387F38 00EC6821 */  addu       $t5, $a3, $t4
/* 1B4C 80387F3C C5A40004 */  lwc1       $f4, 4($t5)
/* 1B50 80387F40 E4A40004 */  swc1       $f4, 4($a1)
/* 1B54 80387F44 904E0005 */  lbu        $t6, 5($v0)
/* 1B58 80387F48 01C80019 */  multu      $t6, $t0
/* 1B5C 80387F4C 00007812 */  mflo       $t7
/* 1B60 80387F50 00EFC021 */  addu       $t8, $a3, $t7
/* 1B64 80387F54 C7060008 */  lwc1       $f6, 8($t8)
/* 1B68 80387F58 E4A60008 */  swc1       $f6, 8($a1)
.L80387F5C:
/* 1B6C 80387F5C 24630002 */  addiu      $v1, $v1, 2
/* 1B70 80387F60 1469FFB7 */  bne        $v1, $t1, .L80387E40
/* 1B74 80387F64 24C60018 */   addiu     $a2, $a2, 0x18
/* 1B78 80387F68 03E00008 */  jr         $ra
/* 1B7C 80387F6C 00000000 */   nop
glabel func_80387F70
/* 1B80 80387F70 27BDFFC8 */  addiu      $sp, $sp, -0x38
/* 1B84 80387F74 AFBF0014 */  sw         $ra, 0x14($sp)
/* 1B88 80387F78 AFA40038 */  sw         $a0, 0x38($sp)
/* 1B8C 80387F7C AFA5003C */  sw         $a1, 0x3c($sp)
/* 1B90 80387F80 AFA60040 */  sw         $a2, 0x40($sp)
/* 1B94 80387F84 0C0A3A69 */  jal        player_getPosition
/* 1B98 80387F88 27A4001C */   addiu     $a0, $sp, 0x1c
/* 1B9C 80387F8C 8FA20038 */  lw         $v0, 0x38($sp)
/* 1BA0 80387F90 2405000C */  addiu      $a1, $zero, 0xc
/* 1BA4 80387F94 3C038039 */  lui        $v1, %hi(D_803927D0)
/* 1BA8 80387F98 904E0081 */  lbu        $t6, 0x81($v0)
/* 1BAC 80387F9C 246327D0 */  addiu      $v1, $v1, %lo(D_803927D0)
/* 1BB0 80387FA0 C7A6001C */  lwc1       $f6, 0x1c($sp)
/* 1BB4 80387FA4 01C50019 */  multu      $t6, $a1
/* 1BB8 80387FA8 C7B00020 */  lwc1       $f16, 0x20($sp)
/* 1BBC 80387FAC 2442007C */  addiu      $v0, $v0, 0x7c
/* 1BC0 80387FB0 27A40028 */  addiu      $a0, $sp, 0x28
/* 1BC4 80387FB4 00007812 */  mflo       $t7
/* 1BC8 80387FB8 006FC021 */  addu       $t8, $v1, $t7
/* 1BCC 80387FBC C7040000 */  lwc1       $f4, ($t8)
/* 1BD0 80387FC0 46062201 */  sub.s      $f8, $f4, $f6
/* 1BD4 80387FC4 C7A60024 */  lwc1       $f6, 0x24($sp)
/* 1BD8 80387FC8 E7A80028 */  swc1       $f8, 0x28($sp)
/* 1BDC 80387FCC 90590005 */  lbu        $t9, 5($v0)
/* 1BE0 80387FD0 03250019 */  multu      $t9, $a1
/* 1BE4 80387FD4 00004012 */  mflo       $t0
/* 1BE8 80387FD8 00684821 */  addu       $t1, $v1, $t0
/* 1BEC 80387FDC C52A0004 */  lwc1       $f10, 4($t1)
/* 1BF0 80387FE0 46105481 */  sub.s      $f18, $f10, $f16
/* 1BF4 80387FE4 E7B2002C */  swc1       $f18, 0x2c($sp)
/* 1BF8 80387FE8 904A0005 */  lbu        $t2, 5($v0)
/* 1BFC 80387FEC 01450019 */  multu      $t2, $a1
/* 1C00 80387FF0 00005812 */  mflo       $t3
/* 1C04 80387FF4 006B6021 */  addu       $t4, $v1, $t3
/* 1C08 80387FF8 C5840008 */  lwc1       $f4, 8($t4)
/* 1C0C 80387FFC AFA20018 */  sw         $v0, 0x18($sp)
/* 1C10 80388000 46062201 */  sub.s      $f8, $f4, $f6
/* 1C14 80388004 0C095914 */  jal        ml_vec3f_normalize
/* 1C18 80388008 E7A80030 */   swc1      $f8, 0x30($sp)
/* 1C1C 8038800C 8FA20018 */  lw         $v0, 0x18($sp)
/* 1C20 80388010 2405000C */  addiu      $a1, $zero, 0xc
/* 1C24 80388014 C7A00040 */  lwc1       $f0, 0x40($sp)
/* 1C28 80388018 904D0005 */  lbu        $t5, 5($v0)
/* 1C2C 8038801C C7AA0028 */  lwc1       $f10, 0x28($sp)
/* 1C30 80388020 3C038039 */  lui        $v1, %hi(D_803927D0)
/* 1C34 80388024 01A50019 */  multu      $t5, $a1
/* 1C38 80388028 46005402 */  mul.s      $f16, $f10, $f0
/* 1C3C 8038802C 246327D0 */  addiu      $v1, $v1, %lo(D_803927D0)
/* 1C40 80388030 8FA4003C */  lw         $a0, 0x3c($sp)
/* 1C44 80388034 00007012 */  mflo       $t6
/* 1C48 80388038 006E7821 */  addu       $t7, $v1, $t6
/* 1C4C 8038803C C5F20000 */  lwc1       $f18, ($t7)
/* 1C50 80388040 46128100 */  add.s      $f4, $f16, $f18
/* 1C54 80388044 E4840000 */  swc1       $f4, ($a0)
/* 1C58 80388048 90580005 */  lbu        $t8, 5($v0)
/* 1C5C 8038804C C7A6002C */  lwc1       $f6, 0x2c($sp)
/* 1C60 80388050 03050019 */  multu      $t8, $a1
/* 1C64 80388054 46003202 */  mul.s      $f8, $f6, $f0
/* 1C68 80388058 0000C812 */  mflo       $t9
/* 1C6C 8038805C 00794021 */  addu       $t0, $v1, $t9
/* 1C70 80388060 C50A0004 */  lwc1       $f10, 4($t0)
/* 1C74 80388064 460A4400 */  add.s      $f16, $f8, $f10
/* 1C78 80388068 E4900004 */  swc1       $f16, 4($a0)
/* 1C7C 8038806C 90490005 */  lbu        $t1, 5($v0)
/* 1C80 80388070 C7B20030 */  lwc1       $f18, 0x30($sp)
/* 1C84 80388074 01250019 */  multu      $t1, $a1
/* 1C88 80388078 46009102 */  mul.s      $f4, $f18, $f0
/* 1C8C 8038807C 00005012 */  mflo       $t2
/* 1C90 80388080 006A5821 */  addu       $t3, $v1, $t2
/* 1C94 80388084 C5660008 */  lwc1       $f6, 8($t3)
/* 1C98 80388088 46062200 */  add.s      $f8, $f4, $f6
/* 1C9C 8038808C E4880008 */  swc1       $f8, 8($a0)
/* 1CA0 80388090 8FBF0014 */  lw         $ra, 0x14($sp)
/* 1CA4 80388094 27BD0038 */  addiu      $sp, $sp, 0x38
/* 1CA8 80388098 03E00008 */  jr         $ra
/* 1CAC 8038809C 00000000 */   nop
glabel func_803880A0
/* 1CB0 803880A0 44800000 */  mtc1       $zero, $f0
/* 1CB4 803880A4 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 1CB8 803880A8 44856000 */  mtc1       $a1, $f12
/* 1CBC 803880AC AFBF0014 */  sw         $ra, 0x14($sp)
/* 1CC0 803880B0 00803825 */  or         $a3, $a0, $zero
/* 1CC4 803880B4 2484002C */  addiu      $a0, $a0, 0x2c
/* 1CC8 803880B8 E4800004 */  swc1       $f0, 4($a0)
/* 1CCC 803880BC E4800000 */  swc1       $f0, ($a0)
/* 1CD0 803880C0 E48C0008 */  swc1       $f12, 8($a0)
/* 1CD4 803880C4 8CE60050 */  lw         $a2, 0x50($a3)
/* 1CD8 803880C8 0C095A40 */  jal        ml_vec3f_yaw_rotate_copy
/* 1CDC 803880CC 00802825 */   or        $a1, $a0, $zero
/* 1CE0 803880D0 8FBF0014 */  lw         $ra, 0x14($sp)
/* 1CE4 803880D4 27BD0018 */  addiu      $sp, $sp, 0x18
/* 1CE8 803880D8 03E00008 */  jr         $ra
/* 1CEC 803880DC 00000000 */   nop
glabel func_803880E0
/* 1CF0 803880E0 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 1CF4 803880E4 AFBF0014 */  sw         $ra, 0x14($sp)
/* 1CF8 803880E8 AFA5001C */  sw         $a1, 0x1c($sp)
/* 1CFC 803880EC 0C0CA656 */  jal        marker_getActor
/* 1D00 803880F0 AFA60020 */   sw        $a2, 0x20($sp)
/* 1D04 803880F4 00402025 */  or         $a0, $v0, $zero
/* 1D08 803880F8 0C0E2061 */  jal        func_80388184
/* 1D0C 803880FC 2405000C */   addiu     $a1, $zero, 0xc
/* 1D10 80388100 8FBF0014 */  lw         $ra, 0x14($sp)
/* 1D14 80388104 27BD0018 */  addiu      $sp, $sp, 0x18
/* 1D18 80388108 03E00008 */  jr         $ra
/* 1D1C 8038810C 00000000 */   nop
glabel func_80388110
/* 1D20 80388110 27BDFFD8 */  addiu      $sp, $sp, -0x28
/* 1D24 80388114 AFBF001C */  sw         $ra, 0x1c($sp)
/* 1D28 80388118 AFA5002C */  sw         $a1, 0x2c($sp)
/* 1D2C 8038811C 0C0CA656 */  jal        marker_getActor
/* 1D30 80388120 AFA60030 */   sw        $a2, 0x30($sp)
/* 1D34 80388124 244E007C */  addiu      $t6, $v0, 0x7c
/* 1D38 80388128 AFA20024 */  sw         $v0, 0x24($sp)
/* 1D3C 8038812C 0C0AEB93 */  jal        func_802BAE4C
/* 1D40 80388130 AFAE0020 */   sw        $t6, 0x20($sp)
/* 1D44 80388134 00002025 */  or         $a0, $zero, $zero
/* 1D48 80388138 0C0D29EF */  jal        randi2
/* 1D4C 8038813C 24050005 */   addiu     $a1, $zero, 5
/* 1D50 80388140 8FAF0024 */  lw         $t7, 0x24($sp)
/* 1D54 80388144 3C188039 */  lui        $t8, %hi(func_803880E0)
/* 1D58 80388148 271880E0 */  addiu      $t8, $t8, %lo(func_803880E0)
/* 1D5C 8038814C 8DE70000 */  lw         $a3, ($t7)
/* 1D60 80388150 AFA00014 */  sw         $zero, 0x14($sp)
/* 1D64 80388154 AFB80010 */  sw         $t8, 0x10($sp)
/* 1D68 80388158 24441101 */  addiu      $a0, $v0, 0x1101
/* 1D6C 8038815C 24050004 */  addiu      $a1, $zero, 4
/* 1D70 80388160 0C0C4520 */  jal        func_80311480
/* 1D74 80388164 00003025 */   or        $a2, $zero, $zero
/* 1D78 80388168 8FA80020 */  lw         $t0, 0x20($sp)
/* 1D7C 8038816C 24190001 */  addiu      $t9, $zero, 1
/* 1D80 80388170 A1190009 */  sb         $t9, 9($t0)
/* 1D84 80388174 8FBF001C */  lw         $ra, 0x1c($sp)
/* 1D88 80388178 27BD0028 */  addiu      $sp, $sp, 0x28
/* 1D8C 8038817C 03E00008 */  jr         $ra
/* 1D90 80388180 00000000 */   nop
glabel func_80388184
/* 1D94 80388184 27BDFFB8 */  addiu      $sp, $sp, -0x48
/* 1D98 80388188 AFBF002C */  sw         $ra, 0x2c($sp)
/* 1D9C 8038818C AFB00028 */  sw         $s0, 0x28($sp)
/* 1DA0 80388190 00808025 */  or         $s0, $a0, $zero
/* 1DA4 80388194 0C08F6D7 */  jal        func_8023DB5C
/* 1DA8 80388198 AFA5004C */   sw        $a1, 0x4c($sp)
/* 1DAC 8038819C AFA20040 */  sw         $v0, 0x40($sp)
/* 1DB0 803881A0 0C0A1DF6 */  jal        animctrl_getAnimTimer
/* 1DB4 803881A4 8E040014 */   lw        $a0, 0x14($s0)
/* 1DB8 803881A8 E7A0003C */  swc1       $f0, 0x3c($sp)
/* 1DBC 803881AC 2603007C */  addiu      $v1, $s0, 0x7c
/* 1DC0 803881B0 240E0001 */  addiu      $t6, $zero, 1
/* 1DC4 803881B4 A06E0000 */  sb         $t6, ($v1)
/* 1DC8 803881B8 3C0638D1 */  lui        $a2, 0x38d1
/* 1DCC 803881BC 34C6B717 */  ori        $a2, $a2, 0xb717
/* 1DD0 803881C0 AFA30030 */  sw         $v1, 0x30($sp)
/* 1DD4 803881C4 8FA5004C */  lw         $a1, 0x4c($sp)
/* 1DD8 803881C8 02002025 */  or         $a0, $s0, $zero
/* 1DDC 803881CC 0C0CA2E3 */  jal        func_80328B8C
/* 1DE0 803881D0 24070001 */   addiu     $a3, $zero, 1
/* 1DE4 803881D4 0C0CA636 */  jal        actor_loopAnimation
/* 1DE8 803881D8 02002025 */   or        $a0, $s0, $zero
/* 1DEC 803881DC 8E040000 */  lw         $a0, ($s0)
/* 1DF0 803881E0 0C0E1980 */  jal        func_80386600
/* 1DF4 803881E4 00002825 */   or        $a1, $zero, $zero
/* 1DF8 803881E8 8FAF004C */  lw         $t7, 0x4c($sp)
/* 1DFC 803881EC 24010009 */  addiu      $at, $zero, 9
/* 1E00 803881F0 8FA30030 */  lw         $v1, 0x30($sp)
/* 1E04 803881F4 51E1000E */  beql       $t7, $at, .L80388230
/* 1E08 803881F8 8FB8004C */   lw        $t8, 0x4c($sp)
/* 1E0C 803881FC 92040044 */  lbu        $a0, 0x44($s0)
/* 1E10 80388200 0C0C38FF */  jal        func_8030E3FC
/* 1E14 80388204 AFA30030 */   sw        $v1, 0x30($sp)
/* 1E18 80388208 10400008 */  beqz       $v0, .L8038822C
/* 1E1C 8038820C 8FA30030 */   lw        $v1, 0x30($sp)
/* 1E20 80388210 92040044 */  lbu        $a0, 0x44($s0)
/* 1E24 80388214 0C0C38E5 */  jal        func_8030E394
/* 1E28 80388218 AFA30030 */   sw        $v1, 0x30($sp)
/* 1E2C 8038821C 3C047FFF */  lui        $a0, 0x7fff
/* 1E30 80388220 0C0C3989 */  jal        func_8030E624
/* 1E34 80388224 34844162 */   ori       $a0, $a0, 0x4162
/* 1E38 80388228 8FA30030 */  lw         $v1, 0x30($sp)
.L8038822C:
/* 1E3C 8038822C 8FB8004C */  lw         $t8, 0x4c($sp)
.L80388230:
/* 1E40 80388230 2719FFFE */  addiu      $t9, $t8, -2
/* 1E44 80388234 2F21000C */  sltiu      $at, $t9, 0xc
/* 1E48 80388238 102000C7 */  beqz       $at, .L80388558
/* 1E4C 8038823C 0019C880 */   sll       $t9, $t9, 2
/* 1E50 80388240 3C018039 */  lui        $at, %hi(D_80392134)
/* 1E54 80388244 00390821 */  addu       $at, $at, $t9
/* 1E58 80388248 8C392134 */  lw         $t9, %lo(D_80392134)($at)
/* 1E5C 8038824C 03200008 */  jr         $t9
/* 1E60 80388250 00000000 */   nop
/* 1E64 80388254 02002025 */  or         $a0, $s0, $zero
/* 1E68 80388258 0C0E1F87 */  jal        func_80387E1C
/* 1E6C 8038825C 2605001C */   addiu     $a1, $s0, 0x1c
/* 1E70 80388260 100000BE */  b          .L8038855C
/* 1E74 80388264 8FBF002C */   lw        $ra, 0x2c($sp)
/* 1E78 80388268 8FA80040 */  lw         $t0, 0x40($sp)
/* 1E7C 8038826C 3C018039 */  lui        $at, 0x8039
/* 1E80 80388270 31090001 */  andi       $t1, $t0, 1
/* 1E84 80388274 15200013 */  bnez       $t1, .L803882C4
/* 1E88 80388278 00000000 */   nop
/* 1E8C 8038827C 3C018039 */  lui        $at, %hi(D_80392164)
/* 1E90 80388280 C42C2164 */  lwc1       $f12, %lo(D_80392164)($at)
/* 1E94 80388284 3C018039 */  lui        $at, %hi(D_80392168)
/* 1E98 80388288 0C0D29D5 */  jal        randf2
/* 1E9C 8038828C C42E2168 */   lwc1      $f14, %lo(D_80392168)($at)
/* 1EA0 80388290 3C018039 */  lui        $at, %hi(D_8039216C)
/* 1EA4 80388294 C424216C */  lwc1       $f4, %lo(D_8039216C)($at)
/* 1EA8 80388298 3C018039 */  lui        $at, %hi(D_80392170)
/* 1EAC 8038829C C4262170 */  lwc1       $f6, %lo(D_80392170)($at)
/* 1EB0 803882A0 44050000 */  mfc1       $a1, $f0
/* 1EB4 803882A4 24040142 */  addiu      $a0, $zero, 0x142
/* 1EB8 803882A8 24067D00 */  addiu      $a2, $zero, 0x7d00
/* 1EBC 803882AC 26070004 */  addiu      $a3, $s0, 4
/* 1EC0 803882B0 E7A40010 */  swc1       $f4, 0x10($sp)
/* 1EC4 803882B4 0C0C3A1E */  jal        func_8030E878
/* 1EC8 803882B8 E7A60014 */   swc1      $f6, 0x14($sp)
/* 1ECC 803882BC 10000011 */  b          .L80388304
/* 1ED0 803882C0 44800000 */   mtc1      $zero, $f0
.L803882C4:
/* 1ED4 803882C4 C42C2174 */  lwc1       $f12, 0x2174($at)
/* 1ED8 803882C8 3C018039 */  lui        $at, %hi(D_80392178)
/* 1EDC 803882CC 0C0D29D5 */  jal        randf2
/* 1EE0 803882D0 C42E2178 */   lwc1      $f14, %lo(D_80392178)($at)
/* 1EE4 803882D4 3C018039 */  lui        $at, %hi(D_8039217C)
/* 1EE8 803882D8 C428217C */  lwc1       $f8, %lo(D_8039217C)($at)
/* 1EEC 803882DC 3C018039 */  lui        $at, %hi(D_80392180)
/* 1EF0 803882E0 C42A2180 */  lwc1       $f10, %lo(D_80392180)($at)
/* 1EF4 803882E4 44050000 */  mfc1       $a1, $f0
/* 1EF8 803882E8 2404014B */  addiu      $a0, $zero, 0x14b
/* 1EFC 803882EC 24067D00 */  addiu      $a2, $zero, 0x7d00
/* 1F00 803882F0 26070004 */  addiu      $a3, $s0, 4
/* 1F04 803882F4 E7A80010 */  swc1       $f8, 0x10($sp)
/* 1F08 803882F8 0C0C3A1E */  jal        func_8030E878
/* 1F0C 803882FC E7AA0014 */   swc1      $f10, 0x14($sp)
/* 1F10 80388300 44800000 */  mtc1       $zero, $f0
.L80388304:
/* 1F14 80388304 00000000 */  nop
/* 1F18 80388308 E6000028 */  swc1       $f0, 0x28($s0)
/* 1F1C 8038830C 10000092 */  b          .L80388558
/* 1F20 80388310 E6000060 */   swc1      $f0, 0x60($s0)
/* 1F24 80388314 8E040000 */  lw         $a0, ($s0)
/* 1F28 80388318 AFA30030 */  sw         $v1, 0x30($sp)
/* 1F2C 8038831C 0C0E1980 */  jal        func_80386600
/* 1F30 80388320 24050001 */   addiu     $a1, $zero, 1
/* 1F34 80388324 3C018039 */  lui        $at, %hi(D_80392184)
/* 1F38 80388328 C42C2184 */  lwc1       $f12, %lo(D_80392184)($at)
/* 1F3C 8038832C 3C018039 */  lui        $at, %hi(D_80392188)
/* 1F40 80388330 C4302188 */  lwc1       $f16, %lo(D_80392188)($at)
/* 1F44 80388334 3C018039 */  lui        $at, %hi(D_8039218C)
/* 1F48 80388338 C432218C */  lwc1       $f18, %lo(D_8039218C)($at)
/* 1F4C 8038833C 3C063F59 */  lui        $a2, 0x3f59
/* 1F50 80388340 260A0004 */  addiu      $t2, $s0, 4
/* 1F54 80388344 AFAA0010 */  sw         $t2, 0x10($sp)
/* 1F58 80388348 34C6999A */  ori        $a2, $a2, 0x999a
/* 1F5C 8038834C 240500C1 */  addiu      $a1, $zero, 0xc1
/* 1F60 80388350 24077D00 */  addiu      $a3, $zero, 0x7d00
/* 1F64 80388354 E7B00014 */  swc1       $f16, 0x14($sp)
/* 1F68 80388358 0C0C9355 */  jal        func_80324D54
/* 1F6C 8038835C E7B20018 */   swc1      $f18, 0x18($sp)
/* 1F70 80388360 44800000 */  mtc1       $zero, $f0
/* 1F74 80388364 02002025 */  or         $a0, $s0, $zero
/* 1F78 80388368 0C0E1EC0 */  jal        func_80387B00
/* 1F7C 8038836C E6000028 */   swc1      $f0, 0x28($s0)
/* 1F80 80388370 8FA30030 */  lw         $v1, 0x30($sp)
/* 1F84 80388374 10000078 */  b          .L80388558
/* 1F88 80388378 A060000A */   sb        $zero, 0xa($v1)
/* 1F8C 8038837C 3C0144FA */  lui        $at, 0x44fa
/* 1F90 80388380 44811000 */  mtc1       $at, $f2
/* 1F94 80388384 C4600014 */  lwc1       $f0, 0x14($v1)
/* 1F98 80388388 3C018039 */  lui        $at, 0x8039
/* 1F9C 8038838C 4600103C */  c.lt.s     $f2, $f0
/* 1FA0 80388390 00000000 */  nop
/* 1FA4 80388394 45020004 */  bc1fl      .L803883A8
/* 1FA8 80388398 E4620014 */   swc1      $f2, 0x14($v1)
/* 1FAC 8038839C 10000002 */  b          .L803883A8
/* 1FB0 803883A0 E4600014 */   swc1      $f0, 0x14($v1)
/* 1FB4 803883A4 E4620014 */  swc1       $f2, 0x14($v1)
.L803883A8:
/* 1FB8 803883A8 C4222190 */  lwc1       $f2, 0x2190($at)
/* 1FBC 803883AC C4600014 */  lwc1       $f0, 0x14($v1)
/* 1FC0 803883B0 3C0143C8 */  lui        $at, 0x43c8
/* 1FC4 803883B4 44812000 */  mtc1       $at, $f4
/* 1FC8 803883B8 4602003C */  c.lt.s     $f0, $f2
/* 1FCC 803883BC 00000000 */  nop
/* 1FD0 803883C0 45020004 */  bc1fl      .L803883D4
/* 1FD4 803883C4 E4620014 */   swc1      $f2, 0x14($v1)
/* 1FD8 803883C8 10000002 */  b          .L803883D4
/* 1FDC 803883CC E4600014 */   swc1      $f0, 0x14($v1)
/* 1FE0 803883D0 E4620014 */  swc1       $f2, 0x14($v1)
.L803883D4:
/* 1FE4 803883D4 E4640018 */  swc1       $f4, 0x18($v1)
/* 1FE8 803883D8 C6020028 */  lwc1       $f2, 0x28($s0)
/* 1FEC 803883DC C4660014 */  lwc1       $f6, 0x14($v1)
/* 1FF0 803883E0 24050001 */  addiu      $a1, $zero, 1
/* 1FF4 803883E4 46001207 */  neg.s      $f8, $f2
/* 1FF8 803883E8 46003021 */  cvt.d.s    $f0, $f6
/* 1FFC 803883EC 46024282 */  mul.s      $f10, $f8, $f2
/* 2000 803883F0 46200480 */  add.d      $f18, $f0, $f0
/* 2004 803883F4 46005421 */  cvt.d.s    $f16, $f10
/* 2008 803883F8 46328103 */  div.d      $f4, $f16, $f18
/* 200C 803883FC 462021A0 */  cvt.s.d    $f6, $f4
/* 2010 80388400 E4660028 */  swc1       $f6, 0x28($v1)
/* 2014 80388404 0C0E1980 */  jal        func_80386600
/* 2018 80388408 8E040000 */   lw        $a0, ($s0)
/* 201C 8038840C 8E040014 */  lw         $a0, 0x14($s0)
/* 2020 80388410 0C0A1D93 */  jal        animctrl_setAnimTimer
/* 2024 80388414 8FA5003C */   lw        $a1, 0x3c($sp)
/* 2028 80388418 10000050 */  b          .L8038855C
/* 202C 8038841C 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2030 80388420 C6020028 */  lwc1       $f2, 0x28($s0)
/* 2034 80388424 3C018039 */  lui        $at, %hi(D_80392194)
/* 2038 80388428 C42C2194 */  lwc1       $f12, %lo(D_80392194)($at)
/* 203C 8038842C 46001207 */  neg.s      $f8, $f2
/* 2040 80388430 3C0142C8 */  lui        $at, 0x42c8
/* 2044 80388434 46024282 */  mul.s      $f10, $f8, $f2
/* 2048 80388438 46006021 */  cvt.d.s    $f0, $f12
/* 204C 8038843C 44814000 */  mtc1       $at, $f8
/* 2050 80388440 46200480 */  add.d      $f18, $f0, $f0
/* 2054 80388444 46005421 */  cvt.d.s    $f16, $f10
/* 2058 80388448 C46A001C */  lwc1       $f10, 0x1c($v1)
/* 205C 8038844C 46328103 */  div.d      $f4, $f16, $f18
/* 2060 80388450 460A4401 */  sub.s      $f16, $f8, $f10
/* 2064 80388454 460C8483 */  div.s      $f18, $f16, $f12
/* 2068 80388458 462021A0 */  cvt.s.d    $f6, $f4
/* 206C 8038845C E4660028 */  swc1       $f6, 0x28($v1)
/* 2070 80388460 1000003D */  b          .L80388558
/* 2074 80388464 E472002C */   swc1      $f18, 0x2c($v1)
/* 2078 80388468 0C0CA62B */  jal        actor_playAnimationOnce
/* 207C 8038846C 02002025 */   or        $a0, $s0, $zero
/* 2080 80388470 8E040014 */  lw         $a0, 0x14($s0)
/* 2084 80388474 0C0A1D93 */  jal        animctrl_setAnimTimer
/* 2088 80388478 8FA5003C */   lw        $a1, 0x3c($sp)
/* 208C 8038847C 10000037 */  b          .L8038855C
/* 2090 80388480 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2094 80388484 3C018039 */  lui        $at, %hi(D_80392198)
/* 2098 80388488 C42C2198 */  lwc1       $f12, %lo(D_80392198)($at)
/* 209C 8038848C 3C018039 */  lui        $at, %hi(D_8039219C)
/* 20A0 80388490 0C0D29D5 */  jal        randf2
/* 20A4 80388494 C42E219C */   lwc1      $f14, %lo(D_8039219C)($at)
/* 20A8 80388498 3C018039 */  lui        $at, %hi(D_803921A0)
/* 20AC 8038849C C42421A0 */  lwc1       $f4, %lo(D_803921A0)($at)
/* 20B0 803884A0 3C018039 */  lui        $at, %hi(D_803921A4)
/* 20B4 803884A4 C42621A4 */  lwc1       $f6, %lo(D_803921A4)($at)
/* 20B8 803884A8 44050000 */  mfc1       $a1, $f0
/* 20BC 803884AC 240400EA */  addiu      $a0, $zero, 0xea
/* 20C0 803884B0 24067D00 */  addiu      $a2, $zero, 0x7d00
/* 20C4 803884B4 26070004 */  addiu      $a3, $s0, 4
/* 20C8 803884B8 E7A40010 */  swc1       $f4, 0x10($sp)
/* 20CC 803884BC 0C0C3A1E */  jal        func_8030E878
/* 20D0 803884C0 E7A60014 */   swc1      $f6, 0x14($sp)
/* 20D4 803884C4 10000025 */  b          .L8038855C
/* 20D8 803884C8 8FBF002C */   lw        $ra, 0x2c($sp)
/* 20DC 803884CC 24040092 */  addiu      $a0, $zero, 0x92
/* 20E0 803884D0 0C0969BB */  jal        func_8025A6EC
/* 20E4 803884D4 24057530 */   addiu     $a1, $zero, 0x7530
/* 20E8 803884D8 10000020 */  b          .L8038855C
/* 20EC 803884DC 8FBF002C */   lw        $ra, 0x2c($sp)
/* 20F0 803884E0 3C018039 */  lui        $at, %hi(D_803921A8)
/* 20F4 803884E4 C42C21A8 */  lwc1       $f12, %lo(D_803921A8)($at)
/* 20F8 803884E8 3C018039 */  lui        $at, %hi(D_803921AC)
/* 20FC 803884EC C42E21AC */  lwc1       $f14, %lo(D_803921AC)($at)
/* 2100 803884F0 0C0D29D5 */  jal        randf2
/* 2104 803884F4 AFA30030 */   sw        $v1, 0x30($sp)
/* 2108 803884F8 3C018039 */  lui        $at, %hi(D_803921B0)
/* 210C 803884FC C42821B0 */  lwc1       $f8, %lo(D_803921B0)($at)
/* 2110 80388500 3C018039 */  lui        $at, %hi(D_803921B4)
/* 2114 80388504 C42A21B4 */  lwc1       $f10, %lo(D_803921B4)($at)
/* 2118 80388508 44050000 */  mfc1       $a1, $f0
/* 211C 8038850C 24040131 */  addiu      $a0, $zero, 0x131
/* 2120 80388510 24067D00 */  addiu      $a2, $zero, 0x7d00
/* 2124 80388514 26070004 */  addiu      $a3, $s0, 4
/* 2128 80388518 E7A80010 */  swc1       $f8, 0x10($sp)
/* 212C 8038851C 0C0C3A1E */  jal        func_8030E878
/* 2130 80388520 E7AA0014 */   swc1      $f10, 0x14($sp)
/* 2134 80388524 8FA30030 */  lw         $v1, 0x30($sp)
/* 2138 80388528 3C048038 */  lui        $a0, %hi(func_80386DE4)
/* 213C 8038852C 24846DE4 */  addiu      $a0, $a0, %lo(func_80386DE4)
/* 2140 80388530 906B0001 */  lbu        $t3, 1($v1)
/* 2144 80388534 29610004 */  slti       $at, $t3, 4
/* 2148 80388538 54200008 */  bnel       $at, $zero, .L8038855C
/* 214C 8038853C 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2150 80388540 0C0B0F22 */  jal        func_802C3C88
/* 2154 80388544 8E050000 */   lw        $a1, ($s0)
/* 2158 80388548 8E040000 */  lw         $a0, ($s0)
/* 215C 8038854C 00002825 */  or         $a1, $zero, $zero
/* 2160 80388550 0C0E2044 */  jal        func_80388110
/* 2164 80388554 00003025 */   or        $a2, $zero, $zero
.L80388558:
/* 2168 80388558 8FBF002C */  lw         $ra, 0x2c($sp)
.L8038855C:
/* 216C 8038855C 8FB00028 */  lw         $s0, 0x28($sp)
/* 2170 80388560 27BD0048 */  addiu      $sp, $sp, 0x48
/* 2174 80388564 03E00008 */  jr         $ra
/* 2178 80388568 00000000 */   nop
glabel func_8038856C
/* 217C 8038856C 27BDFFD8 */  addiu      $sp, $sp, -0x28
/* 2180 80388570 AFBF0014 */  sw         $ra, 0x14($sp)
/* 2184 80388574 AFA5002C */  sw         $a1, 0x2c($sp)
/* 2188 80388578 8C820000 */  lw         $v0, ($a0)
/* 218C 8038857C 24050007 */  addiu      $a1, $zero, 7
/* 2190 80388580 27A6001C */  addiu      $a2, $sp, 0x1c
/* 2194 80388584 8C4E0014 */  lw         $t6, 0x14($v0)
/* 2198 80388588 000EC280 */  sll        $t8, $t6, 0xa
/* 219C 8038858C 07030006 */  bgezl      $t8, .L803885A8
/* 21A0 80388590 C4840004 */   lwc1      $f4, 4($a0)
/* 21A4 80388594 0C0D285D */  jal        func_8034A174
/* 21A8 80388598 8C440044 */   lw        $a0, 0x44($v0)
/* 21AC 8038859C 10000008 */  b          .L803885C0
/* 21B0 803885A0 27A4001C */   addiu     $a0, $sp, 0x1c
/* 21B4 803885A4 C4840004 */  lwc1       $f4, 4($a0)
.L803885A8:
/* 21B8 803885A8 E7A4001C */  swc1       $f4, 0x1c($sp)
/* 21BC 803885AC C4860008 */  lwc1       $f6, 8($a0)
/* 21C0 803885B0 E7A60020 */  swc1       $f6, 0x20($sp)
/* 21C4 803885B4 C488000C */  lwc1       $f8, 0xc($a0)
/* 21C8 803885B8 E7A80024 */  swc1       $f8, 0x24($sp)
/* 21CC 803885BC 27A4001C */  addiu      $a0, $sp, 0x1c
.L803885C0:
/* 21D0 803885C0 24050002 */  addiu      $a1, $zero, 2
/* 21D4 803885C4 0C0E19E7 */  jal        func_8038679C
/* 21D8 803885C8 8FA6002C */   lw        $a2, 0x2c($sp)
/* 21DC 803885CC 8FBF0014 */  lw         $ra, 0x14($sp)
/* 21E0 803885D0 27BD0028 */  addiu      $sp, $sp, 0x28
/* 21E4 803885D4 03E00008 */  jr         $ra
/* 21E8 803885D8 00000000 */   nop
glabel func_803885DC
/* 21EC 803885DC 27BDFFD8 */  addiu      $sp, $sp, -0x28
/* 21F0 803885E0 AFBF001C */  sw         $ra, 0x1c($sp)
/* 21F4 803885E4 AFB00018 */  sw         $s0, 0x18($sp)
/* 21F8 803885E8 0C08F6D7 */  jal        func_8023DB5C
/* 21FC 803885EC 00808025 */   or        $s0, $a0, $zero
/* 2200 803885F0 AFA20024 */  sw         $v0, 0x24($sp)
/* 2204 803885F4 0C0C38FF */  jal        func_8030E3FC
/* 2208 803885F8 92040044 */   lbu       $a0, 0x44($s0)
/* 220C 803885FC 54400004 */  bnel       $v0, $zero, .L80388610
/* 2210 80388600 8FAE0024 */   lw        $t6, 0x24($sp)
/* 2214 80388604 0C0C38B1 */  jal        func_8030E2C4
/* 2218 80388608 92040044 */   lbu       $a0, 0x44($s0)
/* 221C 8038860C 8FAE0024 */  lw         $t6, 0x24($sp)
.L80388610:
/* 2220 80388610 31CF0007 */  andi       $t7, $t6, 7
/* 2224 80388614 55E0000F */  bnel       $t7, $zero, .L80388654
/* 2228 80388618 3C053E99 */   lui       $a1, 0x3e99
/* 222C 8038861C 0C0D28E4 */  jal        randf
/* 2230 80388620 00000000 */   nop
/* 2234 80388624 3C013FE0 */  lui        $at, 0x3fe0
/* 2238 80388628 44813800 */  mtc1       $at, $f7
/* 223C 8038862C 44803000 */  mtc1       $zero, $f6
/* 2240 80388630 46000121 */  cvt.d.s    $f4, $f0
/* 2244 80388634 02002025 */  or         $a0, $s0, $zero
/* 2248 80388638 4626203C */  c.lt.d     $f4, $f6
/* 224C 8038863C 3C058039 */  lui        $a1, 0x8039
/* 2250 80388640 45020004 */  bc1fl      .L80388654
/* 2254 80388644 3C053E99 */   lui       $a1, 0x3e99
/* 2258 80388648 0C0E215B */  jal        func_8038856C
/* 225C 8038864C 24A51728 */   addiu     $a1, $a1, 0x1728
/* 2260 80388650 3C053E99 */  lui        $a1, 0x3e99
.L80388654:
/* 2264 80388654 34A5999A */  ori        $a1, $a1, 0x999a
/* 2268 80388658 0C0CA21B */  jal        actor_animationIsAt
/* 226C 8038865C 02002025 */   or        $a0, $s0, $zero
/* 2270 80388660 14400005 */  bnez       $v0, .L80388678
/* 2274 80388664 02002025 */   or        $a0, $s0, $zero
/* 2278 80388668 3C053F47 */  lui        $a1, 0x3f47
/* 227C 8038866C 0C0CA21B */  jal        actor_animationIsAt
/* 2280 80388670 34A5AE14 */   ori       $a1, $a1, 0xae14
/* 2284 80388674 1040000D */  beqz       $v0, .L803886AC
.L80388678:
/* 2288 80388678 3C047FF8 */   lui       $a0, 0x7ff8
/* 228C 8038867C 26050004 */  addiu      $a1, $s0, 4
/* 2290 80388680 3C062710 */  lui        $a2, 0x2710
/* 2294 80388684 34C607D0 */  ori        $a2, $a2, 0x7d0
/* 2298 80388688 AFA50020 */  sw         $a1, 0x20($sp)
/* 229C 8038868C 0C0C3A2D */  jal        func_8030E8B4
/* 22A0 80388690 3484681E */   ori       $a0, $a0, 0x681e
/* 22A4 80388694 3C047FF8 */  lui        $a0, 0x7ff8
/* 22A8 80388698 3C062710 */  lui        $a2, 0x2710
/* 22AC 8038869C 8FA50020 */  lw         $a1, 0x20($sp)
/* 22B0 803886A0 34C607D0 */  ori        $a2, $a2, 0x7d0
/* 22B4 803886A4 0C0C3A2D */  jal        func_8030E8B4
/* 22B8 803886A8 3484688E */   ori       $a0, $a0, 0x688e
.L803886AC:
/* 22BC 803886AC 3C053ECC */  lui        $a1, 0x3ecc
/* 22C0 803886B0 34A5CCCD */  ori        $a1, $a1, 0xcccd
/* 22C4 803886B4 0C0CA21B */  jal        actor_animationIsAt
/* 22C8 803886B8 02002025 */   or        $a0, $s0, $zero
/* 22CC 803886BC 14400005 */  bnez       $v0, .L803886D4
/* 22D0 803886C0 02002025 */   or        $a0, $s0, $zero
/* 22D4 803886C4 3C053F61 */  lui        $a1, 0x3f61
/* 22D8 803886C8 0C0CA21B */  jal        actor_animationIsAt
/* 22DC 803886CC 34A547AE */   ori       $a1, $a1, 0x47ae
/* 22E0 803886D0 1040000D */  beqz       $v0, .L80388708
.L803886D4:
/* 22E4 803886D4 3C047FF8 */   lui       $a0, 0x7ff8
/* 22E8 803886D8 26050004 */  addiu      $a1, $s0, 4
/* 22EC 803886DC 3C062710 */  lui        $a2, 0x2710
/* 22F0 803886E0 34C607D0 */  ori        $a2, $a2, 0x7d0
/* 22F4 803886E4 AFA50020 */  sw         $a1, 0x20($sp)
/* 22F8 803886E8 0C0C3A2D */  jal        func_8030E8B4
/* 22FC 803886EC 3484681E */   ori       $a0, $a0, 0x681e
/* 2300 803886F0 3C047318 */  lui        $a0, 0x7318
/* 2304 803886F4 3C062710 */  lui        $a2, 0x2710
/* 2308 803886F8 8FA50020 */  lw         $a1, 0x20($sp)
/* 230C 803886FC 34C607D0 */  ori        $a2, $a2, 0x7d0
/* 2310 80388700 0C0C3A2D */  jal        func_8030E8B4
/* 2314 80388704 3484688E */   ori       $a0, $a0, 0x688e
.L80388708:
/* 2318 80388708 8FBF001C */  lw         $ra, 0x1c($sp)
/* 231C 8038870C 8FB00018 */  lw         $s0, 0x18($sp)
/* 2320 80388710 27BD0028 */  addiu      $sp, $sp, 0x28
/* 2324 80388714 03E00008 */  jr         $ra
/* 2328 80388718 00000000 */   nop
glabel func_8038871C
/* 232C 8038871C 44867000 */  mtc1       $a2, $f14
/* 2330 80388720 C4840008 */  lwc1       $f4, 8($a0)
/* 2334 80388724 44856000 */  mtc1       $a1, $f12
/* 2338 80388728 00001025 */  or         $v0, $zero, $zero
/* 233C 8038872C 460E2000 */  add.s      $f0, $f4, $f14
/* 2340 80388730 4600603C */  c.lt.s     $f12, $f0
/* 2344 80388734 00000000 */  nop
/* 2348 80388738 45020005 */  bc1fl      .L80388750
/* 234C 8038873C E4800008 */   swc1      $f0, 8($a0)
/* 2350 80388740 E48C0008 */  swc1       $f12, 8($a0)
/* 2354 80388744 03E00008 */  jr         $ra
/* 2358 80388748 24020001 */   addiu     $v0, $zero, 1
/* 235C 8038874C E4800008 */  swc1       $f0, 8($a0)
.L80388750:
/* 2360 80388750 03E00008 */  jr         $ra
/* 2364 80388754 00000000 */   nop
glabel func_80388758
/* 2368 80388758 27BDFFA0 */  addiu      $sp, $sp, -0x60
/* 236C 8038875C AFBF002C */  sw         $ra, 0x2c($sp)
/* 2370 80388760 0C0CA656 */  jal        marker_getActor
/* 2374 80388764 AFB00028 */   sw        $s0, 0x28($sp)
/* 2378 80388768 2443007C */  addiu      $v1, $v0, 0x7c
/* 237C 8038876C 00408025 */  or         $s0, $v0, $zero
/* 2380 80388770 0C0CF767 */  jal        time_getDelta
/* 2384 80388774 AFA30058 */   sw        $v1, 0x58($sp)
/* 2388 80388778 E7A00054 */  swc1       $f0, 0x54($sp)
/* 238C 8038877C 8E0E0010 */  lw         $t6, 0x10($s0)
/* 2390 80388780 8FA30058 */  lw         $v1, 0x58($sp)
/* 2394 80388784 000E7E82 */  srl        $t7, $t6, 0x1a
/* 2398 80388788 25F8FFFE */  addiu      $t8, $t7, -2
/* 239C 8038878C 2F01000C */  sltiu      $at, $t8, 0xc
/* 23A0 80388790 1020028F */  beqz       $at, .L803891D0
/* 23A4 80388794 0018C080 */   sll       $t8, $t8, 2
/* 23A8 80388798 3C018039 */  lui        $at, %hi(D_803921B8)
/* 23AC 8038879C 00380821 */  addu       $at, $at, $t8
/* 23B0 803887A0 8C3821B8 */  lw         $t8, %lo(D_803921B8)($at)
/* 23B4 803887A4 03000008 */  jr         $t8
/* 23B8 803887A8 00000000 */   nop
/* 23BC 803887AC 8E040000 */  lw         $a0, ($s0)
/* 23C0 803887B0 AFA30058 */  sw         $v1, 0x58($sp)
/* 23C4 803887B4 0C0E1980 */  jal        func_80386600
/* 23C8 803887B8 00002825 */   or        $a1, $zero, $zero
/* 23CC 803887BC 0C0E1A6F */  jal        func_803869BC
/* 23D0 803887C0 02002025 */   or        $a0, $s0, $zero
/* 23D4 803887C4 3C014270 */  lui        $at, 0x4270
/* 23D8 803887C8 44812000 */  mtc1       $at, $f4
/* 23DC 803887CC C7A60054 */  lwc1       $f6, 0x54($sp)
/* 23E0 803887D0 02002025 */  or         $a0, $s0, $zero
/* 23E4 803887D4 46062202 */  mul.s      $f8, $f4, $f6
/* 23E8 803887D8 44054000 */  mfc1       $a1, $f8
/* 23EC 803887DC 0C0E1EB3 */  jal        func_80387ACC
/* 23F0 803887E0 00000000 */   nop
/* 23F4 803887E4 2605001C */  addiu      $a1, $s0, 0x1c
/* 23F8 803887E8 3C06446D */  lui        $a2, 0x446d
/* 23FC 803887EC 34C68000 */  ori        $a2, $a2, 0x8000
/* 2400 803887F0 AFA50038 */  sw         $a1, 0x38($sp)
/* 2404 803887F4 0C0E1FDC */  jal        func_80387F70
/* 2408 803887F8 02002025 */   or        $a0, $s0, $zero
/* 240C 803887FC 3C01447A */  lui        $at, 0x447a
/* 2410 80388800 44811000 */  mtc1       $at, $f2
/* 2414 80388804 3C014348 */  lui        $at, 0x4348
/* 2418 80388808 44815000 */  mtc1       $at, $f10
/* 241C 8038880C 3C014416 */  lui        $at, 0x4416
/* 2420 80388810 44818000 */  mtc1       $at, $f16
/* 2424 80388814 44061000 */  mfc1       $a2, $f2
/* 2428 80388818 02002025 */  or         $a0, $s0, $zero
/* 242C 8038881C 8FA50038 */  lw         $a1, 0x38($sp)
/* 2430 80388820 3C0744E1 */  lui        $a3, 0x44e1
/* 2434 80388824 E7A20014 */  swc1       $f2, 0x14($sp)
/* 2438 80388828 E7AA0010 */  swc1       $f10, 0x10($sp)
/* 243C 8038882C 0C0E1D1C */  jal        func_80387470
/* 2440 80388830 E7B00018 */   swc1      $f16, 0x18($sp)
/* 2444 80388834 10400266 */  beqz       $v0, .L803891D0
/* 2448 80388838 8FA30058 */   lw        $v1, 0x58($sp)
/* 244C 8038883C 02002025 */  or         $a0, $s0, $zero
/* 2450 80388840 24050003 */  addiu      $a1, $zero, 3
/* 2454 80388844 0C0E2061 */  jal        func_80388184
/* 2458 80388848 AFA30058 */   sw        $v1, 0x58($sp)
/* 245C 8038884C 8FA30058 */  lw         $v1, 0x58($sp)
/* 2460 80388850 2404000C */  addiu      $a0, $zero, 0xc
/* 2464 80388854 3C028039 */  lui        $v0, %hi(D_803927D0)
/* 2468 80388858 90790005 */  lbu        $t9, 5($v1)
/* 246C 8038885C 244227D0 */  addiu      $v0, $v0, %lo(D_803927D0)
/* 2470 80388860 03240019 */  multu      $t9, $a0
/* 2474 80388864 00004012 */  mflo       $t0
/* 2478 80388868 00484821 */  addu       $t1, $v0, $t0
/* 247C 8038886C C5320000 */  lwc1       $f18, ($t1)
/* 2480 80388870 E612001C */  swc1       $f18, 0x1c($s0)
/* 2484 80388874 906A0005 */  lbu        $t2, 5($v1)
/* 2488 80388878 01440019 */  multu      $t2, $a0
/* 248C 8038887C 00005812 */  mflo       $t3
/* 2490 80388880 004B6021 */  addu       $t4, $v0, $t3
/* 2494 80388884 C5840004 */  lwc1       $f4, 4($t4)
/* 2498 80388888 E6040020 */  swc1       $f4, 0x20($s0)
/* 249C 8038888C 906D0005 */  lbu        $t5, 5($v1)
/* 24A0 80388890 01A40019 */  multu      $t5, $a0
/* 24A4 80388894 00007012 */  mflo       $t6
/* 24A8 80388898 004E7821 */  addu       $t7, $v0, $t6
/* 24AC 8038889C C5E60008 */  lwc1       $f6, 8($t7)
/* 24B0 803888A0 1000024B */  b          .L803891D0
/* 24B4 803888A4 E6060024 */   swc1      $f6, 0x24($s0)
/* 24B8 803888A8 8E040000 */  lw         $a0, ($s0)
/* 24BC 803888AC 0C0E1980 */  jal        func_80386600
/* 24C0 803888B0 00002825 */   or        $a1, $zero, $zero
/* 24C4 803888B4 0C0E1A6F */  jal        func_803869BC
/* 24C8 803888B8 02002025 */   or        $a0, $s0, $zero
/* 24CC 803888BC 2605001C */  addiu      $a1, $s0, 0x1c
/* 24D0 803888C0 AFA50038 */  sw         $a1, 0x38($sp)
/* 24D4 803888C4 0C095819 */  jal        ml_vec3f_distance
/* 24D8 803888C8 26040004 */   addiu     $a0, $s0, 4
/* 24DC 803888CC 3C01447A */  lui        $at, 0x447a
/* 24E0 803888D0 44811000 */  mtc1       $at, $f2
/* 24E4 803888D4 3C014396 */  lui        $at, 0x4396
/* 24E8 803888D8 44817000 */  mtc1       $at, $f14
/* 24EC 803888DC 44061000 */  mfc1       $a2, $f2
/* 24F0 803888E0 46000306 */  mov.s      $f12, $f0
/* 24F4 803888E4 3C0742C8 */  lui        $a3, 0x42c8
/* 24F8 803888E8 0C095EC6 */  jal        ml_map_f
/* 24FC 803888EC E7A20010 */   swc1      $f2, 0x10($sp)
/* 2500 803888F0 3C014270 */  lui        $at, 0x4270
/* 2504 803888F4 44814000 */  mtc1       $at, $f8
/* 2508 803888F8 C7AA0054 */  lwc1       $f10, 0x54($sp)
/* 250C 803888FC E7A00050 */  swc1       $f0, 0x50($sp)
/* 2510 80388900 02002025 */  or         $a0, $s0, $zero
/* 2514 80388904 460A4402 */  mul.s      $f16, $f8, $f10
/* 2518 80388908 44058000 */  mfc1       $a1, $f16
/* 251C 8038890C 0C0E1EB3 */  jal        func_80387ACC
/* 2520 80388910 00000000 */   nop
/* 2524 80388914 3C014348 */  lui        $at, 0x4348
/* 2528 80388918 44819000 */  mtc1       $at, $f18
/* 252C 8038891C 3C0143FA */  lui        $at, 0x43fa
/* 2530 80388920 44812000 */  mtc1       $at, $f4
/* 2534 80388924 3C014396 */  lui        $at, 0x4396
/* 2538 80388928 44813000 */  mtc1       $at, $f6
/* 253C 8038892C 02002025 */  or         $a0, $s0, $zero
/* 2540 80388930 8FA50038 */  lw         $a1, 0x38($sp)
/* 2544 80388934 8FA60050 */  lw         $a2, 0x50($sp)
/* 2548 80388938 3C0744E1 */  lui        $a3, 0x44e1
/* 254C 8038893C E7B20010 */  swc1       $f18, 0x10($sp)
/* 2550 80388940 E7A40014 */  swc1       $f4, 0x14($sp)
/* 2554 80388944 0C0E1D1C */  jal        func_80387470
/* 2558 80388948 E7A60018 */   swc1      $f6, 0x18($sp)
/* 255C 8038894C 10400220 */  beqz       $v0, .L803891D0
/* 2560 80388950 02002025 */   or        $a0, $s0, $zero
/* 2564 80388954 0C0E2061 */  jal        func_80388184
/* 2568 80388958 24050004 */   addiu     $a1, $zero, 4
/* 256C 8038895C 1000021D */  b          .L803891D4
/* 2570 80388960 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2574 80388964 8E040000 */  lw         $a0, ($s0)
/* 2578 80388968 0C0E1980 */  jal        func_80386600
/* 257C 8038896C 00002825 */   or        $a1, $zero, $zero
/* 2580 80388970 0C0E1A6F */  jal        func_803869BC
/* 2584 80388974 02002025 */   or        $a0, $s0, $zero
/* 2588 80388978 3C014270 */  lui        $at, 0x4270
/* 258C 8038897C 44814000 */  mtc1       $at, $f8
/* 2590 80388980 C7AA0054 */  lwc1       $f10, 0x54($sp)
/* 2594 80388984 02002025 */  or         $a0, $s0, $zero
/* 2598 80388988 460A4402 */  mul.s      $f16, $f8, $f10
/* 259C 8038898C 44058000 */  mfc1       $a1, $f16
/* 25A0 80388990 0C0E1EB3 */  jal        func_80387ACC
/* 25A4 80388994 00000000 */   nop
/* 25A8 80388998 3C014370 */  lui        $at, 0x4370
/* 25AC 8038899C 44819000 */  mtc1       $at, $f18
/* 25B0 803889A0 C7A40054 */  lwc1       $f4, 0x54($sp)
/* 25B4 803889A4 02002025 */  or         $a0, $s0, $zero
/* 25B8 803889A8 46049182 */  mul.s      $f6, $f18, $f4
/* 25BC 803889AC 44053000 */  mfc1       $a1, $f6
/* 25C0 803889B0 0C0E1AFB */  jal        func_80386BEC
/* 25C4 803889B4 00000000 */   nop
/* 25C8 803889B8 10400205 */  beqz       $v0, .L803891D0
/* 25CC 803889BC 02002025 */   or        $a0, $s0, $zero
/* 25D0 803889C0 0C0E2061 */  jal        func_80388184
/* 25D4 803889C4 24050005 */   addiu     $a1, $zero, 5
/* 25D8 803889C8 3C013F80 */  lui        $at, 0x3f80
/* 25DC 803889CC 44816000 */  mtc1       $at, $f12
/* 25E0 803889D0 3C058039 */  lui        $a1, %hi(D_80391380)
/* 25E4 803889D4 3C068039 */  lui        $a2, %hi(D_80391390)
/* 25E8 803889D8 24C61390 */  addiu      $a2, $a2, %lo(D_80391390)
/* 25EC 803889DC 0C0E1995 */  jal        func_80386654
/* 25F0 803889E0 24A51380 */   addiu     $a1, $a1, %lo(D_80391380)
/* 25F4 803889E4 100001FB */  b          .L803891D4
/* 25F8 803889E8 8FBF002C */   lw        $ra, 0x2c($sp)
/* 25FC 803889EC 02002025 */  or         $a0, $s0, $zero
/* 2600 803889F0 0C0E1EC0 */  jal        func_80387B00
/* 2604 803889F4 AFA30058 */   sw        $v1, 0x58($sp)
/* 2608 803889F8 C6080060 */  lwc1       $f8, 0x60($s0)
/* 260C 803889FC C7AA0054 */  lwc1       $f10, 0x54($sp)
/* 2610 80388A00 8FA30058 */  lw         $v1, 0x58($sp)
/* 2614 80388A04 3C018039 */  lui        $at, %hi(D_803921E8)
/* 2618 80388A08 460A4400 */  add.s      $f16, $f8, $f10
/* 261C 80388A0C E6100060 */  swc1       $f16, 0x60($s0)
/* 2620 80388A10 C6120060 */  lwc1       $f18, 0x60($s0)
/* 2624 80388A14 D42421E8 */  ldc1       $f4, %lo(D_803921E8)($at)
/* 2628 80388A18 C7A80054 */  lwc1       $f8, 0x54($sp)
/* 262C 80388A1C 46009021 */  cvt.d.s    $f0, $f18
/* 2630 80388A20 3C018039 */  lui        $at, 0x8039
/* 2634 80388A24 4624003C */  c.lt.d     $f0, $f4
/* 2638 80388A28 00000000 */  nop
/* 263C 80388A2C 4500000B */  bc1f       .L80388A5C
/* 2640 80388A30 00000000 */   nop
/* 2644 80388A34 3C018039 */  lui        $at, %hi(D_803921F0)
/* 2648 80388A38 D42621F0 */  ldc1       $f6, %lo(D_803921F0)($at)
/* 264C 80388A3C 460042A1 */  cvt.d.s    $f10, $f8
/* 2650 80388A40 C6120028 */  lwc1       $f18, 0x28($s0)
/* 2654 80388A44 462A3402 */  mul.d      $f16, $f6, $f10
/* 2658 80388A48 46009121 */  cvt.d.s    $f4, $f18
/* 265C 80388A4C 46302200 */  add.d      $f8, $f4, $f16
/* 2660 80388A50 462041A0 */  cvt.s.d    $f6, $f8
/* 2664 80388A54 1000000F */  b          .L80388A94
/* 2668 80388A58 E6060028 */   swc1      $f6, 0x28($s0)
.L80388A5C:
/* 266C 80388A5C D42A21F8 */  ldc1       $f10, 0x21f8($at)
/* 2670 80388A60 C7A40054 */  lwc1       $f4, 0x54($sp)
/* 2674 80388A64 4620503C */  c.lt.d     $f10, $f0
/* 2678 80388A68 00000000 */  nop
/* 267C 80388A6C 45000009 */  bc1f       .L80388A94
/* 2680 80388A70 3C018039 */   lui       $at, %hi(D_80392200)
/* 2684 80388A74 D4322200 */  ldc1       $f18, %lo(D_80392200)($at)
/* 2688 80388A78 46002421 */  cvt.d.s    $f16, $f4
/* 268C 80388A7C C6060028 */  lwc1       $f6, 0x28($s0)
/* 2690 80388A80 46309202 */  mul.d      $f8, $f18, $f16
/* 2694 80388A84 460032A1 */  cvt.d.s    $f10, $f6
/* 2698 80388A88 46285101 */  sub.d      $f4, $f10, $f8
/* 269C 80388A8C 462024A0 */  cvt.s.d    $f18, $f4
/* 26A0 80388A90 E6120028 */  swc1       $f18, 0x28($s0)
.L80388A94:
/* 26A4 80388A94 C6100028 */  lwc1       $f16, 0x28($s0)
/* 26A8 80388A98 C7A60054 */  lwc1       $f6, 0x54($sp)
/* 26AC 80388A9C C4680020 */  lwc1       $f8, 0x20($v1)
/* 26B0 80388AA0 3C014234 */  lui        $at, 0x4234
/* 26B4 80388AA4 46068282 */  mul.s      $f10, $f16, $f6
/* 26B8 80388AA8 44819000 */  mtc1       $at, $f18
/* 26BC 80388AAC 02002025 */  or         $a0, $s0, $zero
/* 26C0 80388AB0 460A4100 */  add.s      $f4, $f8, $f10
/* 26C4 80388AB4 E4640020 */  swc1       $f4, 0x20($v1)
/* 26C8 80388AB8 C7B00054 */  lwc1       $f16, 0x54($sp)
/* 26CC 80388ABC 46109182 */  mul.s      $f6, $f18, $f16
/* 26D0 80388AC0 44053000 */  mfc1       $a1, $f6
/* 26D4 80388AC4 0C0E1EFF */  jal        func_80387BFC
/* 26D8 80388AC8 00000000 */   nop
/* 26DC 80388ACC 3C0141F0 */  lui        $at, 0x41f0
/* 26E0 80388AD0 44814000 */  mtc1       $at, $f8
/* 26E4 80388AD4 C7AA0054 */  lwc1       $f10, 0x54($sp)
/* 26E8 80388AD8 02002025 */  or         $a0, $s0, $zero
/* 26EC 80388ADC 460A4102 */  mul.s      $f4, $f8, $f10
/* 26F0 80388AE0 44052000 */  mfc1       $a1, $f4
/* 26F4 80388AE4 0C0CA3EC */  jal        func_80328FB0
/* 26F8 80388AE8 00000000 */   nop
/* 26FC 80388AEC C6100060 */  lwc1       $f16, 0x60($s0)
/* 2700 80388AF0 3C013FF0 */  lui        $at, 0x3ff0
/* 2704 80388AF4 44819800 */  mtc1       $at, $f19
/* 2708 80388AF8 44809000 */  mtc1       $zero, $f18
/* 270C 80388AFC 460081A1 */  cvt.d.s    $f6, $f16
/* 2710 80388B00 02002025 */  or         $a0, $s0, $zero
/* 2714 80388B04 4626903C */  c.lt.d     $f18, $f6
/* 2718 80388B08 00000000 */  nop
/* 271C 80388B0C 450201B1 */  bc1fl      .L803891D4
/* 2720 80388B10 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2724 80388B14 0C0E2061 */  jal        func_80388184
/* 2728 80388B18 24050006 */   addiu     $a1, $zero, 6
/* 272C 80388B1C 100001AD */  b          .L803891D4
/* 2730 80388B20 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2734 80388B24 02002025 */  or         $a0, $s0, $zero
/* 2738 80388B28 0C0E1A6F */  jal        func_803869BC
/* 273C 80388B2C AFA30058 */   sw        $v1, 0x58($sp)
/* 2740 80388B30 8FA30058 */  lw         $v1, 0x58($sp)
/* 2744 80388B34 3C098039 */  lui        $t1, 0x8039
/* 2748 80388B38 3C0B8039 */  lui        $t3, 0x8039
/* 274C 80388B3C 90620001 */  lbu        $v0, 1($v1)
/* 2750 80388B40 90780004 */  lbu        $t8, 4($v1)
/* 2754 80388B44 24590001 */  addiu      $t9, $v0, 1
/* 2758 80388B48 0319082A */  slt        $at, $t8, $t9
/* 275C 80388B4C 14200012 */  bnez       $at, .L80388B98
/* 2760 80388B50 00025080 */   sll       $t2, $v0, 2
/* 2764 80388B54 00024080 */  sll        $t0, $v0, 2
/* 2768 80388B58 01284821 */  addu       $t1, $t1, $t0
/* 276C 80388B5C 8D291738 */  lw         $t1, 0x1738($t1)
/* 2770 80388B60 C7A00054 */  lwc1       $f0, 0x54($sp)
/* 2774 80388B64 3C018039 */  lui        $at, %hi(D_80392208)
/* 2778 80388B68 44894000 */  mtc1       $t1, $f8
/* 277C 80388B6C D4322208 */  ldc1       $f18, %lo(D_80392208)($at)
/* 2780 80388B70 468042A0 */  cvt.s.w    $f10, $f8
/* 2784 80388B74 C6080028 */  lwc1       $f8, 0x28($s0)
/* 2788 80388B78 46005102 */  mul.s      $f4, $f10, $f0
/* 278C 80388B7C 460042A1 */  cvt.d.s    $f10, $f8
/* 2790 80388B80 46002421 */  cvt.d.s    $f16, $f4
/* 2794 80388B84 46328182 */  mul.d      $f6, $f16, $f18
/* 2798 80388B88 46265100 */  add.d      $f4, $f10, $f6
/* 279C 80388B8C 46202420 */  cvt.s.d    $f16, $f4
/* 27A0 80388B90 1000000C */  b          .L80388BC4
/* 27A4 80388B94 E6100028 */   swc1      $f16, 0x28($s0)
.L80388B98:
/* 27A8 80388B98 016A5821 */  addu       $t3, $t3, $t2
/* 27AC 80388B9C 8D6B1738 */  lw         $t3, 0x1738($t3)
/* 27B0 80388BA0 C7AA0054 */  lwc1       $f10, 0x54($sp)
/* 27B4 80388BA4 C6040028 */  lwc1       $f4, 0x28($s0)
/* 27B8 80388BA8 448B9000 */  mtc1       $t3, $f18
/* 27BC 80388BAC 00000000 */  nop
/* 27C0 80388BB0 46809220 */  cvt.s.w    $f8, $f18
/* 27C4 80388BB4 460A4182 */  mul.s      $f6, $f8, $f10
/* 27C8 80388BB8 46062400 */  add.s      $f16, $f4, $f6
/* 27CC 80388BBC E6100028 */  swc1       $f16, 0x28($s0)
/* 27D0 80388BC0 C7A00054 */  lwc1       $f0, 0x54($sp)
.L80388BC4:
/* 27D4 80388BC4 C6080028 */  lwc1       $f8, 0x28($s0)
/* 27D8 80388BC8 3C014334 */  lui        $at, 0x4334
/* 27DC 80388BCC 44813000 */  mtc1       $at, $f6
/* 27E0 80388BD0 46004282 */  mul.s      $f10, $f8, $f0
/* 27E4 80388BD4 C4720020 */  lwc1       $f18, 0x20($v1)
/* 27E8 80388BD8 02002025 */  or         $a0, $s0, $zero
/* 27EC 80388BDC 46003402 */  mul.s      $f16, $f6, $f0
/* 27F0 80388BE0 460A9101 */  sub.s      $f4, $f18, $f10
/* 27F4 80388BE4 44058000 */  mfc1       $a1, $f16
/* 27F8 80388BE8 E4640020 */  swc1       $f4, 0x20($v1)
/* 27FC 80388BEC 0C0E1EFF */  jal        func_80387BFC
/* 2800 80388BF0 AFA30058 */   sw        $v1, 0x58($sp)
/* 2804 80388BF4 3C0141F0 */  lui        $at, 0x41f0
/* 2808 80388BF8 44814000 */  mtc1       $at, $f8
/* 280C 80388BFC C7B20054 */  lwc1       $f18, 0x54($sp)
/* 2810 80388C00 02002025 */  or         $a0, $s0, $zero
/* 2814 80388C04 46124282 */  mul.s      $f10, $f8, $f18
/* 2818 80388C08 44055000 */  mfc1       $a1, $f10
/* 281C 80388C0C 0C0CA3EC */  jal        func_80328FB0
/* 2820 80388C10 00000000 */   nop
/* 2824 80388C14 8FA30058 */  lw         $v1, 0x58($sp)
/* 2828 80388C18 906C000A */  lbu        $t4, 0xa($v1)
/* 282C 80388C1C 55800017 */  bnel       $t4, $zero, .L80388C7C
/* 2830 80388C20 C4700014 */   lwc1      $f16, 0x14($v1)
/* 2834 80388C24 C4700014 */  lwc1       $f16, 0x14($v1)
/* 2838 80388C28 3C018039 */  lui        $at, %hi(D_80392210)
/* 283C 80388C2C D4322210 */  ldc1       $f18, %lo(D_80392210)($at)
/* 2840 80388C30 46008221 */  cvt.d.s    $f8, $f16
/* 2844 80388C34 C4640020 */  lwc1       $f4, 0x20($v1)
/* 2848 80388C38 46324282 */  mul.d      $f10, $f8, $f18
/* 284C 80388C3C 3C044CBB */  lui        $a0, 0x4cbb
/* 2850 80388C40 460021A1 */  cvt.d.s    $f6, $f4
/* 2854 80388C44 3C062710 */  lui        $a2, 0x2710
/* 2858 80388C48 240D0001 */  addiu      $t5, $zero, 1
/* 285C 80388C4C 34C607D0 */  ori        $a2, $a2, 0x7d0
/* 2860 80388C50 348458C4 */  ori        $a0, $a0, 0x58c4
/* 2864 80388C54 26050004 */  addiu      $a1, $s0, 4
/* 2868 80388C58 462A303C */  c.lt.d     $f6, $f10
/* 286C 80388C5C 00000000 */  nop
/* 2870 80388C60 45020006 */  bc1fl      .L80388C7C
/* 2874 80388C64 C4700014 */   lwc1      $f16, 0x14($v1)
/* 2878 80388C68 A06D000A */  sb         $t5, 0xa($v1)
/* 287C 80388C6C 0C0C3A2D */  jal        func_8030E8B4
/* 2880 80388C70 AFA30058 */   sw        $v1, 0x58($sp)
/* 2884 80388C74 8FA30058 */  lw         $v1, 0x58($sp)
/* 2888 80388C78 C4700014 */  lwc1       $f16, 0x14($v1)
.L80388C7C:
/* 288C 80388C7C 3C013FE8 */  lui        $at, 0x3fe8
/* 2890 80388C80 44819800 */  mtc1       $at, $f19
/* 2894 80388C84 44809000 */  mtc1       $zero, $f18
/* 2898 80388C88 46008221 */  cvt.d.s    $f8, $f16
/* 289C 80388C8C C4640020 */  lwc1       $f4, 0x20($v1)
/* 28A0 80388C90 46324182 */  mul.d      $f6, $f8, $f18
/* 28A4 80388C94 27A40040 */  addiu      $a0, $sp, 0x40
/* 28A8 80388C98 460020A1 */  cvt.d.s    $f2, $f4
/* 28AC 80388C9C 24050000 */  addiu      $a1, $zero, 0
/* 28B0 80388CA0 4622303C */  c.lt.d     $f6, $f2
/* 28B4 80388CA4 00000000 */  nop
/* 28B8 80388CA8 45020025 */  bc1fl      .L80388D40
/* 28BC 80388CAC 44804800 */   mtc1      $zero, $f9
/* 28C0 80388CB0 0C0E1AD5 */  jal        func_80386B54
/* 28C4 80388CB4 AFA30058 */   sw        $v1, 0x58($sp)
/* 28C8 80388CB8 C7AA0040 */  lwc1       $f10, 0x40($sp)
/* 28CC 80388CBC 44800000 */  mtc1       $zero, $f0
/* 28D0 80388CC0 C6080004 */  lwc1       $f8, 4($s0)
/* 28D4 80388CC4 E60A001C */  swc1       $f10, 0x1c($s0)
/* 28D8 80388CC8 C7A40044 */  lwc1       $f4, 0x44($sp)
/* 28DC 80388CCC C60A0008 */  lwc1       $f10, 8($s0)
/* 28E0 80388CD0 2604002C */  addiu      $a0, $s0, 0x2c
/* 28E4 80388CD4 E6040020 */  swc1       $f4, 0x20($s0)
/* 28E8 80388CD8 C7B00048 */  lwc1       $f16, 0x48($sp)
/* 28EC 80388CDC E6000020 */  swc1       $f0, 0x20($s0)
/* 28F0 80388CE0 E6100024 */  swc1       $f16, 0x24($s0)
/* 28F4 80388CE4 C7B20040 */  lwc1       $f18, 0x40($sp)
/* 28F8 80388CE8 46124181 */  sub.s      $f6, $f8, $f18
/* 28FC 80388CEC C608000C */  lwc1       $f8, 0xc($s0)
/* 2900 80388CF0 E606002C */  swc1       $f6, 0x2c($s0)
/* 2904 80388CF4 C7A40044 */  lwc1       $f4, 0x44($sp)
/* 2908 80388CF8 46045401 */  sub.s      $f16, $f10, $f4
/* 290C 80388CFC E6100030 */  swc1       $f16, 0x30($s0)
/* 2910 80388D00 C7B20048 */  lwc1       $f18, 0x48($sp)
/* 2914 80388D04 E6000030 */  swc1       $f0, 0x30($s0)
/* 2918 80388D08 46124181 */  sub.s      $f6, $f8, $f18
/* 291C 80388D0C 0C095914 */  jal        ml_vec3f_normalize
/* 2920 80388D10 E6060034 */   swc1      $f6, 0x34($s0)
/* 2924 80388D14 C60C002C */  lwc1       $f12, 0x2c($s0)
/* 2928 80388D18 0C095C57 */  jal        func_8025715C
/* 292C 80388D1C C60E0034 */   lwc1      $f14, 0x34($s0)
/* 2930 80388D20 3C014334 */  lui        $at, 0x4334
/* 2934 80388D24 44815000 */  mtc1       $at, $f10
/* 2938 80388D28 8FA30058 */  lw         $v1, 0x58($sp)
/* 293C 80388D2C 460A0100 */  add.s      $f4, $f0, $f10
/* 2940 80388D30 E6040064 */  swc1       $f4, 0x64($s0)
/* 2944 80388D34 C4700020 */  lwc1       $f16, 0x20($v1)
/* 2948 80388D38 460080A1 */  cvt.d.s    $f2, $f16
/* 294C 80388D3C 44804800 */  mtc1       $zero, $f9
.L80388D40:
/* 2950 80388D40 44804000 */  mtc1       $zero, $f8
/* 2954 80388D44 00000000 */  nop
/* 2958 80388D48 4628103C */  c.lt.d     $f2, $f8
/* 295C 80388D4C 00000000 */  nop
/* 2960 80388D50 45020120 */  bc1fl      .L803891D4
/* 2964 80388D54 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2968 80388D58 90620001 */  lbu        $v0, 1($v1)
/* 296C 80388D5C 00002025 */  or         $a0, $zero, $zero
/* 2970 80388D60 24050007 */  addiu      $a1, $zero, 7
/* 2974 80388D64 14400003 */  bnez       $v0, .L80388D74
/* 2978 80388D68 00000000 */   nop
/* 297C 80388D6C 10000001 */  b          .L80388D74
/* 2980 80388D70 24040001 */   addiu     $a0, $zero, 1
.L80388D74:
/* 2984 80388D74 906E0004 */  lbu        $t6, 4($v1)
/* 2988 80388D78 00827821 */  addu       $t7, $a0, $v0
/* 298C 80388D7C 02002025 */  or         $a0, $s0, $zero
/* 2990 80388D80 01CF082A */  slt        $at, $t6, $t7
/* 2994 80388D84 14200008 */  bnez       $at, .L80388DA8
/* 2998 80388D88 00000000 */   nop
/* 299C 80388D8C 02002025 */  or         $a0, $s0, $zero
/* 29A0 80388D90 24050008 */  addiu      $a1, $zero, 8
/* 29A4 80388D94 0C0E2061 */  jal        func_80388184
/* 29A8 80388D98 AFA30058 */   sw        $v1, 0x58($sp)
/* 29AC 80388D9C 8FA30058 */  lw         $v1, 0x58($sp)
/* 29B0 80388DA0 1000010B */  b          .L803891D0
/* 29B4 80388DA4 A0600004 */   sb        $zero, 4($v1)
.L80388DA8:
/* 29B8 80388DA8 0C0E2061 */  jal        func_80388184
/* 29BC 80388DAC AFA30058 */   sw        $v1, 0x58($sp)
/* 29C0 80388DB0 8FA30058 */  lw         $v1, 0x58($sp)
/* 29C4 80388DB4 90780004 */  lbu        $t8, 4($v1)
/* 29C8 80388DB8 27190001 */  addiu      $t9, $t8, 1
/* 29CC 80388DBC 10000104 */  b          .L803891D0
/* 29D0 80388DC0 A0790004 */   sb        $t9, 4($v1)
/* 29D4 80388DC4 02002025 */  or         $a0, $s0, $zero
/* 29D8 80388DC8 0C0E1A6F */  jal        func_803869BC
/* 29DC 80388DCC AFA30058 */   sw        $v1, 0x58($sp)
/* 29E0 80388DD0 8FA30058 */  lw         $v1, 0x58($sp)
/* 29E4 80388DD4 C7A00054 */  lwc1       $f0, 0x54($sp)
/* 29E8 80388DD8 C6120028 */  lwc1       $f18, 0x28($s0)
/* 29EC 80388DDC C4660028 */  lwc1       $f6, 0x28($v1)
/* 29F0 80388DE0 3C014334 */  lui        $at, 0x4334
/* 29F4 80388DE4 02002025 */  or         $a0, $s0, $zero
/* 29F8 80388DE8 46003282 */  mul.s      $f10, $f6, $f0
/* 29FC 80388DEC 460A9100 */  add.s      $f4, $f18, $f10
/* 2A00 80388DF0 44815000 */  mtc1       $at, $f10
/* 2A04 80388DF4 E6040028 */  swc1       $f4, 0x28($s0)
/* 2A08 80388DF8 C6080028 */  lwc1       $f8, 0x28($s0)
/* 2A0C 80388DFC C4700020 */  lwc1       $f16, 0x20($v1)
/* 2A10 80388E00 46004182 */  mul.s      $f6, $f8, $f0
/* 2A14 80388E04 00000000 */  nop
/* 2A18 80388E08 46005102 */  mul.s      $f4, $f10, $f0
/* 2A1C 80388E0C 46068481 */  sub.s      $f18, $f16, $f6
/* 2A20 80388E10 44052000 */  mfc1       $a1, $f4
/* 2A24 80388E14 0C0E1EFF */  jal        func_80387BFC
/* 2A28 80388E18 E4720020 */   swc1      $f18, 0x20($v1)
/* 2A2C 80388E1C 3C0141F0 */  lui        $at, 0x41f0
/* 2A30 80388E20 44814000 */  mtc1       $at, $f8
/* 2A34 80388E24 C7B00054 */  lwc1       $f16, 0x54($sp)
/* 2A38 80388E28 02002025 */  or         $a0, $s0, $zero
/* 2A3C 80388E2C 46104182 */  mul.s      $f6, $f8, $f16
/* 2A40 80388E30 44053000 */  mfc1       $a1, $f6
/* 2A44 80388E34 0C0CA3EC */  jal        func_80328FB0
/* 2A48 80388E38 00000000 */   nop
/* 2A4C 80388E3C C6120028 */  lwc1       $f18, 0x28($s0)
/* 2A50 80388E40 44805000 */  mtc1       $zero, $f10
/* 2A54 80388E44 02002025 */  or         $a0, $s0, $zero
/* 2A58 80388E48 460A903C */  c.lt.s     $f18, $f10
/* 2A5C 80388E4C 00000000 */  nop
/* 2A60 80388E50 450200E0 */  bc1fl      .L803891D4
/* 2A64 80388E54 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2A68 80388E58 0C0E2061 */  jal        func_80388184
/* 2A6C 80388E5C 24050004 */   addiu     $a1, $zero, 4
/* 2A70 80388E60 3C013FC0 */  lui        $at, 0x3fc0
/* 2A74 80388E64 44816000 */  mtc1       $at, $f12
/* 2A78 80388E68 3C058039 */  lui        $a1, %hi(D_80391390)
/* 2A7C 80388E6C 3C068039 */  lui        $a2, %hi(D_80391380)
/* 2A80 80388E70 24C61380 */  addiu      $a2, $a2, %lo(D_80391380)
/* 2A84 80388E74 0C0E1995 */  jal        func_80386654
/* 2A88 80388E78 24A51390 */   addiu     $a1, $a1, %lo(D_80391390)
/* 2A8C 80388E7C 100000D5 */  b          .L803891D4
/* 2A90 80388E80 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2A94 80388E84 02002025 */  or         $a0, $s0, $zero
/* 2A98 80388E88 0C0E2177 */  jal        func_803885DC
/* 2A9C 80388E8C AFA30058 */   sw        $v1, 0x58($sp)
/* 2AA0 80388E90 0C0E1A6F */  jal        func_803869BC
/* 2AA4 80388E94 02002025 */   or        $a0, $s0, $zero
/* 2AA8 80388E98 8FA30058 */  lw         $v1, 0x58($sp)
/* 2AAC 80388E9C C7A00054 */  lwc1       $f0, 0x54($sp)
/* 2AB0 80388EA0 C6040028 */  lwc1       $f4, 0x28($s0)
/* 2AB4 80388EA4 C4680028 */  lwc1       $f8, 0x28($v1)
/* 2AB8 80388EA8 3C014270 */  lui        $at, 0x4270
/* 2ABC 80388EAC 02002025 */  or         $a0, $s0, $zero
/* 2AC0 80388EB0 46004402 */  mul.s      $f16, $f8, $f0
/* 2AC4 80388EB4 46102180 */  add.s      $f6, $f4, $f16
/* 2AC8 80388EB8 44818000 */  mtc1       $at, $f16
/* 2ACC 80388EBC E6060028 */  swc1       $f6, 0x28($s0)
/* 2AD0 80388EC0 C60A0028 */  lwc1       $f10, 0x28($s0)
/* 2AD4 80388EC4 C4720020 */  lwc1       $f18, 0x20($v1)
/* 2AD8 80388EC8 46005202 */  mul.s      $f8, $f10, $f0
/* 2ADC 80388ECC 00000000 */  nop
/* 2AE0 80388ED0 46008182 */  mul.s      $f6, $f16, $f0
/* 2AE4 80388ED4 46089101 */  sub.s      $f4, $f18, $f8
/* 2AE8 80388ED8 44053000 */  mfc1       $a1, $f6
/* 2AEC 80388EDC 0C0E1EB3 */  jal        func_80387ACC
/* 2AF0 80388EE0 E4640020 */   swc1      $f4, 0x20($v1)
/* 2AF4 80388EE4 0C0E1F53 */  jal        func_80387D4C
/* 2AF8 80388EE8 02002025 */   or        $a0, $s0, $zero
/* 2AFC 80388EEC 3C0141F0 */  lui        $at, 0x41f0
/* 2B00 80388EF0 44815000 */  mtc1       $at, $f10
/* 2B04 80388EF4 C7B20054 */  lwc1       $f18, 0x54($sp)
/* 2B08 80388EF8 02002025 */  or         $a0, $s0, $zero
/* 2B0C 80388EFC 46125202 */  mul.s      $f8, $f10, $f18
/* 2B10 80388F00 44054000 */  mfc1       $a1, $f8
/* 2B14 80388F04 0C0CA3EC */  jal        func_80328FB0
/* 2B18 80388F08 00000000 */   nop
/* 2B1C 80388F0C C6040028 */  lwc1       $f4, 0x28($s0)
/* 2B20 80388F10 44808000 */  mtc1       $zero, $f16
/* 2B24 80388F14 02002025 */  or         $a0, $s0, $zero
/* 2B28 80388F18 4610203C */  c.lt.s     $f4, $f16
/* 2B2C 80388F1C 00000000 */  nop
/* 2B30 80388F20 450200AC */  bc1fl      .L803891D4
/* 2B34 80388F24 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2B38 80388F28 0C0E2061 */  jal        func_80388184
/* 2B3C 80388F2C 24050009 */   addiu     $a1, $zero, 9
/* 2B40 80388F30 3C014000 */  lui        $at, 0x4000
/* 2B44 80388F34 44816000 */  mtc1       $at, $f12
/* 2B48 80388F38 3C058039 */  lui        $a1, %hi(D_80391390)
/* 2B4C 80388F3C 3C068039 */  lui        $a2, %hi(D_80391380)
/* 2B50 80388F40 24C61380 */  addiu      $a2, $a2, %lo(D_80391380)
/* 2B54 80388F44 0C0E1995 */  jal        func_80386654
/* 2B58 80388F48 24A51390 */   addiu     $a1, $a1, %lo(D_80391390)
/* 2B5C 80388F4C 3C014080 */  lui        $at, 0x4080
/* 2B60 80388F50 44813000 */  mtc1       $at, $f6
/* 2B64 80388F54 1000009E */  b          .L803891D0
/* 2B68 80388F58 E6060060 */   swc1      $f6, 0x60($s0)
/* 2B6C 80388F5C 0C0E2177 */  jal        func_803885DC
/* 2B70 80388F60 02002025 */   or        $a0, $s0, $zero
/* 2B74 80388F64 C6000060 */  lwc1       $f0, 0x60($s0)
/* 2B78 80388F68 44805800 */  mtc1       $zero, $f11
/* 2B7C 80388F6C 44805000 */  mtc1       $zero, $f10
/* 2B80 80388F70 460004A1 */  cvt.d.s    $f18, $f0
/* 2B84 80388F74 C7A80054 */  lwc1       $f8, 0x54($sp)
/* 2B88 80388F78 4632503C */  c.lt.d     $f10, $f18
/* 2B8C 80388F7C 02002025 */  or         $a0, $s0, $zero
/* 2B90 80388F80 3C053F7F */  lui        $a1, 0x3f7f
/* 2B94 80388F84 45000004 */  bc1f       .L80388F98
/* 2B98 80388F88 00000000 */   nop
/* 2B9C 80388F8C 46080101 */  sub.s      $f4, $f0, $f8
/* 2BA0 80388F90 1000008F */  b          .L803891D0
/* 2BA4 80388F94 E6040060 */   swc1      $f4, 0x60($s0)
.L80388F98:
/* 2BA8 80388F98 0C0CA21B */  jal        actor_animationIsAt
/* 2BAC 80388F9C 34A5F972 */   ori       $a1, $a1, 0xf972
/* 2BB0 80388FA0 1040008B */  beqz       $v0, .L803891D0
/* 2BB4 80388FA4 02002025 */   or        $a0, $s0, $zero
/* 2BB8 80388FA8 0C0E2061 */  jal        func_80388184
/* 2BBC 80388FAC 24050002 */   addiu     $a1, $zero, 2
/* 2BC0 80388FB0 02002025 */  or         $a0, $s0, $zero
/* 2BC4 80388FB4 0C0E2028 */  jal        func_803880A0
/* 2BC8 80388FB8 3C0544FA */   lui       $a1, 0x44fa
/* 2BCC 80388FBC 10000085 */  b          .L803891D4
/* 2BD0 80388FC0 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2BD4 80388FC4 3C014270 */  lui        $at, 0x4270
/* 2BD8 80388FC8 44818000 */  mtc1       $at, $f16
/* 2BDC 80388FCC C7A60054 */  lwc1       $f6, 0x54($sp)
/* 2BE0 80388FD0 02002025 */  or         $a0, $s0, $zero
/* 2BE4 80388FD4 46068282 */  mul.s      $f10, $f16, $f6
/* 2BE8 80388FD8 44055000 */  mfc1       $a1, $f10
/* 2BEC 80388FDC 0C0E1EB3 */  jal        func_80387ACC
/* 2BF0 80388FE0 00000000 */   nop
/* 2BF4 80388FE4 02002025 */  or         $a0, $s0, $zero
/* 2BF8 80388FE8 0C0E1AFB */  jal        func_80386BEC
/* 2BFC 80388FEC 3C0541F0 */   lui       $a1, 0x41f0
/* 2C00 80388FF0 3C0143C8 */  lui        $at, 0x43c8
/* 2C04 80388FF4 44819000 */  mtc1       $at, $f18
/* 2C08 80388FF8 C7A80054 */  lwc1       $f8, 0x54($sp)
/* 2C0C 80388FFC 02002025 */  or         $a0, $s0, $zero
/* 2C10 80389000 3C0543E6 */  lui        $a1, 0x43e6
/* 2C14 80389004 46089102 */  mul.s      $f4, $f18, $f8
/* 2C18 80389008 44062000 */  mfc1       $a2, $f4
/* 2C1C 8038900C 0C0E21C7 */  jal        func_8038871C
/* 2C20 80389010 00000000 */   nop
/* 2C24 80389014 02002025 */  or         $a0, $s0, $zero
/* 2C28 80389018 0C0E1CD0 */  jal        func_80387340
/* 2C2C 8038901C 3C053F80 */   lui       $a1, 0x3f80
/* 2C30 80389020 3C053F7F */  lui        $a1, 0x3f7f
/* 2C34 80389024 34A5F972 */  ori        $a1, $a1, 0xf972
/* 2C38 80389028 0C0CA21B */  jal        actor_animationIsAt
/* 2C3C 8038902C 02002025 */   or        $a0, $s0, $zero
/* 2C40 80389030 10400067 */  beqz       $v0, .L803891D0
/* 2C44 80389034 02002025 */   or        $a0, $s0, $zero
/* 2C48 80389038 0C0E2061 */  jal        func_80388184
/* 2C4C 8038903C 24050002 */   addiu     $a1, $zero, 2
/* 2C50 80389040 02002025 */  or         $a0, $s0, $zero
/* 2C54 80389044 0C0E2028 */  jal        func_803880A0
/* 2C58 80389048 3C0544FA */   lui       $a1, 0x44fa
/* 2C5C 8038904C 10000061 */  b          .L803891D4
/* 2C60 80389050 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2C64 80389054 3C014270 */  lui        $at, 0x4270
/* 2C68 80389058 44818000 */  mtc1       $at, $f16
/* 2C6C 8038905C C7A60054 */  lwc1       $f6, 0x54($sp)
/* 2C70 80389060 02002025 */  or         $a0, $s0, $zero
/* 2C74 80389064 AFA30058 */  sw         $v1, 0x58($sp)
/* 2C78 80389068 46068282 */  mul.s      $f10, $f16, $f6
/* 2C7C 8038906C 44055000 */  mfc1       $a1, $f10
/* 2C80 80389070 0C0E1EB3 */  jal        func_80387ACC
/* 2C84 80389074 00000000 */   nop
/* 2C88 80389078 02002025 */  or         $a0, $s0, $zero
/* 2C8C 8038907C 0C0E1AFB */  jal        func_80386BEC
/* 2C90 80389080 3C0541F0 */   lui       $a1, 0x41f0
/* 2C94 80389084 8FA30058 */  lw         $v1, 0x58($sp)
/* 2C98 80389088 3C0143C8 */  lui        $at, 0x43c8
/* 2C9C 8038908C C7A80054 */  lwc1       $f8, 0x54($sp)
/* 2CA0 80389090 90680009 */  lbu        $t0, 9($v1)
/* 2CA4 80389094 5100004F */  beql       $t0, $zero, .L803891D4
/* 2CA8 80389098 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2CAC 8038909C 44819000 */  mtc1       $at, $f18
/* 2CB0 803890A0 02002025 */  or         $a0, $s0, $zero
/* 2CB4 803890A4 3C0543E6 */  lui        $a1, 0x43e6
/* 2CB8 803890A8 46089102 */  mul.s      $f4, $f18, $f8
/* 2CBC 803890AC 44062000 */  mfc1       $a2, $f4
/* 2CC0 803890B0 0C0E21C7 */  jal        func_8038871C
/* 2CC4 803890B4 00000000 */   nop
/* 2CC8 803890B8 10000046 */  b          .L803891D4
/* 2CCC 803890BC 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2CD0 803890C0 3C014270 */  lui        $at, 0x4270
/* 2CD4 803890C4 44818000 */  mtc1       $at, $f16
/* 2CD8 803890C8 C7A60054 */  lwc1       $f6, 0x54($sp)
/* 2CDC 803890CC 02002025 */  or         $a0, $s0, $zero
/* 2CE0 803890D0 46068282 */  mul.s      $f10, $f16, $f6
/* 2CE4 803890D4 44055000 */  mfc1       $a1, $f10
/* 2CE8 803890D8 0C0E1EB3 */  jal        func_80387ACC
/* 2CEC 803890DC 00000000 */   nop
/* 2CF0 803890E0 02002025 */  or         $a0, $s0, $zero
/* 2CF4 803890E4 0C0E1AFB */  jal        func_80386BEC
/* 2CF8 803890E8 3C0541F0 */   lui       $a1, 0x41f0
/* 2CFC 803890EC 3C0143C8 */  lui        $at, 0x43c8
/* 2D00 803890F0 44819000 */  mtc1       $at, $f18
/* 2D04 803890F4 C7A80054 */  lwc1       $f8, 0x54($sp)
/* 2D08 803890F8 02002025 */  or         $a0, $s0, $zero
/* 2D0C 803890FC 3C0543E6 */  lui        $a1, 0x43e6
/* 2D10 80389100 46089102 */  mul.s      $f4, $f18, $f8
/* 2D14 80389104 44062000 */  mfc1       $a2, $f4
/* 2D18 80389108 0C0E21C7 */  jal        func_8038871C
/* 2D1C 8038910C 00000000 */   nop
/* 2D20 80389110 02002025 */  or         $a0, $s0, $zero
/* 2D24 80389114 3C054416 */  lui        $a1, 0x4416
/* 2D28 80389118 0C0E1CF7 */  jal        func_803873DC
/* 2D2C 8038911C 3C0644FA */   lui       $a2, 0x44fa
/* 2D30 80389120 3C053F7F */  lui        $a1, 0x3f7f
/* 2D34 80389124 34A5F972 */  ori        $a1, $a1, 0xf972
/* 2D38 80389128 0C0CA21B */  jal        actor_animationIsAt
/* 2D3C 8038912C 02002025 */   or        $a0, $s0, $zero
/* 2D40 80389130 50400028 */  beql       $v0, $zero, .L803891D4
/* 2D44 80389134 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2D48 80389138 0C0C3691 */  jal        func_8030DA44
/* 2D4C 8038913C 92040044 */   lbu       $a0, 0x44($s0)
/* 2D50 80389140 A2000044 */  sb         $zero, 0x44($s0)
/* 2D54 80389144 8E040000 */  lw         $a0, ($s0)
/* 2D58 80389148 0C0E1DCA */  jal        func_80387728
/* 2D5C 8038914C 24050002 */   addiu     $a1, $zero, 2
/* 2D60 80389150 10000020 */  b          .L803891D4
/* 2D64 80389154 8FBF002C */   lw        $ra, 0x2c($sp)
/* 2D68 80389158 3C014270 */  lui        $at, 0x4270
/* 2D6C 8038915C 44818000 */  mtc1       $at, $f16
/* 2D70 80389160 C7A60054 */  lwc1       $f6, 0x54($sp)
/* 2D74 80389164 02002025 */  or         $a0, $s0, $zero
/* 2D78 80389168 AFA30058 */  sw         $v1, 0x58($sp)
/* 2D7C 8038916C 46068282 */  mul.s      $f10, $f16, $f6
/* 2D80 80389170 44055000 */  mfc1       $a1, $f10
/* 2D84 80389174 0C0E1EB3 */  jal        func_80387ACC
/* 2D88 80389178 00000000 */   nop
/* 2D8C 8038917C 02002025 */  or         $a0, $s0, $zero
/* 2D90 80389180 0C0E1AFB */  jal        func_80386BEC
/* 2D94 80389184 3C0541F0 */   lui       $a1, 0x41f0
/* 2D98 80389188 3C053F7F */  lui        $a1, 0x3f7f
/* 2D9C 8038918C 34A5F972 */  ori        $a1, $a1, 0xf972
/* 2DA0 80389190 0C0CA21B */  jal        actor_animationIsAt
/* 2DA4 80389194 02002025 */   or        $a0, $s0, $zero
/* 2DA8 80389198 1040000D */  beqz       $v0, .L803891D0
/* 2DAC 8038919C 8FA30058 */   lw        $v1, 0x58($sp)
/* 2DB0 803891A0 90690001 */  lbu        $t1, 1($v1)
/* 2DB4 803891A4 2405000B */  addiu      $a1, $zero, 0xb
/* 2DB8 803891A8 02002025 */  or         $a0, $s0, $zero
/* 2DBC 803891AC 29210004 */  slti       $at, $t1, 4
/* 2DC0 803891B0 14200005 */  bnez       $at, .L803891C8
/* 2DC4 803891B4 00000000 */   nop
/* 2DC8 803891B8 0C0E2061 */  jal        func_80388184
/* 2DCC 803891BC 02002025 */   or        $a0, $s0, $zero
/* 2DD0 803891C0 10000004 */  b          .L803891D4
/* 2DD4 803891C4 8FBF002C */   lw        $ra, 0x2c($sp)
.L803891C8:
/* 2DD8 803891C8 0C0E2061 */  jal        func_80388184
/* 2DDC 803891CC 2405000A */   addiu     $a1, $zero, 0xa
.L803891D0:
/* 2DE0 803891D0 8FBF002C */  lw         $ra, 0x2c($sp)
.L803891D4:
/* 2DE4 803891D4 8FB00028 */  lw         $s0, 0x28($sp)
/* 2DE8 803891D8 27BD0060 */  addiu      $sp, $sp, 0x60
/* 2DEC 803891DC 03E00008 */  jr         $ra
/* 2DF0 803891E0 00000000 */   nop
glabel func_803891E4
/* 2DF4 803891E4 27BDFFD0 */  addiu      $sp, $sp, -0x30
/* 2DF8 803891E8 AFBF001C */  sw         $ra, 0x1c($sp)
/* 2DFC 803891EC AFB00018 */  sw         $s0, 0x18($sp)
/* 2E00 803891F0 00808025 */  or         $s0, $a0, $zero
/* 2E04 803891F4 0C08F6D7 */  jal        func_8023DB5C
/* 2E08 803891F8 AFA50034 */   sw        $a1, 0x34($sp)
/* 2E0C 803891FC 8FA50034 */  lw         $a1, 0x34($sp)
/* 2E10 80389200 AFA20028 */  sw         $v0, 0x28($sp)
/* 2E14 80389204 2603007C */  addiu      $v1, $s0, 0x7c
/* 2E18 80389208 240E0002 */  addiu      $t6, $zero, 2
/* 2E1C 8038920C A06E0000 */  sb         $t6, ($v1)
/* 2E20 80389210 3C0638D1 */  lui        $a2, 0x38d1
/* 2E24 80389214 34C6B717 */  ori        $a2, $a2, 0xb717
/* 2E28 80389218 AFA30020 */  sw         $v1, 0x20($sp)
/* 2E2C 8038921C 02002025 */  or         $a0, $s0, $zero
/* 2E30 80389220 0C0CA2E3 */  jal        func_80328B8C
/* 2E34 80389224 24070001 */   addiu     $a3, $zero, 1
/* 2E38 80389228 0C0CA636 */  jal        actor_loopAnimation
/* 2E3C 8038922C 02002025 */   or        $a0, $s0, $zero
/* 2E40 80389230 8FA50034 */  lw         $a1, 0x34($sp)
/* 2E44 80389234 2401000E */  addiu      $at, $zero, 0xe
/* 2E48 80389238 8FA30020 */  lw         $v1, 0x20($sp)
/* 2E4C 8038923C 10A1000A */  beq        $a1, $at, .L80389268
/* 2E50 80389240 24010011 */   addiu     $at, $zero, 0x11
/* 2E54 80389244 10A1003D */  beq        $a1, $at, .L8038933C
/* 2E58 80389248 24040092 */   addiu     $a0, $zero, 0x92
/* 2E5C 8038924C 24010013 */  addiu      $at, $zero, 0x13
/* 2E60 80389250 10A1001E */  beq        $a1, $at, .L803892CC
/* 2E64 80389254 24010014 */   addiu     $at, $zero, 0x14
/* 2E68 80389258 10A1002F */  beq        $a1, $at, .L80389318
/* 2E6C 8038925C 3C047FFF */   lui       $a0, 0x7fff
/* 2E70 80389260 10000039 */  b          .L80389348
/* 2E74 80389264 8FBF001C */   lw        $ra, 0x1c($sp)
.L80389268:
/* 2E78 80389268 906F0001 */  lbu        $t7, 1($v1)
/* 2E7C 8038926C 2404000C */  addiu      $a0, $zero, 0xc
/* 2E80 80389270 3C028039 */  lui        $v0, %hi(D_803927D0)
/* 2E84 80389274 25F80008 */  addiu      $t8, $t7, 8
/* 2E88 80389278 331900FF */  andi       $t9, $t8, 0xff
/* 2E8C 8038927C 03240019 */  multu      $t9, $a0
/* 2E90 80389280 244227D0 */  addiu      $v0, $v0, %lo(D_803927D0)
/* 2E94 80389284 A0780005 */  sb         $t8, 5($v1)
/* 2E98 80389288 00004012 */  mflo       $t0
/* 2E9C 8038928C 00484821 */  addu       $t1, $v0, $t0
/* 2EA0 80389290 C5240000 */  lwc1       $f4, ($t1)
/* 2EA4 80389294 E604001C */  swc1       $f4, 0x1c($s0)
/* 2EA8 80389298 906A0005 */  lbu        $t2, 5($v1)
/* 2EAC 8038929C 01440019 */  multu      $t2, $a0
/* 2EB0 803892A0 00005812 */  mflo       $t3
/* 2EB4 803892A4 004B6021 */  addu       $t4, $v0, $t3
/* 2EB8 803892A8 C5860004 */  lwc1       $f6, 4($t4)
/* 2EBC 803892AC E6060020 */  swc1       $f6, 0x20($s0)
/* 2EC0 803892B0 906D0005 */  lbu        $t5, 5($v1)
/* 2EC4 803892B4 01A40019 */  multu      $t5, $a0
/* 2EC8 803892B8 00007012 */  mflo       $t6
/* 2ECC 803892BC 004E7821 */  addu       $t7, $v0, $t6
/* 2ED0 803892C0 C5E80008 */  lwc1       $f8, 8($t7)
/* 2ED4 803892C4 1000001F */  b          .L80389344
/* 2ED8 803892C8 E6080024 */   swc1      $f8, 0x24($s0)
.L803892CC:
/* 2EDC 803892CC 8FB80028 */  lw         $t8, 0x28($sp)
/* 2EE0 803892D0 33190001 */  andi       $t9, $t8, 1
/* 2EE4 803892D4 13200008 */  beqz       $t9, .L803892F8
/* 2EE8 803892D8 3C047FFF */   lui       $a0, 0x7fff
/* 2EEC 803892DC 3C062EE0 */  lui        $a2, 0x2ee0
/* 2EF0 803892E0 34C61B58 */  ori        $a2, $a2, 0x1b58
/* 2EF4 803892E4 34844132 */  ori        $a0, $a0, 0x4132
/* 2EF8 803892E8 0C0C3A2D */  jal        func_8030E8B4
/* 2EFC 803892EC 26050004 */   addiu     $a1, $s0, 4
/* 2F00 803892F0 10000015 */  b          .L80389348
/* 2F04 803892F4 8FBF001C */   lw        $ra, 0x1c($sp)
.L803892F8:
/* 2F08 803892F8 3C047FFF */  lui        $a0, 0x7fff
/* 2F0C 803892FC 3C062EE0 */  lui        $a2, 0x2ee0
/* 2F10 80389300 34C61B58 */  ori        $a2, $a2, 0x1b58
/* 2F14 80389304 34844133 */  ori        $a0, $a0, 0x4133
/* 2F18 80389308 0C0C3A2D */  jal        func_8030E8B4
/* 2F1C 8038930C 26050004 */   addiu     $a1, $s0, 4
/* 2F20 80389310 1000000D */  b          .L80389348
/* 2F24 80389314 8FBF001C */   lw        $ra, 0x1c($sp)
.L80389318:
/* 2F28 80389318 3C062EE0 */  lui        $a2, 0x2ee0
/* 2F2C 8038931C 34C61388 */  ori        $a2, $a2, 0x1388
/* 2F30 80389320 34844131 */  ori        $a0, $a0, 0x4131
/* 2F34 80389324 26050004 */  addiu      $a1, $s0, 4
/* 2F38 80389328 0C0C3A2D */  jal        func_8030E8B4
/* 2F3C 8038932C AFA30020 */   sw        $v1, 0x20($sp)
/* 2F40 80389330 8FA30020 */  lw         $v1, 0x20($sp)
/* 2F44 80389334 10000003 */  b          .L80389344
/* 2F48 80389338 A060000A */   sb        $zero, 0xa($v1)
.L8038933C:
/* 2F4C 8038933C 0C0969BB */  jal        func_8025A6EC
/* 2F50 80389340 24057530 */   addiu     $a1, $zero, 0x7530
.L80389344:
/* 2F54 80389344 8FBF001C */  lw         $ra, 0x1c($sp)
.L80389348:
/* 2F58 80389348 8FB00018 */  lw         $s0, 0x18($sp)
/* 2F5C 8038934C 27BD0030 */  addiu      $sp, $sp, 0x30
/* 2F60 80389350 03E00008 */  jr         $ra
/* 2F64 80389354 00000000 */   nop
glabel func_80389358
/* 2F68 80389358 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 2F6C 8038935C AFA40018 */  sw         $a0, 0x18($sp)
/* 2F70 80389360 AFBF0014 */  sw         $ra, 0x14($sp)
/* 2F74 80389364 AFA5001C */  sw         $a1, 0x1c($sp)
/* 2F78 80389368 3C048038 */  lui        $a0, %hi(func_80386E5C)
/* 2F7C 8038936C AFA60020 */  sw         $a2, 0x20($sp)
/* 2F80 80389370 24846E5C */  addiu      $a0, $a0, %lo(func_80386E5C)
/* 2F84 80389374 0C0B0F22 */  jal        func_802C3C88
/* 2F88 80389378 8FA50018 */   lw        $a1, 0x18($sp)
/* 2F8C 8038937C 8FBF0014 */  lw         $ra, 0x14($sp)
/* 2F90 80389380 27BD0018 */  addiu      $sp, $sp, 0x18
/* 2F94 80389384 03E00008 */  jr         $ra
/* 2F98 80389388 00000000 */   nop
glabel func_8038938C
/* 2F9C 8038938C 27BDFFA8 */  addiu      $sp, $sp, -0x58
/* 2FA0 80389390 AFBF002C */  sw         $ra, 0x2c($sp)
/* 2FA4 80389394 0C0CA656 */  jal        marker_getActor
/* 2FA8 80389398 AFB00028 */   sw        $s0, 0x28($sp)
/* 2FAC 8038939C 244E007C */  addiu      $t6, $v0, 0x7c
/* 2FB0 803893A0 00408025 */  or         $s0, $v0, $zero
/* 2FB4 803893A4 0C0CF767 */  jal        time_getDelta
/* 2FB8 803893A8 AFAE0050 */   sw        $t6, 0x50($sp)
/* 2FBC 803893AC 8FAF0050 */  lw         $t7, 0x50($sp)
/* 2FC0 803893B0 46000086 */  mov.s      $f2, $f0
/* 2FC4 803893B4 91F80001 */  lbu        $t8, 1($t7)
/* 2FC8 803893B8 AFB80048 */  sw         $t8, 0x48($sp)
/* 2FCC 803893BC 8E190010 */  lw         $t9, 0x10($s0)
/* 2FD0 803893C0 00194682 */  srl        $t0, $t9, 0x1a
/* 2FD4 803893C4 2509FFF2 */  addiu      $t1, $t0, -0xe
/* 2FD8 803893C8 2D210007 */  sltiu      $at, $t1, 7
/* 2FDC 803893CC 102000CF */  beqz       $at, .L8038970C
/* 2FE0 803893D0 00094880 */   sll       $t1, $t1, 2
/* 2FE4 803893D4 3C018039 */  lui        $at, %hi(D_80392218)
/* 2FE8 803893D8 00290821 */  addu       $at, $at, $t1
/* 2FEC 803893DC 8C292218 */  lw         $t1, %lo(D_80392218)($at)
/* 2FF0 803893E0 01200008 */  jr         $t1
/* 2FF4 803893E4 00000000 */   nop
/* 2FF8 803893E8 02002025 */  or         $a0, $s0, $zero
/* 2FFC 803893EC 0C0E1A6F */  jal        func_803869BC
/* 3000 803893F0 E7A2004C */   swc1      $f2, 0x4c($sp)
/* 3004 803893F4 3C0141F0 */  lui        $at, 0x41f0
/* 3008 803893F8 C7A2004C */  lwc1       $f2, 0x4c($sp)
/* 300C 803893FC 44812000 */  mtc1       $at, $f4
/* 3010 80389400 02002025 */  or         $a0, $s0, $zero
/* 3014 80389404 46022182 */  mul.s      $f6, $f4, $f2
/* 3018 80389408 44053000 */  mfc1       $a1, $f6
/* 301C 8038940C 0C0E1EB3 */  jal        func_80387ACC
/* 3020 80389410 00000000 */   nop
/* 3024 80389414 2605001C */  addiu      $a1, $s0, 0x1c
/* 3028 80389418 AFA50038 */  sw         $a1, 0x38($sp)
/* 302C 8038941C 0C095819 */  jal        ml_vec3f_distance
/* 3030 80389420 26040004 */   addiu     $a0, $s0, 4
/* 3034 80389424 8FAA0048 */  lw         $t2, 0x48($sp)
/* 3038 80389428 3C0C8039 */  lui        $t4, %hi(D_80391758)
/* 303C 8038942C 258C1758 */  addiu      $t4, $t4, %lo(D_80391758)
/* 3040 80389430 000A5880 */  sll        $t3, $t2, 2
/* 3044 80389434 016C1021 */  addu       $v0, $t3, $t4
/* 3048 80389438 C4480000 */  lwc1       $f8, ($v0)
/* 304C 8038943C 3C01428C */  lui        $at, 0x428c
/* 3050 80389440 44817000 */  mtc1       $at, $f14
/* 3054 80389444 AFA20034 */  sw         $v0, 0x34($sp)
/* 3058 80389448 46000306 */  mov.s      $f12, $f0
/* 305C 8038944C 3C06447A */  lui        $a2, 0x447a
/* 3060 80389450 3C0742C8 */  lui        $a3, 0x42c8
/* 3064 80389454 0C095EC6 */  jal        ml_map_f
/* 3068 80389458 E7A80010 */   swc1      $f8, 0x10($sp)
/* 306C 8038945C 8FA20034 */  lw         $v0, 0x34($sp)
/* 3070 80389460 3C014000 */  lui        $at, 0x4000
/* 3074 80389464 44818000 */  mtc1       $at, $f16
/* 3078 80389468 C44A0000 */  lwc1       $f10, ($v0)
/* 307C 8038946C 3C014320 */  lui        $at, 0x4320
/* 3080 80389470 44812000 */  mtc1       $at, $f4
/* 3084 80389474 46105482 */  mul.s      $f18, $f10, $f16
/* 3088 80389478 3C0143FA */  lui        $at, 0x43fa
/* 308C 8038947C 44813000 */  mtc1       $at, $f6
/* 3090 80389480 3C01428C */  lui        $at, 0x428c
/* 3094 80389484 44814000 */  mtc1       $at, $f8
/* 3098 80389488 44060000 */  mfc1       $a2, $f0
/* 309C 8038948C 02002025 */  or         $a0, $s0, $zero
/* 30A0 80389490 44079000 */  mfc1       $a3, $f18
/* 30A4 80389494 8FA50038 */  lw         $a1, 0x38($sp)
/* 30A8 80389498 E7A40010 */  swc1       $f4, 0x10($sp)
/* 30AC 8038949C E7A60014 */  swc1       $f6, 0x14($sp)
/* 30B0 803894A0 0C0E1D1C */  jal        func_80387470
/* 30B4 803894A4 E7A80018 */   swc1      $f8, 0x18($sp)
/* 30B8 803894A8 10400098 */  beqz       $v0, .L8038970C
/* 30BC 803894AC 240D0001 */   addiu     $t5, $zero, 1
/* 30C0 803894B0 8FAE0050 */  lw         $t6, 0x50($sp)
/* 30C4 803894B4 02002025 */  or         $a0, $s0, $zero
/* 30C8 803894B8 2405000F */  addiu      $a1, $zero, 0xf
/* 30CC 803894BC 0C0E2479 */  jal        func_803891E4
/* 30D0 803894C0 A1CD000A */   sb        $t5, 0xa($t6)
/* 30D4 803894C4 10000092 */  b          .L80389710
/* 30D8 803894C8 8FBF002C */   lw        $ra, 0x2c($sp)
/* 30DC 803894CC 02002025 */  or         $a0, $s0, $zero
/* 30E0 803894D0 0C0E1AFB */  jal        func_80386BEC
/* 30E4 803894D4 3C054110 */   lui       $a1, 0x4110
/* 30E8 803894D8 1040008C */  beqz       $v0, .L8038970C
/* 30EC 803894DC 02002025 */   or        $a0, $s0, $zero
/* 30F0 803894E0 0C0E2479 */  jal        func_803891E4
/* 30F4 803894E4 24050010 */   addiu     $a1, $zero, 0x10
/* 30F8 803894E8 10000089 */  b          .L80389710
/* 30FC 803894EC 8FBF002C */   lw        $ra, 0x2c($sp)
/* 3100 803894F0 02002025 */  or         $a0, $s0, $zero
/* 3104 803894F4 0C0E1AFB */  jal        func_80386BEC
/* 3108 803894F8 3C054040 */   lui       $a1, 0x4040
/* 310C 803894FC 3C053FA6 */  lui        $a1, 0x3fa6
/* 3110 80389500 34A56666 */  ori        $a1, $a1, 0x6666
/* 3114 80389504 0C0E1CD0 */  jal        func_80387340
/* 3118 80389508 02002025 */   or        $a0, $s0, $zero
/* 311C 8038950C 3C053F7F */  lui        $a1, 0x3f7f
/* 3120 80389510 34A5F972 */  ori        $a1, $a1, 0xf972
/* 3124 80389514 0C0CA21B */  jal        actor_animationIsAt
/* 3128 80389518 02002025 */   or        $a0, $s0, $zero
/* 312C 8038951C 1040007B */  beqz       $v0, .L8038970C
/* 3130 80389520 02002025 */   or        $a0, $s0, $zero
/* 3134 80389524 0C0E2479 */  jal        func_803891E4
/* 3138 80389528 24050012 */   addiu     $a1, $zero, 0x12
/* 313C 8038952C 8FA20050 */  lw         $v0, 0x50($sp)
/* 3140 80389530 904F0003 */  lbu        $t7, 3($v0)
/* 3144 80389534 25F80001 */  addiu      $t8, $t7, 1
/* 3148 80389538 331900FF */  andi       $t9, $t8, 0xff
/* 314C 8038953C 2B210004 */  slti       $at, $t9, 4
/* 3150 80389540 1420000D */  bnez       $at, .L80389578
/* 3154 80389544 A0580003 */   sb        $t8, 3($v0)
/* 3158 80389548 A0400003 */  sb         $zero, 3($v0)
/* 315C 8038954C 8FA80048 */  lw         $t0, 0x48($sp)
/* 3160 80389550 3C018039 */  lui        $at, %hi(D_80391748)
/* 3164 80389554 00084880 */  sll        $t1, $t0, 2
/* 3168 80389558 00290821 */  addu       $at, $at, $t1
/* 316C 8038955C C42A1748 */  lwc1       $f10, %lo(D_80391748)($at)
/* 3170 80389560 3C014040 */  lui        $at, 0x4040
/* 3174 80389564 44818000 */  mtc1       $at, $f16
/* 3178 80389568 00000000 */  nop
/* 317C 8038956C 46105482 */  mul.s      $f18, $f10, $f16
/* 3180 80389570 10000066 */  b          .L8038970C
/* 3184 80389574 E6120060 */   swc1      $f18, 0x60($s0)
.L80389578:
/* 3188 80389578 8FAA0048 */  lw         $t2, 0x48($sp)
/* 318C 8038957C 3C018039 */  lui        $at, %hi(D_80391748)
/* 3190 80389580 000A5880 */  sll        $t3, $t2, 2
/* 3194 80389584 002B0821 */  addu       $at, $at, $t3
/* 3198 80389588 C4241748 */  lwc1       $f4, %lo(D_80391748)($at)
/* 319C 8038958C 1000005F */  b          .L8038970C
/* 31A0 80389590 E6040060 */   swc1      $f4, 0x60($s0)
/* 31A4 80389594 02002025 */  or         $a0, $s0, $zero
/* 31A8 80389598 0C0E1AFB */  jal        func_80386BEC
/* 31AC 8038959C 3C054040 */   lui       $a1, 0x4040
/* 31B0 803895A0 02002025 */  or         $a0, $s0, $zero
/* 31B4 803895A4 3C054496 */  lui        $a1, 0x4496
/* 31B8 803895A8 0C0E1CF7 */  jal        func_803873DC
/* 31BC 803895AC 3C064516 */   lui       $a2, 0x4516
/* 31C0 803895B0 3C053F7F */  lui        $a1, 0x3f7f
/* 31C4 803895B4 34A5F972 */  ori        $a1, $a1, 0xf972
/* 31C8 803895B8 0C0CA21B */  jal        actor_animationIsAt
/* 31CC 803895BC 02002025 */   or        $a0, $s0, $zero
/* 31D0 803895C0 10400052 */  beqz       $v0, .L8038970C
/* 31D4 803895C4 24050003 */   addiu     $a1, $zero, 3
/* 31D8 803895C8 0C0E1DCA */  jal        func_80387728
/* 31DC 803895CC 8E040000 */   lw        $a0, ($s0)
/* 31E0 803895D0 1000004F */  b          .L80389710
/* 31E4 803895D4 8FBF002C */   lw        $ra, 0x2c($sp)
/* 31E8 803895D8 02002025 */  or         $a0, $s0, $zero
/* 31EC 803895DC 3C054040 */  lui        $a1, 0x4040
/* 31F0 803895E0 0C0E1AFB */  jal        func_80386BEC
/* 31F4 803895E4 E7A2004C */   swc1      $f2, 0x4c($sp)
/* 31F8 803895E8 C6000060 */  lwc1       $f0, 0x60($s0)
/* 31FC 803895EC 44803800 */  mtc1       $zero, $f7
/* 3200 803895F0 44803000 */  mtc1       $zero, $f6
/* 3204 803895F4 46000221 */  cvt.d.s    $f8, $f0
/* 3208 803895F8 C7A2004C */  lwc1       $f2, 0x4c($sp)
/* 320C 803895FC 4628303C */  c.lt.d     $f6, $f8
/* 3210 80389600 02002025 */  or         $a0, $s0, $zero
/* 3214 80389604 45000004 */  bc1f       .L80389618
/* 3218 80389608 00000000 */   nop
/* 321C 8038960C 46020281 */  sub.s      $f10, $f0, $f2
/* 3220 80389610 1000003E */  b          .L8038970C
/* 3224 80389614 E60A0060 */   swc1      $f10, 0x60($s0)
.L80389618:
/* 3228 80389618 0C0E1AFB */  jal        func_80386BEC
/* 322C 8038961C 3C054040 */   lui       $a1, 0x4040
/* 3230 80389620 1040003A */  beqz       $v0, .L8038970C
/* 3234 80389624 02002025 */   or        $a0, $s0, $zero
/* 3238 80389628 0C0E2479 */  jal        func_803891E4
/* 323C 8038962C 24050010 */   addiu     $a1, $zero, 0x10
/* 3240 80389630 10000037 */  b          .L80389710
/* 3244 80389634 8FBF002C */   lw        $ra, 0x2c($sp)
/* 3248 80389638 3C053F7F */  lui        $a1, 0x3f7f
/* 324C 8038963C 34A5F972 */  ori        $a1, $a1, 0xf972
/* 3250 80389640 0C0CA21B */  jal        actor_animationIsAt
/* 3254 80389644 02002025 */   or        $a0, $s0, $zero
/* 3258 80389648 10400030 */  beqz       $v0, .L8038970C
/* 325C 8038964C 02002025 */   or        $a0, $s0, $zero
/* 3260 80389650 0C0E2479 */  jal        func_803891E4
/* 3264 80389654 2405000E */   addiu     $a1, $zero, 0xe
/* 3268 80389658 1000002D */  b          .L80389710
/* 326C 8038965C 8FBF002C */   lw        $ra, 0x2c($sp)
/* 3270 80389660 3C053F7F */  lui        $a1, 0x3f7f
/* 3274 80389664 34A5F972 */  ori        $a1, $a1, 0xf972
/* 3278 80389668 0C0CA21B */  jal        actor_animationIsAt
/* 327C 8038966C 02002025 */   or        $a0, $s0, $zero
/* 3280 80389670 10400026 */  beqz       $v0, .L8038970C
/* 3284 80389674 8FAC0050 */   lw        $t4, 0x50($sp)
/* 3288 80389678 918D0001 */  lbu        $t5, 1($t4)
/* 328C 8038967C 24050005 */  addiu      $a1, $zero, 5
/* 3290 80389680 02002025 */  or         $a0, $s0, $zero
/* 3294 80389684 29A10004 */  slti       $at, $t5, 4
/* 3298 80389688 1420001B */  bnez       $at, .L803896F8
/* 329C 8038968C 00000000 */   nop
/* 32A0 80389690 0C0D29EF */  jal        randi2
/* 32A4 80389694 00002025 */   or        $a0, $zero, $zero
/* 32A8 80389698 24441115 */  addiu      $a0, $v0, 0x1115
/* 32AC 8038969C 24050020 */  addiu      $a1, $zero, 0x20
/* 32B0 803896A0 00003025 */  or         $a2, $zero, $zero
/* 32B4 803896A4 00003825 */  or         $a3, $zero, $zero
/* 32B8 803896A8 AFA00010 */  sw         $zero, 0x10($sp)
/* 32BC 803896AC 0C0C4520 */  jal        func_80311480
/* 32C0 803896B0 AFA00014 */   sw        $zero, 0x14($sp)
/* 32C4 803896B4 00002025 */  or         $a0, $zero, $zero
/* 32C8 803896B8 0C0D29EF */  jal        randi2
/* 32CC 803896BC 24050003 */   addiu     $a1, $zero, 3
/* 32D0 803896C0 3C0E8039 */  lui        $t6, %hi(func_80389358)
/* 32D4 803896C4 25CE9358 */  addiu      $t6, $t6, %lo(func_80389358)
/* 32D8 803896C8 8E070000 */  lw         $a3, ($s0)
/* 32DC 803896CC AFAE0014 */  sw         $t6, 0x14($sp)
/* 32E0 803896D0 AFA00010 */  sw         $zero, 0x10($sp)
/* 32E4 803896D4 2444111A */  addiu      $a0, $v0, 0x111a
/* 32E8 803896D8 24050004 */  addiu      $a1, $zero, 4
/* 32EC 803896DC 0C0C4520 */  jal        func_80311480
/* 32F0 803896E0 00003025 */   or        $a2, $zero, $zero
/* 32F4 803896E4 02002025 */  or         $a0, $s0, $zero
/* 32F8 803896E8 0C0E2479 */  jal        func_803891E4
/* 32FC 803896EC 24050011 */   addiu     $a1, $zero, 0x11
/* 3300 803896F0 10000007 */  b          .L80389710
/* 3304 803896F4 8FBF002C */   lw        $ra, 0x2c($sp)
.L803896F8:
/* 3308 803896F8 0C0E2479 */  jal        func_803891E4
/* 330C 803896FC 2405000E */   addiu     $a1, $zero, 0xe
/* 3310 80389700 02002025 */  or         $a0, $s0, $zero
/* 3314 80389704 0C0E2028 */  jal        func_803880A0
/* 3318 80389708 3C0544FA */   lui       $a1, 0x44fa
.L8038970C:
/* 331C 8038970C 8FBF002C */  lw         $ra, 0x2c($sp)
.L80389710:
/* 3320 80389710 8FB00028 */  lw         $s0, 0x28($sp)
/* 3324 80389714 27BD0058 */  addiu      $sp, $sp, 0x58
/* 3328 80389718 03E00008 */  jr         $ra
/* 332C 8038971C 00000000 */   nop
glabel func_80389720
/* 3330 80389720 27BDFFD8 */  addiu      $sp, $sp, -0x28
/* 3334 80389724 AFBF0014 */  sw         $ra, 0x14($sp)
/* 3338 80389728 AFA40028 */  sw         $a0, 0x28($sp)
/* 333C 8038972C 0C0C9BBB */  jal        func_80326EEC
/* 3340 80389730 2404038B */   addiu     $a0, $zero, 0x38b
/* 3344 80389734 8FA70028 */  lw         $a3, 0x28($sp)
/* 3348 80389738 24EEFFFF */  addiu      $t6, $a3, -1
/* 334C 8038973C 2DC10005 */  sltiu      $at, $t6, 5
/* 3350 80389740 10200045 */  beqz       $at, .L80389858
/* 3354 80389744 000E7080 */   sll       $t6, $t6, 2
/* 3358 80389748 3C018039 */  lui        $at, %hi(D_80392234)
/* 335C 8038974C 002E0821 */  addu       $at, $at, $t6
/* 3360 80389750 8C2E2234 */  lw         $t6, %lo(D_80392234)($at)
/* 3364 80389754 01C00008 */  jr         $t6
/* 3368 80389758 00000000 */   nop
/* 336C 8038975C 3C058039 */  lui        $a1, %hi(D_80391768)
/* 3370 80389760 24A51768 */  addiu      $a1, $a1, %lo(D_80391768)
/* 3374 80389764 240403A2 */  addiu      $a0, $zero, 0x3a2
/* 3378 80389768 0C0CA04F */  jal        func_8032813C
/* 337C 8038976C 24060087 */   addiu     $a2, $zero, 0x87
/* 3380 80389770 8C4F0000 */  lw         $t7, ($v0)
/* 3384 80389774 3C018039 */  lui        $at, %hi(D_803927B0)
/* 3388 80389778 AFA2001C */  sw         $v0, 0x1c($sp)
/* 338C 8038977C 8FA70028 */  lw         $a3, 0x28($sp)
/* 3390 80389780 10000035 */  b          .L80389858
/* 3394 80389784 AC2F27B0 */   sw        $t7, %lo(D_803927B0)($at)
/* 3398 80389788 3C058039 */  lui        $a1, %hi(D_80391774)
/* 339C 8038978C 24A51774 */  addiu      $a1, $a1, %lo(D_80391774)
/* 33A0 80389790 240403A2 */  addiu      $a0, $zero, 0x3a2
/* 33A4 80389794 0C0CA04F */  jal        func_8032813C
/* 33A8 80389798 2406002D */   addiu     $a2, $zero, 0x2d
/* 33AC 8038979C 8C580000 */  lw         $t8, ($v0)
/* 33B0 803897A0 3C018039 */  lui        $at, %hi(D_803927B4)
/* 33B4 803897A4 AFA2001C */  sw         $v0, 0x1c($sp)
/* 33B8 803897A8 8FA70028 */  lw         $a3, 0x28($sp)
/* 33BC 803897AC 1000002A */  b          .L80389858
/* 33C0 803897B0 AC3827B4 */   sw        $t8, %lo(D_803927B4)($at)
/* 33C4 803897B4 3C058039 */  lui        $a1, %hi(D_80391780)
/* 33C8 803897B8 24A51780 */  addiu      $a1, $a1, %lo(D_80391780)
/* 33CC 803897BC 240403A2 */  addiu      $a0, $zero, 0x3a2
/* 33D0 803897C0 0C0CA04F */  jal        func_8032813C
/* 33D4 803897C4 2406013B */   addiu     $a2, $zero, 0x13b
/* 33D8 803897C8 8C590000 */  lw         $t9, ($v0)
/* 33DC 803897CC 3C018039 */  lui        $at, %hi(D_803927B8)
/* 33E0 803897D0 AFA2001C */  sw         $v0, 0x1c($sp)
/* 33E4 803897D4 8FA70028 */  lw         $a3, 0x28($sp)
/* 33E8 803897D8 1000001F */  b          .L80389858
/* 33EC 803897DC AC3927B8 */   sw        $t9, %lo(D_803927B8)($at)
/* 33F0 803897E0 3C058039 */  lui        $a1, %hi(D_8039178C)
/* 33F4 803897E4 24A5178C */  addiu      $a1, $a1, %lo(D_8039178C)
/* 33F8 803897E8 240403A2 */  addiu      $a0, $zero, 0x3a2
/* 33FC 803897EC 0C0CA04F */  jal        func_8032813C
/* 3400 803897F0 240600E1 */   addiu     $a2, $zero, 0xe1
/* 3404 803897F4 8C480000 */  lw         $t0, ($v0)
/* 3408 803897F8 3C018039 */  lui        $at, %hi(D_803927BC)
/* 340C 803897FC AFA2001C */  sw         $v0, 0x1c($sp)
/* 3410 80389800 8FA70028 */  lw         $a3, 0x28($sp)
/* 3414 80389804 10000014 */  b          .L80389858
/* 3418 80389808 AC2827BC */   sw        $t0, %lo(D_803927BC)($at)
/* 341C 8038980C 90490083 */  lbu        $t1, 0x83($v0)
/* 3420 80389810 3C014334 */  lui        $at, 0x4334
/* 3424 80389814 240403A9 */  addiu      $a0, $zero, 0x3a9
/* 3428 80389818 51200005 */  beql       $t1, $zero, .L80389830
/* 342C 8038981C 44810000 */   mtc1      $at, $f0
/* 3430 80389820 44800000 */  mtc1       $zero, $f0
/* 3434 80389824 10000004 */  b          .L80389838
/* 3438 80389828 4600010D */   trunc.w.s $f4, $f0
/* 343C 8038982C 44810000 */  mtc1       $at, $f0
.L80389830:
/* 3440 80389830 00000000 */  nop
/* 3444 80389834 4600010D */  trunc.w.s  $f4, $f0
.L80389838:
/* 3448 80389838 3C058039 */  lui        $a1, %hi(D_80391798)
/* 344C 8038983C 3C018039 */  lui        $at, %hi(D_80392750)
/* 3450 80389840 E4202750 */  swc1       $f0, %lo(D_80392750)($at)
/* 3454 80389844 44062000 */  mfc1       $a2, $f4
/* 3458 80389848 0C0CA04F */  jal        func_8032813C
/* 345C 8038984C 24A51798 */   addiu     $a1, $a1, %lo(D_80391798)
/* 3460 80389850 AFA2001C */  sw         $v0, 0x1c($sp)
/* 3464 80389854 8FA70028 */  lw         $a3, 0x28($sp)
.L80389858:
/* 3468 80389858 24010005 */  addiu      $at, $zero, 5
/* 346C 8038985C 14E10005 */  bne        $a3, $at, .L80389874
/* 3470 80389860 8FA3001C */   lw        $v1, 0x1c($sp)
/* 3474 80389864 3C0140A8 */  lui        $at, 0x40a8
/* 3478 80389868 44813000 */  mtc1       $at, $f6
/* 347C 8038986C 10000004 */  b          .L80389880
/* 3480 80389870 E4660060 */   swc1      $f6, 0x60($v1)
.L80389874:
/* 3484 80389874 3C018039 */  lui        $at, %hi(D_80392248)
/* 3488 80389878 C4282248 */  lwc1       $f8, %lo(D_80392248)($at)
/* 348C 8038987C E4680060 */  swc1       $f8, 0x60($v1)
.L80389880:
/* 3490 80389880 946D00F6 */  lhu        $t5, 0xf6($v1)
/* 3494 80389884 30EC01FF */  andi       $t4, $a3, 0x1ff
/* 3498 80389888 31AEFE00 */  andi       $t6, $t5, 0xfe00
/* 349C 8038988C 018E7825 */  or         $t7, $t4, $t6
/* 34A0 80389890 A46F00F6 */  sh         $t7, 0xf6($v1)
/* 34A4 80389894 8FBF0014 */  lw         $ra, 0x14($sp)
/* 34A8 80389898 27BD0028 */  addiu      $sp, $sp, 0x28
/* 34AC 8038989C 03E00008 */  jr         $ra
/* 34B0 803898A0 00000000 */   nop
glabel func_803898A4
/* 34B4 803898A4 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 34B8 803898A8 AFA40018 */  sw         $a0, 0x18($sp)
/* 34BC 803898AC AFBF0014 */  sw         $ra, 0x14($sp)
/* 34C0 803898B0 3C048039 */  lui        $a0, %hi(func_80389720)
/* 34C4 803898B4 24849720 */  addiu      $a0, $a0, %lo(func_80389720)
/* 34C8 803898B8 0C0B0F22 */  jal        func_802C3C88
/* 34CC 803898BC 8FA50018 */   lw        $a1, 0x18($sp)
/* 34D0 803898C0 8FBF0014 */  lw         $ra, 0x14($sp)
/* 34D4 803898C4 27BD0018 */  addiu      $sp, $sp, 0x18
/* 34D8 803898C8 03E00008 */  jr         $ra
/* 34DC 803898CC 00000000 */   nop
glabel func_803898D0
/* 34E0 803898D0 27BDFFE0 */  addiu      $sp, $sp, -0x20
/* 34E4 803898D4 AFBF0014 */  sw         $ra, 0x14($sp)
/* 34E8 803898D8 0C0CA656 */  jal        marker_getActor
/* 34EC 803898DC 00000000 */   nop
/* 34F0 803898E0 AFA2001C */  sw         $v0, 0x1c($sp)
/* 34F4 803898E4 240403AB */  addiu      $a0, $zero, 0x3ab
/* 34F8 803898E8 0C0CA063 */  jal        spawn_child_actor
/* 34FC 803898EC 27A5001C */   addiu     $a1, $sp, 0x1c
/* 3500 803898F0 8C4E0000 */  lw         $t6, ($v0)
/* 3504 803898F4 8FAF001C */  lw         $t7, 0x1c($sp)
/* 3508 803898F8 24180001 */  addiu      $t8, $zero, 1
/* 350C 803898FC 3C018039 */  lui        $at, %hi(D_803927C5)
/* 3510 80389900 ADEE0100 */  sw         $t6, 0x100($t7)
/* 3514 80389904 8FBF0014 */  lw         $ra, 0x14($sp)
/* 3518 80389908 A03827C5 */  sb         $t8, %lo(D_803927C5)($at)
/* 351C 8038990C 27BD0020 */  addiu      $sp, $sp, 0x20
/* 3520 80389910 03E00008 */  jr         $ra
/* 3524 80389914 00000000 */   nop
glabel func_80389918
/* 3528 80389918 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 352C 8038991C AFA40018 */  sw         $a0, 0x18($sp)
/* 3530 80389920 AFBF0014 */  sw         $ra, 0x14($sp)
/* 3534 80389924 3C048039 */  lui        $a0, %hi(func_803898D0)
/* 3538 80389928 248498D0 */  addiu      $a0, $a0, %lo(func_803898D0)
/* 353C 8038992C 0C0B0F22 */  jal        func_802C3C88
/* 3540 80389930 8FA50018 */   lw        $a1, 0x18($sp)
/* 3544 80389934 8FBF0014 */  lw         $ra, 0x14($sp)
/* 3548 80389938 27BD0018 */  addiu      $sp, $sp, 0x18
/* 354C 8038993C 03E00008 */  jr         $ra
/* 3550 80389940 00000000 */   nop
glabel func_80389944
/* 3554 80389944 27BDFFE0 */  addiu      $sp, $sp, -0x20
/* 3558 80389948 AFBF0014 */  sw         $ra, 0x14($sp)
/* 355C 8038994C AFA50024 */  sw         $a1, 0x24($sp)
/* 3560 80389950 0C0CA656 */  jal        marker_getActor
/* 3564 80389954 AFA60028 */   sw        $a2, 0x28($sp)
/* 3568 80389958 0C0AEB93 */  jal        func_802BAE4C
/* 356C 8038995C AFA2001C */   sw        $v0, 0x1c($sp)
/* 3570 80389960 44806000 */  mtc1       $zero, $f12
/* 3574 80389964 0C0C938E */  jal        func_80324E38
/* 3578 80389968 00002825 */   or        $a1, $zero, $zero
/* 357C 8038996C 8FAE001C */  lw         $t6, 0x1c($sp)
/* 3580 80389970 24050004 */  addiu      $a1, $zero, 4
/* 3584 80389974 0C0E1DCA */  jal        func_80387728
/* 3588 80389978 8DC40000 */   lw        $a0, ($t6)
/* 358C 8038997C 8FBF0014 */  lw         $ra, 0x14($sp)
/* 3590 80389980 27BD0020 */  addiu      $sp, $sp, 0x20
/* 3594 80389984 03E00008 */  jr         $ra
/* 3598 80389988 00000000 */   nop
glabel func_8038998C
/* 359C 8038998C 27BDFFC0 */  addiu      $sp, $sp, -0x40
/* 35A0 80389990 AFBF003C */  sw         $ra, 0x3c($sp)
/* 35A4 80389994 AFB20038 */  sw         $s2, 0x38($sp)
/* 35A8 80389998 AFB10034 */  sw         $s1, 0x34($sp)
/* 35AC 8038999C AFB00030 */  sw         $s0, 0x30($sp)
/* 35B0 803899A0 F7B60028 */  sdc1       $f22, 0x28($sp)
/* 35B4 803899A4 F7B40020 */  sdc1       $f20, 0x20($sp)
/* 35B8 803899A8 240E0003 */  addiu      $t6, $zero, 3
/* 35BC 803899AC 3C0638D1 */  lui        $a2, 0x38d1
/* 35C0 803899B0 00A08025 */  or         $s0, $a1, $zero
/* 35C4 803899B4 00809025 */  or         $s2, $a0, $zero
/* 35C8 803899B8 A08E007C */  sb         $t6, 0x7c($a0)
/* 35CC 803899BC 34C6B717 */  ori        $a2, $a2, 0xb717
/* 35D0 803899C0 0C0CA2E3 */  jal        func_80328B8C
/* 35D4 803899C4 24070001 */   addiu     $a3, $zero, 1
/* 35D8 803899C8 24010015 */  addiu      $at, $zero, 0x15
/* 35DC 803899CC 1201000B */  beq        $s0, $at, .L803899FC
/* 35E0 803899D0 2642007C */   addiu     $v0, $s2, 0x7c
/* 35E4 803899D4 24010018 */  addiu      $at, $zero, 0x18
/* 35E8 803899D8 12010038 */  beq        $s0, $at, .L80389ABC
/* 35EC 803899DC 24010019 */   addiu     $at, $zero, 0x19
/* 35F0 803899E0 12010038 */  beq        $s0, $at, .L80389AC4
/* 35F4 803899E4 3C047FFF */   lui       $a0, 0x7fff
/* 35F8 803899E8 2401001A */  addiu      $at, $zero, 0x1a
/* 35FC 803899EC 1201003C */  beq        $s0, $at, .L80389AE0
/* 3600 803899F0 00000000 */   nop
/* 3604 803899F4 1000004C */  b          .L80389B28
/* 3608 803899F8 8FBF003C */   lw        $ra, 0x3c($sp)
.L803899FC:
/* 360C 803899FC 90430005 */  lbu        $v1, 5($v0)
/* 3610 80389A00 2404000C */  addiu      $a0, $zero, 0xc
/* 3614 80389A04 246F0001 */  addiu      $t7, $v1, 1
/* 3618 80389A08 29E10010 */  slti       $at, $t7, 0x10
/* 361C 80389A0C 10200004 */  beqz       $at, .L80389A20
/* 3620 80389A10 24780001 */   addiu     $t8, $v1, 1
/* 3624 80389A14 A0580005 */  sb         $t8, 5($v0)
/* 3628 80389A18 10000002 */  b          .L80389A24
/* 362C 80389A1C 2404000C */   addiu     $a0, $zero, 0xc
.L80389A20:
/* 3630 80389A20 A0440005 */  sb         $a0, 5($v0)
.L80389A24:
/* 3634 80389A24 90590005 */  lbu        $t9, 5($v0)
/* 3638 80389A28 3C038039 */  lui        $v1, %hi(D_803927D0)
/* 363C 80389A2C 246327D0 */  addiu      $v1, $v1, %lo(D_803927D0)
/* 3640 80389A30 03240019 */  multu      $t9, $a0
/* 3644 80389A34 3C0142F0 */  lui        $at, 0x42f0
/* 3648 80389A38 4481B000 */  mtc1       $at, $f22
/* 364C 80389A3C 3C01C2F0 */  lui        $at, 0xc2f0
/* 3650 80389A40 02408025 */  or         $s0, $s2, $zero
/* 3654 80389A44 4481A000 */  mtc1       $at, $f20
/* 3658 80389A48 00008825 */  or         $s1, $zero, $zero
/* 365C 80389A4C 00004012 */  mflo       $t0
/* 3660 80389A50 00684821 */  addu       $t1, $v1, $t0
/* 3664 80389A54 C5240000 */  lwc1       $f4, ($t1)
/* 3668 80389A58 E644001C */  swc1       $f4, 0x1c($s2)
/* 366C 80389A5C 904A0005 */  lbu        $t2, 5($v0)
/* 3670 80389A60 01440019 */  multu      $t2, $a0
/* 3674 80389A64 00005812 */  mflo       $t3
/* 3678 80389A68 006B6021 */  addu       $t4, $v1, $t3
/* 367C 80389A6C C5860004 */  lwc1       $f6, 4($t4)
/* 3680 80389A70 E6460020 */  swc1       $f6, 0x20($s2)
/* 3684 80389A74 904D0005 */  lbu        $t5, 5($v0)
/* 3688 80389A78 01A40019 */  multu      $t5, $a0
/* 368C 80389A7C 00007012 */  mflo       $t6
/* 3690 80389A80 006E7821 */  addu       $t7, $v1, $t6
/* 3694 80389A84 C5E80008 */  lwc1       $f8, 8($t7)
/* 3698 80389A88 E6480024 */  swc1       $f8, 0x24($s2)
/* 369C 80389A8C 24120003 */  addiu      $s2, $zero, 3
.L80389A90:
/* 36A0 80389A90 4600A306 */  mov.s      $f12, $f20
/* 36A4 80389A94 0C0D29D5 */  jal        randf2
/* 36A8 80389A98 4600B386 */   mov.s     $f14, $f22
/* 36AC 80389A9C C60A001C */  lwc1       $f10, 0x1c($s0)
/* 36B0 80389AA0 26310001 */  addiu      $s1, $s1, 1
/* 36B4 80389AA4 26100004 */  addiu      $s0, $s0, 4
/* 36B8 80389AA8 46005400 */  add.s      $f16, $f10, $f0
/* 36BC 80389AAC 1632FFF8 */  bne        $s1, $s2, .L80389A90
/* 36C0 80389AB0 E6100018 */   swc1      $f16, 0x18($s0)
/* 36C4 80389AB4 1000001C */  b          .L80389B28
/* 36C8 80389AB8 8FBF003C */   lw        $ra, 0x3c($sp)
.L80389ABC:
/* 36CC 80389ABC 10000019 */  b          .L80389B24
/* 36D0 80389AC0 A240007F */   sb        $zero, 0x7f($s2)
.L80389AC4:
/* 36D4 80389AC4 3C062EE0 */  lui        $a2, 0x2ee0
/* 36D8 80389AC8 34C61388 */  ori        $a2, $a2, 0x1388
/* 36DC 80389ACC 34844131 */  ori        $a0, $a0, 0x4131
/* 36E0 80389AD0 0C0C3A2D */  jal        func_8030E8B4
/* 36E4 80389AD4 26450004 */   addiu     $a1, $s2, 4
/* 36E8 80389AD8 10000013 */  b          .L80389B28
/* 36EC 80389ADC 8FBF003C */   lw        $ra, 0x3c($sp)
.L80389AE0:
/* 36F0 80389AE0 0C0E1B3E */  jal        func_80386CF8
/* 36F4 80389AE4 02402025 */   or        $a0, $s2, $zero
/* 36F8 80389AE8 44806000 */  mtc1       $zero, $f12
/* 36FC 80389AEC 0C0C938E */  jal        func_80324E38
/* 3700 80389AF0 24050001 */   addiu     $a1, $zero, 1
/* 3704 80389AF4 00002025 */  or         $a0, $zero, $zero
/* 3708 80389AF8 0C0D29EF */  jal        randi2
/* 370C 80389AFC 24050005 */   addiu     $a1, $zero, 5
/* 3710 80389B00 3C188039 */  lui        $t8, %hi(func_80389944)
/* 3714 80389B04 27189944 */  addiu      $t8, $t8, %lo(func_80389944)
/* 3718 80389B08 8E470000 */  lw         $a3, ($s2)
/* 371C 80389B0C AFA00014 */  sw         $zero, 0x14($sp)
/* 3720 80389B10 AFB80010 */  sw         $t8, 0x10($sp)
/* 3724 80389B14 2444112C */  addiu      $a0, $v0, 0x112c
/* 3728 80389B18 240500A8 */  addiu      $a1, $zero, 0xa8
/* 372C 80389B1C 0C0C4520 */  jal        func_80311480
/* 3730 80389B20 00003025 */   or        $a2, $zero, $zero
.L80389B24:
/* 3734 80389B24 8FBF003C */  lw         $ra, 0x3c($sp)
.L80389B28:
/* 3738 80389B28 D7B40020 */  ldc1       $f20, 0x20($sp)
/* 373C 80389B2C D7B60028 */  ldc1       $f22, 0x28($sp)
/* 3740 80389B30 8FB00030 */  lw         $s0, 0x30($sp)
/* 3744 80389B34 8FB10034 */  lw         $s1, 0x34($sp)
/* 3748 80389B38 8FB20038 */  lw         $s2, 0x38($sp)
/* 374C 80389B3C 03E00008 */  jr         $ra
/* 3750 80389B40 27BD0040 */   addiu     $sp, $sp, 0x40
glabel func_80389B44
/* 3754 80389B44 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 3758 80389B48 AFA40018 */  sw         $a0, 0x18($sp)
/* 375C 80389B4C AFBF0014 */  sw         $ra, 0x14($sp)
/* 3760 80389B50 3C048038 */  lui        $a0, %hi(func_80386DE4)
/* 3764 80389B54 24846DE4 */  addiu      $a0, $a0, %lo(func_80386DE4)
/* 3768 80389B58 0C0B0F22 */  jal        func_802C3C88
/* 376C 80389B5C 8FA50018 */   lw        $a1, 0x18($sp)
/* 3770 80389B60 8FBF0014 */  lw         $ra, 0x14($sp)
/* 3774 80389B64 27BD0018 */  addiu      $sp, $sp, 0x18
/* 3778 80389B68 03E00008 */  jr         $ra
/* 377C 80389B6C 00000000 */   nop
glabel func_80389B70
/* 3780 80389B70 27BDFFB8 */  addiu      $sp, $sp, -0x48
/* 3784 80389B74 AFBF002C */  sw         $ra, 0x2c($sp)
/* 3788 80389B78 0C0CA656 */  jal        marker_getActor
/* 378C 80389B7C AFB00028 */   sw        $s0, 0x28($sp)
/* 3790 80389B80 244E007C */  addiu      $t6, $v0, 0x7c
/* 3794 80389B84 00408025 */  or         $s0, $v0, $zero
/* 3798 80389B88 0C0CF767 */  jal        time_getDelta
/* 379C 80389B8C AFAE0040 */   sw        $t6, 0x40($sp)
/* 37A0 80389B90 8FAF0040 */  lw         $t7, 0x40($sp)
/* 37A4 80389B94 E7A0003C */  swc1       $f0, 0x3c($sp)
/* 37A8 80389B98 91F80001 */  lbu        $t8, 1($t7)
/* 37AC 80389B9C AFB80038 */  sw         $t8, 0x38($sp)
/* 37B0 80389BA0 0C0A1DF6 */  jal        animctrl_getAnimTimer
/* 37B4 80389BA4 8E040014 */   lw        $a0, 0x14($s0)
/* 37B8 80389BA8 E7A00034 */  swc1       $f0, 0x34($sp)
/* 37BC 80389BAC 8E190010 */  lw         $t9, 0x10($s0)
/* 37C0 80389BB0 00194682 */  srl        $t0, $t9, 0x1a
/* 37C4 80389BB4 2509FFEB */  addiu      $t1, $t0, -0x15
/* 37C8 80389BB8 2D210007 */  sltiu      $at, $t1, 7
/* 37CC 80389BBC 102000E0 */  beqz       $at, .L80389F40
/* 37D0 80389BC0 00094880 */   sll       $t1, $t1, 2
/* 37D4 80389BC4 3C018039 */  lui        $at, %hi(D_8039224C)
/* 37D8 80389BC8 00290821 */  addu       $at, $at, $t1
/* 37DC 80389BCC 8C29224C */  lw         $t1, %lo(D_8039224C)($at)
/* 37E0 80389BD0 01200008 */  jr         $t1
/* 37E4 80389BD4 00000000 */   nop
/* 37E8 80389BD8 0C0E1A6F */  jal        func_803869BC
/* 37EC 80389BDC 02002025 */   or        $a0, $s0, $zero
/* 37F0 80389BE0 C6040060 */  lwc1       $f4, 0x60($s0)
/* 37F4 80389BE4 C7A6003C */  lwc1       $f6, 0x3c($sp)
/* 37F8 80389BE8 8FA30040 */  lw         $v1, 0x40($sp)
/* 37FC 80389BEC 44809800 */  mtc1       $zero, $f19
/* 3800 80389BF0 46062201 */  sub.s      $f8, $f4, $f6
/* 3804 80389BF4 44809000 */  mtc1       $zero, $f18
/* 3808 80389BF8 3C018039 */  lui        $at, 0x8039
/* 380C 80389BFC 02002025 */  or         $a0, $s0, $zero
/* 3810 80389C00 E6080060 */  swc1       $f8, 0x60($s0)
/* 3814 80389C04 C60A0060 */  lwc1       $f10, 0x60($s0)
/* 3818 80389C08 8FAF0038 */  lw         $t7, 0x38($sp)
/* 381C 80389C0C 46005421 */  cvt.d.s    $f16, $f10
/* 3820 80389C10 000FC080 */  sll        $t8, $t7, 2
/* 3824 80389C14 4632803C */  c.lt.d     $f16, $f18
/* 3828 80389C18 00380821 */  addu       $at, $at, $t8
/* 382C 80389C1C 45000017 */  bc1f       .L80389C7C
/* 3830 80389C20 00000000 */   nop
/* 3834 80389C24 906A000A */  lbu        $t2, 0xa($v1)
/* 3838 80389C28 24050017 */  addiu      $a1, $zero, 0x17
/* 383C 80389C2C 02002025 */  or         $a0, $s0, $zero
/* 3840 80389C30 11400005 */  beqz       $t2, .L80389C48
/* 3844 80389C34 00000000 */   nop
/* 3848 80389C38 0C0E2663 */  jal        func_8038998C
/* 384C 80389C3C 02002025 */   or        $a0, $s0, $zero
/* 3850 80389C40 1000000A */  b          .L80389C6C
/* 3854 80389C44 8FA30040 */   lw        $v1, 0x40($sp)
.L80389C48:
/* 3858 80389C48 0C0E2663 */  jal        func_8038998C
/* 385C 80389C4C 24050016 */   addiu     $a1, $zero, 0x16
/* 3860 80389C50 8FA30040 */  lw         $v1, 0x40($sp)
/* 3864 80389C54 3C018039 */  lui        $at, %hi(D_803917B4)
/* 3868 80389C58 906B0001 */  lbu        $t3, 1($v1)
/* 386C 80389C5C 000B6080 */  sll        $t4, $t3, 2
/* 3870 80389C60 002C0821 */  addu       $at, $at, $t4
/* 3874 80389C64 C42417B4 */  lwc1       $f4, %lo(D_803917B4)($at)
/* 3878 80389C68 E6040060 */  swc1       $f4, 0x60($s0)
.L80389C6C:
/* 387C 80389C6C 906D000A */  lbu        $t5, 0xa($v1)
/* 3880 80389C70 39AE0001 */  xori       $t6, $t5, 1
/* 3884 80389C74 100000B2 */  b          .L80389F40
/* 3888 80389C78 A06E000A */   sb        $t6, 0xa($v1)
.L80389C7C:
/* 388C 80389C7C C42017A4 */  lwc1       $f0, 0x17a4($at)
/* 3890 80389C80 3C0142F0 */  lui        $at, 0x42f0
/* 3894 80389C84 44813000 */  mtc1       $at, $f6
/* 3898 80389C88 3C014402 */  lui        $at, 0x4402
/* 389C 80389C8C 44814000 */  mtc1       $at, $f8
/* 38A0 80389C90 3C0143AF */  lui        $at, 0x43af
/* 38A4 80389C94 44815000 */  mtc1       $at, $f10
/* 38A8 80389C98 44060000 */  mfc1       $a2, $f0
/* 38AC 80389C9C 44070000 */  mfc1       $a3, $f0
/* 38B0 80389CA0 2605001C */  addiu      $a1, $s0, 0x1c
/* 38B4 80389CA4 E7A60010 */  swc1       $f6, 0x10($sp)
/* 38B8 80389CA8 E7A80014 */  swc1       $f8, 0x14($sp)
/* 38BC 80389CAC 0C0E1D1C */  jal        func_80387470
/* 38C0 80389CB0 E7AA0018 */   swc1      $f10, 0x18($sp)
/* 38C4 80389CB4 104000A2 */  beqz       $v0, .L80389F40
/* 38C8 80389CB8 02002025 */   or        $a0, $s0, $zero
/* 38CC 80389CBC 0C0E2663 */  jal        func_8038998C
/* 38D0 80389CC0 24050015 */   addiu     $a1, $zero, 0x15
/* 38D4 80389CC4 8FA30040 */  lw         $v1, 0x40($sp)
/* 38D8 80389CC8 3C058039 */  lui        $a1, %hi(func_80389B44)
/* 38DC 80389CCC 24080001 */  addiu      $t0, $zero, 1
/* 38E0 80389CD0 9079000B */  lbu        $t9, 0xb($v1)
/* 38E4 80389CD4 24A59B44 */  addiu      $a1, $a1, %lo(func_80389B44)
/* 38E8 80389CD8 3C018039 */  lui        $at, 0x8039
/* 38EC 80389CDC 57200099 */  bnel       $t9, $zero, .L80389F44
/* 38F0 80389CE0 8FBF002C */   lw        $ra, 0x2c($sp)
/* 38F4 80389CE4 A068000B */  sb         $t0, 0xb($v1)
/* 38F8 80389CE8 8E060000 */  lw         $a2, ($s0)
/* 38FC 80389CEC 0C0C93B9 */  jal        timedFunc_set_1
/* 3900 80389CF0 C42C2268 */   lwc1      $f12, 0x2268($at)
/* 3904 80389CF4 10000093 */  b          .L80389F44
/* 3908 80389CF8 8FBF002C */   lw        $ra, 0x2c($sp)
/* 390C 80389CFC C6100060 */  lwc1       $f16, 0x60($s0)
/* 3910 80389D00 C7B2003C */  lwc1       $f18, 0x3c($sp)
/* 3914 80389D04 44805800 */  mtc1       $zero, $f11
/* 3918 80389D08 44805000 */  mtc1       $zero, $f10
/* 391C 80389D0C 46128101 */  sub.s      $f4, $f16, $f18
/* 3920 80389D10 02002025 */  or         $a0, $s0, $zero
/* 3924 80389D14 E6040060 */  swc1       $f4, 0x60($s0)
/* 3928 80389D18 C6060060 */  lwc1       $f6, 0x60($s0)
/* 392C 80389D1C 46003221 */  cvt.d.s    $f8, $f6
/* 3930 80389D20 462A403C */  c.lt.d     $f8, $f10
/* 3934 80389D24 00000000 */  nop
/* 3938 80389D28 45020086 */  bc1fl      .L80389F44
/* 393C 80389D2C 8FBF002C */   lw        $ra, 0x2c($sp)
/* 3940 80389D30 0C0E2663 */  jal        func_8038998C
/* 3944 80389D34 24050015 */   addiu     $a1, $zero, 0x15
/* 3948 80389D38 3C0140A0 */  lui        $at, 0x40a0
/* 394C 80389D3C 44818000 */  mtc1       $at, $f16
/* 3950 80389D40 1000007F */  b          .L80389F40
/* 3954 80389D44 E6100060 */   swc1      $f16, 0x60($s0)
/* 3958 80389D48 02002025 */  or         $a0, $s0, $zero
/* 395C 80389D4C 0C0E1AFB */  jal        func_80386BEC
/* 3960 80389D50 3C054110 */   lui       $a1, 0x4110
/* 3964 80389D54 5040007B */  beql       $v0, $zero, .L80389F44
/* 3968 80389D58 8FBF002C */   lw        $ra, 0x2c($sp)
/* 396C 80389D5C 0C0A5F1B */  jal        func_80297C6C
/* 3970 80389D60 00000000 */   nop
/* 3974 80389D64 24010003 */  addiu      $at, $zero, 3
/* 3978 80389D68 10410075 */  beq        $v0, $at, .L80389F40
/* 397C 80389D6C 02002025 */   or        $a0, $s0, $zero
/* 3980 80389D70 0C0E2663 */  jal        func_8038998C
/* 3984 80389D74 24050018 */   addiu     $a1, $zero, 0x18
/* 3988 80389D78 10000072 */  b          .L80389F44
/* 398C 80389D7C 8FBF002C */   lw        $ra, 0x2c($sp)
/* 3990 80389D80 02002025 */  or         $a0, $s0, $zero
/* 3994 80389D84 0C0E1AFB */  jal        func_80386BEC
/* 3998 80389D88 3C054040 */   lui       $a1, 0x4040
/* 399C 80389D8C 3C053FA6 */  lui        $a1, 0x3fa6
/* 39A0 80389D90 34A56666 */  ori        $a1, $a1, 0x6666
/* 39A4 80389D94 0C0E1CD0 */  jal        func_80387340
/* 39A8 80389D98 02002025 */   or        $a0, $s0, $zero
/* 39AC 80389D9C 10400004 */  beqz       $v0, .L80389DB0
/* 39B0 80389DA0 8FA30040 */   lw        $v1, 0x40($sp)
/* 39B4 80389DA4 90690003 */  lbu        $t1, 3($v1)
/* 39B8 80389DA8 252A0001 */  addiu      $t2, $t1, 1
/* 39BC 80389DAC A06A0003 */  sb         $t2, 3($v1)
.L80389DB0:
/* 39C0 80389DB0 3C053F7F */  lui        $a1, 0x3f7f
/* 39C4 80389DB4 34A5F972 */  ori        $a1, $a1, 0xf972
/* 39C8 80389DB8 0C0CA21B */  jal        actor_animationIsAt
/* 39CC 80389DBC 02002025 */   or        $a0, $s0, $zero
/* 39D0 80389DC0 1040005F */  beqz       $v0, .L80389F40
/* 39D4 80389DC4 8FA30040 */   lw        $v1, 0x40($sp)
/* 39D8 80389DC8 90620001 */  lbu        $v0, 1($v1)
/* 39DC 80389DCC 906B0003 */  lbu        $t3, 3($v1)
/* 39E0 80389DD0 0162082A */  slt        $at, $t3, $v0
/* 39E4 80389DD4 1420005A */  bnez       $at, .L80389F40
/* 39E8 80389DD8 28410004 */   slti      $at, $v0, 4
/* 39EC 80389DDC 14200006 */  bnez       $at, .L80389DF8
/* 39F0 80389DE0 02002025 */   or        $a0, $s0, $zero
/* 39F4 80389DE4 02002025 */  or         $a0, $s0, $zero
/* 39F8 80389DE8 0C0E2663 */  jal        func_8038998C
/* 39FC 80389DEC 2405001A */   addiu     $a1, $zero, 0x1a
/* 3A00 80389DF0 10000054 */  b          .L80389F44
/* 3A04 80389DF4 8FBF002C */   lw        $ra, 0x2c($sp)
.L80389DF8:
/* 3A08 80389DF8 3C0140A0 */  lui        $at, 0x40a0
/* 3A0C 80389DFC 44819000 */  mtc1       $at, $f18
/* 3A10 80389E00 24050015 */  addiu      $a1, $zero, 0x15
/* 3A14 80389E04 0C0E2663 */  jal        func_8038998C
/* 3A18 80389E08 E6120060 */   swc1      $f18, 0x60($s0)
/* 3A1C 80389E0C 1000004D */  b          .L80389F44
/* 3A20 80389E10 8FBF002C */   lw        $ra, 0x2c($sp)
/* 3A24 80389E14 3C053F7F */  lui        $a1, 0x3f7f
/* 3A28 80389E18 34A5F972 */  ori        $a1, $a1, 0xf972
/* 3A2C 80389E1C 0C0CA21B */  jal        actor_animationIsAt
/* 3A30 80389E20 02002025 */   or        $a0, $s0, $zero
/* 3A34 80389E24 10400046 */  beqz       $v0, .L80389F40
/* 3A38 80389E28 02002025 */   or        $a0, $s0, $zero
/* 3A3C 80389E2C 0C0E2663 */  jal        func_8038998C
/* 3A40 80389E30 24050017 */   addiu     $a1, $zero, 0x17
/* 3A44 80389E34 10000043 */  b          .L80389F44
/* 3A48 80389E38 8FBF002C */   lw        $ra, 0x2c($sp)
/* 3A4C 80389E3C 3C053DCC */  lui        $a1, 0x3dcc
/* 3A50 80389E40 34A5CCCD */  ori        $a1, $a1, 0xcccd
/* 3A54 80389E44 0C0CA21B */  jal        actor_animationIsAt
/* 3A58 80389E48 02002025 */   or        $a0, $s0, $zero
/* 3A5C 80389E4C 10400004 */  beqz       $v0, .L80389E60
/* 3A60 80389E50 24050043 */   addiu     $a1, $zero, 0x43
/* 3A64 80389E54 44806000 */  mtc1       $zero, $f12
/* 3A68 80389E58 0C0C933F */  jal        func_80324CFC
/* 3A6C 80389E5C 24067FFF */   addiu     $a2, $zero, 0x7fff
.L80389E60:
/* 3A70 80389E60 C7A40034 */  lwc1       $f4, 0x34($sp)
/* 3A74 80389E64 3C018039 */  lui        $at, %hi(D_80392270)
/* 3A78 80389E68 D4262270 */  ldc1       $f6, %lo(D_80392270)($at)
/* 3A7C 80389E6C 46002021 */  cvt.d.s    $f0, $f4
/* 3A80 80389E70 3C018039 */  lui        $at, %hi(D_80392278)
/* 3A84 80389E74 4620303C */  c.lt.d     $f6, $f0
/* 3A88 80389E78 00000000 */  nop
/* 3A8C 80389E7C 4502001B */  bc1fl      .L80389EEC
/* 3A90 80389E80 3C053EC2 */   lui       $a1, 0x3ec2
/* 3A94 80389E84 D4282278 */  ldc1       $f8, %lo(D_80392278)($at)
/* 3A98 80389E88 24050008 */  addiu      $a1, $zero, 8
/* 3A9C 80389E8C 3C068039 */  lui        $a2, 0x8039
/* 3AA0 80389E90 4628003C */  c.lt.d     $f0, $f8
/* 3AA4 80389E94 00000000 */  nop
/* 3AA8 80389E98 45020014 */  bc1fl      .L80389EEC
/* 3AAC 80389E9C 3C053EC2 */   lui       $a1, 0x3ec2
/* 3AB0 80389EA0 8E0C0000 */  lw         $t4, ($s0)
/* 3AB4 80389EA4 24C628B8 */  addiu      $a2, $a2, 0x28b8
/* 3AB8 80389EA8 0C0D285D */  jal        func_8034A174
/* 3ABC 80389EAC 8D840044 */   lw        $a0, 0x44($t4)
/* 3AC0 80389EB0 3C048039 */  lui        $a0, %hi(D_803928B8)
/* 3AC4 80389EB4 248428B8 */  addiu      $a0, $a0, %lo(D_803928B8)
/* 3AC8 80389EB8 0C0E1A4D */  jal        func_80386934
/* 3ACC 80389EBC 24050716 */   addiu     $a1, $zero, 0x716
/* 3AD0 80389EC0 8E0D0000 */  lw         $t5, ($s0)
/* 3AD4 80389EC4 3C068039 */  lui        $a2, %hi(D_803928B8)
/* 3AD8 80389EC8 24C628B8 */  addiu      $a2, $a2, %lo(D_803928B8)
/* 3ADC 80389ECC 24050009 */  addiu      $a1, $zero, 9
/* 3AE0 80389ED0 0C0D285D */  jal        func_8034A174
/* 3AE4 80389ED4 8DA40044 */   lw        $a0, 0x44($t5)
/* 3AE8 80389ED8 3C048039 */  lui        $a0, %hi(D_803928B8)
/* 3AEC 80389EDC 248428B8 */  addiu      $a0, $a0, %lo(D_803928B8)
/* 3AF0 80389EE0 0C0E1A4D */  jal        func_80386934
/* 3AF4 80389EE4 24050716 */   addiu     $a1, $zero, 0x716
/* 3AF8 80389EE8 3C053EC2 */  lui        $a1, 0x3ec2
.L80389EEC:
/* 3AFC 80389EEC 34A58F5C */  ori        $a1, $a1, 0x8f5c
/* 3B00 80389EF0 0C0CA21B */  jal        actor_animationIsAt
/* 3B04 80389EF4 02002025 */   or        $a0, $s0, $zero
/* 3B08 80389EF8 50400004 */  beql       $v0, $zero, .L80389F0C
/* 3B0C 80389EFC 3C053F7F */   lui       $a1, 0x3f7f
/* 3B10 80389F00 0C0E2646 */  jal        func_80389918
/* 3B14 80389F04 8E040000 */   lw        $a0, ($s0)
/* 3B18 80389F08 3C053F7F */  lui        $a1, 0x3f7f
.L80389F0C:
/* 3B1C 80389F0C 34A5F972 */  ori        $a1, $a1, 0xf972
/* 3B20 80389F10 0C0CA21B */  jal        actor_animationIsAt
/* 3B24 80389F14 02002025 */   or        $a0, $s0, $zero
/* 3B28 80389F18 5040000A */  beql       $v0, $zero, .L80389F44
/* 3B2C 80389F1C 8FBF002C */   lw        $ra, 0x2c($sp)
/* 3B30 80389F20 44806000 */  mtc1       $zero, $f12
/* 3B34 80389F24 0C0C934B */  jal        func_80324D2C
/* 3B38 80389F28 24050043 */   addiu     $a1, $zero, 0x43
/* 3B3C 80389F2C 0C0E1B8D */  jal        func_80386E34
/* 3B40 80389F30 00000000 */   nop
/* 3B44 80389F34 02002025 */  or         $a0, $s0, $zero
/* 3B48 80389F38 0C0E2663 */  jal        func_8038998C
/* 3B4C 80389F3C 2405001B */   addiu     $a1, $zero, 0x1b
.L80389F40:
/* 3B50 80389F40 8FBF002C */  lw         $ra, 0x2c($sp)
.L80389F44:
/* 3B54 80389F44 8FB00028 */  lw         $s0, 0x28($sp)
/* 3B58 80389F48 27BD0048 */  addiu      $sp, $sp, 0x48
/* 3B5C 80389F4C 03E00008 */  jr         $ra
/* 3B60 80389F50 00000000 */   nop
glabel func_80389F54
/* 3B64 80389F54 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 3B68 80389F58 AFBF0014 */  sw         $ra, 0x14($sp)
/* 3B6C 80389F5C 240400D2 */  addiu      $a0, $zero, 0xd2
/* 3B70 80389F60 0C0C8001 */  jal        func_80320004
/* 3B74 80389F64 24050001 */   addiu     $a1, $zero, 1
/* 3B78 80389F68 8FBF0014 */  lw         $ra, 0x14($sp)
/* 3B7C 80389F6C 3C018039 */  lui        $at, %hi(D_803927C4)
/* 3B80 80389F70 A02027C4 */  sb         $zero, %lo(D_803927C4)($at)
/* 3B84 80389F74 03E00008 */  jr         $ra
/* 3B88 80389F78 27BD0018 */   addiu     $sp, $sp, 0x18
glabel func_80389F7C
/* 3B8C 80389F7C 27BDFFB0 */  addiu      $sp, $sp, -0x50
/* 3B90 80389F80 AFB00020 */  sw         $s0, 0x20($sp)
/* 3B94 80389F84 00808025 */  or         $s0, $a0, $zero
/* 3B98 80389F88 AFBF0024 */  sw         $ra, 0x24($sp)
/* 3B9C 80389F8C AFA50054 */  sw         $a1, 0x54($sp)
/* 3BA0 80389F90 0C0A1DF6 */  jal        animctrl_getAnimTimer
/* 3BA4 80389F94 8C840014 */   lw        $a0, 0x14($a0)
/* 3BA8 80389F98 E7A00048 */  swc1       $f0, 0x48($sp)
/* 3BAC 80389F9C 2602007C */  addiu      $v0, $s0, 0x7c
/* 3BB0 80389FA0 240E0004 */  addiu      $t6, $zero, 4
/* 3BB4 80389FA4 A04E0000 */  sb         $t6, ($v0)
/* 3BB8 80389FA8 3C0638D1 */  lui        $a2, 0x38d1
/* 3BBC 80389FAC 34C6B717 */  ori        $a2, $a2, 0xb717
/* 3BC0 80389FB0 AFA2002C */  sw         $v0, 0x2c($sp)
/* 3BC4 80389FB4 8FA50054 */  lw         $a1, 0x54($sp)
/* 3BC8 80389FB8 02002025 */  or         $a0, $s0, $zero
/* 3BCC 80389FBC 0C0CA2E3 */  jal        func_80328B8C
/* 3BD0 80389FC0 24070001 */   addiu     $a3, $zero, 1
/* 3BD4 80389FC4 8FAF0054 */  lw         $t7, 0x54($sp)
/* 3BD8 80389FC8 25F8FFE4 */  addiu      $t8, $t7, -0x1c
/* 3BDC 80389FCC 2F010007 */  sltiu      $at, $t8, 7
/* 3BE0 80389FD0 10200140 */  beqz       $at, .L8038A4D4
/* 3BE4 80389FD4 0018C080 */   sll       $t8, $t8, 2
/* 3BE8 80389FD8 3C018039 */  lui        $at, %hi(D_80392280)
/* 3BEC 80389FDC 00380821 */  addu       $at, $at, $t8
/* 3BF0 80389FE0 8C382280 */  lw         $t8, %lo(D_80392280)($at)
/* 3BF4 80389FE4 03000008 */  jr         $t8
/* 3BF8 80389FE8 00000000 */   nop
/* 3BFC 80389FEC 8E040014 */  lw         $a0, 0x14($s0)
/* 3C00 80389FF0 0C0A1D93 */  jal        animctrl_setAnimTimer
/* 3C04 80389FF4 8FA50048 */   lw        $a1, 0x48($sp)
/* 3C08 80389FF8 3C028039 */  lui        $v0, %hi(D_803927D0)
/* 3C0C 80389FFC 244227D0 */  addiu      $v0, $v0, %lo(D_803927D0)
/* 3C10 8038A000 C44400C0 */  lwc1       $f4, 0xc0($v0)
/* 3C14 8038A004 E604001C */  swc1       $f4, 0x1c($s0)
/* 3C18 8038A008 C44600C4 */  lwc1       $f6, 0xc4($v0)
/* 3C1C 8038A00C E6060020 */  swc1       $f6, 0x20($s0)
/* 3C20 8038A010 C44800C8 */  lwc1       $f8, 0xc8($v0)
/* 3C24 8038A014 1000012F */  b          .L8038A4D4
/* 3C28 8038A018 E6080024 */   swc1      $f8, 0x24($s0)
/* 3C2C 8038A01C 8FA2002C */  lw         $v0, 0x2c($sp)
/* 3C30 8038A020 24010002 */  addiu      $at, $zero, 2
/* 3C34 8038A024 90590003 */  lbu        $t9, 3($v0)
/* 3C38 8038A028 5721012B */  bnel       $t9, $at, .L8038A4D8
/* 3C3C 8038A02C 8FBF0024 */   lw        $ra, 0x24($sp)
/* 3C40 8038A030 9048000A */  lbu        $t0, 0xa($v0)
/* 3C44 8038A034 24100001 */  addiu      $s0, $zero, 1
/* 3C48 8038A038 3C018039 */  lui        $at, %hi(D_803927C8)
/* 3C4C 8038A03C 15000125 */  bnez       $t0, .L8038A4D4
/* 3C50 8038A040 00002025 */   or        $a0, $zero, $zero
/* 3C54 8038A044 A03027C8 */  sb         $s0, %lo(D_803927C8)($at)
/* 3C58 8038A048 0C0D29EF */  jal        randi2
/* 3C5C 8038A04C 24050005 */   addiu     $a1, $zero, 5
/* 3C60 8038A050 24441136 */  addiu      $a0, $v0, 0x1136
/* 3C64 8038A054 24050004 */  addiu      $a1, $zero, 4
/* 3C68 8038A058 00003025 */  or         $a2, $zero, $zero
/* 3C6C 8038A05C 00003825 */  or         $a3, $zero, $zero
/* 3C70 8038A060 AFA00010 */  sw         $zero, 0x10($sp)
/* 3C74 8038A064 0C0C4520 */  jal        func_80311480
/* 3C78 8038A068 AFA00014 */   sw        $zero, 0x14($sp)
/* 3C7C 8038A06C 0C0C7FC7 */  jal        func_8031FF1C
/* 3C80 8038A070 240400D2 */   addiu     $a0, $zero, 0xd2
/* 3C84 8038A074 14400043 */  bnez       $v0, .L8038A184
/* 3C88 8038A078 24040001 */   addiu     $a0, $zero, 1
/* 3C8C 8038A07C 8FA9002C */  lw         $t1, 0x2c($sp)
/* 3C90 8038A080 3C018039 */  lui        $at, %hi(D_803927C4)
/* 3C94 8038A084 44806000 */  mtc1       $zero, $f12
/* 3C98 8038A088 A130000A */  sb         $s0, 0xa($t1)
/* 3C9C 8038A08C A03027C4 */  sb         $s0, %lo(D_803927C4)($at)
/* 3CA0 8038A090 0C0C938E */  jal        func_80324E38
/* 3CA4 8038A094 24050001 */   addiu     $a1, $zero, 1
/* 3CA8 8038A098 3C108039 */  lui        $s0, %hi(func_803898A4)
/* 3CAC 8038A09C 261098A4 */  addiu      $s0, $s0, %lo(func_803898A4)
/* 3CB0 8038A0A0 44806000 */  mtc1       $zero, $f12
/* 3CB4 8038A0A4 02002825 */  or         $a1, $s0, $zero
/* 3CB8 8038A0A8 0C0C93B9 */  jal        timedFunc_set_1
/* 3CBC 8038A0AC 24060001 */   addiu     $a2, $zero, 1
/* 3CC0 8038A0B0 44806000 */  mtc1       $zero, $f12
/* 3CC4 8038A0B4 0C0C9398 */  jal        timed_setCameraToNode
/* 3CC8 8038A0B8 24050004 */   addiu     $a1, $zero, 4
/* 3CCC 8038A0BC 3C018039 */  lui        $at, %hi(D_8039229C)
/* 3CD0 8038A0C0 0C0C93A2 */  jal        func_80324E88
/* 3CD4 8038A0C4 C42C229C */   lwc1      $f12, %lo(D_8039229C)($at)
/* 3CD8 8038A0C8 3C018039 */  lui        $at, %hi(D_803922A0)
/* 3CDC 8038A0CC C42C22A0 */  lwc1       $f12, %lo(D_803922A0)($at)
/* 3CE0 8038A0D0 02002825 */  or         $a1, $s0, $zero
/* 3CE4 8038A0D4 0C0C93B9 */  jal        timedFunc_set_1
/* 3CE8 8038A0D8 24060002 */   addiu     $a2, $zero, 2
/* 3CEC 8038A0DC 3C018039 */  lui        $at, %hi(D_803922A4)
/* 3CF0 8038A0E0 C42C22A4 */  lwc1       $f12, %lo(D_803922A4)($at)
/* 3CF4 8038A0E4 0C0C9398 */  jal        timed_setCameraToNode
/* 3CF8 8038A0E8 24050005 */   addiu     $a1, $zero, 5
/* 3CFC 8038A0EC 3C018039 */  lui        $at, %hi(D_803922A8)
/* 3D00 8038A0F0 0C0C93A2 */  jal        func_80324E88
/* 3D04 8038A0F4 C42C22A8 */   lwc1      $f12, %lo(D_803922A8)($at)
/* 3D08 8038A0F8 3C018039 */  lui        $at, %hi(D_803922AC)
/* 3D0C 8038A0FC C42C22AC */  lwc1       $f12, %lo(D_803922AC)($at)
/* 3D10 8038A100 02002825 */  or         $a1, $s0, $zero
/* 3D14 8038A104 0C0C93B9 */  jal        timedFunc_set_1
/* 3D18 8038A108 24060003 */   addiu     $a2, $zero, 3
/* 3D1C 8038A10C 3C018039 */  lui        $at, %hi(D_803922B0)
/* 3D20 8038A110 C42C22B0 */  lwc1       $f12, %lo(D_803922B0)($at)
/* 3D24 8038A114 0C0C9398 */  jal        timed_setCameraToNode
/* 3D28 8038A118 24050006 */   addiu     $a1, $zero, 6
/* 3D2C 8038A11C 3C018039 */  lui        $at, %hi(D_803922B4)
/* 3D30 8038A120 0C0C93A2 */  jal        func_80324E88
/* 3D34 8038A124 C42C22B4 */   lwc1      $f12, %lo(D_803922B4)($at)
/* 3D38 8038A128 3C018039 */  lui        $at, %hi(D_803922B8)
/* 3D3C 8038A12C C42C22B8 */  lwc1       $f12, %lo(D_803922B8)($at)
/* 3D40 8038A130 02002825 */  or         $a1, $s0, $zero
/* 3D44 8038A134 0C0C93B9 */  jal        timedFunc_set_1
/* 3D48 8038A138 24060004 */   addiu     $a2, $zero, 4
/* 3D4C 8038A13C 3C018039 */  lui        $at, %hi(D_803922BC)
/* 3D50 8038A140 C42C22BC */  lwc1       $f12, %lo(D_803922BC)($at)
/* 3D54 8038A144 0C0C9398 */  jal        timed_setCameraToNode
/* 3D58 8038A148 24050007 */   addiu     $a1, $zero, 7
/* 3D5C 8038A14C 3C018039 */  lui        $at, %hi(D_803922C0)
/* 3D60 8038A150 0C0C93A2 */  jal        func_80324E88
/* 3D64 8038A154 C42C22C0 */   lwc1      $f12, %lo(D_803922C0)($at)
/* 3D68 8038A158 3C018039 */  lui        $at, %hi(D_803922C4)
/* 3D6C 8038A15C 3C058039 */  lui        $a1, %hi(func_80389F54)
/* 3D70 8038A160 24A59F54 */  addiu      $a1, $a1, %lo(func_80389F54)
/* 3D74 8038A164 0C0C93AB */  jal        timedFunc_set_0
/* 3D78 8038A168 C42C22C4 */   lwc1      $f12, %lo(D_803922C4)($at)
/* 3D7C 8038A16C 3C018039 */  lui        $at, %hi(D_803922C8)
/* 3D80 8038A170 C42C22C8 */  lwc1       $f12, %lo(D_803922C8)($at)
/* 3D84 8038A174 0C0C938E */  jal        func_80324E38
/* 3D88 8038A178 00002825 */   or        $a1, $zero, $zero
/* 3D8C 8038A17C 100000D6 */  b          .L8038A4D8
/* 3D90 8038A180 8FBF0024 */   lw        $ra, 0x24($sp)
.L8038A184:
/* 3D94 8038A184 3C018039 */  lui        $at, %hi(D_803928C4)
/* 3D98 8038A188 0C0E2629 */  jal        func_803898A4
/* 3D9C 8038A18C AC2428C4 */   sw        $a0, %lo(D_803928C4)($at)
/* 3DA0 8038A190 3C048039 */  lui        $a0, %hi(D_803928C4)
/* 3DA4 8038A194 8C8428C4 */  lw         $a0, %lo(D_803928C4)($a0)
/* 3DA8 8038A198 24840001 */  addiu      $a0, $a0, 1
/* 3DAC 8038A19C 28810005 */  slti       $at, $a0, 5
/* 3DB0 8038A1A0 1420FFF8 */  bnez       $at, .L8038A184
/* 3DB4 8038A1A4 00000000 */   nop
/* 3DB8 8038A1A8 3C018039 */  lui        $at, %hi(D_803928C4)
/* 3DBC 8038A1AC 100000C9 */  b          .L8038A4D4
/* 3DC0 8038A1B0 AC2428C4 */   sw        $a0, %lo(D_803928C4)($at)
/* 3DC4 8038A1B4 3C018039 */  lui        $at, %hi(D_803922CC)
/* 3DC8 8038A1B8 C42C22CC */  lwc1       $f12, %lo(D_803922CC)($at)
/* 3DCC 8038A1BC 3C018039 */  lui        $at, %hi(D_803922D0)
/* 3DD0 8038A1C0 0C0D29D5 */  jal        randf2
/* 3DD4 8038A1C4 C42E22D0 */   lwc1      $f14, %lo(D_803922D0)($at)
/* 3DD8 8038A1C8 3C018039 */  lui        $at, %hi(D_803922D4)
/* 3DDC 8038A1CC C42A22D4 */  lwc1       $f10, %lo(D_803922D4)($at)
/* 3DE0 8038A1D0 3C018039 */  lui        $at, %hi(D_803922D8)
/* 3DE4 8038A1D4 C43022D8 */  lwc1       $f16, %lo(D_803922D8)($at)
/* 3DE8 8038A1D8 44050000 */  mfc1       $a1, $f0
/* 3DEC 8038A1DC 24040131 */  addiu      $a0, $zero, 0x131
/* 3DF0 8038A1E0 24067D00 */  addiu      $a2, $zero, 0x7d00
/* 3DF4 8038A1E4 26070004 */  addiu      $a3, $s0, 4
/* 3DF8 8038A1E8 E7AA0010 */  swc1       $f10, 0x10($sp)
/* 3DFC 8038A1EC 0C0C3A1E */  jal        func_8030E878
/* 3E00 8038A1F0 E7B00014 */   swc1      $f16, 0x14($sp)
/* 3E04 8038A1F4 24040024 */  addiu      $a0, $zero, 0x24
/* 3E08 8038A1F8 0C0B24CD */  jal        func_802C9334
/* 3E0C 8038A1FC 02002825 */   or        $a1, $s0, $zero
/* 3E10 8038A200 100000B5 */  b          .L8038A4D8
/* 3E14 8038A204 8FBF0024 */   lw        $ra, 0x24($sp)
/* 3E18 8038A208 3C047FFF */  lui        $a0, 0x7fff
/* 3E1C 8038A20C 0C0C3989 */  jal        func_8030E624
/* 3E20 8038A210 34844131 */   ori       $a0, $a0, 0x4131
/* 3E24 8038A214 3C018039 */  lui        $at, %hi(D_803922DC)
/* 3E28 8038A218 C42C22DC */  lwc1       $f12, %lo(D_803922DC)($at)
/* 3E2C 8038A21C 24050061 */  addiu      $a1, $zero, 0x61
/* 3E30 8038A220 3C063F80 */  lui        $a2, 0x3f80
/* 3E34 8038A224 0C0C9322 */  jal        timed_playSfx
/* 3E38 8038A228 24077D00 */   addiu     $a3, $zero, 0x7d00
/* 3E3C 8038A22C 3C048038 */  lui        $a0, %hi(func_80386DE4)
/* 3E40 8038A230 24846DE4 */  addiu      $a0, $a0, %lo(func_80386DE4)
/* 3E44 8038A234 0C0B0F22 */  jal        func_802C3C88
/* 3E48 8038A238 8E050000 */   lw        $a1, ($s0)
/* 3E4C 8038A23C 3C047FFF */  lui        $a0, 0x7fff
/* 3E50 8038A240 0C0C3989 */  jal        func_8030E624
/* 3E54 8038A244 348440D9 */   ori       $a0, $a0, 0x40d9
/* 3E58 8038A248 8E040000 */  lw         $a0, ($s0)
/* 3E5C 8038A24C 0C0E198A */  jal        func_80386628
/* 3E60 8038A250 00002825 */   or        $a1, $zero, $zero
/* 3E64 8038A254 26040004 */  addiu      $a0, $s0, 4
/* 3E68 8038A258 AFA40028 */  sw         $a0, 0x28($sp)
/* 3E6C 8038A25C 24050552 */  addiu      $a1, $zero, 0x552
/* 3E70 8038A260 0C0E19B9 */  jal        func_803866E4
/* 3E74 8038A264 24060001 */   addiu     $a2, $zero, 1
/* 3E78 8038A268 8FA40028 */  lw         $a0, 0x28($sp)
/* 3E7C 8038A26C 24050553 */  addiu      $a1, $zero, 0x553
/* 3E80 8038A270 0C0E19B9 */  jal        func_803866E4
/* 3E84 8038A274 2406000C */   addiu     $a2, $zero, 0xc
/* 3E88 8038A278 8FA40028 */  lw         $a0, 0x28($sp)
/* 3E8C 8038A27C 24050554 */  addiu      $a1, $zero, 0x554
/* 3E90 8038A280 0C0E19B9 */  jal        func_803866E4
/* 3E94 8038A284 24060014 */   addiu     $a2, $zero, 0x14
/* 3E98 8038A288 8FA40028 */  lw         $a0, 0x28($sp)
/* 3E9C 8038A28C 24050555 */  addiu      $a1, $zero, 0x555
/* 3EA0 8038A290 0C0E19B9 */  jal        func_803866E4
/* 3EA4 8038A294 24060002 */   addiu     $a2, $zero, 2
/* 3EA8 8038A298 8FA6002C */  lw         $a2, 0x2c($sp)
/* 3EAC 8038A29C 2403000C */  addiu      $v1, $zero, 0xc
/* 3EB0 8038A2A0 3C028039 */  lui        $v0, %hi(D_803927D0)
/* 3EB4 8038A2A4 90CA0007 */  lbu        $t2, 7($a2)
/* 3EB8 8038A2A8 244227D0 */  addiu      $v0, $v0, %lo(D_803927D0)
/* 3EBC 8038A2AC C6040004 */  lwc1       $f4, 4($s0)
/* 3EC0 8038A2B0 01430019 */  multu      $t2, $v1
/* 3EC4 8038A2B4 3C018039 */  lui        $at, %hi(D_803922E0)
/* 3EC8 8038A2B8 D42022E0 */  ldc1       $f0, %lo(D_803922E0)($at)
/* 3ECC 8038A2BC 3C018039 */  lui        $at, 0x8039
/* 3ED0 8038A2C0 24040002 */  addiu      $a0, $zero, 2
/* 3ED4 8038A2C4 00005812 */  mflo       $t3
/* 3ED8 8038A2C8 004B6021 */  addu       $t4, $v0, $t3
/* 3EDC 8038A2CC C59200CC */  lwc1       $f18, 0xcc($t4)
/* 3EE0 8038A2D0 46049181 */  sub.s      $f6, $f18, $f4
/* 3EE4 8038A2D4 E7A6003C */  swc1       $f6, 0x3c($sp)
/* 3EE8 8038A2D8 90CD0007 */  lbu        $t5, 7($a2)
/* 3EEC 8038A2DC C60A0008 */  lwc1       $f10, 8($s0)
/* 3EF0 8038A2E0 01A30019 */  multu      $t5, $v1
/* 3EF4 8038A2E4 00007012 */  mflo       $t6
/* 3EF8 8038A2E8 004E7821 */  addu       $t7, $v0, $t6
/* 3EFC 8038A2EC C5E800D0 */  lwc1       $f8, 0xd0($t7)
/* 3F00 8038A2F0 460A4401 */  sub.s      $f16, $f8, $f10
/* 3F04 8038A2F4 C7A8003C */  lwc1       $f8, 0x3c($sp)
/* 3F08 8038A2F8 460042A1 */  cvt.d.s    $f10, $f8
/* 3F0C 8038A2FC E7B00040 */  swc1       $f16, 0x40($sp)
/* 3F10 8038A300 46205403 */  div.d      $f16, $f10, $f0
/* 3F14 8038A304 90D80007 */  lbu        $t8, 7($a2)
/* 3F18 8038A308 C604000C */  lwc1       $f4, 0xc($s0)
/* 3F1C 8038A30C 03030019 */  multu      $t8, $v1
/* 3F20 8038A310 0000C812 */  mflo       $t9
/* 3F24 8038A314 00594021 */  addu       $t0, $v0, $t9
/* 3F28 8038A318 C51200D4 */  lwc1       $f18, 0xd4($t0)
/* 3F2C 8038A31C 46049181 */  sub.s      $f6, $f18, $f4
/* 3F30 8038A320 E7A60044 */  swc1       $f6, 0x44($sp)
/* 3F34 8038A324 462084A0 */  cvt.s.d    $f18, $f16
/* 3F38 8038A328 E612002C */  swc1       $f18, 0x2c($s0)
/* 3F3C 8038A32C C7A40040 */  lwc1       $f4, 0x40($sp)
/* 3F40 8038A330 D42A22E8 */  ldc1       $f10, 0x22e8($at)
/* 3F44 8038A334 460021A1 */  cvt.d.s    $f6, $f4
/* 3F48 8038A338 46203203 */  div.d      $f8, $f6, $f0
/* 3F4C 8038A33C 462A4401 */  sub.d      $f16, $f8, $f10
/* 3F50 8038A340 462084A0 */  cvt.s.d    $f18, $f16
/* 3F54 8038A344 E6120030 */  swc1       $f18, 0x30($s0)
/* 3F58 8038A348 C7A40044 */  lwc1       $f4, 0x44($sp)
/* 3F5C 8038A34C 460021A1 */  cvt.d.s    $f6, $f4
/* 3F60 8038A350 46203203 */  div.d      $f8, $f6, $f0
/* 3F64 8038A354 462042A0 */  cvt.s.d    $f10, $f8
/* 3F68 8038A358 E60A0034 */  swc1       $f10, 0x34($s0)
/* 3F6C 8038A35C 0C0A3E53 */  jal        func_8028F94C
/* 3F70 8038A360 8FA50028 */   lw        $a1, 0x28($sp)
/* 3F74 8038A364 8FA9002C */  lw         $t1, 0x2c($sp)
/* 3F78 8038A368 912A0007 */  lbu        $t2, 7($t1)
/* 3F7C 8038A36C 5540000E */  bnel       $t2, $zero, .L8038A3A8
/* 3F80 8038A370 44806000 */   mtc1      $zero, $f12
/* 3F84 8038A374 44806000 */  mtc1       $zero, $f12
/* 3F88 8038A378 0C0C9398 */  jal        timed_setCameraToNode
/* 3F8C 8038A37C 2405000A */   addiu     $a1, $zero, 0xa
/* 3F90 8038A380 3C018039 */  lui        $at, %hi(D_803922F0)
/* 3F94 8038A384 0C0C93A2 */  jal        func_80324E88
/* 3F98 8038A388 C42C22F0 */   lwc1      $f12, %lo(D_803922F0)($at)
/* 3F9C 8038A38C 3C018039 */  lui        $at, %hi(D_803922F4)
/* 3FA0 8038A390 C42C22F4 */  lwc1       $f12, %lo(D_803922F4)($at)
/* 3FA4 8038A394 0C0C9398 */  jal        timed_setCameraToNode
/* 3FA8 8038A398 2405000B */   addiu     $a1, $zero, 0xb
/* 3FAC 8038A39C 1000004E */  b          .L8038A4D8
/* 3FB0 8038A3A0 8FBF0024 */   lw        $ra, 0x24($sp)
/* 3FB4 8038A3A4 44806000 */  mtc1       $zero, $f12
.L8038A3A8:
/* 3FB8 8038A3A8 0C0C9398 */  jal        timed_setCameraToNode
/* 3FBC 8038A3AC 2405000C */   addiu     $a1, $zero, 0xc
/* 3FC0 8038A3B0 3C018039 */  lui        $at, %hi(D_803922F8)
/* 3FC4 8038A3B4 0C0C93A2 */  jal        func_80324E88
/* 3FC8 8038A3B8 C42C22F8 */   lwc1      $f12, %lo(D_803922F8)($at)
/* 3FCC 8038A3BC 3C018039 */  lui        $at, %hi(D_803922FC)
/* 3FD0 8038A3C0 C42C22FC */  lwc1       $f12, %lo(D_803922FC)($at)
/* 3FD4 8038A3C4 0C0C9398 */  jal        timed_setCameraToNode
/* 3FD8 8038A3C8 2405000D */   addiu     $a1, $zero, 0xd
/* 3FDC 8038A3CC 10000042 */  b          .L8038A4D8
/* 3FE0 8038A3D0 8FBF0024 */   lw        $ra, 0x24($sp)
/* 3FE4 8038A3D4 0C0CA62B */  jal        actor_playAnimationOnce
/* 3FE8 8038A3D8 02002025 */   or        $a0, $s0, $zero
/* 3FEC 8038A3DC 00002025 */  or         $a0, $zero, $zero
/* 3FF0 8038A3E0 0C0D29EF */  jal        randi2
/* 3FF4 8038A3E4 24050005 */   addiu     $a1, $zero, 5
/* 3FF8 8038A3E8 24441145 */  addiu      $a0, $v0, 0x1145
/* 3FFC 8038A3EC 24050020 */  addiu      $a1, $zero, 0x20
/* 4000 8038A3F0 00003025 */  or         $a2, $zero, $zero
/* 4004 8038A3F4 00003825 */  or         $a3, $zero, $zero
/* 4008 8038A3F8 AFA00010 */  sw         $zero, 0x10($sp)
/* 400C 8038A3FC 0C0C4520 */  jal        func_80311480
/* 4010 8038A400 AFA00014 */   sw        $zero, 0x14($sp)
/* 4014 8038A404 3C018039 */  lui        $at, %hi(D_80392300)
/* 4018 8038A408 C42C2300 */  lwc1       $f12, %lo(D_80392300)($at)
/* 401C 8038A40C 3C018039 */  lui        $at, %hi(D_80392304)
/* 4020 8038A410 0C0D29D5 */  jal        randf2
/* 4024 8038A414 C42E2304 */   lwc1      $f14, %lo(D_80392304)($at)
/* 4028 8038A418 44050000 */  mfc1       $a1, $f0
/* 402C 8038A41C 2404001F */  addiu      $a0, $zero, 0x1f
/* 4030 8038A420 0C0C39A9 */  jal        func_8030E6A4
/* 4034 8038A424 24067D00 */   addiu     $a2, $zero, 0x7d00
/* 4038 8038A428 3C018039 */  lui        $at, %hi(D_80392308)
/* 403C 8038A42C C42C2308 */  lwc1       $f12, %lo(D_80392308)($at)
/* 4040 8038A430 3C018039 */  lui        $at, %hi(D_8039230C)
/* 4044 8038A434 0C0D29D5 */  jal        randf2
/* 4048 8038A438 C42E230C */   lwc1      $f14, %lo(D_8039230C)($at)
/* 404C 8038A43C 44050000 */  mfc1       $a1, $f0
/* 4050 8038A440 24040133 */  addiu      $a0, $zero, 0x133
/* 4054 8038A444 0C0C39A9 */  jal        func_8030E6A4
/* 4058 8038A448 24067D00 */   addiu     $a2, $zero, 0x7d00
/* 405C 8038A44C 0C0C3643 */  jal        func_8030D90C
/* 4060 8038A450 00000000 */   nop
/* 4064 8038A454 3C013F80 */  lui        $at, 0x3f80
/* 4068 8038A458 44818000 */  mtc1       $at, $f16
/* 406C 8038A45C A2020044 */  sb         $v0, 0x44($s0)
/* 4070 8038A460 3C018039 */  lui        $at, %hi(D_803927C0)
/* 4074 8038A464 E43027C0 */  swc1       $f16, %lo(D_803927C0)($at)
/* 4078 8038A468 92040044 */  lbu        $a0, 0x44($s0)
/* 407C 8038A46C 0C0C36A0 */  jal        sfxsource_setSfxId
/* 4080 8038A470 2405002C */   addiu     $a1, $zero, 0x2c
/* 4084 8038A474 92040044 */  lbu        $a0, 0x44($s0)
/* 4088 8038A478 0C0C3745 */  jal        func_8030DD14
/* 408C 8038A47C 24050002 */   addiu     $a1, $zero, 2
/* 4090 8038A480 3C058039 */  lui        $a1, %hi(D_803927C0)
/* 4094 8038A484 8CA527C0 */  lw         $a1, %lo(D_803927C0)($a1)
/* 4098 8038A488 0C0C36ED */  jal        func_8030DBB4
/* 409C 8038A48C 92040044 */   lbu       $a0, 0x44($s0)
/* 40A0 8038A490 92040044 */  lbu        $a0, 0x44($s0)
/* 40A4 8038A494 0C0C36AF */  jal        sfxsource_setSampleRate
/* 40A8 8038A498 24056590 */   addiu     $a1, $zero, 0x6590
/* 40AC 8038A49C 3C028039 */  lui        $v0, %hi(D_803927B0)
/* 40B0 8038A4A0 244227B0 */  addiu      $v0, $v0, %lo(D_803927B0)
/* 40B4 8038A4A4 8C440000 */  lw         $a0, ($v0)
.L8038A4A8:
/* 40B8 8038A4A8 10800005 */  beqz       $a0, .L8038A4C0
/* 40BC 8038A4AC 00000000 */   nop
/* 40C0 8038A4B0 0C0CA0BD */  jal        marker_despawn
/* 40C4 8038A4B4 AFA2002C */   sw        $v0, 0x2c($sp)
/* 40C8 8038A4B8 8FA2002C */  lw         $v0, 0x2c($sp)
/* 40CC 8038A4BC AC400000 */  sw         $zero, ($v0)
.L8038A4C0:
/* 40D0 8038A4C0 3C0B8039 */  lui        $t3, %hi(D_803927C0)
/* 40D4 8038A4C4 256B27C0 */  addiu      $t3, $t3, %lo(D_803927C0)
/* 40D8 8038A4C8 24420004 */  addiu      $v0, $v0, 4
/* 40DC 8038A4CC 544BFFF6 */  bnel       $v0, $t3, .L8038A4A8
/* 40E0 8038A4D0 8C440000 */   lw        $a0, ($v0)
.L8038A4D4:
/* 40E4 8038A4D4 8FBF0024 */  lw         $ra, 0x24($sp)
.L8038A4D8:
/* 40E8 8038A4D8 8FB00020 */  lw         $s0, 0x20($sp)
/* 40EC 8038A4DC 27BD0050 */  addiu      $sp, $sp, 0x50
/* 40F0 8038A4E0 03E00008 */  jr         $ra
/* 40F4 8038A4E4 00000000 */   nop
glabel func_8038A4E8
/* 40F8 8038A4E8 27BDFFD0 */  addiu      $sp, $sp, -0x30
/* 40FC 8038A4EC 44856000 */  mtc1       $a1, $f12
/* 4100 8038A4F0 AFBF002C */  sw         $ra, 0x2c($sp)
/* 4104 8038A4F4 AFB50028 */  sw         $s5, 0x28($sp)
/* 4108 8038A4F8 AFB40024 */  sw         $s4, 0x24($sp)
/* 410C 8038A4FC AFB30020 */  sw         $s3, 0x20($sp)
/* 4110 8038A500 AFB2001C */  sw         $s2, 0x1c($sp)
/* 4114 8038A504 AFB10018 */  sw         $s1, 0x18($sp)
/* 4118 8038A508 AFB00014 */  sw         $s0, 0x14($sp)
/* 411C 8038A50C 44056000 */  mfc1       $a1, $f12
/* 4120 8038A510 8C840000 */  lw         $a0, ($a0)
/* 4124 8038A514 0C0C83B6 */  jal        func_80320ED8
/* 4128 8038A518 24060001 */   addiu     $a2, $zero, 1
/* 412C 8038A51C 0C0CBD4A */  jal        func_8032F528
/* 4130 8038A520 00000000 */   nop
/* 4134 8038A524 10400029 */  beqz       $v0, .L8038A5CC
/* 4138 8038A528 00401825 */   or        $v1, $v0, $zero
/* 413C 8038A52C 24140285 */  addiu      $s4, $zero, 0x285
/* 4140 8038A530 2413027E */  addiu      $s3, $zero, 0x27e
/* 4144 8038A534 2412027D */  addiu      $s2, $zero, 0x27d
/* 4148 8038A538 2411027C */  addiu      $s1, $zero, 0x27c
/* 414C 8038A53C 2410027B */  addiu      $s0, $zero, 0x27b
.L8038A540:
/* 4150 8038A540 8C4E0008 */  lw         $t6, 8($v0)
/* 4154 8038A544 31CF0001 */  andi       $t7, $t6, 1
/* 4158 8038A548 11E0001C */  beqz       $t7, .L8038A5BC
/* 415C 8038A54C 00000000 */   nop
/* 4160 8038A550 0C0CA656 */  jal        marker_getActor
/* 4164 8038A554 8C640000 */   lw        $a0, ($v1)
/* 4168 8038A558 8C580000 */  lw         $t8, ($v0)
/* 416C 8038A55C 0040A825 */  or         $s5, $v0, $zero
/* 4170 8038A560 8F030014 */  lw         $v1, 0x14($t8)
/* 4174 8038A564 0003CAC0 */  sll        $t9, $v1, 0xb
/* 4178 8038A568 00194582 */  srl        $t0, $t9, 0x16
/* 417C 8038A56C 11100009 */  beq        $t0, $s0, .L8038A594
/* 4180 8038A570 00000000 */   nop
/* 4184 8038A574 11110007 */  beq        $t0, $s1, .L8038A594
/* 4188 8038A578 00000000 */   nop
/* 418C 8038A57C 11120005 */  beq        $t0, $s2, .L8038A594
/* 4190 8038A580 00000000 */   nop
/* 4194 8038A584 11130003 */  beq        $t0, $s3, .L8038A594
/* 4198 8038A588 00000000 */   nop
/* 419C 8038A58C 1514000B */  bne        $t0, $s4, .L8038A5BC
/* 41A0 8038A590 00000000 */   nop
.L8038A594:
/* 41A4 8038A594 0C0CBD4A */  jal        func_8032F528
/* 41A8 8038A598 00000000 */   nop
/* 41AC 8038A59C 10400005 */  beqz       $v0, .L8038A5B4
/* 41B0 8038A5A0 00000000 */   nop
.L8038A5A4:
/* 41B4 8038A5A4 0C0CBD4A */  jal        func_8032F528
/* 41B8 8038A5A8 00000000 */   nop
/* 41BC 8038A5AC 1440FFFD */  bnez       $v0, .L8038A5A4
/* 41C0 8038A5B0 00000000 */   nop
.L8038A5B4:
/* 41C4 8038A5B4 10000006 */  b          .L8038A5D0
/* 41C8 8038A5B8 8EA20000 */   lw        $v0, ($s5)
.L8038A5BC:
/* 41CC 8038A5BC 0C0CBD4A */  jal        func_8032F528
/* 41D0 8038A5C0 00000000 */   nop
/* 41D4 8038A5C4 1440FFDE */  bnez       $v0, .L8038A540
/* 41D8 8038A5C8 00401825 */   or        $v1, $v0, $zero
.L8038A5CC:
/* 41DC 8038A5CC 00001025 */  or         $v0, $zero, $zero
.L8038A5D0:
/* 41E0 8038A5D0 8FBF002C */  lw         $ra, 0x2c($sp)
/* 41E4 8038A5D4 8FB00014 */  lw         $s0, 0x14($sp)
/* 41E8 8038A5D8 8FB10018 */  lw         $s1, 0x18($sp)
/* 41EC 8038A5DC 8FB2001C */  lw         $s2, 0x1c($sp)
/* 41F0 8038A5E0 8FB30020 */  lw         $s3, 0x20($sp)
/* 41F4 8038A5E4 8FB40024 */  lw         $s4, 0x24($sp)
/* 41F8 8038A5E8 8FB50028 */  lw         $s5, 0x28($sp)
/* 41FC 8038A5EC 03E00008 */  jr         $ra
/* 4200 8038A5F0 27BD0030 */   addiu     $sp, $sp, 0x30
glabel func_8038A5F4
/* 4204 8038A5F4 27BDFF80 */  addiu      $sp, $sp, -0x80
/* 4208 8038A5F8 AFBF002C */  sw         $ra, 0x2c($sp)
/* 420C 8038A5FC 0C0CA656 */  jal        marker_getActor
/* 4210 8038A600 AFB00028 */   sw        $s0, 0x28($sp)
/* 4214 8038A604 244E007C */  addiu      $t6, $v0, 0x7c
/* 4218 8038A608 00408025 */  or         $s0, $v0, $zero
/* 421C 8038A60C 0C0CF767 */  jal        time_getDelta
/* 4220 8038A610 AFAE0078 */   sw        $t6, 0x78($sp)
/* 4224 8038A614 8FAF0078 */  lw         $t7, 0x78($sp)
/* 4228 8038A618 E7A00074 */  swc1       $f0, 0x74($sp)
/* 422C 8038A61C 91F80001 */  lbu        $t8, 1($t7)
/* 4230 8038A620 AFB80070 */  sw         $t8, 0x70($sp)
/* 4234 8038A624 0C0CC8A7 */  jal        func_8033229C
/* 4238 8038A628 8E040000 */   lw        $a0, ($s0)
/* 423C 8038A62C 44050000 */  mfc1       $a1, $f0
/* 4240 8038A630 0C0E293A */  jal        func_8038A4E8
/* 4244 8038A634 02002025 */   or        $a0, $s0, $zero
/* 4248 8038A638 10400044 */  beqz       $v0, .L8038A74C
/* 424C 8038A63C 00402025 */   or        $a0, $v0, $zero
/* 4250 8038A640 0C0E3485 */  jal        func_8038D214
/* 4254 8038A644 AFA2006C */   sw        $v0, 0x6c($sp)
/* 4258 8038A648 0C0C7FC7 */  jal        func_8031FF1C
/* 425C 8038A64C 240400D1 */   addiu     $a0, $zero, 0xd1
/* 4260 8038A650 1440000D */  bnez       $v0, .L8038A688
/* 4264 8038A654 240400D1 */   addiu     $a0, $zero, 0xd1
/* 4268 8038A658 0C0C8001 */  jal        func_80320004
/* 426C 8038A65C 24050001 */   addiu     $a1, $zero, 1
/* 4270 8038A660 3C018039 */  lui        $at, %hi(D_803927C4)
/* 4274 8038A664 A02027C4 */  sb         $zero, %lo(D_803927C4)($at)
/* 4278 8038A668 3C013F80 */  lui        $at, 0x3f80
/* 427C 8038A66C 44816000 */  mtc1       $at, $f12
/* 4280 8038A670 0C0C93A2 */  jal        func_80324E88
/* 4284 8038A674 00000000 */   nop
/* 4288 8038A678 3C013F80 */  lui        $at, 0x3f80
/* 428C 8038A67C 44816000 */  mtc1       $at, $f12
/* 4290 8038A680 0C0C938E */  jal        func_80324E38
/* 4294 8038A684 00002825 */   or        $a1, $zero, $zero
.L8038A688:
/* 4298 8038A688 8FB90078 */  lw         $t9, 0x78($sp)
/* 429C 8038A68C 24050005 */  addiu      $a1, $zero, 5
/* 42A0 8038A690 93230001 */  lbu        $v1, 1($t9)
/* 42A4 8038A694 1460000D */  bnez       $v1, .L8038A6CC
/* 42A8 8038A698 00602025 */   or        $a0, $v1, $zero
/* 42AC 8038A69C 0C0D29EF */  jal        randi2
/* 42B0 8038A6A0 00002025 */   or        $a0, $zero, $zero
/* 42B4 8038A6A4 24441140 */  addiu      $a0, $v0, 0x1140
/* 42B8 8038A6A8 24050020 */  addiu      $a1, $zero, 0x20
/* 42BC 8038A6AC 00003025 */  or         $a2, $zero, $zero
/* 42C0 8038A6B0 00003825 */  or         $a3, $zero, $zero
/* 42C4 8038A6B4 AFA00010 */  sw         $zero, 0x10($sp)
/* 42C8 8038A6B8 0C0C4520 */  jal        func_80311480
/* 42CC 8038A6BC AFA00014 */   sw        $zero, 0x14($sp)
/* 42D0 8038A6C0 8FA80078 */  lw         $t0, 0x78($sp)
/* 42D4 8038A6C4 91030001 */  lbu        $v1, 1($t0)
/* 42D8 8038A6C8 00602025 */  or         $a0, $v1, $zero
.L8038A6CC:
/* 42DC 8038A6CC 24890001 */  addiu      $t1, $a0, 1
/* 42E0 8038A6D0 29210004 */  slti       $at, $t1, 4
/* 42E4 8038A6D4 10200008 */  beqz       $at, .L8038A6F8
/* 42E8 8038A6D8 246A0001 */   addiu     $t2, $v1, 1
/* 42EC 8038A6DC 8FAB0078 */  lw         $t3, 0x78($sp)
/* 42F0 8038A6E0 02002025 */  or         $a0, $s0, $zero
/* 42F4 8038A6E4 24050020 */  addiu      $a1, $zero, 0x20
/* 42F8 8038A6E8 0C0E27DF */  jal        func_80389F7C
/* 42FC 8038A6EC A16A0001 */   sb        $t2, 1($t3)
/* 4300 8038A6F0 10000153 */  b          .L8038AC40
/* 4304 8038A6F4 8FBF002C */   lw        $ra, 0x2c($sp)
.L8038A6F8:
/* 4308 8038A6F8 0C0CA656 */  jal        marker_getActor
/* 430C 8038A6FC 8FA4006C */   lw        $a0, 0x6c($sp)
/* 4310 8038A700 8C4C0000 */  lw         $t4, ($v0)
/* 4314 8038A704 2401027B */  addiu      $at, $zero, 0x27b
/* 4318 8038A708 8FAF0078 */  lw         $t7, 0x78($sp)
/* 431C 8038A70C 8D830014 */  lw         $v1, 0x14($t4)
/* 4320 8038A710 02002025 */  or         $a0, $s0, $zero
/* 4324 8038A714 00036AC0 */  sll        $t5, $v1, 0xb
/* 4328 8038A718 000D7582 */  srl        $t6, $t5, 0x16
/* 432C 8038A71C 11C10003 */  beq        $t6, $at, .L8038A72C
/* 4330 8038A720 2401027E */   addiu     $at, $zero, 0x27e
/* 4334 8038A724 15C10003 */  bne        $t6, $at, .L8038A734
/* 4338 8038A728 8FB90078 */   lw        $t9, 0x78($sp)
.L8038A72C:
/* 433C 8038A72C 10000003 */  b          .L8038A73C
/* 4340 8038A730 A1E00007 */   sb        $zero, 7($t7)
.L8038A734:
/* 4344 8038A734 24180001 */  addiu      $t8, $zero, 1
/* 4348 8038A738 A3380007 */  sb         $t8, 7($t9)
.L8038A73C:
/* 434C 8038A73C 0C0E27DF */  jal        func_80389F7C
/* 4350 8038A740 24050021 */   addiu     $a1, $zero, 0x21
/* 4354 8038A744 1000013E */  b          .L8038AC40
/* 4358 8038A748 8FBF002C */   lw        $ra, 0x2c($sp)
.L8038A74C:
/* 435C 8038A74C 8E080010 */  lw         $t0, 0x10($s0)
/* 4360 8038A750 00084E82 */  srl        $t1, $t0, 0x1a
/* 4364 8038A754 252AFFE4 */  addiu      $t2, $t1, -0x1c
/* 4368 8038A758 2D410007 */  sltiu      $at, $t2, 7
/* 436C 8038A75C 10200137 */  beqz       $at, .L8038AC3C
/* 4370 8038A760 000A5080 */   sll       $t2, $t2, 2
/* 4374 8038A764 3C018039 */  lui        $at, %hi(D_80392310)
/* 4378 8038A768 002A0821 */  addu       $at, $at, $t2
/* 437C 8038A76C 8C2A2310 */  lw         $t2, %lo(D_80392310)($at)
/* 4380 8038A770 01400008 */  jr         $t2
/* 4384 8038A774 00000000 */   nop
/* 4388 8038A778 0C0E1A6F */  jal        func_803869BC
/* 438C 8038A77C 02002025 */   or        $a0, $s0, $zero
/* 4390 8038A780 3C0143FA */  lui        $at, 0x43fa
/* 4394 8038A784 44810000 */  mtc1       $at, $f0
/* 4398 8038A788 3C01430C */  lui        $at, 0x430c
/* 439C 8038A78C 44812000 */  mtc1       $at, $f4
/* 43A0 8038A790 3C0142F0 */  lui        $at, 0x42f0
/* 43A4 8038A794 44813000 */  mtc1       $at, $f6
/* 43A8 8038A798 44060000 */  mfc1       $a2, $f0
/* 43AC 8038A79C 02002025 */  or         $a0, $s0, $zero
/* 43B0 8038A7A0 2605001C */  addiu      $a1, $s0, 0x1c
/* 43B4 8038A7A4 3C07447A */  lui        $a3, 0x447a
/* 43B8 8038A7A8 E7A00014 */  swc1       $f0, 0x14($sp)
/* 43BC 8038A7AC E7A40010 */  swc1       $f4, 0x10($sp)
/* 43C0 8038A7B0 0C0E1D1C */  jal        func_80387470
/* 43C4 8038A7B4 E7A60018 */   swc1      $f6, 0x18($sp)
/* 43C8 8038A7B8 10400120 */  beqz       $v0, .L8038AC3C
/* 43CC 8038A7BC 02002025 */   or        $a0, $s0, $zero
/* 43D0 8038A7C0 0C0E27DF */  jal        func_80389F7C
/* 43D4 8038A7C4 2405001D */   addiu     $a1, $zero, 0x1d
/* 43D8 8038A7C8 1000011D */  b          .L8038AC40
/* 43DC 8038A7CC 8FBF002C */   lw        $ra, 0x2c($sp)
/* 43E0 8038A7D0 02002025 */  or         $a0, $s0, $zero
/* 43E4 8038A7D4 0C0E1AFB */  jal        func_80386BEC
/* 43E8 8038A7D8 3C054110 */   lui       $a1, 0x4110
/* 43EC 8038A7DC 50400118 */  beql       $v0, $zero, .L8038AC40
/* 43F0 8038A7E0 8FBF002C */   lw        $ra, 0x2c($sp)
/* 43F4 8038A7E4 0C0A5F1B */  jal        func_80297C6C
/* 43F8 8038A7E8 00000000 */   nop
/* 43FC 8038A7EC 24010003 */  addiu      $at, $zero, 3
/* 4400 8038A7F0 10410112 */  beq        $v0, $at, .L8038AC3C
/* 4404 8038A7F4 3C0B8039 */   lui       $t3, %hi(D_803927C4)
/* 4408 8038A7F8 916B27C4 */  lbu        $t3, %lo(D_803927C4)($t3)
/* 440C 8038A7FC 02002025 */  or         $a0, $s0, $zero
/* 4410 8038A800 5560010F */  bnel       $t3, $zero, .L8038AC40
/* 4414 8038A804 8FBF002C */   lw        $ra, 0x2c($sp)
/* 4418 8038A808 0C0E27DF */  jal        func_80389F7C
/* 441C 8038A80C 2405001E */   addiu     $a1, $zero, 0x1e
/* 4420 8038A810 1000010B */  b          .L8038AC40
/* 4424 8038A814 8FBF002C */   lw        $ra, 0x2c($sp)
/* 4428 8038A818 02002025 */  or         $a0, $s0, $zero
/* 442C 8038A81C 0C0E1AFB */  jal        func_80386BEC
/* 4430 8038A820 3C054040 */   lui       $a1, 0x4040
/* 4434 8038A824 3C0C8039 */  lui        $t4, %hi(D_803927C4)
/* 4438 8038A828 918C27C4 */  lbu        $t4, %lo(D_803927C4)($t4)
/* 443C 8038A82C 3C053F80 */  lui        $a1, 0x3f80
/* 4440 8038A830 02002025 */  or         $a0, $s0, $zero
/* 4444 8038A834 15800016 */  bnez       $t4, .L8038A890
/* 4448 8038A838 00000000 */   nop
/* 444C 8038A83C 0C0E1CD0 */  jal        func_80387340
/* 4450 8038A840 02002025 */   or        $a0, $s0, $zero
/* 4454 8038A844 3C053F7F */  lui        $a1, 0x3f7f
/* 4458 8038A848 34A5F972 */  ori        $a1, $a1, 0xf972
/* 445C 8038A84C 0C0CA21B */  jal        actor_animationIsAt
/* 4460 8038A850 02002025 */   or        $a0, $s0, $zero
/* 4464 8038A854 104000F9 */  beqz       $v0, .L8038AC3C
/* 4468 8038A858 8FAD0078 */   lw        $t5, 0x78($sp)
/* 446C 8038A85C 91AE0003 */  lbu        $t6, 3($t5)
/* 4470 8038A860 02002025 */  or         $a0, $s0, $zero
/* 4474 8038A864 2405001F */  addiu      $a1, $zero, 0x1f
/* 4478 8038A868 25CF0001 */  addiu      $t7, $t6, 1
/* 447C 8038A86C 0C0E27DF */  jal        func_80389F7C
/* 4480 8038A870 A1AF0003 */   sb        $t7, 3($t5)
/* 4484 8038A874 8FB80070 */  lw         $t8, 0x70($sp)
/* 4488 8038A878 3C018039 */  lui        $at, %hi(D_803917D0)
/* 448C 8038A87C 0018C880 */  sll        $t9, $t8, 2
/* 4490 8038A880 00390821 */  addu       $at, $at, $t9
/* 4494 8038A884 C42817D0 */  lwc1       $f8, %lo(D_803917D0)($at)
/* 4498 8038A888 100000EC */  b          .L8038AC3C
/* 449C 8038A88C E6080060 */   swc1      $f8, 0x60($s0)
.L8038A890:
/* 44A0 8038A890 0C0E27DF */  jal        func_80389F7C
/* 44A4 8038A894 2405001D */   addiu     $a1, $zero, 0x1d
/* 44A8 8038A898 100000E9 */  b          .L8038AC40
/* 44AC 8038A89C 8FBF002C */   lw        $ra, 0x2c($sp)
/* 44B0 8038A8A0 02002025 */  or         $a0, $s0, $zero
/* 44B4 8038A8A4 0C0E1AFB */  jal        func_80386BEC
/* 44B8 8038A8A8 3C054040 */   lui       $a1, 0x4040
/* 44BC 8038A8AC C6000060 */  lwc1       $f0, 0x60($s0)
/* 44C0 8038A8B0 44805800 */  mtc1       $zero, $f11
/* 44C4 8038A8B4 44805000 */  mtc1       $zero, $f10
/* 44C8 8038A8B8 46000421 */  cvt.d.s    $f16, $f0
/* 44CC 8038A8BC C7B20074 */  lwc1       $f18, 0x74($sp)
/* 44D0 8038A8C0 4630503C */  c.lt.d     $f10, $f16
/* 44D4 8038A8C4 02002025 */  or         $a0, $s0, $zero
/* 44D8 8038A8C8 45000004 */  bc1f       .L8038A8DC
/* 44DC 8038A8CC 00000000 */   nop
/* 44E0 8038A8D0 46120101 */  sub.s      $f4, $f0, $f18
/* 44E4 8038A8D4 100000D9 */  b          .L8038AC3C
/* 44E8 8038A8D8 E6040060 */   swc1      $f4, 0x60($s0)
.L8038A8DC:
/* 44EC 8038A8DC 0C0E1AFB */  jal        func_80386BEC
/* 44F0 8038A8E0 3C054040 */   lui       $a1, 0x4040
/* 44F4 8038A8E4 104000D5 */  beqz       $v0, .L8038AC3C
/* 44F8 8038A8E8 02002025 */   or        $a0, $s0, $zero
/* 44FC 8038A8EC 0C0E27DF */  jal        func_80389F7C
/* 4500 8038A8F0 2405001E */   addiu     $a1, $zero, 0x1e
/* 4504 8038A8F4 100000D2 */  b          .L8038AC40
/* 4508 8038A8F8 8FBF002C */   lw        $ra, 0x2c($sp)
/* 450C 8038A8FC 3C053F7F */  lui        $a1, 0x3f7f
/* 4510 8038A900 34A5F972 */  ori        $a1, $a1, 0xf972
/* 4514 8038A904 0C0CA21B */  jal        actor_animationIsAt
/* 4518 8038A908 02002025 */   or        $a0, $s0, $zero
/* 451C 8038A90C 104000CB */  beqz       $v0, .L8038AC3C
/* 4520 8038A910 02002025 */   or        $a0, $s0, $zero
/* 4524 8038A914 0C0E27DF */  jal        func_80389F7C
/* 4528 8038A918 2405001C */   addiu     $a1, $zero, 0x1c
/* 452C 8038A91C 100000C8 */  b          .L8038AC40
/* 4530 8038A920 8FBF002C */   lw        $ra, 0x2c($sp)
/* 4534 8038A924 02002025 */  or         $a0, $s0, $zero
/* 4538 8038A928 0C0E1AFB */  jal        func_80386BEC
/* 453C 8038A92C 3C054040 */   lui       $a1, 0x4040
/* 4540 8038A930 C7A00074 */  lwc1       $f0, 0x74($sp)
/* 4544 8038A934 C606002C */  lwc1       $f6, 0x2c($s0)
/* 4548 8038A938 C60A0004 */  lwc1       $f10, 4($s0)
/* 454C 8038A93C 27A4005C */  addiu      $a0, $sp, 0x5c
/* 4550 8038A940 46003202 */  mul.s      $f8, $f6, $f0
/* 4554 8038A944 460A4400 */  add.s      $f16, $f8, $f10
/* 4558 8038A948 E7B0005C */  swc1       $f16, 0x5c($sp)
/* 455C 8038A94C C6120030 */  lwc1       $f18, 0x30($s0)
/* 4560 8038A950 C6060008 */  lwc1       $f6, 8($s0)
/* 4564 8038A954 46009102 */  mul.s      $f4, $f18, $f0
/* 4568 8038A958 46062200 */  add.s      $f8, $f4, $f6
/* 456C 8038A95C E7A80060 */  swc1       $f8, 0x60($sp)
/* 4570 8038A960 C60A0034 */  lwc1       $f10, 0x34($s0)
/* 4574 8038A964 C612000C */  lwc1       $f18, 0xc($s0)
/* 4578 8038A968 46005402 */  mul.s      $f16, $f10, $f0
/* 457C 8038A96C 46128100 */  add.s      $f4, $f16, $f18
/* 4580 8038A970 0C0C25C9 */  jal        func_80309724
/* 4584 8038A974 E7A40064 */   swc1      $f4, 0x64($sp)
/* 4588 8038A978 C7A60060 */  lwc1       $f6, 0x60($sp)
/* 458C 8038A97C 46000086 */  mov.s      $f2, $f0
/* 4590 8038A980 C7A8005C */  lwc1       $f8, 0x5c($sp)
/* 4594 8038A984 4600303C */  c.lt.s     $f6, $f0
/* 4598 8038A988 C7B2005C */  lwc1       $f18, 0x5c($sp)
/* 459C 8038A98C 4502001F */  bc1fl      .L8038AA0C
/* 45A0 8038A990 E6120004 */   swc1      $f18, 4($s0)
/* 45A4 8038A994 E6080004 */  swc1       $f8, 4($s0)
/* 45A8 8038A998 C7AA0060 */  lwc1       $f10, 0x60($sp)
/* 45AC 8038A99C 02002025 */  or         $a0, $s0, $zero
/* 45B0 8038A9A0 24050022 */  addiu      $a1, $zero, 0x22
/* 45B4 8038A9A4 E60A0008 */  swc1       $f10, 8($s0)
/* 45B8 8038A9A8 C7B00064 */  lwc1       $f16, 0x64($sp)
/* 45BC 8038A9AC E6020008 */  swc1       $f2, 8($s0)
/* 45C0 8038A9B0 0C0E27DF */  jal        func_80389F7C
/* 45C4 8038A9B4 E610000C */   swc1      $f16, 0xc($s0)
/* 45C8 8038A9B8 3C018039 */  lui        $at, %hi(D_8039232C)
/* 45CC 8038A9BC C42C232C */  lwc1       $f12, %lo(D_8039232C)($at)
/* 45D0 8038A9C0 3C018039 */  lui        $at, %hi(D_80392330)
/* 45D4 8038A9C4 0C0D29D5 */  jal        randf2
/* 45D8 8038A9C8 C42E2330 */   lwc1      $f14, %lo(D_80392330)($at)
/* 45DC 8038A9CC 44050000 */  mfc1       $a1, $f0
/* 45E0 8038A9D0 2404001F */  addiu      $a0, $zero, 0x1f
/* 45E4 8038A9D4 0C0C39A9 */  jal        func_8030E6A4
/* 45E8 8038A9D8 24067D00 */   addiu     $a2, $zero, 0x7d00
/* 45EC 8038A9DC 3C018039 */  lui        $at, %hi(D_80392334)
/* 45F0 8038A9E0 C42C2334 */  lwc1       $f12, %lo(D_80392334)($at)
/* 45F4 8038A9E4 3C018039 */  lui        $at, %hi(D_80392338)
/* 45F8 8038A9E8 0C0D29D5 */  jal        randf2
/* 45FC 8038A9EC C42E2338 */   lwc1      $f14, %lo(D_80392338)($at)
/* 4600 8038A9F0 44050000 */  mfc1       $a1, $f0
/* 4604 8038A9F4 24040132 */  addiu      $a0, $zero, 0x132
/* 4608 8038A9F8 0C0C39A9 */  jal        func_8030E6A4
/* 460C 8038A9FC 24067D00 */   addiu     $a2, $zero, 0x7d00
/* 4610 8038AA00 1000008F */  b          .L8038AC40
/* 4614 8038AA04 8FBF002C */   lw        $ra, 0x2c($sp)
/* 4618 8038AA08 E6120004 */  swc1       $f18, 4($s0)
.L8038AA0C:
/* 461C 8038AA0C C7A40060 */  lwc1       $f4, 0x60($sp)
/* 4620 8038AA10 3C01C4AF */  lui        $at, 0xc4af
/* 4624 8038AA14 44814000 */  mtc1       $at, $f8
/* 4628 8038AA18 E6040008 */  swc1       $f4, 8($s0)
/* 462C 8038AA1C C7A60064 */  lwc1       $f6, 0x64($sp)
/* 4630 8038AA20 C6120030 */  lwc1       $f18, 0x30($s0)
/* 4634 8038AA24 E606000C */  swc1       $f6, 0xc($s0)
/* 4638 8038AA28 C7AA0074 */  lwc1       $f10, 0x74($sp)
/* 463C 8038AA2C 460A4402 */  mul.s      $f16, $f8, $f10
/* 4640 8038AA30 46109100 */  add.s      $f4, $f18, $f16
/* 4644 8038AA34 10000081 */  b          .L8038AC3C
/* 4648 8038AA38 E6040030 */   swc1      $f4, 0x30($s0)
/* 464C 8038AA3C 0C0A1DF6 */  jal        animctrl_getAnimTimer
/* 4650 8038AA40 8E040014 */   lw        $a0, 0x14($s0)
/* 4654 8038AA44 3C053E2E */  lui        $a1, 0x3e2e
/* 4658 8038AA48 E7A00058 */  swc1       $f0, 0x58($sp)
/* 465C 8038AA4C 34A5147B */  ori        $a1, $a1, 0x147b
/* 4660 8038AA50 0C0CA21B */  jal        actor_animationIsAt
/* 4664 8038AA54 02002025 */   or        $a0, $s0, $zero
/* 4668 8038AA58 10400012 */  beqz       $v0, .L8038AAA4
/* 466C 8038AA5C 3C018039 */   lui       $at, %hi(D_8039233C)
/* 4670 8038AA60 C42C233C */  lwc1       $f12, %lo(D_8039233C)($at)
/* 4674 8038AA64 3C018039 */  lui        $at, %hi(D_80392340)
/* 4678 8038AA68 0C0D29D5 */  jal        randf2
/* 467C 8038AA6C C42E2340 */   lwc1      $f14, %lo(D_80392340)($at)
/* 4680 8038AA70 44050000 */  mfc1       $a1, $f0
/* 4684 8038AA74 2404001F */  addiu      $a0, $zero, 0x1f
/* 4688 8038AA78 0C0C39A9 */  jal        func_8030E6A4
/* 468C 8038AA7C 24067D00 */   addiu     $a2, $zero, 0x7d00
/* 4690 8038AA80 3C018039 */  lui        $at, %hi(D_80392344)
/* 4694 8038AA84 C42C2344 */  lwc1       $f12, %lo(D_80392344)($at)
/* 4698 8038AA88 3C018039 */  lui        $at, %hi(D_80392348)
/* 469C 8038AA8C 0C0D29D5 */  jal        randf2
/* 46A0 8038AA90 C42E2348 */   lwc1      $f14, %lo(D_80392348)($at)
/* 46A4 8038AA94 44050000 */  mfc1       $a1, $f0
/* 46A8 8038AA98 24040133 */  addiu      $a0, $zero, 0x133
/* 46AC 8038AA9C 0C0C39A9 */  jal        func_8030E6A4
/* 46B0 8038AAA0 24067D00 */   addiu     $a2, $zero, 0x7d00
.L8038AAA4:
/* 46B4 8038AAA4 3C053DCC */  lui        $a1, 0x3dcc
/* 46B8 8038AAA8 34A5CCCD */  ori        $a1, $a1, 0xcccd
/* 46BC 8038AAAC 0C0CA21B */  jal        actor_animationIsAt
/* 46C0 8038AAB0 02002025 */   or        $a0, $s0, $zero
/* 46C4 8038AAB4 10400012 */  beqz       $v0, .L8038AB00
/* 46C8 8038AAB8 3C018039 */   lui       $at, %hi(D_8039234C)
/* 46CC 8038AABC C42C234C */  lwc1       $f12, %lo(D_8039234C)($at)
/* 46D0 8038AAC0 3C018039 */  lui        $at, %hi(D_80392350)
/* 46D4 8038AAC4 0C0D29D5 */  jal        randf2
/* 46D8 8038AAC8 C42E2350 */   lwc1      $f14, %lo(D_80392350)($at)
/* 46DC 8038AACC 44050000 */  mfc1       $a1, $f0
/* 46E0 8038AAD0 2404001F */  addiu      $a0, $zero, 0x1f
/* 46E4 8038AAD4 0C0C39A9 */  jal        func_8030E6A4
/* 46E8 8038AAD8 24067D00 */   addiu     $a2, $zero, 0x7d00
/* 46EC 8038AADC 3C018039 */  lui        $at, %hi(D_80392354)
/* 46F0 8038AAE0 C42C2354 */  lwc1       $f12, %lo(D_80392354)($at)
/* 46F4 8038AAE4 3C018039 */  lui        $at, %hi(D_80392358)
/* 46F8 8038AAE8 0C0D29D5 */  jal        randf2
/* 46FC 8038AAEC C42E2358 */   lwc1      $f14, %lo(D_80392358)($at)
/* 4700 8038AAF0 44050000 */  mfc1       $a1, $f0
/* 4704 8038AAF4 2404012A */  addiu      $a0, $zero, 0x12a
/* 4708 8038AAF8 0C0C39A9 */  jal        func_8030E6A4
/* 470C 8038AAFC 24067D00 */   addiu     $a2, $zero, 0x7d00
.L8038AB00:
/* 4710 8038AB00 C7A60058 */  lwc1       $f6, 0x58($sp)
/* 4714 8038AB04 3C018039 */  lui        $at, %hi(D_80392360)
/* 4718 8038AB08 D4282360 */  ldc1       $f8, %lo(D_80392360)($at)
/* 471C 8038AB0C 46003021 */  cvt.d.s    $f0, $f6
/* 4720 8038AB10 3C018039 */  lui        $at, %hi(D_80392368)
/* 4724 8038AB14 4620403E */  c.le.d     $f8, $f0
/* 4728 8038AB18 00000000 */  nop
/* 472C 8038AB1C 45020026 */  bc1fl      .L8038ABB8
/* 4730 8038AB20 3C053F0F */   lui       $a1, 0x3f0f
/* 4734 8038AB24 D42A2368 */  ldc1       $f10, %lo(D_80392368)($at)
/* 4738 8038AB28 3C028039 */  lui        $v0, %hi(D_803927C0)
/* 473C 8038AB2C 244227C0 */  addiu      $v0, $v0, %lo(D_803927C0)
/* 4740 8038AB30 462A003E */  c.le.d     $f0, $f10
/* 4744 8038AB34 00000000 */  nop
/* 4748 8038AB38 4502001F */  bc1fl      .L8038ABB8
/* 474C 8038AB3C 3C053F0F */   lui       $a1, 0x3f0f
/* 4750 8038AB40 C4520000 */  lwc1       $f18, ($v0)
/* 4754 8038AB44 3C018039 */  lui        $at, %hi(D_80392370)
/* 4758 8038AB48 D42C2370 */  ldc1       $f12, %lo(D_80392370)($at)
/* 475C 8038AB4C 46009421 */  cvt.d.s    $f16, $f18
/* 4760 8038AB50 3C018039 */  lui        $at, %hi(D_80392378)
/* 4764 8038AB54 462C8100 */  add.d      $f4, $f16, $f12
/* 4768 8038AB58 D42E2378 */  ldc1       $f14, %lo(D_80392378)($at)
/* 476C 8038AB5C 462021A0 */  cvt.s.d    $f6, $f4
/* 4770 8038AB60 E4460000 */  swc1       $f6, ($v0)
/* 4774 8038AB64 C4480000 */  lwc1       $f8, ($v0)
/* 4778 8038AB68 46004021 */  cvt.d.s    $f0, $f8
/* 477C 8038AB6C 4620703C */  c.lt.d     $f14, $f0
/* 4780 8038AB70 00000000 */  nop
/* 4784 8038AB74 45020004 */  bc1fl      .L8038AB88
/* 4788 8038AB78 462C0280 */   add.d     $f10, $f0, $f12
/* 478C 8038AB7C 10000006 */  b          .L8038AB98
/* 4790 8038AB80 46207086 */   mov.d     $f2, $f14
/* 4794 8038AB84 462C0280 */  add.d      $f10, $f0, $f12
.L8038AB88:
/* 4798 8038AB88 462054A0 */  cvt.s.d    $f18, $f10
/* 479C 8038AB8C E4520000 */  swc1       $f18, ($v0)
/* 47A0 8038AB90 C4500000 */  lwc1       $f16, ($v0)
/* 47A4 8038AB94 460080A1 */  cvt.d.s    $f2, $f16
.L8038AB98:
/* 47A8 8038AB98 46201120 */  cvt.s.d    $f4, $f2
/* 47AC 8038AB9C 92040044 */  lbu        $a0, 0x44($s0)
/* 47B0 8038ABA0 44052000 */  mfc1       $a1, $f4
/* 47B4 8038ABA4 0C0C36ED */  jal        func_8030DBB4
/* 47B8 8038ABA8 00000000 */   nop
/* 47BC 8038ABAC 0C0C38B1 */  jal        func_8030E2C4
/* 47C0 8038ABB0 92040044 */   lbu       $a0, 0x44($s0)
/* 47C4 8038ABB4 3C053F0F */  lui        $a1, 0x3f0f
.L8038ABB8:
/* 47C8 8038ABB8 34A55C29 */  ori        $a1, $a1, 0x5c29
/* 47CC 8038ABBC 0C0CA21B */  jal        actor_animationIsAt
/* 47D0 8038ABC0 02002025 */   or        $a0, $s0, $zero
/* 47D4 8038ABC4 1040000C */  beqz       $v0, .L8038ABF8
/* 47D8 8038ABC8 02002025 */   or        $a0, $s0, $zero
/* 47DC 8038ABCC 3C018039 */  lui        $at, %hi(D_80392380)
/* 47E0 8038ABD0 C42C2380 */  lwc1       $f12, %lo(D_80392380)($at)
/* 47E4 8038ABD4 3C018039 */  lui        $at, %hi(D_80392384)
/* 47E8 8038ABD8 0C0D29D5 */  jal        randf2
/* 47EC 8038ABDC C42E2384 */   lwc1      $f14, %lo(D_80392384)($at)
/* 47F0 8038ABE0 44050000 */  mfc1       $a1, $f0
/* 47F4 8038ABE4 240400C5 */  addiu      $a0, $zero, 0xc5
/* 47F8 8038ABE8 0C0C39A9 */  jal        func_8030E6A4
/* 47FC 8038ABEC 24067D00 */   addiu     $a2, $zero, 0x7d00
/* 4800 8038ABF0 10000013 */  b          .L8038AC40
/* 4804 8038ABF4 8FBF002C */   lw        $ra, 0x2c($sp)
.L8038ABF8:
/* 4808 8038ABF8 3C053F7F */  lui        $a1, 0x3f7f
/* 480C 8038ABFC 0C0CA21B */  jal        actor_animationIsAt
/* 4810 8038AC00 34A5F972 */   ori       $a1, $a1, 0xf972
/* 4814 8038AC04 5040000E */  beql       $v0, $zero, .L8038AC40
/* 4818 8038AC08 8FBF002C */   lw        $ra, 0x2c($sp)
/* 481C 8038AC0C 44806000 */  mtc1       $zero, $f12
/* 4820 8038AC10 0C0C93A2 */  jal        func_80324E88
/* 4824 8038AC14 00000000 */   nop
/* 4828 8038AC18 44806000 */  mtc1       $zero, $f12
/* 482C 8038AC1C 0C0C938E */  jal        func_80324E38
/* 4830 8038AC20 00002825 */   or        $a1, $zero, $zero
/* 4834 8038AC24 8E040000 */  lw         $a0, ($s0)
/* 4838 8038AC28 0C0E1DCA */  jal        func_80387728
/* 483C 8038AC2C 24050005 */   addiu     $a1, $zero, 5
/* 4840 8038AC30 0C0C3691 */  jal        func_8030DA44
/* 4844 8038AC34 92040044 */   lbu       $a0, 0x44($s0)
/* 4848 8038AC38 A2000044 */  sb         $zero, 0x44($s0)
.L8038AC3C:
/* 484C 8038AC3C 8FBF002C */  lw         $ra, 0x2c($sp)
.L8038AC40:
/* 4850 8038AC40 8FB00028 */  lw         $s0, 0x28($sp)
/* 4854 8038AC44 27BD0080 */  addiu      $sp, $sp, 0x80
/* 4858 8038AC48 03E00008 */  jr         $ra
/* 485C 8038AC4C 00000000 */   nop
glabel func_8038AC50
/* 4860 8038AC50 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 4864 8038AC54 AFBF0014 */  sw         $ra, 0x14($sp)
/* 4868 8038AC58 0C0CA656 */  jal        marker_getActor
/* 486C 8038AC5C 00000000 */   nop
/* 4870 8038AC60 3C0638D1 */  lui        $a2, 0x38d1
/* 4874 8038AC64 34C6B717 */  ori        $a2, $a2, 0xb717
/* 4878 8038AC68 00402025 */  or         $a0, $v0, $zero
/* 487C 8038AC6C 24050024 */  addiu      $a1, $zero, 0x24
/* 4880 8038AC70 0C0CA2E3 */  jal        func_80328B8C
/* 4884 8038AC74 24070001 */   addiu     $a3, $zero, 1
/* 4888 8038AC78 8FBF0014 */  lw         $ra, 0x14($sp)
/* 488C 8038AC7C 27BD0018 */  addiu      $sp, $sp, 0x18
/* 4890 8038AC80 03E00008 */  jr         $ra
/* 4894 8038AC84 00000000 */   nop
glabel func_8038AC88
/* 4898 8038AC88 27BDFFD0 */  addiu      $sp, $sp, -0x30
/* 489C 8038AC8C 240E0012 */  addiu      $t6, $zero, 0x12
/* 48A0 8038AC90 AFBF0024 */  sw         $ra, 0x24($sp)
/* 48A4 8038AC94 AFB00020 */  sw         $s0, 0x20($sp)
/* 48A8 8038AC98 AFA50034 */  sw         $a1, 0x34($sp)
/* 48AC 8038AC9C AFAE0028 */  sw         $t6, 0x28($sp)
/* 48B0 8038ACA0 240F0005 */  addiu      $t7, $zero, 5
/* 48B4 8038ACA4 A08F007C */  sb         $t7, 0x7c($a0)
/* 48B8 8038ACA8 3C0638D1 */  lui        $a2, 0x38d1
/* 48BC 8038ACAC 00808025 */  or         $s0, $a0, $zero
/* 48C0 8038ACB0 34C6B717 */  ori        $a2, $a2, 0xb717
/* 48C4 8038ACB4 8FA50034 */  lw         $a1, 0x34($sp)
/* 48C8 8038ACB8 0C0CA2E3 */  jal        func_80328B8C
/* 48CC 8038ACBC 24070001 */   addiu     $a3, $zero, 1
/* 48D0 8038ACC0 8FB80034 */  lw         $t8, 0x34($sp)
/* 48D4 8038ACC4 2719FFDD */  addiu      $t9, $t8, -0x23
/* 48D8 8038ACC8 2F210009 */  sltiu      $at, $t9, 9
/* 48DC 8038ACCC 102000A8 */  beqz       $at, .L8038AF70
/* 48E0 8038ACD0 0019C880 */   sll       $t9, $t9, 2
/* 48E4 8038ACD4 3C018039 */  lui        $at, %hi(D_80392388)
/* 48E8 8038ACD8 00390821 */  addu       $at, $at, $t9
/* 48EC 8038ACDC 8C392388 */  lw         $t9, %lo(D_80392388)($at)
/* 48F0 8038ACE0 03200008 */  jr         $t9
/* 48F4 8038ACE4 00000000 */   nop
/* 48F8 8038ACE8 00002025 */  or         $a0, $zero, $zero
/* 48FC 8038ACEC 0C0D29EF */  jal        randi2
/* 4900 8038ACF0 24050005 */   addiu     $a1, $zero, 5
/* 4904 8038ACF4 2444114F */  addiu      $a0, $v0, 0x114f
/* 4908 8038ACF8 24050004 */  addiu      $a1, $zero, 4
/* 490C 8038ACFC 00003025 */  or         $a2, $zero, $zero
/* 4910 8038AD00 00003825 */  or         $a3, $zero, $zero
/* 4914 8038AD04 AFA00010 */  sw         $zero, 0x10($sp)
/* 4918 8038AD08 0C0C4520 */  jal        func_80311480
/* 491C 8038AD0C AFA00014 */   sw        $zero, 0x14($sp)
/* 4920 8038AD10 92080083 */  lbu        $t0, 0x83($s0)
/* 4924 8038AD14 24090013 */  addiu      $t1, $zero, 0x13
/* 4928 8038AD18 24040002 */  addiu      $a0, $zero, 2
/* 492C 8038AD1C 11000002 */  beqz       $t0, .L8038AD28
/* 4930 8038AD20 00000000 */   nop
/* 4934 8038AD24 AFA90028 */  sw         $t1, 0x28($sp)
.L8038AD28:
/* 4938 8038AD28 0C0A3E53 */  jal        func_8028F94C
/* 493C 8038AD2C 26050004 */   addiu     $a1, $s0, 4
/* 4940 8038AD30 44806000 */  mtc1       $zero, $f12
/* 4944 8038AD34 3C058039 */  lui        $a1, %hi(func_803898A4)
/* 4948 8038AD38 24A598A4 */  addiu      $a1, $a1, %lo(func_803898A4)
/* 494C 8038AD3C 0C0C93B9 */  jal        timedFunc_set_1
/* 4950 8038AD40 24060005 */   addiu     $a2, $zero, 5
/* 4954 8038AD44 44806000 */  mtc1       $zero, $f12
/* 4958 8038AD48 0C0C9398 */  jal        timed_setCameraToNode
/* 495C 8038AD4C 8FA50028 */   lw        $a1, 0x28($sp)
/* 4960 8038AD50 3C0140F0 */  lui        $at, 0x40f0
/* 4964 8038AD54 44816000 */  mtc1       $at, $f12
/* 4968 8038AD58 0C0C93A2 */  jal        func_80324E88
/* 496C 8038AD5C 00000000 */   nop
/* 4970 8038AD60 3C0140F0 */  lui        $at, 0x40f0
/* 4974 8038AD64 44816000 */  mtc1       $at, $f12
/* 4978 8038AD68 3C058039 */  lui        $a1, %hi(func_8038AC50)
/* 497C 8038AD6C 24A5AC50 */  addiu      $a1, $a1, %lo(func_8038AC50)
/* 4980 8038AD70 0C0C93B9 */  jal        timedFunc_set_1
/* 4984 8038AD74 8E060000 */   lw        $a2, ($s0)
/* 4988 8038AD78 3C0140F0 */  lui        $at, 0x40f0
/* 498C 8038AD7C 44816000 */  mtc1       $at, $f12
/* 4990 8038AD80 0C0C938E */  jal        func_80324E38
/* 4994 8038AD84 00002825 */   or        $a1, $zero, $zero
/* 4998 8038AD88 1000007A */  b          .L8038AF74
/* 499C 8038AD8C 8FBF0024 */   lw        $ra, 0x24($sp)
/* 49A0 8038AD90 0C0E2B14 */  jal        func_8038AC50
/* 49A4 8038AD94 8E040000 */   lw        $a0, ($s0)
/* 49A8 8038AD98 10000076 */  b          .L8038AF74
/* 49AC 8038AD9C 8FBF0024 */   lw        $ra, 0x24($sp)
/* 49B0 8038ADA0 10000073 */  b          .L8038AF70
/* 49B4 8038ADA4 A200007F */   sb        $zero, 0x7f($s0)
/* 49B8 8038ADA8 0C0AED07 */  jal        func_802BB41C
/* 49BC 8038ADAC 00002025 */   or        $a0, $zero, $zero
/* 49C0 8038ADB0 920A0044 */  lbu        $t2, 0x44($s0)
/* 49C4 8038ADB4 5540006F */  bnel       $t2, $zero, .L8038AF74
/* 49C8 8038ADB8 8FBF0024 */   lw        $ra, 0x24($sp)
/* 49CC 8038ADBC 0C0C3643 */  jal        func_8030D90C
/* 49D0 8038ADC0 00000000 */   nop
/* 49D4 8038ADC4 A2020044 */  sb         $v0, 0x44($s0)
/* 49D8 8038ADC8 304400FF */  andi       $a0, $v0, 0xff
/* 49DC 8038ADCC 0C0C36A0 */  jal        sfxsource_setSfxId
/* 49E0 8038ADD0 24050134 */   addiu     $a1, $zero, 0x134
/* 49E4 8038ADD4 92040044 */  lbu        $a0, 0x44($s0)
/* 49E8 8038ADD8 0C0C3745 */  jal        func_8030DD14
/* 49EC 8038ADDC 24050002 */   addiu     $a1, $zero, 2
/* 49F0 8038ADE0 92040044 */  lbu        $a0, 0x44($s0)
/* 49F4 8038ADE4 0C0C36ED */  jal        func_8030DBB4
/* 49F8 8038ADE8 3C053F80 */   lui       $a1, 0x3f80
/* 49FC 8038ADEC 92040044 */  lbu        $a0, 0x44($s0)
/* 4A00 8038ADF0 0C0C36AF */  jal        sfxsource_setSampleRate
/* 4A04 8038ADF4 24054268 */   addiu     $a1, $zero, 0x4268
/* 4A08 8038ADF8 1000005E */  b          .L8038AF74
/* 4A0C 8038ADFC 8FBF0024 */   lw        $ra, 0x24($sp)
/* 4A10 8038AE00 920B0044 */  lbu        $t3, 0x44($s0)
/* 4A14 8038AE04 A200007E */  sb         $zero, 0x7e($s0)
/* 4A18 8038AE08 5560005A */  bnel       $t3, $zero, .L8038AF74
/* 4A1C 8038AE0C 8FBF0024 */   lw        $ra, 0x24($sp)
/* 4A20 8038AE10 0C0C3643 */  jal        func_8030D90C
/* 4A24 8038AE14 00000000 */   nop
/* 4A28 8038AE18 A2020044 */  sb         $v0, 0x44($s0)
/* 4A2C 8038AE1C 304400FF */  andi       $a0, $v0, 0xff
/* 4A30 8038AE20 0C0C36A0 */  jal        sfxsource_setSfxId
/* 4A34 8038AE24 24050134 */   addiu     $a1, $zero, 0x134
/* 4A38 8038AE28 92040044 */  lbu        $a0, 0x44($s0)
/* 4A3C 8038AE2C 0C0C3745 */  jal        func_8030DD14
/* 4A40 8038AE30 24050003 */   addiu     $a1, $zero, 3
/* 4A44 8038AE34 92040044 */  lbu        $a0, 0x44($s0)
/* 4A48 8038AE38 0C0C36ED */  jal        func_8030DBB4
/* 4A4C 8038AE3C 3C053F80 */   lui       $a1, 0x3f80
/* 4A50 8038AE40 92040044 */  lbu        $a0, 0x44($s0)
/* 4A54 8038AE44 0C0C36AF */  jal        sfxsource_setSampleRate
/* 4A58 8038AE48 24054268 */   addiu     $a1, $zero, 0x4268
/* 4A5C 8038AE4C 0C0C38B1 */  jal        func_8030E2C4
/* 4A60 8038AE50 92040044 */   lbu       $a0, 0x44($s0)
/* 4A64 8038AE54 10000047 */  b          .L8038AF74
/* 4A68 8038AE58 8FBF0024 */   lw        $ra, 0x24($sp)
/* 4A6C 8038AE5C 0C0D28E4 */  jal        randf
/* 4A70 8038AE60 00000000 */   nop
/* 4A74 8038AE64 3C013FE0 */  lui        $at, 0x3fe0
/* 4A78 8038AE68 44813800 */  mtc1       $at, $f7
/* 4A7C 8038AE6C 44803000 */  mtc1       $zero, $f6
/* 4A80 8038AE70 46000121 */  cvt.d.s    $f4, $f0
/* 4A84 8038AE74 3C018039 */  lui        $at, 0x8039
/* 4A88 8038AE78 4626203C */  c.lt.d     $f4, $f6
/* 4A8C 8038AE7C 00000000 */  nop
/* 4A90 8038AE80 45000013 */  bc1f       .L8038AED0
/* 4A94 8038AE84 00000000 */   nop
/* 4A98 8038AE88 3C018039 */  lui        $at, %hi(D_803923AC)
/* 4A9C 8038AE8C C42C23AC */  lwc1       $f12, %lo(D_803923AC)($at)
/* 4AA0 8038AE90 3C018039 */  lui        $at, %hi(D_803923B0)
/* 4AA4 8038AE94 0C0D29D5 */  jal        randf2
/* 4AA8 8038AE98 C42E23B0 */   lwc1      $f14, %lo(D_803923B0)($at)
/* 4AAC 8038AE9C 3C018039 */  lui        $at, %hi(D_803923B4)
/* 4AB0 8038AEA0 C42823B4 */  lwc1       $f8, %lo(D_803923B4)($at)
/* 4AB4 8038AEA4 3C018039 */  lui        $at, %hi(D_803923B8)
/* 4AB8 8038AEA8 C42A23B8 */  lwc1       $f10, %lo(D_803923B8)($at)
/* 4ABC 8038AEAC 44050000 */  mfc1       $a1, $f0
/* 4AC0 8038AEB0 24040131 */  addiu      $a0, $zero, 0x131
/* 4AC4 8038AEB4 24067D00 */  addiu      $a2, $zero, 0x7d00
/* 4AC8 8038AEB8 26070004 */  addiu      $a3, $s0, 4
/* 4ACC 8038AEBC E7A80010 */  swc1       $f8, 0x10($sp)
/* 4AD0 8038AEC0 0C0C3A1E */  jal        func_8030E878
/* 4AD4 8038AEC4 E7AA0014 */   swc1      $f10, 0x14($sp)
/* 4AD8 8038AEC8 1000002A */  b          .L8038AF74
/* 4ADC 8038AECC 8FBF0024 */   lw        $ra, 0x24($sp)
.L8038AED0:
/* 4AE0 8038AED0 C42C23BC */  lwc1       $f12, 0x23bc($at)
/* 4AE4 8038AED4 3C018039 */  lui        $at, %hi(D_803923C0)
/* 4AE8 8038AED8 0C0D29D5 */  jal        randf2
/* 4AEC 8038AEDC C42E23C0 */   lwc1      $f14, %lo(D_803923C0)($at)
/* 4AF0 8038AEE0 3C018039 */  lui        $at, %hi(D_803923C4)
/* 4AF4 8038AEE4 C43023C4 */  lwc1       $f16, %lo(D_803923C4)($at)
/* 4AF8 8038AEE8 3C018039 */  lui        $at, %hi(D_803923C8)
/* 4AFC 8038AEEC C43223C8 */  lwc1       $f18, %lo(D_803923C8)($at)
/* 4B00 8038AEF0 44050000 */  mfc1       $a1, $f0
/* 4B04 8038AEF4 24040179 */  addiu      $a0, $zero, 0x179
/* 4B08 8038AEF8 24067D00 */  addiu      $a2, $zero, 0x7d00
/* 4B0C 8038AEFC 26070004 */  addiu      $a3, $s0, 4
/* 4B10 8038AF00 E7B00010 */  swc1       $f16, 0x10($sp)
/* 4B14 8038AF04 0C0C3A1E */  jal        func_8030E878
/* 4B18 8038AF08 E7B20014 */   swc1      $f18, 0x14($sp)
/* 4B1C 8038AF0C 10000019 */  b          .L8038AF74
/* 4B20 8038AF10 8FBF0024 */   lw        $ra, 0x24($sp)
/* 4B24 8038AF14 24040092 */  addiu      $a0, $zero, 0x92
/* 4B28 8038AF18 0C0969BB */  jal        func_8025A6EC
/* 4B2C 8038AF1C 24057530 */   addiu     $a1, $zero, 0x7530
/* 4B30 8038AF20 10000014 */  b          .L8038AF74
/* 4B34 8038AF24 8FBF0024 */   lw        $ra, 0x24($sp)
/* 4B38 8038AF28 3C018039 */  lui        $at, %hi(D_803923CC)
/* 4B3C 8038AF2C C42C23CC */  lwc1       $f12, %lo(D_803923CC)($at)
/* 4B40 8038AF30 3C018039 */  lui        $at, %hi(D_803923D0)
/* 4B44 8038AF34 0C0D29D5 */  jal        randf2
/* 4B48 8038AF38 C42E23D0 */   lwc1      $f14, %lo(D_803923D0)($at)
/* 4B4C 8038AF3C 3C018039 */  lui        $at, %hi(D_803923D4)
/* 4B50 8038AF40 C42423D4 */  lwc1       $f4, %lo(D_803923D4)($at)
/* 4B54 8038AF44 3C018039 */  lui        $at, %hi(D_803923D8)
/* 4B58 8038AF48 C42623D8 */  lwc1       $f6, %lo(D_803923D8)($at)
/* 4B5C 8038AF4C 44050000 */  mfc1       $a1, $f0
/* 4B60 8038AF50 24040131 */  addiu      $a0, $zero, 0x131
/* 4B64 8038AF54 24067D00 */  addiu      $a2, $zero, 0x7d00
/* 4B68 8038AF58 26070004 */  addiu      $a3, $s0, 4
/* 4B6C 8038AF5C E7A40010 */  swc1       $f4, 0x10($sp)
/* 4B70 8038AF60 0C0C3A1E */  jal        func_8030E878
/* 4B74 8038AF64 E7A60014 */   swc1      $f6, 0x14($sp)
/* 4B78 8038AF68 0C0CA62B */  jal        actor_playAnimationOnce
/* 4B7C 8038AF6C 02002025 */   or        $a0, $s0, $zero
.L8038AF70:
/* 4B80 8038AF70 8FBF0024 */  lw         $ra, 0x24($sp)
.L8038AF74:
/* 4B84 8038AF74 8FB00020 */  lw         $s0, 0x20($sp)
/* 4B88 8038AF78 27BD0030 */  addiu      $sp, $sp, 0x30
/* 4B8C 8038AF7C 03E00008 */  jr         $ra
/* 4B90 8038AF80 00000000 */   nop
glabel func_8038AF84
/* 4B94 8038AF84 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 4B98 8038AF88 AFBF0014 */  sw         $ra, 0x14($sp)
/* 4B9C 8038AF8C 0C0CA656 */  jal        marker_getActor
/* 4BA0 8038AF90 00000000 */   nop
/* 4BA4 8038AF94 00402025 */  or         $a0, $v0, $zero
/* 4BA8 8038AF98 0C0E2B22 */  jal        func_8038AC88
/* 4BAC 8038AF9C 24050029 */   addiu     $a1, $zero, 0x29
/* 4BB0 8038AFA0 8FBF0014 */  lw         $ra, 0x14($sp)
/* 4BB4 8038AFA4 27BD0018 */  addiu      $sp, $sp, 0x18
/* 4BB8 8038AFA8 03E00008 */  jr         $ra
/* 4BBC 8038AFAC 00000000 */   nop
glabel func_8038AFB0
/* 4BC0 8038AFB0 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 4BC4 8038AFB4 AFBF0014 */  sw         $ra, 0x14($sp)
/* 4BC8 8038AFB8 24040087 */  addiu      $a0, $zero, 0x87
/* 4BCC 8038AFBC 00002825 */  or         $a1, $zero, $zero
/* 4BD0 8038AFC0 0C0B901E */  jal        func_802E4078
/* 4BD4 8038AFC4 24060001 */   addiu     $a2, $zero, 1
/* 4BD8 8038AFC8 8FBF0014 */  lw         $ra, 0x14($sp)
/* 4BDC 8038AFCC 27BD0018 */  addiu      $sp, $sp, 0x18
/* 4BE0 8038AFD0 03E00008 */  jr         $ra
/* 4BE4 8038AFD4 00000000 */   nop
glabel func_8038AFD8
/* 4BE8 8038AFD8 27BDFFB8 */  addiu      $sp, $sp, -0x48
/* 4BEC 8038AFDC AFBF0024 */  sw         $ra, 0x24($sp)
/* 4BF0 8038AFE0 0C0CA656 */  jal        marker_getActor
/* 4BF4 8038AFE4 AFB00020 */   sw        $s0, 0x20($sp)
/* 4BF8 8038AFE8 244E007C */  addiu      $t6, $v0, 0x7c
/* 4BFC 8038AFEC 00408025 */  or         $s0, $v0, $zero
/* 4C00 8038AFF0 0C0CF767 */  jal        time_getDelta
/* 4C04 8038AFF4 AFAE0040 */   sw        $t6, 0x40($sp)
/* 4C08 8038AFF8 240F0014 */  addiu      $t7, $zero, 0x14
/* 4C0C 8038AFFC E7A0003C */  swc1       $f0, 0x3c($sp)
/* 4C10 8038B000 AFAF0038 */  sw         $t7, 0x38($sp)
/* 4C14 8038B004 0C0A1DF6 */  jal        animctrl_getAnimTimer
/* 4C18 8038B008 8E040014 */   lw        $a0, 0x14($s0)
/* 4C1C 8038B00C E7A00034 */  swc1       $f0, 0x34($sp)
/* 4C20 8038B010 0C0CC8A7 */  jal        func_8033229C
/* 4C24 8038B014 8E040000 */   lw        $a0, ($s0)
/* 4C28 8038B018 3C014040 */  lui        $at, 0x4040
/* 4C2C 8038B01C 44812000 */  mtc1       $at, $f4
/* 4C30 8038B020 02002025 */  or         $a0, $s0, $zero
/* 4C34 8038B024 46040183 */  div.s      $f6, $f0, $f4
/* 4C38 8038B028 44053000 */  mfc1       $a1, $f6
/* 4C3C 8038B02C 0C0E293A */  jal        func_8038A4E8
/* 4C40 8038B030 00000000 */   nop
/* 4C44 8038B034 1040008B */  beqz       $v0, .L8038B264
/* 4C48 8038B038 00402025 */   or        $a0, $v0, $zero
/* 4C4C 8038B03C 8C580014 */  lw         $t8, 0x14($v0)
/* 4C50 8038B040 24010285 */  addiu      $at, $zero, 0x285
/* 4C54 8038B044 0018CAC0 */  sll        $t9, $t8, 0xb
/* 4C58 8038B048 00194582 */  srl        $t0, $t9, 0x16
/* 4C5C 8038B04C 55010086 */  bnel       $t0, $at, .L8038B268
/* 4C60 8038B050 8E0C0010 */   lw        $t4, 0x10($s0)
/* 4C64 8038B054 0C0E4497 */  jal        func_8039125C
/* 4C68 8038B058 AFA20030 */   sw        $v0, 0x30($sp)
/* 4C6C 8038B05C 10400081 */  beqz       $v0, .L8038B264
/* 4C70 8038B060 3C028039 */   lui       $v0, %hi(D_803927C6)
/* 4C74 8038B064 244227C6 */  addiu      $v0, $v0, %lo(D_803927C6)
/* 4C78 8038B068 90490000 */  lbu        $t1, ($v0)
/* 4C7C 8038B06C 8FAB0040 */  lw         $t3, 0x40($sp)
/* 4C80 8038B070 240D0023 */  addiu      $t5, $zero, 0x23
/* 4C84 8038B074 252A0001 */  addiu      $t2, $t1, 1
/* 4C88 8038B078 A04A0000 */  sb         $t2, ($v0)
/* 4C8C 8038B07C 916C0007 */  lbu        $t4, 7($t3)
/* 4C90 8038B080 00002025 */  or         $a0, $zero, $zero
/* 4C94 8038B084 3C05427C */  lui        $a1, 0x427c
/* 4C98 8038B088 11800002 */  beqz       $t4, .L8038B094
/* 4C9C 8038B08C 3C063F66 */   lui       $a2, 0x3f66
/* 4CA0 8038B090 AFAD0038 */  sw         $t5, 0x38($sp)
.L8038B094:
/* 4CA4 8038B094 904E0000 */  lbu        $t6, ($v0)
/* 4CA8 8038B098 29C1000A */  slti       $at, $t6, 0xa
/* 4CAC 8038B09C 1020003C */  beqz       $at, .L8038B190
/* 4CB0 8038B0A0 00000000 */   nop
/* 4CB4 8038B0A4 3C063F66 */  lui        $a2, 0x3f66
/* 4CB8 8038B0A8 34C66666 */  ori        $a2, $a2, 0x6666
/* 4CBC 8038B0AC 00002025 */  or         $a0, $zero, $zero
/* 4CC0 8038B0B0 0C0AECF7 */  jal        func_802BB3DC
/* 4CC4 8038B0B4 3C054190 */   lui       $a1, 0x4190
/* 4CC8 8038B0B8 3C018039 */  lui        $at, %hi(D_803923DC)
/* 4CCC 8038B0BC 0C0C93A2 */  jal        func_80324E88
/* 4CD0 8038B0C0 C42C23DC */   lwc1      $f12, %lo(D_803923DC)($at)
/* 4CD4 8038B0C4 3C188039 */  lui        $t8, %hi(D_803927C6)
/* 4CD8 8038B0C8 931827C6 */  lbu        $t8, %lo(D_803927C6)($t8)
/* 4CDC 8038B0CC 8FAF0038 */  lw         $t7, 0x38($sp)
/* 4CE0 8038B0D0 3C018039 */  lui        $at, %hi(D_803923E0)
/* 4CE4 8038B0D4 C42C23E0 */  lwc1       $f12, %lo(D_803923E0)($at)
/* 4CE8 8038B0D8 01F82821 */  addu       $a1, $t7, $t8
/* 4CEC 8038B0DC 0C0C9398 */  jal        timed_setCameraToNode
/* 4CF0 8038B0E0 24A50003 */   addiu     $a1, $a1, 3
/* 4CF4 8038B0E4 8FB90040 */  lw         $t9, 0x40($sp)
/* 4CF8 8038B0E8 3C058039 */  lui        $a1, %hi(D_803927C6)
/* 4CFC 8038B0EC 90A527C6 */  lbu        $a1, %lo(D_803927C6)($a1)
/* 4D00 8038B0F0 8FA40030 */  lw         $a0, 0x30($sp)
/* 4D04 8038B0F4 0C0E441C */  jal        func_80391070
/* 4D08 8038B0F8 93260007 */   lbu       $a2, 7($t9)
/* 4D0C 8038B0FC 02002025 */  or         $a0, $s0, $zero
/* 4D10 8038B100 0C0E2B22 */  jal        func_8038AC88
/* 4D14 8038B104 2405002A */   addiu     $a1, $zero, 0x2a
/* 4D18 8038B108 3C028039 */  lui        $v0, %hi(D_803927C6)
/* 4D1C 8038B10C 904227C6 */  lbu        $v0, %lo(D_803927C6)($v0)
/* 4D20 8038B110 24010009 */  addiu      $at, $zero, 9
/* 4D24 8038B114 8FA80040 */  lw         $t0, 0x40($sp)
/* 4D28 8038B118 14410046 */  bne        $v0, $at, .L8038B234
/* 4D2C 8038B11C 3C058039 */   lui       $a1, %hi(func_8038AF84)
/* 4D30 8038B120 91090007 */  lbu        $t1, 7($t0)
/* 4D34 8038B124 24040016 */  addiu      $a0, $zero, 0x16
/* 4D38 8038B128 3C018039 */  lui        $at, 0x8039
/* 4D3C 8038B12C 11200002 */  beqz       $t1, .L8038B138
/* 4D40 8038B130 24A5AF84 */   addiu     $a1, $a1, %lo(func_8038AF84)
/* 4D44 8038B134 24040025 */  addiu      $a0, $zero, 0x25
.L8038B138:
/* 4D48 8038B138 8E060000 */  lw         $a2, ($s0)
/* 4D4C 8038B13C AFA4002C */  sw         $a0, 0x2c($sp)
/* 4D50 8038B140 0C0C93B9 */  jal        timedFunc_set_1
/* 4D54 8038B144 C42C23E4 */   lwc1      $f12, 0x23e4($at)
/* 4D58 8038B148 3C018039 */  lui        $at, %hi(D_803923E8)
/* 4D5C 8038B14C 8FA5002C */  lw         $a1, 0x2c($sp)
/* 4D60 8038B150 0C0C9398 */  jal        timed_setCameraToNode
/* 4D64 8038B154 C42C23E8 */   lwc1      $f12, %lo(D_803923E8)($at)
/* 4D68 8038B158 3C018039 */  lui        $at, %hi(D_803923EC)
/* 4D6C 8038B15C 0C0C93A2 */  jal        func_80324E88
/* 4D70 8038B160 C42C23EC */   lwc1      $f12, %lo(D_803923EC)($at)
/* 4D74 8038B164 3C0B8039 */  lui        $t3, %hi(D_803927C6)
/* 4D78 8038B168 916B27C6 */  lbu        $t3, %lo(D_803927C6)($t3)
/* 4D7C 8038B16C 8FAA0038 */  lw         $t2, 0x38($sp)
/* 4D80 8038B170 3C018039 */  lui        $at, %hi(D_803923F0)
/* 4D84 8038B174 C42C23F0 */  lwc1       $f12, %lo(D_803923F0)($at)
/* 4D88 8038B178 014B2821 */  addu       $a1, $t2, $t3
/* 4D8C 8038B17C 0C0C9398 */  jal        timed_setCameraToNode
/* 4D90 8038B180 24A50003 */   addiu     $a1, $a1, 3
/* 4D94 8038B184 3C028039 */  lui        $v0, %hi(D_803927C6)
/* 4D98 8038B188 1000002A */  b          .L8038B234
/* 4D9C 8038B18C 904227C6 */   lbu       $v0, %lo(D_803927C6)($v0)
.L8038B190:
/* 4DA0 8038B190 0C0AECF7 */  jal        func_802BB3DC
/* 4DA4 8038B194 34C66666 */   ori       $a2, $a2, 0x6666
/* 4DA8 8038B198 0C0E447E */  jal        func_803911F8
/* 4DAC 8038B19C 8FA40030 */   lw        $a0, 0x30($sp)
/* 4DB0 8038B1A0 0C0C39B5 */  jal        func_8030E6D4
/* 4DB4 8038B1A4 24040165 */   addiu     $a0, $zero, 0x165
/* 4DB8 8038B1A8 240400A3 */  addiu      $a0, $zero, 0xa3
/* 4DBC 8038B1AC 0C0969BB */  jal        func_8025A6EC
/* 4DC0 8038B1B0 24054E20 */   addiu     $a1, $zero, 0x4e20
/* 4DC4 8038B1B4 02002025 */  or         $a0, $s0, $zero
/* 4DC8 8038B1B8 0C0E2B22 */  jal        func_8038AC88
/* 4DCC 8038B1BC 2405002B */   addiu     $a1, $zero, 0x2b
/* 4DD0 8038B1C0 44806000 */  mtc1       $zero, $f12
/* 4DD4 8038B1C4 0C0C93A2 */  jal        func_80324E88
/* 4DD8 8038B1C8 00000000 */   nop
/* 4DDC 8038B1CC 8FA50038 */  lw         $a1, 0x38($sp)
/* 4DE0 8038B1D0 44806000 */  mtc1       $zero, $f12
/* 4DE4 8038B1D4 0C0C9398 */  jal        timed_setCameraToNode
/* 4DE8 8038B1D8 24A5000D */   addiu     $a1, $a1, 0xd
/* 4DEC 8038B1DC 3C048039 */  lui        $a0, %hi(D_803917E0)
/* 4DF0 8038B1E0 0C0A3E17 */  jal        func_8028F85C
/* 4DF4 8038B1E4 248417E0 */   addiu     $a0, $a0, %lo(D_803917E0)
/* 4DF8 8038B1E8 44804000 */  mtc1       $zero, $f8
/* 4DFC 8038B1EC 3C048039 */  lui        $a0, %hi(D_803928C8)
/* 4E00 8038B1F0 248428C8 */  addiu      $a0, $a0, %lo(D_803928C8)
/* 4E04 8038B1F4 3C028039 */  lui        $v0, %hi(D_803917E0)
/* 4E08 8038B1F8 244217E0 */  addiu      $v0, $v0, %lo(D_803917E0)
/* 4E0C 8038B1FC E4880000 */  swc1       $f8, ($a0)
/* 4E10 8038B200 8E07000C */  lw         $a3, 0xc($s0)
/* 4E14 8038B204 8E060004 */  lw         $a2, 4($s0)
/* 4E18 8038B208 C44C0000 */  lwc1       $f12, ($v0)
/* 4E1C 8038B20C 0C095C81 */  jal        func_80257204
/* 4E20 8038B210 C44E0008 */   lwc1      $f14, 8($v0)
/* 4E24 8038B214 44805000 */  mtc1       $zero, $f10
/* 4E28 8038B218 3C048039 */  lui        $a0, %hi(D_803928C8)
/* 4E2C 8038B21C 248428C8 */  addiu      $a0, $a0, %lo(D_803928C8)
/* 4E30 8038B220 E4800004 */  swc1       $f0, 4($a0)
/* 4E34 8038B224 0C0A3EBB */  jal        func_8028FAEC
/* 4E38 8038B228 E48A0008 */   swc1      $f10, 8($a0)
/* 4E3C 8038B22C 3C028039 */  lui        $v0, %hi(D_803927C6)
/* 4E40 8038B230 904227C6 */  lbu        $v0, %lo(D_803927C6)($v0)
.L8038B234:
/* 4E44 8038B234 24010003 */  addiu      $at, $zero, 3
/* 4E48 8038B238 1441000A */  bne        $v0, $at, .L8038B264
/* 4E4C 8038B23C 00002025 */   or        $a0, $zero, $zero
/* 4E50 8038B240 0C0D29EF */  jal        randi2
/* 4E54 8038B244 24050005 */   addiu     $a1, $zero, 5
/* 4E58 8038B248 24441159 */  addiu      $a0, $v0, 0x1159
/* 4E5C 8038B24C 24050020 */  addiu      $a1, $zero, 0x20
/* 4E60 8038B250 00003025 */  or         $a2, $zero, $zero
/* 4E64 8038B254 00003825 */  or         $a3, $zero, $zero
/* 4E68 8038B258 AFA00010 */  sw         $zero, 0x10($sp)
/* 4E6C 8038B25C 0C0C4520 */  jal        func_80311480
/* 4E70 8038B260 AFA00014 */   sw        $zero, 0x14($sp)
.L8038B264:
/* 4E74 8038B264 8E0C0010 */  lw         $t4, 0x10($s0)
.L8038B268:
/* 4E78 8038B268 000C6E82 */  srl        $t5, $t4, 0x1a
/* 4E7C 8038B26C 25AEFFDD */  addiu      $t6, $t5, -0x23
/* 4E80 8038B270 2DC10009 */  sltiu      $at, $t6, 9
/* 4E84 8038B274 10200129 */  beqz       $at, .L8038B71C
/* 4E88 8038B278 000E7080 */   sll       $t6, $t6, 2
/* 4E8C 8038B27C 3C018039 */  lui        $at, %hi(D_803923F4)
/* 4E90 8038B280 002E0821 */  addu       $at, $at, $t6
/* 4E94 8038B284 8C2E23F4 */  lw         $t6, %lo(D_803923F4)($at)
/* 4E98 8038B288 01C00008 */  jr         $t6
/* 4E9C 8038B28C 00000000 */   nop
/* 4EA0 8038B290 02002025 */  or         $a0, $s0, $zero
/* 4EA4 8038B294 0C0E1AFB */  jal        func_80386BEC
/* 4EA8 8038B298 3C054040 */   lui       $a1, 0x4040
/* 4EAC 8038B29C 10000120 */  b          .L8038B720
/* 4EB0 8038B2A0 8FBF0024 */   lw        $ra, 0x24($sp)
/* 4EB4 8038B2A4 02002025 */  or         $a0, $s0, $zero
/* 4EB8 8038B2A8 0C0E1AFB */  jal        func_80386BEC
/* 4EBC 8038B2AC 3C054110 */   lui       $a1, 0x4110
/* 4EC0 8038B2B0 5040011B */  beql       $v0, $zero, .L8038B720
/* 4EC4 8038B2B4 8FBF0024 */   lw        $ra, 0x24($sp)
/* 4EC8 8038B2B8 0C0A5F1B */  jal        func_80297C6C
/* 4ECC 8038B2BC 00000000 */   nop
/* 4ED0 8038B2C0 24010003 */  addiu      $at, $zero, 3
/* 4ED4 8038B2C4 10410115 */  beq        $v0, $at, .L8038B71C
/* 4ED8 8038B2C8 02002025 */   or        $a0, $s0, $zero
/* 4EDC 8038B2CC 0C0E2B22 */  jal        func_8038AC88
/* 4EE0 8038B2D0 24050025 */   addiu     $a1, $zero, 0x25
/* 4EE4 8038B2D4 10000112 */  b          .L8038B720
/* 4EE8 8038B2D8 8FBF0024 */   lw        $ra, 0x24($sp)
/* 4EEC 8038B2DC 02002025 */  or         $a0, $s0, $zero
/* 4EF0 8038B2E0 0C0E1AFB */  jal        func_80386BEC
/* 4EF4 8038B2E4 3C054040 */   lui       $a1, 0x4040
/* 4EF8 8038B2E8 0C0A5F1B */  jal        func_80297C6C
/* 4EFC 8038B2EC 00000000 */   nop
/* 4F00 8038B2F0 24010003 */  addiu      $at, $zero, 3
/* 4F04 8038B2F4 14410006 */  bne        $v0, $at, .L8038B310
/* 4F08 8038B2F8 02002025 */   or        $a0, $s0, $zero
/* 4F0C 8038B2FC 02002025 */  or         $a0, $s0, $zero
/* 4F10 8038B300 0C0E2B22 */  jal        func_8038AC88
/* 4F14 8038B304 24050024 */   addiu     $a1, $zero, 0x24
/* 4F18 8038B308 10000105 */  b          .L8038B720
/* 4F1C 8038B30C 8FBF0024 */   lw        $ra, 0x24($sp)
.L8038B310:
/* 4F20 8038B310 0C0E1CD0 */  jal        func_80387340
/* 4F24 8038B314 3C053F80 */   lui       $a1, 0x3f80
/* 4F28 8038B318 10400005 */  beqz       $v0, .L8038B330
/* 4F2C 8038B31C 02002025 */   or        $a0, $s0, $zero
/* 4F30 8038B320 8FAF0040 */  lw         $t7, 0x40($sp)
/* 4F34 8038B324 91F80003 */  lbu        $t8, 3($t7)
/* 4F38 8038B328 27190001 */  addiu      $t9, $t8, 1
/* 4F3C 8038B32C A1F90003 */  sb         $t9, 3($t7)
.L8038B330:
/* 4F40 8038B330 3C053F7F */  lui        $a1, 0x3f7f
/* 4F44 8038B334 0C0CA21B */  jal        actor_animationIsAt
/* 4F48 8038B338 34A5F972 */   ori       $a1, $a1, 0xf972
/* 4F4C 8038B33C 104000F7 */  beqz       $v0, .L8038B71C
/* 4F50 8038B340 8FA80040 */   lw        $t0, 0x40($sp)
/* 4F54 8038B344 91090003 */  lbu        $t1, 3($t0)
/* 4F58 8038B348 02002025 */  or         $a0, $s0, $zero
/* 4F5C 8038B34C 29210005 */  slti       $at, $t1, 5
/* 4F60 8038B350 542000F3 */  bnel       $at, $zero, .L8038B720
/* 4F64 8038B354 8FBF0024 */   lw        $ra, 0x24($sp)
/* 4F68 8038B358 0C0E2B22 */  jal        func_8038AC88
/* 4F6C 8038B35C 24050026 */   addiu     $a1, $zero, 0x26
/* 4F70 8038B360 100000EF */  b          .L8038B720
/* 4F74 8038B364 8FBF0024 */   lw        $ra, 0x24($sp)
/* 4F78 8038B368 02002025 */  or         $a0, $s0, $zero
/* 4F7C 8038B36C 0C0E1AFB */  jal        func_80386BEC
/* 4F80 8038B370 3C054040 */   lui       $a1, 0x4040
/* 4F84 8038B374 02002025 */  or         $a0, $s0, $zero
/* 4F88 8038B378 3C05442F */  lui        $a1, 0x442f
/* 4F8C 8038B37C 0C0E1CF7 */  jal        func_803873DC
/* 4F90 8038B380 3C064516 */   lui       $a2, 0x4516
/* 4F94 8038B384 3C053F7F */  lui        $a1, 0x3f7f
/* 4F98 8038B388 34A5F972 */  ori        $a1, $a1, 0xf972
/* 4F9C 8038B38C 0C0CA21B */  jal        actor_animationIsAt
/* 4FA0 8038B390 02002025 */   or        $a0, $s0, $zero
/* 4FA4 8038B394 104000E1 */  beqz       $v0, .L8038B71C
/* 4FA8 8038B398 02002025 */   or        $a0, $s0, $zero
/* 4FAC 8038B39C 0C0E2B22 */  jal        func_8038AC88
/* 4FB0 8038B3A0 24050027 */   addiu     $a1, $zero, 0x27
/* 4FB4 8038B3A4 3C014080 */  lui        $at, 0x4080
/* 4FB8 8038B3A8 44818000 */  mtc1       $at, $f16
/* 4FBC 8038B3AC 100000DB */  b          .L8038B71C
/* 4FC0 8038B3B0 E6100060 */   swc1      $f16, 0x60($s0)
/* 4FC4 8038B3B4 8FAA0040 */  lw         $t2, 0x40($sp)
/* 4FC8 8038B3B8 3C054090 */  lui        $a1, 0x4090
/* 4FCC 8038B3BC 02002025 */  or         $a0, $s0, $zero
/* 4FD0 8038B3C0 914B0008 */  lbu        $t3, 8($t2)
/* 4FD4 8038B3C4 11600005 */  beqz       $t3, .L8038B3DC
/* 4FD8 8038B3C8 00000000 */   nop
/* 4FDC 8038B3CC 0C0E1B1A */  jal        func_80386C68
/* 4FE0 8038B3D0 02002025 */   or        $a0, $s0, $zero
/* 4FE4 8038B3D4 10000004 */  b          .L8038B3E8
/* 4FE8 8038B3D8 C6000060 */   lwc1      $f0, 0x60($s0)
.L8038B3DC:
/* 4FEC 8038B3DC 0C0E1AFB */  jal        func_80386BEC
/* 4FF0 8038B3E0 3C054040 */   lui       $a1, 0x4040
/* 4FF4 8038B3E4 C6000060 */  lwc1       $f0, 0x60($s0)
.L8038B3E8:
/* 4FF8 8038B3E8 44809800 */  mtc1       $zero, $f19
/* 4FFC 8038B3EC 44809000 */  mtc1       $zero, $f18
/* 5000 8038B3F0 46000121 */  cvt.d.s    $f4, $f0
/* 5004 8038B3F4 C7A6003C */  lwc1       $f6, 0x3c($sp)
/* 5008 8038B3F8 4624903C */  c.lt.d     $f18, $f4
/* 500C 8038B3FC 8FAC0040 */  lw         $t4, 0x40($sp)
/* 5010 8038B400 45020005 */  bc1fl      .L8038B418
/* 5014 8038B404 918D0008 */   lbu       $t5, 8($t4)
/* 5018 8038B408 46060201 */  sub.s      $f8, $f0, $f6
/* 501C 8038B40C 100000C3 */  b          .L8038B71C
/* 5020 8038B410 E6080060 */   swc1      $f8, 0x60($s0)
/* 5024 8038B414 918D0008 */  lbu        $t5, 8($t4)
.L8038B418:
/* 5028 8038B418 3C028039 */  lui        $v0, %hi(D_803927C9)
/* 502C 8038B41C 244227C9 */  addiu      $v0, $v0, %lo(D_803927C9)
/* 5030 8038B420 55A000BF */  bnel       $t5, $zero, .L8038B720
/* 5034 8038B424 8FBF0024 */   lw        $ra, 0x24($sp)
/* 5038 8038B428 904E0000 */  lbu        $t6, ($v0)
/* 503C 8038B42C 24180001 */  addiu      $t8, $zero, 1
/* 5040 8038B430 24050023 */  addiu      $a1, $zero, 0x23
/* 5044 8038B434 15C00006 */  bnez       $t6, .L8038B450
/* 5048 8038B438 02002025 */   or        $a0, $s0, $zero
/* 504C 8038B43C A0580000 */  sb         $t8, ($v0)
/* 5050 8038B440 0C0E2B22 */  jal        func_8038AC88
/* 5054 8038B444 02002025 */   or        $a0, $s0, $zero
/* 5058 8038B448 100000B5 */  b          .L8038B720
/* 505C 8038B44C 8FBF0024 */   lw        $ra, 0x24($sp)
.L8038B450:
/* 5060 8038B450 0C0E2B22 */  jal        func_8038AC88
/* 5064 8038B454 24050025 */   addiu     $a1, $zero, 0x25
/* 5068 8038B458 100000B1 */  b          .L8038B720
/* 506C 8038B45C 8FBF0024 */   lw        $ra, 0x24($sp)
/* 5070 8038B460 3C053E57 */  lui        $a1, 0x3e57
/* 5074 8038B464 34A50A3D */  ori        $a1, $a1, 0xa3d
/* 5078 8038B468 0C0CA21B */  jal        actor_animationIsAt
/* 507C 8038B46C 02002025 */   or        $a0, $s0, $zero
/* 5080 8038B470 10400006 */  beqz       $v0, .L8038B48C
/* 5084 8038B474 3C047FFF */   lui       $a0, 0x7fff
/* 5088 8038B478 3C062EE0 */  lui        $a2, 0x2ee0
/* 508C 8038B47C 34C61388 */  ori        $a2, $a2, 0x1388
/* 5090 8038B480 34844163 */  ori        $a0, $a0, 0x4163
/* 5094 8038B484 0C0C3A2D */  jal        func_8030E8B4
/* 5098 8038B488 26050004 */   addiu     $a1, $s0, 4
.L8038B48C:
/* 509C 8038B48C C7AA0034 */  lwc1       $f10, 0x34($sp)
/* 50A0 8038B490 3C018039 */  lui        $at, %hi(D_80392418)
/* 50A4 8038B494 D4302418 */  ldc1       $f16, %lo(D_80392418)($at)
/* 50A8 8038B498 46005021 */  cvt.d.s    $f0, $f10
/* 50AC 8038B49C 3C018039 */  lui        $at, %hi(D_80392420)
/* 50B0 8038B4A0 4620803C */  c.lt.d     $f16, $f0
/* 50B4 8038B4A4 00000000 */  nop
/* 50B8 8038B4A8 45020009 */  bc1fl      .L8038B4D0
/* 50BC 8038B4AC 3C053F7F */   lui       $a1, 0x3f7f
/* 50C0 8038B4B0 D4322420 */  ldc1       $f18, %lo(D_80392420)($at)
/* 50C4 8038B4B4 4632003C */  c.lt.d     $f0, $f18
/* 50C8 8038B4B8 00000000 */  nop
/* 50CC 8038B4BC 45020004 */  bc1fl      .L8038B4D0
/* 50D0 8038B4C0 3C053F7F */   lui       $a1, 0x3f7f
/* 50D4 8038B4C4 0C0C38B1 */  jal        func_8030E2C4
/* 50D8 8038B4C8 92040044 */   lbu       $a0, 0x44($s0)
/* 50DC 8038B4CC 3C053F7F */  lui        $a1, 0x3f7f
.L8038B4D0:
/* 50E0 8038B4D0 34A5F972 */  ori        $a1, $a1, 0xf972
/* 50E4 8038B4D4 0C0CA21B */  jal        actor_animationIsAt
/* 50E8 8038B4D8 02002025 */   or        $a0, $s0, $zero
/* 50EC 8038B4DC 1040008F */  beqz       $v0, .L8038B71C
/* 50F0 8038B4E0 02002025 */   or        $a0, $s0, $zero
/* 50F4 8038B4E4 0C0E2B22 */  jal        func_8038AC88
/* 50F8 8038B4E8 24050027 */   addiu     $a1, $zero, 0x27
/* 50FC 8038B4EC 0C0C3691 */  jal        func_8030DA44
/* 5100 8038B4F0 92040044 */   lbu       $a0, 0x44($s0)
/* 5104 8038B4F4 10000089 */  b          .L8038B71C
/* 5108 8038B4F8 A2000044 */   sb        $zero, 0x44($s0)
/* 510C 8038B4FC 3C053F7F */  lui        $a1, 0x3f7f
/* 5110 8038B500 34A5F972 */  ori        $a1, $a1, 0xf972
/* 5114 8038B504 0C0CA21B */  jal        actor_animationIsAt
/* 5118 8038B508 02002025 */   or        $a0, $s0, $zero
/* 511C 8038B50C 50400084 */  beql       $v0, $zero, .L8038B720
/* 5120 8038B510 8FBF0024 */   lw        $ra, 0x24($sp)
/* 5124 8038B514 8FA20040 */  lw         $v0, 0x40($sp)
/* 5128 8038B518 24010008 */  addiu      $at, $zero, 8
/* 512C 8038B51C 00002025 */  or         $a0, $zero, $zero
/* 5130 8038B520 90590002 */  lbu        $t9, 2($v0)
/* 5134 8038B524 3C054140 */  lui        $a1, 0x4140
/* 5138 8038B528 272F0001 */  addiu      $t7, $t9, 1
/* 513C 8038B52C 31E800FF */  andi       $t0, $t7, 0xff
/* 5140 8038B530 1501007A */  bne        $t0, $at, .L8038B71C
/* 5144 8038B534 A04F0002 */   sb        $t7, 2($v0)
/* 5148 8038B538 0C0AECF7 */  jal        func_802BB3DC
/* 514C 8038B53C 3C063F80 */   lui       $a2, 0x3f80
/* 5150 8038B540 92040044 */  lbu        $a0, 0x44($s0)
/* 5154 8038B544 50800076 */  beql       $a0, $zero, .L8038B720
/* 5158 8038B548 8FBF0024 */   lw        $ra, 0x24($sp)
/* 515C 8038B54C 0C0C38E5 */  jal        func_8030E394
/* 5160 8038B550 00000000 */   nop
/* 5164 8038B554 0C0C3691 */  jal        func_8030DA44
/* 5168 8038B558 92040044 */   lbu       $a0, 0x44($s0)
/* 516C 8038B55C 1000006F */  b          .L8038B71C
/* 5170 8038B560 A2000044 */   sb        $zero, 0x44($s0)
/* 5174 8038B564 3C053F7F */  lui        $a1, 0x3f7f
/* 5178 8038B568 34A5F972 */  ori        $a1, $a1, 0xf972
/* 517C 8038B56C 0C0CA21B */  jal        actor_animationIsAt
/* 5180 8038B570 02002025 */   or        $a0, $s0, $zero
/* 5184 8038B574 10400069 */  beqz       $v0, .L8038B71C
/* 5188 8038B578 02002025 */   or        $a0, $s0, $zero
/* 518C 8038B57C 0C0E2B22 */  jal        func_8038AC88
/* 5190 8038B580 24050027 */   addiu     $a1, $zero, 0x27
/* 5194 8038B584 10000066 */  b          .L8038B720
/* 5198 8038B588 8FBF0024 */   lw        $ra, 0x24($sp)
/* 519C 8038B58C 3C053DCC */  lui        $a1, 0x3dcc
/* 51A0 8038B590 34A5CCCD */  ori        $a1, $a1, 0xcccd
/* 51A4 8038B594 0C0CA21B */  jal        actor_animationIsAt
/* 51A8 8038B598 02002025 */   or        $a0, $s0, $zero
/* 51AC 8038B59C 14400005 */  bnez       $v0, .L8038B5B4
/* 51B0 8038B5A0 3C053E75 */   lui       $a1, 0x3e75
/* 51B4 8038B5A4 34A5C28F */  ori        $a1, $a1, 0xc28f
/* 51B8 8038B5A8 0C0CA21B */  jal        actor_animationIsAt
/* 51BC 8038B5AC 02002025 */   or        $a0, $s0, $zero
/* 51C0 8038B5B0 10400005 */  beqz       $v0, .L8038B5C8
.L8038B5B4:
/* 51C4 8038B5B4 02002025 */   or        $a0, $s0, $zero
/* 51C8 8038B5B8 24050718 */  addiu      $a1, $zero, 0x718
/* 51CC 8038B5BC 240606C2 */  addiu      $a2, $zero, 0x6c2
/* 51D0 8038B5C0 0C0E317C */  jal        func_8038C5F0
/* 51D4 8038B5C4 3C074000 */   lui       $a3, 0x4000
.L8038B5C8:
/* 51D8 8038B5C8 3C053E99 */  lui        $a1, 0x3e99
/* 51DC 8038B5CC 34A5999A */  ori        $a1, $a1, 0x999a
/* 51E0 8038B5D0 0C0CA21B */  jal        actor_animationIsAt
/* 51E4 8038B5D4 02002025 */   or        $a0, $s0, $zero
/* 51E8 8038B5D8 10400003 */  beqz       $v0, .L8038B5E8
/* 51EC 8038B5DC 3C047FF8 */   lui       $a0, 0x7ff8
/* 51F0 8038B5E0 0C0C3989 */  jal        func_8030E624
/* 51F4 8038B5E4 34846964 */   ori       $a0, $a0, 0x6964
.L8038B5E8:
/* 51F8 8038B5E8 3C053ECC */  lui        $a1, 0x3ecc
/* 51FC 8038B5EC 34A5CCCD */  ori        $a1, $a1, 0xcccd
/* 5200 8038B5F0 0C0CA21B */  jal        actor_animationIsAt
/* 5204 8038B5F4 02002025 */   or        $a0, $s0, $zero
/* 5208 8038B5F8 10400003 */  beqz       $v0, .L8038B608
/* 520C 8038B5FC 3C048978 */   lui       $a0, 0x8978
/* 5210 8038B600 0C0C3989 */  jal        func_8030E624
/* 5214 8038B604 34846964 */   ori       $a0, $a0, 0x6964
.L8038B608:
/* 5218 8038B608 3C053F19 */  lui        $a1, 0x3f19
/* 521C 8038B60C 34A5999A */  ori        $a1, $a1, 0x999a
/* 5220 8038B610 0C0CA21B */  jal        actor_animationIsAt
/* 5224 8038B614 02002025 */   or        $a0, $s0, $zero
/* 5228 8038B618 10400003 */  beqz       $v0, .L8038B628
/* 522C 8038B61C 3C048CB8 */   lui       $a0, 0x8cb8
/* 5230 8038B620 0C0C3989 */  jal        func_8030E624
/* 5234 8038B624 34846964 */   ori       $a0, $a0, 0x6964
.L8038B628:
/* 5238 8038B628 3C053F33 */  lui        $a1, 0x3f33
/* 523C 8038B62C 34A53333 */  ori        $a1, $a1, 0x3333
/* 5240 8038B630 0C0CA21B */  jal        actor_animationIsAt
/* 5244 8038B634 02002025 */   or        $a0, $s0, $zero
/* 5248 8038B638 10400003 */  beqz       $v0, .L8038B648
/* 524C 8038B63C 3C049318 */   lui       $a0, 0x9318
/* 5250 8038B640 0C0C3989 */  jal        func_8030E624
/* 5254 8038B644 34846964 */   ori       $a0, $a0, 0x6964
.L8038B648:
/* 5258 8038B648 3C053F4F */  lui        $a1, 0x3f4f
/* 525C 8038B64C 34A55C29 */  ori        $a1, $a1, 0x5c29
/* 5260 8038B650 0C0CA21B */  jal        actor_animationIsAt
/* 5264 8038B654 02002025 */   or        $a0, $s0, $zero
/* 5268 8038B658 10400003 */  beqz       $v0, .L8038B668
/* 526C 8038B65C 3C047FFF */   lui       $a0, 0x7fff
/* 5270 8038B660 0C0C3989 */  jal        func_8030E624
/* 5274 8038B664 34844130 */   ori       $a0, $a0, 0x4130
.L8038B668:
/* 5278 8038B668 3C053F59 */  lui        $a1, 0x3f59
/* 527C 8038B66C 34A5999A */  ori        $a1, $a1, 0x999a
/* 5280 8038B670 0C0CA21B */  jal        actor_animationIsAt
/* 5284 8038B674 02002025 */   or        $a0, $s0, $zero
/* 5288 8038B678 50400004 */  beql       $v0, $zero, .L8038B68C
/* 528C 8038B67C 3C053F66 */   lui       $a1, 0x3f66
/* 5290 8038B680 0C0E1CBE */  jal        func_803872F8
/* 5294 8038B684 02002025 */   or        $a0, $s0, $zero
/* 5298 8038B688 3C053F66 */  lui        $a1, 0x3f66
.L8038B68C:
/* 529C 8038B68C 34A56666 */  ori        $a1, $a1, 0x6666
/* 52A0 8038B690 0C0CA21B */  jal        actor_animationIsAt
/* 52A4 8038B694 02002025 */   or        $a0, $s0, $zero
/* 52A8 8038B698 50400019 */  beql       $v0, $zero, .L8038B700
/* 52AC 8038B69C 3C053F7F */   lui       $a1, 0x3f7f
/* 52B0 8038B6A0 0C0AEB93 */  jal        func_802BAE4C
/* 52B4 8038B6A4 00000000 */   nop
/* 52B8 8038B6A8 8FA90040 */  lw         $t1, 0x40($sp)
/* 52BC 8038B6AC 3C048039 */  lui        $a0, %hi(D_803917F8)
/* 52C0 8038B6B0 26050004 */  addiu      $a1, $s0, 4
/* 52C4 8038B6B4 912A0007 */  lbu        $t2, 7($t1)
/* 52C8 8038B6B8 248417F8 */  addiu      $a0, $a0, %lo(D_803917F8)
/* 52CC 8038B6BC 15400006 */  bnez       $t2, .L8038B6D8
/* 52D0 8038B6C0 00000000 */   nop
/* 52D4 8038B6C4 3C048039 */  lui        $a0, %hi(D_803917EC)
/* 52D8 8038B6C8 0C0AEBAD */  jal        func_802BAEB4
/* 52DC 8038B6CC 248417EC */   addiu     $a0, $a0, %lo(D_803917EC)
/* 52E0 8038B6D0 10000003 */  b          .L8038B6E0
/* 52E4 8038B6D4 00000000 */   nop
.L8038B6D8:
/* 52E8 8038B6D8 0C0AEBAD */  jal        func_802BAEB4
/* 52EC 8038B6DC 26050004 */   addiu     $a1, $s0, 4
.L8038B6E0:
/* 52F0 8038B6E0 0C0E3F0B */  jal        func_8038FC2C
/* 52F4 8038B6E4 24040001 */   addiu     $a0, $zero, 1
/* 52F8 8038B6E8 3C018039 */  lui        $at, %hi(D_80392428)
/* 52FC 8038B6EC 3C058039 */  lui        $a1, %hi(func_8038AFB0)
/* 5300 8038B6F0 24A5AFB0 */  addiu      $a1, $a1, %lo(func_8038AFB0)
/* 5304 8038B6F4 0C0C93AB */  jal        timedFunc_set_0
/* 5308 8038B6F8 C42C2428 */   lwc1      $f12, %lo(D_80392428)($at)
/* 530C 8038B6FC 3C053F7F */  lui        $a1, 0x3f7f
.L8038B700:
/* 5310 8038B700 34A5F972 */  ori        $a1, $a1, 0xf972
/* 5314 8038B704 0C0CA21B */  jal        actor_animationIsAt
/* 5318 8038B708 02002025 */   or        $a0, $s0, $zero
/* 531C 8038B70C 50400004 */  beql       $v0, $zero, .L8038B720
/* 5320 8038B710 8FBF0024 */   lw        $ra, 0x24($sp)
/* 5324 8038B714 0C0CA0BD */  jal        marker_despawn
/* 5328 8038B718 8E040000 */   lw        $a0, ($s0)
.L8038B71C:
/* 532C 8038B71C 8FBF0024 */  lw         $ra, 0x24($sp)
.L8038B720:
/* 5330 8038B720 8FB00020 */  lw         $s0, 0x20($sp)
/* 5334 8038B724 27BD0048 */  addiu      $sp, $sp, 0x48
/* 5338 8038B728 03E00008 */  jr         $ra
/* 533C 8038B72C 00000000 */   nop
glabel func_8038B730
/* 5340 8038B730 27BDFFE0 */  addiu      $sp, $sp, -0x20
/* 5344 8038B734 AFBF0014 */  sw         $ra, 0x14($sp)
/* 5348 8038B738 AFA50024 */  sw         $a1, 0x24($sp)
/* 534C 8038B73C 0C0CA656 */  jal        marker_getActor
/* 5350 8038B740 AFA60028 */   sw        $a2, 0x28($sp)
/* 5354 8038B744 0C0AF9C8 */  jal        func_802BE720
/* 5358 8038B748 AFA2001C */   sw        $v0, 0x1c($sp)
/* 535C 8038B74C 44806000 */  mtc1       $zero, $f12
/* 5360 8038B750 0C0C93A2 */  jal        func_80324E88
/* 5364 8038B754 00000000 */   nop
/* 5368 8038B758 0C0A3DE1 */  jal        func_8028F784
/* 536C 8038B75C 00002025 */   or        $a0, $zero, $zero
/* 5370 8038B760 8FAE001C */  lw         $t6, 0x1c($sp)
/* 5374 8038B764 24050001 */  addiu      $a1, $zero, 1
/* 5378 8038B768 0C0E1DCA */  jal        func_80387728
/* 537C 8038B76C 8DC40000 */   lw        $a0, ($t6)
/* 5380 8038B770 8FBF0014 */  lw         $ra, 0x14($sp)
/* 5384 8038B774 27BD0020 */  addiu      $sp, $sp, 0x20
/* 5388 8038B778 03E00008 */  jr         $ra
/* 538C 8038B77C 00000000 */   nop
glabel func_8038B780
/* 5390 8038B780 27BDFFD8 */  addiu      $sp, $sp, -0x28
/* 5394 8038B784 AFBF001C */  sw         $ra, 0x1c($sp)
/* 5398 8038B788 0C0CA656 */  jal        marker_getActor
/* 539C 8038B78C 00000000 */   nop
/* 53A0 8038B790 240400CF */  addiu      $a0, $zero, 0xcf
/* 53A4 8038B794 0C0C7FC7 */  jal        func_8031FF1C
/* 53A8 8038B798 AFA20024 */   sw        $v0, 0x24($sp)
/* 53AC 8038B79C 14400011 */  bnez       $v0, .L8038B7E4
/* 53B0 8038B7A0 8FA30024 */   lw        $v1, 0x24($sp)
/* 53B4 8038B7A4 240400CF */  addiu      $a0, $zero, 0xcf
/* 53B8 8038B7A8 24050001 */  addiu      $a1, $zero, 1
/* 53BC 8038B7AC 0C0C8001 */  jal        func_80320004
/* 53C0 8038B7B0 AFA30024 */   sw        $v1, 0x24($sp)
/* 53C4 8038B7B4 8FA30024 */  lw         $v1, 0x24($sp)
/* 53C8 8038B7B8 3C0E8039 */  lui        $t6, %hi(func_8038B730)
/* 53CC 8038B7BC 25CEB730 */  addiu      $t6, $t6, %lo(func_8038B730)
/* 53D0 8038B7C0 8C670000 */  lw         $a3, ($v1)
/* 53D4 8038B7C4 AFA00014 */  sw         $zero, 0x14($sp)
/* 53D8 8038B7C8 AFAE0010 */  sw         $t6, 0x10($sp)
/* 53DC 8038B7CC 240410E7 */  addiu      $a0, $zero, 0x10e7
/* 53E0 8038B7D0 2405002A */  addiu      $a1, $zero, 0x2a
/* 53E4 8038B7D4 0C0C4520 */  jal        func_80311480
/* 53E8 8038B7D8 24660004 */   addiu     $a2, $v1, 4
/* 53EC 8038B7DC 10000010 */  b          .L8038B820
/* 53F0 8038B7E0 8FBF001C */   lw        $ra, 0x1c($sp)
.L8038B7E4:
/* 53F4 8038B7E4 00002025 */  or         $a0, $zero, $zero
/* 53F8 8038B7E8 24050005 */  addiu      $a1, $zero, 5
/* 53FC 8038B7EC 0C0D29EF */  jal        randi2
/* 5400 8038B7F0 AFA30024 */   sw        $v1, 0x24($sp)
/* 5404 8038B7F4 8FA30024 */  lw         $v1, 0x24($sp)
/* 5408 8038B7F8 3C0F8039 */  lui        $t7, %hi(func_8038B730)
/* 540C 8038B7FC 25EFB730 */  addiu      $t7, $t7, %lo(func_8038B730)
/* 5410 8038B800 8C670000 */  lw         $a3, ($v1)
/* 5414 8038B804 AFA00014 */  sw         $zero, 0x14($sp)
/* 5418 8038B808 AFAF0010 */  sw         $t7, 0x10($sp)
/* 541C 8038B80C 244410E8 */  addiu      $a0, $v0, 0x10e8
/* 5420 8038B810 2405002B */  addiu      $a1, $zero, 0x2b
/* 5424 8038B814 0C0C4520 */  jal        func_80311480
/* 5428 8038B818 24660004 */   addiu     $a2, $v1, 4
/* 542C 8038B81C 8FBF001C */  lw         $ra, 0x1c($sp)
.L8038B820:
/* 5430 8038B820 27BD0028 */  addiu      $sp, $sp, 0x28
/* 5434 8038B824 03E00008 */  jr         $ra
/* 5438 8038B828 00000000 */   nop
glabel func_8038B82C
/* 543C 8038B82C 03E00008 */  jr         $ra
/* 5440 8038B830 AFA40000 */   sw        $a0, ($sp)
glabel func_8038B834
/* 5444 8038B834 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 5448 8038B838 AFBF0014 */  sw         $ra, 0x14($sp)
/* 544C 8038B83C AFA5001C */  sw         $a1, 0x1c($sp)
/* 5450 8038B840 0C0CA656 */  jal        marker_getActor
/* 5454 8038B844 AFA40018 */   sw        $a0, 0x18($sp)
/* 5458 8038B848 904E007C */  lbu        $t6, 0x7c($v0)
/* 545C 8038B84C 8FA40018 */  lw         $a0, 0x18($sp)
/* 5460 8038B850 25CFFFFF */  addiu      $t7, $t6, -1
/* 5464 8038B854 2DE10005 */  sltiu      $at, $t7, 5
/* 5468 8038B858 10200048 */  beqz       $at, .L8038B97C
/* 546C 8038B85C 000F7880 */   sll       $t7, $t7, 2
/* 5470 8038B860 3C018039 */  lui        $at, %hi(D_8039242C)
/* 5474 8038B864 002F0821 */  addu       $at, $at, $t7
/* 5478 8038B868 8C2F242C */  lw         $t7, %lo(D_8039242C)($at)
/* 547C 8038B86C 01E00008 */  jr         $t7
/* 5480 8038B870 00000000 */   nop
/* 5484 8038B874 8C430010 */  lw         $v1, 0x10($v0)
/* 5488 8038B878 24010006 */  addiu      $at, $zero, 6
/* 548C 8038B87C 0003C682 */  srl        $t8, $v1, 0x1a
/* 5490 8038B880 13010003 */  beq        $t8, $at, .L8038B890
/* 5494 8038B884 24010007 */   addiu     $at, $zero, 7
/* 5498 8038B888 5701000A */  bnel       $t8, $at, .L8038B8B4
/* 549C 8038B88C 8C820014 */   lw        $v0, 0x14($a0)
.L8038B890:
/* 54A0 8038B890 8C820014 */  lw         $v0, 0x14($a0)
/* 54A4 8038B894 0002CAC2 */  srl        $t9, $v0, 0xb
/* 54A8 8038B898 3B280260 */  xori       $t0, $t9, 0x260
/* 54AC 8038B89C 00084D80 */  sll        $t1, $t0, 0x16
/* 54B0 8038B8A0 000952C2 */  srl        $t2, $t1, 0xb
/* 54B4 8038B8A4 01425826 */  xor        $t3, $t2, $v0
/* 54B8 8038B8A8 1000003B */  b          .L8038B998
/* 54BC 8038B8AC AC8B0014 */   sw        $t3, 0x14($a0)
/* 54C0 8038B8B0 8C820014 */  lw         $v0, 0x14($a0)
.L8038B8B4:
/* 54C4 8038B8B4 000262C2 */  srl        $t4, $v0, 0xb
/* 54C8 8038B8B8 398D025E */  xori       $t5, $t4, 0x25e
/* 54CC 8038B8BC 000D7580 */  sll        $t6, $t5, 0x16
/* 54D0 8038B8C0 000E7AC2 */  srl        $t7, $t6, 0xb
/* 54D4 8038B8C4 01E2C026 */  xor        $t8, $t7, $v0
/* 54D8 8038B8C8 10000033 */  b          .L8038B998
/* 54DC 8038B8CC AC980014 */   sw        $t8, 0x14($a0)
/* 54E0 8038B8D0 90590086 */  lbu        $t9, 0x86($v0)
/* 54E4 8038B8D4 5720000A */  bnel       $t9, $zero, .L8038B900
/* 54E8 8038B8D8 8C820014 */   lw        $v0, 0x14($a0)
/* 54EC 8038B8DC 8C820014 */  lw         $v0, 0x14($a0)
/* 54F0 8038B8E0 000242C2 */  srl        $t0, $v0, 0xb
/* 54F4 8038B8E4 39090260 */  xori       $t1, $t0, 0x260
/* 54F8 8038B8E8 00095580 */  sll        $t2, $t1, 0x16
/* 54FC 8038B8EC 000A5AC2 */  srl        $t3, $t2, 0xb
/* 5500 8038B8F0 01626026 */  xor        $t4, $t3, $v0
/* 5504 8038B8F4 10000028 */  b          .L8038B998
/* 5508 8038B8F8 AC8C0014 */   sw        $t4, 0x14($a0)
/* 550C 8038B8FC 8C820014 */  lw         $v0, 0x14($a0)
.L8038B900:
/* 5510 8038B900 00026AC2 */  srl        $t5, $v0, 0xb
/* 5514 8038B904 39AE0281 */  xori       $t6, $t5, 0x281
/* 5518 8038B908 000E7D80 */  sll        $t7, $t6, 0x16
/* 551C 8038B90C 000FC2C2 */  srl        $t8, $t7, 0xb
/* 5520 8038B910 0302C826 */  xor        $t9, $t8, $v0
/* 5524 8038B914 10000020 */  b          .L8038B998
/* 5528 8038B918 AC990014 */   sw        $t9, 0x14($a0)
/* 552C 8038B91C 8C820014 */  lw         $v0, 0x14($a0)
/* 5530 8038B920 000242C2 */  srl        $t0, $v0, 0xb
/* 5534 8038B924 39090282 */  xori       $t1, $t0, 0x282
/* 5538 8038B928 00095580 */  sll        $t2, $t1, 0x16
/* 553C 8038B92C 000A5AC2 */  srl        $t3, $t2, 0xb
/* 5540 8038B930 01626026 */  xor        $t4, $t3, $v0
/* 5544 8038B934 10000018 */  b          .L8038B998
/* 5548 8038B938 AC8C0014 */   sw        $t4, 0x14($a0)
/* 554C 8038B93C 8C820014 */  lw         $v0, 0x14($a0)
/* 5550 8038B940 00026AC2 */  srl        $t5, $v0, 0xb
/* 5554 8038B944 39AE0283 */  xori       $t6, $t5, 0x283
/* 5558 8038B948 000E7D80 */  sll        $t7, $t6, 0x16
/* 555C 8038B94C 000FC2C2 */  srl        $t8, $t7, 0xb
/* 5560 8038B950 0302C826 */  xor        $t9, $t8, $v0
/* 5564 8038B954 10000010 */  b          .L8038B998
/* 5568 8038B958 AC990014 */   sw        $t9, 0x14($a0)
/* 556C 8038B95C 8C820014 */  lw         $v0, 0x14($a0)
/* 5570 8038B960 000242C2 */  srl        $t0, $v0, 0xb
/* 5574 8038B964 39090283 */  xori       $t1, $t0, 0x283
/* 5578 8038B968 00095580 */  sll        $t2, $t1, 0x16
/* 557C 8038B96C 000A5AC2 */  srl        $t3, $t2, 0xb
/* 5580 8038B970 01626026 */  xor        $t4, $t3, $v0
/* 5584 8038B974 10000008 */  b          .L8038B998
/* 5588 8038B978 AC8C0014 */   sw        $t4, 0x14($a0)
.L8038B97C:
/* 558C 8038B97C 8C820014 */  lw         $v0, 0x14($a0)
/* 5590 8038B980 00026AC2 */  srl        $t5, $v0, 0xb
/* 5594 8038B984 39AE025E */  xori       $t6, $t5, 0x25e
/* 5598 8038B988 000E7D80 */  sll        $t7, $t6, 0x16
/* 559C 8038B98C 000FC2C2 */  srl        $t8, $t7, 0xb
/* 55A0 8038B990 0302C826 */  xor        $t9, $t8, $v0
/* 55A4 8038B994 AC990014 */  sw         $t9, 0x14($a0)
.L8038B998:
/* 55A8 8038B998 8FBF0014 */  lw         $ra, 0x14($sp)
/* 55AC 8038B99C 27BD0018 */  addiu      $sp, $sp, 0x18
/* 55B0 8038B9A0 24020001 */  addiu      $v0, $zero, 1
/* 55B4 8038B9A4 03E00008 */  jr         $ra
/* 55B8 8038B9A8 00000000 */   nop
glabel func_8038B9AC
/* 55BC 8038B9AC 27BDFFD0 */  addiu      $sp, $sp, -0x30
/* 55C0 8038B9B0 AFBF0024 */  sw         $ra, 0x24($sp)
/* 55C4 8038B9B4 AFB00020 */  sw         $s0, 0x20($sp)
/* 55C8 8038B9B8 0C0CA656 */  jal        marker_getActor
/* 55CC 8038B9BC AFA50034 */   sw        $a1, 0x34($sp)
/* 55D0 8038B9C0 AFA2002C */  sw         $v0, 0x2c($sp)
/* 55D4 8038B9C4 9044007C */  lbu        $a0, 0x7c($v0)
/* 55D8 8038B9C8 2443007C */  addiu      $v1, $v0, 0x7c
/* 55DC 8038B9CC 24010001 */  addiu      $at, $zero, 1
/* 55E0 8038B9D0 10810008 */  beq        $a0, $at, .L8038B9F4
/* 55E4 8038B9D4 00608025 */   or        $s0, $v1, $zero
/* 55E8 8038B9D8 24010002 */  addiu      $at, $zero, 2
/* 55EC 8038B9DC 1081001D */  beq        $a0, $at, .L8038BA54
/* 55F0 8038B9E0 24010003 */   addiu     $at, $zero, 3
/* 55F4 8038B9E4 50810047 */  beql       $a0, $at, .L8038BB04
/* 55F8 8038B9E8 90780001 */   lbu       $t8, 1($v1)
/* 55FC 8038B9EC 10000063 */  b          .L8038BB7C
/* 5600 8038B9F0 8FBF0024 */   lw        $ra, 0x24($sp)
.L8038B9F4:
/* 5604 8038B9F4 906E0001 */  lbu        $t6, 1($v1)
/* 5608 8038B9F8 00002025 */  or         $a0, $zero, $zero
/* 560C 8038B9FC 55C0000B */  bnel       $t6, $zero, .L8038BA2C
/* 5610 8038BA00 92020001 */   lbu       $v0, 1($s0)
/* 5614 8038BA04 0C0D29EF */  jal        randi2
/* 5618 8038BA08 24050005 */   addiu     $a1, $zero, 5
/* 561C 8038BA0C 244410F7 */  addiu      $a0, $v0, 0x10f7
/* 5620 8038BA10 24050020 */  addiu      $a1, $zero, 0x20
/* 5624 8038BA14 00003025 */  or         $a2, $zero, $zero
/* 5628 8038BA18 00003825 */  or         $a3, $zero, $zero
/* 562C 8038BA1C AFA00010 */  sw         $zero, 0x10($sp)
/* 5630 8038BA20 0C0C4520 */  jal        func_80311480
/* 5634 8038BA24 AFA00014 */   sw        $zero, 0x14($sp)
/* 5638 8038BA28 92020001 */  lbu        $v0, 1($s0)
.L8038BA2C:
/* 563C 8038BA2C 2405000D */  addiu      $a1, $zero, 0xd
/* 5640 8038BA30 244F0001 */  addiu      $t7, $v0, 1
/* 5644 8038BA34 29E10005 */  slti       $at, $t7, 5
/* 5648 8038BA38 1020004F */  beqz       $at, .L8038BB78
/* 564C 8038BA3C 24580001 */   addiu     $t8, $v0, 1
/* 5650 8038BA40 A2180001 */  sb         $t8, 1($s0)
/* 5654 8038BA44 0C0E2061 */  jal        func_80388184
/* 5658 8038BA48 8FA4002C */   lw        $a0, 0x2c($sp)
/* 565C 8038BA4C 1000004A */  b          .L8038BB78
/* 5660 8038BA50 A2000004 */   sb        $zero, 4($s0)
.L8038BA54:
/* 5664 8038BA54 8C590010 */  lw         $t9, 0x10($v0)
/* 5668 8038BA58 24010014 */  addiu      $at, $zero, 0x14
/* 566C 8038BA5C 00194682 */  srl        $t0, $t9, 0x1a
/* 5670 8038BA60 51010046 */  beql       $t0, $at, .L8038BB7C
/* 5674 8038BA64 8FBF0024 */   lw        $ra, 0x24($sp)
/* 5678 8038BA68 90690002 */  lbu        $t1, 2($v1)
/* 567C 8038BA6C 252A0001 */  addiu      $t2, $t1, 1
/* 5680 8038BA70 29410003 */  slti       $at, $t2, 3
/* 5684 8038BA74 5420001B */  bnel       $at, $zero, .L8038BAE4
/* 5688 8038BA78 920E0002 */   lbu       $t6, 2($s0)
/* 568C 8038BA7C 906B0001 */  lbu        $t3, 1($v1)
/* 5690 8038BA80 A0600002 */  sb         $zero, 2($v1)
/* 5694 8038BA84 00002025 */  or         $a0, $zero, $zero
/* 5698 8038BA88 5560000B */  bnel       $t3, $zero, .L8038BAB8
/* 569C 8038BA8C 92020001 */   lbu       $v0, 1($s0)
/* 56A0 8038BA90 0C0D29EF */  jal        randi2
/* 56A4 8038BA94 24050005 */   addiu     $a1, $zero, 5
/* 56A8 8038BA98 24441110 */  addiu      $a0, $v0, 0x1110
/* 56AC 8038BA9C 24050020 */  addiu      $a1, $zero, 0x20
/* 56B0 8038BAA0 00003025 */  or         $a2, $zero, $zero
/* 56B4 8038BAA4 00003825 */  or         $a3, $zero, $zero
/* 56B8 8038BAA8 AFA00010 */  sw         $zero, 0x10($sp)
/* 56BC 8038BAAC 0C0C4520 */  jal        func_80311480
/* 56C0 8038BAB0 AFA00014 */   sw        $zero, 0x14($sp)
/* 56C4 8038BAB4 92020001 */  lbu        $v0, 1($s0)
.L8038BAB8:
/* 56C8 8038BAB8 24050014 */  addiu      $a1, $zero, 0x14
/* 56CC 8038BABC 244C0001 */  addiu      $t4, $v0, 1
/* 56D0 8038BAC0 29810005 */  slti       $at, $t4, 5
/* 56D4 8038BAC4 1020002C */  beqz       $at, .L8038BB78
/* 56D8 8038BAC8 244D0001 */   addiu     $t5, $v0, 1
/* 56DC 8038BACC A20D0001 */  sb         $t5, 1($s0)
/* 56E0 8038BAD0 0C0E2479 */  jal        func_803891E4
/* 56E4 8038BAD4 8FA4002C */   lw        $a0, 0x2c($sp)
/* 56E8 8038BAD8 10000028 */  b          .L8038BB7C
/* 56EC 8038BADC 8FBF0024 */   lw        $ra, 0x24($sp)
/* 56F0 8038BAE0 920E0002 */  lbu        $t6, 2($s0)
.L8038BAE4:
/* 56F4 8038BAE4 24050013 */  addiu      $a1, $zero, 0x13
/* 56F8 8038BAE8 25CF0001 */  addiu      $t7, $t6, 1
/* 56FC 8038BAEC A20F0002 */  sb         $t7, 2($s0)
/* 5700 8038BAF0 0C0E2479 */  jal        func_803891E4
/* 5704 8038BAF4 8FA4002C */   lw        $a0, 0x2c($sp)
/* 5708 8038BAF8 10000020 */  b          .L8038BB7C
/* 570C 8038BAFC 8FBF0024 */   lw        $ra, 0x24($sp)
/* 5710 8038BB00 90780001 */  lbu        $t8, 1($v1)
.L8038BB04:
/* 5714 8038BB04 00002025 */  or         $a0, $zero, $zero
/* 5718 8038BB08 5700000B */  bnel       $t8, $zero, .L8038BB38
/* 571C 8038BB0C 92020001 */   lbu       $v0, 1($s0)
/* 5720 8038BB10 0C0D29EF */  jal        randi2
/* 5724 8038BB14 24050005 */   addiu     $a1, $zero, 5
/* 5728 8038BB18 24441127 */  addiu      $a0, $v0, 0x1127
/* 572C 8038BB1C 24050020 */  addiu      $a1, $zero, 0x20
/* 5730 8038BB20 00003025 */  or         $a2, $zero, $zero
/* 5734 8038BB24 00003825 */  or         $a3, $zero, $zero
/* 5738 8038BB28 AFA00010 */  sw         $zero, 0x10($sp)
/* 573C 8038BB2C 0C0C4520 */  jal        func_80311480
/* 5740 8038BB30 AFA00014 */   sw        $zero, 0x14($sp)
/* 5744 8038BB34 92020001 */  lbu        $v0, 1($s0)
.L8038BB38:
/* 5748 8038BB38 24050019 */  addiu      $a1, $zero, 0x19
/* 574C 8038BB3C 24590001 */  addiu      $t9, $v0, 1
/* 5750 8038BB40 2B210005 */  slti       $at, $t9, 5
/* 5754 8038BB44 1020000C */  beqz       $at, .L8038BB78
/* 5758 8038BB48 24480001 */   addiu     $t0, $v0, 1
/* 575C 8038BB4C A2080001 */  sb         $t0, 1($s0)
/* 5760 8038BB50 0C0E2663 */  jal        func_8038998C
/* 5764 8038BB54 8FA4002C */   lw        $a0, 0x2c($sp)
/* 5768 8038BB58 92090001 */  lbu        $t1, 1($s0)
/* 576C 8038BB5C 24010004 */  addiu      $at, $zero, 4
/* 5770 8038BB60 3C048038 */  lui        $a0, %hi(func_80386DE4)
/* 5774 8038BB64 15210004 */  bne        $t1, $at, .L8038BB78
/* 5778 8038BB68 8FAA002C */   lw        $t2, 0x2c($sp)
/* 577C 8038BB6C 24846DE4 */  addiu      $a0, $a0, %lo(func_80386DE4)
/* 5780 8038BB70 0C0B0F22 */  jal        func_802C3C88
/* 5784 8038BB74 8D450000 */   lw        $a1, ($t2)
.L8038BB78:
/* 5788 8038BB78 8FBF0024 */  lw         $ra, 0x24($sp)
.L8038BB7C:
/* 578C 8038BB7C 8FB00020 */  lw         $s0, 0x20($sp)
/* 5790 8038BB80 27BD0030 */  addiu      $sp, $sp, 0x30
/* 5794 8038BB84 03E00008 */  jr         $ra
/* 5798 8038BB88 00000000 */   nop
glabel func_8038BB8C
/* 579C 8038BB8C 27BDFFD8 */  addiu      $sp, $sp, -0x28
/* 57A0 8038BB90 AFBF001C */  sw         $ra, 0x1c($sp)
/* 57A4 8038BB94 0C0CA656 */  jal        marker_getActor
/* 57A8 8038BB98 AFA5002C */   sw        $a1, 0x2c($sp)
/* 57AC 8038BB9C AFA20024 */  sw         $v0, 0x24($sp)
/* 57B0 8038BBA0 904E007C */  lbu        $t6, 0x7c($v0)
/* 57B4 8038BBA4 24010001 */  addiu      $at, $zero, 1
/* 57B8 8038BBA8 2443007C */  addiu      $v1, $v0, 0x7c
/* 57BC 8038BBAC 15C10026 */  bne        $t6, $at, .L8038BC48
/* 57C0 8038BBB0 3C018039 */   lui       $at, %hi(D_80392440)
/* 57C4 8038BBB4 C42C2440 */  lwc1       $f12, %lo(D_80392440)($at)
/* 57C8 8038BBB8 3C018039 */  lui        $at, %hi(D_80392444)
/* 57CC 8038BBBC C42E2444 */  lwc1       $f14, %lo(D_80392444)($at)
/* 57D0 8038BBC0 0C0D29D5 */  jal        randf2
/* 57D4 8038BBC4 AFA30020 */   sw        $v1, 0x20($sp)
/* 57D8 8038BBC8 3C018039 */  lui        $at, %hi(D_80392448)
/* 57DC 8038BBCC C4242448 */  lwc1       $f4, %lo(D_80392448)($at)
/* 57E0 8038BBD0 3C018039 */  lui        $at, %hi(D_8039244C)
/* 57E4 8038BBD4 C426244C */  lwc1       $f6, %lo(D_8039244C)($at)
/* 57E8 8038BBD8 8FA70024 */  lw         $a3, 0x24($sp)
/* 57EC 8038BBDC 44050000 */  mfc1       $a1, $f0
/* 57F0 8038BBE0 240400EA */  addiu      $a0, $zero, 0xea
/* 57F4 8038BBE4 24067D00 */  addiu      $a2, $zero, 0x7d00
/* 57F8 8038BBE8 E7A40010 */  swc1       $f4, 0x10($sp)
/* 57FC 8038BBEC E7A60014 */  swc1       $f6, 0x14($sp)
/* 5800 8038BBF0 0C0C3A1E */  jal        func_8030E878
/* 5804 8038BBF4 24E70004 */   addiu     $a3, $a3, 4
/* 5808 8038BBF8 8FA30020 */  lw         $v1, 0x20($sp)
/* 580C 8038BBFC 00002025 */  or         $a0, $zero, $zero
/* 5810 8038BC00 24050005 */  addiu      $a1, $zero, 5
/* 5814 8038BC04 8C6F0010 */  lw         $t7, 0x10($v1)
/* 5818 8038BC08 55E00010 */  bnel       $t7, $zero, .L8038BC4C
/* 581C 8038BC0C 90680000 */   lbu       $t0, ($v1)
/* 5820 8038BC10 0C0D29EF */  jal        randi2
/* 5824 8038BC14 AFA30020 */   sw        $v1, 0x20($sp)
/* 5828 8038BC18 244410ED */  addiu      $a0, $v0, 0x10ed
/* 582C 8038BC1C 00002825 */  or         $a1, $zero, $zero
/* 5830 8038BC20 00003025 */  or         $a2, $zero, $zero
/* 5834 8038BC24 00003825 */  or         $a3, $zero, $zero
/* 5838 8038BC28 AFA00010 */  sw         $zero, 0x10($sp)
/* 583C 8038BC2C 0C0C4520 */  jal        func_80311480
/* 5840 8038BC30 AFA00014 */   sw        $zero, 0x14($sp)
/* 5844 8038BC34 10400004 */  beqz       $v0, .L8038BC48
/* 5848 8038BC38 8FA30020 */   lw        $v1, 0x20($sp)
/* 584C 8038BC3C 8C780010 */  lw         $t8, 0x10($v1)
/* 5850 8038BC40 27190001 */  addiu      $t9, $t8, 1
/* 5854 8038BC44 AC790010 */  sw         $t9, 0x10($v1)
.L8038BC48:
/* 5858 8038BC48 90680000 */  lbu        $t0, ($v1)
.L8038BC4C:
/* 585C 8038BC4C 24010003 */  addiu      $at, $zero, 3
/* 5860 8038BC50 55010016 */  bnel       $t0, $at, .L8038BCAC
/* 5864 8038BC54 8FBF001C */   lw        $ra, 0x1c($sp)
/* 5868 8038BC58 90620006 */  lbu        $v0, 6($v1)
/* 586C 8038BC5C 8FA90024 */  lw         $t1, 0x24($sp)
/* 5870 8038BC60 54400012 */  bnel       $v0, $zero, .L8038BCAC
/* 5874 8038BC64 8FBF001C */   lw        $ra, 0x1c($sp)
/* 5878 8038BC68 8D2A0010 */  lw         $t2, 0x10($t1)
/* 587C 8038BC6C 2401001A */  addiu      $at, $zero, 0x1a
/* 5880 8038BC70 244C0001 */  addiu      $t4, $v0, 1
/* 5884 8038BC74 000A5E82 */  srl        $t3, $t2, 0x1a
/* 5888 8038BC78 1161000B */  beq        $t3, $at, .L8038BCA8
/* 588C 8038BC7C 00002025 */   or        $a0, $zero, $zero
/* 5890 8038BC80 A06C0006 */  sb         $t4, 6($v1)
/* 5894 8038BC84 0C0D29EF */  jal        randi2
/* 5898 8038BC88 24050005 */   addiu     $a1, $zero, 5
/* 589C 8038BC8C 2444111D */  addiu      $a0, $v0, 0x111d
/* 58A0 8038BC90 00002825 */  or         $a1, $zero, $zero
/* 58A4 8038BC94 00003025 */  or         $a2, $zero, $zero
/* 58A8 8038BC98 00003825 */  or         $a3, $zero, $zero
/* 58AC 8038BC9C AFA00010 */  sw         $zero, 0x10($sp)
/* 58B0 8038BCA0 0C0C4520 */  jal        func_80311480
/* 58B4 8038BCA4 AFA00014 */   sw        $zero, 0x14($sp)
.L8038BCA8:
/* 58B8 8038BCA8 8FBF001C */  lw         $ra, 0x1c($sp)
.L8038BCAC:
/* 58BC 8038BCAC 27BD0028 */  addiu      $sp, $sp, 0x28
/* 58C0 8038BCB0 03E00008 */  jr         $ra
/* 58C4 8038BCB4 00000000 */   nop
glabel func_8038BCB8
/* 58C8 8038BCB8 27BDFFE0 */  addiu      $sp, $sp, -0x20
/* 58CC 8038BCBC AFBF0014 */  sw         $ra, 0x14($sp)
/* 58D0 8038BCC0 0C0CA656 */  jal        marker_getActor
/* 58D4 8038BCC4 00000000 */   nop
/* 58D8 8038BCC8 AFA2001C */  sw         $v0, 0x1c($sp)
/* 58DC 8038BCCC 240403AF */  addiu      $a0, $zero, 0x3af
/* 58E0 8038BCD0 0C0CA063 */  jal        spawn_child_actor
/* 58E4 8038BCD4 27A5001C */   addiu     $a1, $sp, 0x1c
/* 58E8 8038BCD8 8FBF0014 */  lw         $ra, 0x14($sp)
/* 58EC 8038BCDC 8C4E0000 */  lw         $t6, ($v0)
/* 58F0 8038BCE0 3C018039 */  lui        $at, %hi(D_803927A4)
/* 58F4 8038BCE4 27BD0020 */  addiu      $sp, $sp, 0x20
/* 58F8 8038BCE8 03E00008 */  jr         $ra
/* 58FC 8038BCEC AC2E27A4 */   sw        $t6, %lo(D_803927A4)($at)
glabel func_8038BCF0
/* 5900 8038BCF0 27BDFF98 */  addiu      $sp, $sp, -0x68
/* 5904 8038BCF4 AFBF0024 */  sw         $ra, 0x24($sp)
/* 5908 8038BCF8 AFB20020 */  sw         $s2, 0x20($sp)
/* 590C 8038BCFC AFB1001C */  sw         $s1, 0x1c($sp)
/* 5910 8038BD00 AFB00018 */  sw         $s0, 0x18($sp)
/* 5914 8038BD04 8C8E016C */  lw         $t6, 0x16c($a0)
/* 5918 8038BD08 00809025 */  or         $s2, $a0, $zero
/* 591C 8038BD0C 3C058039 */  lui        $a1, 0x8039
/* 5920 8038BD10 000EC6C0 */  sll        $t8, $t6, 0x1b
/* 5924 8038BD14 0702007D */  bltzl      $t8, .L8038BF0C
/* 5928 8038BD18 2650007C */   addiu     $s0, $s2, 0x7c
/* 592C 8038BD1C 9248016F */  lbu        $t0, 0x16f($s2)
/* 5930 8038BD20 8E440000 */  lw         $a0, ($s2)
/* 5934 8038BD24 24A5B834 */  addiu      $a1, $a1, -0x47cc
/* 5938 8038BD28 35090010 */  ori        $t1, $t0, 0x10
/* 593C 8038BD2C 0C0CC030 */  jal        func_803300C0
/* 5940 8038BD30 A249016F */   sb        $t1, 0x16f($s2)
/* 5944 8038BD34 3C058039 */  lui        $a1, %hi(func_8038BB8C)
/* 5948 8038BD38 3C068039 */  lui        $a2, %hi(func_8038B9AC)
/* 594C 8038BD3C 24C6B9AC */  addiu      $a2, $a2, %lo(func_8038B9AC)
/* 5950 8038BD40 24A5BB8C */  addiu      $a1, $a1, %lo(func_8038BB8C)
/* 5954 8038BD44 8E440000 */  lw         $a0, ($s2)
/* 5958 8038BD48 0C0CC02A */  jal        marker_setCollisionScripts
/* 595C 8038BD4C 00003825 */   or        $a3, $zero, $zero
/* 5960 8038BD50 8E4A0000 */  lw         $t2, ($s2)
/* 5964 8038BD54 02402025 */  or         $a0, $s2, $zero
/* 5968 8038BD58 8D420000 */  lw         $v0, ($t2)
/* 596C 8038BD5C 904B000B */  lbu        $t3, 0xb($v0)
/* 5970 8038BD60 316CFFF7 */  andi       $t4, $t3, 0xfff7
/* 5974 8038BD64 0C0CAAA2 */  jal        actor_collisionOn
/* 5978 8038BD68 A04C000B */   sb        $t4, 0xb($v0)
/* 597C 8038BD6C 3C118039 */  lui        $s1, %hi(D_803927D0)
/* 5980 8038BD70 263127D0 */  addiu      $s1, $s1, %lo(D_803927D0)
/* 5984 8038BD74 2410038C */  addiu      $s0, $zero, 0x38c
.L8038BD78:
/* 5988 8038BD78 02002025 */  or         $a0, $s0, $zero
/* 598C 8038BD7C 0C0C1389 */  jal        func_80304E24
/* 5990 8038BD80 02202825 */   or        $a1, $s1, $zero
/* 5994 8038BD84 26100001 */  addiu      $s0, $s0, 1
/* 5998 8038BD88 2A01039F */  slti       $at, $s0, 0x39f
/* 599C 8038BD8C 1420FFFA */  bnez       $at, .L8038BD78
/* 59A0 8038BD90 2631000C */   addiu     $s1, $s1, 0xc
/* 59A4 8038BD94 3C018039 */  lui        $at, %hi(D_803927A8)
/* 59A8 8038BD98 AC2027A8 */  sw         $zero, %lo(D_803927A8)($at)
/* 59AC 8038BD9C 3C018039 */  lui        $at, %hi(D_803927A4)
/* 59B0 8038BDA0 AC2027A4 */  sw         $zero, %lo(D_803927A4)($at)
/* 59B4 8038BDA4 3C018039 */  lui        $at, %hi(D_803927C4)
/* 59B8 8038BDA8 A02027C4 */  sb         $zero, %lo(D_803927C4)($at)
/* 59BC 8038BDAC 3C018039 */  lui        $at, %hi(D_803927C5)
/* 59C0 8038BDB0 A02027C5 */  sb         $zero, %lo(D_803927C5)($at)
/* 59C4 8038BDB4 3C018039 */  lui        $at, %hi(D_803927C6)
/* 59C8 8038BDB8 A02027C6 */  sb         $zero, %lo(D_803927C6)($at)
/* 59CC 8038BDBC 3C018039 */  lui        $at, %hi(D_803927C7)
/* 59D0 8038BDC0 A02027C7 */  sb         $zero, %lo(D_803927C7)($at)
/* 59D4 8038BDC4 3C018039 */  lui        $at, %hi(D_803927C8)
/* 59D8 8038BDC8 A02027C8 */  sb         $zero, %lo(D_803927C8)($at)
/* 59DC 8038BDCC 3C018039 */  lui        $at, %hi(D_803927C9)
/* 59E0 8038BDD0 A02027C9 */  sb         $zero, %lo(D_803927C9)($at)
/* 59E4 8038BDD4 2650007C */  addiu      $s0, $s2, 0x7c
/* 59E8 8038BDD8 A2000008 */  sb         $zero, 8($s0)
/* 59EC 8038BDDC A2000009 */  sb         $zero, 9($s0)
/* 59F0 8038BDE0 A200000B */  sb         $zero, 0xb($s0)
/* 59F4 8038BDE4 3C018039 */  lui        $at, %hi(D_803927B4)
/* 59F8 8038BDE8 AC2027B4 */  sw         $zero, %lo(D_803927B4)($at)
/* 59FC 8038BDEC AC2027B0 */  sw         $zero, 0x27b0($at)
/* 5A00 8038BDF0 3C018039 */  lui        $at, %hi(D_803927B8)
/* 5A04 8038BDF4 AC2027B8 */  sw         $zero, %lo(D_803927B8)($at)
/* 5A08 8038BDF8 AC2027BC */  sw         $zero, 0x27bc($at)
/* 5A0C 8038BDFC 3C048039 */  lui        $a0, %hi(func_8038BCB8)
/* 5A10 8038BE00 2484BCB8 */  addiu      $a0, $a0, %lo(func_8038BCB8)
/* 5A14 8038BE04 0C0B0F22 */  jal        func_802C3C88
/* 5A18 8038BE08 8E450000 */   lw        $a1, ($s2)
/* 5A1C 8038BE0C 8E440000 */  lw         $a0, ($s2)
/* 5A20 8038BE10 0C0E1DCA */  jal        func_80387728
/* 5A24 8038BE14 00002825 */   or        $a1, $zero, $zero
/* 5A28 8038BE18 A2000001 */  sb         $zero, 1($s0)
/* 5A2C 8038BE1C 8E440000 */  lw         $a0, ($s2)
/* 5A30 8038BE20 0C0E1980 */  jal        func_80386600
/* 5A34 8038BE24 00002825 */   or        $a1, $zero, $zero
/* 5A38 8038BE28 8E440000 */  lw         $a0, ($s2)
/* 5A3C 8038BE2C 0C0E198A */  jal        func_80386628
/* 5A40 8038BE30 24050001 */   addiu     $a1, $zero, 1
/* 5A44 8038BE34 0C0E3F00 */  jal        func_8038FC00
/* 5A48 8038BE38 00000000 */   nop
/* 5A4C 8038BE3C 3C013F80 */  lui        $at, 0x3f80
/* 5A50 8038BE40 44816000 */  mtc1       $at, $f12
/* 5A54 8038BE44 3C058039 */  lui        $a1, %hi(D_80391380)
/* 5A58 8038BE48 3C068039 */  lui        $a2, %hi(D_80391390)
/* 5A5C 8038BE4C 24C61390 */  addiu      $a2, $a2, %lo(D_80391390)
/* 5A60 8038BE50 0C0E1995 */  jal        func_80386654
/* 5A64 8038BE54 24A51380 */   addiu     $a1, $a1, %lo(D_80391380)
/* 5A68 8038BE58 0C0A3DE1 */  jal        func_8028F784
/* 5A6C 8038BE5C 24040001 */   addiu     $a0, $zero, 1
/* 5A70 8038BE60 3C048039 */  lui        $a0, %hi(D_80391804)
/* 5A74 8038BE64 24841804 */  addiu      $a0, $a0, %lo(D_80391804)
/* 5A78 8038BE68 3C0544FA */  lui        $a1, 0x44fa
/* 5A7C 8038BE6C 0C0A3D2E */  jal        func_8028F4B8
/* 5A80 8038BE70 3C06C52F */   lui       $a2, 0xc52f
/* 5A84 8038BE74 24040093 */  addiu      $a0, $zero, 0x93
/* 5A88 8038BE78 0C0A3E85 */  jal        func_8028FA14
/* 5A8C 8038BE7C 24050002 */   addiu     $a1, $zero, 2
/* 5A90 8038BE80 0C0D326C */  jal        func_8034C9B0
/* 5A94 8038BE84 00002025 */   or        $a0, $zero, $zero
/* 5A98 8038BE88 3C014000 */  lui        $at, 0x4000
/* 5A9C 8038BE8C 44816000 */  mtc1       $at, $f12
/* 5AA0 8038BE90 0C0E19A6 */  jal        func_80386698
/* 5AA4 8038BE94 00000000 */   nop
/* 5AA8 8038BE98 0C0BE6AA */  jal        func_802F9AA8
/* 5AAC 8038BE9C 2404009A */   addiu     $a0, $zero, 0x9a
/* 5AB0 8038BEA0 3C018039 */  lui        $at, %hi(D_80392450)
/* 5AB4 8038BEA4 C4202450 */  lwc1       $f0, %lo(D_80392450)($at)
/* 5AB8 8038BEA8 00408025 */  or         $s0, $v0, $zero
/* 5ABC 8038BEAC 00402025 */  or         $a0, $v0, $zero
/* 5AC0 8038BEB0 44050000 */  mfc1       $a1, $f0
/* 5AC4 8038BEB4 44060000 */  mfc1       $a2, $f0
/* 5AC8 8038BEB8 0C0BE76E */  jal        func_802F9DB8
/* 5ACC 8038BEBC 24070000 */   addiu     $a3, $zero, 0
/* 5AD0 8038BEC0 44800000 */  mtc1       $zero, $f0
/* 5AD4 8038BEC4 02002025 */  or         $a0, $s0, $zero
/* 5AD8 8038BEC8 3C064000 */  lui        $a2, 0x4000
/* 5ADC 8038BECC 44050000 */  mfc1       $a1, $f0
/* 5AE0 8038BED0 44070000 */  mfc1       $a3, $f0
/* 5AE4 8038BED4 0C0BE7F4 */  jal        func_802F9FD0
/* 5AE8 8038BED8 00000000 */   nop
/* 5AEC 8038BEDC 02002025 */  or         $a0, $s0, $zero
/* 5AF0 8038BEE0 240561A8 */  addiu      $a1, $zero, 0x61a8
/* 5AF4 8038BEE4 240661A8 */  addiu      $a2, $zero, 0x61a8
/* 5AF8 8038BEE8 0C0BE818 */  jal        func_802FA060
/* 5AFC 8038BEEC 24070000 */   addiu     $a3, $zero, 0
/* 5B00 8038BEF0 3C014000 */  lui        $at, 0x4000
/* 5B04 8038BEF4 44816000 */  mtc1       $at, $f12
/* 5B08 8038BEF8 2405007F */  addiu      $a1, $zero, 0x7f
/* 5B0C 8038BEFC 3C063F80 */  lui        $a2, 0x3f80
/* 5B10 8038BF00 0C0C9322 */  jal        timed_playSfx
/* 5B14 8038BF04 24077D00 */   addiu     $a3, $zero, 0x7d00
/* 5B18 8038BF08 2650007C */  addiu      $s0, $s2, 0x7c
.L8038BF0C:
/* 5B1C 8038BF0C 92050000 */  lbu        $a1, ($s0)
/* 5B20 8038BF10 2CA10006 */  sltiu      $at, $a1, 6
/* 5B24 8038BF14 1020001D */  beqz       $at, .L8038BF8C
/* 5B28 8038BF18 00056880 */   sll       $t5, $a1, 2
/* 5B2C 8038BF1C 3C018039 */  lui        $at, %hi(D_80392454)
/* 5B30 8038BF20 002D0821 */  addu       $at, $at, $t5
/* 5B34 8038BF24 8C2D2454 */  lw         $t5, %lo(D_80392454)($at)
/* 5B38 8038BF28 01A00008 */  jr         $t5
/* 5B3C 8038BF2C 00000000 */   nop
/* 5B40 8038BF30 0C0E2E0B */  jal        func_8038B82C
/* 5B44 8038BF34 8E440000 */   lw        $a0, ($s2)
/* 5B48 8038BF38 10000014 */  b          .L8038BF8C
/* 5B4C 8038BF3C 92050000 */   lbu       $a1, ($s0)
/* 5B50 8038BF40 0C0E21D6 */  jal        func_80388758
/* 5B54 8038BF44 8E440000 */   lw        $a0, ($s2)
/* 5B58 8038BF48 10000010 */  b          .L8038BF8C
/* 5B5C 8038BF4C 92050000 */   lbu       $a1, ($s0)
/* 5B60 8038BF50 0C0E24E3 */  jal        func_8038938C
/* 5B64 8038BF54 8E440000 */   lw        $a0, ($s2)
/* 5B68 8038BF58 1000000C */  b          .L8038BF8C
/* 5B6C 8038BF5C 92050000 */   lbu       $a1, ($s0)
/* 5B70 8038BF60 0C0E26DC */  jal        func_80389B70
/* 5B74 8038BF64 8E440000 */   lw        $a0, ($s2)
/* 5B78 8038BF68 10000008 */  b          .L8038BF8C
/* 5B7C 8038BF6C 92050000 */   lbu       $a1, ($s0)
/* 5B80 8038BF70 0C0E297D */  jal        func_8038A5F4
/* 5B84 8038BF74 8E440000 */   lw        $a0, ($s2)
/* 5B88 8038BF78 10000004 */  b          .L8038BF8C
/* 5B8C 8038BF7C 92050000 */   lbu       $a1, ($s0)
/* 5B90 8038BF80 0C0E2BF6 */  jal        func_8038AFD8
/* 5B94 8038BF84 8E440000 */   lw        $a0, ($s2)
/* 5B98 8038BF88 92050000 */  lbu        $a1, ($s0)
.L8038BF8C:
/* 5B9C 8038BF8C 24040023 */  addiu      $a0, $zero, 0x23
/* 5BA0 8038BF90 0C0C8149 */  jal        func_80320524
/* 5BA4 8038BF94 24060003 */   addiu     $a2, $zero, 3
/* 5BA8 8038BF98 3C048039 */  lui        $a0, %hi(D_80392788)
/* 5BAC 8038BF9C 0C0A3A69 */  jal        player_getPosition
/* 5BB0 8038BFA0 24842788 */   addiu     $a0, $a0, %lo(D_80392788)
/* 5BB4 8038BFA4 C6440004 */  lwc1       $f4, 4($s2)
/* 5BB8 8038BFA8 3C028039 */  lui        $v0, %hi(D_80392798)
/* 5BBC 8038BFAC 24422798 */  addiu      $v0, $v0, %lo(D_80392798)
/* 5BC0 8038BFB0 E4440000 */  swc1       $f4, ($v0)
/* 5BC4 8038BFB4 C6460008 */  lwc1       $f6, 8($s2)
/* 5BC8 8038BFB8 3C0E8039 */  lui        $t6, 0x8039
/* 5BCC 8038BFBC E4460004 */  swc1       $f6, 4($v0)
/* 5BD0 8038BFC0 C648000C */  lwc1       $f8, 0xc($s2)
/* 5BD4 8038BFC4 E4480008 */  swc1       $f8, 8($v0)
/* 5BD8 8038BFC8 8E440100 */  lw         $a0, 0x100($s2)
/* 5BDC 8038BFCC 10800006 */  beqz       $a0, .L8038BFE8
/* 5BE0 8038BFD0 00000000 */   nop
/* 5BE4 8038BFD4 91CE27C5 */  lbu        $t6, 0x27c5($t6)
/* 5BE8 8038BFD8 11C00003 */  beqz       $t6, .L8038BFE8
/* 5BEC 8038BFDC 00000000 */   nop
/* 5BF0 8038BFE0 0C0E3AE4 */  jal        func_8038EB90
/* 5BF4 8038BFE4 26450004 */   addiu     $a1, $s2, 4
.L8038BFE8:
/* 5BF8 8038BFE8 3C048039 */  lui        $a0, %hi(D_803927A4)
/* 5BFC 8038BFEC 8C8427A4 */  lw         $a0, %lo(D_803927A4)($a0)
/* 5C00 8038BFF0 50800035 */  beql       $a0, $zero, .L8038C0C8
/* 5C04 8038BFF4 8FBF0024 */   lw        $ra, 0x24($sp)
/* 5C08 8038BFF8 0C0CA656 */  jal        marker_getActor
/* 5C0C 8038BFFC 00000000 */   nop
/* 5C10 8038C000 C64A0004 */  lwc1       $f10, 4($s2)
/* 5C14 8038C004 3C014348 */  lui        $at, 0x4348
/* 5C18 8038C008 44812000 */  mtc1       $at, $f4
/* 5C1C 8038C00C E7AA004C */  swc1       $f10, 0x4c($sp)
/* 5C20 8038C010 C6500008 */  lwc1       $f16, 8($s2)
/* 5C24 8038C014 3C01C248 */  lui        $at, 0xc248
/* 5C28 8038C018 00408025 */  or         $s0, $v0, $zero
/* 5C2C 8038C01C E7B00050 */  swc1       $f16, 0x50($sp)
/* 5C30 8038C020 C652000C */  lwc1       $f18, 0xc($s2)
/* 5C34 8038C024 E7A40050 */  swc1       $f4, 0x50($sp)
/* 5C38 8038C028 44818000 */  mtc1       $at, $f16
/* 5C3C 8038C02C E7B20054 */  swc1       $f18, 0x54($sp)
/* 5C40 8038C030 C6460004 */  lwc1       $f6, 4($s2)
/* 5C44 8038C034 27A4004C */  addiu      $a0, $sp, 0x4c
/* 5C48 8038C038 27A50034 */  addiu      $a1, $sp, 0x34
/* 5C4C 8038C03C E7A60034 */  swc1       $f6, 0x34($sp)
/* 5C50 8038C040 C6480008 */  lwc1       $f8, 8($s2)
/* 5C54 8038C044 27A60040 */  addiu      $a2, $sp, 0x40
/* 5C58 8038C048 00003825 */  or         $a3, $zero, $zero
/* 5C5C 8038C04C E7A80038 */  swc1       $f8, 0x38($sp)
/* 5C60 8038C050 C64A000C */  lwc1       $f10, 0xc($s2)
/* 5C64 8038C054 E7B00038 */  swc1       $f16, 0x38($sp)
/* 5C68 8038C058 0C0C26D2 */  jal        func_80309B48
/* 5C6C 8038C05C E7AA003C */   swc1      $f10, 0x3c($sp)
/* 5C70 8038C060 10400015 */  beqz       $v0, .L8038C0B8
/* 5C74 8038C064 C7B20038 */   lwc1      $f18, 0x38($sp)
/* 5C78 8038C068 3C0140C0 */  lui        $at, 0x40c0
/* 5C7C 8038C06C 44812000 */  mtc1       $at, $f4
/* 5C80 8038C070 C7A80034 */  lwc1       $f8, 0x34($sp)
/* 5C84 8038C074 46049180 */  add.s      $f6, $f18, $f4
/* 5C88 8038C078 E7A60038 */  swc1       $f6, 0x38($sp)
/* 5C8C 8038C07C E6080004 */  swc1       $f8, 4($s0)
/* 5C90 8038C080 C7AA0038 */  lwc1       $f10, 0x38($sp)
/* 5C94 8038C084 9218005B */  lbu        $t8, 0x5b($s0)
/* 5C98 8038C088 E60A0008 */  swc1       $f10, 8($s0)
/* 5C9C 8038C08C C7B0003C */  lwc1       $f16, 0x3c($sp)
/* 5CA0 8038C090 37190001 */  ori        $t9, $t8, 1
/* 5CA4 8038C094 E610000C */  swc1       $f16, 0xc($s0)
/* 5CA8 8038C098 C7A40038 */  lwc1       $f4, 0x38($sp)
/* 5CAC 8038C09C C6520008 */  lwc1       $f18, 8($s2)
/* 5CB0 8038C0A0 46049181 */  sub.s      $f6, $f18, $f4
/* 5CB4 8038C0A4 E606001C */  swc1       $f6, 0x1c($s0)
/* 5CB8 8038C0A8 C6480128 */  lwc1       $f8, 0x128($s2)
/* 5CBC 8038C0AC A219005B */  sb         $t9, 0x5b($s0)
/* 5CC0 8038C0B0 10000004 */  b          .L8038C0C4
/* 5CC4 8038C0B4 E6080128 */   swc1      $f8, 0x128($s0)
.L8038C0B8:
/* 5CC8 8038C0B8 9208005B */  lbu        $t0, 0x5b($s0)
/* 5CCC 8038C0BC 3109FFFE */  andi       $t1, $t0, 0xfffe
/* 5CD0 8038C0C0 A209005B */  sb         $t1, 0x5b($s0)
.L8038C0C4:
/* 5CD4 8038C0C4 8FBF0024 */  lw         $ra, 0x24($sp)
.L8038C0C8:
/* 5CD8 8038C0C8 8FB00018 */  lw         $s0, 0x18($sp)
/* 5CDC 8038C0CC 8FB1001C */  lw         $s1, 0x1c($sp)
/* 5CE0 8038C0D0 8FB20020 */  lw         $s2, 0x20($sp)
/* 5CE4 8038C0D4 03E00008 */  jr         $ra
/* 5CE8 8038C0D8 27BD0068 */   addiu     $sp, $sp, 0x68
glabel func_8038C0DC
/* 5CEC 8038C0DC 3C028039 */  lui        $v0, %hi(D_80392798)
/* 5CF0 8038C0E0 24422798 */  addiu      $v0, $v0, %lo(D_80392798)
/* 5CF4 8038C0E4 C4440000 */  lwc1       $f4, ($v0)
/* 5CF8 8038C0E8 E4840000 */  swc1       $f4, ($a0)
/* 5CFC 8038C0EC C4460004 */  lwc1       $f6, 4($v0)
/* 5D00 8038C0F0 E4860004 */  swc1       $f6, 4($a0)
/* 5D04 8038C0F4 C4480008 */  lwc1       $f8, 8($v0)
/* 5D08 8038C0F8 03E00008 */  jr         $ra
/* 5D0C 8038C0FC E4880008 */   swc1      $f8, 8($a0)
glabel func_8038C100
/* 5D10 8038C100 3C018039 */  lui        $at, %hi(D_803927C5)
/* 5D14 8038C104 03E00008 */  jr         $ra
/* 5D18 8038C108 A02027C5 */   sb        $zero, %lo(D_803927C5)($at)
glabel func_8038C10C
/* 5D1C 8038C10C 27BDFFE8 */  addiu      $sp, $sp, -0x18
/* 5D20 8038C110 AFBF0014 */  sw         $ra, 0x14($sp)
/* 5D24 8038C114 0C0CA656 */  jal        marker_getActor
/* 5D28 8038C118 00000000 */   nop
/* 5D2C 8038C11C 00402025 */  or         $a0, $v0, $zero
/* 5D30 8038C120 0C0E2B22 */  jal        func_8038AC88
/* 5D34 8038C124 24050028 */   addiu     $a1, $zero, 0x28
/* 5D38 8038C128 8FBF0014 */  lw         $ra, 0x14($sp)
/* 5D3C 8038C12C 27BD0018 */  addiu      $sp, $sp, 0x18
/* 5D40 8038C130 03E00008 */  jr         $ra
/* 5D44 8038C134 00000000 */   nop
glabel func_8038C138
/* 5D48 8038C138 240E0001 */  addiu      $t6, $zero, 1
/* 5D4C 8038C13C 3C018039 */  lui        $at, %hi(D_803927C7)
/* 5D50 8038C140 03E00008 */  jr         $ra
/* 5D54 8038C144 A02E27C7 */   sb        $t6, %lo(D_803927C7)($at)
glabel func_8038C148
/* 5D58 8038C148 27BDFFB0 */  addiu      $sp, $sp, -0x50
/* 5D5C 8038C14C AFBF0024 */  sw         $ra, 0x24($sp)
/* 5D60 8038C150 AFB00020 */  sw         $s0, 0x20($sp)
/* 5D64 8038C154 F7B40018 */  sdc1       $f20, 0x18($sp)
/* 5D68 8038C158 0C0C9BBB */  jal        func_80326EEC
/* 5D6C 8038C15C 2404038B */   addiu     $a0, $zero, 0x38b
/* 5D70 8038C160 244E007C */  addiu      $t6, $v0, 0x7c
/* 5D74 8038C164 AFA2004C */  sw         $v0, 0x4c($sp)
/* 5D78 8038C168 0C0E37E8 */  jal        func_8038DFA0
/* 5D7C 8038C16C AFAE0048 */   sw        $t6, 0x48($sp)
/* 5D80 8038C170 0C0E448D */  jal        func_80391234
/* 5D84 8038C174 E7A00034 */   swc1      $f0, 0x34($sp)
/* 5D88 8038C178 C7A40034 */  lwc1       $f4, 0x34($sp)
/* 5D8C 8038C17C 0C0E4490 */  jal        func_80391240
/* 5D90 8038C180 46040500 */   add.s     $f20, $f0, $f4
/* 5D94 8038C184 E7A00040 */  swc1       $f0, 0x40($sp)
/* 5D98 8038C188 24100014 */  addiu      $s0, $zero, 0x14
/* 5D9C 8038C18C 240400FC */  addiu      $a0, $zero, 0xfc
/* 5DA0 8038C190 0C0C8001 */  jal        func_80320004
/* 5DA4 8038C194 24050001 */   addiu     $a1, $zero, 1
/* 5DA8 8038C198 8FAF0048 */  lw         $t7, 0x48($sp)
/* 5DAC 8038C19C 8FA4004C */  lw         $a0, 0x4c($sp)
/* 5DB0 8038C1A0 91F80007 */  lbu        $t8, 7($t7)
/* 5DB4 8038C1A4 13000002 */  beqz       $t8, .L8038C1B0
/* 5DB8 8038C1A8 00000000 */   nop
/* 5DBC 8038C1AC 24100023 */  addiu      $s0, $zero, 0x23
.L8038C1B0:
/* 5DC0 8038C1B0 0C0E2B22 */  jal        func_8038AC88
/* 5DC4 8038C1B4 24050027 */   addiu     $a1, $zero, 0x27
/* 5DC8 8038C1B8 8FA80048 */  lw         $t0, 0x48($sp)
/* 5DCC 8038C1BC 24190001 */  addiu      $t9, $zero, 1
/* 5DD0 8038C1C0 44806000 */  mtc1       $zero, $f12
/* 5DD4 8038C1C4 24050001 */  addiu      $a1, $zero, 1
/* 5DD8 8038C1C8 0C0C938E */  jal        func_80324E38
/* 5DDC 8038C1CC A1190008 */   sb        $t9, 8($t0)
/* 5DE0 8038C1D0 44806000 */  mtc1       $zero, $f12
/* 5DE4 8038C1D4 0C0C9398 */  jal        timed_setCameraToNode
/* 5DE8 8038C1D8 02002825 */   or        $a1, $s0, $zero
/* 5DEC 8038C1DC 0C0C93A2 */  jal        func_80324E88
/* 5DF0 8038C1E0 4600A306 */   mov.s     $f12, $f20
/* 5DF4 8038C1E4 3C018039 */  lui        $at, %hi(D_80392470)
/* 5DF8 8038C1E8 D4282470 */  ldc1       $f8, %lo(D_80392470)($at)
/* 5DFC 8038C1EC 4600A1A1 */  cvt.d.s    $f6, $f20
/* 5E00 8038C1F0 3C058039 */  lui        $a1, %hi(func_8038C138)
/* 5E04 8038C1F4 46283282 */  mul.d      $f10, $f6, $f8
/* 5E08 8038C1F8 24A5C138 */  addiu      $a1, $a1, %lo(func_8038C138)
/* 5E0C 8038C1FC 0C0C93AB */  jal        timedFunc_set_0
/* 5E10 8038C200 46205320 */   cvt.s.d   $f12, $f10
/* 5E14 8038C204 4600A306 */  mov.s      $f12, $f20
/* 5E18 8038C208 0C0C9398 */  jal        timed_setCameraToNode
/* 5E1C 8038C20C 26050001 */   addiu     $a1, $s0, 1
/* 5E20 8038C210 C7B00040 */  lwc1       $f16, 0x40($sp)
/* 5E24 8038C214 4610A300 */  add.s      $f12, $f20, $f16
/* 5E28 8038C218 0C0C93A2 */  jal        func_80324E88
/* 5E2C 8038C21C E7AC0030 */   swc1      $f12, 0x30($sp)
/* 5E30 8038C220 C7B40030 */  lwc1       $f20, 0x30($sp)
/* 5E34 8038C224 8FA9004C */  lw         $t1, 0x4c($sp)
/* 5E38 8038C228 3C058039 */  lui        $a1, %hi(func_8038C10C)
/* 5E3C 8038C22C 24A5C10C */  addiu      $a1, $a1, %lo(func_8038C10C)
/* 5E40 8038C230 4600A306 */  mov.s      $f12, $f20
/* 5E44 8038C234 0C0C93B9 */  jal        timedFunc_set_1
/* 5E48 8038C238 8D260000 */   lw        $a2, ($t1)
/* 5E4C 8038C23C 4600A306 */  mov.s      $f12, $f20
/* 5E50 8038C240 0C0C9398 */  jal        timed_setCameraToNode
/* 5E54 8038C244 26050002 */   addiu     $a1, $s0, 2
/* 5E58 8038C248 3C018039 */  lui        $at, %hi(D_80392478)
/* 5E5C 8038C24C C4322478 */  lwc1       $f18, %lo(D_80392478)($at)
/* 5E60 8038C250 4612A300 */  add.s      $f12, $f20, $f18
/* 5E64 8038C254 0C0C93A2 */  jal        func_80324E88
/* 5E68 8038C258 E7AC002C */   swc1      $f12, 0x2c($sp)
/* 5E6C 8038C25C C7AC002C */  lwc1       $f12, 0x2c($sp)
/* 5E70 8038C260 0C0C9398 */  jal        timed_setCameraToNode
/* 5E74 8038C264 26050003 */   addiu     $a1, $s0, 3
/* 5E78 8038C268 8FBF0024 */  lw         $ra, 0x24($sp)
/* 5E7C 8038C26C D7B40018 */  ldc1       $f20, 0x18($sp)
/* 5E80 8038C270 8FB00020 */  lw         $s0, 0x20($sp)
/* 5E84 8038C274 03E00008 */  jr         $ra
/* 5E88 8038C278 27BD0050 */   addiu     $sp, $sp, 0x50
glabel func_8038C27C
/* 5E8C 8038C27C 3C018039 */  lui        $at, %hi(D_803927C4)
/* 5E90 8038C280 03E00008 */  jr         $ra
/* 5E94 8038C284 A02427C4 */   sb        $a0, %lo(D_803927C4)($at)
glabel func_8038C288
/* 5E98 8038C288 3C014040 */  lui        $at, 0x4040
/* 5E9C 8038C28C 44810000 */  mtc1       $at, $f0
/* 5EA0 8038C290 03E00008 */  jr         $ra
/* 5EA4 8038C294 00000000 */   nop
glabel func_8038C298
/* 5EA8 8038C298 3C028039 */  lui        $v0, %hi(D_803927C7)
/* 5EAC 8038C29C 03E00008 */  jr         $ra
/* 5EB0 8038C2A0 904227C7 */   lbu       $v0, %lo(D_803927C7)($v0)
glabel func_8038C2A4
/* 5EB4 8038C2A4 3C028039 */  lui        $v0, %hi(D_803927C8)
/* 5EB8 8038C2A8 03E00008 */  jr         $ra
/* 5EBC 8038C2AC 904227C8 */   lbu       $v0, %lo(D_803927C8)($v0)
glabel func_8038C2B0
/* 5EC0 8038C2B0 3C028039 */  lui        $v0, %hi(D_803927C9)
/* 5EC4 8038C2B4 03E00008 */  jr         $ra
/* 5EC8 8038C2B8 904227C9 */   lbu       $v0, %lo(D_803927C9)($v0)
/* 5ECC 8038C2BC 00000000 */  nop
