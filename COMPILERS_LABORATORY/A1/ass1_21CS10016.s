# ---------------------------------------------------------------- #
# ---------------------------------------------------------------- #
# Bratin Mondal
# 21CS10016   
# Compilers Assignment - 1
# ---------------------------------------------------------------- #
# ---------------------------------------------------------------- #
	.file	"code.c"											  # The Source File Name
	.text														  # It indicates that the below section is of type text
	.globl	calculateFrequency									  # calculateFrequency is declared as global here, means can be referred to and accessed from other parts of the program
	.type	calculateFrequency, @function						  # Type of calculateFrequency is specified as function here
calculateFrequency:												  # The start of description of function Calculate Frequency
.LFB0:															  # Start of the function prologue
	.cfi_startproc												  # Call frame information. Start of the procedure
	endbr64														  # End branch									  
	pushq	%rbp												  # Put the base pointer in the stack (Save the base pointer)
	.cfi_def_cfa_offset 16										  # Set CFA to use offset of 16
	.cfi_offset 6, -16 											  # Set rule to set register 6 at offset of -16 from CFI
	movq	%rsp, %rbp											  # rbp <-- rsp. Stack pointer is moved to the base pointer. Executed at the begining of the function
	.cfi_def_cfa_register 6										  # Set CFA register to register number 6
	movq	%rdi, -24(%rbp)										  # Copy %rdi to -24(%rbp). It is to save the first argument (arr1[]) in -24(%rbp)
	movl	%esi, -28(%rbp)										  # Copy %esi to -28(%rbp). It is to save the second argument (n) in -28(%rbp)
	movq	%rdx, -40(%rbp)										  # Copy %rdx to -40(%rbp). It is to save the third argument (fr1[]) -40(%rrbp)
	movl	$0, -12(%rbp)										  # Copy 0 to -12(%rbp). It is to initialize i(Outer loop iterator) at -12(%rbp) with 0 
	jmp	.L2														  # Jump to .L2 where condition checking is done to see if the outer loop needs to continue
.L7:															  # Starting of Outer Loop
	movl	$1, -4(%rbp)										  # Copy 1 to -4(%rbp). It is to initialize ctr(Frquency counter) at -4(%rbp) with 1. Executes the statement ctr = 1
	movl	-12(%rbp), %eax										  # Copy -12(%rbp) to %eax. It is to load i at %eax
	addl	$1, %eax											  # Add 1 to %eax. It is to increment i by 1
	movl	%eax, -8(%rbp)										  # Copy %eax to -8(%rbp). It is to save the updated value of i in -8(%rbp)
	jmp	.L3														  # Jump to L3 at the start of the inner loop	
.L5:															  # Inner Loop instructions
	movl	-12(%rbp), %eax										  # Copy -12(%rbp) to %eax. It is to load i at %eax
	cltq														  # Convert long to quad
	leaq	0(,%rax,4), %rdx								  	  # Calculate the distance of arr1[i] which needs to be added to address of arr1[] to get the element access at arr1[i]
	movq	-24(%rbp), %rax									   	  # Copy -24(%rbp) to %rax. It is to load address of arr1[] at %rax
	addq	%rdx, %rax											  # Add %rdx to %rax. It is to get the address of arr1[i] at %rax
	movl	(%rax), %edx										  # Copy (%rax) to %edx. It is to load arr1[i] into %edx
	movl	-8(%rbp), %eax										  # Copy -8(%rbp) to %eax. It is to load j in %eax
	cltq														  # Convert long to quad
	leaq	0(,%rax,4), %rcx									  # Calculate the distance of arr1[j] which needs to be added to address of arr1[] to get the element access at arr1[j]
	movq	-24(%rbp), %rax										  # Copy -24(%rbp) to %rax. It is to load address of arr1[] in %rax
	addq	%rcx, %rax											  # Add %rcx to %rax. It is to get the address of arr1[j] in %rax
	movl	(%rax), %eax										  # Copy (%rax) to %eax. It is to load arr1[j] in %eax
	cmpl	%eax, %edx											  # Compare %eax with %edx. It compares arr1[i] with arr1[j] for the statement if(arr1[i]==arr1[j])
	jne	.L4														  # Jump to .L4 if arr1[i]!=arr[j] (Jump on not equal)
	addl	$1, -4(%rbp)										  # Add 1 to -4(%rbp). It is to increment ctr by 1
	movl	-8(%rbp), %eax										  # Copy -8(%rbp) to %eax. It is to load j in %eax
	cltq														  # Convert long to quad
	leaq	0(,%rax,4), %rdx									  # Calculate the distance of fr1[j] which needs to be added to address of fr1[] to get the element access at fr1[j]
	movq	-40(%rbp), %rax										  # Copy -40(%rbp) to %rax. It is to load address of fr1[] in %rax
	addq	%rdx, %rax											  # Add %rdx to %rax. It is to calculate address of fr1[j] in %rax
	movl	$0, (%rax)											  # Copy 0 to (%rax). Set the value at fr1[j] to 0
