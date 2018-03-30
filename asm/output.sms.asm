; Source code created by SMS Examine V1.2a
; Size: 131072 bytes

.MEMORYMAP
SLOTSIZE $4000
SLOT 0 $0000
SLOT 1 $4000
SLOT 2 $8000
DEFAULTSLOT 2
.ENDME

.ROMBANKMAP
BANKSTOTAL 8
BANKSIZE $4000
BANKS 8
.ENDRO

; SDSC Tag:
; Name:        Simpsons Trivia
; Author:      StevePro Studios
; Date:        27.03.2018
; Version:     1.00
; Description: Simpsons Trivia game for the SMS Power! 2018 Competition

.BANK 0 SLOT 0
.ORG $0000

_START:
	di
	im   1
	jp   _LABEL_70_2


; Data from 6 to 7 (2 bytes)
; (only NULL-bytes)
.db $00, $00

_LABEL_8_8:
	ld   c, $BF
	di
	out  (c), l
	out  (c), h
	ei
	ret


; Data from 11 to 37 (39 bytes)
.db $00, $00, $00, $00, $00, $00, $00, "}", $D3, $BE, "|", $D6, $00, $00, $D3, $BE, $C9
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00

_IRQ_HANDLER:
	jp   _LABEL_4ECF_10


; Data from 3B to 65 (43 bytes)
; (only NULL-bytes)
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00

_NMI_HANDLER:
	jp   _LABEL_4F05_61


; Data from 69 to 6F (7 bytes)
; (only NULL-bytes)
.db $00, $00, $00, $00, $00, $00, $00

_LABEL_70_2:
	ld   sp, $DFF0
	ld   de, $FFFC
	xor  a
	ld   (de), a
	ld   b, $03
_LABEL_7A_3:
	inc  de
	ld   (de), a
	inc  a
	djnz _LABEL_7A_3
	xor  a
	ld   hl, $C000
	ld   (hl), a
	ld   de, $C001
	ld   bc, $1FF0
	ldir
	call _LABEL_6054_4
	call _LABEL_4C3F_6
	ei
	call _LABEL_1FBC_25

; Data from 96 to 2AE (537 bytes)
.db $C3, $04, $02, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED, $A3, $ED
.db $A3, $ED, $A3, $C9, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $00
.db $00, $00, $00, $00, $00, $00, $00, $00, $00, $00, $3E, $02, $CF, $C9, $3E, $00
.db $CF, $76, $18, $FD, $3A, $4F, $00, $32, $30, $C1, $3A, $50, $00, $32, $31, $C1
.db $3A, $51, $00, $32, $32, $C1, $3A, $52, $00, $32, $33, $C1, $3A, $53, $00, $32
.db $34, $C1, $3A, $54, $00, $32, $35, $C1, $C9, $FD, $21, $33, $C1, $FD, $7E, $00
.db $D6, $01, $3E, $00, $17, $FD, $77, $00, $FD, $21, $34, $C1, $FD, $7E, $00, $D6
.db $01, $3E, $00, $17, $FD, $77, $00, $FD, $21, $35, $C1, $FD, $7E, $00, $D6, $01
.db $3E, $00, $17, $FD, $77, $00, $C9, $21, $FF, $FF, $36, $06, $21, $70, $00, $E5
.db $21, $95, $9F, $E5, $CD, $D4, $51, $F1, $26, $20, $E3, $33, $21, $4E, $9F, $E5
.db $21, $00, $00, $E5, $CD, $F2, $4F, $F1, $F1, $33, $21, $3E, $9F, $C3, $75, $4D
.db $21, $FF, $FF, $36, $06, $21, $60, $00, $E5, $21, $D7, $80, $E5, $CD, $D4, $51
.db $F1, $26, $20, $E3, $33, $21, $10, $80, $E5, $21, $00, $00, $E5, $CD, $F2, $4F
.db $F1, $F1, $33, $21, $00, $80, $C3, $75, $4D

