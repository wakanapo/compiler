	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.section	__TEXT,__literal8,8byte_literals
	.align	3
LCPI0_0:
	.quad	4646741967558095667     ## double 456.69999999999999
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_return_456_7
	.align	4, 0x90
_return_456_7:                          ## @return_456_7
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
	movsd	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