.L4:															  # Incrementing j (For going to next iteration of inner loop)
	addl	$1, -8(%rbp)										  #	Add 1 to -8(%rbp). Incrementing j by 1
.L3:															  # Checking if inner loop needs to continue and then either continue it or goes to other section of the outer loop
	movl	-8(%rbp), %eax										  # Copy -8(%rbp) to %eax. It is to load j in %eax
	cmpl	-28(%rbp), %eax										  # Compare -28(%rbp) with %eax. It is to compare j with n in the innner loop terminating condition
	jl	.L5														  # Jump to .L5. If j < n it is to continue with the next iteration of the loop. (Jump if less)
	movl	-12(%rbp), %eax										  # Copy -12(%rbp) to %eax. It is to load i in %eax
	cltq														  # Convert long to quad
	leaq	0(,%rax,4), %rdx									  # Calculate the distance of fr1[i] which needs to be added to address of fr1[] to get the element access at fr1[i]
	movq	-40(%rbp), %rax										  # Copy -40(%rbp) to %rax. It is to load the address of fr1[] in %rax
	addq	%rdx, %rax											  # Add %%rdx to %rax. It is to calculate the address of fr1[i] in %rax
	movl	(%rax), %eax										  # Copy to (%rax) to %eax. It is to load fr1[i] in %eax
	testl	%eax, %eax											  # Compute bitwise and of value at %eax. It is effectively checking whether fr1[i] is non-zero
	je	.L6														  # If the result of the above operation is zero, move to .L6  It means moving to .L6 if fr1[i] is zero
	movl	-12(%rbp), %eax										  # Copy -12(%rbp) to eax. This is to load i in %eax
	cltq														  # Convert long to quad
	leaq	0(,%rax,4), %rdx									  # Calculate the distance of fr1[i] which needs to be added to address of fr1[] to get the element access at fr1[i]
	movq	-40(%rbp), %rax										  # Copy -40(%rbp) to %rax. It is to load the address of fr1[] in %rax
	addq	%rax, %rdx											  # Add %rax to %rdx. It calculates the address of fr1[i] in %rdx
	movl	-4(%rbp), %eax										  # Copy -4(%rbp) to %eax. It loads the value of ctr  in %eax
	movl	%eax, (%rdx)										  # Copy %eax to (%rdx). It assigns the value of ctr to fr1[i]
.L6:															  # Incrementing i after iteration of outer loop
	addl	$1, -12(%rbp)										  # Add 1 to -12(%rbp). It is to increase the value of i after eaxh iteration of the outer loop
.L2:															  # To check if the outer loop needs to continue
	movl	-12(%rbp), %eax										  # Copy from -12(%rbp) to %eax. It is to load the value of i in %eax
	cmpl	-28(%rbp), %eax										  # Compare between -28(%rbp) and %eax. It compares i and n at the end of each iteration of the outer loop
	jl	.L7														  # Jump to .L7 if the condition is met. Effectively jump to the next iteration of outer loop if i<n
	nop               											  # No operation
	nop															  # No operation
	popq	%rbp												  # Pop %rbp. It restores the base pointer
	.cfi_def_cfa 7, 8											  # Define the new value of the Canonical Frame Address
	ret															  # Return from the function
	.cfi_endproc												  # Call frame information. End of the procedure
