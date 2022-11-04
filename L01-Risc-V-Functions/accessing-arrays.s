# int array[5];
# array[0] = array[0] * 2;
# array[1] = array[1] * 2;

# s0 = array base address

lui s0, 0x00000
addi s0, zero, 0x000

lw t1, 0(s0)
slli t1, t1, 1
sw t1, 0(s0)

lw t1, 4(s0)
slli t1, t1, 1
sw t1, 4(s0)