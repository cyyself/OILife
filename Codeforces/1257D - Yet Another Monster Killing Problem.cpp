#include <bits/stdc++.h>
using namespace std;
int a[200005];
pair <int,int> h[200005];
int main() {
	int t;
	scanf("%d",&t);
	while (t --) {
		int n;
		scanf("%d",&n);
		int ma = 0;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			ma = max(ma,a[i]);
		}
		int m;
		scanf("%d",&m);
		for (int i=0;i<m;i++) scanf("%d%d",&h[i].first,&h[i].second);
		sort(h,h+m);
		for (int i=m-2;i>=0;i--) h[i].second = max(h[i+1].second,h[i].second);
		if (h[m-1].first < ma) {
			printf("-1\n");
			continue;
		}
		int p1 = 0, p2 = 0;
		int ans = 0;
		while (p1 < n) {
			p2 = p1;
			int mx = a[p1];
			while (p2 < n - 1) {
				auto x = upper_bound(h,h+m,make_pair(max(mx,a[p2+1]),0));
				if (x != h+m && x->second >= p2 - p1 + 2) {
					mx = max(mx,a[p2+1]);
					p2 ++;
				}
				else break;
			}
			p1 = p2 + 1;
			ans ++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
