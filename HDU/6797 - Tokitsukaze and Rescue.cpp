#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
vector <pair<int,int> > g[maxn];
int pre[maxn];
int dis[maxn];
bool ban[maxn][maxn];
void dijkstra(int s) {
	memset(dis,0x3f,sizeof(dis));
	priority_queue <pair<int,int> > q;
	dis[s] = 0;
	q.push({0,s});
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		int u = cur.second;
		if (dis[u] != -cur.first) continue;
		for (auto x:g[u]) {
			int v = x.first;
			if (ban[u][v]) continue;
			int w = x.second;
			if (dis[u] + w < dis[v]) {
				pre[v] = u;
				dis[v] = dis[u] + w;
				q.push({-dis[v],v});
			}
		}
	}
}
int ans;
int n;
void dfs(int k) {
	if (k == 0) {
		dijkstra(1);
		ans = max(ans,dis[n]);
	}
	else {
		dijkstra(1);
		vector <pair<int,int> > edges;
		int cur = n;
		while (cur != 1) {
			edges.emplace_back(cur,pre[cur]);
			cur = pre[cur];
		}
		for (auto x:edges) {
			ban[x.first][x.second] = true;
			ban[x.second][x.first] = true;
			dfs(k-1);
			ban[x.first][x.second] = false;
			ban[x.second][x.first] = false;

		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int k;
		scanf("%d%d",&n,&k);
		ans = 0;
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=0;i<n*(n-1)/2;i++) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			g[u].emplace_back(v,w);
			g[v].emplace_back(u,w);
		}
		dfs(k);
		printf("%d\n",ans);
	}
	return 0;
}
