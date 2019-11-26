#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
int d[225];
int MI[205][25],MA[205][25];
struct Edge{
	int f,v,next;
}e[200005];
int ecnt;
int head[225];
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
int dis[225];
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
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,m;
		scanf("%d%d",&n,&m);
		//clear begin
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=0;i<=n+m+1;i++) d[i] = 0;
		//clear end
		int s = 0, t = n+m+1;
		for (int i=1;i<=n;i++) {
			int x;
			scanf("%d",&x);
			d[s] += x;
			d[i] -= x;
		}
		for (int i=1;i<=m;i++) {
			int x;
			scanf("%d",&x);
			d[n+i] += x;
			d[t] -= x;
		}
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
			MI[i][j] = 0;
			MA[i][j] = INF;
		}
		int c;
		scanf("%d",&c);
		while (c --) {
			int x,y,k;
			char op;
			scanf("%d%d %c%d",&x,&y,&op,&k);
			if (op == '<') {
				k --;
				if (x == 0) {
					if (y == 0) {
						for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) MA[i][j] = min(MA[i][j],k);
					}
					else {
						for (int i=1;i<=n;i++) MA[i][y] = min(MA[i][y],k);
					}
				}
				else if (y == 0) {
					for (int j=1;j<=m;j++) MA[x][j] = min(MA[x][j],k);
				}
				else MA[x][y] = min(MA[x][y],k);
			}
			else if (op == '>') {
				k ++;
				if (x == 0) {
					if (y == 0) {
						for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) MI[i][j] = max(MI[i][j],k);
					}
					else {
						for (int i=1;i<=n;i++) MI[i][y] = max(MI[i][y],k);
					}
				}
				else if (y == 0) {
					for (int j=1;j<=m;j++) MI[x][j] = max(MI[x][j],k);
				}
				else MI[x][y] = max(MI[x][y],k);
			}
			else {
				if (x == 0) {
					if (y == 0) {
						for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
							MI[i][j] = max(MI[i][j],k);
							MA[i][j] = min(MA[i][j],k);
						}
					}
					else {
						for (int i=1;i<=n;i++) {
							MI[i][y] = max(MI[i][y],k);
							MA[i][y] = min(MA[i][y],k);
						}
					}
				}
				else if (y == 0) {
					for (int j=1;j<=m;j++) {
						MI[x][j] = max(MI[x][j],k);
						MA[x][j] = min(MA[x][j],k);
					}
				}
				else {
					MI[x][y] = max(MI[x][y],k);
					MA[x][y] = min(MA[x][y],k);
				}
			}
		}
		bool ans = true;
		for (int i=1;i<=n && ans;i++) {
			for (int j=1;j<=m && ans;j++) {
				d[i] += MI[i][j];
				d[n+j] -= MI[i][j];
				if (MA[i][j] < MI[i][j]) ans = false;
				addedge(i,n+j,MA[i][j]-MI[i][j]);
			}
		}
		if (ans) {
			int need = 0;
			int ss = n + m + 2, tt = n + m + 3;
			for (int i=0;i<=n+m+1;i++) {
				if (d[i] < 0) addedge(ss,i,-d[i]);
				else if (d[i] >= 0) {//==0的
					addedge(i,tt,d[i]);
					need += d[i];
				}
			}
			addedge(t,s,INF);
			if (dinic(ss,tt) == need) {
				int k = 1;
				for (int i=1;i<=n;i++) {
					for (int j=1;j<=m;j++) {
						printf("%d%c",MI[i][j]+e[k].f,j==m?'\n':' ');
						k += 2;
					}
				}
			}
			else printf("IMPOSSIBLE\n");
		}
		else printf("IMPOSSIBLE\n");
		printf("\n");
	}
	return 0;
}
