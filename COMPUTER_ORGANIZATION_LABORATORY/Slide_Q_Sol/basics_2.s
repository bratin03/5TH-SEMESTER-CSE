.data
prompt: .asciiz "Enter a string: "
encoded_prompt: .asciiz "Encoded string: "
terminate_prompt: .asciiz "Do you want to terminate? (y/n): "
newline: .asciiz "\n"
input_buffer: .space 100
encoded_buffer: .space 100

.text
.globl main

main:
    li $v0, 4           # Print prompt
    la $a0, prompt
    syscall
    
    li $v0, 8           # Read input string
    la $a0, input_buffer
    li $a1, 100
    syscall

    move $t5, $a0       # Save the address of input string
    
encode_loop:
    lb $t0, ($t5)       # Load a character from input string
    beqz $t0, terminate # If null terminator is reached, terminate
    beq $t0,0xA,terminate
    li $t1, '0'         # ASCII value of '0'
    li $t2, '9'         # ASCII value of '9'
    sub $t0, $t0, $t1   # Calculate the difference between character and '0'
    blt $t0,0,encoded # If the character is not a digit, skip encoding
    bgt $t0,9,encoded
    
    beq $t0, 0, digit_0
    beq $t0, 1, digit_1
    beq $t0, 2, digit_2
    beq $t0, 3, digit_3
    beq $t0, 4, digit_4
    beq $t0, 5, digit_5
    beq $t0, 6, digit_6
    beq $t0, 7, digit_7
    beq $t0, 8, digit_8
    beq $t0, 9, digit_9

    
digit_0:
    li $t0, '4'
    j encoded
digit_1:
    li $t0, '6'
    j encoded
digit_2:
    li $t0, '9'
    j encoded
digit_3:
    li $t0, '5'
    j encoded
digit_4:
    li $t0, '0'
    j encoded
digit_5:
    li $t0, '3'
    j encoded
digit_6:
    li $t0, '1'
    j encoded
digit_7:
    li $t0, '8'
    j encoded
digit_8:
    li $t0, '7'
    j encoded
digit_9:
    li $t0, '2'
    
encoded:
    sb $t0, ($t5)       # Store the encoded digit in the encoded buffer
    addi $t5, $t5, 1    # Move to the next character in input string    # Move to the next position in encoded buffer
    j encode_loop
terminate:
    li $v0, 4           # Print encoded prompt
    la $a0, encoded_prompt
    syscall
    sb $zero ,($t5)
    li $v0, 4 
    la $a0, input_buffer    # Load the address of encoded buffer
          # Print encoded string
    syscall
    j terminate_print
terminate_print:
    li $v0, 4           # Print newline
    la $a0, newline
    syscall
    
    li $v0, 4           # Print terminate prompt
    la $a0, terminate_prompt
    syscall
    
    li $v0, 12          # Read a single character (y/n)
    syscall
    
    li $t0, 'y'         # ASCII value of 'y'
    beq $v0, $t0, end_program
    
    li $t0, 'Y'         # ASCII value of 'Y'
    beq $v0, $t0, end_program
    li $v0, 4           # Print newline
    la $a0, newline
    syscall


    j main              # Otherwise, ask for another input string

end_program:
    li $v0, 10          # Exit program
    syscall
