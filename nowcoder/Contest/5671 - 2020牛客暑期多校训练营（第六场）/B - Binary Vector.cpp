#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e9+7;
long long qpow(long long a,long long b) {
	long long res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
			res %= mo;
		}
		a *= a;
		a %= mo;
		b >>= 1;
	}
	return res;
}
const int maxn = 2e7;
int base[maxn+5],base_rev[maxn+5];
int ans[maxn+5];
int main() {
	base[0] = 1;
	for (int i=1;i<=maxn;i++) base[i] = (base[i-1] * 2ll) % mo;
	base_rev[maxn] = qpow(base[maxn],mo-2);
	for (int i=maxn-1;i>=0;i--) base_rev[i] = (base_rev[i+1] * 2ll) % mo;
	ans[0] = 1;
	for (int i=1;i<=maxn;i++) {
		ans[i] = (((1ll * ans[i-1] * ((base[i]-1+mo) % mo) ) % mo) * base_rev[i]) % mo;
	}
	for (int i=2;i<=maxn;i++) ans[i] ^= ans[i-1];
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}
