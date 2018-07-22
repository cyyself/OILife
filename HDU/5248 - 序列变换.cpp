#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int b[100005];
bool judge(int cost) {
	b[0] = a[0] - cost;
	for (int i=1;i<n;i++) {
		if (a[i] + cost > b[i-1]) b[i] = max(b[i-1]+1,a[i]-cost);//能取b[i-1]+1的时候最优，不行时则取a[i]-cost
		else return false;
	}
	return true;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		int l = 0;
		int r = 1;
		while (!judge(r)) {
			l = r;
			r *= 2;
		}
		int ans;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (judge(mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		printf("Case #%d:\n%d\n",t,ans);
	}
	return 0;
}
