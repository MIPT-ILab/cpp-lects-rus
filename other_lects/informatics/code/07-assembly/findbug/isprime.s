	.file	"isprime.c"
	.intel_syntax noprefix
	.text
	.globl	_is_prime
	.def	_is_prime;	.scl	2;	.type	32;	.endef
_is_prime:
	push	ebx
	mov	ebx, DWORD PTR [esp+8]
	mov	eax, 0
	cmp	ebx, 1
	jbe	L1
	mov	ecx, 2
	mov	eax, 1
	cmp	ebx, 3
	jbe	L1
L3:
	add	ecx, 1
	mov	eax, ecx
	imul	eax, ecx
	cmp	eax, ebx
	ja	L10
	mov	eax, ebx
	mov	edx, 0
	div	ecx
	cmp	edx, 0
	jne	L3
	mov	eax, 0
	jmp	L1
L10:
	mov	eax, 1
L1:
	pop	ebx
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "prime\0"
LC1:
	.ascii "composite\0"
LC2:
	.ascii "Number %d is %s\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp
	mov	ebp, esp
	push	edi
	push	esi
	push	ebx
	and	esp, -16
	sub	esp, 16
	call	___main
	mov	ebx, 2
	mov	edi, OFFSET FLAT:LC0
	mov	esi, OFFSET FLAT:LC1
L13:
	mov	DWORD PTR [esp], ebx
	call	_is_prime
	test	eax, eax
	mov	eax, esi
	cmovne	eax, edi
	mov	DWORD PTR [esp+8], eax
	mov	DWORD PTR [esp+4], ebx
	mov	DWORD PTR [esp], OFFSET FLAT:LC2
	call	_printf
	add	ebx, 1
	cmp	ebx, 30
	jne	L13
	mov	eax, 0
	lea	esp, [ebp-12]
	pop	ebx
	pop	esi
	pop	edi
	pop	ebp
	ret
	.ident	"GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
