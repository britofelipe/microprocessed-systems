# add the powers of 2 from 1 
# to 100
# int sum = 0;
# int i;

# for (i=1; i < 101; i = i*2) {
#   sum = sum + i;
# }

# s0 = i, s1 = sum

addi s0, zero, 1
addi s1, zero, 0
addi t0, zero, 101

for:
	slt t2, s0, s0
    beq t2, zero, done
    add s1, s1, s0
    slli s0, s0, 1
    j for
    
done: