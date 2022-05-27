# Assembly Macros

.set K0BASE, 0x80000000
.set K1BASE, 0xA0000000
.set K2BASE, 0xC0000000

.macro glabel label
    .global \label
    .ent \label
    .balign 4
    \label:
.endm

.macro dlabel label
    .global \label
    \label:
.endm

.macro endlabel label
    .end \label
.endm

.macro .word32 x
    .word \x
.endm
