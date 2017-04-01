	.file	"01-abssort.cc"
	.text
	.p2align 4,,15
	.globl	_Z17abssort_predicateff
	.def	_Z17abssort_predicateff;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z17abssort_predicateff
_Z17abssort_predicateff:
.LFB2179:
	.seh_endprologue
	movss	.LC0(%rip), %xmm2
	andps	%xmm2, %xmm0
	andps	%xmm2, %xmm1
	ucomiss	%xmm0, %xmm1
	seta	%al
	ret
	.seh_endproc
	.p2align 4,,15
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB2668:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.section	.text$_ZSt16__insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt16__insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_
	.def	_ZSt16__insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt16__insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_
_ZSt16__insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_:
.LFB2568:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	movaps	%xmm6, 32(%rsp)
	.seh_savexmm	%xmm6, 32
	.seh_endprologue
	movq	%rcx, %r13
	movq	%rdx, %r14
	movq	%r8, %rbx
	cmpq	%rdx, %rcx
	je	.L3
	leaq	4(%rcx), %rdi
	cmpq	%rdi, %rdx
	je	.L3
	leaq	8(%rcx), %rbp
	movl	$4, %r12d
	.p2align 4,,10
.L11:
	movss	0(%r13), %xmm1
	movss	(%rdi), %xmm0
	movq	%rdi, %r15
	call	*%rbx
	movss	(%rdi), %xmm6
	testb	%al, %al
	je	.L10
	jmp	.L16
	.p2align 4,,10
.L17:
	movss	(%r15), %xmm0
	movss	%xmm0, 4(%r15)
.L10:
	movss	-4(%r15), %xmm1
	movaps	%xmm6, %xmm0
	movq	%r15, %rsi
	subq	$4, %r15
	call	*%rbx
	testb	%al, %al
	jne	.L17
	movss	%xmm6, (%rsi)
	movq	%rbp, %rsi
.L8:
	addq	$4, %rdi
	addq	$4, %rbp
	addq	$4, %r12
	cmpq	%rsi, %r14
	jne	.L11
.L3:
	movaps	32(%rsp), %xmm6
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.p2align 4,,10
.L16:
	movq	%r12, %rax
	movq	%rbp, %rsi
	shrq	$2, %rax
	je	.L7
	movl	$4, %ecx
	movq	%r12, %r8
	movq	%r13, %rdx
	subq	%r12, %rcx
	addq	%rdi, %rcx
	call	memmove
.L7:
	movss	%xmm6, 0(%r13)
	jmp	.L8
	.seh_endproc
	.section	.text$_ZSt22__final_insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt22__final_insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_
	.def	_ZSt22__final_insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt22__final_insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_
_ZSt22__final_insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_:
.LFB2529:
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$48, %rsp
	.seh_stackalloc	48
	movaps	%xmm6, 32(%rsp)
	.seh_savexmm	%xmm6, 32
	.seh_endprologue
	movq	%rdx, %rax
	movq	%rdx, %r12
	movq	%r8, %rdi
	subq	%rcx, %rax
	cmpq	$67, %rax
	jle	.L19
	leaq	64(%rcx), %rbp
	movq	%rbp, %rdx
	call	_ZSt16__insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_
	cmpq	%rbp, %r12
	je	.L18
	.p2align 4,,10
.L26:
	movss	0(%rbp), %xmm6
	movq	%rbp, %rbx
	jmp	.L23
	.p2align 4,,10
.L27:
	movss	(%rbx), %xmm0
	movss	%xmm0, 4(%rbx)
.L23:
	movss	-4(%rbx), %xmm1
	movaps	%xmm6, %xmm0
	movq	%rbx, %rsi
	subq	$4, %rbx
	call	*%rdi
	testb	%al, %al
	jne	.L27
	addq	$4, %rbp
	movss	%xmm6, (%rsi)
	cmpq	%rbp, %r12
	jne	.L26
.L18:
	movaps	32(%rsp), %xmm6
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	ret
.L19:
	movaps	32(%rsp), %xmm6
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	jmp	_ZSt16__insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_
	.seh_endproc
	.section	.text$_ZSt13__adjust_heapIPfxfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_T0_S8_T1_T2_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt13__adjust_heapIPfxfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_T0_S8_T1_T2_
	.def	_ZSt13__adjust_heapIPfxfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_T0_S8_T1_T2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt13__adjust_heapIPfxfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_T0_S8_T1_T2_
_ZSt13__adjust_heapIPfxfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_T0_S8_T1_T2_:
.LFB2654:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	movaps	%xmm6, 32(%rsp)
	.seh_savexmm	%xmm6, 32
	.seh_endprologue
	movq	160(%rsp), %rdi
	leaq	-1(%r8), %rax
	movq	%rcx, %r14
	movq	%rdx, %rbp
	movq	%r8, %r13
	movq	%rax, %r12
	movaps	%xmm3, %xmm6
	shrq	$63, %r12
	addq	%rax, %r12
	sarq	%r12
	cmpq	%r12, %rdx
	jge	.L29
	movq	%rdx, %r15
	.p2align 4,,10
