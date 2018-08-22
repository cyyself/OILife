#include <bits/stdc++.h>
using namespace std;
int n;
int head[10005];
struct edge {
	int v,w;
	int next;
}e[20005];
int ecnt;
void AddEdge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
bool vis[10005];
int dis[10005];
void dfs(int u) {
	vis[u] = true;
	for (int i=head[u];i != -1;i=e[i].next) {
		int v = e[i].v;
		int w = e[i].w;
		if (!vis[v]) {
			dis[v] = dis[u] + w;
			dfs(v);
		}
	}
}
int dis2[10005];
void dfs2(int u) {
	vis[u] = true;
	for (int i=head[u];i != -1;i=e[i].next) {
		int v = e[i].v;
		int w = e[i].w;
		if (!vis[v]) {
			dis2[v] = dis2[u] + w;
			dfs2(v);
		}
	}
}
int main() {
	while (scanf("%d",&n) == 1) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int u=2;u<=n;u++) {
			int v,w;
			scanf("%d%d",&v,&w);
			AddEdge(u,v,w);
			AddEdge(v,u,w);
		}
		memset(vis,false,sizeof(vis));
		dis[1] = 0;
		dfs(1);

		int root = 0;
		for (int i=1;i<=n;i++) if (dis[i] > dis[root]) root = i;
		dis[root] = 0;
		memset(vis,false,sizeof(vis));
		dfs(root);

		root = 0;
		for (int i=1;i<=n;i++) if (dis[i] > dis[root]) root = i;
		dis2[root] = 0;
		memset(vis,false,sizeof(vis));
		dfs2(root);
		for (int i=1;i<=n;i++) {
			printf("%d\n",max(dis[i],dis2[i]));
		}
	}
	return 0;
}
