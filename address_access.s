	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_foo
	.align	4, 0x90
_foo:                                   ## @foo
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
	subq	$64, %rsp
	movl	$1, %eax
	movl	%eax, %edi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -8(%rbp)
	callq	_malloc
	leaq	L_.str(%rip), %rdi
	leaq	-25(%rbp), %rsi
	movq	_D@GOTPCREL(%rip), %r8
	leaq	-18(%rbp), %rdx
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rcx
	callq	_f
	leaq	L_.str1(%rip), %rsi
	movl	$10, %r9d
	movl	%r9d, %edx
	leaq	-18(%rbp), %rdi
	movb	%al, -41(%rbp)          ## 1-byte Spill
	callq	___strcpy_chk
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movl	-24(%rbp), %r9d
	movq	(%rcx), %rcx
	cmpq	-8(%rbp), %rcx
	movq	%rax, -56(%rbp)         ## 8-byte Spill
	movl	%r9d, -60(%rbp)         ## 4-byte Spill
	jne	LBB0_2
## BB#1:                                ## %SP_return
	movl	-60(%rbp), %eax         ## 4-byte Reload
	addq	$64, %rsp
	popq	%rbp
	retq
LBB0_2:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.globl	_f
	.align	4, 0x90
_f:                                     ## @f
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
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	%rdx, -32(%rbp)
	movq	%rcx, -40(%rbp)
	movq	%r8, -48(%rbp)
	movq	-16(%rbp), %rcx
	movsbl	2(%rcx), %eax
	movq	-24(%rbp), %rcx
	movsbl	2(%rcx), %r9d
	cmpl	%r9d, %eax
	jne	LBB1_2
## BB#1:
	movq	-32(%rbp), %rax
	movb	2(%rax), %cl
	movb	%cl, -1(%rbp)
	jmp	LBB1_3
LBB1_2:
	movq	-40(%rbp), %rax
	movsbl	2(%rax), %ecx
	movq	-48(%rbp), %rax
	movsbl	2(%rax), %edx
	addl	%edx, %ecx
	movb	%cl, %sil
	movb	%sil, -1(%rbp)
LBB1_3:
	movsbl	-1(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"hello world\n"

	.comm	_D,100,4                ## @D
L_.str1:                                ## @.str1
	.asciz	"dear sir.\n"


.subsections_via_symbols
