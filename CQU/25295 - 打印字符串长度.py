#!/usr/bin/env python3
while True:
	try:
		s = input()
	except EOFError:
		break
	cnt = 0
	for c in s:
		cnt += 1
	print(cnt)
