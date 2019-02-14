#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int pre[500];
bool vis[500];
vector <int> g[500];
int read() {
	int ret = 0;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret;
}
int dfs(int u) {
	for (vector<int>::iterator it=g[u].begin();it != g[u].end();it ++) {
		int v = *it;
		if (!vis[v]) {
			vis[v] = true;
			if (pre[v] == -1 || dfs(pre[v])) {
				pre[v] = u;
				return true;
			}
		}
	}
	return false;
}
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		for (int i=0;i<n;i++) g[i].clear();
		memset(pre,-1,sizeof(pre));
		for (int i=0;i<n;i++) {
			int id = read();
			int m = read();
			while (m --) {
				int w;
				scanf("%d",&w);
				g[id].push_back(w);
			}
		}
		int ans = 0;
		for (int i=0;i<n;i++) {
			memset(vis,false,sizeof(vis));
			ans += dfs(i);
		}
		printf("%d\n",n-ans/2);
	}
	return 0;
}
