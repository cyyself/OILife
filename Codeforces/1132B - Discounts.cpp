#include <bits/stdc++.h>
using namespace std;
long long a[300005];
long long sum[300005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
	int m;
	scanf("%d",&m);
	while (m --) {
		int q;
		scanf("%d",&q);
		long long ans = sum[n] - sum[n-q+1] + sum[n - q];
		printf("%lld\n",ans);
	}
	return 0;
}
