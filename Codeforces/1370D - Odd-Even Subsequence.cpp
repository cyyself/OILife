#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int arr[maxn];
int n,k;
bool check(int x) {
	int cnt0 = 0, cnt1 = 0;
	int cur = 0;
	for (int i=0;i<n;i++) {
		if (cur == 0) {
			if (arr[i] > x) continue;
			else {
				cnt0 ++;
				cur ^= 1;
			}
		}
		else {
			cnt0 ++;
			cur ^= 1;
		}
	}
	cur = 0;
	for (int i=0;i<n;i++) {
		if (cur == 1) {
			if (arr[i] > x) continue;
			else {
				cnt1 ++;
				cur ^= 1;
			}
		}
		else {
			cnt1 ++;
			cur ^= 1;
		}
	}
	return max(cnt0,cnt1) >= k;
}
int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	check(2);
	int l = 1, r = 1e9;
	int ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d\n",ans);
	return 0;
}
