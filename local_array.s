	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_f
	.align	4, 0x90
_f:                                     ## @f
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rcx
	movq	%rcx, -8(%rbp)
	movl	%edi, -36(%rbp)
	movl	%esi, -40(%rbp)
	movl	%edx, -44(%rbp)
	movl	-44(%rbp), %edx
	movslq	-36(%rbp), %rcx
	movl	%edx, -32(%rbp,%rcx,4)
	movslq	-40(%rbp), %rcx
	movl	-32(%rbp,%rcx,4), %edx
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	movl	%edx, -48(%rbp)         ## 4-byte Spill
	jne	LBB0_2
## BB#1:                                ## %SP_return
	movl	-48(%rbp), %eax         ## 4-byte Reload
	addq	$48, %rsp
	popq	%rbp
	retq
LBB0_2:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc


.subsections_via_symbols
