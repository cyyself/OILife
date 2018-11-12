#!/usr/bin/env python3
from math import *
class Pos():
	def __init__(self):
		self.x,self.y = map(int,input().split())
def getdir(a,b):
	if a.x > b.x:
		if a.y > b.y:
			return 1
		else:
			return 2
	else:
		if a.y > b.y:
			return 3
		else:
			return 4
T = int(input())
for t in range(T):
	n = input()
	a = Pos()
	b = Pos()
	c = Pos()
	if (abs(a.x - b.x) == abs(a.y - b.y) or abs(c.x - b.x) == abs(c.y - b.y) or a.x == b.x or a.y == b.y or c.x == b.x or c.y == b.y):
		print('No')
	else:
		d1 = getdir(a,b)
		d2 = getdir(c,b)
		if (d1 == d2):
			print('Yes')
		else:
			print('No')
