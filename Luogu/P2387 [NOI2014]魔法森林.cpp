#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int u,v;
	long long a,b;
	friend bool operator < (const Edge &a,const Edge &b) {
		return a.a < b.a;
	}
}e[100000];
long long dis[50005];
struct DATA {
	int u;
	long long w;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.w > b.w;
	}
};
priority_queue <DATA> q;
struct edge {
	int v;
	long long w;
};
vector <edge> g[50005];
void AddEdge(int u,int v,long long w) {
	g[u].push_back({v,w});
}
void dijkstra() {
	while (!q.empty()) {
		DATA cur = q.top();
		q.pop();
		int u = cur.u;
		if (dis[u] < cur.w) continue;
		for (auto x:g[u]) {
			int v = x.v;
			int w = max(x.w,dis[u]);
			if (w < dis[v]) {
				dis[v] = w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main() {
	memset(dis,0x3f,sizeof(dis));
	dis[1] = 0;
	int n,m;
	scanf("%d%d",&n,&m);
	long long maxb = 0;
	for (int i=0;i<m;i++) {
		scanf("%d%d%lld%lld",&e[i].u,&e[i].v,&e[i].a,&e[i].b);
		maxb = max(maxb,e[i].b);
	}
	sort(e,e+m);
	long long ans = e[m-1].a + maxb + 1;
	int ptr = 0;
	while (ptr < m) {
		long long cura = e[ptr].a;
		if (cura >= ans) break;
		do {
			AddEdge(e[ptr].u,e[ptr].v,e[ptr].b);
			if (max(dis[e[ptr].u],e[ptr].b) < dis[e[ptr].v]) {
				dis[e[ptr].v] = max(dis[e[ptr].u],e[ptr].b);
				q.push({e[ptr].v,dis[e[ptr].v]});
			}
			AddEdge(e[ptr].v,e[ptr].u,e[ptr].b);
			if (max(dis[e[ptr].v],e[ptr].b) < dis[e[ptr].u]) {
				dis[e[ptr].u] = max(dis[e[ptr].v],e[ptr].b);
				q.push({e[ptr].u,dis[e[ptr].u]});
			}
			ptr ++;
		}
		while (ptr < m && e[ptr].a == e[ptr-1].a);
		dijkstra();
		ans = min(ans,cura+dis[n]);
	}
	if (ans > e[m-1].a + maxb) printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}
