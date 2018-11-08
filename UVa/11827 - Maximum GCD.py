#!/usr/bin/env python3
def gcd(a,b):
	if b == 0: 
		return a
	else:
		return gcd(b,a%b)
n = int(input())
for i in range(n):
	a = input().split()
	ans = 1
	for x in a:
		for y in a:
			if (x != y):
				ans = max(ans,gcd(int(x),int(y)))
	print(ans)