_LABEL_2AF_37:
	ld   hl, $0000
	push hl
	ld   hl, $2745
	push hl
	call _LABEL_51D4_38
	pop  af
	pop  af
	ld   hl, $26B5
	jp   _LABEL_4D75_57

_LABEL_2C2_59:
	ld   hl, $0040
	push hl
	ld   hl, $2AA6
	push hl
	call _LABEL_51D4_38
	pop  af
	ld   hl, $0050
	ex   (sp), hl
	ld   hl, $29EC
	push hl
	call _LABEL_51D4_38

; Data from 2D9 to 12F5 (4125 bytes)
.incbin "output.sms.dat.0"

_LABEL_12F6_27:
	ld   a, $00
	out  ($BF), a
	ld   a, $40
	out  ($BF), a
	ld   bc, $4000
_LABEL_1301_28:
	ld   a, $00
	out  ($BE), a
	dec  bc
	ld   a, b
	or   c
	jp   nz, _LABEL_1301_28
	ret


; Data from 130C to 1FBB (3248 bytes)
.incbin "output.sms.dat.4"

_LABEL_1FBC_25:
	call _LABEL_4C3F_6
	ld   hl, $0140
	call _LABEL_4CBD_26
	call _LABEL_12F6_27
	ld   l, $00
	call _LABEL_4D08_29
	ld   l, $01
	call _LABEL_4CF4_34
	call _LABEL_2AF_37
	call _LABEL_2C2_59

; Data from 1FD8 to 3FFF (8232 bytes)
.incbin "output.sms.dat.7"


.BANK 1 SLOT 1
.ORG $0000


; Data from 4000 to 4C3E (3135 bytes)
.incbin "output.sms.dat.10"

_LABEL_4C3F_6:
	ld   hl, $0000
	push hl
	call _LABEL_4D61_7
	pop  af
	ld   c, $00
_LABEL_4C49_14:
	ld   hl, $4C93
	ld   b, $00
	add  hl, bc
	ld   b, (hl)
	di
	ld   a, b
	out  ($BF), a
	ld   a, c
	set  7, a
	out  ($BF), a
	ei
	inc  c
	ld   a, c
	sub  $0B
	jr   c, _LABEL_4C49_14
	call _LABEL_4DA1_15
	call _LABEL_4DFC_16
	call _LABEL_4E0E_17
	call _LABEL_4EA1_20
_LABEL_4C6C_21:
	in   a, ($7E)
	ld   b, a
	ld   a, $80
	sub  b
	jr   c, _LABEL_4C6C_21
_LABEL_4C74_22:
	in   a, ($7E)
	sub  $80
	jr   c, _LABEL_4C74_22
_LABEL_4C7A_23:
	in   a, ($7E)
	ld   c, a
	in   a, ($7E)
	sub  c
	jr   nc, _LABEL_4C7A_23
	ld   a, c
	sub  $E7
	jr   c, _LABEL_4C8D_24
	ld   hl, $C1AC
	ld   (hl), $80
	ret

_LABEL_4C8D_24:
	ld   hl, $C1AC
	ld   (hl), $40
	ret


; Data from 4C93 to 4CA5 (19 bytes)
.db $04, $20, $FF, $FF, $FF, $FF, $FF, $00, $00, $00, $FF, $FD, $21, $AC, $C1, $FD
.db $6E, $00, $C9

_LABEL_4CA6_31:
	ld   c, l
	ld   e, h
	ld   d, $00
	ld   hl, $C2C4
	add  hl, de
	ld   a, (hl)
	or   c
	ld   c, a
	ld   (hl), c
	di
	ld   a, c
	out  ($BF), a
	ld   a, e
	set  7, a
	out  ($BF), a
	ei
	ret

