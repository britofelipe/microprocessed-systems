# C Code
# int main() 
# {
#   int y;
#   ...
#   y = diffofsums(2, 3, 4, 5);  // 4 arguments
#   ...
# }

# int diffofsums(int f, int g, int h, int i)
# {
#   int result;
#   result = (f + g) - (h + i);
#   return result;               // return value
# }

# s7 = y

addi a0, zero, 2
addi a1, zero, 3
addi a2, zero, 4
addi a3, zero, 5
jal diffofsums
add s7, a0, zero

diffofsums:
	addi sp, sp, -8
    sw t0, 4(sp)
    sw t1, 0(sp)
    
	add t0, a0, a1
    add t1, a2, a3
    sub a0, t0, t1
    
    lw t0, 4(sp)
    lw t1, 0(sp)
    addi sp, sp, 8
    
    jr ra