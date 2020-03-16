#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 50005;
const int inf = 0x3f3f3f3f;
int p[maxn];
int dep[maxn];
int up[maxn][20];
vector <int> tr[maxn];
int MIN[maxn][20],MAX[maxn][20],f[maxn][20],g[maxn][20];//f往上走,g往下走
void dfs(int u,int rt) {
	up[u][0] = rt;
	MIN[u][0] = ((u == 1)?inf:min(p[rt],p[u]));
	MAX[u][0] = ((u == 1)?0:max(p[rt],p[u]));
	f[u][0] = ((u == 1)?0:max(0,p[rt]-p[u]));
	g[u][0] = ((u == 1)?0:max(0,p[u]-p[rt]));
	for (int j=1;(1<<j)<=dep[u];j++) {
		int uu = up[u][j-1];
		up[u][j] = up[uu][j-1];
		MIN[u][j] = min(MIN[u][j-1],MIN[uu][j-1]);
		MAX[u][j] = max(MAX[u][j-1],MAX[uu][j-1]);
		f[u][j] = max(f[u][j-1],max(f[uu][j-1],MAX[uu][j-1] - MIN[u][j-1]));
		g[u][j] = max(g[u][j-1],max(g[uu][j-1],MAX[u][j-1] - MIN[uu][j-1]));
	}
	//for (auto v:tr[u]) {
	for (int i=0;i<tr[u].size();i++) {
		int v = tr[u][i];
		if (v == rt) continue;
		dep[v] = dep[u] + 1;
		dfs(v,u);
	}
}
int getlca(int u,int v) {
	if (dep[u] < dep[v]) swap(u,v);
	int diff = dep[u] - dep[v];
	for (int i=0;(1<<i)<=diff;i++) if (diff & (1 << i)) {
		u = up[u][i];
		diff -= (1 << i);
	}
	for (int i=log(u)/log(2);i>=0;i--) {
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}
	return (u == v?u:up[u][0]);
}
//这几个query函数都是针对链的
int query_up_min(int u,int v) {
	int diff = dep[u] - dep[v];
	int res = inf;
	for (int i=0;(1<<i)<=diff;i++) if (diff & (1 << i)) {
		res = min(res,MIN[u][i]);
		u = up[u][i];
	}
	return res;
}
int query_up_max(int u,int v) {
	int diff = dep[u] - dep[v];
	int res = 0;
	for (int i=0;(1<<i)<=diff;i++) if (diff & (1 << i)) {
		res = max(res,MAX[u][i]);
		u = up[u][i];
	}
	return res;
}
int query_up(int u,int v) {
	int ans = 0;
	int diff = dep[u] - dep[v];
	int mi = inf;
	for (int i=0;(1<<i)<=diff;i++) if (diff & (1 << i)) {
		ans = max(ans,f[u][i]);
		mi = min(mi,MIN[u][i]);
		u = up[u][i];
		diff -= (1 << i);
		ans = max(ans,query_up_max(u,v) - mi);
	}
	return ans;
}
int query_down(int u,int v) {
	int ans = 0;
	int diff = dep[v] - dep[u];
	int mx = 0;
	for (int i=0;(1<<i)<=diff;i++) if (diff & (1 << i)) {
		ans = max(ans,g[v][i]);
		mx = max(mx,MAX[v][i]);
		v = up[v][i];
		diff -= (1 << i);
		ans = max(ans,mx - query_up_min(v,u));
	}
	return ans;
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&p[i]);
	}
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	dfs(1,0);
	int q;
	scanf("%d",&q);
	while (q --) {
		int u,v;
		scanf("%d%d",&u,&v);
		int lca = getlca(u,v);
		if (lca == u || lca == v) {
			if (dep[u] > dep[v]) printf("%d\n",query_up(u,v));
			else printf("%d\n",query_down(u,v));
		}
		else {
			int ans = max(query_up(u,lca),max(query_down(lca,v),query_up_max(v,lca) - query_up_min(u,lca)));
			printf("%d\n",ans);
		}
	}
	return 0;
}
