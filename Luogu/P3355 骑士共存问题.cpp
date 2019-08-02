#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Edge{
	int f,v,next;
}e[800005];
int ecnt = 0;
int head[40005];
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
int dis[40005];
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
const int dx[8] = {-2,-2,-1,-1,1,1,2,2};
const int dy[8] = {1,-1,2,-2,2,-2,1,-1};
bool ban[200][200];
int n,m;
inline int get_id(int x,int y) {
	return x * n + y + 1;
}
int main() {
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	int ans = n * n;
	for (int i=0;i<m;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		if (!ban[x-1][y-1]) ans --;
		ban[x-1][y-1] = true;
	}

	for (int x=0;x<n;x++) for (int y=0;y<n;y++) if (((x + y) & 1) && !ban[x][y]) {
		AddEdge(0,get_id(x,y),1);
		for (int k=0;k<8;k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (ban[nx][ny]) continue;
			AddEdge(get_id(x,y),get_id(nx,ny),1);
		}
	}
	for (int x=0;x<n;x++) for (int y=0;y<n;y++) if (!((x + y) & 1) && !ban[x][y]) {
		AddEdge(get_id(x,y),n*n+1,1);
	}
	ans -= dinic(0,n*n+1);
	printf("%d\n",ans);
}
