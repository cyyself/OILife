#!/usr/bin/env python3
while True:
	try:
		s = input().split('#')
	except EOFError:
		break
	if s[1].find(s[0]) != -1:
		print('YES')
	else:
		print('NO')
