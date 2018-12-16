#!/usr/bin/env python3
n = int(input())
b = [0] + list(map(int,input().split()))
a = [0] * (n+1)
a[1] = 0
a[n] = b[1]
for i in range(2,n//2+1):
	if (b[i] - a[i-1] <= a[n-i+2]):
		a[i]     = a[i-1]
		a[n-i+1] = b[i] - a[i]
	else:
		a[n-i+1] = a[n-i+2]
		a[i] = b[i] - a[n-i+1]
for i in range(1,n+1):
	print(a[i],end=' ')
