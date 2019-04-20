	.text
	.intel_syntax noprefix
	.def	 fib;
	.scl	2;
	.type	32;
	.endef
	.globl	fib
	.p2align	4, 0x90
fib:
	test	ecx, ecx
	je	.LBB0_5
	cmp	ecx, 1
	jne	.LBB0_2
	mov	ecx, 1
	mov	eax, ecx
	ret
.LBB0_2:
	mov	r8d, ecx
	neg	r8d
	xor	edx, edx
	mov	r9d, 1
	mov	eax, 2
	.p2align	4, 0x90
.LBB0_3:
	mov	ecx, edx
	add	ecx, r9d
	xor	edx, edx
	cmp	eax, 5
	seta	dl
	add	edx, r9d
	lea	r10d, [r8 + rax]
	add	r10d, 1
	lea	eax, [rax + 1]
	mov	r9d, ecx
	cmp	r10d, 1
	jne	.LBB0_3
.LBB0_5:
	mov	eax, ecx
	ret

	.def	 main;
	.scl	2;
	.type	32;
	.endef
	.globl	main
	.p2align	4, 0x90
main:
	push	rsi
	push	rdi
	sub	rsp, 40
	mov	esi, 2
	lea	rdi, [rip + "??_C@_0BL@FFMNFBOF@Fibonacci?5number?5?$CFd?5is?5?$CFd?6?$AA@"]
	.p2align	4, 0x90
.LBB1_1:
	mov	ecx, esi
	call	fib
	mov	rcx, rdi
	mov	edx, esi
	mov	r8d, eax
	call	printf
	add	esi, 1
	cmp	esi, 20
	jne	.LBB1_1
	xor	eax, eax
	add	rsp, 40
	pop	rdi
	pop	rsi
	ret

	.def	 printf;
	.scl	2;
	.type	32;
	.endef
	.section	.text,"xr",discard,printf
	.globl	printf
	.p2align	4, 0x90
printf:
	push	rsi
	push	rdi
	sub	rsp, 40
	mov	rsi, rcx
	mov	qword ptr [rsp + 88], r9
	mov	qword ptr [rsp + 80], r8
	mov	qword ptr [rsp + 72], rdx
	lea	rdi, [rsp + 72]
	mov	qword ptr [rsp + 32], rdi
	mov	ecx, 1
	call	__acrt_iob_func
	xor	r8d, r8d
	mov	rcx, rax
	mov	rdx, rsi
	mov	r9, rdi
	call	_vfprintf_l
	add	rsp, 40
	pop	rdi
	pop	rsi
	ret

	.def	 __local_stdio_printf_options;
	.scl	2;
	.type	32;
	.endef
	.section	.text,"xr",discard,__local_stdio_printf_options
	.globl	__local_stdio_printf_options
	.p2align	4, 0x90
__local_stdio_printf_options:
	lea	rax, [rip + __local_stdio_printf_options._OptionsStorage]
	ret

	.def	 _vfprintf_l;
	.scl	2;
	.type	32;
	.endef
	.section	.text,"xr",discard,_vfprintf_l
	.globl	_vfprintf_l
	.p2align	4, 0x90
_vfprintf_l:
	push	r14
	push	rsi
	push	rdi
	push	rbx
	sub	rsp, 40
	mov	rsi, r9
	mov	r14, r8
	mov	rbx, rdx
	mov	rdi, rcx
	call	__local_stdio_printf_options
	mov	rcx, qword ptr [rax]
	mov	qword ptr [rsp + 32], rsi
	mov	rdx, rdi
	mov	r8, rbx
	mov	r9, r14
	call	__stdio_common_vfprintf
	add	rsp, 40
	pop	rbx
	pop	rdi
	pop	rsi
	pop	r14
	ret

	.section	.rdata,"dr",discard,"??_C@_0BL@FFMNFBOF@Fibonacci?5number?5?$CFd?5is?5?$CFd?6?$AA@"
	.globl	"??_C@_0BL@FFMNFBOF@Fibonacci?5number?5?$CFd?5is?5?$CFd?6?$AA@"
"??_C@_0BL@FFMNFBOF@Fibonacci?5number?5?$CFd?5is?5?$CFd?6?$AA@":
	.asciz	"Fibonacci number %d is %d\n"

	.lcomm	__local_stdio_printf_options._OptionsStorage,8,8

