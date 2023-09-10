# Code for taking array input and printing

####################### Data segment ######################################
 .data
msg_input1:   .asciiz "Enter the 8 numbers: "
spaceS:	.asciiz "    "

pos_result:   .asciiz "The sorted numbers are    "

#declaring the array and the space it'll use
array: .space 32	
####################### Data segment ######################################

####################### Text segment ######################################
.text
.globl main
    main:
        #Asking for numbers
	    la $a0, msg_input1 
	    li $v0,4  #prints the message string
	    syscall

	    la $t0, array
	    li $s0, 0

	    # Reading input
	    Loop1:
	        li $v0, 5  #reads first integer
		    syscall
		
		    #Move the inputs to the array
		    sw $v0, ($t0)
		    
		    #Increase the array index
		    addi $t0, $t0, 4

		    # No. of integers
            addi $s0, $s0, 1

		    #Loop Condition
		    blt $s0, 8, Loop1
	      
	    	
		# printing the array
        li $s0,0
        la $t0, array
        Loop2:
            li $v0, 1
            lw $a0, ($t0)
            syscall

            addi $t0, $t0, 4
            addi $s0, $s0, 1

            # printing space
            li  $v0, 4
	    	la  $a0, spaceS 
	    	syscall  

            # Loop Condition
            blt $s0, 8, Loop2


	    exit:
	     	li $v0, 10
          	syscall # exit


  # #              