#include <bits/stdc++.h>
using namespace std;
int head[205];
struct edge {
	int v;
	int next;
}e[205];
int ecnt;
void AddEdge(int u,int v) {
	e[ecnt].v = v;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int f[205][2];//0表示这个点不选，1表示这个点要选
bool vis[205];
bool g[205][2];//表示这个状态有没有多种情况
void dfs(int u) {
	vis[u] = true;
	bool curflag = false;
	for (int i=head[u];i != -1;i=e[i].next) {
		int v = e[i].v;
		if (!vis[v]) {
			dfs(v);
			f[u][1] += f[v][0];
			g[u][1] |= g[v][0];
			if (f[v][1] > f[v][0]) {
				f[u][0] += f[v][1];
				g[u][0] |= g[v][1];
			}
			else {
				f[u][0] += f[v][0];
				g[u][0] |= g[v][0];
			}
			if (f[v][1] == f[v][0]) g[u][0] = true;
		}
	}
}
map <string,int> mem;
int getnum(string n) {
	if (mem[n] == 0) return mem[n] = mem.size();
	else return mem[n];
}
int main() {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		mem.clear();
		memset(f,0,sizeof(f));
		memset(g,false,sizeof(g));
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=1;i<=n;i++) f[i][1] = 1;

		string bigboss;
		cin >> bigboss;
		int root = getnum(bigboss);
		string a,b;
		for (int i=1;i<n;i++) {
			cin >> a >> b;
			AddEdge(getnum(b),getnum(a));
		}
		memset(vis,false,sizeof(vis));
		dfs(root);
		if (f[root][0] > f[root][1]) {
			printf("%d ",f[root][0]);
			if (g[root][0]) printf("No\n");
			else printf("Yes\n");
		}
		else {
			printf("%d ",f[root][1]);
			if (g[root][1] || f[root][0] == f[root][1]) printf("No\n");
			else printf("Yes\n");
		}
	}
	return 0;
}
