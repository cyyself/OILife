def exgcd(q,w,x,y):
	if w == 0:
		x[0] = 1
		y[0] = 0
		return q
	else:
		ret = exgcd(w,q%w,y,x)
		y[0] -= x[0] * (q//w)
		return ret

def work():
	if n == 1:
		if (a[0] > b[0]):
			return b[0]
		else:
			return -1
	else:
		flag = True
		a1 = a[0]
		b1 = b[0]
		ans = b[0]
		for i in range(1,n):
			a2 = a[i]
			b2 = b[i]
			k1 = [0]
			k2 = [0]
			g = exgcd(a1,a[i],k1,k2)
			if (b2 - b1) % g != 0:
				flag = False
			if not flag:
				break
			k1[0] *= (b2 -b1) // g
			xs = a2 // g
			k1[0] = k1[0] % xs
			b1 += k1[0] * a1
			a1 = (a1 // g) * a2
		if flag:
			return b1
		else:
			return -1

a = []
b = []
n,m = map(int,input().split())
for i in range(n):
	x,y = map(int,input().split())
	a.append(x)
	b.append(y)
ans = work()
if ans == -1:
	print('he was definitely lying')
elif ans > m:
	print('he was probably lying')
else:
	print(ans)
