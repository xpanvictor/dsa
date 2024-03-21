
"""
Using an 8 bit variable to store two 4 bits numbers
"""
mask = 00001111

num1 = 0101
num2 = 1101

# shifts num1 by 4 bits to left and appends num2 to remaining 4 bits
combined = 00000000
combined = combined + num1

