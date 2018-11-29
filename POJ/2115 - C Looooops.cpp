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
		long long len = 1LL << k;
		long long g = exgcd(len,c,x,y);
		if ((b-a) % g != 0) printf("FOREVER\n");
		else {
			y *= (b-a)/g;
			len /= g;
			if (len < 0) len = -len;
			y = (y % len + len) % len;
			printf("%lld\n",y);
		}
	}
	return 0;
}
