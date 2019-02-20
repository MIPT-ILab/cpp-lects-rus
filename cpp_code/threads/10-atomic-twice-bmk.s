	.file	"10-atomic-twice-bmk.cc"
	.text
	.section	.text$_ZNKSt5ctypeIcE8do_widenEc,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNKSt5ctypeIcE8do_widenEc
	.def	__ZNKSt5ctypeIcE8do_widenEc;	.scl	2;	.type	32;	.endef
__ZNKSt5ctypeIcE8do_widenEc:
LFB1948:
	.cfi_startproc
	movzbl	4(%esp), %eax
	ret	$4
	.cfi_endproc
LFE1948:
	.section	.text$_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEE6_M_runEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEE6_M_runEv
	.def	__ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEE6_M_runEv;	.scl	2;	.type	32;	.endef
__ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEE6_M_runEv:
LFB4149:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	4(%ecx), %eax
	movl	%eax, (%esp)
	call	*8(%ecx)
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE4149:
	.text
	.p2align 4,,15
	.globl	__Z10threadfunci
	.def	__Z10threadfunci;	.scl	2;	.type	32;	.endef
__Z10threadfunci:
LFB3377:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3377
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %ebx
	jmp	L8
	.p2align 4,,10
L11:
	movl	$_m, (%esp)
	call	_pthread_mutex_unlock
L8:
	movl	$_m, (%esp)
LEHB0:
	call	_pthread_mutex_lock
LEHE0:
	testl	%eax, %eax
	jne	L10
	movl	_cnt, %eax
	movl	_cnt+4, %ecx
	addl	$1, %eax
	leal	2(%ecx), %edx
	movl	%eax, _cnt
	addl	%edx, %eax
	movl	%edx, _cnt+4
	cmpl	%ebx, %eax
	jl	L11
	movl	$_m, 32(%esp)
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	jmp	_pthread_mutex_unlock
L10:
	.cfi_restore_state
	movl	%eax, (%esp)
LEHB1:
	call	__ZSt20__throw_system_errori
LEHE1:
	.cfi_endproc
LFE3377:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA3377:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3377-LLSDACSB3377
LLSDACSB3377:
	.uleb128 LEHB0-LFB3377
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB3377
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
LLSDACSE3377:
	.text
	.section	.text$_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEED1Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEED1Ev
	.def	__ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEED1Ev:
LFB4125:
	.cfi_startproc
	movl	$__ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE+8, (%ecx)
	jmp	__ZNSt6thread6_StateD2Ev
	.cfi_endproc
LFE4125:
	.section	.text$_ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEED0Ev,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEED0Ev
	.def	__ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEED0Ev;	.scl	2;	.type	32;	.endef
__ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEED0Ev:
LFB4126:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	%ecx, %ebx
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE+8, (%ecx)
	call	__ZNSt6thread6_StateD2Ev
	movl	%ebx, (%esp)
	movl	$12, 4(%esp)
	call	__ZdlPvj
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE4126:
	.text
	.p2align 4,,15
	.def	___tcf_1;	.scl	3;	.type	32;	.endef
___tcf_1:
LFB4148:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4148
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$_m, (%esp)
	call	_pthread_mutex_destroy
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE4148:
	.section	.gcc_except_table,"w"
LLSDA4148:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4148-LLSDACSB4148
LLSDACSB4148:
LLSDACSE4148:
	.text
	.p2align 4,,15
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB4144:
	.cfi_startproc
	movl	$__ZStL8__ioinit, %ecx
	jmp	__ZNSt8ios_base4InitD1Ev
	.cfi_endproc
LFE4144:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "basic_string::_M_construct null not valid\0"
LC1:
	.ascii "stoi\0"
LC2:
	.ascii " \0"
	.def	___divdi3;	.scl	2;	.type	32;	.endef
	.section	.text.unlikely,"x"
LCOLDB3:
	.section	.text.startup,"x"
