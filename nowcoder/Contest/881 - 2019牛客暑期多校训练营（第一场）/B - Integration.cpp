#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e9+7;
long long qpow(long long a,long long b) {
	long long ret = 1;
	while (b) {
		if (b & 1) {
			ret *= a;
			ret %= mo;
		}
		a *= a;
		a %= mo;
		b >>= 1;
	}
	return ret;
}
long long inv(long long x) {
	return qpow(x,mo-2);
}
long long a[1005];
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		long long ans = 0;
		for (int i=1;i<=n;i++) {
			long long fm = (a[i] * 2) % mo;
			for (int j=1;j<=n;j++) {
				if (j == i) continue;
				fm *= ( (a[j] * a[j]) % mo - (a[i] * a[i]) % mo + mo) % mo;
				fm %= mo;
			}
			ans += inv(fm);
			ans %= mo;
		}
		printf("%lld\n",ans);
	}
	return 0;
}