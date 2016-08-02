	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_increment_array
	.align	4, 0x90
_increment_array:                       ## @increment_array
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
	movq	_z@GOTPCREL(%rip), %rcx
	movl	400(%rcx), %edx
	addl	$1234, %edx             ## imm = 0x4D2
	movl	%edx, (%rax)
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.comm	_z,4000,4               ## @z
	.comm	_y,4,2                  ## @y

.subsections_via_symbols
