#################################
#   Assignment - 4              #
#   Question No. - 1            #
#   Group No. - 8               #
#   Bratin Mondal (21CS10016)   #
#   Somya Kumar (21CS30050)     #
#   Date: August 16th, 2023     #
#################################


####################### Data segment ######################################
.data
    # Prompt to input an integer
    prompt: .asciiz "Input an integer n:\n"
    # Message to display the result
    result: .asciiz "Sum of the series = "
    # Warning for wrong input
    warning: .asciiz "Wrong Input. Enter a positive number."
####################### Data segment ######################################

####################### Text segment ######################################
.text
main:
    # Display the prompt
    li        $v0, 4          # Load appropriate system call code
    la        $a0, prompt     # Load the address of the string to be displayed
    syscall                   # Make the system call to display prompt

    # Read input integer
    li        $v0, 5          # Load appropriate system call code for reading integer
    syscall                   # Make the system call to read integer

    j sanityCheck

    # Handle invalid input
    sanityError:
        li $v0, 4              # Load appropriate system call code for printing string
        la $a0, warning        # Load the address of the warning string
        syscall                # Make the system call to print warning
        j exit                 # Exit on invalid input

    # Perform sanity check on the input
    sanityCheck:
    blt $v0, 1, sanityError   # Branch if less than 1

    # Call the 'series' function
    move      $a0, $v0        # Move the input integer to argument register
    jal       series          # Jump to the 'series' function and save return address in $ra
    move      $t0, $v0        # Save the result of 'series' function in $t0

    # Display the result message
    li        $v0, 4          # Load appropriate system call code for printing string
    la        $a0, result     # Load the address of the result string
    syscall                   # Make the system call to print result message

    # Print the calculated result
    li        $v0, 1          # Load appropriate system call code for printing integer
    move      $a0, $t0        # Move the calculated result to argument register
    syscall                   # Make the system call to print the result

    # Exit the program
    exit:
    li        $v0, 10         # Load appropriate system call code for program exit
    syscall                   # Make the system call to exit the program

.text
series:
    # Base case -- still in parent's stack segment
    # Adjust the stack pointer to store return address and argument

    addi    $sp, $sp, -8       # Allocate space on the stack for two words

    # Save $s0 and $ra onto the stack
    sw      $s0, 4($sp)        # Save the value of $s0 on the stack
    sw      $ra, 0($sp)        # Save the return address on the stack

    bne     $a0, 1, else       # Branch if input is not equal to 1 for recursive call

    addi    $v0, $zero, 1      # Set return value to 1
    j series_return            # Return Base Case

else:
    # Backup $a0
    move    $s0, $a0           # Save the input value in $s0
    addi    $a0, $a0, -1       # Decrement input value by 1
    jal     series             # Jump to the 'series' function

    li $t3, 0                   # Initialize iterator for the loop to calculate n^n
    li $t4, 1                   # Initialize current value i.e., n^0
    j loopCondition             # Jump to loop condition check

    # Loop to calculate n^n
    loop:
        mul $t4, $t4, $s0        # Multiply $t4 with $s0 and store in $t4
        addi $t3, $t3, 1         # Increment the iterator
        j loopCondition          # Jump to loop condition check

    # Check loop iteration count
    loopCondition:
    blt $t3, $s0, loop         # Branch to loop if $t3 < $s0

    add   $v0, $t4, $v0        # Add the calculated value to the accumulated result from previous calls

series_return:
    lw      $s0, 4($sp)         # Restore $s0 from the stack
    lw      $ra, 0($sp)         # Restore $ra from the stack
    addi    $sp, $sp, 8         # Deallocate the space from the stack
    jr      $ra                 # Jump back to the calling function

####################### Text segment ######################################