LHOTB3:
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB3378:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3378
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x70,0x6
	.cfi_escape 0x10,0x7,0x2,0x75,0x7c
	.cfi_escape 0x10,0x6,0x2,0x75,0x78
	.cfi_escape 0x10,0x3,0x2,0x75,0x74
	subl	$88, %esp
	movl	(%ecx), %ebx
	movl	4(%ecx), %esi
	call	___main
	movl	$50000000, -60(%ebp)
	cmpl	$1, %ebx
	jg	L111
L19:
	movl	$4, -72(%ebp)
	movl	$1, -64(%ebp)
	.p2align 4,,10
L66:
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	-64(%ebp), %ebx
	movl	%eax, -88(%ebp)
	movl	-72(%ebp), %eax
	movl	%edx, -84(%ebp)
	movl	%eax, (%esp)
LEHB2:
	call	__Znwj
LEHE2:
	movl	%eax, -68(%ebp)
	.p2align 4,,10
L34:
	movl	$0, (%eax)
	addl	$4, %eax
	subl	$1, %ebx
	jne	L34
	movl	-68(%ebp), %eax
	movl	-72(%ebp), %edi
	movl	%eax, %esi
	addl	%eax, %edi
	movl	%eax, %ebx
	.p2align 4,,10
L43:
	movl	$12, (%esp)
	movl	$0, -52(%ebp)
LEHB3:
	call	__Znwj
LEHE3:
	movl	-60(%ebp), %edx
	movl	$__ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE+8, (%eax)
	leal	-52(%ebp), %ecx
	movl	$__Z10threadfunci, 8(%eax)
	movl	%edx, 4(%eax)
	movl	%eax, -48(%ebp)
	leal	-48(%ebp), %eax
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
LEHB4:
	call	__ZNSt6thread15_M_start_threadESt10unique_ptrINS_6_StateESt14default_deleteIS1_EEPFvvE
LEHE4:
	movl	-48(%ebp), %ecx
	subl	$8, %esp
	testl	%ecx, %ecx
	je	L38
	movl	(%ecx), %eax
	call	*4(%eax)
L38:
	movl	(%ebx), %eax
	testl	%eax, %eax
	jne	L39
	movl	-52(%ebp), %eax
	addl	$4, %ebx
	movl	%eax, -4(%ebx)
	cmpl	%ebx, %edi
	jne	L43
	.p2align 4,,10
L44:
	movl	%esi, %ecx
LEHB5:
	call	__ZNSt6thread4joinEv
LEHE5:
	addl	$4, %esi
	cmpl	%edi, %esi
	jne	L44
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$__ZSt4cout, %ecx
	movl	%eax, %ebx
	movl	-64(%ebp), %eax
	movl	%edx, %esi
	movl	%eax, (%esp)
LEHB6:
	call	__ZNSolsEi
LEHE6:
	subl	$4, %esp
	movl	%eax, -76(%ebp)
	movl	$1, 8(%esp)
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
LEHB7:
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
LEHE7:
	movl	%ebx, %eax
	movl	%esi, %edx
	subl	-88(%ebp), %eax
	sbbl	-84(%ebp), %edx
	movl	$1000000, 8(%esp)
	movl	$0, 12(%esp)
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	___divdi3
	movl	-76(%ebp), %ecx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
LEHB8:
	call	__ZNSo9_M_insertIxEERSoT_
LEHE8:
	movl	%eax, %esi
	movl	(%eax), %eax
	subl	$8, %esp
	movl	-12(%eax), %eax
	movl	124(%esi,%eax), %ebx
	testl	%ebx, %ebx
	je	L112
	cmpb	$0, 28(%ebx)
	je	L53
	movsbl	39(%ebx), %eax
L54:
	movl	%eax, (%esp)
	movl	%esi, %ecx
LEHB9:
	call	__ZNSo3putEc
LEHE9:
	subl	$4, %esp
	movl	%eax, %ecx
LEHB10:
	call	__ZNSo5flushEv
LEHE10:
	movl	$0, _cnt
	movl	-68(%ebp), %eax
	movl	$0, _cnt+4
	movl	(%eax), %ecx
	testl	%ecx, %ecx
	je	L64
	jmp	L39
	.p2align 4,,10
L109:
	movl	(%eax), %edx
	testl	%edx, %edx
	jne	L39
