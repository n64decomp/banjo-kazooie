.set noat
.set noreorder
.set gp=64
.macro glabel label
    .global \label
    \label:
.endm

.macro dlabel label
    .global \label
    \label:
.endm

.macro jlabel label
    \label:
.endm

.macro endlabel label
.endm