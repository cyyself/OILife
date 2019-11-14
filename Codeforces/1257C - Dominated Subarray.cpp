#include <bits/stdc++.h>
using namespace std;
int a[200005];
int cnt[200005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			cnt[i] = 0;
		}
		int p1 = 1, p2 = 1;
		cnt[a[1]] ++;
		int ans = n + 1;
		while (p1 <= n) {
			while (p2 + 1 <= n) {
				cnt[a[++p2]] ++;
				if (cnt[a[p2]] == 2) break;
			}
			if (cnt[a[p2]] != 2) break;
			while (cnt[a[p1]] != 2) {
				cnt[a[p1]] --;
				p1 ++;
			}
			ans = min(ans,p2-p1+1);
			cnt[a[p1]] --;
			p1 ++;
			if (p2 < p1) cnt[a[++p2]] ++;
		}
		if (ans == n + 1) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
