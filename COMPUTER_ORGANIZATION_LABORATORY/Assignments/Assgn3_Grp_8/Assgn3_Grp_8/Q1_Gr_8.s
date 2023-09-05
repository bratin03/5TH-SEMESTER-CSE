#################################
#   Assignment - 3              #
#   Question No. - 1            #
#   Group No. - 8               #
#   Bratin Mondal (21CS10016)   #
#   Somya Kumar (21CS30050)     #
#   Date: August 14th, 2023     #
#################################

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
    li $t2, 0                   # $t2 is used to store the sum of the elements of array
    loop1Start:
    li $v0, 5 
    syscall
    add $t2, $t2, $v0           # adding the current value i.e. array[i] to $t2
   
    sw $v0, ($t0)               # Move the inputs to the array
    
    addi $t0, $t0, 4            # Increase the array index
    addi $t1, $t1, 1            # No. of integers stored till now
    blt $t1, $s0, loop1Start    # Loop Condition
    move $s3, $t2               # Store the sum of array elements in $s3
    jr $ra

# Function to find the subarray with maximum sum for normal array( Not circular)
MaxSubArray:
    la $t0, array               # Loading the array address in $t0
    li $t1, 0                   # Initializing the iterator with 0
    li $t2, -10000              # Initializing the current max with a big negative value
    li $t3, 0                   # $t3 stores the sum till array[i]. When it becomes negative, it is restored to zero

    MaxSubArrayLoop:

    lw $t4, ($t0)               # Loading array [i] to $t4
    add $t3, $t3, $t4           # Updating the current sum value
    
    blt $t3, $t2, notUpdateMax  # Checking if current sum is greater than current max.
    move $t2, $t3               # Updating Current max if it is less tha current sum
    notUpdateMax:

    bgt $t3, 0, notResetSum     # Checking if current sum is less than 0
    li $t3, 0                   # reseting current sum to 0 if it is less than zero
    notResetSum:

    addi $t0, $t0, 4            # Increase the array index
    addi $t1, $t1, 1            # Increasing the iterator
    blt $t1, $s0, MaxSubArrayLoop   # Cheking for the loop condition
    jr $ra

# Function to find the subarray with minimum sum for normal array(Not circular)    
MinSubArray:
    la $t0, array               # Loading the array address in $t0
    li $t1, 0                   # Initializing the iterator with 0
    li $t2, 10000               # Initializing the current min with a big positive value
    li $t3, 0                   # $t3 stores the sum till array[i]. When it becomes positive, it is restored to zero

    MinSubArrayLoop:

    lw $t4, ($t0)               # Loading array [i] to $t4
    add $t3, $t3, $t4           # Updating the current sum value
    
    bgt $t3, $t2, notUpdateMin  # Checking if current sum is less than current max.
    move $t2, $t3               # Updating Current min if it is greater than current sum
    notUpdateMin:

    blt $t3, 0, notResetSum2    # Checking if current sum is greater than 0
    li $t3, 0                   # reseting current sum to 0 if it is greater than zero
    notResetSum2:

    addi $t0, $t0, 4            # Increase the array index
    addi $t1, $t1, 1            # Increasing the iterator
    blt $t1, $s0, MinSubArrayLoop   # Checking for the loop condition
    jr $ra

MaxSubArrayCircular:
    jal MaxSubArray             # Calling the MaxSubArray function
    move $s1, $t2               # Storing the Maxarray Sum for normal arrays in $s1

    jal MinSubArray             # Calling the MinSubArray function
    move $s2, $t2               # Storing the Minarray Sum for normal arrays in $s2

    jal PrintNewLine

	la $a0, display_ans         # Prompt for displaying ans
    li $v0,4    
    syscall

    li $t2, 0                   
    sub $t2, $s3, $s2           # Subtracting min sub array sum from the total

    blt $s1, $t2,updateAns      # Checking if the max subarray sum is greater than the (Total - Min Subarray sum)
    j printAns
    updateAns:
    move $s1, $t2               # Storing the final Ans in $s1
        
    printAns:                   # Printing Final ans
        li $v0, 1
        move $a0, $s1
        syscall

	jal PrintNewLine
    jr $ra

.globl main
    main:

        jal TakeNum             # Calling Function to take input N
        
        jal TakeArray           # calling Function to take Input array
        jal MaxSubArrayCircular # calling the main driver function
	    	
	    exit:                   # Exiting the program
	     	li $v0, 10
          	syscall # exit
   