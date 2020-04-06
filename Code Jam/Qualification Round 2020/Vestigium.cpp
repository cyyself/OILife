#include <bits/stdc++.h>
using namespace std;
set <int> r[105],c[105];
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		int n;
		scanf("%d",&n);
		int sum = 0;
		for (int i=1;i<=n;i++) {
			r[i].clear();
			c[i].clear();
		}
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
			int t;
			scanf("%d",&t);
			if (i == j) sum += t;
			r[i].insert(t);
			c[j].insert(t);
		}
		int rr = 0;
		for (int i=1;i<=n;i++) if (r[i].size() != n) rr ++;
		int cc = 0;
		for (int i=1;i<=n;i++) if (c[i].size() != n) cc ++;
		printf("Case #%d: %d %d %d\n",cas,sum,rr,cc);
	}
	return 0;
}
