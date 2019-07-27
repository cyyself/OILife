#include <bits/stdc++.h>
using namespace std;
int a[300005];
int main() {
	int T,n;
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		long long ans = (long long)n * (n + 1) / 2;
		for (int i=1;i<=n;i++) {
			int l = i, r = i;
			long long sum = 0;
			while (l > 0 && sum < a[i]) sum += a[--l];
			while (l < i) {
				sum -= a[l++];
				while (r <= n && sum < a[i]) sum += a[++r];
				ans -= r - i;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}