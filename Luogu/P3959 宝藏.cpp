#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int g[12][12];
int dis[12];
int f[1<<12];
int n;
void dfs(int stat) {
	for (int i=0;i<n;i++) if (stat & (1 << i) ) {
		for (int j=0;j<n;j++) {
			if (stat & (1 << j)) continue;
			if (g[i][j] == INF) continue;
			if (f[stat] + (dis[i] + 1) * g[i][j] < f[stat|(1 << j)]) {
				int t = dis[j];
				f[stat|(1 << j)] = f[stat] + (dis[i] + 1) * g[i][j];
				dis[j] = dis[i] + 1;
				dfs(stat|(1 << j));
				dis[j] = t;
			}
		}
	}
}
int main() {
	int m;
	scanf("%d%d",&n,&m);
	memset(g,0x3f,sizeof(g));
	while (m--) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		u --;
		v --;
		g[u][v] = min(g[u][v],w);
		g[v][u] = min(g[v][u],w);
	}
	int ans = INF;
	for (int i=0;i<n;i++) {
		memset(f,0x3f,sizeof(f));
		memset(dis,0x3f,sizeof(dis));
		dis[i] = 0;
		f[1<<i] = 0;
		dfs(1<<i);
		ans = min(ans,f[(1<<n)-1]);
	}
	printf("%d\n",ans);
	return 0;
}
