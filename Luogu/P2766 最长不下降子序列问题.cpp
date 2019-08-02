#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Edge{
	int f,v,next;
}e[1000000];
int ecnt = 0;//因为采用了一个邻接表奇偶存两条边的方法，所以必须从偶数开始
int head[1005];
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
int dis[1005];
bool bfs(int s,int t) {//划分层次，同时判断是否可到达
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

int dfs(int u,int t,int curflow) {//curflow=>当前可增广的最大流量
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
int f[505],a[505];
int n,k;
void work1() {
	ecnt = 0;
	memset(head,-1,sizeof(head));
	for (int i=1;i<=n;i++) {
		if (f[i] == k) AddEdge(0,i,1);
		if (f[i] == 1) AddEdge(n+i,2*n+1,1);
		AddEdge(i,n+i,1);
		for (int j=i+1;j<=n;j++) if (a[i] <= a[j] && f[j] == f[i] - 1) AddEdge(n+i,j,1);
	}
	printf("%d\n",dinic(0,2*n+1));
}
void work2() {
	ecnt = 0;
	memset(head,-1,sizeof(head));
	for (int i=1;i<=n;i++) {
		if (f[i] == k) AddEdge(0,i,((i==1||i==n)&&k!=1)?INF:1);
		if (f[i] == 1) AddEdge(n+i,2*n+1,((i==1||i==n)&&k!=1)?INF:1);
		AddEdge(i,n+i,(i==1||i==n)?INF:1);
		for (int j=i+1;j<=n;j++) if (a[i] <= a[j] && f[j] == f[i] - 1) AddEdge(n+i,j,1);
	}
	printf("%d\n",dinic(0,2*n+1));
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) f[i] = 1;
	k = 1;
	for (int i=n-1;i>=1;i--) {
		for (int j=i+1;j<=n;j++) if (a[j] >= a[i]) f[i] = max(f[i],f[j]+1);
		k = max(f[i],k);
	}
	printf("%d\n",k);
	work1();
	work2();
	return 0;
}
