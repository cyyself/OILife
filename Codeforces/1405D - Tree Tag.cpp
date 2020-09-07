#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector <int> g[maxn];
int dis[maxn];
void dfs(int u,int f) {
	for (auto v:g[u]) {
		if (v == f) continue;
		dis[v] = dis[u] + 1;
		dfs(v,u);
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,a,b,da,db;
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		for (int i=1;i<n;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dis[a] = 0;
		dfs(a,-1);
		int disab = dis[b];
		int f = 1;
		for (int i=1;i<=n;i++) if (dis[i] > dis[f]) f = i;
		dis[f] = 0;
		dfs(f,-1);
		int len = 0;
		for (int i=1;i<=n;i++) len = max(len,dis[i]);
		da = min(da,len);
		db = min(db,len);
		if (disab <= da) printf("Alice\n");
		else {
			if (db > 2 * da) printf("Bob\n");
			else printf("Alice\n");
		}
		for (int i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}
