# Assignment Number 2
# Problem Number 1
# Semester Number 5
# Group Number 8
# Group Members
# Bratin Mondal (21CS10016)
# Somya Kumar (21CS30050)

.data
# Data segment
prompt1:
    .asciiz "Enter the number of cycles in Permutation: "
promptCount:
    .asciiz "Enter the number of elements in cycle: "
newline:
    .asciiz "\n"
space:
    .asciiz " "

length: .word 9
array1: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

####################### Text segment ######################################
.text
.globl main
main:
    # Prompt for the number of cycles
    li $v0, 4
    la $a0, prompt1
    syscall

    # Read the number of cycles
    li $v0, 5
    syscall
    move $t0, $v0

    # Initialize start index
    li $t1, 0

loop:
    # Prompt for the number of elements in the current cycle
    li $v0, 4
    la $a0, promptCount
    syscall

    # Read the number of elements in the current cycle
    li $v0, 5
    syscall
    move $t2, $v0

    # Initialize loop counter
    li $t3, 0

    # Initialize first element and previous element
    li $t4, -1
    li $t5, -1

loop_inner:
    # Prompt for the current element in the cycle
    li $v0, 5
    syscall
    move $t7, $v0
    
    # If it's not the first iteration, swap elements
    beq $t3, 0, first_itr
    first_itr:
        move $t4, $t7
        move $t5, $t7
        addi $t3, $t3, 1
        j inner_loop_condition
    
    # Calculate the address of the current element in array1
    la $t6, array1
    sub $t5, $t5, 1
    sll $t5, $t5, 2
    add $t6, $t6, $t5
    sw $t7, ($t6)
    addi $t3, $t3, 1
    j inner_loop_condition

inner_loop_condition:
    # Continue swapping until all elements in the cycle are processed
    blt $t3, $t2, loop_inner

    # Calculate the addresses of the elements to be swapped
    la $t6, array1
    sub $t7, $t7, 1
    sll $t7, $t7, 2
    add $t6, $t6, $t7
    lw $t8, ($t6)

    la $t7, array1
    sub $t5, $t5, 1
    sll $t5, $t5, 2
    add $t7, $t7, $t5
    lw $t9, ($t7)

    # Swap the elements
    sw $t9, ($t6)
    sw $t8, ($t7)

    # Move to the next cycle
    addi $t1, $t1, 1
    j loop_condition

loop_condition:
    # Continue processing cycles until all cycles are processed
    blt $t1, $t0, loop
    j print_loop

print_loop:
    # Print the elements of array1
    la $t0, array1
    lw $t1, length
    li $t2, 0

print_loop_inner:
    bge $t2, $t1, end_print_loop

    lw $a0, ($t0)
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, space
    syscall

    addi $t0, $t0, 4
    addi $t2, $t2, 1
    j print_loop_inner

end_print_loop:
    # Print a newline and exit
    li $v0, 4
    la $a0, newline
    syscall

    # Exiting
    li $v0, 10
    syscall
