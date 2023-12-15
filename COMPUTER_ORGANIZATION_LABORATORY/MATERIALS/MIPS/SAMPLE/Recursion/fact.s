.data
    input_prompt:   .asciiz "Enter a non-negative integer: "
    result_msg:     .asciiz "The factorial is: "
    newline:        .asciiz "\n"
    
.text
    # Function to read an integer from user input
    # Arguments: none
    # Returns: $v0 = the input integer
read_int:
    li $v0, 5           # syscall code 5 for reading an integer
    syscall
    move $t0, $v0       # Move the result to $t0
    jr $ra              # Return to the calling code

    # Function to print an integer
    # Arguments: $a0 = integer to print
    # Returns: none
print_int:
    li $v0, 1           # syscall code 1 for printing an integer
    syscall
    li $v0, 4           # syscall code 4 for printing a string
    la $a0, newline     # load the newline string address
    syscall
    jr $ra              # Return to the calling code

    # Function to calculate the factorial of an integer
    # Arguments: $a0 = integer for which to calculate the factorial
    # Returns: $t0 = factorial of the input integer
calculate_factorial:
    li $t1, 1           # Initialize the result to 1
    li $t2, 1           # Initialize the counter to 1

factorial_loop:
    ble $t2, $a0, factorial_multiply   # If counter <= input integer, perform multiplication
    j factorial_end    # Jump to the end of the loop if the counter is greater than the input integer

factorial_multiply:
    mul $t1, $t1, $t2   # Multiply the result by the counter
    addi $t2, $t2, 1    # Increment the counter
    j factorial_loop    # Jump back to the beginning of the loop

factorial_end:
    move $t0, $t1       # Move the result to $t0
    jr $ra              # Return to the calling code

main:
    # Print the prompt and read the input integer
    li $v0, 4           # syscall code 4 for printing a string
    la $a0, input_prompt    # load the input prompt string address
    syscall
    jal read_int        # Jump and link to read_int function

    # Calculate the factorial of the input integer
    move $a0, $t0       # Move the input integer to $a0
    jal calculate_factorial    # Jump and link to calculate_factorial function

    # Print the result
    li $v0, 4           # syscall code 4 for printing a string
    la $a0, result_msg  # load the result message string address
    syscall
    move $a0, $t0       # Move the factorial result to $a0
    jal print_int       # Jump and link to print_int function

    # Exit the program
    li $v0, 10          # syscall code 10 for program exit
    syscall
