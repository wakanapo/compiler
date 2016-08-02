	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_g
	.align	4, 0x90
_g:                                     ## @g
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
	movq	_x@GOTPCREL(%rip), %r10
	movl	%edi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movl	%r8d, -24(%rbp)
	movl	%r9d, -28(%rbp)
	movl	-8(%rbp), %ecx
	addl	-12(%rbp), %ecx
	addl	-16(%rbp), %ecx
	movl	%ecx, (%r10)
	movl	-20(%rbp), %ecx
	addl	-24(%rbp), %ecx
	addl	-28(%rbp), %ecx
	movl	%ecx, (%rax)
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.comm	_x,4,2                  ## @x
	.comm	_y,4,2                  ## @y

.subsections_via_symbols
