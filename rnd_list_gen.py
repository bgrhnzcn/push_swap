import random as ran
import sys


maxValue = int(sys.argv[1])
values = []
while len(values) <= maxValue:
	input = ran.randint(0, maxValue)
	if input not in values:
		values.append(input)

while len(values) >= 1:
	sys.stdout.write(str(values.pop()))
	if len(values) != 1:
		sys.stdout.write(" ")
