#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int maxm = 5005;
int head[maxn];
struct Edge{
	int u,v,id;
	int next;
}e[maxm];
int ecnt = 0;
inline void AddEdge(int u,int v,int id) {
	e[ecnt].u = u;
	e[ecnt].v = v;
	e[ecnt].id = id;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int rt[maxn],dfn[maxn],low[maxn];
int tjtime;//tarjan time
stack <int> s;
bool ins[maxn];
int subg = 0;//子图数量
void tarjan(int u) {
	dfn[u] = ++tjtime;
	low[u] = tjtime;
	s.push(u);
	ins[u] = true;
	for (int i=head[u];i != -1;i=e[i].next) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if (ins[v]) low[u] = min(low[u],dfn[v]);
	}
	if (low[u] == dfn[u]) {//一个强连通分量
		subg ++;
		while (!s.empty()) {
			int cur = s.top();
			s.pop();
			ins[cur] = false;
			rt[cur] = subg;
			if (cur == u) break;
		}
	}
}
bool vis[5005];
int c[5005];
void dfs(int u) {
	if (vis[u]) return ;
	vis[u] = true;
	for (int i=head[u];i != -1;i=e[i].next) {
		int v = e[i].v;
		c[e[i].id] = 1 + (u < v);
		dfs(v);
	}
}
int main() {
	memset(head,-1,sizeof(head));
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		AddEdge(u,v,i);
	}
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	if (subg == n) {
		printf("1\n");
		for (int i=1;i<=m;i++) printf("1%c",i==m?'\n':' ');
	}
	else {
		printf("2\n");
		for (int i=1;i<=n;i++) dfs(i);
		for (int i=1;i<=m;i++) printf("%d%c",c[i],i==m?'\n':' ');
	}
	return 0;
}
