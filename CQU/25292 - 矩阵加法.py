#!/usr/bin/env python3
n,m=map(int,input().split())
a = []
for i in range(n):
	a.append(list(map(int,input().split())))
b = []
for i in range(n):
	b.append(list(map(int,input().split())))
for i in range(n):
	for j in range(m):
		if j != 0:
			print(' ',end='')
		print(a[i][j]+b[i][j],end='')
	print('')
