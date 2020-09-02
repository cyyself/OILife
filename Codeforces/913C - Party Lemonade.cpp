#include <bits/stdc++.h>
using namespace std;
long long a[31];
int main() {
	int n,L;
	scanf("%d%d",&n,&L);
	memset(a,0x3f,sizeof(a));
	for (int i=0;i<n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<30;i++) a[i] = min(a[i],a[i-1] << 1);
	long long high = 0;
	long long cost = 0;
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i=30;i>=0;i--) {
		if (L & (1 << i)) {
			high |= 1 << i;
			cost += a[i];
		}
		long long cur = cost;
		if (L - high) cur += a[i];
		ans = min(ans,cur);
	}
	printf("%lld\n",ans);
	return 0;
}
