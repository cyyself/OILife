#include <bits/stdc++.h>
using namespace std;
int a[100005];
int n,k;
long long m;
bool check(int x) {
	long long cnt = 0;
	int j = 1;
	int kcnt = 0;
	for (int i=1;i<=n;i++) {
		if (a[i] >= x) kcnt ++;
		if (kcnt == k) {
			cnt += n - i + 1;
			while (a[j] < x) {
				cnt += n - i + 1;
				j ++;
			}
			j ++;
			kcnt --;
		}
	}
	return cnt >= m;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d%d%lld",&n,&k,&m);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		int l = 1, r = 1e9;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(mid)) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
