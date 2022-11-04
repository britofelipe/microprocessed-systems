# determines the power
# of x such that 2x = 128
# int pow = 1;
# int x   = 0;

# while (pow != 128) {
#   pow = pow * 2;
#   x = x + 1;
# }

# s0 = pow, s1 = x

addi s0, zero, 1
addi s1, zero, 0
addi t0, zero, 128

power:
	beq s1, s2, done
	slli s0, s0, 1
    addi s1, s1, 1
    j power
    
done: