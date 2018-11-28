#!/usr/bin/env python3
n = int(input())
#    1  2  3  4  5  6  7  8  9  10 11 12
a = (31,28,31,30,31,30,31,31,30,31,30,31)
b = (31,29,31,30,31,30,31,31,30,31,30,31)
ans = [0] * 7
cur = 0
for y in range(1900,1900+n):
	if (y % 4 == 0 and y % 100 != 0) or y % 400 == 0:
		for j in b:
			ans[(cur+12)%7] += 1
			cur += j
			cur %= 7
	else:
		for j in a:
			ans[(cur+12)%7] += 1
			cur += j
			cur %= 7
print(ans[5],ans[6],ans[0],ans[1],ans[2],ans[3],ans[4])
