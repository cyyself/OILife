#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct edge {
	int v;
	long long a,b;
	long long t;
};
vector <edge> g[305];
long long dis[305];
bool inq[305];
void spfa(int s) {
	memset(dis,0x3f,sizeof(dis));
	queue <int> q;
	q.push(s);
	dis[s] = 0;
	inq[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (auto e:g[u]) {
			if (e.a < e.t) continue;
			long long now = dis[u] % (e.a + e.b);
			long long tmp = dis[u] + e.t;
			if (e.a - now < e.t) tmp += e.a + e.b - now;//加上等待时间
			if (dis[e.v] > tmp) {
				dis[e.v] = tmp;
				if (!inq[e.v]) {
					q.push(e.v);
					inq[e.v] = true;
				}
			}    
		}
	}
}
int main() {
	int n,m,s,t;
	int c = 1;
	while (scanf("%d%d%d%d",&n,&m,&s,&t) == 4) {
		for (int i=1;i<=n+1;i++) g[i].clear();
		while (m--) {
			int u,v;
			long long a,b,_t;
			scanf("%d%d%lld%lld%lld",&u,&v,&a,&b,&_t);
			g[u].push_back((edge){v,a,b,_t});
		}
		spfa(s);
		if (dis[t] == INF) printf("Case %d: -1\n",c++);
		else printf("Case %d: %lld\n",c++,dis[t]);
	}
	return 0;
}
