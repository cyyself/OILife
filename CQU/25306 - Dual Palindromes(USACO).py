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

n,s=map(int,input().split())
ans = []
while len(ans) < n:
	s += 1
	cnt = 0
	for i in range(2,11):
		if judge(con(s,i)):
			cnt += 1
		if cnt >= 2:
			ans.append(s)
			break
for x in ans:
	print(x)
