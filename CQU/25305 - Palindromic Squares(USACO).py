#!/usr/bin/env python3
def judge(s):
	l = 0
	r = len(s) - 1
	while l < r:
		if s[l] != s[r]:
			return False
		l += 1
		r -= 1
	return True
def con(x,b):
	ret = []
	while x != 0:
		tmp = x % b
		if (tmp >= 10):
			tmp = chr(65+tmp-10)
		ret = [str(tmp)] + ret
		x //= b
	return ret
b = int(input())
for i in range(1,301):
	x = con(i**2,b)
	if (judge(x)):
		print(''.join(con(i,b)),''.join(x))
