.data
prompt1:
.asciiz "Enter number of numbers in the array:\n"
prompt2:
.asciiz "Enter the "
prompt3:
.asciiz " number:\n"
prompt4:
.asciiz "Enter the number to search for:\n"
prompt5:
.asciiz "The number is in the array.\n"
prompt6:
.asciiz "The number is not in the array.\n"
newline:
.asciiz "\n"
array:
.word 0:100  # Reserve space for 100 integers in the array.

.text
.globl main
main:
    # Prompt the user for the number of elements in the array.
    la $a0, prompt1
    li $v0, 4
    syscall
    li $v0, 5
    syscall
    move $t0, $v0  # Store the number of elements in $t0

    li $t1, 0
    la $t2, array

    # Jump to the loop condition check.
    j loopcondition

loop:
    # Prompt the user for each array element.
    la $a0, prompt2
    li $v0, 4
    syscall
    addi $t3, $t1, 1
    li $v0, 1
    move $a0, $t3
    syscall
    la $a0, prompt3
    li $v0, 4
    syscall
    li $v0, 5
    syscall
    sw $v0, 0($t2)
    addi $t2, $t2, 4
    addi $t1, $t1, 1

loopcondition:
    blt $t1, $t0, loop  # Continue looping if t1 < t0

    # Prompt the user for the number to search for.
    li $v0, 4
    la $a0, prompt4
    syscall
    li $v0, 5
    syscall
    move $t1, $v0  # Store the number to search for in $t1

    li $t2, 0
    addi $t3, $t0, -1
    la $t4, array

    # Jump to the second loop condition check.
    j loopcondition2

loop2:
    # Calculate the middle index.
    add $t5, $t2, $t3
    li $t6, 2
    div $t5, $t6
    mflo $t7

    # Calculate the memory offset for the middle element.
    mul $t8, $t7, 4
    add $t9, $t4, $t8
    lw $t8, 0($t9)  # Load the middle element from memory.

    # Check if the middle element is equal to the target.
    beq $t8, $t1, found  # If found, jump to the 'found' label.

    # If not found, adjust the search boundaries.
    bge $t8, $t1, searchleft
    addi $t7, $t7, 1  # Move to the right half.
    move $t2, $t7
    j loopcondition2

searchleft:
    addi $t7, $t7, -1  # Move to the left half.
    move $t3, $t7

loopcondition2:
    ble $t2, $t3, loop2  # Continue looping if t2 <= t3

    # If we reach this point, the search is complete, and the number is not in the array.
    li $v0, 4
    la $a0, prompt6
    syscall

exit:
    # Exit the program.
    li $v0, 10
    syscall

found:
    # Display a message indicating the number was found.
    li $v0, 4
    la $a0, prompt5
    syscall

    # Exit the program.
    j exit
