# Is a little endian?
# 1 for big endian
# 0 for little endian

isLittleEndian:
lui t0, 0x23456
addi t0, t0, 0x000

addi sp, sp, -4
addi t1, zero, 0xFF	# t1 = 11111111

sw t1, 0(sp)		# saves 11111111 to top of stack (sp)
lb t2, 3(zero)		# reads byte 3 of sp
beq t1, t2, bigEndian	# if the byte 3 is 0xFF, then it is a big endian (LSB in 3rd byte)
addi a0, zero, 0
j done

bigEndian:
	addi a0, zero, 1

done:
	addi sp, sp, 4
    jr ra