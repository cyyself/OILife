#!/usr/bin/env python3
def printline(arr):
	print(arr[0],end='')
	for x in arr[1:]:
		print('',x,end='')
	print('')
n = int(input())
last = []
for i in range(n):
	cur = [1]
	for j in range(i):
		cur.append(last[j]+last[j+1])
	printline(cur)
	last = cur
	last.append(0)
