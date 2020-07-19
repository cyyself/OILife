#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e5+5;
pair <int,int> a[maxm];
long long pre[maxm];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;i++) scanf("%d%d",&a[i].first,&a[i].second);
		sort(a,a+m);
		reverse(a,a+m);
		pre[0] = a[0].first;
		for (int i=1;i<m;i++) pre[i] = pre[i-1] + a[i].first;
		long long ans = 0;
		if (n <= m) ans = pre[n-1];
		for (int i=0;i<m;i++) {
			int l = 0, r = min(m-1,n-1), pos = -1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (a[mid].first >= a[i].second) {
					pos = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			if (pos == -1) {
				ans = max(ans,a[i].first + 1ll*(n-1) * a[i].second);
			}
			else {
				if (pos == n - 1) {
					ans = max(ans,pre[n-1]);
				}
				else {
					if (i <= pos) {
						ans = max(ans,pre[pos] + 1ll*(n-(pos+1)) * a[i].second);
					}
					else {
						ans = max(ans,pre[pos] + a[i].first + max(1ll*(n-(pos+1)-1),0ll) * a[i].second);
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
