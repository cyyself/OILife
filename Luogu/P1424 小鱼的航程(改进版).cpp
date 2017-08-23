#include <cstdio>
int main() {
	long long x,n;
	scanf("%lld%lld",&x,&n);
	long long ans = 0;
	for (long long i=x;i<x+n;i++) if (i % 7 != 0 && i % 7 != 6) ans += 250;
	printf("%lld\n",ans);
	return 0;
}