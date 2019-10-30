#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		deque <pair<int,long long> > q;
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		bool ans = true;
		a[n+1] = 0;
		for (int i=1;i<=n+1 && ans;i++) {
			if (a[i] > a[i-1]) {
				q.push_back({i,a[i]-a[i-1]});
			}
			else if (a[i] < a[i-1]) {
				long long rem = a[i-1] - a[i];
				while (rem && ans) {
					auto f = q.front();
					q.pop_front();
					long long c = min(f.second,rem);
					rem -= c;
 					if ((i - f.first) != 1 && (i - f.first) != 2) {
 						if (f.second - c > 0) q.push_front({f.first,f.second-c});
					}
					else ans = false;
				}
			}
		}
		if (ans) printf("Case #%d: Yes\n",cas);
		else printf("Case #%d: No\n",cas);
	}
	return 0;
}
