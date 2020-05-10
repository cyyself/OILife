a = input().strip().split("+")
ans = 0
for x in a:
    if x.find('d') != -1:
        n = int(x[0:x.find('d')])
        d = int(x[x.find('d')+1:])
        ans += n * (1 + d)
    else:
        ans += int(x) * 2
if ans % 2:
    print("{}.5".format(ans//2))
else:
    print(ans // 2)
