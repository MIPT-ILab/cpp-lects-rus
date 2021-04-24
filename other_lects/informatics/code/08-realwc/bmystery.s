	.file	"bmystery.c"
	.intel_syntax noprefix
	.text
	.p2align 4
	.globl	less
	.type	less, @function
less:
.LFB40:
	.cfi_startproc
	endbr64
	mov	eax, DWORD PTR [rdi]
	sub	eax, DWORD PTR [rsi]
	ret
	.cfi_endproc
.LFE40:
	.size	less, .-less
	.p2align 4
	.globl	measure
	.type	measure, @function
measure:
.LFB39:
	.cfi_startproc
	endbr64
	push	r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	mov	r12d, esi
	push	rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	mov	rbp, rdi
	push	rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	call	clock@PLT
	mov	r8d, 50000
	xor	ecx, ecx
	mov	rbx, rax
	lea	eax, -1[r12]
	lea	rdi, 4[rbp+rax*4]
	.p2align 4,,10
	.p2align 3
.L4:
	mov	rax, rbp
	test	r12d, r12d
	jle	.L8
	.p2align 4,,10
	.p2align 3
.L6:
	movsx	rdx, DWORD PTR [rax]
	mov	rsi, rdx
	add	rdx, rcx
	cmp	esi, 128
	cmovg	rcx, rdx
	add	rax, 4
	cmp	rax, rdi
	jne	.L6
.L8:
	sub	r8d, 1
	jne	.L4
	mov	QWORD PTR gsum[rip], rcx
	call	clock@PLT
	sub	eax, ebx
	pop	rbx
	.cfi_def_cfa_offset 24
	pop	rbp
	.cfi_def_cfa_offset 16
	pop	r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE39:
	.size	measure, .-measure
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"pre-sorting data"
.LC2:
	.string	"elapsed time: %lf\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB41:
	.cfi_startproc
	endbr64
	push	r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	push	rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	push	rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	lea	r11, -126976[rsp]
	.cfi_def_cfa 11, 127008
.LPSRL0:
	sub	rsp, 4096
	or	DWORD PTR [rsp], 0
	cmp	rsp, r11
	jne	.LPSRL0
	.cfi_def_cfa_register 7
	sub	rsp, 1040
	.cfi_def_cfa_offset 128048
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR 128008[rsp], rax
	xor	eax, eax
	mov	rbp, rsp
	lea	rbx, 128000[rsp]
	mov	r12, rbp
	.p2align 4,,10
	.p2align 3
.L14:
	call	rand@PLT
	add	r12, 4
	cdq
	shr	edx, 24
	add	eax, edx
	movzx	eax, al
	sub	eax, edx
	mov	DWORD PTR -4[r12], eax
	cmp	r12, rbx
	jne	.L14
	lea	rdi, .LC0[rip]
	call	puts@PLT
	lea	rcx, less[rip]
	mov	edx, 4
	mov	rdi, rbp
	mov	esi, 32000
	call	qsort@PLT
	mov	esi, 32000
	mov	rdi, rbp
	call	measure
	pxor	xmm0, xmm0
	mov	edi, 1
	lea	rsi, .LC2[rip]
	cvtsi2sd	xmm0, eax
	mov	eax, 1
	divsd	xmm0, QWORD PTR .LC1[rip]
	call	__printf_chk@PLT
	mov	rax, QWORD PTR 128008[rsp]
	xor	rax, QWORD PTR fs:40
	jne	.L18
	add	rsp, 128016
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	xor	eax, eax
	pop	rbx
	.cfi_def_cfa_offset 24
	pop	rbp
	.cfi_def_cfa_offset 16
	pop	r12
	.cfi_def_cfa_offset 8
	ret
.L18:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE41:
	.size	main, .-main
	.comm	gsum,8,8
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1093567616
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
