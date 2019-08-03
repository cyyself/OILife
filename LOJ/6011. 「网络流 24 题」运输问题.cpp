#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge {
	int to, capacity, cost, rev;
	edge() {}
	edge(int to, int _capacity, int _cost, int _rev) :to(to), capacity(_capacity), cost(_cost), rev(_rev) {}
};
struct Min_Cost_Max_Flow {
	int V, H[4005], dis[4005], PreV[4005], PreE[4005];
	vector<edge> G[4005];
	void init(int n) {
		V = n;
		for (int i = 0; i <= V; ++i)G[i].clear();
	}
	void add(int from, int to, int cap, int cost) {
		G[from].push_back(edge(to, cap, cost, G[to].size()));
		G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
	}
	int cal(int s, int t, int f, int& flow) {
		int res = 0; fill(H, H + 1 + V, 0);
		while (f) {
			priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
			fill(dis, dis + 1 + V, INF);
			dis[s] = 0; q.push(pair<int, int>(0, s));
			while (!q.empty()) {
				pair<int, int> now = q.top(); q.pop();
				int v = now.second;
				if (dis[v] < now.first)continue;
				for (int i = 0; i < G[v].size(); ++i) {
					edge& e = G[v][i];
					if (e.capacity > 0 && dis[e.to] > dis[v] + e.cost + H[v] - H[e.to]) {
						dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
						PreV[e.to] = v;
						PreE[e.to] = i;
						q.push(pair<int, int>(dis[e.to], e.to));
					}
				}
			}
			if (dis[t] == INF)break;
			for (int i = 0; i <= V; ++i)H[i] += dis[i];
			int d = f;
			for (int v = t; v != s; v = PreV[v])d = min(d, G[PreV[v]][PreE[v]].capacity);
			f -= d; flow += d; res += d*H[t];
			for (int v = t; v != s; v = PreV[v]) {
				edge& e = G[PreV[v]][PreE[v]];
				e.capacity -= d;
				G[v][e.rev].capacity += d;
			}
		}
		return res;
	}
}mcmf;
int a[105],b[105],c[105][105];
int m,n;
void work1() {
	mcmf.init(m+n+1);
	for (int i=1;i<=m;i++) mcmf.add(0,i,a[i],0);
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) mcmf.add(i,m+j,INF,c[i][j]);
	for (int i=1;i<=n;i++) mcmf.add(m+i,m+n+1,b[i],0);
	int f;
	printf("%d\n",mcmf.cal(0,m+n+1,INF,f));
}
void work2() {
	mcmf.init(m+n+1);
	for (int i=1;i<=m;i++) mcmf.add(0,i,a[i],0);
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) mcmf.add(i,m+j,INF,-c[i][j]);
	for (int i=1;i<=n;i++) mcmf.add(m+i,m+n+1,b[i],0);
	int f;
	printf("%d\n",-mcmf.cal(0,m+n+1,INF,f));
}
int main() {
	scanf("%d%d",&m,&n);
	int suma = 0,sumb = 0;
	for (int i=1;i<=m;i++) {
		scanf("%d",&a[i]);
		suma += a[i];
	}
	for (int i=1;i<=n;i++) {
		scanf("%d",&b[i]);
		sumb += b[i];
	}
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) scanf("%d",&c[i][j]);
	work1();
	work2();
	return 0;
}
