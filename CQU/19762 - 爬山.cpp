#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> g[10005];
bool dfs(int u) {
	for (auto v:g[u]) {
		if (!dfs(v)) return true;
	}
	return false;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=0;i<m;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
		}
		if (dfs(1)) printf("Case %d: RunningPhoton\n",cas);
		else printf("Case %d: Snowdrop\n",cas);
	}
	return 0;
}
