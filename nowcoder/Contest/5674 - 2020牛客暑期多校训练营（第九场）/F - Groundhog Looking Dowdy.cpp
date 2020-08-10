#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
pair <int,int> a[maxn*2];
int cnt[maxn];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int len = 0;
	for (int i=1;i<=n;i++) {
		int sz;
		scanf("%d",&sz);
		for (int j=0;j<sz;j++) {
			int val;
			scanf("%d",&val);
			a[len++] = make_pair(val,i);
		}
	}
	sort(a,a+len);
	len = unique(a,a+len) - a;
	int l = 0,r = 0;
	cnt[a[0].second] ++;
	int tot = 1;
	while (tot < m) {
		if (cnt[a[r+1].second] == 0) tot ++;
		cnt[a[r+1].second] ++;
		r ++;
	}
	int ans = 1e9;
	while (r < len) {
		ans = min(ans,a[r].first-a[l].first);
		if (r + 1 < len) {
			if (cnt[a[r+1].second] == 0) tot ++;
			cnt[a[r+1].second] ++;
			while (tot > m) {
				if (cnt[a[l].second] == 1) tot --;
				cnt[a[l].second] --;
				l ++;
			}
			while (cnt[a[l].second] > 1) {
				cnt[a[l].second] --;
				l ++;
			}
		}
		r ++;
	}
	printf("%d\n",ans);
	return 0;
}
