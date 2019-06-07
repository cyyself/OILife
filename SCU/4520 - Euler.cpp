#include <bits/stdc++.h>
using namespace std;
int degdiff[505];
int deg[505];
vector <int> g[505];
int n,m;
int vis[505];
int bfs(int s) {
	queue <int> q;
	q.push(s);
	vis[s] = true;
	int cnt = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cnt ++;
		for (auto v:g[u]) {
			if (!vis[v]) {
				vis[v] = true;
				q.push(v);
			}
		}
	}
	return cnt;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) {
			deg[i] = degdiff[i] = 0;
			vis[i] = false;
			g[i].clear();
		}
		for (int i=0;i<m;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
			deg[u] ++;
			deg[v] ++;
			degdiff[v] ++;
			degdiff[u] --;
		}
		int bcnt = bfs(1);
		bool ans1 = bcnt == n;
		if (ans1) {
			int cnt = 0;
			for (int i=1;i<=n;i++) if (deg[i] & 1) cnt ++;
			if (!(cnt == 0 || cnt == 2)) ans1 = false; 
		}
		bool ans2 = ans1;
		int cnt1 = 0, cnt2 = 0;
		for (int i=1;i<=n && ans2;i++) {
			if (degdiff[i] == -1) cnt1 ++;
			else if (degdiff[i] == 1) cnt2 ++;
			else if (degdiff[i] != 0) ans2 = false;
		}
		printf("%s %s\n",ans1?"Yes":"No",ans2?"Yes":"No");
	}
	return 0;
}
