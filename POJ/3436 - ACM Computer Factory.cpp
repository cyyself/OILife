#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 102;
const int MAXE = MAXN*MAXN;
struct edge {
	int u,v;
	int f;
	int next;
}e[MAXE];
int head[MAXN];
int ecnt;
void _add(int u,int v,int f) {
	e[ecnt].u = u;
	e[ecnt].v = v;
	e[ecnt].f = f;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
void add(int u,int v,int f) {
	_add(u,v,f);
	_add(v,u,0);
}
int dis[MAXN];
bool bfs(int s,int t) {
	memset(dis,0x3f,sizeof(dis));
	queue <int> q;
	dis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == t) return true;
		for (int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			if (e[i].f > 0 && dis[v] == INF) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return dis[t] != INF;
}
int dfs(int u,int t,int maxflow) {
	if (maxflow == 0 || u == t) return maxflow;
	if (dis[u] >= dis[t]) return 0;
	int ret = 0;
	for (int i=head[u];~i && ret < maxflow;i=e[i].next) {//多路增广
		int v = e[i].v;
		int f = e[i].f;
		if (dis[v] == dis[u] + 1 && f > 0) {
			int pushflow = min(maxflow-ret,f);
			int chflow = dfs(v,t,pushflow);
			if (chflow > 0) {
				e[ i ].f -= chflow;
				e[i^1].f += chflow;
				ret += chflow;
			}
			else dis[v] = -1;//炸点
		}
	}
	if (ret == 0) dis[u] = -1;//炸点
	return ret;
}
int dinic(int s,int t) {
	int ans = 0;
	while (bfs(s,t)) ans += dfs(s,t,INF);
	return ans;
}
int s[55][15];
int d[55][15];
int q[55];
int p,n;
bool judge(int x,int y) {
	for (int i=0;i<p;i++) {
		if (s[y][i] == 2) continue;
		if (d[x][i] != s[y][i]) return false;
	}
	return true;
}
struct DATA {
	int u,v,f;
};
int main() {
	while (scanf("%d%d",&p,&n) == 2) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		q[0] = INF;
		for (int i=1;i<=n;i++) {
			scanf("%d",&q[i]);
			for (int j=0;j<p;j++) scanf("%d",&s[i][j]);
			for (int j=0;j<p;j++) scanf("%d",&d[i][j]);
		}
		q[n+1] = INF;
		for (int i=0;i<p;i++) s[n+1][i] = 1;
		for (int i=1;i<=n;i++) if (judge(0,i)) add(0,i,q[i]);//源点到各点拆后入点
		for (int i=1;i<=n;i++) add(i,i+50,q[i]);//自身拆的入点到自身拆的出点
		for (int i=1;i<=n;i++) if (judge(i,n+1)) add(i+50,101,q[i]);//拆的出点到终点
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) {
				if (i == j) continue;
				if (judge(i,j)) add(i+50,j,min(q[i],q[j]));
			}
		int ans = dinic(0,101);
		vector <DATA> a;
		for (int i=1;i<ecnt;i+=2) {
			if (e[i].u >= 1 && e[i].u <= 50 && e[i].v >= 51 && e[i].v <= 100 && e[i].f > 0) {
				int u = e[i].u;
				int v = e[i].v - 50;
				if (u == v) continue;
				a.push_back((DATA){v,u,e[i].f});
			}
		}
		printf("%d %lu\n",ans,a.size());
		for (unsigned int i=0;i<a.size();i++) printf("%d %d %d\n",a[i].u,a[i].v,a[i].f);
	}

	return 0;
}
