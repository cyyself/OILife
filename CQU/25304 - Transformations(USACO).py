#!/usr/bin/env python3
def turn(x):
	ret = [[0 for j in range(n)] for i in range(n)]
	for i in range(n):
		for j in range(n):
			ret[j][n-1-i] = x[i][j]
	return ret
def rev(x):
	ret = [[0 for j in range(n)] for i in range(n)]
	for i in range(n):
		for j in range(n):
			ret[i][n-1-j] = x[i][j]
	return ret
def eq(a,b):
	for i in range(n):
		for j in range(n):
			if (a[i][j] != b[i][j]):
				return False
	return True
n = int(input())
a = []
b = []
for i in range(n):
	a.append(list(input()))
for i in range(n):
	b.append(list(input()))
flag = 0
for ans in range(1,3+1):
	a = turn(a)
	if eq(a,b):
		flag = ans
		break
if flag != 0:
	print(flag)
else:
	#转回去
	a = turn(a)
	a = rev(a)
	if eq(a,b):
		flag = 4
	for ans in range(1,3+1):
		a = turn(a)
		if eq(a,b):
			flag = 5
			break
	if flag != 0:
		print(flag)
	else:
		a = turn(a)
		a = rev(a)
		if eq(a,b):
			print(6)
		else:
			print(7)
