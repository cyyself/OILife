#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct edge {
	int to;
	long long capacity, cost;
	int rev;
	edge() {}
	edge(int to, long long _capacity, long long _cost,int _rev) :to(to), capacity(_capacity), cost(_cost), rev(_rev) {}
};
struct Min_Cost_Max_Flow {
	int V;
	long long H[4005], dis[4005];
	int PreV[4005], PreE[4005];
	vector<edge> G[4005];
	void init(int n) {
		V = n;
		for (int i = 0; i <= V; ++i)G[i].clear();
	}
	void addedge(int from, int to, long long cap, long long cost) {
		G[from].push_back(edge(to, cap, cost, G[to].size()));
		G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
	}
	long long cal(int s, int t, long long f, long long& flow) {
		long long res = 0;
		fill(H, H + 1 + V, 0);
		while (f) {
			priority_queue <pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
			fill(dis, dis + 1 + V, INF);
			dis[s] = 0; q.push(pair<int, int>(0, s));
			while (!q.empty()) {
				pair<long long, int> now = q.top(); q.pop();
				int v = now.second;
				if (dis[v] < now.first)continue;
				for (int i = 0; i < G[v].size(); ++i) {
					edge& e = G[v][i];
					if (e.capacity > 0 && dis[e.to] > dis[v] + e.cost + H[v] - H[e.to]) {
						dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
						PreV[e.to] = v;
						PreE[e.to] = i;
						q.push(pair<long long, int>(dis[e.to], e.to));
					}
				}
			}
			if (dis[t] == INF)break;
			for (int i = 0; i <= V; ++i)H[i] += dis[i];
			long long d = f;
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
#define x first
#define y second
pair <int,int> s[500];
vector <int> ls;
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&s[i].x,&s[i].y);
		if (s[i].x > s[i].y) swap(s[i].x,s[i].y);
		ls.push_back(s[i].x);
		ls.push_back(s[i].y);
	}
	sort(ls.begin(),ls.end());
	ls.erase(unique(ls.begin(),ls.end()),ls.end());
	ls.push_back(0x3f3f3f3f);
	MCMF.init(ls.size());
	for (int i=0;i<(int)ls.size()-1;i++) MCMF.addedge(i,i+1,k,0);
	for (int i=0;i<n;i++) {
		int lsx = lower_bound(ls.begin(),ls.end(),s[i].x) - ls.begin();
		int lsy = lower_bound(ls.begin(),ls.end(),s[i].y) - ls.begin();
		MCMF.addedge(lsx,lsy,1,-(s[i].y-s[i].x));
	}
	long long flow;
	printf("%lld\n",-MCMF.cal(0,(int)ls.size()-1,INF,flow));
	return 0;
}
