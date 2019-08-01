#include <bits/stdc++.h>
using namespace std;
vector <int> g[101];
int pre[101];
bool vis[101];
bool dfs(int u) {
	for (auto v:g[u]) {
		if (vis[v]) continue;
		vis[v] = true;
		if (pre[v] == -1 || dfs(pre[v])) {
			pre[v] = u;
			return true;
		}
	}
	return false;
}
int m,n;
void work() {
	memset(pre,-1,sizeof(pre));
	int match = 0;
	for (int i=1;i<=m;i++) {
		memset(vis,false,sizeof(vis));
		match += dfs(i);
	}
	if (match == 0) printf("No Solution!\n");
	else {
		printf("%d\n",match);
		for (int i=1;i<=n;i++) if (pre[i] != -1) printf("%d %d\n",pre[i],i);
	}
}
int main() {
	scanf("%d%d",&m,&n);
	int u,v;
	while (scanf("%d%d",&u,&v) == 2 && u != -1 && v != -1) g[u].push_back(v);
	work();
	return 0;
}
