# C Code
# 	int array[1000];
# 	int i;
# 
# 	for (i=0; i < 10; i = i + 1)
#  		array[i] = array[i] * 8;

# RISC-V assembly code
# s0 = array base address, s1 = i

lui s0, 0x00000
addi s0, zero, 0x000

addi s1, zero, 0			# i = 0
addi t2, zero, 1000			# t0 = 1000

for:
	bge s1, t2, done		# checks if i < 1000
    slli t0, s1, 2			# byte offset
    add t0, t0, s0 			# array[i] address
    lw t1, 0(t0)			# load array[i] to t2
    slli t1, t1, 3			# array[i]<<3
    sw t1, 0(t0)			# saves t2 to array[i]
    addi s1, s1, 1
    j for
    
done: