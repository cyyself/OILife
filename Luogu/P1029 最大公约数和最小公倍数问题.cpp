#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
int main() {
	long long x,y;
	scanf("%lld%lld",&x,&y);
	long long n = x * y;
	int ans = 0;
	for (long long p=1;p*p<=n;p++) {
		if (n % p == 0) {
			int q = n / p;
			if (gcd(p,q) == x) ans += 2;
		}
	}
	printf("%d\n",ans);
	return 0;
}