_LABEL_4CBD_26:
	ld   a, l
	ld   e, h
	cpl
	ld   b, a
	ld   d, $00
	ld   hl, $C2C4
	add  hl, de
	ld   a, (hl)
	and  b
	ld   c, a
	ld   (hl), c
	di
	ld   a, c
	out  ($BF), a
	ld   a, e
	set  7, a
	out  ($BF), a
	ei
	ret


; Data from 4CD6 to 4CF3 (30 bytes)
.db $F3, "}", $D3, $BF, ">", $88, $D3, $BF, $FB, $C9, $F3, "}", $D3, $BF, ">", $89, $D3
.db $BF, $FB, $C9, $F3, "}", $D3, $BF, ">", $87, $D3, $BF, $FB, $C9

_LABEL_4CF4_34:
	bit  0, l
	jr   z, _LABEL_4CFC_35
	ld   c, $FB
	jr   _LABEL_4CFE_36

_LABEL_4CFC_35:
	ld   c, $FF
_LABEL_4CFE_36:
	di
	ld   a, c
	out  ($BF), a
	ld   a, $86
	out  ($BF), a
	ei
	ret

_LABEL_4D08_29:
	ld   c, l
	bit  0, c
	jr   z, _LABEL_4D1C_30
	push bc
	ld   hl, $0102
	call _LABEL_4CA6_31
	pop  bc
	ld   hl, $C2C6
	ld   (hl), $10
	jr   _LABEL_4D29_32

_LABEL_4D1C_30:
	push bc
	ld   hl, $0102
	call _LABEL_4CBD_26
	pop  bc
	ld   hl, $C2C6
	ld   (hl), $08
_LABEL_4D29_32:
	bit  1, c
	jr   z, _LABEL_4D41_33
	ld   hl, $0101
	call _LABEL_4CA6_31
	ld   hl, $C2C7
	ld   (hl), $10
	ld   iy, $C2C6
	sla  (iy+0)
	ret

_LABEL_4D41_33:
	ld   hl, $0101
	call _LABEL_4CBD_26
	ld   hl, $C2C7
	ld   (hl), $08
	ret


; Data from 4D4D to 4D60 (20 bytes)
.db $21, $02, $00, $39, $4E, $06, $00, $21, $00, $C0, $09, $CF, $21, $03, $00, $39
.db $7E, $D3, $BE, $C9

_LABEL_4D61_7:
	ld   hl, $0002
	add  hl, sp
	ld   c, (hl)
	ld   b, $00
	ld   hl, $C010
	add  hl, bc
	rst  $8
	ld   hl, $0003
	add  hl, sp
	ld   a, (hl)
	out  ($BE), a
	ret

_LABEL_4D75_57:
	ld   de, $C000
	ld   c, $BF
	di
	out  (c), e
	out  (c), d
	ei
	ld   b, $10
	ld   c, $BE
_LABEL_4D84_58:
	outi
	jr   nz, _LABEL_4D84_58
	ret


; Data from 4D89 to 4DA0 (24 bytes)
.db $11, $10, $C0, $0E, $BF, $F3, $ED, $59, $ED, $51, $FB, $06, $10, $0E, $BE, $ED
.db $A3, $20, $FC, $C9, $7D, $D3, $BE, $C9

_LABEL_4DA1_15:
	ld   hl, $C271
	ld   (hl), $00
	ret


; Data from 4DA7 to 4DFB (85 bytes)
.db $3A, $71, $C2, $D6, $40, $30, $4B, $FD, $21, $03, $00, $FD, $39, $FD, $7E, $00
.db $D6, $D1, $28, $3E, $3E, $B1, $21, $71, $C2, $86, $4F, $3E, $C1, $CE, $00, $47
.db $FD, $5E, $00, $1D, $7B, $02, $3A, $71, $C2, $87, $4F, $21, $F1, $C1, $06, $00
.db $09, $FD, $21, $02, $00, $FD, $39, $FD, $7E, $00, $77, $23, $FD, $21, $04, $00
.db $FD, $39, $FD, $7E, $00, $77, $FD, $21, $71, $C2, $FD, $4E, $00, $FD, $34, $00
.db $69, $C9, $2E, $FF, $C9

