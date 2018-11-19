#!/usr/bin/env python3
m,n,k = map(int,input().split())
a = []
for i in range(m):
	a.append(list(map(int,input().split())))
b = []
for i in range(n):
	b.append(list(map(int,input().split())))
for i in range(m):
	for j in range(k):
		tmp = 0
		for l in range(n):
			tmp += a[i][l] * b[l][j]
		if j != 0:
			print(' ',end='')
		print(tmp,end='')
	print('')
