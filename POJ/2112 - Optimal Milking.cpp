#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int g[231][231];
int pre[31][15];
bool vis[31][15];
int k,c,m;
bool dfs(int u,int limit) {
	for (int i=1;i<=k;i++) {
		if (g[u][i] > limit) continue;
		for (int j=0;j<m;j++) {
			if (vis[i][j]) continue;
			vis[i][j] = true;
			if (pre[i][j] == -1 || dfs(pre[i][j],limit)) {
				pre[i][j] = u;
				return true;
			}
		}
	}
	return false;
}
int check(int mid) {
	memset(pre,-1,sizeof(pre));
	int ans = 0;
	for (int i=k+1;i<=k+c;i++) {
		memset(vis,false,sizeof(vis));
		ans += dfs(i,mid);
	}
	return ans;
}
int main() {
	while (scanf("%d%d%d",&k,&c,&m) == 3) {
		for (int i=1;i<=k+c;i++) for (int j=1;j<=k+c;j++) {
			scanf("%d",&g[i][j]);
			if (g[i][j] == 0) g[i][j] = INF;
		}
		for (int _k=1;_k<=k+c;_k++) for (int i=1;i<=k+c;i++) for (int j=1;j<=k+c;j++) g[i][j] = min(g[i][j],g[i][_k] + g[_k][j]);
		int ans = -1;
		int l = 1,r = INF;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid) == c) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
