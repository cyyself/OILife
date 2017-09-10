#include <bits/stdc++.h>
using namespace std;
int f[500010];
int s[500010];
int n,m;

int q[500010];//std::queue不能取第二个元素，我也很无奈啊
int head,tail;

//f[i]=min(f[i],f[j]+(s[i]-s[j])^2+m)
/*
f[j]+(s[i]-s[j])^2+m<=f[k]+(s[i]-s[k])^2+m

(f[j]+s[j]*s[j])-(f[k]+s[k]*s[k])] / 
2(s[j]-s[k]) 
<= s[i]

*/
inline int fun(int i,int j) {
	return f[j]+(s[i]-s[j])*(s[i]-s[j]) + m;
}
inline int gety(int j,int k) {
	return f[j]+s[j]*s[j]-(f[k]+s[k]*s[k]);
}
inline int getx(int j,int k) {
	return 2*(s[j]-s[k]);
}

int main() {
	while (scanf("%d%d",&n,&m) == 2) {
		for (int i=1;i<=n;i++) {
			scanf("%d",&s[i]);
			s[i] += s[i-1];//前缀和
		}
		head = 0;
		tail = 0;
		q[tail++] = 0;
		f[0] = 0;
		for (int i=1;i<=n;i++) {
			while (head + 1 < tail && 
				gety(q[head+1],q[head]) <= 
				s[i] * getx(q[head+1],q[head])
			) head++;
			f[i] = fun(i,q[head]);
			while (head + 1 < tail && 
				gety(i,q[tail-1]) * getx(q[tail-1],q[tail-2]) <= 
				gety(q[tail-1],q[tail-2]) * getx(i,q[tail-1])
			) tail--;
			q[tail++] = i;
		}
		printf("%d\n",f[n]);
	}
	return 0;
}
