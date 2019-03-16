	.file	"main-inlasm.c"
	.intel_syntax noprefix
	.text
	.globl	_name
	.section .rdata,"dr"
LC0:
	.ascii "Hello, world!\12\0"
	.data
	.align 4
_name:
	.long	LC0
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB13:
	.cfi_startproc
	push	ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	mov	ebp, esp
	.cfi_def_cfa_register 5
	and	esp, -16
	call	___main
	mov	edx, DWORD PTR _name
/APP
 # 9 "main-inlasm.c" 1
	mov DWORD PTR [esp], 5
call _fact
mov DWORD PTR [esp+4], eax
lea eax, BYTE PTR [edx]
mov DWORD PTR [esp], eax
call _printf

 # 0 "" 2
/NO_APP
	mov	eax, 0
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.ident	"GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_fact;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
