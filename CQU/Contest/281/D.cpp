#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long x,y;
		scanf("%lld%lld",&x,&y);
		long long g = gcd(x,y);
		long long l = (x / g) * y;
		if (l % g == 0) printf("%lld\n",l/g);
		else printf("%lld %lld\n",l / g,l % g);
	}
	return 0;
}
