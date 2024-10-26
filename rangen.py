import sys
import os
import random

argc = len(sys.argv)

if argc != 2:
	os.write(2, b"Enter random array len")
	exit(1)

array = random.sample(range(0, 2147483647), int(sys.argv[1]))

print(*array, sep=" ")