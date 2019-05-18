	.file	"fib.c"
	.intel_syntax noprefix
	.text
	.globl	fib
	.type	fib, @function
fib:
	mov	eax, edi
	test	edi, edi
	je	.L1
	cmp	edi, 1
	jbe	.L5
	add	edi, 1
	mov	ecx, 2
	mov	esi, 1
	mov	edx, 0
.L3:
	lea	eax, [rdx+rsi]
	cmp	ecx, 5
	setg	dl
	movzx	edx, dl
	add	edx, esi
	add	ecx, 1
	mov	esi, eax
	cmp	ecx, edi
	jne	.L3
	ret
.L5:
	mov	eax, 1
.L1:
	ret
	.size	fib, .-fib
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Fibonacci number %d is %d\n"
	.text
	.globl	main
	.type	main, @function
main:
	push	rbx
	mov	ebx, 2
.L8:
	mov	edi, ebx
	call	fib
	mov	edx, eax
	mov	esi, ebx
	mov	edi, OFFSET FLAT:.LC0
	mov	eax, 0
	call	printf
	add	ebx, 1
	cmp	ebx, 20
	jne	.L8
	mov	eax, 0
	pop	rbx
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
