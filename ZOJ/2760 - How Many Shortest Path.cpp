#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
const int MAXN = 105;
const int MAXE = 20005;
//要注意边数要开2倍，因为还有反向弧
int n,s,t;
int g[MAXN][MAXN];
int f[MAXN][MAXN];
//邻接表 {
int head[MAXN];
int nexte[MAXE];
int c[MAXE];
int to[MAXE];
int ecnt;
void al_init() {
	ecnt = 0;
	memset(head,-1,sizeof(head));
}

void AddEdge(int _from,int _to,int _cap) {
	//不含反向弧
	nexte[ecnt] = head[_from];
	head[_from] = ecnt;
	to[ecnt] = _to;
	c[ecnt] = _cap;
	ecnt ++;
}
//邻接表 }
//dinic {
int dis[MAXN];
bool bfs() {
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int en = head[cur];en != -1; en = nexte[en]) {
			int v = to[en];
			if (c[en] != 0 && dis[v] == INF) {
				dis[v] = dis[cur] + 1;
				q.push(v);
			}
		}
	}
	return dis[t] != INF;
}
int dfs(int u,int curflow) {
	if (u == t) return curflow;
	if (dis[u] >= dis[t]) return 0;
	for (int en = head[u]; en != -1;en = nexte[en]) {
		int v = to[en];
		int flow;
		if (c[en] != 0 && dis[v] == dis[u] + 1 && (flow = dfs(v,min(curflow,c[en])))) {
			c[en] -= flow;
			c[en ^ 1] += flow;
			return flow;
		}
	}
	return 0;
}
int dinic() {
	int ans = 0;
	int flow;
	while(bfs()) while(flow = dfs(s,INF)) ans += flow;
	return ans;
}
//dinic }
int main() {
	while(scanf("%d",&n) == 1) {
		al_init();
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++) {
				scanf("%d",&g[i][j]);
				if (i == j) g[i][j] = 0;
				if (g[i][j] == -1) g[i][j] = INF;
				/*WA了两小时纪念
				if (g[i][j] == -1) g[i][j] = INF;
				else if (i == j) g[i][j] = 0;
				*/
				f[i][j] = g[i][j];
			}
		scanf("%d%d",&s,&t);
		if (s == t) {
			printf("inf\n");
			continue;
		}
		for (int k=0;k<n;k++)
			for (int i=0;i<n;i++) if (k != i)
				for (int j=0;j<n;j++) if (j != k && i != j && f[i][k] != INF && f[k][j] != INF)
					f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
		/*
		//debug_print g {
			for (int i=0;i<n;i++) {
				for (int j=0;j<n;j++) if (g[i][j] != INF) printf("%d\t",g[i][j]);
					else printf("INF\t");
				printf("\n");
			}
		//debug_print g }
		*/
		if (f[s][t] == INF) {
			printf("0\n");
			continue;
		}
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++) {
				if (i != j && g[i][j] != INF && f[s][i] != INF && f[j][t] != INF && f[s][t] == f[s][i] + g[i][j] + f[j][t]) {
					AddEdge(i,j,1);
					AddEdge(j,i,0);
					/*
					//debug {
					printf("added %d->%d\n",i,j);
					//debug }
					*/
				}
			}
		printf("%d\n",dinic());
	}
	return 0;
}