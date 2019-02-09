	.file	"10-atomic-bmk.cc"
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
	addl	$1, %eax
	movl	%eax, _cnt
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
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "basic_string::_M_construct null not valid\0"
	.text
	.align 2
	.p2align 4,,15
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.isra.36;	.scl	3;	.type	32;	.endef
__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.isra.36:
LFB4198:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	leal	8(%ecx), %ebp
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	%ebp, (%ecx)
	movl	64(%esp), %edi
	testl	%edi, %edi
	je	L28
	movl	%edi, (%esp)
	movl	%ecx, %ebx
	call	_strlen
	movl	%eax, %esi
	movl	%eax, 28(%esp)
	cmpl	$15, %eax
	ja	L29
	cmpl	$1, %eax
	jne	L22
	movzbl	(%edi), %eax
	movb	%al, 8(%ebx)
L23:
	movl	28(%esp), %eax
	movl	(%ebx), %edx
	movl	%eax, 4(%ebx)
	movb	$0, (%edx,%eax)
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret	$4
L22:
	.cfi_restore_state
	testl	%eax, %eax
	je	L23
	jmp	L21
L29:
	leal	28(%esp), %eax
	movl	$0, 4(%esp)
	movl	%ebx, %ecx
	movl	%eax, (%esp)
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERjj
	.cfi_def_cfa_offset 56
	movl	%eax, %ebp
	pushl	%edx
	.cfi_def_cfa_offset 60
	pushl	%edx
	.cfi_def_cfa_offset 64
	movl	%eax, (%ebx)
	movl	28(%esp), %eax
	movl	%eax, 8(%ebx)
L21:
	movl	%esi, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%ebp, (%esp)
	call	_memcpy
	jmp	L23
L28:
	movl	$LC0, (%esp)
	call	__ZSt19__throw_logic_errorPKc
	.cfi_endproc
LFE4198:
	.section	.text$_ZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PjS9_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__ZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PjS9_
	.def	__ZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PjS9_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PjS9_:
LFB3427:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA3427
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	__imp___errno, %ebx
	movl	72(%esp), %esi
LEHB2:
	call	*%ebx
	movl	(%eax), %ebp
	call	*%ebx
LEHE2:
	movl	$0, (%eax)
	movl	80(%esp), %eax
	movl	%esi, (%esp)
	movl	%eax, 8(%esp)
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
LEHB3:
	call	*64(%esp)
	movl	%eax, %edi
	cmpl	%esi, 28(%esp)
	je	L42
	call	*%ebx
LEHE3:
	cmpl	$34, (%eax)
	je	L43
	movl	76(%esp), %edx
	testl	%edx, %edx
	je	L33
	movl	28(%esp), %eax
	movl	76(%esp), %edx
	subl	%esi, %eax
	movl	%eax, (%edx)
L33:
	call	*%ebx
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L44
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%edi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,10
L44:
	.cfi_restore_state
	call	*%ebx
	movl	%ebp, (%eax)
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	movl	%edi, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
L43:
	.cfi_restore_state
	movl	68(%esp), %eax
	movl	%eax, (%esp)
LEHB4:
	call	__ZSt20__throw_out_of_rangePKc
L42:
	movl	68(%esp), %eax
	movl	%eax, (%esp)
	call	__ZSt24__throw_invalid_argumentPKc
LEHE4:
L37:
	movl	%eax, %esi
L35:
	call	*%ebx
	cmpl	$0, (%eax)
	jne	L36
	call	*%ebx
	movl	%ebp, (%eax)
L36:
	movl	%esi, (%esp)
LEHB5:
	call	__Unwind_Resume
LEHE5:
	.cfi_endproc
LFE3427:
	.section	.gcc_except_table,"w"
LLSDA3427:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3427-LLSDACSB3427
LLSDACSB3427:
	.uleb128 LEHB2-LFB3427
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB3-LFB3427
	.uleb128 LEHE3-LEHB3
	.uleb128 L37-LFB3427
	.uleb128 0
	.uleb128 LEHB4-LFB3427
	.uleb128 LEHE4-LEHB4
	.uleb128 L37-LFB3427
	.uleb128 0
	.uleb128 LEHB5-LFB3427
	.uleb128 LEHE5-LEHB5
	.uleb128 0
	.uleb128 0
