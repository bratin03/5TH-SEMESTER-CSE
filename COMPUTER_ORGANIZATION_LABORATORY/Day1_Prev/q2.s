.globl main

.data

prompt1:
    .asciiz "Enter 1st positive integer: "
prompt2:
    .asciiz "Enter 2nd positive integer: "
result:
    .asciiz "The sum is: "
warning:
    .asciiz "Wrong input"
newline:
    .asciiz "\n"

    .text
main:
    li $v0,4
    la $a0, prompt1
    syscall

    li $v0, 5
    syscall
    move $s0, $v0


    li $v0,4
    la $a0, prompt2
    syscall

    li $v0, 5
    syscall
    move $s1, $v0
    
    li $t0, 0
    
    blt $s0, $zero, sendWarning
    blt $s1, $zero, sendWarning

    # 0 can be loaded as $zero or 0 or from t0


    add $s1,$s0, $s1
    li $v0, 4
    la $a0, result
    syscall

    li $v0, 1
    move $a0, $s1
    syscall

    j exit

    sendWarning:
        li $v0, 4
        la $a0, warning
        syscall
        j exit

    exit:

        li $v0, 10
        syscall