L64:
	addl	$4, %eax
	cmpl	%edi, %eax
	jne	L109
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	addl	$1, -64(%ebp)
	movl	-64(%ebp), %eax
	addl	$4, -72(%ebp)
	cmpl	$21, %eax
	jne	L66
	leal	-16(%ebp), %esp
	xorl	%eax, %eax
	popl	%ecx
	.cfi_remember_state
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.p2align 4,,10
L53:
	.cfi_restore_state
	movl	%ebx, %ecx
LEHB11:
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
LEHE11:
	movl	(%ebx), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L54
	movl	$10, (%esp)
	movl	%ebx, %ecx
LEHB12:
	call	*%edx
LEHE12:
	subl	$4, %esp
	movsbl	%al, %eax
	jmp	L54
L111:
	movl	4(%esi), %edx
	leal	-40(%ebp), %ebx
	movl	%ebx, -48(%ebp)
	testl	%edx, %edx
	je	L20
	xorl	%eax, %eax
	orl	$-1, %ecx
	movl	%edx, %edi
	repnz scasb
	movl	%ecx, %eax
	notl	%eax
	leal	-1(%eax), %esi
	movl	%esi, -52(%ebp)
	cmpl	$15, %esi
	ja	L113
	cmpl	$1, %esi
	jne	L24
	movzbl	(%edx), %eax
	movb	%al, -40(%ebp)
	jmp	L25
L39:
	call	__ZSt9terminatev
L24:
	testl	%esi, %esi
	jne	L114
