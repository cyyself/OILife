#!/usr/bin/env python3
# 洛谷上会TLE（显示为RE），我自己数据测试通过
n,w = map(int,input().split())
dx = (w-1)//2
X = {}
if w == 0:
	print(0)
else:
	for x in range(n):
		Xi,Bi = map(int,input().split())
		l = Xi - dx;
		r = Xi + dx + 1;
		if (l in X) == False: X[l] = [Bi]
		else: X[l].append(Bi)
		if (r in X) == False: X[r] = [-Bi]
		else: X[r].append(-Bi)
	Xkey = list(X.keys())
	Xkey.sort()
	ans = 0
	cur = 0
	for i in Xkey:
		for j in X[i]:
			cur += j
		ans = max(ans,cur)
	print(ans)
