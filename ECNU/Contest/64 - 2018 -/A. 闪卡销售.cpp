#include <bits/stdc++.h>
using std::max;
int cnt[1005];
int prize[1005];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&cnt[i]);
	for (int i=1;i<=m;i++) {
		int p,q;
		scanf("%d%d",&p,&q);
		prize[p] = max(prize[p],q);
	}
	int ans = 0;
	for (int i=1;i<=n;i++) {
		ans += prize[i] * cnt[i];
	}
	printf("%d\n",ans);
	return 0;
}
