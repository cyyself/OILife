#!/usr/bin/env python3
n = int(input())
for i in range(n):
	tmp = list(map(int,input().split()))
	tmp.sort()
	print(tmp[0],end='')
	for x in tmp[1:]:
		print(':%d'%(x),end='')
	print('')
