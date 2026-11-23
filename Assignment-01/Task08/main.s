	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"RURAL ELECTRICITY BILL"
.LC1:
	.string	"Invalid units"
.LC2:
	.string	"%3d units -> Rs. %ld.%02ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -32(%rbp)
	movl	$100, -28(%rbp)
	movl	$150, -24(%rbp)
	movl	$200, -20(%rbp)
	movl	$350, -16(%rbp)
	movl	$5, -44(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -48(%rbp)
	jmp	.L2
.L5:
	movl	-48(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %eax
	movl	%eax, %edi
	call	calculate_bill_paise@PLT
	movq	%rax, -40(%rbp)
	cmpq	$0, -40(%rbp)
	jns	.L3
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L4
.L3:
	movq	-40(%rbp), %rcx
	movabsq	$-6640827866535438581, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	leaq	(%rdx,%rcx), %rax
	sarq	$6, %rax
	movq	%rax, %rdx
	movq	%rcx, %rax
	sarq	$63, %rax
	movq	%rdx, %rsi
	subq	%rax, %rsi
	imulq	$100, %rsi, %rax
	movq	%rcx, %rsi
	subq	%rax, %rsi
	movq	-40(%rbp), %rcx
	movabsq	$-6640827866535438581, %rdx
	movq	%rcx, %rax
	imulq	%rdx
	leaq	(%rdx,%rcx), %rax
	sarq	$6, %rax
	movq	%rax, %rdx
	movq	%rcx, %rax
	sarq	$63, %rax
	subq	%rax, %rdx
	movl	-48(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %eax
	leaq	.LC2(%rip), %rdi
	movq	%rsi, %rcx
	movl	%eax, %esi
	movl	$0, %eax
	call	printf@PLT
	movl	-48(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %eax
	movq	-40(%rbp), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	print_debug_info@PLT
.L4:
	addl	$1, -48(%rbp)
.L2:
	movl	-48(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jl	.L5
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 15.2.0-16ubuntu1) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
