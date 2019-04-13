	.file	"bmystery.c"
	.intel_syntax noprefix
	.text
	.p2align 4,,15
	.globl	_measure
	.def	_measure;	.scl	2;	.type	32;	.endef
_measure:
	push	ebp
	mov	ebp, 50000
	push	edi
	xor	edi, edi
	push	esi
	xor	esi, esi
	push	ebx
	sub	esp, 28
	call	_clock
	mov	ebx, DWORD PTR [esp+52]
	mov	DWORD PTR [esp+12], eax
	mov	eax, DWORD PTR [esp+48]
	lea	edx, [eax+ebx*4]
	.p2align 4,,10
L2:
	mov	ecx, DWORD PTR [esp+52]
	mov	eax, DWORD PTR [esp+48]
	test	ecx, ecx
	jle	L6
	.p2align 4,,10
L4:
	mov	ecx, DWORD PTR [eax]
	cmp	ecx, 128
	jle	L3
	mov	ebx, ecx
	sar	ebx, 31
	add	esi, ecx
	adc	edi, ebx
L3:
	add	eax, 4
	cmp	eax, edx
	jne	L4
L6:
	sub	ebp, 1
	jne	L2
	mov	DWORD PTR _gsum, esi
	mov	DWORD PTR _gsum+4, edi
	call	_clock
	sub	eax, DWORD PTR [esp+12]
	add	esp, 28
	pop	ebx
	pop	esi
	pop	edi
	pop	ebp
	ret
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
	push	ebp
	mov	eax, 128032
	mov	ebp, esp
	push	edi
	push	esi
	push	ebx
	and	esp, -16
	call	___chkstk_ms
	sub	esp, eax
	call	___main
	lea	esi, [esp+32]
	lea	ebx, [esp+128032]
	mov	edi, esi
	.p2align 4,,10
L14:
	call	_rand
	add	edi, 4
	cdq
	shr	edx, 24
	add	eax, edx
	movzx	eax, al
	sub	eax, edx
	mov	DWORD PTR [edi-4], eax
	cmp	edi, ebx
	jne	L14
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
	pop	esi
	pop	edi
	pop	ebp
	ret
	.comm	_gsum, 8, 3
	.section .rdata,"dr"
	.align 4
LC1:
	.long	1148846080
	.ident	"GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_clock;	.scl	2;	.type	32;	.endef
	.def	_rand;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
