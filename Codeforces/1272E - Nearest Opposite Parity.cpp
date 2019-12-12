#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int inf = 0x3f3f3f3f;
int a[maxn];
int dis[maxn][2];
int n;
vector <int> g[maxn];//建图要反着来
void bfs() {
	for (int i=1;i<=n;i++) {
		int l = i - a[i];
		if (l >= 1) g[l].push_back(i);
		int r = i + a[i];
		if (r <= n) g[r].push_back(i);
	}
	queue <int> q[2];
	for (int i=1;i<=n;i++) {
		q[a[i]&1].push(i);
		dis[i][a[i]&1] = 0;
	}
	while (!q[0].empty()) {
		int u = q[0].front();
		q[0].pop();
		for (auto v:g[u]) {
			if (dis[v][0] > dis[u][0] + 1) {
				dis[v][0] = dis[u][0] + 1;
				q[0].push(v);
			}
		}
	}
	while (!q[1].empty()) {
		int u = q[1].front();
		q[1].pop();
		for (auto v:g[u]) {
			if (dis[v][1] > dis[u][1] + 1) {
				dis[v][1] = dis[u][1] + 1;
				q[1].push(v);
			}
		}
	}
}
int main() {
	memset(dis,0x3f,sizeof(dis));
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	bfs();
	for (int i=1;i<=n;i++) printf("%d%c",dis[i][(a[i]&1)^1]==inf?-1:dis[i][(a[i]&1)^1],i==n?'\n':' ');
	return 0;
}
