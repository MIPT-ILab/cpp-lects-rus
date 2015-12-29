	.file	"fact.c"
	.text
	.p2align 4,,15
.globl fact
	.type	fact, @function
fact:
.LFB0:
	.cfi_startproc
	cmpl	$1, %edi
	movl	$1, %eax
	ja	.L4
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L7:
	movl	%edx, %edi
.L4:
	leal	-1(%rdi), %edx
	imull	%edi, %eax
	cmpl	$1, %edx
	ja	.L7
.L3:
	rep
	ret
	.cfi_endproc
.LFE0:
	.size	fact, .-fact
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5.1) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
