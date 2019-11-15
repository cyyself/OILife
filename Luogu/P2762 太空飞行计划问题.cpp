#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Edge{
	int f,v,next;
}e[5200];
int ecnt = 0;
int head[105];
void _addedge(int u,int v,int c) {
	e[ecnt].v = v;
	e[ecnt].f = c;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
void addedge(int u,int v,int c) {
	_addedge(u,v,c);
	_addedge(v,u,0);
}
int dis[105];
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
int main() {
	memset(head,-1,sizeof(head));
	int m,n;
	scanf("%d%d",&m,&n);
	int sump = 0;
	for (int i=1;i<=m;i++) {
		int p;
		scanf("%d",&p);
		sump += p;
		addedge(0,i,p);
		char tools[10000];
		memset(tools,0,sizeof tools);
		cin.getline(tools,10000);
		int ulen=0,tool;
		while (sscanf(tools+ulen,"%d",&tool)==1) {
			addedge(i,m+tool,INF);
			if (tool==0) 
				ulen++;
			else {
				while (tool) {
					tool/=10;
					ulen++;
				}
			}
			ulen++;
		}
	}
	for (int i=1;i<=n;i++) {
		int c;
		scanf("%d",&c);
		addedge(m+i,m+n+1,c);
	}
	int ans = sump - dinic(0,m+n+1);
	for (int i=1;i<=m;i++) if (dis[i] != INF) printf("%d ",i);
	printf("\n");
	for (int i=1;i<=n;i++) if (dis[m+i] != INF) printf("%d ",i);
	printf("\n");
	printf("%d\n",ans);
	return 0;
}
