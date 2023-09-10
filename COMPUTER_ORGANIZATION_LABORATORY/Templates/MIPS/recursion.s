####################### Data segment ######################################
 .data
msg_input1:     .asciiz "Enter the number of elements (N):\n"
msg_input2:     .asciiz "Enter the elements of the array (separated by newline):\n"
display_ans:    .asciiz "Max Circular Subarray Sum is: "
space:	        .asciiz "    "
newLine:        .asciiz "\n"
array: .word 0:100	
####################### Data segment ######################################

####################### Text segment ######################################
.text

# Function to print a new line.
PrintNewLine:
    li $v0, 4
    la $a0, newLine
    syscall
    jr $ra
# Function to take N as input
TakeNum:
    # Asking for numbers
	la $a0, msg_input1 
	li $v0,4  # Prompt asking N as input
	syscall

    li $v0, 5
    syscall # Reading N
    move $s0, $v0   # Number of elements is $s0
    jr $ra

# Function to take an array input and also calculate the sum of all the elements of the array
TakeArray:
	la $a0, msg_input2 
    li $v0,4    
    syscall
    la $t0, array
	li $t1, 0                
    loop1Start:
    li $v0, 5 
    syscall
    sw $v0, ($t0)               # Move the inputs to the array
    addi $t0, $t0, 4            # Increase the array index
    addi $t1, $t1, 1            # No. of integers stored till now
    blt $t1, $s0, loop1Start    # Loop Condition
    jr $ra
    
# Function to find the subarray with maximum sum for normal array( Not circular)
RecursiveSort:
    addi $sp,$sp,-12
    sw $ra,0($sp)
    
    move $t4, $t2
    move $t5, $t3 # l is t4; r is t5
    move $t6, $t2
    j loopCondition
    Loop:
        innerLoop1:
        innerLoopCondition1:
        bgt $t3, $t4, Con_1_2
        Con_1_2:
        
    loopCondition:
    blt $t4, $t5, Loop

.globl main
    main:

        jal TakeNum             # Calling Function to take input N
        
        jal TakeArray           # calling Function to take Input array

        la $t1, array
        li $t2, 0
        subi $t3, $s0, 1


	    	
	    exit:                   # Exiting the program
	     	li $v0, 10
          	syscall # exit
   