#include <bits/stdc++.h>
using namespace std;
vector <int> g[105][2];
int w[105];
struct DATA {
	int dis,u;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.dis > b.dis;
	}
};
int dis[105];
int dij(int s,int type,int t) {
	memset(dis,0x3f,sizeof(dis));
	dis[s] = w[s];
	priority_queue <DATA> q;
	q.push((DATA){dis[s],s});
	while (!q.empty()) {
		DATA cur = q.top();
		q.pop();
		if (cur.dis > dis[cur.u]) continue;
		if (cur.u == t) return dis[t];
		for (int typ=0;typ<2;typ++) {
			if (cur.u == s && typ == type) continue;
			for (auto v:g[cur.u][typ]) {
				if (dis[cur.u] + w[v] < dis[v]) {
					dis[v] = dis[cur.u] + w[v];
					q.push((DATA){dis[v],v});
				}
			}
		}
	}
	return 0x3f3f3f3f;
}
set <pair<int,int> > e;
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int u,l,n1,n2;
		scanf("%d%d%d%d",&u,&l,&n1,&n2);
		w[u] = l;
		while (n1 --) {
			int v;
			scanf("%d",&v);
			g[u][0].push_back(v);
		}
		while (n2 --) {
			int v;
			scanf("%d",&v);
			g[u][1].push_back(v);
		}
	}
	int ans = 0x3f3f3f3f;
	for (int u=1;u<=n;u++) {
		for (auto v:g[u][0]) ans = min(ans,dij(u,0,v));
		for (auto v:g[u][1]) ans = min(ans,dij(u,1,v));
	}
	printf("%d\n",ans);
	return 0;
}
