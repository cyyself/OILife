#!/usr/bin/env python3
n = int(input())
i = 1
ans = []
while i * i <= n:
	if n % i == 0:
		j = n // i
		ans.append(i + (i-1)*i*j//2)
		if (j != i):
			ans.append(j + (j-1)*j*i//2)
	i += 1
ans.sort()
for x in ans:
	print(x,end=' ')
