	.file	"fib.c"
	.intel_syntax noprefix
	.text
	.globl	fib
	.type	fib, @function
fib:
	push	esi
	push	ebx
	mov	esi, DWORD PTR [esp+12]
	mov	eax, esi
	test	esi, esi
	je	.L1
	cmp	esi, 1
	jbe	.L5
	add	esi, 1
	mov	ecx, 2
	mov	ebx, 1
	mov	edx, 0
.L3:
	lea	eax, [edx+ebx]
	cmp	ecx, 5
	setg	dl
	movzx	edx, dl
	add	edx, ebx
	add	ecx, 1
	mov	ebx, eax
	cmp	ecx, esi
	jne	.L3
.L1:
	pop	ebx
	pop	esi
	ret
.L5:
	mov	eax, 1
	jmp	.L1
	.size	fib, .-fib
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Fibonacci number %d is %d\n"
	.text
	.globl	main
	.type	main, @function
main:
	lea	ecx, [esp+4]
	and	esp, -16
	push	DWORD PTR [ecx-4]
	push	ebp
	mov	ebp, esp
	push	ebx
	push	ecx
	mov	ebx, 2
.L9:
	push	ebx
	call	fib
	push	eax
	push	ebx
	push	OFFSET FLAT:.LC0
	call	printf
	add	ebx, 1
	add	esp, 16
	cmp	ebx, 20
	jne	.L9
	mov	eax, 0
	lea	esp, [ebp-8]
	pop	ecx
	pop	ebx
	pop	ebp
	lea	esp, [ecx-4]
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
