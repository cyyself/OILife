#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
set <int> g[5005];
bool vis[5005];
int pre[5005];
char s[50][51];
bool dfs(int u) {
	for (set<int>::iterator it=g[u].begin();it != g[u].end();it ++) {
		int v = *it;
		if (vis[v]) continue;
		vis[v] = true;
		if (pre[v] == -1 || dfs(pre[v])) {
			pre[v] = u;
			return true;
		}
	}
	return false;
}
int main() {
	int r,c;
	while (scanf("%d%d",&r,&c) == 2) {
		memset(pre,-1,sizeof(pre));
		for (int i=0;i<r;i++) {
			scanf("%s",s[i]);
			for (int j=0;j<c;j++) if (s[i][j] == '*') {
				int x = i;
				int y = j;
				while (x > 0 && s[x-1][j] == '*') {
					x --;
				}
				while (y > 0 && s[i][y-1] == '*') {
					y --;
				}
				g[x*c+j].insert(i*c+y);
			}
		}
		int ans = 0;
		for (int i=0;i<r*c;i++) {
			memset(vis,false,sizeof(vis));
			ans += dfs(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
