#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> g[1005];
int pre[1005];
bool vis[1005];
bool dfs(int u) {
	for (vector<int>::iterator it=g[u].begin();it != g[u].end();it ++) {
		int v = *it;
		if (!vis[v]) {
			vis[v] = true;
			if (!pre[v] || dfs(pre[v])) {
				pre[v] = u;
				return true;
			}
		}
	}
	return false;
}
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		memset(pre,0,sizeof(pre));
		for (int i=1;i<=n;i++) {
			int k;
			scanf("%d",&k);
			g[i].clear();
			while (k --) {
				int v;
				scanf("%d",&v);
				g[i].push_back(v);
			}
		}
		int ans = 0;
		for (int i=1;i<=n;i++) {
			memset(vis,false,sizeof(vis));
			ans += dfs(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
