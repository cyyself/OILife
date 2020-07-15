#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
int id[505][505];//以网格图左下角的点作为对偶图的面的点
vector <pair<int,int> > g[505*505];
const long long inf = 0x3f3f3f3f3f3f3f3f;
void add(int u,int v,int c) {
	g[u].push_back({v,c});
	g[v].push_back({u,c});
}
long long dis[505*505];
priority_queue <pair<long long,int> > q;
void dijkstra(int s) {
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	q.push({0,s});
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		int u = cur.second;
		if (dis[u] != -cur.first) continue;
		for (auto x:g[u]) {
			int v = x.first;
			int w = x.second;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push({-dis[v],v});
			}
		}
	}
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int s = 0, t = 1, idcnt = 2;//之后的编号都采用对偶图
	for (int l=1;l<=n;l++) for (int r=l;r<=n;r++) id[l][r] = idcnt ++;
	for (int i=0;i<m;i++) {
		int l,r,c;
		char dir;
		scanf("%d%d %c%d",&l,&r,&dir,&c);
		if (dir == 'L') {
			if (r == n) add(id[l][r],s,c);
			else add(id[l][r],id[l][r+1],c);
		}
		else if (dir == 'R') {
			if (l == 1) add(id[l][r],t,c);
			else add(id[l-1][r],id[l][r],c);
		}
		else assert(false);
	}
	dijkstra(s);
	if (dis[t] == inf) printf("-1\n");
	else printf("%lld\n",dis[t]);
	return 0;
}