.LFE0:															  # End of calculateFrequency function
	.size	calculateFrequency, .-calculateFrequency			  # Set the size of the calculateFrequency function by substracting the start from the end
	.section	.rodata											  # Start of read-only data section
.LC0:															  # First string label to print in printArrayWithFrequency function
	.string	"Element\tFrequency"								  # Defining the content of the string "Element\tFrequency"	
.LC1:															  # Second string label to print in printArrayWithFrequency function
	.string	"%d\t%d\n"											  # Defining the content of the string "%d\t%d\n"	
	.text														  # It indicates that the below section is of type text
	.globl	printArrayWithFrequency								  # printArrayWithFrequency is declared as global here, means can be referred to and accessed from other parts of the program
	.type	printArrayWithFrequency, @function					  # printArrayWithFrequency type is specified as function here
printArrayWithFrequency:										  # Function printArrayWithFrequency
.LFB1:															  # Start of the function prologue
	.cfi_startproc												  # Call frame information. Start of the procedure
	endbr64														  # End branch
	pushq	%rbp												  # Put the base pointer in the stack (Save the base pointer)
	.cfi_def_cfa_offset 16										  # Set CFA to use offset of 16
	.cfi_offset 6, -16											  # Set rule to set register 6 at offset of -16 from CFI
	movq	%rsp, %rbp											  # rbp <-- rsp. Stack pointer is moved to the base pointer
	.cfi_def_cfa_register 6										  # Set CFA register to register number 6
	subq	$48, %rsp											  # Reserve 48 bytes for local variables in the fucntion printArrayWithFrequency
	movq	%rdi, -24(%rbp)										  # Copy %rdi to -24(%rbp). It is to save the first argument arr1[]
	movq	%rsi, -32(%rbp)										  # Copy %rsi to -32(%rbp). It is to save the second argument fr1[]
	movl	%edx, -36(%rbp)										  # Copy %edx to -36(%rbp). It is to save the third argument n
	leaq	.LC0(%rip), %rdi									  # Load the address of a string constant ".LC0" into the first argument register (rdi) for printing
	call	puts@PLT											  # Call the puts function to print the string stored at the address in rdi. printf("Element\tFrequency\n");
	movl	$0, -4(%rbp)										  # Copy 0 to -4(%rbp). Initialize the loop variable i with 0
	jmp	.L9														  # Jump to .L9 . Jump to the start of the loop
.L11:															  # The for loop executions
	movl	-4(%rbp), %eax										  # Copy -4(%rbp) to %eax. It is to load in %eax
	cltq														  # Convert long to quad
	leaq	0(,%rax,4), %rdx									  # Calculate the distance of fr1[i] which needs to be added to address of fr1[] to get the element access at fr1[i]
	movq	-32(%rbp), %rax										  # Copy -32(%rbp) to %rax. Load address of fr1[] in %rax
	addq	%rdx, %rax											  # Add %rdx to %rax. Calculate the address of fr1[i]
	movl	(%rax), %eax										  # Copy the value from %rax to %eax. It loads the value at fr1[i] in %eax
	testl	%eax, %eax											  # Compute bitwise and of value at %eax. It is effectively checking whether fr1[i] is non-zero
	je	.L10													  # Jump on equal to .L10 . Jump to .L10 if f1[i] is zero
	movl	-4(%rbp), %eax										  # Copy -4(%rbp) to %eax. It loads i in %eax
	cltq														  # Convert long to quad
	leaq	0(,%rax,4), %rdx									  # Calculate the distance of arr1[i] which needs to be added to address of arr1[] to get the element access at arr1[i]
	movq	-32(%rbp), %rax										  # Copy from -32(%rbp) to %rax. It loads the address of arr1[] in %rax
	addq	%rdx, %rax											  # Add %rdx to %rax. Calculate the address of arr1[i]
	movl	(%rax), %edx										  # Copy from (%rax) to %edx. Load arr1[i] into %edx
	movl	-4(%rbp), %eax										  # Copy -4(%rbp) to %eax. It loads i in %eax
	cltq														  # Convert long to quad
	leaq	0(,%rax,4), %rcx									  # Calculate the distance of fr1[i] which needs to be added to address of fr1[] to get the element access at fr1[i]
	movq	-24(%rbp), %rax										  # Copy from -24(%rbp) to %rax. It loads the address of fr1[] in %rax
	addq	%rcx, %rax											  # Add %rcx to %rax. Calculate the address of fr1[i]
	movl	(%rax), %eax										  # Copy from %rax to %eax. Load fr1[i] into %eax
	movl	%eax, %esi											  # Copy from %eax to %esi. Load element for printing
	leaq	.LC1(%rip), %rdi									  # Load the address of a string constant ".LC1" into the first argument register (rdi) for printing
	movl	$0, %eax											  # Copy 0 to %eax to clear the register
	call	printf@PLT											  # Call the printf function to print the string stored at the address in rdi. printf("%d\t%d\n", arr1[i], fr1[i]);
