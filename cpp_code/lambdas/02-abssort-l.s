	.file	"02-abssort-l.cc"
	.text
	.p2align 4,,15
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB2670:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.p2align 4,,15
	.def	_ZSt13__adjust_heapIPfxfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_T0_S7_T1_T2_.isra.12;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt13__adjust_heapIPfxfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_T0_S7_T1_T2_.isra.12
_ZSt13__adjust_heapIPfxfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_T0_S7_T1_T2_.isra.12:
.LFB2684:
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	leaq	-1(%r8), %rax
	movq	%rax, %rbx
	shrq	$63, %rbx
	addq	%rax, %rbx
	sarq	%rbx
	cmpq	%rbx, %rdx
	jge	.L3
	movss	.LC0(%rip), %xmm2
	movq	%rdx, %r11
	.p2align 4,,10
.L6:
	leaq	1(%r11), %r9
	leaq	(%r9,%r9), %rax
	salq	$3, %r9
	leaq	(%rcx,%r9), %r10
	movss	-4(%rcx,%r9), %xmm0
	movss	(%r10), %xmm1
	andps	%xmm2, %xmm0
	movaps	%xmm1, %xmm4
	andps	%xmm2, %xmm4
	ucomiss	%xmm4, %xmm0
	jbe	.L4
	subq	$1, %rax
	leaq	(%rcx,%rax,4), %r10
	movss	(%r10), %xmm1
.L4:
	movss	%xmm1, (%rcx,%r11,4)
	movq	%rax, %r11
	cmpq	%rbx, %rax
	jl	.L6
	testb	$1, %r8b
	jne	.L7
.L13:
	leaq	-2(%r8), %r9
	movq	%r9, %r8
	shrq	$63, %r8
	addq	%r9, %r8
	sarq	%r8
	cmpq	%rax, %r8
	je	.L19
.L7:
	cmpq	%rdx, %rax
	jle	.L8
	movss	.LC0(%rip), %xmm2
	leaq	-1(%rax), %r9
	movaps	%xmm3, %xmm4
	movq	%r9, %r8
	andps	%xmm2, %xmm4
	shrq	$63, %r8
	addq	%r9, %r8
	sarq	%r8
	movss	(%rcx,%r8,4), %xmm0
	movaps	%xmm0, %xmm1
	andps	%xmm2, %xmm1
	ucomiss	%xmm1, %xmm4
	jbe	.L8
	leaq	(%rcx,%r8,4), %r10
	movss	%xmm0, (%rcx,%rax,4)
	cmpq	%r8, %rdx
	jge	.L8
.L11:
	leaq	-1(%r8), %rax
	movq	%rax, %r9
	shrq	$63, %r9
	addq	%rax, %r9
	sarq	%r9
	movss	(%rcx,%r9,4), %xmm0
	movaps	%xmm0, %xmm1
	andps	%xmm2, %xmm1
	ucomiss	%xmm1, %xmm4
	jbe	.L8
	movq	%r8, %rax
	movq	%r9, %r8
	leaq	(%rcx,%r8,4), %r10
	movss	%xmm0, (%rcx,%rax,4)
	cmpq	%r8, %rdx
	jl	.L11
.L8:
	movss	%xmm3, (%r10)
	popq	%rbx
	ret
	.p2align 4,,10
.L19:
	leaq	2(%rax,%rax), %rax
	movss	-4(%rcx,%rax,4), %xmm0
	subq	$1, %rax
	movss	%xmm0, (%r10)
	leaq	(%rcx,%rax,4), %r10
	jmp	.L7
.L3:
	leaq	(%rcx,%rdx,4), %r10
	movq	%rdx, %rax
	testb	$1, %r8b
	je	.L13
	jmp	.L8
	.seh_endproc
	.p2align 4,,15
	.def	_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_T1_;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_T1_
_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_T1_:
.LFB2530:
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
	movq	%rdx, %rax
	movq	%rcx, %r12
	movq	%r8, %r13
	movl	%r9d, %edi
	subq	%rcx, %rax
	cmpq	$67, %rax
	jle	.L20
	testq	%r8, %r8
	je	.L45
	movss	.LC0(%rip), %xmm6
	leaq	8(%rcx), %rsi
.L23:
	sarq	$3, %rax
	movss	4(%r12), %xmm4
	subq	$1, %r13
	movss	-4(%rdx), %xmm5
	leaq	(%r12,%rax,4), %rax
	movss	(%rax), %xmm2
	movaps	%xmm4, %xmm1
	movaps	%xmm5, %xmm3
	andps	%xmm6, %xmm1
	andps	%xmm6, %xmm3
	movaps	%xmm2, %xmm0
	andps	%xmm6, %xmm0
	ucomiss	%xmm1, %xmm0
	jbe	.L56
	ucomiss	%xmm0, %xmm3
	ja	.L60
	ucomiss	%xmm1, %xmm3
	jbe	.L62
