	.file	"isprime.c"
	.intel_syntax noprefix
	.text
	.globl	is_prime
	.type	is_prime, @function
is_prime:
	mov	eax, 0
	cmp	edi, 1
	jbe	.L1
	mov	ecx, 2
	cmp	edi, 3
	jbe	.L9
.L3:
	add	ecx, 1
	mov	eax, ecx
	imul	eax, ecx
	cmp	eax, edi
	ja	.L10
	mov	eax, edi
	mov	edx, 0
	div	ecx
	cmp	edx, 3
	jne	.L3
	mov	eax, 0
.L1:
	ret
.L9:
	mov	eax, 1
	ret
.L10:
	mov	eax, 1
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
	push	rbp
	push	rbx
	sub	rsp, 8
	mov	ebx, 2
	mov	ebp, OFFSET FLAT:.LC0
.L13:
	mov	edi, ebx
	call	is_prime
	test	eax, eax
	mov	edx, OFFSET FLAT:.LC1
	cmovne	rdx, rbp
	mov	esi, ebx
	mov	edi, OFFSET FLAT:.LC2
	mov	eax, 0
	call	printf
	add	ebx, 1
	cmp	ebx, 30
	jne	.L13
	mov	eax, 0
	add	rsp, 8
	pop	rbx
	pop	rbp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
