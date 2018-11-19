#!/usr/bin/env python3
n = int(input())
dic = {}
for i in range(n):
	s = input()
	for c in s:
		t = c.upper()
		if (dic.__contains__(t)):
			dic[t] += 1
		else:
			dic[t] = 1
for i in sorted(dic.keys()):
	tmp = (i,dic[i],dic[i]>4)
	print(tmp)
