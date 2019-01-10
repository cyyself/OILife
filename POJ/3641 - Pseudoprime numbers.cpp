#include <cstdio>
long long qpow(long long a,long long p,long long mo) {
	long long ret = 1;
	while (p) {
		if (p & 1) {
			ret *= a;
			ret %= mo;
		}
		a *= a;
		a %= mo;
		p >>= 1;
	}
	return ret % mo;
}
bool prime(register int x) {
	for (register int i=2;i*i<=x;i++) {
		if (x % i == 0) return false;
	}
	return true;
}
int main() {
	long long p,a;
	while (scanf("%lld%lld",&p,&a) == 2) {
		if (p == 0 && a == 0) break;
		if ((!prime(p)) && qpow(a,p,p) == a) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
