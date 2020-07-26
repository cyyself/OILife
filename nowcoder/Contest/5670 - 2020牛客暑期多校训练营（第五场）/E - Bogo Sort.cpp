from collections import Counter
import functools
def dfs(x):
    global vst,cnt,a
    #vst[x] = True
    #Size[cnt] += 1
    while (not vst[x]):
        vst[x] = True
        Size[cnt] += 1
        x = a[x]
    #if (not vst[a[x]]):
    #   dfs(a[x])
n = int(input())
a = [int(0)] + list(map(int,input().split()))
Size = [int(0)] * (n + 1)
vst = [False] * (n + 1)
cnt = int(0)
#线性筛 begin
pri_pre = [int(0)] * (n + 1)
primes = []
pri = [int(0)] * (n + 1)
pri[1] = True
for i in range(2,n+1):
    if not pri[i]:
        primes.append(i)
    for p in primes:
        if i * p > n:
            break
        pri[i*p] = True
        pri_pre[i*p] = p
        if i % p == 0:
            break
#线性筛 end
for i in range(1,n+1):
    if (not vst[i]):
        cnt += 1
        dfs(i)
ans = []
for i in range(1,cnt+1):
    cur = Size[i]
    cur_cnt = Counter()
    while (pri_pre[cur] != 0):
        cur_cnt[pri_pre[cur]] += 1
        cur //= pri_pre[cur]
    if cur > 1:
        cur_cnt[cur] += 1
    if (len(cur_cnt)):
        ans.append(cur_cnt)
def cmp(x,y):
    return len(y) - len(x)
ans = sorted(ans,key=functools.cmp_to_key(cmp))
merge_ans = Counter()
for x in ans:
    merge_ans |= x
result = 1
for p,pp in merge_ans.items():
    result *= p ** pp
print(result)
