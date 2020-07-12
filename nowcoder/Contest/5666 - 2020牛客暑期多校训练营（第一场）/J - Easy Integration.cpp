#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+5;
const long long mo = 998244353;
long long fac[maxn];
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
long long inv(long long x) {
	return qpow(x,mo-2);
}
int main() {
	fac[1] = 1;
	for (int i=2;i<maxn;i++) fac[i] = (fac[i-1] * i) % mo;
	long long n;
	while (scanf("%lld",&n) == 1) {
		long long ans = fac[2 * n + 1];
		ans = (ans * qpow(inv(fac[n]),2)) % mo;
		printf("%lld\n",inv(ans));
	}
	return 0;
}