.L63:
	movss	(%r12), %xmm0
	movss	%xmm5, (%r12)
	movss	%xmm0, -4(%rdx)
	movss	4(%r12), %xmm3
	movss	(%r12), %xmm4
.L31:
	movq	%rsi, %rcx
	movq	%rdx, %rax
	.p2align 4,,10
.L34:
	movaps	%xmm4, %xmm2
	movaps	%xmm3, %xmm1
	leaq	-4(%rcx), %rbx
	andps	%xmm6, %xmm2
	andps	%xmm6, %xmm1
	movq	%rbx, %rbp
	ucomiss	%xmm1, %xmm2
	ja	.L39
	movaps	%xmm0, %xmm1
	subq	$4, %rax
	andps	%xmm6, %xmm1
	ucomiss	%xmm2, %xmm1
	jbe	.L40
	.p2align 4,,10
.L52:
	subq	$4, %rax
	movss	(%rax), %xmm0
	movaps	%xmm0, %xmm1
	andps	%xmm6, %xmm1
	ucomiss	%xmm2, %xmm1
	ja	.L52
.L40:
	cmpq	%rax, %rbx
	jnb	.L64
	movss	%xmm0, -4(%rcx)
	movss	-4(%rax), %xmm0
	movss	%xmm3, (%rax)
	movss	(%r12), %xmm4
.L39:
	movss	(%rcx), %xmm3
	addq	$4, %rcx
	jmp	.L34
.L64:
	movl	%edi, %r9d
	movq	%r13, %r8
	movq	%rbx, %rcx
	call	_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_T1_
	movq	%rbx, %rax
	subq	%r12, %rax
	cmpq	$67, %rax
	jle	.L20
	movq	%rbx, %rdx
	testq	%r13, %r13
	jne	.L23
.L22:
	sarq	$2, %rax
	leaq	-2(%rax), %rsi
	movq	%rax, %rbx
	sarq	%rsi
	jmp	.L25
.L65:
	subq	$1, %rsi
.L25:
	movss	(%r12,%rsi,4), %xmm3
	movq	%rbx, %r8
	movq	%rsi, %rdx
	movq	%r12, %rcx
	call	_ZSt13__adjust_heapIPfxfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_T0_S7_T1_T2_.isra.12
	testq	%rsi, %rsi
	jne	.L65
.L26:
	subq	$4, %rbp
	movss	(%r12), %xmm0
	xorl	%edx, %edx
	movq	%r12, %rcx
	movq	%rbp, %rbx
	movss	0(%rbp), %xmm3
	subq	%r12, %rbx
	movss	%xmm0, 0(%rbp)
	movq	%rbx, %r8
	sarq	$2, %r8
	call	_ZSt13__adjust_heapIPfxfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_T0_S7_T1_T2_.isra.12
	cmpq	$7, %rbx
	jg	.L26
.L20:
	movaps	32(%rsp), %xmm6
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
.L56:
	ucomiss	%xmm1, %xmm3
	ja	.L62
	ucomiss	%xmm0, %xmm3
	ja	.L63
.L60:
	movss	(%r12), %xmm0
	movss	%xmm2, (%r12)
	movss	%xmm0, (%rax)
	movss	-4(%rdx), %xmm0
	movss	(%r12), %xmm4
	movss	4(%r12), %xmm3
	jmp	.L31
.L62:
	movss	(%r12), %xmm3
	movss	%xmm4, (%r12)
	movss	%xmm3, 4(%r12)
	movss	-4(%rdx), %xmm0
	jmp	.L31
.L45:
	movq	%rdx, %rbp
	jmp	.L22
	.seh_endproc
	.p2align 4,,15
	.def	_ZSt16__insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_.isra.23;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt16__insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_.isra.23
_ZSt16__insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_.isra.23:
.LFB2695:
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
	movaps	%xmm6, 32(%rsp)
	.seh_savexmm	%xmm6, 32
	movaps	%xmm7, 48(%rsp)
	.seh_savexmm	%xmm7, 48
	.seh_endprologue
	movq	%rcx, %r12
	movq	%rdx, %r13
	cmpq	%rdx, %rcx
	je	.L66
	leaq	4(%rcx), %rax
	cmpq	%rax, %rdx
	je	.L66
	leaq	8(%rcx), %rbx
	movl	$4, %esi
	movl	$4, %edi
	movss	.LC0(%rip), %xmm6
	.p2align 4,,10
.L76:
	movss	-4(%rbx), %xmm7
	movss	(%r12), %xmm0
	leaq	-4(%rbx), %rdx
	movq	%rbx, %rbp
	movaps	%xmm7, %xmm2
	andps	%xmm6, %xmm0
	andps	%xmm6, %xmm2
	ucomiss	%xmm2, %xmm0
	ja	.L88
	movss	-8(%rbx), %xmm0
	leaq	-8(%rbx), %rax
	movaps	%xmm0, %xmm1
	andps	%xmm6, %xmm1
	ucomiss	%xmm2, %xmm1
	ja	.L83
	jmp	.L89
	.p2align 4,,10
