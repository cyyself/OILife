#include <bits/stdc++.h>
using namespace std;
int head[6005];
struct edge {
	int v;
	int next;
}e[6005];
int ind[6005];
int ecnt;
void AddEdge(int u,int v) {
	ind[v] ++;
	e[ecnt].v = v;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int f[6005][2];//0表示这个点不选，1表示这个点要选
bool vis[6005];
void dfs(int u) {
	vis[u] = true;
	for (int i=head[u];i != -1;i=e[i].next) {
		int v = e[i].v;
		if (!vis[v]) {
			dfs(v);
			f[u][0] += max(f[v][1],f[v][0]);
			f[u][1] += f[v][0];
		}
	}
}
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		memset(f,0,sizeof(f));
		memset(ind,0,sizeof(ind));
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=1;i<=n;i++) {
			int w;
			scanf("%d",&w);
			f[i][1] += w;
		}
		int l,k;
		while (scanf("%d%d",&l,&k) == 2) {
			if (l * k == 0) break;
			AddEdge(k,l);
		}
		int root = 0;
		for (int i=1;i<=n;i++) if (ind[i] == 0) {
			root = i;
			break;
		}
		dfs(root);
		memset(vis,false,sizeof(vis));
		printf("%d\n",max(f[root][0],f[root][1]));
	}
	return 0;
}
