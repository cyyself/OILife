//要处理入度为0的地方和有环的地方
#include <bits/stdc++.h>
using namespace std;
int ind[10005];
bool stat[10005];
vector <int> g[10005];
int read() {
	int ret = 0;
	char c = getchar();
	while ( !(c >= '0' && c <= '9') ) {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret;
}
void dfs(int n) {
	stat[n] = false;
	for (auto v:g[n]) if (stat[v]) dfs(v);
}
int main() {
	int n,m;
	int T = 0;
	while (scanf("%d%d",&n,&m) == 2) {
		memset(ind,0,sizeof(ind));
		memset(stat,true,sizeof(stat));
		while (m--) {
			int u,v;
			u = read();
			v = read();
			ind[v] ++;
			g[u].push_back(v);
		}
		int cnt = 0;
		for (int i=1;i<=n;i++) if (ind[i] == 0) {
			cnt++;
			dfs(i);
		}
		for (int i=1;i<=n;i++) {//处理环的任意一点
			if (stat[i]) {
				dfs(i);
				cnt++;
			}
		}
		for (int i=1;i<=n;i++) g[i].clear();
		printf("Case %d: %d\n",++T,cnt);
	}
	return 0;
}
