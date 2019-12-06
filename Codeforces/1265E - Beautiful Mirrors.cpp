#include <bits/stdc++.h>
using namespace std;
const long long mo = 998244353;
long long p[200005];
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
long long e[200005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&p[i]);
	for (int i=1;i<=n;i++) {
		e[i] = (((e[i-1]+1)*100) % mo) * inv(p[i]);
		e[i] %= mo;
	}
	printf("%lld\n",e[n]);
	return 0;
}
