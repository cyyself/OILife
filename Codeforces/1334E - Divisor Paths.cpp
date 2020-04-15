#include <bits/stdc++.h>
using namespace std;
const long long mo = 998244353;
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
long long fac[65];
int main() {
	fac[0] = 1;
	for (int i=1;i<=60;i++) {
		fac[i] = fac[i-1] * i;
		fac[i] %= mo;
	}
	long long D;
	scanf("%lld",&D);
	vector <long long> p;
	for (long long i=2;i*i<=D;i++) if (D % i == 0) {
		p.push_back(i);
		while (D % i == 0) D /= i;
	}
	if (D > 1) p.push_back(D);
	int q;
	scanf("%d",&q);
	while (q --) {
		long long u,v;
		scanf("%lld%lld",&u,&v);
		int cnt1 = 0, cnt2 = 0;
		long long ans = 1;
		for (auto x:p) {
			int cur = 0;
			while (u % x == 0) {
				cur ++;
				u /= x;
			}
			while (v % x == 0) {
				cur --;
				v /= x;
			}
			if (cur > 0) {
				cnt1 += cur;
				ans *= inv(fac[cur]);
				ans %= mo;
			}
			else if (cur < 0) {
				cnt2 += -cur;
				ans *= inv(fac[-cur]);
				ans %= mo;
			}
		}
		ans *= fac[cnt1];
		ans %= mo;
		ans *= fac[cnt2];
		ans %= mo;
		printf("%lld\n",ans);
	}
	return 0;
}
