# Modify the adddigits program so that it accepts a string which consists of both digits and non-digit characters. The program should however print the sum of only the digits, while ignoring the non-digit characters.
# For example: if the string input is, 12ABC?3, the sum is 6

#####Data Segment########## 
.data
number_prompt:
.asciiz "Please enter a number (<11 digits): " 
out_msg:
.asciiz "\n The sum of individual digits is: " 
newline:
.asciiz "\n" 
number:
.space 11

#####Code Segment########### 
.text
.globl main 
main:
la $a0,number_prompt 
li $v0,4
syscall
la $a0,number 
li $a1,11
li $v0,8
syscall
la $a0,out_msg 
li $v0,4
syscall

la $t0, number 
loop:
lb $t1,($t0) 
beq $t1,0xA,exit_loop 
beqz $t1,exit_loop 
blt $t1,'0',nextiter
bgt $t1,'9',nextiter
and $t1,$t1,0x0F 
addu $t2,$t2,$t1 
addu $t0,$t0,1
b loop

nextiter:
addu $t0,$t0,1
b loop

exit_loop: 
move $a0,$t2
li $v0,1 
syscall
la $a0,newline 
li $v0,4
syscall
exit:
li $v0,10
syscall