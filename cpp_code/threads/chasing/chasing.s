	.cpu generic+fp+simd
	.file	"chasing.cc"
	.text
	.align	2
	.global	updateboth
	.type	updateboth, %function
updateboth:
.LFB2023:
	.cfi_startproc
	adrp	x1, .LANCHOR0
	ldr	w0, [x1, #:lo12:.LANCHOR0]
	cbz	w0, .L1
.L4:
	ldr	w2, [x1, #:lo12:.LANCHOR0]
	add	x0, x1, :lo12:.LANCHOR0
	add	w2, w2, 1
	str	w2, [x1, #:lo12:.LANCHOR0]
	ldr	w2, [x0, 256]
	add	w2, w2, 1
	str	w2, [x0, 256]
	ldr	w0, [x1, #:lo12:.LANCHOR0]
	cbnz	w0, .L4
.L1:
	ret
	.cfi_endproc
.LFE2023:
	.size	updateboth, .-updateboth
	.section	.text._ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED2Ev,"axG",%progbits,_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED5Ev,comdat
	.align	2
	.weak	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED2Ev
	.type	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED2Ev, %function
_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED2Ev:
.LFB2371:
	.cfi_startproc
	ret
	.cfi_endproc
.LFE2371:
	.size	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED2Ev, .-_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED2Ev
	.weak	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED1Ev
_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED1Ev = _ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED2Ev
	.section	.text._ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv,"axG",%progbits,_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv,comdat
	.align	2
	.weak	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv
	.type	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv, %function
_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv:
.LFB2374:
	.cfi_startproc
	mov	x1, x0
	add	x0, x0, 16
	ldr	x1, [x1, 16]
	ldr	x1, [x1]
	br	x1
	.cfi_endproc
.LFE2374:
	.size	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv, .-_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv
	.section	.text._ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEE6_M_runEv,"axG",%progbits,_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEE6_M_runEv,comdat
	.align	2
	.weak	_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEE6_M_runEv
	.type	_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEE6_M_runEv, %function
_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEE6_M_runEv:
.LFB2377:
	.cfi_startproc
	ldr	x0, [x0, 24]
	br	x0
	.cfi_endproc
.LFE2377:
	.size	_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEE6_M_runEv, .-_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEE6_M_runEv
	.section	.text._ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED0Ev,"axG",%progbits,_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED5Ev,comdat
	.align	2
	.weak	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED0Ev
	.type	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED0Ev, %function
_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED0Ev:
.LFB2373:
	.cfi_startproc
	b	_ZdlPv
	.cfi_endproc
.LFE2373:
	.size	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED0Ev, .-_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED0Ev
	.section	.text._ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv,"axG",%progbits,_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv,comdat
	.align	2
	.weak	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.type	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv, %function
_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv:
.LFB2375:
	.cfi_startproc
	b	_ZdlPv
	.cfi_endproc
.LFE2375:
	.size	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv, .-_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.text
	.align	2
	.global	readboth
	.type	readboth, %function
readboth:
.LFB2024:
	.cfi_startproc
	stp	x29, x30, [sp, -16]!
	.cfi_def_cfa_offset 16
	.cfi_offset 29, -16
	.cfi_offset 30, -8
	adrp	x1, .LANCHOR0
	add	x29, sp, 0
	.cfi_def_cfa_register 29
.L14:
	add	x0, x1, :lo12:.LANCHOR0
	ldr	w0, [x0, 256]
	ldr	w2, [x1, #:lo12:.LANCHOR0]
	cmp	w0, w2
	bhi	.L16
	cbnz	w0, .L14
	ldp	x29, x30, [sp], 16
	.cfi_remember_state
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
.L16:
	.cfi_restore_state
	adrp	x3, .LANCHOR1
	adrp	x1, .LC0
	adrp	x0, .LC1
	add	x3, x3, :lo12:.LANCHOR1
	mov	w2, 24
	add	x1, x1, :lo12:.LC0
	add	x0, x0, :lo12:.LC1
	bl	__assert_fail
	.cfi_endproc
.LFE2024:
	.size	readboth, .-readboth
	.section	.text._ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info,"axG",%progbits,_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info,comdat
	.align	2
	.weak	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
	.type	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info, %function
_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info:
.LFB2376:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0
	.cfi_def_cfa_register 29
	ldr	x2, [x1, 8]
	ldr	x1, .LC2
	str	x19, [sp, 16]
	.cfi_offset 19, -16
	mov	x19, x0
	cmp	x2, x1
	beq	.L18
	ldrb	w0, [x2]
	cmp	w0, 42
	beq	.L20
	mov	x0, x2
	bl	strcmp
	cbz	w0, .L18
.L20:
	mov	x0, 0
	ldr	x19, [sp, 16]
	.cfi_remember_state
	.cfi_restore 19
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
.L18:
	.cfi_restore_state
	add	x0, x19, 16
	ldr	x19, [sp, 16]
	.cfi_restore 19
	ldp	x29, x30, [sp], 32
	.cfi_restore 29
	.cfi_restore 30
	.cfi_def_cfa 31, 0
	ret
	.cfi_endproc
.LFE2376:
	.size	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info, .-_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
	.align	3
.LC2:
	.xword	_ZTSSt19_Sp_make_shared_tag
	.section	.text._ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv,"axG",%progbits,_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv,comdat
	.align	2
	.weak	_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.type	_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv, %function
_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv:
.LFB2201:
	.cfi_startproc
	cbz	x0, .L25
	ldr	x1, [x0]
	ldr	x2, .LC3
	ldr	x1, [x1, 8]
	cmp	x1, x2
	bne	.L27
	b	_ZdlPv
.L25:
	ret
.L27:
	br	x1
	.cfi_endproc
.LFE2201:
	.size	_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv, .-_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.align	3
.LC3:
	.xword	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED0Ev
	.section	.text._ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED2Ev,"axG",%progbits,_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED5Ev,comdat
	.align	2
	.weak	_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED2Ev
	.type	_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED2Ev, %function
_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED2Ev:
.LFB2351:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0
	.cfi_def_cfa_register 29
	stp	x19, x20, [sp, 16]
	.cfi_offset 19, -16
	.cfi_offset 20, -8
	ldr	x1, .LC4
	ldr	x19, [x0, 16]
	str	x1, [x0]
	cbz	x19, .L28
	ldr	x20, .LC5
	cbz	x20, .L31
	add	x1, x19, 8
	mov	w2, -1
.L39:
	ldaxr	w0, [x1]
	add	w3, w0, w2
	stlxr	w4, w3, [x1]
	cbnz	w4, .L39
	cmp	w0, 1
	beq	.L40
.L28:
	ldp	x19, x20, [sp, 16]
	.cfi_remember_state
	.cfi_restore 20
	.cfi_restore 19
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
.L31:
	.cfi_restore_state
	ldr	w0, [x19, 8]
	sub	w1, w0, #1
	cmp	w0, 1
	str	w1, [x19, 8]
	bne	.L28
.L40:
	ldr	x0, [x19]
	ldr	x1, [x0, 16]
	ldr	x0, .LC6
	cmp	x1, x0
	bne	.L34
	ldr	x1, [x19, 16]
	add	x0, x19, 16
	ldr	x1, [x1]
	blr	x1
.L35:
	cbz	x20, .L36
	add	x1, x19, 12
	mov	w2, -1
.L38:
	ldaxr	w0, [x1]
	add	w3, w0, w2
	stlxr	w4, w3, [x1]
	cbnz	w4, .L38
.L37:
	cmp	w0, 1
	bne	.L28
	ldr	x1, [x19]
	mov	x0, x19
	ldp	x19, x20, [sp, 16]
	.cfi_remember_state
	.cfi_restore 20
	.cfi_restore 19
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ldr	x1, [x1, 24]
	br	x1
.L36:
	.cfi_restore_state
	ldr	w0, [x19, 12]
	sub	w1, w0, #1
	str	w1, [x19, 12]
	b	.L37
.L34:
	mov	x0, x19
	blr	x1
	b	.L35
	.cfi_endproc
.LFE2351:
	.size	_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED2Ev, .-_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED2Ev
	.align	3
.LC4:
	.xword	_ZTVNSt6thread10_Impl_baseE+16
	.align	3
.LC5:
	.xword	_ZL28__gthrw___pthread_key_createPjPFvPvE
	.align	3
.LC6:
	.xword	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv
	.weak	_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED1Ev
_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED1Ev = _ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED2Ev
	.section	.text._ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED0Ev,"axG",%progbits,_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED5Ev,comdat
	.align	2
	.weak	_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED0Ev
	.type	_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED0Ev, %function
_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED0Ev:
.LFB2353:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	add	x29, sp, 0
	.cfi_def_cfa_register 29
	stp	x19, x20, [sp, 16]
	.cfi_offset 19, -32
	.cfi_offset 20, -24
	mov	x19, x0
	ldr	x20, [x0, 16]
	str	x21, [sp, 32]
	.cfi_offset 21, -16
	ldr	x0, .LC7
	str	x0, [x19]
	cbz	x20, .L43
	ldr	x21, .LC8
	cbz	x21, .L44
	add	x1, x20, 8
	mov	w2, -1
.L52:
	ldaxr	w0, [x1]
	add	w3, w0, w2
	stlxr	w4, w3, [x1]
	cbnz	w4, .L52
	cmp	w0, 1
	beq	.L53
.L43:
	mov	x0, x19
	ldr	x21, [sp, 32]
	.cfi_remember_state
	.cfi_restore 21
	ldp	x19, x20, [sp, 16]
	.cfi_restore 20
	.cfi_restore 19
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	b	_ZdlPv
.L44:
	.cfi_restore_state
	ldr	w0, [x20, 8]
	sub	w1, w0, #1
	cmp	w0, 1
	str	w1, [x20, 8]
	bne	.L43
.L53:
	ldr	x0, [x20]
	ldr	x1, [x0, 16]
	ldr	x0, .LC9
	cmp	x1, x0
	bne	.L47
	ldr	x1, [x20, 16]
	add	x0, x20, 16
	ldr	x1, [x1]
	blr	x1
.L48:
	cbz	x21, .L49
	add	x1, x20, 12
	mov	w2, -1
.L51:
	ldaxr	w0, [x1]
	add	w3, w0, w2
	stlxr	w4, w3, [x1]
	cbnz	w4, .L51
.L50:
	cmp	w0, 1
	bne	.L43
	ldr	x1, [x20]
	mov	x0, x20
	ldr	x1, [x1, 24]
	blr	x1
	b	.L43
.L49:
	ldr	w0, [x20, 12]
	sub	w1, w0, #1
	str	w1, [x20, 12]
	b	.L50
.L47:
	mov	x0, x20
	blr	x1
	b	.L48
	.cfi_endproc
.LFE2353:
	.size	_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED0Ev, .-_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED0Ev
	.align	3
.LC7:
	.xword	_ZTVNSt6thread10_Impl_baseE+16
	.align	3
.LC8:
	.xword	_ZL28__gthrw___pthread_key_createPjPFvPvE
	.align	3
.LC9:
	.xword	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv
	.section	.text._ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv,"axG",%progbits,_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv,comdat
	.align	2
	.weak	_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
	.type	_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv, %function
_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv:
.LFB2144:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	add	x29, sp, 0
	.cfi_def_cfa_register 29
	stp	x19, x20, [sp, 16]
	.cfi_offset 19, -16
	.cfi_offset 20, -8
	ldr	x20, .LC10
	cbz	x20, .L55
	add	x2, x0, 8
	mov	w3, -1
.L65:
	ldaxr	w1, [x2]
	add	w4, w1, w3
	stlxr	w5, w4, [x2]
	cbnz	w5, .L65
	cmp	w1, 1
	beq	.L66
.L54:
	ldp	x19, x20, [sp, 16]
	.cfi_remember_state
	.cfi_restore 20
	.cfi_restore 19
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
.L55:
	.cfi_restore_state
	ldr	w1, [x0, 8]
	sub	w2, w1, #1
	cmp	w1, 1
	str	w2, [x0, 8]
	bne	.L54
.L66:
	mov	x19, x0
	ldr	x0, [x0]
	ldr	x1, [x0, 16]
	ldr	x0, .LC11
	cmp	x1, x0
	bne	.L59
	ldr	x1, [x19, 16]
	add	x0, x19, 16
	ldr	x1, [x1]
	blr	x1
.L60:
	cbz	x20, .L61
	add	x1, x19, 12
	mov	w2, -1
.L64:
	ldaxr	w0, [x1]
	add	w3, w0, w2
	stlxr	w4, w3, [x1]
	cbnz	w4, .L64
.L62:
	cmp	w0, 1
	bne	.L54
	ldr	x1, [x19]
	mov	x0, x19
	ldp	x19, x20, [sp, 16]
	.cfi_remember_state
	.cfi_restore 20
	.cfi_restore 19
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ldr	x1, [x1, 24]
	br	x1
.L61:
	.cfi_restore_state
	ldr	w0, [x19, 12]
	sub	w1, w0, #1
	str	w1, [x19, 12]
	b	.L62
.L59:
	mov	x0, x19
	blr	x1
	b	.L60
	.cfi_endproc
.LFE2144:
	.size	_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv, .-_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
	.align	3
.LC10:
	.xword	_ZL28__gthrw___pthread_key_createPjPFvPvE
	.align	3
.LC11:
	.xword	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv
	.section	.text._ZNSt6threadC2IRFvvEIEEEOT_DpOT0_,"axG",%progbits,_ZNSt6threadC5IRFvvEIEEEOT_DpOT0_,comdat
	.align	2
	.weak	_ZNSt6threadC2IRFvvEIEEEOT_DpOT0_
	.type	_ZNSt6threadC2IRFvvEIEEEOT_DpOT0_, %function
_ZNSt6threadC2IRFvvEIEEEOT_DpOT0_:
.LFB2096:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA2096
	stp	x29, x30, [sp, -80]!
	.cfi_def_cfa_offset 80
	.cfi_offset 29, -80
	.cfi_offset 30, -72
	add	x29, sp, 0
	.cfi_def_cfa_register 29
	stp	x19, x20, [sp, 16]
	.cfi_offset 19, -64
	.cfi_offset 20, -56
	adrp	x19, __stack_chk_guard
	mov	x20, x0
	add	x0, x19, :lo12:__stack_chk_guard
	str	x21, [sp, 32]
	.cfi_offset 21, -48
	ldr	x2, [x0]
	str	x2, [x29, 72]
	mov	x2,0
	mov	x21, x1
	adrp	x2, pthread_create
	str	xzr, [x20]
	add	x2, x2, :lo12:pthread_create
	mov	x0, 48
.LEHB0:
	bl	_Znwm
.LEHE0:
	mov	x2, x0
	mov	x3, x0
	mov	w4, 1
	str	w4, [x0, 8]
	add	x1, x29, 56
	str	w4, [x2, 12]
	mov	x0, x20
	ldr	x4, .LC12
	str	x4, [x3], 16
	ldr	x4, .LC13
	str	xzr, [x3, 8]
	str	xzr, [x3, 16]
	str	x4, [x2, 16]
	str	x21, [x2, 40]
	str	x3, [x29, 56]
	str	x2, [x29, 64]
.LEHB1:
	bl	_ZNSt6thread15_M_start_threadESt10shared_ptrINS_10_Impl_baseEE
.LEHE1:
	ldr	x20, [x29, 64]
	cbz	x20, .L67
	ldr	x21, .LC14
	cbz	x21, .L69
	add	x1, x20, 8
	mov	w2, -1
.L87:
	ldaxr	w0, [x1]
	add	w3, w0, w2
	stlxr	w4, w3, [x1]
	cbnz	w4, .L87
	cmp	w0, 1
	beq	.L88
.L67:
	add	x19, x19, :lo12:__stack_chk_guard
	ldr	x1, [x29, 72]
	ldr	x0, [x19]
	eor	x0, x1, x0
	cbnz	x0, .L89
	ldp	x19, x20, [sp, 16]
	.cfi_remember_state
	.cfi_restore 20
	.cfi_restore 19
	ldr	x21, [sp, 32]
	.cfi_restore 21
	ldp	x29, x30, [sp], 80
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
.L69:
	.cfi_restore_state
	ldr	w0, [x20, 8]
	sub	w1, w0, #1
	cmp	w0, 1
	str	w1, [x20, 8]
	bne	.L67
.L88:
	ldr	x0, [x20]
	ldr	x1, [x0, 16]
	ldr	x0, .LC15
	cmp	x1, x0
	bne	.L71
	ldr	x1, [x20, 16]
	add	x0, x20, 16
	ldr	x1, [x1]
	blr	x1
.L72:
	cbz	x21, .L73
	add	x1, x20, 12
	mov	w2, -1
.L86:
	ldaxr	w0, [x1]
	add	w3, w0, w2
	stlxr	w4, w3, [x1]
	cbnz	w4, .L86
.L74:
	cmp	w0, 1
	bne	.L67
	ldr	x1, [x20]
	mov	x0, x20
	ldr	x1, [x1, 24]
	blr	x1
	b	.L67
.L73:
	ldr	w0, [x20, 12]
	sub	w1, w0, #1
	str	w1, [x20, 12]
	b	.L74
.L71:
	mov	x0, x20
	blr	x1
	b	.L72
.L89:
	bl	__stack_chk_fail
.L79:
	ldr	x1, [x29, 64]
	mov	x19, x0
	cbz	x1, .L77
	mov	x0, x1
	bl	_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv
.L77:
	mov	x0, x19
.LEHB2:
	bl	_Unwind_Resume
.LEHE2:
	.cfi_endproc
.LFE2096:
	.global	__gxx_personality_v0
	.section	.gcc_except_table._ZNSt6threadC2IRFvvEIEEEOT_DpOT0_,"aG",%progbits,_ZNSt6threadC5IRFvvEIEEEOT_DpOT0_,comdat
.LLSDA2096:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2096-.LLSDACSB2096
.LLSDACSB2096:
	.uleb128 .LEHB0-.LFB2096
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB2096
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L79-.LFB2096
	.uleb128 0
	.uleb128 .LEHB2-.LFB2096
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE2096:
	.section	.text._ZNSt6threadC2IRFvvEIEEEOT_DpOT0_,"axG",%progbits,_ZNSt6threadC5IRFvvEIEEEOT_DpOT0_,comdat
	.size	_ZNSt6threadC2IRFvvEIEEEOT_DpOT0_, .-_ZNSt6threadC2IRFvvEIEEEOT_DpOT0_
	.align	3
.LC12:
	.xword	_ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE+16
	.align	3
.LC13:
	.xword	_ZTVNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE+16
	.align	3
.LC14:
	.xword	_ZL28__gthrw___pthread_key_createPjPFvPvE
	.align	3
.LC15:
	.xword	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv
	.weak	_ZNSt6threadC2IRFvvEJEEEOT_DpOT0_
_ZNSt6threadC2IRFvvEJEEEOT_DpOT0_ = _ZNSt6threadC2IRFvvEIEEEOT_DpOT0_
	.weak	_ZNSt6threadC1IRFvvEIEEEOT_DpOT0_
_ZNSt6threadC1IRFvvEIEEEOT_DpOT0_ = _ZNSt6threadC2IRFvvEIEEEOT_DpOT0_
	.weak	_ZNSt6threadC1IRFvvEJEEEOT_DpOT0_
_ZNSt6threadC1IRFvvEJEEEOT_DpOT0_ = _ZNSt6threadC1IRFvvEIEEEOT_DpOT0_
	.section	.text.startup,"ax",%progbits
	.align	2
	.global	main
	.type	main, %function
main:
.LFB2025:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA2025
	stp	x29, x30, [sp, -64]!
	.cfi_def_cfa_offset 64
	.cfi_offset 29, -64
	.cfi_offset 30, -56
	adrp	x1, readboth
	add	x29, sp, 0
	.cfi_def_cfa_register 29
	str	x19, [sp, 16]
	.cfi_offset 19, -48
	adrp	x19, __stack_chk_guard
	add	x2, x19, :lo12:__stack_chk_guard
	add	x1, x1, :lo12:readboth
	add	x0, x29, 40
	ldr	x3, [x2]
	str	x3, [x29, 56]
	mov	x3,0
.LEHB3:
	bl	_ZNSt6threadC1IRFvvEIEEEOT_DpOT0_
.LEHE3:
	adrp	x1, updateboth
	add	x0, x29, 48
	add	x1, x1, :lo12:updateboth
.LEHB4:
	bl	_ZNSt6threadC1IRFvvEIEEEOT_DpOT0_
.LEHE4:
	add	x0, x29, 40
.LEHB5:
	bl	_ZNSt6thread4joinEv
	add	x0, x29, 48
	bl	_ZNSt6thread4joinEv
.LEHE5:
	ldr	x0, [x29, 48]
	cbnz	x0, .L92
	ldr	x0, [x29, 40]
	cbnz	x0, .L92
	add	x19, x19, :lo12:__stack_chk_guard
	ldr	x2, [x29, 56]
	ldr	x1, [x19]
	eor	x1, x2, x1
	cbnz	x1, .L100
	ldr	x19, [sp, 16]
	.cfi_remember_state
	.cfi_restore 19
	ldp	x29, x30, [sp], 64
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa 31, 0
	ret
.L92:
	.cfi_restore_state
	bl	_ZSt9terminatev
.L100:
	bl	__stack_chk_fail
.L97:
	ldr	x1, [x29, 48]
	cbnz	x1, .L92
.L94:
	ldr	x1, [x29, 40]
	cbnz	x1, .L92
.LEHB6:
	bl	_Unwind_Resume
.LEHE6:
.L96:
	b	.L94
	.cfi_endproc
.LFE2025:
	.section	.gcc_except_table,"a",%progbits
.LLSDA2025:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2025-.LLSDACSB2025
.LLSDACSB2025:
	.uleb128 .LEHB3-.LFB2025
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB2025
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L96-.LFB2025
	.uleb128 0
	.uleb128 .LEHB5-.LFB2025
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L97-.LFB2025
	.uleb128 0
	.uleb128 .LEHB6-.LFB2025
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
.LLSDACSE2025:
	.section	.text.startup
	.size	main, .-main
	.weak	_ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE
	.section	.rodata._ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE,"aG",%progbits,_ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE,comdat
	.align	3
	.type	_ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE, %object
	.size	_ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE, 16
_ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE:
	.xword	_ZTVN10__cxxabiv117__class_type_infoE+16
	.xword	_ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE
	.weak	_ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE
	.section	.rodata._ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE,"aG",%progbits,_ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE,comdat
	.align	3
	.type	_ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE, %object
	.size	_ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE, 47
_ZTSSt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE:
	.string	"St11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE"
	.weak	_ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.section	.rodata._ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE,"aG",%progbits,_ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE,comdat
	.align	3
	.type	_ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE, %object
	.size	_ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE, 24
_ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE:
	.xword	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.xword	_ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.xword	_ZTISt11_Mutex_baseILN9__gnu_cxx12_Lock_policyE2EE
	.weak	_ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.section	.rodata._ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE,"aG",%progbits,_ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE,comdat
	.align	3
	.type	_ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE, %object
	.size	_ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE, 52
_ZTSSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE:
	.string	"St16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE"
	.weak	_ZTINSt6thread10_Impl_baseE
	.section	.rodata._ZTINSt6thread10_Impl_baseE,"aG",%progbits,_ZTINSt6thread10_Impl_baseE,comdat
	.align	3
	.type	_ZTINSt6thread10_Impl_baseE, %object
	.size	_ZTINSt6thread10_Impl_baseE, 16
_ZTINSt6thread10_Impl_baseE:
	.xword	_ZTVN10__cxxabiv117__class_type_infoE+16
	.xword	_ZTSNSt6thread10_Impl_baseE
	.weak	_ZTSNSt6thread10_Impl_baseE
	.section	.rodata._ZTSNSt6thread10_Impl_baseE,"aG",%progbits,_ZTSNSt6thread10_Impl_baseE,comdat
	.align	3
	.type	_ZTSNSt6thread10_Impl_baseE, %object
	.size	_ZTSNSt6thread10_Impl_baseE, 24
_ZTSNSt6thread10_Impl_baseE:
	.string	"NSt6thread10_Impl_baseE"
	.weak	_ZTINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE
	.section	.rodata._ZTINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE,"aG",%progbits,_ZTINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE,comdat
	.align	3
	.type	_ZTINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE, %object
	.size	_ZTINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE, 24
_ZTINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE:
	.xword	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.xword	_ZTSNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE
	.xword	_ZTINSt6thread10_Impl_baseE
	.weak	_ZTSNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE
	.section	.rodata._ZTSNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE,"aG",%progbits,_ZTSNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE,comdat
	.align	3
	.type	_ZTSNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE, %object
	.size	_ZTSNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE, 46
_ZTSNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE:
	.string	"NSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE"
	.weak	_ZTSSt19_Sp_make_shared_tag
	.section	.rodata._ZTSSt19_Sp_make_shared_tag,"aG",%progbits,_ZTSSt19_Sp_make_shared_tag,comdat
	.align	3
	.type	_ZTSSt19_Sp_make_shared_tag, %object
	.size	_ZTSSt19_Sp_make_shared_tag, 24
_ZTSSt19_Sp_make_shared_tag:
	.string	"St19_Sp_make_shared_tag"
	.weak	_ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE
	.section	.rodata._ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE,"aG",%progbits,_ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE,comdat
	.align	3
	.type	_ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE, %object
	.size	_ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE, 24
_ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE:
	.xword	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.xword	_ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE
	.xword	_ZTISt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE
	.weak	_ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE
	.section	.rodata._ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE,"aG",%progbits,_ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE,comdat
	.align	3
	.type	_ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE, %object
	.size	_ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE, 111
_ZTSSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE:
	.string	"St23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE"
	.weak	_ZTVNSt6thread10_Impl_baseE
	.section	.rodata._ZTVNSt6thread10_Impl_baseE,"aG",%progbits,_ZTVNSt6thread10_Impl_baseE,comdat
	.align	3
	.type	_ZTVNSt6thread10_Impl_baseE, %object
	.size	_ZTVNSt6thread10_Impl_baseE, 40
_ZTVNSt6thread10_Impl_baseE:
	.xword	0
	.xword	_ZTINSt6thread10_Impl_baseE
	.xword	0
	.xword	0
	.xword	__cxa_pure_virtual
	.weak	_ZTVNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE
	.section	.rodata._ZTVNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE,"aG",%progbits,_ZTVNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE,comdat
	.align	3
	.type	_ZTVNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE, %object
	.size	_ZTVNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE, 40
_ZTVNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE:
	.xword	0
	.xword	_ZTINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEE
	.xword	_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED1Ev
	.xword	_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEED0Ev
	.xword	_ZNSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEE6_M_runEv
	.weak	_ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE
	.section	.rodata._ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE,"aG",%progbits,_ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE,comdat
	.align	3
	.type	_ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE, %object
	.size	_ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE, 56
_ZTVSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE:
	.xword	0
	.xword	_ZTISt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE
	.xword	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED1Ev
	.xword	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EED0Ev
	.xword	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_disposeEv
	.xword	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE10_M_destroyEv
	.xword	_ZNSt23_Sp_counted_ptr_inplaceINSt6thread5_ImplISt12_Bind_simpleIFPFvvEvEEEESaIS7_ELN9__gnu_cxx12_Lock_policyE2EE14_M_get_deleterERKSt9type_info
	.global	b
	.global	a
	.weakref	_ZL28__gthrw___pthread_key_createPjPFvPvE,__pthread_key_create
	.section	.rodata
	.align	3
.LANCHOR1 = . + 0
	.type	_ZZ8readbothE19__PRETTY_FUNCTION__, %object
	.size	_ZZ8readbothE19__PRETTY_FUNCTION__, 16
_ZZ8readbothE19__PRETTY_FUNCTION__:
	.string	"void readboth()"
	.data
	.align	8
.LANCHOR0 = . + 0
	.type	a, %object
	.size	a, 4
a:
	.word	1
	.zero	252
	.type	b, %object
	.size	b, 4
b:
	.word	1
	.section	.rodata.str1.8,"aMS",%progbits,1
	.align	3
.LC0:
	.string	"chasing.cc"
	.zero	5
.LC1:
	.string	"bl <= al"
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.DW.ref.__gxx_personality_v0,"awG",%progbits,DW.ref.__gxx_personality_v0,comdat
	.align	3
	.type	DW.ref.__gxx_personality_v0, %object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.xword	__gxx_personality_v0
	.ident	"GCC: (Ubuntu/Linaro 4.9.1-16ubuntu6) 4.9.1"
	.section	.note.GNU-stack,"",%progbits
