# Non-leaf function: 
#	a function that calls another function

# Must preserve ra before function call.

# f1 (non-leaf function) uses s4-s5 and needs a0-a1 after call to f2

f1:
	addi sp, sp, -20	# make space on stack for 5 words
    sw a0, 16(sp)
    sw a1, 12(sp)
    sw ra, 8(sp)		# save ra on stack
    sw s4, 4(sp)
    sw s5, 0(sp)
    jal f2
    # ...
  	lw ra, 8(sp)		# restore ra (and other registers) from stack
    # ...
    addi sp, sp, 20
    jr ra

# f2 (leaf function) only uses s4 and calls no functions

f2:
	addi sp, sp, -4
    sw s4, 0(sp)
    # ...
    lw s4, 0(sp)
    addi sp, sp, 4
    jr ra
	