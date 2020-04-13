#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
long long a[maxn],b[maxn];
long long pre[maxn];
long long query(int l,int r) {
	if (l > r) return 0;
	return pre[r] - pre[l-1];
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]);
		for (int i=1;i<=n;i++) pre[i] = pre[i-1] + max(0ll,a[i]-b[i==1?n:i-1]);
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (int i=1;i<=n;i++) {
			ans = min(ans,a[i]+query(1,i-1)+query(i+1,n));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
