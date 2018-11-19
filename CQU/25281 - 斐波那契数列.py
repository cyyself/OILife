#!/usr/bin/env python3
a = 0
b = 1
n = int(input())
for i in range(n):
	cur = a + b
	a = b
	b = cur
print(b)
