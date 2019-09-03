#include <bits/stdc++.h>
using namespace std;
long long sum(long long x) {
	return x * (x + 1) / 2;
}
int main() {
	long long n,k;
	scanf("%lld%lld",&n,&k);
	long long ans = n * k;
	n = min(n,k);
	for (int l=1,r;l<=n;l=r+1) {
		r = min(k / (k / l),n);
		ans -= (sum(r) - sum(l-1)) * (k / l);
	}
	printf("%lld\n",ans);
	return 0;
}
