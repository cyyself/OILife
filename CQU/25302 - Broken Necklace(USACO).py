#!/usr/bin/env python3
n = int(input()) * 3
s = input() * 3
sr = s.replace('w','r')
sb = s.replace('w','b')
#从这个点开始向左最多能取的长度（把w当成r）
lr = [1] * n
#从这个点开始向左最多能取的长度（把w当成b）
lb = [1] * n
#从这个点开始向右最多能取的长度（把w当成r）
rr = [1] * n
#从这个点开始向右最多能取的长度（把w当成b）
rb = [1] * n
for i in range(1,n):
	if (sr[i] == sr[i-1]):
		lr[i] = lr[i-1] + 1
	if (sb[i] == sb[i-1]):
		lb[i] = lb[i-1] + 1
for i in range(n-2,0,-1):
	if (sr[i] == sr[i+1]):
		rr[i] = rr[i+1] + 1
	if (sb[i] == sb[i+1]):
		rb[i] = rb[i+1] + 1
ans = 0
for i in range(n-1):
	ans = max(ans,min(n//3,max(lr[i],lb[i]) + max(rr[i+1],rb[i+1])))
print(ans)
