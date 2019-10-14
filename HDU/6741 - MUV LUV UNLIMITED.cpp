#include <bits/stdc++.h>
using namespace std;
int f[1000005];
int deg[1000005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) f[i] = deg[i] = 0;
		for (int u=2;u<=n;u++) {
			int v;
			scanf("%d",&v);
			f[u] = v;
			deg[v] ++;
		}
		bool ans = false;
		for (int i=1;i<=n;i++) if (deg[i] == 0) {//leaf
			if (deg[f[i]] >= 2) {
				ans = true;//说明先手一定可以改变状态
				break;
			}
			int u = i;
			int len = 0;
			while (deg[f[u]] == 1) {
				u = f[u];
				len ++;
			}
			if (len % 2 == 0) {
				ans = true;
				break;
			}
		}
		if (ans) printf("Takeru\n");
		else printf("Meiya\n");
	}
	return 0;
}
