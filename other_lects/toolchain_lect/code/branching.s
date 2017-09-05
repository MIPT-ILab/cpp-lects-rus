	.file	"branching.c"
	.text
	.p2align 4,,15
	.globl	foo
	.type	foo, @function
foo:
.LFB24:
	.cfi_startproc
.L2:
.L7:
	cmpl	$0, %edi
	jle	.L16
.L3:
	cmpl	$2, %edi
	jg	.L7
	addl	$5, %edi
	cmpl	$-9, %edi
	jge	.L13
.L10:
	addl	$5, %edi
	cmpl	$-9, %edi
	jge	.L13
	cmpl	$2, %edi
	jle	.L10
	cmpl	$0, %edi
	jg	.L3
.L16:
	.p2align 4,,5
	jne	.L17
	movl	$9, %eax
	.p2align 4,,3
	ret
	.p2align 4,,10
	.p2align 3
.L17:
	addl	$5, %edi
	jmp	.L3
.L13:
	leal	7(%rdi), %eax
	ret
	.cfi_endproc
.LFE24:
	.size	foo, .-foo
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB25:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$1, %edi
	call	foo
	movl	$.LC0, %esi
	movl	%eax, %edx
	movl	$1, %edi
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__printf_chk
	.cfi_endproc
.LFE25:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
