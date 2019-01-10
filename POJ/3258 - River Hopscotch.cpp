#include <cstdio>
#include <algorithm>
using namespace std;
int l,n,m;
int d[50005];
bool check(int x) {
	int last = 0;
	int cnt = 0;
	for (int i=0;i<=n && cnt <= m;i++) {
		if (d[i] - last < x) cnt ++;
		else last = d[i];
	}
	return cnt <= m;
}
int main() {
	scanf("%d%d%d",&l,&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&d[i]);
	sort(d,d+n);
	d[n] = l;
	int l = 0;
	int r = d[n];
	int ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
