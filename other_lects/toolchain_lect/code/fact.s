	.file	"fact.c"
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.text
.Ltext0:
	.local	__gcov_indirect_call_callee
	.comm	__gcov_indirect_call_callee,8,8
	.local	__gcov_indirect_call_counters
	.comm	__gcov_indirect_call_counters,8,8
.globl fact
	.type	fact, @function
fact:
.LFB0:
	.file 1 "fact.c"
	.loc 1 3 0
	.cfi_startproc
	pushq	%rbp
.LCFI0:
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
.LCFI1:
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	.loc 1 4 0
	cmpl	$1, -4(%rbp)
	ja	.L2
	.loc 1 5 0
	movl	$1, %eax
	movq	.LPBX1+8(%rip), %rdx
	addq	$1, %rdx
	movq	%rdx, .LPBX1+8(%rip)
	jmp	.L3
.L2:
	movq	.LPBX1(%rip), %rax
	addq	$1, %rax
	movq	%rax, .LPBX1(%rip)
	.loc 1 7 0
	movl	-4(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	fact
	imull	-4(%rbp), %eax
	movq	.LPBX1+16(%rip), %rdx
	addq	$1, %rdx
	movq	%rdx, .LPBX1+16(%rip)
.L3:
	.loc 1 8 0
	leave
	ret
	.cfi_endproc
.LFE0:
	.size	fact, .-fact
	.local	.LPBX1
	.comm	.LPBX1,24,16
	.section	.rodata
	.align 8
.LC0:
	.string	"/home/tilir/cpp_lectures/other_lects/toolchain_lect/code/fact.gcda"
	.align 4
.LC1:
	.long	1
	.long	-671772290
	.long	3
	.data
	.align 32
	.type	.LPBX0, @object
	.size	.LPBX0, 104
.LPBX0:
	.long	875574314
	.zero	4
	.quad	0
	.long	-18689078
	.zero	4
	.quad	.LC0
	.long	1
	.zero	4
	.quad	.LC1
	.long	1
	.zero	4
	.long	3
	.zero	4
	.quad	.LPBX1
	.quad	__gcov_merge_add
	.zero	24
	.text
	.type	_GLOBAL__I_65535_0_fact, @function
_GLOBAL__I_65535_0_fact:
.LFB1:
	.loc 1 8 0
	.cfi_startproc
	pushq	%rbp
.LCFI2:
	.cfi_def_cfa_offset 16
	movq	%rsp, %rbp
	.cfi_offset 6, -16
.LCFI3:
	.cfi_def_cfa_register 6
	.loc 1 8 0
	movl	$.LPBX0, %edi
	call	__gcov_init
	leave
	ret
	.cfi_endproc
.LFE1:
	.size	_GLOBAL__I_65535_0_fact, .-_GLOBAL__I_65535_0_fact
	.section	.ctors,"aw",@progbits
	.align 8
	.quad	_GLOBAL__I_65535_0_fact
	.text
.Letext0:
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST0:
	.quad	.LFB0-.Ltext0
	.quad	.LCFI0-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 8
	.quad	.LCFI0-.Ltext0
	.quad	.LCFI1-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 16
	.quad	.LCFI1-.Ltext0
	.quad	.LFE0-.Ltext0
	.value	0x2
	.byte	0x76
	.sleb128 16
	.quad	0x0
	.quad	0x0
.LLST1:
	.quad	.LFB1-.Ltext0
	.quad	.LCFI2-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 8
	.quad	.LCFI2-.Ltext0
	.quad	.LCFI3-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 16
	.quad	.LCFI3-.Ltext0
	.quad	.LFE1-.Ltext0
	.value	0x2
	.byte	0x76
	.sleb128 16
	.quad	0x0
	.quad	0x0
	.section	.debug_info
	.long	0x7e
	.value	0x2
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF0
	.byte	0x1
	.long	.LASF1
	.long	.LASF2
	.quad	.Ltext0
	.quad	.Letext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.long	.LASF3
	.byte	0x1
	.byte	0x2
	.byte	0x1
	.long	0x5f
	.quad	.LFB0
	.quad	.LFE0
	.long	.LLST0
	.long	0x5f
	.uleb128 0x3
	.string	"x"
	.byte	0x1
	.byte	0x2
	.long	0x5f
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.byte	0x0
	.uleb128 0x4
	.byte	0x4
	.byte	0x7
	.long	.LASF4
	.uleb128 0x5
	.long	.LASF5
	.byte	0x1
	.byte	0x1
	.quad	.LFB1
	.quad	.LFE1
	.long	.LLST1
	.byte	0x0
	.section	.debug_abbrev
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x2
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0x0
	.byte	0x0
	.uleb128 0x5
	.uleb128 0x2e
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x34
	.uleb128 0xc
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section	.debug_pubnames,"",@progbits
	.long	0x17
	.value	0x2
	.long	.Ldebug_info0
	.long	0x82
	.long	0x2d
	.string	"fact"
	.long	0x0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0x0
	.value	0x0
	.value	0x0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0x0
	.quad	0x0
	.section	.debug_str,"MS",@progbits,1
.LASF3:
	.string	"fact"
.LASF2:
	.string	"/home/tilir/cpp_lectures/other_lects/toolchain_lect/code"
.LASF4:
	.string	"unsigned int"
.LASF0:
	.string	"GNU C 4.4.3"
.LASF5:
	.string	"_GLOBAL__I_65535_0_fact"
.LASF1:
	.string	"fact.c"
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5.1) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
