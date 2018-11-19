#!/usr/bin/env python3
s = input()
dic = {}
for c in s:
	t = c.upper()
	if (dic.__contains__(t)):
		dic[t] += 1
	else:
		dic[t] = 1
for i in sorted(dic.keys()):
	print(i,dic[i])
