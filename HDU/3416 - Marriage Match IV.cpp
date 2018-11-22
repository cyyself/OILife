/*
TLE了两小时的感慨：
1. 别用费用流每次看dis[t]，会TLE的
2. 找最短路上的边跑最大流如果用dinic，记得要写多路增广，不然会TLE的
*/
#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Edge{
	int v;
	int f;
	int next;
}e[200005];
int ecnt;
int head[1005];
void AddEdge(int u,int v,int c) {
	e[ecnt].v = v;
	e[ecnt].f = c;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
void add(int u,int v,int c) {
	AddEdge(u,v,c);
	AddEdge(v,u,0);
}
int s,t;
int dis[1005];

bool bfs() {//划分层次，同时判断是否可到达
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 1;
	queue <int> q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == t) return 1;
		for (int i=head[u];i!=-1;i = e[i].next) {
			int v = e[i].v;
			if (e[i].f != 0 && dis[v] == INF) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return dis[t] != INF;
}

int dfs(int u,int curflow) {
	if (curflow == 0 || u == t) return curflow;
	if (dis[u] >= dis[t]) return 0;
	int ret = 0;
	for (int i=head[u];i!=-1 && ret < curflow;i=e[i].next) {
		int v = e[i].v;
		int f = e[i].f;
		if (dis[v] == dis[u] + 1 && f != 0) {
			int pushflow = min(curflow-ret,f);
			int chflow = dfs(v,pushflow);
			if (chflow > 0) {
				e[ i ].f -= chflow;
				e[i^1].f += chflow;
				ret += chflow;
			}
			else dis[v] = -1;
		}
	}
	if (ret == 0) dis[u] = -1;
	return ret;
}
int dinic() {
	int ans = 0;
	while(bfs()) ans += dfs(s,INF);
	return ans;
}

struct _edge {
	int v,w;
	int next;
};
struct adj {
	int head[1005];
	_edge e[100005];
	int ecnt;
	void init() {
		memset(head,-1,sizeof(head));
		ecnt = 0;
	}
	void addedge(int u,int v,int w) {
		e[ecnt].v = v;
		e[ecnt].w = w;
		e[ecnt].next = head[u];
		head[u] = ecnt;
		ecnt ++;
	}
}g1,g2;
int dis1[1005];
int dis2[1005];
int n;
bool inq[1005];
void spfa(int s,adj &g,int dis[]) {
	queue <int> q;
	memset(dis,0x3f,sizeof(int) * (n+1));
	q.push(s);
	dis[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i=g.head[u];~i;i=g.e[i].next) {
			int v = g.e[i].v;
			int w = g.e[i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int m;
		scanf("%d%d",&n,&m);
		g1.init();
		g2.init();
		for (int i=0;i<m;i++) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if (u == v) continue;
			g1.addedge(u,v,w);
			g2.addedge(v,u,w);
		}
		scanf("%d%d",&s,&t);
		spfa(s,g1,dis1);
		if (dis1[t] == INF) {
			printf("0\n");
			continue;
		}
		spfa(t,g2,dis2);
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int u=1;u<=n;u++) {
			for (int i=g1.head[u];~i;i=g1.e[i].next) {
				int v = g1.e[i].v;
				int w = g1.e[i].w;
				if (dis1[u] + w + dis2[v] == dis1[t]) add(u,v,1);
			}
		}
		printf("%d\n",dinic());
	}
	return 0;
}
