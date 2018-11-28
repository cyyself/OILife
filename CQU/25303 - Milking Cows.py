#!/usr/bin/env python3
import functools
class farmer:
	def __init__(self,a,b):
		self.a = a
		self.b = b
	def __lt__(self,other):
		return self.a < other.a or (self.a == other.a and self.b < other.b)
	def __eq__(self,other):
		return self.a == other.a or self.b == other.b
arr = []
n = int(input())
for i in range(n):
	s,t = map(int,input().split())
	arr.append(farmer(s,t))
arr.sort()
l = arr[0].a
r = arr[0].b
ans1 = 0
ans2 = 0
for i in arr:
	if (i.a <= r):
		r = max(r,i.b)
		ans1 = max(ans1,r-l)
	else:
		ans2 = max(ans2,i.a - r)
		l = i.a
		r = i.b
print(ans1,ans2)
