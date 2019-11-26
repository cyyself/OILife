#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 365 + 1000 + 5;
const int maxe = 2000000;
struct Edge{
	int f,used,v,next;
}e[maxe];
int ecnt;
int head[maxn];
void _AddEdge(int u,int v,int c,int used) {
	e[ecnt].v = v;
	e[ecnt].f = c;
	e[ecnt].used = used;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
void AddEdge(int u,int v,int c,int used = 0) {
	_AddEdge(u,v,c,used);
	_AddEdge(v,u,0,used);
}
int dis[maxn];
bool bfs(int s,int t) {
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

int dfs(int u,int t,int curflow) {
	if (curflow == 0 || u == t) return curflow;
	if (dis[u] >= dis[t]) return 0;
	int ret = 0;
	for (int i=head[u];i!=-1 && ret < curflow;i=e[i].next) {
		int v = e[i].v;
		int f = e[i].f;
		if (dis[v] == dis[u] + 1 && f != 0) {
			int pushflow = min(curflow-ret,f);
			int chflow = dfs(v,t,pushflow);
			if (chflow > 0) {
				e[ i ].f -= chflow;//偶数+1,奇数-1，很巧妙的位运算
				e[i^1].f += chflow;
				ret += chflow;
			}
			else dis[v] = -1;
		}
	}
	if (ret == 0) dis[u] = -1;
	return ret;
}
int dinic(int s,int t) {
	int ans = 0;
	while(bfs(s,t)) ans += dfs(s,t,INF);
	return ans;
}
int d[maxn];
void addedge(int u,int v,int f_min,int f_max) {
	AddEdge(u,v,f_max-f_min,f_min);
	d[u] += f_min;
	d[v] -= f_min;
}
void build(int s,int t,int ss,int tt,int &need) {
	for (int i=s;i<=t;i++) {
		if (d[i] < 0) AddEdge(ss,i,-d[i]);
		else {
			need += d[i];
			AddEdge(i,tt,d[i]);
		}
	}
}
int n,m;
vector <int> eid;
int main() {
	while (scanf("%d%d",&n,&m) == 2) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		eid.clear();
		int s = 0, t = n + m + 1;
		for (int i=s;i<=t;i++) d[i] = 0;
		for (int i=1;i<=m;i++) {
			int g;
			scanf("%d",&g);
			addedge(n+i,t,g,INF);
		}
		for (int i=1;i<=n;i++) {
			int c,limit;
			scanf("%d%d",&c,&limit);
			addedge(s,i,0,limit);
			for (int j=1;j<=c;j++) {
				int tk,l,r;
				scanf("%d%d%d",&tk,&l,&r);
				tk ++;
				addedge(i,n+tk,l,r);
				eid.push_back(ecnt-1);
			}
		}
		int need = 0, ss = t + 1, tt = t + 2;
		build(s,t,ss,tt,need);
		AddEdge(t,s,INF);
		if (dinic(ss,tt) == need) {
			e[ecnt-1].f = e[ecnt-2].f = 0;//屏蔽t到s的边
			dinic(s,t);
			int tot = 0;
			for (auto x:eid) tot += e[x].f + e[x].used;
			printf("%d\n",tot);
			for (auto x:eid) printf("%d\n",e[x].f + e[x].used);
		}
		else printf("-1\n");
		printf("\n");
	}
	return 0;
}
