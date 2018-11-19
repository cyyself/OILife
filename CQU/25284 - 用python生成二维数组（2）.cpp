#!/usr/bin/env python3
n,m = map(int,input().split())
cur = 0
ans = []
for i in range(n):
	tmp = []
	for j in range(m):
		tmp.append(cur)
		cur += 1
	ans.append(tmp)
print(ans)
