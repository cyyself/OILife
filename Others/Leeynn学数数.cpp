#include <bits/stdc++.h>
using namespace std;
long long tr[4][100005];
long long a[100005];
int n;
inline int lowbit(int x) {
	return x & (-x);
}
inline long long sum(int t,int pos) {
	long long sum = 0;
	for (int i=pos;i>=1;i-=lowbit(i)) sum += tr[t][i];
	return sum;
}
inline void add(int t,int pos,int d) {
	for (int i=pos;i<=n;i+=lowbit(i)) tr[t][i] += d;
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		add(i%4,i,a[i]);
	}
	int q;
	scanf("%d",&q);
	while (q --) {
		int o,u,v;
		scanf("%d%d%d",&o,&u,&v);
		if (o == 1) {
			int d = v - a[u];
			add(u%4,u,d);
			a[u] = v;
		}
		else {
			long long ans = sum(u%4,v) - sum(u%4,u-1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
