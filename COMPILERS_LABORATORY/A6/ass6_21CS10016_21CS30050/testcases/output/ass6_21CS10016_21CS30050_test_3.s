/*
 * @file ./testcases/output/ass6_21CS10016_21CS30050_test_3.s
 * @brief This file contains the assembly code for the input source file.
 * It is generated by the tinyC Compiler.
Assignment Number 6
Student Information:
 - Bratin Mondal(Roll Number - 21CS10016)
 - Somya Kumar(Roll Number - 21CS30050)
  */

	.file	"./testcases/input/ass6_21CS10016_21CS30050_test_3.c"
	.text
	.section	.rodata
.LC0:
	.string	"\nTesting the absolute_val function\n"
.LC1:
	.string	"absolute_val("
.LC2:
	.string	") = "
.LC3:
	.string	"\n"
.LC4:
	.string	"absolute_val("
.LC5:
	.string	") = "
.LC6:
	.string	"\n"
.LC7:
	.string	"Testing the min function\n"
.LC8:
	.string	"Min("
.LC9:
	.string	", "
.LC10:
	.string	") = "
.LC11:
	.string	"\n"
.LC12:
	.string	"Testing the max function\n"
.LC13:
	.string	"Max("
.LC14:
	.string	", "
.LC15:
	.string	") = "
.LC16:
	.string	"\n"
.LC17:
	.string	"Testing the min_3 function\n"
.LC18:
	.string	"Min_3("
.LC19:
	.string	", "
.LC20:
	.string	", "
.LC21:
	.string	") = "
.LC22:
	.string	"\n"
.LC23:
	.string	"Testing the max_3 function\n"
.LC24:
	.string	"Max_3("
.LC25:
	.string	", "
.LC26:
	.string	", "
.LC27:
	.string	") = "
.LC28:
	.string	"\n"
.LC29:
	.string	"Testing the min_4 function\n"
.LC30:
	.string	"Min_4("
.LC31:
	.string	", "
.LC32:
	.string	", "
.LC33:
	.string	", "
.LC34:
	.string	") = "
.LC35:
	.string	"\n"
.LC36:
	.string	"Testing the max_4 function\n"
.LC37:
	.string	"Max_4("
.LC38:
	.string	", "
.LC39:
	.string	", "
.LC40:
	.string	", "
.LC41:
	.string	") = "
.LC42:
	.string	"\n"
.LC43:
	.float	-1
	.text
	.globl	min
	.type	min, @function
