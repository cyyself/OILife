#!/usr/bin/env python3
T = int(input())
def dfs(dep,lasta,lastb):
	global stat
	if stat:
		return
	if dep == 10:
		stat = True
	else:
		if arr[dep] > lasta:
			dfs(dep+1,arr[dep],lastb)
		if arr[dep] > lastb:
			dfs(dep+1,lasta,arr[dep])
while T > 0:
	T -= 1
	arr = list(map(int,input().split()))
	stat = False
	dfs(0,-1,-1)
	if stat:
		print('YES')
	else:
		print('NO')