.L10:															  # Incrementing i(For going to next iteration of loop)
	addl	$1, -4(%rbp)									      # Adding 1 to -4(%rbp). Adding 1 to i
.L9:															  # Checking if loop needs to continue
	movl	-4(%rbp), %eax										  # Copy from -4(%rbp) to %eax. It is to load the value of i in %eax
	cmpl	-36(%rbp), %eax										  # Compare -36(%rbp) with %eax. It checks the loop condition i<n
	jl	.L11													  # Jump on less than to .L11 . If i<n , the loop condition is met, then continue with another iteration of the loop 
	nop															  # No opeation
	nop															  # No opeation
	leave														  # Leave instruction for the function. Deallocate stack frame, restore previous %rbp
	.cfi_def_cfa 7, 8											  # Update the Canonical Frame Address
	ret															  # Return from the function
	.cfi_endproc												  # Call frame information. End of the procedure
.LFE1:															  # End of printArrayWithFrequency function
	.size	printArrayWithFrequency, .-printArrayWithFrequency    # Set the size of the printArrayWithFrequency function by substracting the start from the end
	.section	.rodata											  # Start of read-only data section
	.align 8													  # 8 byte memory boundary alignment
.LC2:															  # Third string label to print in main function
	.string	"\n\nCount frequency of each integer element of an array:" # Defining the content of the string "\n\nCount frequency of each integer element of an array:"
	.align 8													  # 8 byte memory boundary alignment
.LC3:															  # Fourth string label to print in main function
	.string	"------------------------------------------------"	  # Defining the content of the string "------------------------------------------------"
	.align 8													  # 8 byte memory boundary alignment
.LC4:															  # Fifth string label to print in main function
	.string	"Input the number of elements to be stored in the array :" # Defining the content of the string "Input the number of elements to be stored in the array :"
.LC5:															  # Sixth string label to print in main function
	.string	"%d"												  # Defining the content of the string "%d"
	.align 8													  # 8 byte memory boundary alignment
.LC6:															  # Seventh string label to print in main function
	.string	"Enter each elements separated by space: "			  # Defining the content of the string "Enter each elements separated by space: "
	.text														  # It indicates that the below section is of type text
	.globl	main												  # main is declared as global here, means can be referred to and accessed from other parts of the program
	.type	main, @function										  # main type is specified as function here
