.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

glabel func_8025C240
/* F37A70 8025C240 3C048027 */  lui        $a0, %hi(D_80276E70)
/* F37A74 8025C244 DC846E70 */  ld         $a0, %lo(D_80276E70)($a0)
/* F37A78 8025C248 3C018027 */  lui        $at, %hi(D_80276E70)
/* F37A7C 8025C24C 000437FC */  dsll32     $a2, $a0, 31
/* F37A80 8025C250 00042FF8 */  dsll       $a1, $a0, 31
/* F37A84 8025C254 000637FA */  dsrl       $a2, $a2, 31
/* F37A88 8025C258 0005283E */  dsrl32     $a1, $a1, 0
/* F37A8C 8025C25C 0004233C */  dsll32     $a0, $a0, 12
/* F37A90 8025C260 00C53025 */  or         $a2, $a2, $a1
/* F37A94 8025C264 0004203E */  dsrl32     $a0, $a0, 0
/* F37A98 8025C268 00C43026 */  xor        $a2, $a2, $a0
/* F37A9C 8025C26C 0006253A */  dsrl       $a0, $a2, 20
/* F37AA0 8025C270 30840FFF */  andi       $a0, $a0, 0xFFF
/* F37AA4 8025C274 00862026 */  xor        $a0, $a0, $a2
/* F37AA8 8025C278 0004103C */  dsll32     $v0, $a0, 0
/* F37AAC 8025C27C FC246E70 */  sd         $a0, %lo(D_80276E70)($at)
/* F37AB0 8025C280 03E00008 */  jr         $ra
/* F37AB4 8025C284 0002103F */   dsra32    $v0, $v0, 0
endlabel func_8025C240

glabel func_8025C288
/* F37AB8 8025C288 64840001 */  daddiu     $a0, $a0, 0x1
/* F37ABC 8025C28C 3C018027 */  lui        $at, %hi(D_80276E70)
/* F37AC0 8025C290 FC246E70 */  sd         $a0, %lo(D_80276E70)($at)
/* F37AC4 8025C294 03E00008 */  jr         $ra
/* F37AC8 8025C298 24040000 */   addiu     $a0, $zero, 0x0
endlabel func_8025C288

glabel func_8025C29C
/* F37ACC 8025C29C DC870000 */  ld         $a3, 0x0($a0)
/* F37AD0 8025C2A0 000737FC */  dsll32     $a2, $a3, 31
/* F37AD4 8025C2A4 00072FF8 */  dsll       $a1, $a3, 31
/* F37AD8 8025C2A8 000637FA */  dsrl       $a2, $a2, 31
/* F37ADC 8025C2AC 0005283E */  dsrl32     $a1, $a1, 0
/* F37AE0 8025C2B0 00073B3C */  dsll32     $a3, $a3, 12
/* F37AE4 8025C2B4 00C53025 */  or         $a2, $a2, $a1
/* F37AE8 8025C2B8 0007383E */  dsrl32     $a3, $a3, 0
/* F37AEC 8025C2BC 00C73026 */  xor        $a2, $a2, $a3
/* F37AF0 8025C2C0 00063D3A */  dsrl       $a3, $a2, 20
/* F37AF4 8025C2C4 30E70FFF */  andi       $a3, $a3, 0xFFF
/* F37AF8 8025C2C8 00E63826 */  xor        $a3, $a3, $a2
/* F37AFC 8025C2CC 0007103C */  dsll32     $v0, $a3, 0
/* F37B00 8025C2D0 FC870000 */  sd         $a3, 0x0($a0)
/* F37B04 8025C2D4 03E00008 */  jr         $ra
/* F37B08 8025C2D8 0002103F */   dsra32    $v0, $v0, 0
/* F37B0C 8025C2DC 00000000 */  nop
endlabel func_8025C29C