LLSDACSE3427:
	.section	.text$_ZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PjS9_,"x"
	.linkonce discard
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
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
	subl	$120, %esp
	movl	(%ecx), %ebx
	movl	4(%ecx), %esi
	call	___main
	cmpl	$1, %ebx
	jg	L116
	movl	$50000000, -60(%ebp)
	movl	$3, %edi
	movl	$10, -92(%ebp)
L46:
	leal	0(,%edi,4), %eax
	movl	$0, -64(%ebp)
	movl	%eax, -72(%ebp)
	.p2align 4,,10
L73:
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	%eax, -80(%ebp)
	movl	%edx, -76(%ebp)
	testl	%edi, %edi
	je	L86
	cmpl	$1073741823, %edi
	ja	L117
	movl	-72(%ebp), %eax
	movl	%eax, (%esp)
LEHB6:
	call	__Znwj
LEHE6:
	movl	%eax, %esi
	movl	%eax, %edx
	movl	%edi, %eax
	.p2align 4,,10
L52:
	movl	$0, (%edx)
	addl	$4, %edx
	subl	$1, %eax
	jne	L52
	movl	-72(%ebp), %eax
	addl	%esi, %eax
	movl	%eax, -68(%ebp)
	testl	%edi, %edi
	je	L61
	xorl	%ebx, %ebx
	.p2align 4,,10
L53:
	movl	$12, (%esp)
	movl	$0, -52(%ebp)
LEHB7:
	call	__Znwj
LEHE7:
	movl	-60(%ebp), %edx
	movl	$__ZTVNSt6thread11_State_implINS_8_InvokerISt5tupleIJPFviEiEEEEEE+8, (%eax)
	leal	-52(%ebp), %ecx
	movl	$__Z10threadfunci, 8(%eax)
	movl	%edx, 4(%eax)
	movl	%eax, -48(%ebp)
	leal	-48(%ebp), %eax
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
LEHB8:
	call	__ZNSt6thread15_M_start_threadESt10unique_ptrINS_6_StateESt14default_deleteIS1_EEPFvvE
LEHE8:
	movl	-48(%ebp), %ecx
	subl	$8, %esp
	testl	%ecx, %ecx
	je	L55
	movl	(%ecx), %eax
	call	*4(%eax)
L55:
	movl	(%esi,%ebx,4), %eax
	testl	%eax, %eax
	jne	L56
	movl	-52(%ebp), %eax
	movl	%eax, (%esi,%ebx,4)
	addl	$1, %ebx
	cmpl	%edi, %ebx
	jne	L53
	xorl	%ebx, %ebx
	.p2align 4,,10
L62:
	leal	(%esi,%ebx,4), %ecx
LEHB9:
	call	__ZNSt6thread4joinEv
	addl	$1, %ebx
	cmpl	%edi, %ebx
	jne	L62
