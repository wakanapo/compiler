	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_return_123
	.align	4, 0x90
_return_123:                            ## @return_123
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
	movl	$123, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_return_456
	.align	4, 0x90
_return_456:                            ## @return_456
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	movl	$456, %eax              ## imm = 0x1C8
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_return_789
	.align	4, 0x90
_return_789:                            ## @return_789
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	movl	$789, %eax              ## imm = 0x315
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
