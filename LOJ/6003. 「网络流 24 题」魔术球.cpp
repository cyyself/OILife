#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Edge{
	int f,v,next;
}e[200005];
int ecnt = 0;//因为采用了一个邻接表奇偶存两条边的方法，所以必须从偶数开始
int head[10005];
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
int dis[10005];
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
bool vis[10005];
void print(int u) {
	vis[u] = true;
	for (int i=head[u];i != -1;i=e[i].next) if ( (i & 1) == 0 && e[i].f == 0) {
		printf(" %d",e[i].v/2);
		print(e[i].v-1);
		return;
	}
}
int main() {
	memset(head,-1,sizeof(head));
	int n;
	scanf("%d",&n);
	int s = 0, t = 1;
	int path = 0;
	int vcnt = 0;
	while (path <= n) {
		vcnt ++;
		AddEdge(s,vcnt*2,1);
		AddEdge(vcnt*2+1,t,1);
		for (int i=sqrt(vcnt)+1;i*i<2*vcnt;i++) 
			AddEdge((i*i-vcnt)*2,vcnt*2+1,1);
		if (dinic(s,t) == 0) path ++;
	}
	printf("%d\n",vcnt - 1);
	for (int i=1;i<vcnt;i++) {
		if (!vis[i*2]) {
			printf("%d",i);
			print(i*2);
			printf("\n");
		}
	}
	return 0;
}
