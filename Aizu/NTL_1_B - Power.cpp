#include <bits/stdc++.h>
using namespace std;
long long qpow(long long a,long long b) {
	long long ret = 1;
	while (b) {
		if (b & 1) {
			ret *= a;
			ret %= 1000000007;
		}
		a *= a;
		a %= 1000000007;
		b >>= 1;
	}
	return ret;
}
int main() {
	long long m,n;
	scanf("%lld%lld",&m,&n);
	printf("%lld\n",qpow(m,n));
	return 0;
}
