#include <bits/stdc++.h>
using namespace std;
const long long mo = 998244353;
#define x first
#define y second
long long fac[20000005],inv[20000005];
long long l,d,m;
long long qpow(long long a,long long b) {
	long long ret = 1;
	while (b) {
		if (b & 1) {
			ret *= a;
			ret %= mo;
		}
		b >>= 1;
		a *= a;
		a %= mo;
	}
	return ret;
}
long long c(long long n,long long m) {
	if (n < 0 || m < 0 || m > n) return 0;
	return (((fac[n] * inv[m]) % mo) * inv[n-m]) % mo;
}
void init() {
	fac[0] = 1;
	for (int i=1;i<=2*l;i++) {
		fac[i] = fac[i-1] * i;
		fac[i] %= mo;
	}
	inv[2*l] = qpow(fac[2*l],mo-2);
	for (int i=2*l-1;i>=0;i--) {
		inv[i] = inv[i+1] * (i + 1LL);
		inv[i] %= mo;
	}
}
long long f[10000005],pre[10000005];
long long g[3005][2];
pair <long long,long long> a[3005];
int main() {
	scanf("%lld%lld%lld",&l,&d,&m);
	init();
	f[0] = pre[0] = 1;
	for (int i=1;i<=l;i++) {
		if (i >= d) f[i] = pre[i-d];
		pre[i] = pre[i-1] + f[i];
		if (pre[i] >= mo) pre[i] -= mo;
	}
	for (int i=1;i<=m;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
	sort(a+1,a+1+m);
	long long ans = f[l];
	g[0][0] = 1;
	for (int i=1;i<=m;i++) {
		for (int j=0;j<i;j++) {
			long long dt = a[i].x - a[j].x;
			long long dp = a[i].y - a[j].y - dt * d;
			if (dt <= 0 || dp < 0) continue;
			long long cur = c(dp+dt-1,dt-1);
			g[i][1] += cur * g[j][0];
			g[i][1] %= mo;
			g[i][0] += cur * g[j][1];
			g[i][0] %= mo;
		}
		long long cur = (g[i][1] - g[i][0]) * f[l-a[i].y];
		ans -= cur;
		ans = (ans % mo + mo) % mo;
	}
	printf("%lld\n",ans);
	return 0;
}
