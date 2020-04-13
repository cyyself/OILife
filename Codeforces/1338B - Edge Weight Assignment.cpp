#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector <int> g[maxn];
bool vis[maxn];
int dis[2];
int ans;
void dfs(int u,int fa,int dep) {
	if (g[u].size() == 1) dis[dep] ++;
	for (auto v:g[u]) {
		if (v == fa) continue;
		dfs(v,u,dep^1);
	}
}
int main() {
	int n;
	scanf("%d",&n);
	ans = n;
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,-1,0);
	if (dis[0] && dis[1]) printf("3 ");
	else printf("1 ");
	int ans = n - 1;
	for (int i=1;i<=n;i++) if (g[i].size() == 1) {
		ans -= vis[g[i][0]];
		vis[g[i][0]] = true;
	}
	printf("%d\n",ans);
	return 0;
}
