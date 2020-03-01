#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 305;
struct obs {
	double degl,degr;
	int l,r;
	int w;
}a[maxn];
vector <double> all_deg;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long dp[maxn*2][maxn*2];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		all_deg.clear();
		for (int i=0;i<n;i++) {
			int h,l,r;
			scanf("%d%d%d",&h,&l,&r);
			a[i].degl = - atan2(h,l);
			a[i].degr = - atan2(h,r);
			scanf("%d",&a[i].w);
			all_deg.push_back(a[i].degl);
			all_deg.push_back(a[i].degr);
		}
		sort(all_deg.begin(),all_deg.end());
		all_deg.erase(unique(all_deg.begin(),all_deg.end()),all_deg.end());
		for (int i=0;i<n;i++) {
			a[i].l = lower_bound(all_deg.begin(),all_deg.end(),a[i].degl) - all_deg.begin();
			a[i].r = lower_bound(all_deg.begin(),all_deg.end(),a[i].degr) - all_deg.begin();
		}
		for (int len=1;len<=all_deg.size();len++) {
			for (int i=0;i+len-1<all_deg.size();i++) {
				int j = i + len - 1;
				dp[i][j] = inf;
				int sel = -1;
				for (int k=0;k<n;k++) if (i <= a[k].l && a[k].r <= j) {
					if (sel == -1 || a[k].w > a[sel].w) sel = k;
				}
				if (sel == -1) {
					dp[i][j] = 0;
				}
				else for (int k=a[sel].l;k<=a[sel].r;k++) dp[i][j] = min(dp[i][j],(k-1>=0?dp[i][k-1]:0)+a[sel].w+dp[k+1][j]);
			}
		}
		printf("%lld\n",dp[0][all_deg.size()-1]);
	}
	return 0;
}
