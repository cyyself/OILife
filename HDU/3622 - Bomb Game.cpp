#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-4;
vector <int> g[205];
bool vis[205];
int dfn[205],low[205],root[205];
int rootcnt;
int timestamp;
stack <int> s;
void tarjan(int u) {
	dfn[u] = low[u] = ++timestamp;
	vis[u] = true;
	s.push(u);
	for (auto v:g[u]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else {
			if (vis[v]) low[u] = min(low[u],dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		rootcnt ++;
		while (!s.empty()) {
			int v = s.top();
			s.pop();
			root[v] = rootcnt;
			vis[v] = false;
			if (v == u) break;
		}
	}
}
int n;
struct Pos {
	double x,y;
	friend double operator - (const Pos &a,const Pos &b) {
		double dx = a.x - b.x;
		double dy = a.y - b.y;

		return sqrt(dx * dx + dy * dy);
	}
}p[101][2];
bool check(double x) {
	for (int i=1;i<=2*n;i++) {
		g[i].clear();
		dfn[i] = 0;
	}
	timestamp = rootcnt = 0;
	for (int i=1;i<=n;i++) for (int j=1;j<i;j++) {
		if (p[i][0] - p[j][0] < x * 2) {
			g[i].push_back(j+n);
			g[j].push_back(i+n);
		}
		if (p[i][0] - p[j][1] < x * 2) {
			g[i].push_back(j);
			g[j+n].push_back(i+n);
		}
		if (p[i][1] - p[j][0] < x * 2) {
			g[i+n].push_back(j+n);
			g[j].push_back(i);
		}
		if (p[i][1] - p[j][1] < x * 2) {
			g[i+n].push_back(j);
			g[j+n].push_back(i);
		}
	}
	for (int i=1;i<=2*n;i++) if (!dfn[i]) tarjan(i);
	for (int i=1;i<=n;i++) if (root[i] == root[i+n]) return false;
	return true;
}
int main() {
	while (scanf("%d",&n) == 1) {
		for (int i=1;i<=n;i++) scanf("%lf%lf%lf%lf",&p[i][0].x,&p[i][0].y,&p[i][1].x,&p[i][1].y);
		double l = 0;
		double r = 1e9;
		while (r - l > eps) {
			double mid = (l + r) / 2;
			if (check(mid)) {
				l = mid;
			}
			else r = mid;
		}
		printf("%0.2lf\n",l);
	}
	return 0;
}
