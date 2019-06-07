#include <bits/stdc++.h>
using namespace std;
int c[505];
bool g[505][505];
int n,m;
bool ans;
bool dfs(int u) {
	bool flag = false;
	for (int i=1;i<=n && ans;i++) {
		if (i == u || g[u][i]) continue;
		if (c[i] == -1) {
			flag = true;
			c[i] = c[u] ^ 1;
			dfs(i);
		}
		else if (c[i] != (c[u] ^ 1)) ans = false;
	}
	return flag;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		memset(g,false,sizeof(g));
		memset(c,-1,sizeof(c));
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			g[u][v] = g[v][u] = true;
		}
		ans = true;
		for (int i=1;i<=n;i++) if (c[i] == -1) {
			c[i] = 0;
			if (!dfs(i)) c[i] = -1;
		}
		for (int i=1;i<=n && ans;i++) {
			if (c[i] == -1) continue;
			for (int j=1;j<=n && ans;j++) {
				if (c[j] == -1) continue;
				if (i == j) continue;
				if (g[i][j]) {
					if (c[i] != c[j]) ans = false;
				}
				else {
					if (c[i] == c[j]) ans = false;
				}
			}
		}
		if (ans) puts("Yes");
		else puts("No");
	}
	return 0;
}