_LABEL_4DFC_16:
	ld   a, ($C271)
	sub  $40
	ret  nc

	ld   bc, $C1B1
	ld   hl, ($C271)
	ld   h, $00
	add  hl, bc
	ld   (hl), $D0
	ret

_LABEL_4E0E_17:
	ld   hl, $7F00
	rst  $8
	ld   bc, $C1B1
	ld   e, $40
_LABEL_4E17_18:
	ld   a, (bc)
	out  ($BE), a
	inc  bc
	ld   d, e
	dec  d
	ld   a, d
	ld   e, a
	or   a
	jr   nz, _LABEL_4E17_18
	ld   hl, $7F80
	rst  $8
	ld   bc, $C1F1
	ld   e, $80
_LABEL_4E2B_19:
	ld   a, (bc)
	out  ($BE), a
	inc  bc
	ld   d, e
	dec  d
	ld   a, d
	ld   e, a
	or   a
	jr   nz, _LABEL_4E2B_19
	ret


; Data from 4E37 to 4EA0 (106 bytes)
.db $21, $A9, $C1, $36, $00, $21, $A9, $C1, $CB, $46, $28, $F9, $C9, $2A, $AD, $C1
.db $C9, $FD, $21, $AF, $C1, $FD, $7E, $00, $2F, $4F, $FD, $7E, $01, $2F, $47, $FD
.db $21, $AD, $C1, $FD, $7E, $00, $A1, $6F, $FD, $7E, $01, $A0, $67, $C9, $3A, $AD
.db $C1, $FD, $21, $AF, $C1, $FD, $A6, $00, $6F, $3A, $AE, $C1, $FD, $21, $AF, $C1
.db $FD, $A6, $01, $67, $C9, $FD, $21, $AD, $C1, $FD, $7E, $00, $2F, $4F, $FD, $7E
.db $01, $2F, $47, $79, $FD, $21, $AF, $C1, $FD, $A6, $00, $6F, $78, $FD, $A6, $01
.db $67, $C9, $FD, $21, $AB, $C1, $FD, $6E, $00, $C9

_LABEL_4EA1_20:
	ld   hl, $C1AB
	ld   (hl), $00
	ret


; Data from 4EA7 to 4ECE (40 bytes)
.db $21, $02, $00, $39, $7E, $32, $72, $C2, $21, $03, $00, $39, $7E, $32, $73, $C2
.db $C9, $21, $02, $00, $39, $4E, $F3, $79, $D3, $BF, $3E, $8A, $D3, $BF, $FB, $C9
.db $DB, $7E, $6F, $C9, $DB, $7F, $6F, $C9

_LABEL_4ECF_10:
	push af
	push hl
	in   a, ($BF)
	ld   ($C1AA), a
	rlca
	jr   nc, _LABEL_4EF2_11
	ld   hl, $C1A9
	ld   (hl), $01
	ld   hl, ($C1AD)
	ld   ($C1AF), hl
	in   a, ($DC)
	cpl
	ld   hl, $C1AD
	ld   (hl), a
	in   a, ($DD)
	cpl
	inc  hl
	ld   (hl), a
	jr   _LABEL_4F00_12

_LABEL_4EF2_11:
	push bc
	push de
	push iy
	ld   hl, ($C272)
	call _LABEL_51D3_13
	pop  iy
	pop  de
	pop  bc
_LABEL_4F00_12:
	pop  hl
	pop  af
	ei
	reti

_LABEL_4F05_61:
	push af
	push bc
	push de
	push hl
	push iy
	ld   hl, $C1AB
	ld   (hl), $01
	pop  iy
	pop  hl
	pop  de
	pop  bc
	pop  af
	retn


