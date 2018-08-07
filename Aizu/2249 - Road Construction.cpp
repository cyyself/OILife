#include <bits/stdc++.h>
using namespace std;
int n,m;
struct edge {
	int v,d,c;
};
vector <edge> e[10005];
int dis[10005];
int cost[10005];
bool inq[10005];
void spfa(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(cost,0x3f,sizeof(cost));
	memset(inq,false,sizeof(inq));
	queue <int> q;
	dis[s] = 0;
	cost[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (edge i:e[u]) {
			int v = i.v;
			if (dis[u] + i.d < dis[v] || (dis[u]+i.d == dis[v] && cost[v] > i.c)) {
				dis[v] = dis[u] + i.d;
				cost[v] = i.c;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
}
int main() {
	while (scanf("%d%d",&n,&m) == 2) {
		if (n == 0 && m == 0) break;
		for (int i=0;i<m;i++) {
			int u,v,d,c;
			scanf("%d%d%d%d",&u,&v,&d,&c);
			e[u].push_back((edge){v,d,c});
			e[v].push_back((edge){u,d,c});
		}
		spfa(1);
		int ans = 0;
		for (int i=2;i<=n;i++) ans += cost[i];
		printf("%d\n",ans);
		for (int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}