main:															  # The main function
.LFB2:															  # Label indicating the start of the main function
	.cfi_startproc												  # Call frame information. Start of the procedure
	endbr64														  # End branch
	pushq	%rbp											      # Put the base pointer in the stack (Save the base pointer)
	.cfi_def_cfa_offset 16										  # Set CFA to use offset of 16
	.cfi_offset 6, -16										      # Set rule to set register 6 at offset of -16 from CFI
	movq	%rsp, %rbp											  # rbp <-- rsp. Stack pointer is moved to the base pointer
	.cfi_def_cfa_register 6										  # Set CFA register to register number 6
	subq	$832, %rsp											  # Reserve 832 bytes for local variables in the fucntion main
	movq	%fs:40, %rax									      # Load the add of fs:40 into %rax. Load address of global offset table
	movq	%rax, -8(%rbp)										  # Copy from %rax to -8(%rbp). Save the loaded value in -8(%rbp)
	xorl	%eax, %eax											  #	Compute xor of %eax with itself. It sets %eax to 0
	leaq	.LC2(%rip), %rdi									  # Load the address of a string constant ".LC2" into the first argument register (rdi) for printing
	call	puts@PLT											  # Call the puts function to print the string stored at the address in rdi. printf("\n\nCount frequency of each integer element of an array:\n");
	leaq	.LC3(%rip), %rdi									  # Load the address of a string constant ".LC3" into the first argument register (rdi) for printing
	call	puts@PLT											  # Call the puts function to print the string stored at the address in rdi. printf("------------------------------------------------\n");
	leaq	.LC4(%rip), %rdi									  # Load the address of a string constant ".LC4" into the first argument register (rdi) for printing
	movl	$0, %eax											  # Copy 0 to %eax to clear the register
	call	printf@PLT											  # Call the printf function to print the string stored at the address in rdi. printf("Input the number of elements to be stored in the array :");
	leaq	-828(%rbp), %rax									  # Load address from -828(%rbp) to %rax. It is to load the address of n
	movq	%rax, %rsi											  # Copy from %rax to %rsi. It is to pass the loaded address to rsi
	leaq	.LC5(%rip), %rdi									  # Load the address of a string constant ".LC5" into the first argument register (rdi) for scanning
	movl	$0, %eax											  # Copy 0 to %eax register to clear the register
	call	__isoc99_scanf@PLT									  # Call scanf function to get the input value for n. scanf("%d",&n);
	leaq	.LC6(%rip), %rdi									  # Load the address of a string constant ".LC6" into the first argument register (rdi) for printing
	movl	$0, %eax											  # Copy 0 to %eax register to clear the register
	call	printf@PLT											  # Call the printf function to print the string stored at the address in rdi. printf("Enter each elements separated by space: ");
	movl	$0, -824(%rbp)										  # Copy 0 to -824(%rbp) to initialize the loop variable i as 0
	jmp	.L13													  # Jump to .L13 to the start of the looop
.L14:															  # Loop for taking input of the array arr1
	leaq	-816(%rbp), %rax									  # Load the address of arr1 in %rax. It loads arr1[] in %rax
	movl	-824(%rbp), %edx									  # Copy -824(%rbp) to %edx. It loads the value of i
	movslq	%edx, %rdx											  # Copy from %edx to %rax and also while copying convert it from 32 bit to 64 bit
	salq	$2, %rdx											  # Multiply the value in %rdx by 4. It will be used to find the address of arr1[i]
	addq	%rdx, %rax											  # Add %rdx to %rax. It calculates the actual address of arr1[i]
	movq	%rax, %rsi											  # Copy from %rax to %rsi. It takes the address of arr1[i] in %rsi, which will be used for scanning
	leaq	.LC5(%rip), %rdi									  # Load the address of a string constant ".LC5" into the first argument register (rdi) for scanning
	movl	$0, %eax											  # Copy 0 to %eax register to clear the register
	call	__isoc99_scanf@PLT									  # Call scanf function to get the input value for arr1[i] scanf("%d",&arr1[i]);
	addl	$1, -824(%rbp)									      # Add 1 to value it -824(%rbp). It increases the value of by 1 after finishing a iteration of the loop
.L13:															  # Checking by comparing i and n, if the loop needs to continue
	movl	-828(%rbp), %eax									  # Copy from -828(%rbp) to %eax. It loads the value of n
	cmpl	%eax, -824(%rbp)									  # Compare value in %eax with value in -824(%rbp). It checks for the loop condition i<n
	jl	.L14													  # Jump on less than to .L14. If i < n means go to line .L14 and continue with next iteration of the loop 
	movl	$0, -820(%rbp)										  # Copy 0 to -820(%rbp). It initializes the value of loop variable i with 0 for the second for loop which initliazes elements of fr1 with -1
	jmp	.L15													  # Jump to .L15 to the start of the next for loop
