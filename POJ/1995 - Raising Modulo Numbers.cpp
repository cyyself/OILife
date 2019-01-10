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
int main() {
	int Z;
	scanf("%d",&Z);
	while (Z--) {
		int m,h;
		scanf("%d%d",&m,&h);
		int sum = 0;
		while (h --) {
			int a,b;
			scanf("%d%d",&a,&b);
			sum += qpow(a,b,m);
			sum %= m;
		}
		printf("%d\n",sum);
	}
	return 0;
}
