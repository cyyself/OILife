#include <bits/stdc++.h>
using namespace std;
const long long mo = 100000007;
long long a[100005];
long long b[100005];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (long long i=0;i<n;i++) {
		scanf("%lld",&a[i]);
		a[i] %= mo;
	}
	for (long long i=0;i<m;i++) {
		scanf("%lld",&b[i]);
		b[i] %= mo;
	}
	long long colsum = 0;
	for (long long i=0;i<m;i++) {
		colsum += (((b[i] * (i+1LL)) % mo) * (m - i)) % mo;
		colsum %= mo;
	}
	long long ans = 0;
	for (long long i=0;i<n;i++) {
		ans += (((((colsum * a[i]) % mo) * (i + 1LL) ) % mo) * (n - i)) % mo;
		ans %= mo;
	}
	printf("%lld\n",ans);
	return 0;
}