L61:
	call	__ZNSt6chrono3_V212system_clock3nowEv
	movl	$__ZSt4cout, %ecx
	movl	%eax, -88(%ebp)
	movl	-64(%ebp), %eax
	movl	%edx, -84(%ebp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	subl	$4, %esp
	movl	%eax, %ebx
	movl	$1, 8(%esp)
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	-88(%ebp), %eax
	movl	-84(%ebp), %edx
	movl	$1000000, 8(%esp)
	subl	-80(%ebp), %eax
	sbbl	-76(%ebp), %edx
	movl	$0, 12(%esp)
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	___divdi3
	movl	%ebx, %ecx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	__ZNSo9_M_insertIxEERSoT_
	movl	%eax, %edx
	movl	%eax, -80(%ebp)
	movl	(%eax), %eax
	subl	$8, %esp
	movl	-12(%eax), %eax
	movl	124(%edx,%eax), %ebx
	testl	%ebx, %ebx
	je	L118
	cmpb	$0, 28(%ebx)
	je	L64
	movsbl	39(%ebx), %eax
L65:
	movl	%eax, (%esp)
	movl	-80(%ebp), %ecx
	call	__ZNSo3putEc
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNSo5flushEv
	movl	$0, _cnt
	cmpl	%esi, -68(%ebp)
	je	L66
	movl	(%esi), %ebx
	testl	%ebx, %ebx
	jne	L56
	movl	%esi, %eax
	movl	-68(%ebp), %edx
	jmp	L67
	.p2align 4,,10
L69:
	movl	(%eax), %ecx
	testl	%ecx, %ecx
	jne	L56
L67:
	addl	$4, %eax
	cmpl	%eax, %edx
	jne	L69
L71:
	movl	%esi, (%esp)
	call	__ZdlPv
L70:
	addl	$1, -64(%ebp)
	movl	-64(%ebp), %eax
	cmpl	-92(%ebp), %eax
	jl	L73
L98:
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
L64:
	.cfi_restore_state
	movl	%ebx, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L65
	movl	$10, (%esp)
	movl	%ebx, %ecx
	call	*%edx
LEHE9:
	subl	$4, %esp
	movsbl	%al, %eax
	jmp	L65
L66:
	testl	%esi, %esi
	je	L70
	jmp	L71
	.p2align 4,,10
L86:
	movl	$0, -68(%ebp)
	xorl	%esi, %esi
	jmp	L61
L116:
	movl	4(%esi), %eax
	leal	-48(%ebp), %ecx
	movl	%eax, (%esp)
LEHB10:
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.isra.36
LEHE10:
	pushl	%eax
	movl	-48(%ebp), %eax
	movl	$10, 16(%esp)
	movl	$0, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	$_strtol, (%esp)
LEHB11:
	call	__ZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PjS9_
LEHE11:
	movl	%eax, -60(%ebp)
	movl	-48(%ebp), %eax
	leal	-40(%ebp), %edi
	cmpl	%edi, %eax
	je	L47
	movl	%eax, (%esp)
	call	__ZdlPv
L47:
	cmpl	$2, %ebx
	je	L84
	movl	8(%esi), %eax
	leal	-48(%ebp), %ecx
	movl	%eax, (%esp)
LEHB12:
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.isra.36
LEHE12:
	pushl	%eax
	movl	-48(%ebp), %eax
	movl	$10, 16(%esp)
	movl	$0, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	$_strtol, (%esp)
LEHB13:
	call	__ZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PjS9_
LEHE13:
	movl	%eax, %edi
	movl	-48(%ebp), %eax
	leal	-40(%ebp), %edx
	cmpl	%edx, %eax
	je	L48
	movl	%eax, (%esp)
	call	__ZdlPv
L48:
	cmpl	$3, %ebx
	je	L85
	movl	12(%esi), %eax
	leal	-48(%ebp), %ecx
	movl	%eax, (%esp)
LEHB14:
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.isra.36
LEHE14:
	pushl	%eax
	movl	-48(%ebp), %eax
	movl	$10, 16(%esp)
	movl	$0, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	$_strtol, (%esp)
LEHB15:
	call	__ZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PjS9_
LEHE15:
	movl	%eax, -92(%ebp)
	movl	-48(%ebp), %eax
	leal	-40(%ebp), %esi
	cmpl	%esi, %eax
	je	L49
	movl	%eax, (%esp)
	call	__ZdlPv
L49:
	cmpl	$0, -92(%ebp)
	jg	L46
	jmp	L98
L56:
	call	__ZSt9terminatev
L84:
	movl	$3, %edi
	movl	$10, -92(%ebp)
	jmp	L46
L118:
LEHB16:
	call	__ZSt16__throw_bad_castv
LEHE16:
L117:
LEHB17:
	call	__ZSt17__throw_bad_allocv
LEHE17:
L85:
	movl	$10, -92(%ebp)
	jmp	L46
L91:
	movl	%eax, %ebx
	jmp	L78
L90:
	movl	%eax, %ebx
	jmp	L78
L89:
	movl	%eax, %ebx
	jmp	L78
L93:
	movl	%eax, %ebx
	jmp	L58
L92:
	movl	%eax, %ebx
	jmp	L60
	.section	.gcc_except_table,"w"
LLSDA3378:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE3378-LLSDACSB3378
LLSDACSB3378:
	.uleb128 LEHB6-LFB3378
	.uleb128 LEHE6-LEHB6
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB7-LFB3378
	.uleb128 LEHE7-LEHB7
	.uleb128 L92-LFB3378
	.uleb128 0
	.uleb128 LEHB8-LFB3378
	.uleb128 LEHE8-LEHB8
	.uleb128 L93-LFB3378
	.uleb128 0
	.uleb128 LEHB9-LFB3378
	.uleb128 LEHE9-LEHB9
	.uleb128 L92-LFB3378
	.uleb128 0
	.uleb128 LEHB10-LFB3378
	.uleb128 LEHE10-LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB11-LFB3378
	.uleb128 LEHE11-LEHB11
	.uleb128 L89-LFB3378
	.uleb128 0
	.uleb128 LEHB12-LFB3378
	.uleb128 LEHE12-LEHB12
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB13-LFB3378
	.uleb128 LEHE13-LEHB13
	.uleb128 L90-LFB3378
	.uleb128 0
	.uleb128 LEHB14-LFB3378
	.uleb128 LEHE14-LEHB14
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB15-LFB3378
	.uleb128 LEHE15-LEHB15
	.uleb128 L91-LFB3378
	.uleb128 0
	.uleb128 LEHB16-LFB3378
	.uleb128 LEHE16-LEHB16
	.uleb128 L92-LFB3378
	.uleb128 0
	.uleb128 LEHB17-LFB3378
	.uleb128 LEHE17-LEHB17
	.uleb128 0
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
L78:
	.cfi_escape 0xf,0x3,0x75,0x70,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x74
	.cfi_escape 0x10,0x5,0x2,0x75,0
	.cfi_escape 0x10,0x6,0x2,0x75,0x78
	.cfi_escape 0x10,0x7,0x2,0x75,0x7c
	movl	-48(%ebp), %edx
	leal	-40(%ebp), %eax
	cmpl	%eax, %edx
	je	L82
	movl	%edx, (%esp)
	call	__ZdlPv
L82:
	movl	%ebx, (%esp)
LEHB18:
	call	__Unwind_Resume
LEHE18:
L58:
	movl	-48(%ebp), %ecx
	testl	%ecx, %ecx
	je	L60
	movl	(%ecx), %eax
	call	*4(%eax)
L60:
	movl	%esi, %eax
L81:
	cmpl	%eax, -68(%ebp)
	jne	L119
	testl	%esi, %esi
	je	L82
	movl	%esi, (%esp)
	call	__ZdlPv
	jmp	L82
L119:
	cmpl	$0, (%eax)
	jne	L56
	addl	$4, %eax
	jmp	L81
	.cfi_endproc
LFE3378:
	.section	.gcc_except_table,"w"
LLSDAC3378:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSEC3378-LLSDACSBC3378
LLSDACSBC3378:
	.uleb128 LEHB18-LCOLDB3
	.uleb128 LEHE18-LEHB18
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
LEHB19:
	call	__ZNSt8ios_base4InitC1Ev
LEHE19:
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
	.uleb128 LEHB19-LFB4161
	.uleb128 LEHE19-LEHB19
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
	.space 4
.lcomm __ZStL8__ioinit,1,1
	.ident	"GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_pthread_mutex_unlock;	.scl	2;	.type	32;	.endef
	.def	_pthread_mutex_lock;	.scl	2;	.type	32;	.endef
	.def	__ZSt20__throw_system_errori;	.scl	2;	.type	32;	.endef
	.def	__ZNSt6thread6_StateD2Ev;	.scl	2;	.type	32;	.endef
	.def	__ZdlPvj;	.scl	2;	.type	32;	.endef
	.def	_pthread_mutex_destroy;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERjj;	.scl	2;	.type	32;	.endef
	.def	_memcpy;	.scl	2;	.type	32;	.endef
	.def	__ZSt19__throw_logic_errorPKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt20__throw_out_of_rangePKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt24__throw_invalid_argumentPKc;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
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
	.def	_strtol;	.scl	2;	.type	32;	.endef
	.def	__ZSt9terminatev;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	__ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
	.def	_pthread_mutex_init;	.scl	2;	.type	32;	.endef