.L78:
	movq	%rdx, %rax
.L83:
	movss	%xmm0, 4(%rax)
	movss	-4(%rax), %xmm0
	leaq	-4(%rax), %rdx
	movaps	%xmm0, %xmm1
	andps	%xmm6, %xmm1
	ucomiss	%xmm2, %xmm1
	ja	.L78
.L73:
	movss	%xmm7, (%rax)
.L72:
	addq	$4, %rbx
	addq	$4, %rsi
	cmpq	%rbp, %r13
	jne	.L76
.L66:
	movaps	32(%rsp), %xmm6
	movaps	48(%rsp), %xmm7
	addq	$72, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
	.p2align 4,,10
.L88:
	movq	%rsi, %rax
	shrq	$2, %rax
	je	.L71
	movq	%rdi, %rcx
	movq	%rsi, %r8
	subq	%rsi, %rcx
	addq	%rdx, %rcx
	movq	%r12, %rdx
	call	memmove
.L71:
	movss	%xmm7, (%r12)
	jmp	.L72
.L89:
	movq	%rdx, %rax
	jmp	.L73
	.seh_endproc
	.p2align 4,,15
	.def	_ZSt22__final_insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_.isra.24;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt22__final_insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_.isra.24
_ZSt22__final_insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_.isra.24:
.LFB2696:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movq	%rdx, %rax
	movq	%rdx, %rsi
	subq	%rcx, %rax
	cmpq	$67, %rax
	jle	.L91
	leaq	64(%rcx), %rbx
	movq	%rbx, %rdx
	call	_ZSt16__insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_.isra.23
	movss	.LC0(%rip), %xmm2
	cmpq	%rbx, %rsi
	je	.L90
	.p2align 4,,10
.L102:
	movss	(%rbx), %xmm4
	movss	-4(%rbx), %xmm0
	leaq	-4(%rbx), %rax
	movaps	%xmm4, %xmm3
	movaps	%xmm0, %xmm1
	andps	%xmm2, %xmm3
	andps	%xmm2, %xmm1
	ucomiss	%xmm3, %xmm1
	ja	.L103
	jmp	.L106
	.p2align 4,,10
.L100:
	movq	%rdx, %rax
.L103:
	movss	%xmm0, 4(%rax)
	movss	-4(%rax), %xmm0
	leaq	-4(%rax), %rdx
	movaps	%xmm0, %xmm1
	andps	%xmm2, %xmm1
	ucomiss	%xmm3, %xmm1
	ja	.L100
	addq	$4, %rbx
	movss	%xmm4, (%rax)
	cmpq	%rbx, %rsi
	jne	.L102
.L90:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
.L91:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	jmp	_ZSt16__insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_.isra.23
.L106:
	movq	%rbx, %rax
	addq	$4, %rbx
	movss	%xmm4, (%rax)
	cmpq	%rbx, %rsi
	jne	.L102
	jmp	.L90
	.seh_endproc
	.p2align 4,,15
	.globl	_Z7abssortPfj
	.def	_Z7abssortPfj;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7abssortPfj
_Z7abssortPfj:
.LFB2179:
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
	je	.L107
	sarq	$2, %rax
	movl	$63, %r8d
	movq	%rsi, %rdx
	xorl	%r9d, %r9d
	bsrq	%rax, %rax
	xorq	$63, %rax
	cltq
	subq	%rax, %r8
	addq	%r8, %r8
	call	_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_T1_
	movq	%rsi, %rdx
	movq	%rbx, %rcx
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	jmp	_ZSt22__final_insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_.isra.24
	.p2align 4,,10
.L107:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
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
.LFB2183:
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
	xorl	%r9d, %r9d
	movl	$4, %r8d
	leaq	48(%rsp), %rdx
	movq	%rsi, %rcx
	movl	$0xc0800000, 32(%rsp)
	movl	$0xc0000000, 36(%rsp)
	movl	$0x3f800000, 40(%rsp)
	movl	$0x40400000, 44(%rsp)
	call	_ZSt16__introsort_loopIPfxN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_T1_
	leaq	48(%rsp), %rdx
	movq	%rsi, %rcx
	call	_ZSt22__final_insertion_sortIPfN9__gnu_cxx5__ops15_Iter_comp_iterIZ7abssortS0_jEUlffE_EEEvT_S6_T0_.isra.24
	movq	.refptr._ZSt4cout(%rip), %rbp
.L110:
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
	jne	.L110
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
	.p2align 4,,15
	.def	_GLOBAL__sub_I__Z7abssortPfj;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z7abssortPfj
_GLOBAL__sub_I__Z7abssortPfj:
.LFB2671:
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
	.quad	_GLOBAL__sub_I__Z7abssortPfj
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
