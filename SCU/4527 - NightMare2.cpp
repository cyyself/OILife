#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int v;
	int cap;
	long long w;
};
struct DATA {
	int u;
	long long dis;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.dis > b.dis;
	}
};
const long long INF = 0x3f3f3f3f3f3f3f3f;
vector <Edge> g[50005];
int n,m,k;
bool spfa(int limit) {
	static long long dis[50005];
	dis[1] = 0;
	for (int i=2;i<=n;i++) dis[i] = INF;
	priority_queue <DATA> q;
	q.push((DATA){1,0});
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		if (cur.dis > dis[cur.u]) continue;
		for (auto e:g[cur.u]) {
			if (e.cap < limit) continue;
			if (dis[cur.u] + e.w < dis[e.v]) {
				dis[e.v] = dis[cur.u] + e.w;
				q.push((DATA){e.v,dis[e.v]});
			}
		}
	}
	return dis[n] <= k;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d%d%d",&n,&m,&k);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=0;i<m;i++) {
			int u,v,c;
			long long d;
			scanf("%d%d%d%lld",&u,&v,&c,&d);
			g[u].push_back((Edge){v,c,d});
			g[v].push_back((Edge){u,c,d});
		}
		int l = 0;
		int r = 2000000000;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (spfa(mid)) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (ans == -1) printf("Poor RunningPhoton!\n");
		else printf("%d\n",ans);
	}
	return 0;
}
