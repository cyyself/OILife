#!/usr/bin/env python3
while True:
	try:
		s = input()
	except EOFError:
		break
	s = list(s)
	for i in range(1,len(s),2):
		t = s[i]
		s[i] = s[i-1]
		s[i-1] = t
	print(''.join(s))
