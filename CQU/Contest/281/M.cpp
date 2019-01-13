#include <bits/stdc++.h>
using namespace std;
vector <int> g[10005];
bool dfs(int u,int dep,int rt) {
	if (dep == 2) {
		for (auto v:g[u]) if (v == rt) return true;
		return false;
	}
	else {
		for (auto v:g[u]) {
			if (v == rt) continue;
			if (dfs(v,dep+1,rt)) return true;
		}
		return false;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) g[i].clear();
		while (m --) {
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = 0;
		for (int i=1;i<=n;i++) ans = max(ans,(int)g[i].size());
		if (ans < 3) {
			for (int i=1;i<=n;i++) if (dfs(i,0,i)) {
				ans = 3;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}