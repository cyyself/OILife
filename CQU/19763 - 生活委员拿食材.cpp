#include <bits/stdc++.h>
using namespace std;
int INF = 0x3f3f3f3f;
struct edge {
	int v,w;
	int next;
}e[10005];
int head[1005];
int ecnt;
void addedge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int g[11][11];//食材之间的距离
int need[10];//每种食物需要的食材(用二进制位存储)
int loc[11];//每种食材对应的节点号
int cost[1<<10];//拿指定类型的食材
int f[1<<10][11];

int n,m,k;
int dfs(int stat,int u) {
	if (f[stat][u] != INF) return f[stat][u];
	if (stat == 0) return f[stat][u] = 0;
	for (int v=1;v<=m;v++) {
		if (stat & (1 << (v-1)) && g[v][u] < INF) {
			int w = g[v][u];
			if (__builtin_popcount(stat) == 1) w = g[0][v];
			f[stat][u] = min(f[stat][u],dfs(stat^(1 << (u-1)),v) + w);
			cost[stat] = min(cost[stat],f[stat][u]);
		}
	}
	return f[stat][u];
}
struct DATA {
	int u;
	int dis;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.dis > b.dis;
	}
};
priority_queue <DATA> q;
int dis[1005];
void dijkstra(int s) {
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	q.push((DATA){s,0});
	while (!q.empty()) {
		DATA cur = q.top();
		q.pop();
		int u = cur.u;
		if (dis[u] < cur.dis) continue;
		for (int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			if (dis[u] + e[i].w < dis[v]) {
				dis[v] = dis[u] + e[i].w;
				q.push((DATA){v,dis[v]});
			}
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		memset(need,0,sizeof(need));
		memset(g,0x3f,sizeof(g));
		memset(cost,0x3f,sizeof(cost));
		memset(f,0x3f,sizeof(f));
		memset(head,-1,sizeof(head));
		ecnt = 0;
		scanf("%d%d%d",&n,&m,&k);
		for (int i=0;i<n;i++) {
			int c;
			scanf("%d",&c);
			while (c --) {
				int t;
				scanf("%d",&t);
				need[i] |= 1 << t;
			}
		}
		int N,M;
		scanf("%d%d",&N,&M);
		for (int i=0;i<M;i++) {
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			addedge(u,v,c);
			addedge(v,u,c);
		}
		loc[0] = 1;
		for (int i=1;i<=m;i++) scanf("%d",&loc[i]);
		for (int i=0;i<=m;i++) {
			dijkstra(loc[i]);
			for (int j=0;j<=m;j++) g[i][j] = dis[loc[j]];
		}
		//for (int i=0;i<=m;i++) g[0][i] = 0;
		for (int i=1;i<=m;i++) dfs((1<<m)-1,i);
		int ans = INF;
		for (int i=0;i<(1<<n);i++) {
			if (__builtin_popcount(i) == k) {
				int stat = 0;
				for (int j=0;j<n;j++) if (i & (1 << j)) stat |= need[j];
				ans = min(ans,cost[stat]);
			}
		}
		printf("Case %d: %d\n",cas,ans);
	}
	return 0;
}
