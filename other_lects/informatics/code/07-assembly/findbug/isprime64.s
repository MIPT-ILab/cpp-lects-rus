	.text
	.intel_syntax noprefix
	.def	 is_prime;
	.scl	2;
	.type	32;
	.endef
	.globl	is_prime
	.p2align	4, 0x90
is_prime:
	xor	r8d, r8d
	cmp	ecx, 2
	jb	.LBB0_6
	mov	r9d, ecx
	mov	r8d, 1
	cmp	ecx, 4
	jb	.LBB0_6
	mov	ecx, 2
	.p2align	4, 0x90
.LBB0_4:
	xor	edx, edx
	mov	eax, r9d
	div	ecx
	cmp	edx, 3
	je	.LBB0_5
	add	ecx, 1
	mov	eax, ecx
	imul	eax, ecx
	cmp	eax, r9d
	jbe	.LBB0_4
.LBB0_6:
	mov	eax, r8d
	ret
.LBB0_5:
	xor	r8d, r8d
	mov	eax, r8d
	ret

	.def	 main;
	.scl	2;
	.type	32;
	.endef
	.globl	main
	.p2align	4, 0x90
main:
	push	r14
	push	rsi
	push	rdi
	push	rbx
	sub	rsp, 40
	mov	esi, 2
	lea	r14, [rip + "??_C@_09EIHFMDLJ@composite?$AA@"]
	lea	rbx, [rip + "??_C@_05NIKGJPCK@prime?$AA@"]
	lea	rdi, [rip + "??_C@_0BB@DJJPDKAN@Number?5?$CFd?5is?5?$CFs?6?$AA@"]
	.p2align	4, 0x90
.LBB1_1:
	mov	ecx, esi
	call	is_prime
	test	eax, eax
	mov	r8, rbx
	cmove	r8, r14
	mov	rcx, rdi
	mov	edx, esi
	call	printf
	add	esi, 1
	cmp	esi, 30
	jne	.LBB1_1
	xor	eax, eax
	add	rsp, 40
	pop	rbx
	pop	rdi
	pop	rsi
	pop	r14
	ret

	.section	.rdata,"dr",discard,"??_C@_05NIKGJPCK@prime?$AA@"
	.globl	"??_C@_05NIKGJPCK@prime?$AA@"
"??_C@_05NIKGJPCK@prime?$AA@":
	.asciz	"prime"

	.section	.rdata,"dr",discard,"??_C@_09EIHFMDLJ@composite?$AA@"
	.globl	"??_C@_09EIHFMDLJ@composite?$AA@"
"??_C@_09EIHFMDLJ@composite?$AA@":
	.asciz	"composite"

	.section	.rdata,"dr",discard,"??_C@_0BB@DJJPDKAN@Number?5?$CFd?5is?5?$CFs?6?$AA@"
	.globl	"??_C@_0BB@DJJPDKAN@Number?5?$CFd?5is?5?$CFs?6?$AA@"
"??_C@_0BB@DJJPDKAN@Number?5?$CFd?5is?5?$CFs?6?$AA@":
	.asciz	"Number %d is %s\n"

	.lcomm	__local_stdio_printf_options._OptionsStorage,8,8

