/*
 * @file ./testcases/output/ass6_21CS10016_21CS30050_test_6.s
 * @brief This file contains the assembly code for the input source file.
 * It is generated by the tinyC Compiler.
Assignment Number 6
Student Information:
 - Bratin Mondal(Roll Number - 21CS10016)
 - Somya Kumar(Roll Number - 21CS30050)
  */

	.file	"./testcases/input/ass6_21CS10016_21CS30050_test_6.c"
	.text
	.globl	waste_float_d.Global
	.data
	.align 4
	.type	waste_float_d.Global, @object
	.size	waste_float_d.Global, 4
waste_float_d.Global:
	.float	2.3
	.globl	t_1
	.data
	.align 4
	.type	t_1, @object
	.size	t_1, 4
t_1:
	.float	2.3
	.comm	waste_char1.Global, 1, 1
	.comm	waste_int1.Global, 4, 4
	.comm	waste_int2.Global, 4, 4
	.globl	a.Global
	.data
	.align 4
	.type	a.Global, @object
	.size	a.Global, 4
a.Global:
	.long	4
	.globl	t_2
	.data
	.align 4
	.type	t_2, @object
	.size	t_2, 4
t_2:
	.long	4
	.comm	p.Global, 8, 8
	.comm	b.Global, 4, 4
	.section	.rodata
.LC0:
	.string	"Entered for iteration "
.LC1:
	.string	"\n"
.LC2:
	.string	"\nScope 1: "
.LC3:
	.string	"\nScope 2: "
.LC4:
	.string	"\nw==3\n"
.LC5:
	.string	"\nScope 3: "
.LC6:
	.string	"\n"
	.section	.rodata
.LC7:
	.float	2.3
.LC8:
	.float	-1
	.text
	movss	.LC7(%rip), %xmm0
	movss	%xmm0, 0(%rbp)

	movss	0(%rbp), %xmm0
	movss	%xmm0, 0(%rbp)

	movl	$4, %eax
	movl 	%eax, 0(%rbp)
	movl	0(%rbp), %eax
	movl 	%eax, 0(%rbp)
	.globl	main
	.type	main, @function
main: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$180, %rsp

	movl	$1, %eax
	movl 	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
.L1: 
	movq 	$.LC0, -32(%rbp)
	movq 	-32(%rbp), %rdi
	call	printStr
	movl	%eax, -40(%rbp)
	movl	-24(%rbp), %eax
	movl 	%eax, -44(%rbp)
	movl	-24(%rbp), %eax
	incl	%eax
	movl	%eax, -24(%rbp)

	movq 	-44(%rbp), %rdi
	call	printInt
	movl	%eax, -48(%rbp)
	movq 	$.LC1, -52(%rbp)
	movq 	-52(%rbp), %rdi
	call	printStr
	movl	%eax, -60(%rbp)
	movl	$10, %eax
	movl 	%eax, -64(%rbp)
	movl	-24(%rbp), %eax
	cmpl	-64(%rbp), %eax
	jl .L1
	jmp .L2
.L2: 
	nop
	movl	$10, %eax
	movl 	%eax, -76(%rbp)
	movl	-76(%rbp), %eax
	movl 	%eax, -72(%rbp)
	movq 	$.LC2, -80(%rbp)
	movq 	-80(%rbp), %rdi
	call	printStr
	movl	%eax, -88(%rbp)
	movq 	-72(%rbp), %rdi
	call	printInt
	movl	%eax, -92(%rbp)
	nop
	movl	$2, %eax
	movl 	%eax, -100(%rbp)
	movl	-100(%rbp), %eax
	movl 	%eax, -96(%rbp)
	movq 	$.LC3, -104(%rbp)
	movq 	-104(%rbp), %rdi
	call	printStr
	movl	%eax, -112(%rbp)
	movq 	-96(%rbp), %rdi
	call	printInt
	movl	%eax, -116(%rbp)
	nop
	movl	$3, %eax
	movl 	%eax, -124(%rbp)
	movl	-124(%rbp), %eax
	movl 	%eax, -120(%rbp)
	movl	$3, %eax
	movl 	%eax, -128(%rbp)
	movl	-120(%rbp), %eax
	cmpl	-128(%rbp), %eax
	je .L3
	jmp .L4
.L3: 
	nop
	movq 	$.LC4, -160(%rbp)
	movq 	-160(%rbp), %rdi
	call	printStr
	movl	%eax, -168(%rbp)
	movl	$4, %eax
	movl 	%eax, -172(%rbp)
	movl	-172(%rbp), %eax
	movl 	%eax, -120(%rbp)
	jmp .L4
.L4: 
	movq 	$.LC5, -132(%rbp)
	movq 	-132(%rbp), %rdi
	call	printStr
	movl	%eax, -140(%rbp)
	movq 	-120(%rbp), %rdi
	call	printInt
	movl	%eax, -144(%rbp)
	movq 	$.LC6, -148(%rbp)
	movq 	-148(%rbp), %rdi
	call	printStr
	movl	%eax, -156(%rbp)
	movl	$0, %eax
	movl 	%eax, -68(%rbp)
	movq	-68(%rbp), %rax

	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
