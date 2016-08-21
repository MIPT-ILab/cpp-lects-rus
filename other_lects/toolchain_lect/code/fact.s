	.file	"fact.c"
	.text
	.p2align 4,,15
	.globl	fact
	.type	fact, @function
fact:
.LFB0:
	.cfi_startproc
	cmpl	$1, %edi
	movl	$1, %eax
	jbe	.L4
	.p2align 4,,10
	.p2align 3
.L3:
	imull	%edi, %eax
	subl	$1, %edi
	cmpl	$1, %edi
	jne	.L3
	rep ret
.L4:
	rep ret
	.cfi_endproc
.LFE0:
	.size	fact, .-fact
	.ident	"GCC: (GNU) 6.1.0"
	.section	.note.GNU-stack,"",@progbits
