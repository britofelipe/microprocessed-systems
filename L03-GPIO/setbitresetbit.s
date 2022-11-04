lui t0, 0x40000
addi t0, t0, 0x700

# Set pin 0
lw t1, 0x14(t0)		# ODR address
ori t1, t1, 0x1		# mask set pin 0

# Reset pin 1
addi t2, zero, 0x2	# t2 = 0b10
xori t2, t2, -1		# t2 = 1...1101
and t1, t1, t2		# mask reset pin 1
sw t1, 0x14(t0)