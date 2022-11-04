# int factorial(int n) {
#  if (n <= 1)
#     return 1;

#  else
#     return (n*factorial(n−1));
# }

addi a0, zero, 3

factorial:
	addi sp, sp, -8		# save registers
	sw a0, 4(sp)
	sw ra, 0(sp)
	addi t0, zero, 1	# to check if it is less or equal than one
	bgt a0, t0, else
    addi, a0, zero, 1	# if n <= 1, return 1
    addi sp, sp, 8		# restore sp
    jr ra

else:
	addi a0, a0, -1
    jal factorial
    lw t1, 4(sp)		# restore n into t1
    lw ra, 0(sp)		# restore ra
    addi sp, sp, 8		# restore sp
    mul a0, t1, a0		# a0 = n*factorial(n-1)
    jr ra
