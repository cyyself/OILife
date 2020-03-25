#include <bits/stdc++.h>
using namespace std;
const long long mo = 998244353;
const int maxn = 5e5+5;
int l[maxn],r[maxn],x[maxn];
int rr[maxn],d[maxn],f[maxn];
int main() {
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	for (int i=0;i<m;i++) scanf("%d%d%d",&l[i],&r[i],&x[i]);
	long long ans = 1;
	for (int b=0;b<k;b++) {
		for (int i=0;i<=n+1;i++) f[i] = rr[i] = d[i] = 0;
		for (int i=0;i<m;i++) {
			if (x[i] & (1 << b)) {
				d[l[i]] ++;
				d[r[i]+1] --;
			}
			else rr[r[i]] = max(rr[r[i]],l[i]);
		}
		int pre = 0;
		int last = 0;
		for (int i=1;i<=n;i++) {
			pre += d[i];
			int add = 0;
			if (!pre) {
				if (!last) add = (f[i] + 1) % mo;
				else add = (f[i] - f[last] + mo) % mo;
			}
			f[i+1] = (f[i] + add) % mo;
			last = max(last,rr[i]);
		}
		if (last) ans *= f[n+1] - f[last] + mo;
		else ans *= f[n+1] + 1;
		ans %= mo;
	}
	printf("%lld\n",ans);
	return 0;
}
