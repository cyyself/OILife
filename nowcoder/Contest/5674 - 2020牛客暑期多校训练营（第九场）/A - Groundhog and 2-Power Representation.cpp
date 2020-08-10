#!/usr/bin/env python3
def qpow(a,b):
	res = 1
	while b:
		if b % 2:
			res *= a
		b //= 2
		a *= a
	return res
x = input()
print(eval(x.replace("2(","qpow(2,")))
