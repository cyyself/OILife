#include <bits/stdc++.h>
using namespace std;
int deg[1005];
bool vis[1005];
bool vis_down[1005];//下层不必考虑的点
int cnt;
int ask(int u,int v) {
	cnt ++;
	vis[u] = true;
	vis[v] = true;
	printf("? %d %d\n",u,v);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	if (res != u) vis_down[u] = true;
	if (res != v) vis_down[v] = true;
	vis[res] = true;
	return res;
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		deg[u] ++;
		deg[v] ++;
	}
	queue <int> q;
	for (int i=1;i<=n;i++) if (deg[i] == 1) {
		q.push(i);
	}
	int u = q.front();
	q.pop();
	int v = q.front();
	q.pop();
	int lca = ask(u,v);
	while (!q.empty()) {
		while (!q.empty() && vis[q.front()]) q.pop();
		if (q.empty()) break;
		u = q.front();
		q.pop();
		int v = -1;
		while (!q.empty()) {
			if (!vis[q.front()]) {
				v = q.front();
				q.pop();
				break;
			}
			else q.pop();
		}
		if (~v) {
			int n_lca = ask(u,v);
			vis[n_lca] = true;
			if (cnt == n / 2) break;
			if (!vis_down[n_lca] && lca != n_lca) lca = ask(lca,n_lca);
		}
		else {
			lca = ask(u,lca);
		}
		if (cnt == n / 2) break;
	}
	printf("! %d\n",lca);
	return 0;
}
