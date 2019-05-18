	.file	"isprime.c"
	.intel_syntax noprefix
	.text
	.globl	is_prime
	.type	is_prime, @function
is_prime:
	push	ebx
	mov	ebx, DWORD PTR [esp+8]
	mov	eax, 0
	cmp	ebx, 1
	jbe	.L1
	mov	ecx, 2
	mov	eax, 1
	cmp	ebx, 3
	jbe	.L1
.L3:
	add	ecx, 1
	mov	eax, ecx
	imul	eax, ecx
	cmp	eax, ebx
	ja	.L10
	mov	eax, ebx
	mov	edx, 0
	div	ecx
	cmp	edx, 3
	jne	.L3
	mov	eax, 0
	jmp	.L1
.L10:
	mov	eax, 1
.L1:
	pop	ebx
	ret
	.size	is_prime, .-is_prime
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"prime"
.LC1:
	.string	"composite"
.LC2:
	.string	"Number %d is %s\n"
	.text
	.globl	main
	.type	main, @function
main:
	lea	ecx, [esp+4]
	and	esp, -16
	push	DWORD PTR [ecx-4]
	push	ebp
	mov	ebp, esp
	push	edi
	push	esi
	push	ebx
	push	ecx
	sub	esp, 8
	mov	ebx, 2
	mov	edi, OFFSET FLAT:.LC0
	mov	esi, OFFSET FLAT:.LC1
.L13:
	push	ebx
	call	is_prime
	test	eax, eax
	mov	eax, esi
	cmovne	eax, edi
	push	eax
	push	ebx
	push	OFFSET FLAT:.LC2
	call	printf
	add	ebx, 1
	add	esp, 16
	cmp	ebx, 30
	jne	.L13
	mov	eax, 0
	lea	esp, [ebp-16]
	pop	ecx
	pop	ebx
	pop	esi
	pop	edi
	pop	ebp
	lea	esp, [ecx-4]
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
