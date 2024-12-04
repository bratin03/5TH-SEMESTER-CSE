#################################
#   Assignment - 4              #
#   Question No. - 2            #
#   Group No. - 8               #
#   Bratin Mondal (21CS10016)   #
#   Somya Kumar (21CS30050)     #
#   Date: August 16th, 2023     #
#################################


####################### Data segment ######################################
.data
    prompt:   .asciiz "Input an integer N:\n"
    result:   .asciiz "Number of steps of Collatz sequence:\n"
    warning:  .asciiz "Wrong Input. Integer entered is not positive."
####################### Data segment ######################################

####################### Text segment ######################################
.text
main:
    # Show prompt asking for input
    li       $v0, 4        # Print string syscall code
    la       $a0, prompt   # Load prompt string address
    syscall                # Print prompt

    # Read n
    li       $v0, 5        # Read integer syscall code
    syscall                # Read an integer
    j        sanityCheck   # Jump to the sanity check

sanityError:
    li       $v0, 4        # Print string syscall code
    la       $a0, warning  # Load warning string address
    syscall                # Print warning
    j        exit          # Jump to exit

sanityCheck:
    blt      $v0, 1, sanityError  # If n < 1, jump to sanityError

    move     $a0, $v0      # Move the input value into $a0

    # Call the collatz_length_finder function
    jal      collatz_length_finder     # Jump to collatz_length_finder and save return address

    move     $t0, $v0      # Move the result of collatz_length_finder into $t0

    # Show prompt to display result
    li       $v0, 4        # Print string syscall code
    la       $a0, result   # Load result string address
    syscall                # Print result prompt

    # Print the result
    li       $v0, 1        # Print integer syscall code
    move     $a0, $t0      # Move the result value ($t0) into $a0
    syscall                # Print the result
    j        exit          # Jump to exit

.text
collatz_length_finder:
    # Function to find the length of Collatz sequence for input x
    
    addi     $sp, $sp, -8   # Allocate space on the stack
    
    # Save $s0 and $ra on the stack
    sw       $s0, 4($sp)    # Save $s0 at offset 4 from $sp
    sw       $ra, 0($sp)    # Save $ra at offset 0 from $sp
    
    bne      $a0, 1, else   # If x != 1, jump to else section
    addi     $v0, $zero, 0  # Return 0 (base case for Collatz sequence)
    j        collatz_length_finder_return  # Jump to the return section
    
else:
    # Backup $a0
    move     $s0, $a0       # Move $a0 (input x) into $s0 for backup
    
    # Check if x is odd or even
    and      $t0, $s0, 1    # $t0 = $s0 & 1 (Check the least significant bit)
    bne      $t0, 0, odd    # If x is odd, jump to odd section
    j        even            # Otherwise, jump to even section

odd:
    # Calculate Collatz sequence for odd x: x = 3*x + 1
    mul      $a0, $a0, 3    # $a0 = $a0 * 3
    addi     $a0, $a0, 1    # $a0 = $a0 + 1
    j        endif           # Jump to endif section

even:
    # Calculate Collatz sequence for even x: x = x / 2
    li       $t1, 2          # Load 2 into $t1
    div      $a0, $t1        # Divide $a0 by $t1
    mflo     $a0             # Move the quotient into $a0
    j        endif           # Jump to endif section

endif:
    jal      collatz_length_finder       # Call the factorial function
    addi     $v0, $v0, 1    # Add 1 to the result of the factorial function
    
collatz_length_finder_return:
    lw       $s0, 4($sp)     # Restore $s0 from the stack
    lw       $ra, 0($sp)     # Restore $ra from the stack
    addi     $sp, $sp, 8     # Deallocate space from the stack
    jr       $ra             # Return to the calling function

exit: 
    # Exit
    li       $v0, 10        # Load exit syscall code into $v0
    syscall                # Execute the syscall to exit
# End of the program

####################### Text segment ######################################