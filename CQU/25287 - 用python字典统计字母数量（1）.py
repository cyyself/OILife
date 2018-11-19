#!/usr/bin/env python3
s = input()
dic = {}
for c in s:
	if (dic.__contains__(c)):
		dic[c] += 1
	else:
		dic[c] = 1
for i in sorted(dic.keys()):
	print(i,dic[i])
