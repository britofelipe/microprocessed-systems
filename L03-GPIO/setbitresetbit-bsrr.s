# Address of BSRR of GPIOA is 0x4800 0000 + 0x18 = 0x4800 0018

lui a0, 0x48000	# a0 = 0x48000000 -> Address

lui a1, 0x00020	# a1 = 0x00020000
addi a1, a1, 0x1	# a1 = 0x00020001 -> 0 to 15 (set) and 16 to 31 (reset)

sw a1, 0x018(a0)