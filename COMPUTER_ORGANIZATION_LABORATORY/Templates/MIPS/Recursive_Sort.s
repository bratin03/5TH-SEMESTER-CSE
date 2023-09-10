# This program sorts an array of 10 integers recursively (quick sort algorithm)
#
    .globl main

    .data
# program output text constants

array: 
    .space  40

prompt:
    .asciiz "Enter 10 integers (one in each line): "
sorted_msg:
    .asciiz "Sorted array: "
whitespace:
    .asciiz " "
newline:
    .asciiz "\n"

    .text

# main program
main:
    jal     initialize_sp                       # initialize stack

    li		$v0, 4
    la		$a0, prompt
    syscall

    li      $v0, 4
    la      $a0, newline
    syscall

read_array:
    li      $t0, 0                              # count variable <- 0
    b       while_read

while_read:
    bge     $t0, 40, exit_read                  # if count >= 40, exit from read

    li      $v0, 5                              # read int input by user
    syscall 

    sw      $v0, array($t0)                     # store input in array
    addi    $t0, $t0, 4                         # count++
    b       while_read                          # continue to reading loop

exit_read:
    la      $a0, array                          # $a0 <- $array
    li      $a1, 0                              # $a1 <- 0
    li      $a2, 9                              # $a2 <- 9
    jal     recursive_sort                      # call recursive_sort function

print_array:
    li      $v0, 4
    la      $a0, sorted_msg                     # print sorted_msg string
    syscall

    li      $v0, 4
    la      $a0, newline
    syscall
    li      $t0, 0                              # i <- 0
    
    b       while_print                         # continue to print loop

while_print:
    bge     $t0, 40, exit_print                 # if i >= 40, exit from print

    li      $v0, 1
    lw      $a0, array($t0)                     # print arr[count]
    syscall

    li      $v0, 4
    la      $a0, whitespace                     # print whitespace for convinience
    syscall

    addi    $t0, $t0, 4                         # count++

    b       while_print                         # continue to print loop

exit_print:
    move    $sp, $fp                            # free stack

    li      $v0, 4
    la      $a0, newline
    syscall

    li      $v0, 4
    la      $a0, newline
    syscall

    li      $v0, 10                             # terminate program
    syscall                         

# Functions, segments and loops

# Since we need the stack for small number of variables, we will push to stack normally and use base addressing to retrieve
initialize_sp:
    addi    $sp, $sp -4                         # make space for 1 word
    sw      $fp, 0($sp)                         # push $fp in stack
    move    $fp, $sp                            # $fp <- $sp (for freeing stack later)
    jr      $ra

push_sp:
    addi    $sp, $sp, -4                        # make space for 1 word
    sw      $a0, 0($sp)                         # push $a0 in stack
    jr      $ra

recursive_sort:
    # temporarily move $ra to $t0 as calling push_sp will change the value of $ra
    move    $t0, $ra

    # push required arguments to stack
    jal     push_sp

    move    $a0, $a1
    jal     push_sp                             # push left to stack

    move    $a0, $a2
    jal     push_sp                             # push right to stack

    move    $a0, $t0
    jal     push_sp                             # push $ra to stack

    # need to push $s0 and $s1 to stack for next recursive calls
    # l and r values

    move    $a0, $s0
    jal     push_sp                             # save left in stack

    move    $a0, $s1
    jal     push_sp                             # save right in stack

    lw      $s0, 16($sp)                        # l <- left
    lw      $s1, 12($sp)                        # r <- right

outer_while:
    bge     $s0, $s1, return                    # if l >= r, return from sort

