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
	subq	$32, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movb	$0, %al
	callq	_aa
	movl	%eax, -16(%rbp)
	movb	$0, %al
	callq	_bb
	movl	%eax, -20(%rbp)
	movb	$0, %al
	callq	_cc
	movl	%eax, -24(%rbp)
	movl	-16(%rbp), %eax
	imull	-4(%rbp), %eax
	movl	-20(%rbp), %edx
	imull	-8(%rbp), %edx
	addl	%edx, %eax
	movl	-24(%rbp), %edx
	imull	-12(%rbp), %edx
	addl	%edx, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
