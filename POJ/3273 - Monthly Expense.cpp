#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005];
int n,m;
bool judge(int x) {
	int cnt = 0;
	int cur = 0;
	for (int i=0;i<n;i++) {
		if (cur + a[i] > x) {
			cur = 0;
			cnt ++;
		}
		cur += a[i];
	}
	if (cur) cnt ++;
	return cnt <= m;
}
int main() {
	while (scanf("%d%d",&n,&m) == 2) {
		int l = 0;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			l = max(l,a[i]);
		}
		int r = 0x3f3f3f3f;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (judge(mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
