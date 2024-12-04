# Assignment Number 1
# Problem Number 1
# Semester Number 5
# Group Number 8
# Group Members
# Bratin Mondal (21CS10016)
# Somya Kumar (21CS30050)

# This program computes and displays the value of e^x for an input x using Taylor Series


####################### Data segment ######################################
.data

# Prompts for asking input and showing the result
prompt1:
    .asciiz "Enter an integer (x): "
Ans1Part1:
    .asciiz "Value of e^"
Ans1Part2:
    .asciiz " = "    
Ans2:
    .asciiz "The Number of iterations = "
newline:
    .asciiz "\n"

####################### Data segment ######################################


####################### Text segment ######################################
    .text
    .globl main
main:
    li $v0,4
    la $a0, prompt1 #Prompt asking for input from the user
    syscall 

    li $v0, 5 # Get the value of X from the user
    syscall
    move $s0, $v0

    li $t0, 0  # $t0 stores the number of iterations, initialized with 0
    li $t1, 0  # $t1 stores the current sum after going through an iteration, intitalized with 0
    li $t2, 1  # $t2 stores the current term that will be added in the current iteration
    li $t4, 1  # For the term in Taylor Series, we keep the track of the power of x in $t4 that will contribute to the term being added in that iteration. For example this term stores x^0 in first iteration, x^1 in second iteration, x^2 in third iteraiton and so on. 
    li $t5, 1 # For the term in Taylor Series, we keep the track of the factorial in $t5 that will contribute to the term being added in that iteration. For example this term stores 0! in first iteration, 1! in second iteration, 2! in third iteraiton and so on.


    j LoopCondition # Entering the loop for calculating the taylor series sum

    Loop:
    add $t1, $t1, $t2 # Adding the Term of a taylor series to current sum
    add $t0,$t0,1 # Increasing the number of itertaions by 1
    mul $t4, $t4, $s0 # Calculating the next power of x in $t4 by multiplying with the previous power of x  
    mul $t5, $t5, $t0 # Calculating the next factorial in $t5 by multiplying the last factoiral value with number of iterations  
    div $t4, $t5 # Calculating the term to be added for the next iteration by dividing $t4 with $t5
    mflo $t2 # Moving the quotient after the division to our term to be addded in iteration
    j LoopCondition # Going to LoopCondition to check if the iteration needs to be further continued

    LoopCondition:
    bgt $t2, 0, Loop
    # If the term that needs to be added in the current iteration of Taylor Series is greater than 0, we continue with the next iteration

    # Printing the answer for the calculated value of e^x
    li $v0, 4
    la $a0, Ans1Part1
    syscall

    li $v0, 1
    move $a0, $s0
    syscall

    li $v0, 4
    la $a0, Ans1Part2
    syscall

    li $v0, 1
    move $a0, $t1
    syscall
    # Printing the answer for the calculated value of e^x done

    # Printing Newline
    li $v0, 4
    la $a0,newline
    syscall

    # Printing the answer for number of iterations

    li $v0, 4
    la $a0, Ans2
    syscall

    li $v0, 1
    move $a0, $t0
    syscall
    # Printing the answer for number of iterations done

    # Printing Newline

    li $v0, 4
    la $a0,newline
    syscall

    # Exiting

    exit:
        li $v0, 10
        syscall

####################### Text segment ######################################