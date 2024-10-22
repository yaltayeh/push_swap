import sys
import os
import random

argc = len(sys.argv)

if argc != 2:
	os.write(2, b"Enter random array len")
	exit(1)

array = []
for i in range(int(sys.argv[1])):
	num = random.randrange(-2147483648, 2147483647)
	if num not in array:
		array.append(num)

print(*array, sep=" ")