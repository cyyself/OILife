#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
int main() {
	int n;
	scanf("%d",&n);
	long long ans = 1;
	while (n --) {
		long long x;
		scanf("%lld",&x);
		x /= gcd(x,ans);
		ans *= x;
	}
	printf("%lld\n",ans);
	return 0;
}
