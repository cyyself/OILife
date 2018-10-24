#include <bits/stdc++.h>
using namespace std;
vector <int> g[100005];
int dep[100005];
int up[100005][20];
bool vis[100005];
void dfs(int u) {
	vis[u] = true;
	for (int i=1,len=1;len<=dep[u];i++,len<<=1) up[u][i] = up[up[u][i-1]][i-1];
	for (auto v:g[u]) {
		if (!vis[v]) {
			dep[v] = dep[u] + 1;
			up[v][0] = u;
			dfs(v);
		}
	}
}
int lca(int u,int v) {
	if (dep[u] > dep[v]) swap(u,v);
	int diff = dep[v] - dep[u];
	for (int i=0,bin=1;diff;i++,bin <<=1) {
		if (diff & bin) {
			v = up[v][i];
			diff -= bin;
		}
	}
	for (int i=log(dep[u])/log(2);i>=0;i--) {
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}
	if (u == v) return u;
	return up[u][0];
}
bool inpath(int x,int s,int t) {
	return dep[x] >= dep[lca(s,t)] && (lca(s,x) == x || lca(x,t) == x);
}
int main() {
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	while (q --) {
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if (inpath(lca(a,b),c,d) || inpath(lca(c,d),a,b)) printf("Y\n");
		else printf("N\n");
	}
	return 0;
}