; Data from 4F18 to 51D2 (699 bytes)
.db $DD, $E5, $DD, $21, $00, $00, $DD, $39, $F5, $F5, $FD, $21, $C8, $C2, $FD, $5E
.db $00, $FD, $56, $01, $FD, $6E, $02, $FD, $66, $03, $DD, $72, $FC, $DD, $75, $FD
.db $DD, $74, $FE, $DD, $36, $FF, $00, $06, $02, $DD, $CB, $FE, $3E, $DD, $CB, $FD
.db $1E, $DD, $CB, $FC, $1E, $10, $F2, $7B, $DD, $AE, $FC, $4F, $7A, $DD, $AE, $FD
.db $47, $7D, $DD, $AE, $FE, $5F, $7C, $DD, $AE, $FF, $57, $DD, $71, $FD, $DD, $70
.db $FE, $DD, $73, $FF, $DD, $36, $FC, $00, $DD, $CB, $FD, $26, $DD, $CB, $FE, $16
.db $DD, $CB, $FF, $16, $79, $DD, $AE, $FC, $4F, $78, $DD, $AE, $FD, $47, $7B, $DD
.db $AE, $FE, $5F, $7A, $DD, $AE, $FF, $57, $DD, $72, $FC, $DD, $36, $FD, $00, $DD
.db $36, $FE, $00, $DD, $36, $FF, $00, $DD, $CB, $FC, $3E, $DD, $7E, $FC, $A9, $DD
.db $77, $FC, $DD, $7E, $FD, $A8, $DD, $77, $FD, $DD, $7E, $FE, $AB, $DD, $77, $FE
.db $DD, $7E, $FF, $AA, $DD, $77, $FF, $11, $C8, $C2, $21, $00, $00, $39, $01, $04
.db $00, $ED, $B0, $E1, $E5, $CB, $BC, $DD, $F9, $DD, $E1, $C9, $21, $02, $00, $39
.db $4E, $23, $46, $11, $00, $00, $FD, $21, $C8, $C2, $FD, $71, $00, $FD, $70, $01
.db $FD, $73, $02, $7A, $CB, $FF, $FD, $77, $03, $C9, $DD, $E5, $DD, $21, $00, $00
.db $DD, $39, $21, $F0, $FF, $39, $F9, $DD, $36, $FE, $00, $DD, $36, $FF, $00, $DD
.db $36, $F3, $00, $DD, $36, $F4, $00, $DD, $6E, $05, $26, $00, $29, $29, $29, $29
.db $29, $29, $DD, $75, $FC, $7C, $F6, $78, $DD, $77, $FD, $DD, $7E, $04, $DD, $77
.db $FA, $DD, $36, $FB, $00, $DD, $CB, $FA, $26, $DD, $CB, $FB, $16, $DD, $7E, $FC
.db $DD, $B6, $FA, $5F, $DD, $7E, $FD, $DD, $B6, $FB, $57, $DD, $7E, $08, $DD, $77
.db $FA, $DD, $77, $F1, $DD, $36, $F0, $00, $6B, $62, $CF, $DD, $6E, $06, $DD, $66
.db $07, $7E, $DD, $77, $F2, $23, $DD, $75, $06, $DD, $74, $07, $DD, $7E, $06, $DD
.db $77, $FC, $DD, $7E, $07, $DD, $77, $FD, $DD, $7E, $F2, $E6, $02, $DD, $77, $F9
.db $DD, $7E, $F2, $0F, $0F, $E6, $3F, $DD, $77, $F8, $DD, $CB, $F2, $46, $CA, $2B
.db $51, $DD, $36, $F6, $00, $DD, $7E, $FF, $DD, $77, $F7, $DD, $4E, $FC, $DD, $46
.db $FD, $03, $DD, $6E, $FC, $DD, $66, $FD, $6E, $DD, $7E, $F8, $C6, $02, $DD, $77
.db $F5, $26, $00, $7D, $DD, $B6, $F6, $6F, $7C, $DD, $B6, $F7, $67, $DD, $7E, $F9
.db $B7, $28, $3C, $DD, $71, $06, $DD, $70, $07, $4D, $44, $DD, $6E, $F5, $7D, $B7
.db $CA, $A4, $51, $E5, $69, $60, $DF, $E1, $DD, $35, $F1, $DD, $7E, $F1, $B7, $20
.db $15, $7B, $C6, $40, $5F, $7A, $CE, $00, $57, $E5, $C5, $6B, $62, $CF, $C1, $E1
.db $DD, $7E, $FA, $DD, $77, $F1, $3E, $01, $95, $30, $01, $03, $2D, $18, $CF, $DD
.db $71, $06, $DD, $70, $07, $DD, $75, $FE, $DD, $74, $FF, $DD, $46, $F5, $78, $B7
.db $CA, $B4, $51, $DD, $6E, $FE, $DD, $66, $FF, $DF, $DD, $35, $F1, $DD, $7E, $F1
.db $B7, $20, $0D, $21, $40, $00, $19, $5D, $54, $CF, $DD, $7E, $FA, $DD, $77, $F1
.db $05, $18, $DB, $DD, $7E, $F9, $B7, $28, $29, $DD, $CB, $F2, $56, $28, $10, $DD
.db $7E, $FE, $DD, $77, $F3, $DD, $7E, $FF, $DD, $77, $F4, $DD, $36, $F0, $01, $DD
.db $4E, $F2, $CB, $39, $CB, $39, $CB, $39, $DD, $71, $FF, $DD, $36, $FE, $00, $C3
.db $53, $50, $DD, $6E, $F8, $7D, $B7, $28, $6D, $DD, $7E, $FF, $DD, $77, $F6, $DD
.db $36, $F7, $00, $DD, $4E, $FC, $DD, $46, $FD, $DD, $75, $F5, $DD, $7E, $F5, $B7
.db $28, $34, $0A, $D3, $BE, $03, $00, $00, $00, $DD, $7E, $F6, $D3, $BE, $DD, $35
.db $F1, $DD, $7E, $F1, $B7, $20, $10, $21, $40, $00, $19, $EB, $C5, $6B, $62, $CF
.db $C1, $DD, $7E, $FA, $DD, $77, $F1, $DD, $35, $F5, $18, $D0, $DD, $71, $FE, $DD
.db $70, $FF, $18, $08, $18, $06, $DD, $71, $06, $DD, $70, $07, $DD, $CB, $F0, $46
.db $CA, $53, $50, $DD, $7E, $F3, $DD, $77, $FE, $DD, $7E, $F4, $DD, $77, $FF, $DD
.db $36, $F0, $00, $C3, $53, $50, $DD, $F9, $DD, $E1, $C9