.L31:
	leaq	1(%r15), %rax
	leaq	(%rax,%rax), %rsi
	salq	$3, %rax
	leaq	(%r14,%rax), %rbx
	movss	-4(%r14,%rax), %xmm1
	movss	(%rbx), %xmm0
	call	*%rdi
	testb	%al, %al
	je	.L30
	subq	$1, %rsi
	leaq	(%r14,%rsi,4), %rbx
.L30:
	movss	(%rbx), %xmm0
	movss	%xmm0, (%r14,%r15,4)
	movq	%rsi, %r15
	cmpq	%r12, %rsi
	jl	.L31
	testb	$1, %r13b
	jne	.L32
.L37:
	leaq	-2(%r13), %rax
	movq	%rax, %r13
	shrq	$63, %r13
	addq	%rax, %r13
	sarq	%r13
	cmpq	%rsi, %r13
	je	.L44
.L32:
	cmpq	%rbp, %rsi
	jg	.L45
.L33:
	movss	%xmm6, (%rbx)
	movaps	32(%rsp), %xmm6
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.p2align 4,,10
.L44:
	leaq	2(%rsi,%rsi), %rsi
	movss	-4(%r14,%rsi,4), %xmm0
	subq	$1, %rsi
	movss	%xmm0, (%rbx)
	leaq	(%r14,%rsi,4), %rbx
	cmpq	%rbp, %rsi
	jle	.L33
.L45:
	leaq	-1(%rsi), %rax
	movq	%rax, %r12
	shrq	$63, %r12
	addq	%rax, %r12
	sarq	%r12
	.p2align 4,,10
.L35:
	leaq	(%r14,%r12,4), %rbx
	movaps	%xmm6, %xmm1
	movss	(%rbx), %xmm0
	call	*%rdi
	testb	%al, %al
	jne	.L34
	leaq	(%r14,%rsi,4), %rbx
	jmp	.L33
	.p2align 4,,10
.L34:
	leaq	-1(%r12), %rdx
	movss	(%rbx), %xmm0
	movq	%rdx, %rax
	shrq	$63, %rax
	movss	%xmm0, (%r14,%rsi,4)
	addq	%rdx, %rax
	sarq	%rax
	cmpq	%r12, %rbp
	jge	.L33
	movq	%r12, %rsi
	movq	%rax, %r12
	jmp	.L35
.L29:
	leaq	(%rcx,%rdx,4), %rbx
	movq	%rdx, %rsi
	testb	$1, %r8b
	je	.L37
	jmp	.L33
	.seh_endproc
	.section	.text$_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_T1_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_T1_
	.def	_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_T1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_T1_
_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_T1_:
.LFB2528:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	.seh_endprologue
	movq	%rdx, %rax
	movq	%rcx, %rbx
	movq	%rdx, %r13
	movq	%r8, %r14
	subq	%rcx, %rax
	movq	%r9, %rsi
	cmpq	$67, %rax
	jle	.L46
	testq	%r8, %r8
	je	.L65
	leaq	8(%rcx), %rdx
	movq	%rdx, 56(%rsp)
.L49:
	sarq	$3, %rax
	movss	4(%rbx), %xmm0
	subq	$1, %r14
	leaq	(%rbx,%rax,4), %rdi
	movss	(%rdi), %xmm1
	call	*%rsi
	movss	-4(%r13), %xmm1
	testb	%al, %al
	je	.L53
	movss	(%rdi), %xmm0
	call	*%rsi
	testb	%al, %al
	je	.L54
	movss	(%rbx), %xmm0
.L58:
	movss	(%rdi), %xmm1
	movss	%xmm1, (%rbx)
	movss	%xmm0, (%rdi)
	movss	4(%rbx), %xmm0
	movss	(%rbx), %xmm1
.L55:
	movq	56(%rsp), %rdi
	movq	%r13, %r15
	jmp	.L59
	.p2align 4,,10
.L60:
	movss	(%rbx), %xmm1
	movss	(%rdi), %xmm0
	addq	$4, %rdi
.L59:
	leaq	-4(%rdi), %rbp
	movq	%rbp, %r12
	call	*%rsi
	testb	%al, %al
	jne	.L60
	.p2align 4,,10
.L71:
	subq	$4, %r15
	movss	(%r15), %xmm1
	movss	(%rbx), %xmm0
	call	*%rsi
	testb	%al, %al
	jne	.L71
	cmpq	%rbp, %r15
	jbe	.L72
	movss	-4(%rdi), %xmm0
	movss	(%r15), %xmm1
	movss	%xmm1, -4(%rdi)
	movss	%xmm0, (%r15)
	jmp	.L60
.L72:
	movq	%rsi, %r9
	movq	%r14, %r8
	movq	%r13, %rdx
	movq	%rbp, %rcx
	call	_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_T1_
	movq	%rbp, %rax
	subq	%rbx, %rax
	cmpq	$67, %rax
	jle	.L46
	movq	%rbp, %r13
	testq	%r14, %r14
	jne	.L49
