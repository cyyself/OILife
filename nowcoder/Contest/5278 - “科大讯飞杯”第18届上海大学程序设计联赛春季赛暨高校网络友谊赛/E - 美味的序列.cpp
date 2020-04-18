#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
long long a[maxn];
int main() {
	long long n;
	scanf("%lld",&n);
	long long ans = - n * (n-1) / 2;
	for (int i=1;i<=n;i++) {
		long long t;
		scanf("%lld",&t);
		ans += t;
	}
	printf("%lld\n",ans);
	return 0;
}
