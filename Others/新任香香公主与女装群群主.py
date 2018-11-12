#!/usr/bin/env python3
from math import *
def judge(x):
	global n,k,a,w
	y = []
	for i in range(n):
		y.append(a[i] - x * w[i])
	y.sort(reverse=True)
	return sum(y[0:k]) >= 0
while True:
	global n,k,a,w
	n,k = map(int,input().split())
	if n == 0 and k == 0:
		break
	k = n - k
	a = list(map(int,input().split()))
	w = list(map(int,input().split()))
	l = 0.0
	r = 1.0
	while (r - l > 1e-5):
		mid = (l + r) / 2
		if (judge(mid)):
			l = mid
		else:
			r = mid
	print(int(round(l*100)))
