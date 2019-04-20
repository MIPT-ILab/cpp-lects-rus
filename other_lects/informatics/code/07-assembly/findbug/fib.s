	.file	"fib.c"
	.intel_syntax noprefix
	.text
	.globl	_fib
	.def	_fib;	.scl	2;	.type	32;	.endef
_fib:
	push	esi
	push	ebx
	mov	esi, DWORD PTR [esp+12]
	mov	eax, esi
	test	esi, esi
	je	L1
	cmp	esi, 1
	jbe	L5
	add	esi, 1
	mov	ecx, 2
	mov	ebx, 1
	mov	edx, 0
L3:
	lea	eax, [edx+ebx]
	cmp	ecx, 5
	setg	dl
	movzx	edx, dl
	add	edx, ebx
	add	ecx, 1
	mov	ebx, eax
	cmp	ecx, esi
	jne	L3
L1:
	pop	ebx
	pop	esi
	ret
L5:
	mov	eax, 1
	jmp	L1
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Fibonacci number %d is %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	push	ebp
	mov	ebp, esp
	push	ebx
	and	esp, -16
	sub	esp, 16
	call	___main
	mov	ebx, 2
L9:
	mov	DWORD PTR [esp], ebx
	call	_fib
	mov	DWORD PTR [esp+8], eax
	mov	DWORD PTR [esp+4], ebx
	mov	DWORD PTR [esp], OFFSET FLAT:LC0
	call	_printf
	add	ebx, 1
	cmp	ebx, 20
	jne	L9
	mov	eax, 0
	mov	ebx, DWORD PTR [ebp-4]
	leave
	ret
	.ident	"GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
