	.file	"fact.c"
	.text
	.p2align 4
	.globl	fact
	.type	fact, @function
fact:
.LFB0:
	.cfi_startproc
	endbr64
	movl	$1, %eax
	cmpl	$1, %edi
	jle	.L10
	.p2align 4,,10
	.p2align 3
.L2:
	movl	%edi, %edx
	subl	$1, %edi
	imull	%edx, %eax
	cmpl	$1, %edi
	jne	.L2
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	movl	%edi, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	fact, .-fact
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
