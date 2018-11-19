#!/usr/bin/env python3
while True:
	try:
		s = input()
	except EOFError:
		break
	print(s[::-1])
