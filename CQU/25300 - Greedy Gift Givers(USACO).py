#!/usr/bin/env python3
n = int(input())
ans = {}
namelist = []
for i in range(n):
	name = input().strip()
	namelist.append(name)
	ans[name] = 0

for i in range(n):
	name = input().strip()
	m,k=map(int,input().split())
	if k == 0:
		continue
	ans[name] -= m
	ans[name] += m % k
	for j in range(k):
		to = input().strip()
		ans[to] += m // k
for key in namelist:
	print(key,ans[key])
