#!/usr/bin/env python3
n,m = map(int,input().split())
tmp = [0] * m
tmp[0] = 1
tmp[-1] = -1
ans = [tmp] * n
print(ans)
