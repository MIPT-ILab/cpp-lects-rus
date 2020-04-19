	.file	"fact.c"
	.intel_syntax noprefix
	.text
	.p2align 4
	.globl	fact
	.def	fact;	.scl	2;	.type	32;	.endef
fact:
	mov	eax, 1
	cmp	edi, 1
	jle	.L10
	.p2align 4,,10
	.p2align 3
.L2:
	mov	edx, edi
	dec	edi
	imul	eax, edx
	cmp	edi, 1
	jne	.L2
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	mov	eax, edi
	ret
	.ident	"GCC: (GNU) 9.2.0"
