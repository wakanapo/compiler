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
	movl	$100, %edi
	movl	$200, %esi
	movl	$300, %edx              ## imm = 0x12C
	movl	$400, %ecx              ## imm = 0x190
	movl	$500, %r8d              ## imm = 0x1F4
	movl	$600, %r9d              ## imm = 0x258
	movb	$0, %al
	callq	_f
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