_LABEL_51D3_13:
	jp   (hl)

_LABEL_51D4_38:
	ld   iy, $0004
	add  iy, sp
	ld   l, (iy+0)
	ld   h, (iy+1)
	add  hl, hl
	add  hl, hl
	add  hl, hl
	add  hl, hl
	add  hl, hl
	set  6, h
	rst  $8
	pop  bc
	pop  ix
	push ix
	push bc
	ld   c, (ix+0)
	inc  ix
	ld   b, (ix+0)
	inc  ix
_LABEL_51F8_53:
	push bc
	ld   b, $04
	ld   de, $C274
	ld   c, (ix+0)
	inc  ix
_LABEL_5203_50:
	rlc  c
	jr   nc, _LABEL_524A_39
	rlc  c
	jr   c, _LABEL_5246_40
	ld   a, (ix+0)
	inc  ix
	ex   de, hl
	ld   d, a
	and  $03
	add  a, a
	add  a, a
	add  a, a
	ld   e, a
	ld   a, d
	ld   d, $00
	ld   iy, $C274
	add  iy, de
	ex   de, hl
	cp   $03
	jr   c, _LABEL_5264_41
	cp   $10
	jr   c, _LABEL_523E_42
	cp   $13
	jr   c, _LABEL_5269_43
	cp   $20
	jr   c, _LABEL_523E_42
	cp   $23
	jr   c, _LABEL_526E_44
	cp   $40
	jr   c, _LABEL_523E_42
	cp   $43
	jr   c, _LABEL_5277_45
