#include <bits/stdc++.h>
using namespace std;
__int128 mo;
long long qpow(__int128 a,__int128 b) {
	__int128 ret = 1;
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
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long p,n,m;
		scanf("%lld%lld%lld",&p,&n,&m);
		if (p == 2 || p == 5) {
			printf("0\n");
		}
		else {
			mo = p * 9;
			long long phi = 6LL * (p - 1LL);
			long long d = phi;
			for (long long i=2;i*i<=phi;i++) if (phi % i == 0) {
				if (qpow(10,i) == 1) d = min(d,i);
				if (qpow(10,phi/i) == 1) d = min(d,phi/i);
			}
			map <long long,long long> cnt;
			for (long long i=2;i*i<=d;i++) {
				while (d % i == 0) {
					cnt[i] ++;
					d /= i;
				}
			}
			if (d > 1) cnt[d] ++;
			long long MAX = 0;
			for (auto x:cnt) MAX = max(MAX,x.second);
			__int128 ans = 0, t;
			for (long long j=1;j<=min(MAX,m);j++) {
				t = 1;
				for (auto x:cnt) t *= qpow(x.first,(x.second+j-1)/j);
				t = n / t;
				ans += t;
			}
			ans += (m - min(m,MAX)) * t;
			long long a = ans;
			printf("%lld\n",a);
		}
	}
	return 0;
}