min: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$44, %rsp
	movq	%rdi, -20(%rbp)
	movq	%rsi, -16(%rbp)
	movl	-20(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jg .L1
	jmp .L2
.L1: 
	movl	-16(%rbp), %eax
	movl 	%eax, -28(%rbp)
	jmp .L3
.L2: 
	movl	-20(%rbp), %eax
	movl 	%eax, -28(%rbp)
.L3: 
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq	-24(%rbp), %rax

	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	min, .-min
	.globl	max
	.type	max, @function
max: 
.LFB1:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$44, %rsp
	movq	%rdi, -20(%rbp)
	movq	%rsi, -16(%rbp)
	movl	-20(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl .L4
	jmp .L5
.L4: 
	movl	-16(%rbp), %eax
	movl 	%eax, -28(%rbp)
	jmp .L6
.L5: 
	movl	-20(%rbp), %eax
	movl 	%eax, -28(%rbp)
.L6: 
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq	-24(%rbp), %rax

	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	max, .-max
	.globl	min_3
	.type	min_3, @function
min_3: 
.LFB2:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$56, %rsp
	movq	%rdi, -20(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -12(%rbp)
	movq 	-20(%rbp), %rdi
	movq 	-16(%rbp), %rsi
	call	min
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq 	-24(%rbp), %rdi
	movq 	-12(%rbp), %rsi
	call	min
	movl	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq	-24(%rbp), %rax

	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	min_3, .-min_3
	.globl	max_3
	.type	max_3, @function
max_3: 
.LFB3:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$56, %rsp
	movq	%rdi, -20(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -12(%rbp)
	movq 	-20(%rbp), %rdi
	movq 	-16(%rbp), %rsi
	call	max
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq 	-24(%rbp), %rdi
	movq 	-12(%rbp), %rsi
	call	max
	movl	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq	-24(%rbp), %rax

	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	max_3, .-max_3
	.globl	max_4
	.type	max_4, @function
max_4: 
.LFB4:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$68, %rsp
	movq	%rdi, -20(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -12(%rbp)
	movq	%rcx, -8(%rbp)
	movq 	-20(%rbp), %rdi
	movq 	-16(%rbp), %rsi
	call	max
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq 	-24(%rbp), %rdi
	movq 	-12(%rbp), %rsi
	call	max
	movl	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq 	-24(%rbp), %rdi
	movq 	-8(%rbp), %rsi
	call	max
	movl	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq	-24(%rbp), %rax

	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	max_4, .-max_4
	.globl	min_4
	.type	min_4, @function
min_4: 
.LFB5:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$68, %rsp
	movq	%rdi, -20(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -12(%rbp)
	movq	%rcx, -8(%rbp)
	movq 	-20(%rbp), %rdi
	movq 	-16(%rbp), %rsi
	call	min
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq 	-24(%rbp), %rdi
	movq 	-12(%rbp), %rsi
	call	min
	movl	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq 	-24(%rbp), %rdi
	movq 	-8(%rbp), %rsi
	call	min
	movl	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movq	-24(%rbp), %rax

	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	min_4, .-min_4
	.globl	absolute_val
	.type	absolute_val, @function
absolute_val: 
.LFB6:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$36, %rsp
	movq	%rdi, -20(%rbp)
	movl	$0, %eax
	movl 	%eax, -24(%rbp)
	movl	-20(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jl .L7
	jmp .L8
.L7: 
	movl	-20(%rbp), %eax
	negl	%eax
	movl	%eax, -28(%rbp)

	movq	-28(%rbp), %rax

	jmp .L9
.L8: 
	movq	-20(%rbp), %rax

.L9: 
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE6:
	.size	absolute_val, .-absolute_val
	.globl	main
	.type	main, @function
main: 
.LFB7:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$756, %rsp

	movl	$729, %eax
	movl 	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
	movl	$-1296, %eax
	movl 	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	movl 	%eax, -32(%rbp)
	movl	$1000, %eax
	movl 	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	movl 	%eax, -40(%rbp)
	movq 	$.LC0, -48(%rbp)
	movq 	-48(%rbp), %rdi
	call	printStr
	movl	%eax, -56(%rbp)
	movq 	-24(%rbp), %rdi
	call	absolute_val
	movl	%eax, -64(%rbp)
	movl	-64(%rbp), %eax
	movl 	%eax, -60(%rbp)
	movq 	$.LC1, -68(%rbp)
	movq 	-68(%rbp), %rdi
	call	printStr
	movl	%eax, -76(%rbp)
	movq 	-24(%rbp), %rdi
	call	printInt
	movl	%eax, -80(%rbp)
	movq 	$.LC2, -84(%rbp)
	movq 	-84(%rbp), %rdi
	call	printStr
	movl	%eax, -92(%rbp)
	movq 	-60(%rbp), %rdi
	call	printInt
	movl	%eax, -96(%rbp)
	movq 	$.LC3, -100(%rbp)
	movq 	-100(%rbp), %rdi
	call	printStr
	movl	%eax, -108(%rbp)
	movq 	-32(%rbp), %rdi
	call	absolute_val
	movl	%eax, -116(%rbp)
	movl	-116(%rbp), %eax
	movl 	%eax, -112(%rbp)
	movq 	$.LC4, -120(%rbp)
	movq 	-120(%rbp), %rdi
	call	printStr
	movl	%eax, -128(%rbp)
	movq 	-32(%rbp), %rdi
	call	printInt
	movl	%eax, -132(%rbp)
	movq 	$.LC5, -136(%rbp)
	movq 	-136(%rbp), %rdi
	call	printStr
	movl	%eax, -144(%rbp)
	movq 	-112(%rbp), %rdi
	call	printInt
	movl	%eax, -148(%rbp)
	movq 	$.LC6, -152(%rbp)
	movq 	-152(%rbp), %rdi
	call	printStr
	movl	%eax, -160(%rbp)
	movq 	-24(%rbp), %rdi
	movq 	-32(%rbp), %rsi
	call	min
	movl	%eax, -168(%rbp)
	movl	-168(%rbp), %eax
	movl 	%eax, -164(%rbp)
	movq 	$.LC7, -172(%rbp)
	movq 	-172(%rbp), %rdi
	call	printStr
	movl	%eax, -180(%rbp)
	movq 	$.LC8, -184(%rbp)
	movq 	-184(%rbp), %rdi
	call	printStr
	movl	%eax, -192(%rbp)
	movq 	-24(%rbp), %rdi
	call	printInt
	movl	%eax, -196(%rbp)
	movq 	$.LC9, -200(%rbp)
	movq 	-200(%rbp), %rdi
	call	printStr
	movl	%eax, -208(%rbp)
	movq 	-32(%rbp), %rdi
	call	printInt
	movl	%eax, -212(%rbp)
	movq 	$.LC10, -216(%rbp)
	movq 	-216(%rbp), %rdi
	call	printStr
	movl	%eax, -224(%rbp)
	movq 	-164(%rbp), %rdi
	call	printInt
	movl	%eax, -228(%rbp)
	movq 	$.LC11, -232(%rbp)
	movq 	-232(%rbp), %rdi
	call	printStr
	movl	%eax, -240(%rbp)
	movq 	-24(%rbp), %rdi
	movq 	-32(%rbp), %rsi
	call	max
	movl	%eax, -248(%rbp)
	movl	-248(%rbp), %eax
	movl 	%eax, -244(%rbp)
	movq 	$.LC12, -252(%rbp)
	movq 	-252(%rbp), %rdi
	call	printStr
	movl	%eax, -260(%rbp)
	movq 	$.LC13, -264(%rbp)
	movq 	-264(%rbp), %rdi
	call	printStr
	movl	%eax, -272(%rbp)
	movq 	-24(%rbp), %rdi
	call	printInt
	movl	%eax, -276(%rbp)
	movq 	$.LC14, -280(%rbp)
	movq 	-280(%rbp), %rdi
	call	printStr
	movl	%eax, -288(%rbp)
	movq 	-32(%rbp), %rdi
	call	printInt
	movl	%eax, -292(%rbp)
	movq 	$.LC15, -296(%rbp)
	movq 	-296(%rbp), %rdi
	call	printStr
	movl	%eax, -304(%rbp)
	movq 	-244(%rbp), %rdi
	call	printInt
	movl	%eax, -308(%rbp)
	movq 	$.LC16, -312(%rbp)
	movq 	-312(%rbp), %rdi
	call	printStr
	movl	%eax, -320(%rbp)
	movq 	-24(%rbp), %rdi
	movq 	-32(%rbp), %rsi
	movq 	-40(%rbp), %rdx
	call	min_3
	movl	%eax, -328(%rbp)
	movl	-328(%rbp), %eax
	movl 	%eax, -324(%rbp)
	movq 	$.LC17, -332(%rbp)
	movq 	-332(%rbp), %rdi
	call	printStr
	movl	%eax, -340(%rbp)
	movq 	$.LC18, -344(%rbp)
	movq 	-344(%rbp), %rdi
	call	printStr
	movl	%eax, -352(%rbp)
	movq 	-24(%rbp), %rdi
	call	printInt
	movl	%eax, -356(%rbp)
	movq 	$.LC19, -360(%rbp)
	movq 	-360(%rbp), %rdi
	call	printStr
	movl	%eax, -368(%rbp)
	movq 	-32(%rbp), %rdi
	call	printInt
	movl	%eax, -372(%rbp)
	movq 	$.LC20, -376(%rbp)
	movq 	-376(%rbp), %rdi
	call	printStr
	movl	%eax, -384(%rbp)
	movq 	-40(%rbp), %rdi
	call	printInt
	movl	%eax, -388(%rbp)
	movq 	$.LC21, -392(%rbp)
	movq 	-392(%rbp), %rdi
	call	printStr
	movl	%eax, -400(%rbp)
	movq 	-324(%rbp), %rdi
	call	printInt
	movl	%eax, -404(%rbp)
	movq 	$.LC22, -408(%rbp)
	movq 	-408(%rbp), %rdi
	call	printStr
	movl	%eax, -416(%rbp)
	movq 	-24(%rbp), %rdi
	movq 	-32(%rbp), %rsi
	movq 	-40(%rbp), %rdx
	call	max_3
	movl	%eax, -424(%rbp)
	movl	-424(%rbp), %eax
	movl 	%eax, -420(%rbp)
	movq 	$.LC23, -428(%rbp)
	movq 	-428(%rbp), %rdi
	call	printStr
	movl	%eax, -436(%rbp)
	movq 	$.LC24, -440(%rbp)
	movq 	-440(%rbp), %rdi
	call	printStr
	movl	%eax, -448(%rbp)
	movq 	-24(%rbp), %rdi
	call	printInt
	movl	%eax, -452(%rbp)
	movq 	$.LC25, -456(%rbp)
	movq 	-456(%rbp), %rdi
	call	printStr
	movl	%eax, -464(%rbp)
	movq 	-32(%rbp), %rdi
	call	printInt
	movl	%eax, -468(%rbp)
	movq 	$.LC26, -472(%rbp)
	movq 	-472(%rbp), %rdi
	call	printStr
	movl	%eax, -480(%rbp)
	movq 	-40(%rbp), %rdi
	call	printInt
	movl	%eax, -484(%rbp)
	movq 	$.LC27, -488(%rbp)
	movq 	-488(%rbp), %rdi
	call	printStr
	movl	%eax, -496(%rbp)
	movq 	-420(%rbp), %rdi
	call	printInt
	movl	%eax, -500(%rbp)
	movq 	$.LC28, -504(%rbp)
	movq 	-504(%rbp), %rdi
	call	printStr
	movl	%eax, -512(%rbp)
	movl	$313, %eax
	movl 	%eax, -520(%rbp)
	movl	-520(%rbp), %eax
	movl 	%eax, -516(%rbp)
	movq 	-24(%rbp), %rdi
	movq 	-32(%rbp), %rsi
	movq 	-40(%rbp), %rdx
	movq 	-516(%rbp), %rcx
	call	min_4
	movl	%eax, -532(%rbp)
	movl	-532(%rbp), %eax
	movl 	%eax, -528(%rbp)
	movq 	$.LC29, -536(%rbp)
	movq 	-536(%rbp), %rdi
	call	printStr
	movl	%eax, -544(%rbp)
	movq 	$.LC30, -548(%rbp)
	movq 	-548(%rbp), %rdi
	call	printStr
	movl	%eax, -556(%rbp)
	movq 	-24(%rbp), %rdi
	call	printInt
	movl	%eax, -560(%rbp)
	movq 	$.LC31, -564(%rbp)
	movq 	-564(%rbp), %rdi
	call	printStr
	movl	%eax, -572(%rbp)
	movq 	-32(%rbp), %rdi
	call	printInt
	movl	%eax, -576(%rbp)
	movq 	$.LC32, -580(%rbp)
	movq 	-580(%rbp), %rdi
	call	printStr
	movl	%eax, -588(%rbp)
	movq 	-40(%rbp), %rdi
	call	printInt
	movl	%eax, -592(%rbp)
	movq 	$.LC33, -596(%rbp)
	movq 	-596(%rbp), %rdi
	call	printStr
	movl	%eax, -604(%rbp)
	movq 	-516(%rbp), %rdi
	call	printInt
	movl	%eax, -608(%rbp)
	movq 	$.LC34, -612(%rbp)
	movq 	-612(%rbp), %rdi
	call	printStr
	movl	%eax, -620(%rbp)
	movq 	-528(%rbp), %rdi
	call	printInt
	movl	%eax, -624(%rbp)
	movq 	$.LC35, -628(%rbp)
	movq 	-628(%rbp), %rdi
	call	printStr
	movl	%eax, -636(%rbp)
	movq 	-24(%rbp), %rdi
	movq 	-32(%rbp), %rsi
	movq 	-40(%rbp), %rdx
	movq 	-516(%rbp), %rcx
	call	max_4
	movl	%eax, -644(%rbp)
	movl	-644(%rbp), %eax
	movl 	%eax, -640(%rbp)
	movq 	$.LC36, -648(%rbp)
	movq 	-648(%rbp), %rdi
	call	printStr
	movl	%eax, -656(%rbp)
	movq 	$.LC37, -660(%rbp)
	movq 	-660(%rbp), %rdi
	call	printStr
	movl	%eax, -668(%rbp)
	movq 	-24(%rbp), %rdi
	call	printInt
	movl	%eax, -672(%rbp)
	movq 	$.LC38, -676(%rbp)
	movq 	-676(%rbp), %rdi
	call	printStr
	movl	%eax, -684(%rbp)
	movq 	-32(%rbp), %rdi
	call	printInt
	movl	%eax, -688(%rbp)
	movq 	$.LC39, -692(%rbp)
	movq 	-692(%rbp), %rdi
	call	printStr
	movl	%eax, -700(%rbp)
	movq 	-40(%rbp), %rdi
	call	printInt
	movl	%eax, -704(%rbp)
	movq 	$.LC40, -708(%rbp)
	movq 	-708(%rbp), %rdi
	call	printStr
	movl	%eax, -716(%rbp)
	movq 	-516(%rbp), %rdi
	call	printInt
	movl	%eax, -720(%rbp)
	movq 	$.LC41, -724(%rbp)
	movq 	-724(%rbp), %rdi
	call	printStr
	movl	%eax, -732(%rbp)
	movq 	-640(%rbp), %rdi
	call	printInt
	movl	%eax, -736(%rbp)
	movq 	$.LC42, -740(%rbp)
	movq 	-740(%rbp), %rdi
	call	printStr
	movl	%eax, -748(%rbp)
	movl	$0, %eax
	movl 	%eax, -752(%rbp)
	movq	-752(%rbp), %rax

	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
