	.file	"fact.c"
	.intel_syntax noprefix
	.text
	.globl	_fact
	.def	_fact;	.scl	2;	.type	32;	.endef
_fact:
LFB0:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	sub	esp, 16
	mov	DWORD PTR [ebp-4], 1
	cmp	DWORD PTR [ebp+8], 1
	jg	L4
	mov	eax, DWORD PTR [ebp+8]
	jmp	L3
L5:
	mov	eax, DWORD PTR [ebp-4]
	imul	eax, DWORD PTR [ebp+8]
	mov	DWORD PTR [ebp-4], eax
	sub	DWORD PTR [ebp+8], 1
L4:
	cmp	DWORD PTR [ebp+8], 0
	jg	L5
	mov	eax, DWORD PTR [ebp-4]
L3:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 8.1.0"
