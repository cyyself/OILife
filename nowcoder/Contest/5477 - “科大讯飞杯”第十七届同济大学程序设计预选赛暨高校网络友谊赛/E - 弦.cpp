#include <bits/stdc++.h>
using namespace std;
long long mo = 1e9+7;
long long qpow(long long a,long long b) {
	long long res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
			res %= mo;
		}
		b >>= 1;
		a *= a;
		a %= mo;
	}
	return res;
}
long long inv(long long x) {
	return qpow(x,mo-2);
}
const int maxn = 2e7+5;
long long fac[maxn];
int main() {
	fac[0] = 1;
	for (int i=1;i<maxn;i++) fac[i] = (fac[i-1] * i) % mo;
	long long n;
	scanf("%lld",&n);
	long long ans = (fac[2*n] * inv((fac[n+1]*fac[n])%mo))%mo;
	ans *= inv((fac[2*n]*inv(qpow(2,n)*fac[n]%mo))%mo);
	ans %= mo;
	printf("%lld\n",ans);
	return 0;
}
