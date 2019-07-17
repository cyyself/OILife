#include <bits/stdc++.h>
using namespace std;
vector <pair<int,long long> > g[100005];
long long d[2][100005];
bool inq[100005];
int pre[100005];
int n,m;
void spfa(int s,long long *dis) {
	memset(dis,0x3f,sizeof(long long)*(n+1));
	queue <int> q;
	dis[s] = 0;
	q.push(s);
	pre[s] = -1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (auto e:g[u]) {
			int v = e.first;
			int w = e.second;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				pre[v] = u;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=0;i<m;i++) {
			int u,v;
			long long w;
			scanf("%d%d%lld",&u,&v,&w);
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		spfa(n,d[1]);
		spfa(1,d[0]);
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (int u=1;u<=n;u++) {
			for (auto e:g[u]) {
				int v = e.first;
				int w = e.second;
				if (pre[v] != u) {
					ans = min(ans,d[0][u] + w + d[1][v]);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
