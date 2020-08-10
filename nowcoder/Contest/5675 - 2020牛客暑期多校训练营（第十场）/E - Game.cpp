#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
long long a[maxn];
int n;
bool check(long long x) {
	long long rem = 0;
	for (int i=n-1;i>=0;i--) {
		if (a[i] > x) rem += a[i] - x;
		else rem -= min(rem,x - a[i]);
	}
	return rem == 0;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%lld",&a[i]);
		int l = 0, r = 1e9;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				ans = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
