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
	void Init(int n) {
		V = n;
		for (int i = 0; i <= V; ++i)G[i].clear();
	}
	void Add_Edge(int from, int to, int cap, int cost) {
		G[from].push_back(edge(to, cap, cost, G[to].size()));
		G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
	}
	int Min_cost_max_flow(int s, int t, int f, int& flow) {
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
}MCMF;
int a[105][105],n;
void work1() {
	MCMF.Init(2*n+1);
	for (int i=1;i<=n;i++) {
		MCMF.Add_Edge(0,i,1,0);
		for (int j=1;j<=n;j++) MCMF.Add_Edge(i,n+j,1,a[i][j]);
		MCMF.Add_Edge(n+i,2*n+1,1,0);
	}
	int f;
	printf("%d\n",MCMF.Min_cost_max_flow(0,2*n+1,INF,f));
}
void work2() {
	MCMF.Init(2*n+1);
	for (int i=1;i<=n;i++) {
		MCMF.Add_Edge(0,i,1,0);
		for (int j=1;j<=n;j++) MCMF.Add_Edge(i,n+j,1,-a[i][j]);
		MCMF.Add_Edge(n+i,2*n+1,1,0);
	}
	int f;
	printf("%d\n",-MCMF.Min_cost_max_flow(0,2*n+1,INF,f));
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	work1();
	work2();
	return 0;
}