_LABEL_523E_42:
	ld   h, a
	ld   l, (ix+0)
	inc  ix
	jr   _LABEL_5250_46

_LABEL_5246_40:
	ld   h, $00
	jr   _LABEL_5250_46

_LABEL_524A_39:
	rlc  c
	sbc  a, a
	ld   l, a
	ld   h, $FF
_LABEL_5250_46:
	push bc
	ld   b, $08
_LABEL_5253_48:
	ld   a, l
	rlc  h
	jr   c, _LABEL_525D_47
	ld   a, (ix+0)
	inc  ix
_LABEL_525D_47:
	ld   (de), a
	inc  de
	djnz _LABEL_5253_48
	pop  bc
	jr   _LABEL_5295_49

_LABEL_5264_41:
	ld   hl, $FF00
	jr   _LABEL_527E_56

_LABEL_5269_43:
	ld   hl, $FFFF
	jr   _LABEL_527E_56

_LABEL_526E_44:
	ld   h, (ix+0)
	ld   l, $00
	inc  ix
	jr   _LABEL_527E_56

_LABEL_5277_45:
	ld   h, (ix+0)
	ld   l, $FF
	inc  ix
_LABEL_527E_56:
	push bc
	ld   b, $08
_LABEL_5281_55:
	ld   a, (iy+0)
	inc  iy
	xor  l
	rlc  h
	jr   c, _LABEL_5290_54
	ld   a, (ix+0)
	inc  ix
_LABEL_5290_54:
	ld   (de), a
	inc  de
	djnz _LABEL_5281_55
	pop  bc
_LABEL_5295_49:
	dec  b
	jp   nz, _LABEL_5203_50
	ld   de, $0008
	ld   c, e
	ld   hl, $C274
_LABEL_52A0_52:
	ld   b, $04
	push hl
_LABEL_52A3_51:
	ld   a, (hl)
	out  ($BE), a
	add  hl, de
	djnz _LABEL_52A3_51
	pop  hl
	inc  hl
	dec  c
	jr   nz, _LABEL_52A0_52
	pop  bc
	dec  bc
	ld   a, b
	or   c
	jp   nz, _LABEL_51F8_53
	ret


; Data from 52B6 to 6053 (3486 bytes)
.incbin "output.sms.dat.14"

_LABEL_6054_4:
	ld   bc, $0038
	ld   a, b
	or   c
	jr   z, _LABEL_6063_5
	ld   de, $C294
	ld   hl, $601C
	ldir
_LABEL_6063_5:
	ld   hl, $0000
	ld   ($C184), hl
	ld   l, $00
	ld   ($C186), hl
	ret


; Data from 606F to 7FFF (8081 bytes)
.incbin "output.sms.dat.18"


.BANK 2 SLOT 2
.ORG $0000


; Data from 8000 to BFFF (16384 bytes)
.incbin "output.sms.dat.20"


.BANK 3
.ORG $0000


; Data from C000 to FFFF (16384 bytes)
.incbin "output.sms.dat.30"


.BANK 4
.ORG $0000


; Data from 10000 to 13FFF (16384 bytes)
.incbin "output.sms.dat.40"


.BANK 5
.ORG $0000


; Data from 14000 to 17FFF (16384 bytes)
.incbin "output.sms.dat.50"


.BANK 6
.ORG $0000


; Data from 18000 to 1BFFF (16384 bytes)
.incbin "output.sms.dat.60"


.BANK 7
.ORG $0000


; Data from 1C000 to 1FFFF (16384 bytes)
.incbin "output.sms.dat.70"