.L48:
	sarq	$2, %rax
	leaq	-2(%rax), %rbp
	movq	%rax, %rdi
	sarq	%rbp
	jmp	.L51
.L73:
	subq	$1, %rbp
.L51:
	movq	%rsi, 32(%rsp)
	movss	(%rbx,%rbp,4), %xmm3
	movq	%rdi, %r8
	movq	%rbp, %rdx
	movq	%rbx, %rcx
	call	_ZSt13__adjust_heapIPfxfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_T0_S8_T1_T2_
	testq	%rbp, %rbp
	jne	.L73
.L52:
	subq	$4, %r12
	movss	(%rbx), %xmm0
	movss	(%r12), %xmm3
	xorl	%edx, %edx
	movq	%r12, %rdi
	movq	%rbx, %rcx
	subq	%rbx, %rdi
	movss	%xmm0, (%r12)
	movq	%rsi, 32(%rsp)
	movq	%rdi, %r8
	sarq	$2, %r8
	call	_ZSt13__adjust_heapIPfxfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_T0_S8_T1_T2_
	cmpq	$7, %rdi
	jg	.L52
.L46:
	addq	$72, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L53:
	movss	4(%rbx), %xmm0
	call	*%rsi
	testb	%al, %al
	je	.L57
	movss	(%rbx), %xmm0
.L70:
	movss	4(%rbx), %xmm1
	movss	%xmm0, 4(%rbx)
	movss	%xmm1, (%rbx)
	jmp	.L55
.L54:
	movss	4(%rbx), %xmm0
	movss	-4(%r13), %xmm1
	call	*%rsi
	movss	(%rbx), %xmm0
	testb	%al, %al
	je	.L70
.L69:
	movss	-4(%r13), %xmm1
	movss	%xmm1, (%rbx)
	movss	%xmm0, -4(%r13)
	movss	4(%rbx), %xmm0
	movss	(%rbx), %xmm1
	jmp	.L55
.L57:
	movss	(%rdi), %xmm0
	movss	-4(%r13), %xmm1
	call	*%rsi
	movss	(%rbx), %xmm0
	testb	%al, %al
	je	.L58
	jmp	.L69
.L65:
	movq	%rdx, %r12
	jmp	.L48
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC5:
	.ascii " \0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2181:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	xorl	%ebx, %ebx
	leaq	.LC5(%rip), %rdi
	call	__main
	leaq	32(%rsp), %rsi
	movl	$4, %r8d
	leaq	_Z17abssort_predicateff(%rip), %r9
	leaq	48(%rsp), %rdx
	movq	%rsi, %rcx
	movl	$0xc0800000, 32(%rsp)
	movl	$0xc0000000, 36(%rsp)
	movl	$0x3f800000, 40(%rsp)
	movl	$0x40400000, 44(%rsp)
	call	_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_T1_
	leaq	_Z17abssort_predicateff(%rip), %r8
	leaq	48(%rsp), %rdx
	movq	%rsi, %rcx
	call	_ZSt22__final_insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_
	movq	.refptr._ZSt4cout(%rip), %rbp
.L75:
	movq	%rbp, %rcx
	pxor	%xmm1, %xmm1
	cvtss2sd	(%rsi,%rbx), %xmm1
	call	_ZNSo9_M_insertIdEERSoT_
	addq	$4, %rbx
	movq	%rdi, %rdx
	movl	$1, %r8d
	movq	%rax, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	cmpq	$16, %rbx
	jne	.L75
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	xorl	%eax, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.text
	.p2align 4,,15
	.globl	_Z7abssortPfj
	.def	_Z7abssortPfj;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7abssortPfj
_Z7abssortPfj:
.LFB2180:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movl	%edx, %eax
	movq	%rcx, %rbx
	salq	$2, %rax
	leaq	(%rcx,%rax), %rsi
	cmpq	%rsi, %rcx
	je	.L77
	sarq	$2, %rax
	movl	$63, %r8d
	movq	%rsi, %rdx
	bsrq	%rax, %rax
	leaq	_Z17abssort_predicateff(%rip), %r9
	xorq	$63, %rax
	cltq
	subq	%rax, %r8
	addq	%r8, %r8
	call	_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_T1_
	leaq	_Z17abssort_predicateff(%rip), %r8
	movq	%rsi, %rdx
	movq	%rbx, %rcx
	call	_ZSt22__final_insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIPFbffEEEEvT_S7_T0_
	nop
.L77:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.section	.text.startup,"x"
	.p2align 4,,15
	.def	_GLOBAL__sub_I__Z17abssort_predicateff;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z17abssort_predicateff
_GLOBAL__sub_I__Z17abssort_predicateff:
.LFB2669:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	addq	$40, %rsp
	jmp	atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__Z17abssort_predicateff
.lcomm _ZStL8__ioinit,1,1
	.section .rdata,"dr"
	.align 16
.LC0:
	.long	2147483647
	.long	0
	.long	0
	.long	0
	.ident	"GCC: (GNU) 6.1.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	_ZNSo9_M_insertIdEERSoT_;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
