#include <cstdio>
long long exgcd(long long a,long long b,long long &x,long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		long long ret = exgcd(b,a%b,y,x);
		y -= x * (a / b);
		return ret;
	}
}
int main() {
	long long a,b,c,k;
	while (scanf("%lld%lld%lld%lld",&a,&b,&c,&k) == 4) {
		if (a == 0 && b == 0 && c == 0 && k == 0) break;
		long long x,y;
		long long g = exgcd((1LL<<k),c,x,y);
		if ((b-a) % g != 0) printf("FOREVER\n");
		else {
			y *= (b-a)/g;
			y %= 1LL << k;
			y = (y % ((1LL << k) / g) + ((1LL << k) / g)) % ((1LL << k) / g);
			printf("%lld\n",y);
		}
	}
	return 0;
}
