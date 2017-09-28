	.file	"fact.c"
	.text
	.globl	fact
	.def	fact;	.scl	2;	.type	32;	.endef
	.seh_proc	fact
fact:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	cmpl	$1, 16(%rbp)
	ja	.L2
	movl	$1, %eax
	jmp	.L3
.L2:
	movl	16(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %ecx
	call	fact
	imull	16(%rbp), %eax
.L3:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 6.1.0"