.L16:															  # Loop for fr1 array initialization
	movl	-820(%rbp), %eax									  # Copy from -820(%rbp) to %eax. It loads the value of i
	cltq														  # Convert long to quad
	movl	$-1, -416(%rbp,%rax,4)								  # Copy -1 to the address of fr1[i]. Initialize fr1[i] with -1						  
	addl	$1, -820(%rbp)										  # Add 1 to the value at -820(%rbp). Increment the value of i by 1	
.L15:															  # Checking if the fr1[] array initialization loop needs to continue
	movl	-828(%rbp), %eax									  # Copy from -828(%rbp) to %eax. It loads the value of n in %eax
	cmpl	%eax, -820(%rbp)									  # Compare between value at %eax and -820(%rbp). It checks for the loop condition i < n
	jl	.L16													  # Jump on less than to .L16. It means if the condition i < n is met jump to another iteration of the loop
	movl	-828(%rbp), %ecx									  # Copy from -828(%rbp) to %ecx. It loads the value of n in %ecx.
	leaq	-416(%rbp), %rdx									  # From -416(%rbp), load the address of fr1[] into rdx. It is loaded and will be passed as the third argument of the function calculateFrequency
	leaq	-816(%rbp), %rax									  # From -816(%rbp), load the address of arr1[] into rax
	movl	%ecx, %esi											  # Copy from %ecx to %esi. It is to be passed as the second argument of the function calculateFrequency
	movq	%rax, %rdi											  # Copy from %rax to %rdi. It is to be passed as the first argument of the function calculateFrequency
	call	calculateFrequency									  # Calls the function calculateFrequency from main function
	movl	-828(%rbp), %edx									  # Copy from -828(%rbp) to %edx. It loads the value of n in %edx and will be passed as the third parameter in the function printArrayWithFrequency
	leaq	-416(%rbp), %rcx									  # From -416(%rbp), load the address of fr1[] into rcx
	leaq	-816(%rbp), %rax									  # From -816(%rbp), load the address of arr1[] into rax
	movq	%rcx, %rsi											  # Copy from %rcx to %rsi. It loads the address of fr1[] into rsi which will be passed as the second parameter in the function printArrayWithFrequency
	movq	%rax, %rdi											  # Copy from %rax to %rdi. It loads the address of arr1[] into rdi which will be passed as the first parameter in the function printArrayWithFrequency
	call	printArrayWithFrequency								  # Calls the function printArrayWithFrequency from main function
	movl	$0, %eax											  # Copy 0 to %eax to clear the register
	movq	-8(%rbp), %rcx										  # Copy from -8(%rbp) to %rcx. Load address of global offset table
	xorq	%fs:40, %rcx										  # Check for stack smashing
	je	.L18													  # Jump to .L18 for exit if no stack smashing detected
	call	__stack_chk_fail@PLT								  # Otherwise check call stack smashing error function
.L18:															  # Exiting
	leave														  # Clear stack and leave
	.cfi_def_cfa 7, 8											  # Update the Canonical Frame Address 
	ret															  # Return from the function
	.cfi_endproc												  # Call frame information. End of the procedure
.LFE2:															  # End of main function
	.size	main, .-main										  # Set the size of the main function by substracting the start from the end
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"		  # Identifying information about the compiler used to generate the code
	.section	.note.GNU-stack,"",@progbits					  # GNU stack note
	.section	.note.gnu.property,"a"							  # GNU property note with attribute "a"
	.align 8													  # 8 byte memory boundary alignment
	.long	 1f - 0f											  # Calculate the difference in addresses between the labels 1f and 0f
	.long	 4f - 1f											  # Calculate the difference in addresses between the labels 4f and 1f
	.long	 5													  # Metadata entry value for the note	  
0:																  # Label marking the start of the section
	.string	 "GNU"												  # A string with the content "GNU"
1:																  # Label used for the first address difference calculation
	.align 8													  # Align the next instruction at an 8-byte boundary
	.long	 0xc0000002											  # Note data
	.long	 3f - 2f											  # Calculate the difference in addresses between the labels 3f and 2f
2:																  # Contains note data	  
	.long	 0x3											      # Specific note data
3:																  # Alignment for the last note
	.align 8													  # Align the next instruction at an 8-byte boundary
4:																  # Label indicating the end of the last note
