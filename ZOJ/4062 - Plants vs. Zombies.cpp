#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
long long a[maxn],cnt[maxn];
long long n,m;
bool check(long long mid) {
	for (int i=1;i<=n;i++) cnt[i] = (mid + a[i] - 1) / a[i];
	cnt[n+1] = 0;
	long long need = 0;
	int last = 0;
	for (int i=1;i<=n;i++) {
		if (cnt[i]) {
			cnt[i] --;
			need += i - last;
			last = i;
		}
		
		long long toge = min(cnt[i],cnt[i+1]);
		if (toge) {
			need += i - last;
			last = i;
		}
		cnt[i] -= toge;
		cnt[i+1] -= toge;
		need += 2 * toge;
		if (need > m) return false;
		if (cnt[i]) {
			need += 2 * cnt[i];
			cnt[i] = 0;
			need += i - last;
			last = i;
		}
	}
	return need <= m;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%lld%lld",&n,&m);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		long long l = 0, r = 1e18;
		long long ans = -1;
		while (l <= r) {
			long long mid = (l + r) >> 1;
			if (check(mid)) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
