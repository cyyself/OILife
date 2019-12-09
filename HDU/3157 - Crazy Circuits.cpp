#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 50+10;
const int maxe = maxn*maxn*2;
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
int read() {
	char c = getchar();
	int ret = 0;
	while (!(c >= '0' && c <= '9')) {
		if (c == '-') return n+1;
		else if (c == '+') return 0;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret;
}
int main() {
	while (scanf("%d%d",&n,&m) == 2 && (n || m)) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=0;i<=n+5;i++) d[i] = 0;
		for (int i=0;i<m;i++) {
			int u,v,w;
			u = read();
			v = read();
			w = read();
			addedge(u,v,w,INF);
		}
		int need = 0;
		build(0,n+1,n+2,n+3,need);
		AddEdge(n+1,0,INF);
		if (dinic(n+2,n+3) == need) {
			int flow = e[ecnt-1].f;
			e[ecnt-1].f = e[ecnt-2].f = 0;
			flow -= dinic(n+1,0);
			printf("%d\n",flow);
		}
		else printf("impossible\n");
	}
	return 0;
}
