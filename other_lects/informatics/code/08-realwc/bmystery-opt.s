	.file	"bmystery-opt.c"
	.intel_syntax noprefix
	.text
	.p2align 4,,15
	.globl	_measure
	.def	_measure;	.scl	2;	.type	32;	.endef
_measure:
LFB37:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, 50000
	push	edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	push	esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	xor	esi, esi
	push	ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	sub	esp, 28
	.cfi_def_cfa_offset 48
	call	_clock
	mov	edi, DWORD PTR [esp+52]
	mov	DWORD PTR [esp+12], eax
	mov	eax, DWORD PTR [esp+48]
	lea	ebx, [eax+edi*4]
	xor	edi, edi
	.p2align 4,,10
L2:
	mov	eax, DWORD PTR [esp+52]
	mov	ecx, DWORD PTR [esp+48]
	test	eax, eax
	jle	L5
	.p2align 4,,10
L3:
	mov	edx, DWORD PTR [ecx]
	xor	eax, eax
	cmp	edx, 128
	setg	al
	imul	eax, edx
	cdq
	add	esi, eax
	adc	edi, edx
	add	ecx, 4
	cmp	ebx, ecx
	jne	L3
L5:
	sub	ebp, 1
	jne	L2
	mov	DWORD PTR _gsum, esi
	mov	DWORD PTR _gsum+4, edi
	call	_clock
	sub	eax, DWORD PTR [esp+12]
	add	esp, 28
	.cfi_def_cfa_offset 20
	pop	ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	pop	esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	pop	edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE37:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "not pre-sorting data\0"
LC2:
	.ascii "elapsed time: %lf\12\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB38:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	eax, 128032
	mov	ebp, esp
	.cfi_def_cfa_register 5
	push	edi
	push	esi
	push	ebx
	and	esp, -16
	call	___chkstk_ms
	sub	esp, eax
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	call	___main
	lea	esi, [esp+32]
	lea	ebx, [esp+128032]
	mov	edi, esi
	.p2align 4,,10
L13:
	call	_rand
	add	edi, 4
	cdq
	shr	edx, 24
	add	eax, edx
	movzx	eax, al
	sub	eax, edx
	mov	DWORD PTR [edi-4], eax
	cmp	edi, ebx
	jne	L13
	mov	DWORD PTR [esp], OFFSET FLAT:LC0
	call	_puts
	mov	DWORD PTR [esp], esi
	mov	DWORD PTR [esp+4], 32000
	call	_measure
	mov	DWORD PTR [esp], OFFSET FLAT:LC2
	mov	DWORD PTR [esp+28], eax
	fild	DWORD PTR [esp+28]
	fdiv	DWORD PTR LC1
	fstp	QWORD PTR [esp+4]
	call	_printf
	lea	esp, [ebp-12]
	xor	eax, eax
	pop	ebx
	.cfi_restore 3
	pop	esi
	.cfi_restore 6
	pop	edi
	.cfi_restore 7
	pop	ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE38:
	.comm	_gsum, 8, 3
	.section .rdata,"dr"
	.align 4
LC1:
	.long	1148846080
	.ident	"GCC: (i686-win32-dwarf-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_clock;	.scl	2;	.type	32;	.endef
	.def	_rand;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
