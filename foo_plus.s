	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_foo_plus_13
	.align	4, 0x90
_foo_plus_13:                           ## @foo_plus_13
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
	movb	$0, %al
	callq	_foo
	addl	$13, %eax
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
