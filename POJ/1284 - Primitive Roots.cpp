#include <cstdio>
long long phi(long long x) {
	long long ret = x;
	for (int i=2;i*i<=x;i++) {
		if (x % i == 0) {
			ret /= i;
			ret *= i - 1;
		}
		while (x % i == 0) x /= i;
	}
	if (x > 1) {
		ret /= x;
		ret *= x - 1;
	}
	return ret;
}
int main() {
	long long p;
	while (scanf("%lld",&p) == 1) printf("%lld\n",phi(phi(p)));
	return 0;
}
