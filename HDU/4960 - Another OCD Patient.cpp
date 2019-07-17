#include <bits/stdc++.h>
using namespace std;
int a[5005];
int c[5005];
long long f[5005];
int n;
vector <pair<int,int> > pos;

int main() {
	while (scanf("%d",&n) == 1 && n) {
		pos.clear();
		pos.push_back(make_pair(0,n+1));
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&c[i]);
		int l = 1,r = n + 1;
		long long lsum = a[1];
		long long rsum = 0;
		int llast = 0,rlast = n+1;
		while (l < r) {
			while (lsum < rsum && l <= n) lsum += a[++l];
			while (rsum < lsum && r >= 1) rsum += a[--r];
			if (lsum == rsum) {
				if (l < r) pos.push_back(make_pair(l,r));
				lsum += a[++l];
			}
		}
		for (int i=1;i<pos.size();i++) {
			f[i] = 0x3f3f3f3f3f3f3f3f;
			for (int j=0;j<i;j++) f[i] = min(f[i],f[j] + c[pos[i].first-pos[j].first] + c[pos[j].second-pos[i].second]);
		}
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (int i=0;i<pos.size();i++) {
			ans = min(ans,f[i]+c[pos[i].second-pos[i].first-1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
