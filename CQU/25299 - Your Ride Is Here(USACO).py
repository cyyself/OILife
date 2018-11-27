#!/usr/bin/env python3
def cal(s):
	ret = 1
	for c in s:
		ret *= ord(c)-ord('A')+1
		ret %= 47
	return ret
if cal(input()) == cal(input()):
	print('GO')
else:
	print('STAY')
