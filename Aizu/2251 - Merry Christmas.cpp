#include <bits/stdc++.h>
using namespace std;
int n,m,l;
int dis[100][100];
vector <int> g[1000];
struct DATA {
	int p,t;
	void read() {
		scanf("%d%d",&p,&t);
	}
}a[1000];
int pre[1000];
bool vis[1000];
bool dfs(int u) {
	for (auto v:g[u]) {
		if (!vis[v]) {
			vis[v] = true;
			if (pre[v] == -1 || dfs(pre[v])) {
				pre[v] = u;
				return true;
			}
		}
	}
	return false;
}
int main() {
	while (scanf("%d%d%d",&n,&m,&l) == 3 && n) {
		memset(dis,0x3f,sizeof(dis));
		for (int i=0;i<n;i++) dis[i][i] = 0;
		for (int i=0;i<m;i++) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			dis[u][v] = dis[v][u] = min(dis[u][v],w);
		}
		for (int k=0;k<n;k++)
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++) dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
		for (int i=0;i<l;i++) {
			a[i].read();
			g[i].clear();
		}
		for (int i=0;i<l;i++) for (int j=0;j<l;j++) {
			if (i != j && a[i].t + dis[a[i].p][a[j].p] <= a[j].t) g[i].push_back(j);
		}
		memset(pre,-1,sizeof(pre));
		int ans = 0;
		for (int i=0;i<l;i++) {
			memset(vis,false,sizeof(vis));
			ans += dfs(i);
		}
		printf("%d\n",l-ans);
	}
	return 0;
}
