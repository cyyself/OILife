#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Edge{
	int f,v,next;
}e[100000];
int ecnt;
int head[205];
void _AddEdge(int u,int v,int c) {
	e[ecnt].v = v;
	e[ecnt].f = c;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
void addedge(int u,int v,int c) {
	_AddEdge(u,v,c);
	_AddEdge(v,u,0);
}
int dis[205];
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
int dinic(int s,int t) {
	int ans = 0;
	while(bfs(s,t)) ans += dfs(s,t,INF);
	return ans;
}
int d[205];
int min_flow[100000];
int main() {
	freopen("cooling.in","r",stdin);
	freopen("cooling.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int u,v,l,c;
		scanf("%d%d%d%d",&u,&v,&l,&c);
		min_flow[ecnt+1] = l;
		addedge(u,v,c-l);
		d[u] -= l;
		d[v] += l;
	}
	int need = 0;
	for (int i=1;i<=n;i++) {
		if (d[i] < 0) addedge(i,n+1,-d[i]);
		else if (d[i] > 0) {
			addedge(0,i,d[i]);
			need += d[i];
		}
	}
	if (dinic(0,n+1) == need) {
		printf("YES\n");
		for (int i=1;i<2*m;i+=2) printf("%d\n",min_flow[i]+e[i].f);
	}
	else printf("NO\n");
	return 0;
}
