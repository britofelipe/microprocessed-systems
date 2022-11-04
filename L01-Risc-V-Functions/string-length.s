#  C Code
# 	char str[80] = “CAT”;
# 	int len = 0;

# compute length of string
# while (str[len]) len++;

# RISC-V assembly code
# s0 = array base address, s1 = len

addi s1, zero, 0	# len = 0

while:
	add t0, s0, s1		# address of str[len]
    lw t1, 0(t0)		# load str[len]
    beq t1, zero, done	# end of the string?
    addi s1, s1, 1		# len++
    j while

done: