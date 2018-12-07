#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long a,b;
		scanf("%lld%lld",&a,&b);
		long long g = gcd(a,b);
		a /= g;
		b /= g;
		if (a * a - 4 * b < 0) {
			printf("-1 -1\n");
			continue;
		}
		long long x = (a-sqrt(a*a-4*b))/2;
		long long y = (a+sqrt(a*a-4*b))/2;
		if (x + y == a && x*y == b) printf("%lld %lld\n",x*g,y*g);
		else printf("-1 -1\n");
	}
	return 0;
}