L25:
	movl	-52(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	__imp___errno, %esi
	movl	%eax, -44(%ebp)
	movb	$0, (%edx,%eax)
	movl	-48(%ebp), %edi
LEHB13:
	call	*%esi
	movl	(%eax), %eax
	movl	%eax, -64(%ebp)
	call	*%esi
LEHE13:
	movl	$0, (%eax)
	leal	-52(%ebp), %eax
	movl	$10, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_strtol
	movl	%eax, -60(%ebp)
	cmpl	-52(%ebp), %edi
	je	L115
LEHB14:
	call	*%esi
LEHE14:
	cmpl	$34, (%eax)
	je	L116
	call	*%esi
	cmpl	$0, (%eax)
	je	L117
L28:
	movl	-48(%ebp), %eax
	cmpl	%ebx, %eax
	je	L19
	movl	%eax, (%esp)
	call	__ZdlPv
	jmp	L19
L113:
	leal	-52(%ebp), %eax
	movl	$0, 4(%esp)
	leal	-48(%ebp), %ecx
	movl	%eax, (%esp)
	movl	%edx, -60(%ebp)
LEHB15:
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERjj
LEHE15:
	movl	-52(%ebp), %ecx
	movl	%eax, -48(%ebp)
	movl	%ecx, -40(%ebp)
	pushl	%edx
	pushl	%edx
	movl	-60(%ebp), %edx
L23:
	movl	%esi, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_memcpy
	jmp	L25
L117:
	call	*%esi
	movl	-64(%ebp), %esi
	movl	%esi, (%eax)
	jmp	L28
L114:
	movl	%ebx, %eax
	jmp	L23
L112:
LEHB16:
	call	__ZSt16__throw_bad_castv
LEHE16:
L20:
	movl	$LC0, (%esp)
LEHB17:
	call	__ZSt19__throw_logic_errorPKc
LEHE17:
L116:
	movl	$LC1, (%esp)
LEHB18:
	call	__ZSt20__throw_out_of_rangePKc
L115:
	movl	$LC1, (%esp)
	call	__ZSt24__throw_invalid_argumentPKc
LEHE18:
L75:
	movl	%eax, %edi
	jmp	L33
L85:
	jmp	L70
L86:
	jmp	L70
L82:
	jmp	L70
L76:
	movl	%eax, %edi
	jmp	L31
L83:
	jmp	L70
L78:
	jmp	L70
L81:
	jmp	L70
L84:
	jmp	L70
L87:
	jmp	L70
L79:
	jmp	L70
L77:
	movl	%eax, %ebx
	jmp	L41
L80:
	jmp	L70
	.section	.gcc_except_table,"w"
LLSDA3378:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3378-LLSDACSB3378
LLSDACSB3378:
	.uleb128 LEHB2-LFB3378
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB3-LFB3378
	.uleb128 LEHE3-LEHB3
	.uleb128 L87-LFB3378
	.uleb128 0
	.uleb128 LEHB4-LFB3378
	.uleb128 LEHE4-LEHB4
	.uleb128 L77-LFB3378
	.uleb128 0
	.uleb128 LEHB5-LFB3378
	.uleb128 LEHE5-LEHB5
	.uleb128 L79-LFB3378
	.uleb128 0
	.uleb128 LEHB6-LFB3378
	.uleb128 LEHE6-LEHB6
	.uleb128 L81-LFB3378
	.uleb128 0
	.uleb128 LEHB7-LFB3378
	.uleb128 LEHE7-LEHB7
	.uleb128 L78-LFB3378
	.uleb128 0
	.uleb128 LEHB8-LFB3378
	.uleb128 LEHE8-LEHB8
	.uleb128 L83-LFB3378
	.uleb128 0
	.uleb128 LEHB9-LFB3378
	.uleb128 LEHE9-LEHB9
	.uleb128 L80-LFB3378
	.uleb128 0
	.uleb128 LEHB10-LFB3378
	.uleb128 LEHE10-LEHB10
	.uleb128 L82-LFB3378
	.uleb128 0
	.uleb128 LEHB11-LFB3378
	.uleb128 LEHE11-LEHB11
	.uleb128 L85-LFB3378
	.uleb128 0
	.uleb128 LEHB12-LFB3378
	.uleb128 LEHE12-LEHB12
	.uleb128 L84-LFB3378
	.uleb128 0
	.uleb128 LEHB13-LFB3378
	.uleb128 LEHE13-LEHB13
	.uleb128 L75-LFB3378
	.uleb128 0
	.uleb128 LEHB14-LFB3378
	.uleb128 LEHE14-LEHB14
	.uleb128 L76-LFB3378
	.uleb128 0
	.uleb128 LEHB15-LFB3378
	.uleb128 LEHE15-LEHB15
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB16-LFB3378
	.uleb128 LEHE16-LEHB16
	.uleb128 L86-LFB3378
	.uleb128 0
	.uleb128 LEHB17-LFB3378
	.uleb128 LEHE17-LEHB17
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB18-LFB3378
	.uleb128 LEHE18-LEHB18
	.uleb128 L76-LFB3378
	.uleb128 0
LLSDACSE3378:
	.section	.text.startup,"x"
	.cfi_endproc
	.section	.text.unlikely,"x"
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDAC3378
	.def	_main.cold.56;	.scl	3;	.type	32;	.endef
_main.cold.56:
L31:
	.cfi_escape 0xf,0x3,0x75,0x70,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x74
	.cfi_escape 0x10,0x5,0x2,0x75,0
	.cfi_escape 0x10,0x6,0x2,0x75,0x78
	.cfi_escape 0x10,0x7,0x2,0x75,0x7c
	call	*%esi
	cmpl	$0, (%eax)
	jne	L33
	call	*%esi
	movl	-64(%ebp), %esi
	movl	%esi, (%eax)
L33:
	movl	-48(%ebp), %eax
	cmpl	%ebx, %eax
	je	L69
	movl	%eax, (%esp)
	call	__ZdlPv
L69:
	movl	%edi, (%esp)
LEHB19:
	call	__Unwind_Resume
L70:
	movl	-68(%ebp), %edx
L72:
	cmpl	%edi, %edx
	jne	L118
	movl	%eax, -60(%ebp)
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	movl	-60(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_Resume
LEHE19:
L118:
	cmpl	$0, (%edx)
	jne	L39
	addl	$4, %edx
	jmp	L72
L41:
	movl	-48(%ebp), %ecx
	testl	%ecx, %ecx
	je	L42
	movl	(%ecx), %eax
	call	*4(%eax)
L42:
	movl	%ebx, %eax
	movl	-68(%ebp), %edx
	jmp	L72
	.cfi_endproc
LFE3378:
	.section	.gcc_except_table,"w"
LLSDAC3378:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSEC3378-LLSDACSBC3378
LLSDACSBC3378:
	.uleb128 LEHB19-LCOLDB3
	.uleb128 LEHE19-LEHB19
	.uleb128 0
	.uleb128 0
LLSDACSEC3378:
	.section	.text.unlikely,"x"
	.section	.text.startup,"x"
	.section	.text.unlikely,"x"
LCOLDE3:
	.section	.text.startup,"x"
LHOTE3:
	.p2align 4,,15
	.def	__GLOBAL__sub_I_cnt;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_cnt:
LFB4161:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA4161
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZStL8__ioinit, %ecx
LEHB20:
	call	__ZNSt8ios_base4InitC1Ev
LEHE20:
	movl	$___tcf_0, (%esp)
	call	_atexit
	movl	$0, 4(%esp)
	movl	$_m, (%esp)
	call	_pthread_mutex_init
	movl	$___tcf_1, (%esp)
	call	_atexit
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE4161:
	.section	.gcc_except_table,"w"
LLSDA4161:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE4161-LLSDACSB4161
LLSDACSB4161:
	.uleb128 LEHB20-LFB4161
	.uleb128 LEHE20-LEHB20
	.uleb128 0
	.uleb128 0
LLSDACSE4161:
	.section	.text.startup,"x"
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_cnt
	.globl	__ZTSNSt6thread6_StateE
	.section	.rdata$_ZTSNSt6thread6_StateE,"dr"
	.linkonce same_size
	.align 4
__ZTSNSt6thread6_StateE:
	.ascii "NSt6thread6_StateE\0"
	.globl	__ZTINSt6thread6_StateE
	.section	.rdata$_ZTINSt6thread6_StateE,"dr"
	.linkonce same_size
	.align 4
__ZTINSt6thread6_StateE:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTSNSt6thread6_StateE
	.globl	__ZTSNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE
	.section	.rdata$_ZTSNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE,"dr"
	.linkonce same_size
	.align 32
__ZTSNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE:
	.ascii "NSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE\0"
	.globl	__ZTINSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE
	.section	.rdata$_ZTINSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE,"dr"
	.linkonce same_size
	.align 4
__ZTINSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTSNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE
	.long	__ZTINSt6thread6_StateE
	.globl	__ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE
	.section	.rdata$_ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE,"dr"
	.linkonce same_size
	.align 4
__ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE:
	.long	0
	.long	__ZTINSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE
	.long	__ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEED1Ev
	.long	__ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEED0Ev
	.long	__ZNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEE6_M_runEv
	.globl	_m
	.bss
	.align 4
_m:
	.space 4
	.globl	_cnt
	.align 4
_cnt:
	.space 8
.lcomm __ZStL8__ioinit,1,1
	.ident	"GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_pthread_mutex_unlock;	.scl	2;	.type	32;	.endef
	.def	_pthread_mutex_lock;	.scl	2;	.type	32;	.endef
	.def	__ZSt20__throw_system_errori;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6thread6_StateD2Ev;	.scl	2;	.type	32;	.endef
	.def	__ZdlPvj;	.scl	2;	.type	32;	.endef
	.def	_pthread_mutex_destroy;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6chrono3_V212system_clock3nowEv;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6thread15_M_start_threadESt10unique_ptrINS_6_StateESt14default_deleteIS1_EEPFvvE;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6thread4joinEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i;	.scl	2;	.type	32;	.endef
	.def	__ZNSo9_M_insertIxEERSoT_;	.scl	2;	.type	32;	.endef
	.def	__ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	__ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	__ZSt9terminatev;	.scl	2;	.type	32;	.endef
	.def	_strtol;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERjj;	.scl	2;	.type	32;	.endef
	.def	_memcpy;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	__ZSt19__throw_logic_errorPKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt20__throw_out_of_rangePKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt24__throw_invalid_argumentPKc;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
	.def	_pthread_mutex_init;	.scl	2;	.type	32;	.endef
