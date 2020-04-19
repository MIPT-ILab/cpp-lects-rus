	.file	"main.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	subq	$200, %rsp
	.seh_stackalloc	200
	movaps	%xmm6, 32(%rsp)
	.seh_savexmm	%xmm6, 32
	movaps	%xmm7, 48(%rsp)
	.seh_savexmm	%xmm7, 48
	movaps	%xmm8, 64(%rsp)
	.seh_savexmm	%xmm8, 64
	movaps	%xmm9, 80(%rsp)
	.seh_savexmm	%xmm9, 80
	movaps	%xmm10, 96(%rsp)
	.seh_savexmm	%xmm10, 96
	movaps	%xmm11, 112(%rsp)
	.seh_savexmm	%xmm11, 112
	movaps	%xmm12, 128(%rsp)
	.seh_savexmm	%xmm12, 128
	movaps	%xmm13, 144(%rsp)
	.seh_savexmm	%xmm13, 144
	movaps	%xmm14, 160(%rsp)
	.seh_savexmm	%xmm14, 160
	movaps	%xmm15, 176(%rsp)
	.seh_savexmm	%xmm15, 176
	.seh_endprologue
	call	__main
	movl	$5, %edi
	call	fact
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$0, %eax
	movaps	32(%rsp), %xmm6
	movaps	48(%rsp), %xmm7
	movaps	64(%rsp), %xmm8
	movaps	80(%rsp), %xmm9
	movaps	96(%rsp), %xmm10
	movaps	112(%rsp), %xmm11
	movaps	128(%rsp), %xmm12
	movaps	144(%rsp), %xmm13
	movaps	160(%rsp), %xmm14
	movaps	176(%rsp), %xmm15
	addq	$200, %rsp
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 9.2.0"
	.def	fact;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
