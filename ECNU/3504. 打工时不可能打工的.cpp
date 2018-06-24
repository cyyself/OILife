#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main() {
	int n;
	scanf("%d",&n);
	long long cost = 0;
	for (int i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	for (int i=0;i<n;i++) {
		long long t;
		scanf("%lld",&t);
		cost += t;
	}
	int ans = 0;
	for (int i=n-1;i>=0;i--) {
		ans ++;
		cost -= a[i];
		if (cost <= 0) break;
	}
	if (cost > 0) printf("Game Over!\n");
	else printf("%d\n",ans);
	return 0;
}
