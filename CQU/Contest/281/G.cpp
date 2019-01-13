#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		long long ans = 0;
		for (int i=1;i<n;i++) {
			ans += a[i] - a[0];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
