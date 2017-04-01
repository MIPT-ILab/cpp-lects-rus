	.file	"07-closures.cc"
	.text
	.align 2
	.def	_ZZZ4mainENKUlT_E_clIiEEDaS_EN7ClosureclEv;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZZZ4mainENKUlT_E_clIiEEDaS_EN7ClosureclEv
_ZZZ4mainENKUlT_E_clIiEEDaS_EN7ClosureclEv:
.LFB19:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.def	_ZZ4mainENKUlT_E_clIiEEDaS_;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZZ4mainENKUlT_E_clIiEEDaS_
_ZZ4mainENKUlT_E_clIiEEDaS_:
.LFB18:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	24(%rbp), %eax
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "07-closures.cc\0"
.LC1:
	.ascii "t() == 42\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB13:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	leaq	-1(%rbp), %rax
	movl	$42, %edx
	movq	%rax, %rcx
	call	_ZZ4mainENKUlT_E_clIiEEDaS_
	movl	%eax, -16(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZZZ4mainENKUlT_E_clIiEEDaS_EN7ClosureclEv
	cmpl	$42, %eax
	je	.L8
	movl	$15, %r8d
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	_assert
.L8:
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 6.1.0"
	.def	_assert;	.scl	2;	.type	32;	.endef
