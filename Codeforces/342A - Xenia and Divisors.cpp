#include <bits/stdc++.h>
using namespace std;
int cnt[8];
int ans[3];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		cnt[x] ++;
	}
	if (cnt[6] - cnt[3] >= 0 && cnt[1] - cnt[3] >= 0) {
		ans[0] += cnt[3];
		cnt[6] -= cnt[3];
		cnt[1] -= cnt[3];
		cnt[3] -= cnt[3];
		if (cnt[1] - cnt[6] >= 0 && cnt[2] - cnt[6] >= 0) {
			ans[1] += cnt[6];
			cnt[1] -= cnt[6];
			cnt[2] -= cnt[6];
			cnt[6] -= cnt[6];
			if (cnt[1] == cnt[2] && cnt[2] == cnt[4]) {
				ans[2] += cnt[1];
				if ((ans[0] + ans[1] + ans[2]) * 3 == n) {
					for (int i=0;i<ans[2];i++) puts("1 2 4");
					for (int i=0;i<ans[1];i++) puts("1 2 6");
					for (int i=0;i<ans[0];i++) puts("1 3 6");
				}
				else printf("-1\n");
			}
			else printf("-1\n");
		}
		else printf("-1\n");
	}
	else printf("-1\n");
	return 0;
}
