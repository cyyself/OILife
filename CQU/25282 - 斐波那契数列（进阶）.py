#!/usr/bin/env python3
exist = {}
a = 0
b = 1
for i in range(100):
	cur = a + b
	a = b
	b = cur
	exist[b] = True
n = int(input())
if (exist.__contains__(n)):
	print('True')
else:
	print('False')
