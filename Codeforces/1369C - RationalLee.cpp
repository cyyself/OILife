#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int a[maxn];
vector <int> w;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,k;
		scanf("%d%d",&n,&k);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		int onecnt = 0;
		for (int i=0;i<k;i++) {
			int tmp;
			scanf("%d",&tmp);
			if (tmp == 1) onecnt ++;
			else w.push_back(tmp);
		}
		sort(a,a+n);
		sort(w.begin(),w.end());
		reverse(w.begin(),w.end());
		long long ans = 0;
		for (int i=n-1;i>=n-onecnt;i--) ans += 2ll*a[i];
		int l = 0,r = n - 1 - onecnt;
		for (auto len:w) {
			ans += 1ll*a[l] + a[r];
			l += len - 1;
			r --;
		}
		printf("%lld\n",ans);
		w.clear();
	}
	return 0;
}
