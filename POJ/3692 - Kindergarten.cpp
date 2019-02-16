#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int g,b,m;
bool l[200][200];
bool vis[200];
int pre[200];
bool dfs(int u) {
	for (int i=0;i<b;i++) {
		if (!l[u][i]) continue;
		if (!vis[i]) {
			vis[i] = true;
			if (pre[i] == -1 || dfs(pre[i])) {
				pre[i] = u;
				return true;
			}
		}
	}
	return false;
}
int main() {
	int cas = 0;
	while (scanf("%d%d%d",&g,&b,&m) == 3 && g && b) {
		memset(l,true,sizeof(l));
		for (int i=0;i<m;i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			x --;
			y --;
			l[x][y] = false;
		}
		int match = 0;
		memset(pre,-1,sizeof(pre));
		for (int i=0;i<g;i++) {
			memset(vis,false,sizeof(vis));
			match += dfs(i);
		}
		printf("Case %d: %d\n",++cas,b+g-match);
	}
	return 0;
}
