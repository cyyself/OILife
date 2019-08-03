#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Edge{
	int f,v,next;
}e[81840];
int ecnt = 0;
int head[422];
void _AddEdge(int u,int v,int c) {
	e[ecnt].v = v;
	e[ecnt].f = c;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
void AddEdge(int u,int v,int c) {
	_AddEdge(u,v,c);
	_AddEdge(v,u,0);
}
int n,m;
int dis[422];
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
int a[300],b[300];
int ans[300][300];
int main() {
	memset(head,-1,sizeof(head));
	int m,n;
	scanf("%d%d",&m,&n);
	int sum = 0;
	for (int i=1;i<=m;i++) {
		scanf("%d",&a[i]);
		sum += a[i];
		AddEdge(0,i,a[i]);
	}
	for (int i=1;i<=n;i++) {
		scanf("%d",&b[i]);
		for (int j=1;j<=m;j++) {
			AddEdge(j,m+i,1);
			ans[j][i] = ecnt - 2;
		}
		AddEdge(m+i,m+n+1,b[i]);
	}
	int flow = dinic(0,m+n+1);
	if (flow == sum) {
		printf("1\n");
		for (int i=1;i<=m;i++) {
			for (int j=1;j<=n;j++) if (e[ans[i][j]].f == 0) printf("%d ",j);
			printf("\n");
		}
	}
	else printf("0\n");
	return 0;
}
