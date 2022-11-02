# s0 = f, s1 = g, s2 = h
# s3 = i, s4 = j

# if (i == j)
#   f = g + h;
# f = f – i;

addi s0, zero, 1
addi s1, zero, 2
addi s2, zero, 3
addi s3, zero, 4
addi s4, zero, 5

bne s3, s4, target
add s0, s1, s2

target:
	sub s0, s0, s3