inner_while_l:
    lw      $t0, 12($sp)                        # $t0 <- right
    bge     $s0, $t0, inner_while_r             # if l >= right, go to inner_while_r

    lw      $t0, 20($sp)                        # $t0 <- &array[0]

    sll     $t1, $s0, 2                         # $t1 <- 4 * l
    add     $t1, $t0, $t1                       # $t1 <- &array[l]
    lw      $t2, 0($t1)                         # $t2 <- array[l]

    lw      $t1, 16($sp)                        # $t1 = p <- left
    sll     $t1, $t1, 2                         # $t1 <- 4 * p
    add     $t1, $t0, $t1                       # $t1 <- &array[p]
    lw      $t3, 0($t1)                         # $t3 <- array[p]

    bgt     $t2, $t3, inner_while_r             # if array[l] > array[p], go to inner_while_r

    addi    $s0, $s0, 1                         # l++
    j       inner_while_l                       # continue inner_while_l

inner_while_r:
    lw      $t0, 16($sp)                        # $t0 <- left
    ble     $s1, $t0, swap_and_recurse          # if r <= left, go to call function again recursively

    lw      $t0, 20($sp)                        # $t0 <- &array[0]

    sll     $t1, $s1, 2                         # $t1 <- 4 * r
    add     $t1, $t0, $t1                       # $t1 <- &array[r]
    lw      $t2, 0($t1)                         # $t2 <- array[r]

    lw      $t1, 16($sp)                        # $t1 = p <- left
    sll     $t1, $t1, 2                         # $t1 <- 4 * p
    add     $t1, $t0, $t1                       # $t1 <- &array[p]
    lw      $t3, 0($t1)                         # $t3 <- array[p]

    blt     $t2, $t3, swap_and_recurse          # if array[r] < array[p], call function again recursively

    addi    $s1, $s1, -1                        # r--
    j       inner_while_r                       # continue inner_while_r loop

swap_and_recurse:
    blt     $s0, $s1, exit_loop_swap            # if l < r, go to exit loop and swap
    lw      $t0, 20($sp)                        # $t0 <- &array[0]

    lw      $t1, 16($sp)                        # p <- left
    sll     $t1, $t1, 2                         # $t1 <- 4 * p
    add     $a0, $t0, $t1                       # $a0 <- &array[p]

    sll     $t1, $s1, 2                         # $t1 <- 4 * r
    add     $a1, $t0, $t1                       # $a1 <- &array[r]

    jal     swap                                # call the swap function (swap(array[p], array[r])

    lw      $a0, 20($sp)                        # $a0 <- &array[0]
    lw      $a1, 16($sp)                        # $a1 <- left
    addi    $a2, $s1, -1                        # $a2 <- r - 1
    jal     recursive_sort                      # call recursive_sort(A, left, r - 1)

    lw      $a0, 20($sp)                        # $a0 <- &array[0]
    addi    $a1, $s1, 1                         # $a1 <- r + 1
    lw      $a2, 12($sp)                        # $a2 <- right
    jal     recursive_sort                      # call recursive_sort(A, r + 1, right)

    j       return                              # jump to return

exit_loop_swap:
    lw      $t0, 20($sp)                        # $t0 <- &array[0]

    sll     $t1, $s0, 2                         # $t1 <- 4 * l
    add     $a0, $t0, $t1                       # $a0 <- &array[l]

    sll     $t1, $s1, 2                         # $t1 <- 4 * r
    add     $a1, $t0, $t1                       # $a1 <- &array[r]

    jal     swap                                # call the swap function (swap(array[l], array[r])
    j       outer_while                         # continue outer_while loop

# swap procedure to swap elements as address stored in $a0 and $a1

swap:
    lw      $t0, 0($a0)                     
    lw      $t1, 0($a1)                      
    sw      $t0, 0($a1) 
    sw      $t1, 0($a0)                      
    jr      $ra                             

return:
    # restore values stored in stack and deallocate

    lw      $s1, 0($sp)                         # restore value of $s1
    lw      $s0, 4($sp)                         # restore value of $s0
    lw      $ra, 8($sp)                         # get $ra from stack

    # pop elements to retain stack pointer assignment at the end of function

    addi    $sp, $sp, 24
    jr      $ra                                 # jump to return address