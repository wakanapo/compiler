	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_increment
	.align	4, 0x90
_increment:                             ## @increment
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
	movq	_y@GOTPCREL(%rip), %rax
	movq	_x@GOTPCREL(%rip), %rcx
	movl	(%rcx), %edx
	addl	$1234, %edx             ## imm = 0x4D2
	movl	%edx, (%rax)
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.comm	_x,4,2                  ## @x
	.comm	_y,4,2                  ## @y

.subsections_via_symbols
