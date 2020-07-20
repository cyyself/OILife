#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
bool judge[maxn];
vector <long long> primes;
long long pre[maxn];
inline void getprime(int x) {
	judge[1] = true;
	for (int i=2;i<=x;i++) {
		if (!judge[i]) primes.push_back(i);
		for (auto p:primes) {
			if (i * p > x) break;
			judge[i*p] = true;
			pre[i*p] = p;
			if (i % p == 0) break;
		}
	}
}
const long long mo = 1e9+7;
long long qpow(long long a,long long b) {
	long long ret = 1;
	while(b) {
		if(b & 1) {
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
	getprime(1e6);
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n,c;
		scanf("%lld%lld",&n,&c);
		if (n == 1) printf("1\n");
		else {
			long long cnt = 0;
			long long nn = n;
			while (pre[nn]) {
				cnt ++;
				nn /= pre[nn];
			}
			cnt ++;
			printf("%lld\n",qpow(c,cnt));
		}
	}
	return 0;
}
