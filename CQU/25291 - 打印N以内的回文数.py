#!/usr/bin/env python3
def judge(s):
	l = 0
	r = len(s) - 1
	while l < r:
		if (s[l] != s[r]):
			return False
		l += 1
		r -= 1
	return True
n = int(input())
for i in range(n+1):
	if (judge(str(i))):
		print(i)
