#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const double eps = 1e-6;
long long c[maxn];
vector <pair<int,int> > g[maxn];
long long b[maxn];
vector <int> ch[maxn];
void dfs(int u,int rt) {
	for (auto x:g[u]) {
		int v = x.first;
		int w = x.second;
		if (v == rt) continue;
		b[v] = w * 2;
		ch[u].push_back(v);
		dfs(v,u);
	}
}
double cal(double mid,int u) {
	double res = c[u] - mid * b[u];
	for (auto v:ch[u]) {
		res += max((double)0,cal(mid,v));
	}
	return res;
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for (int i=1;i<=n;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs(0,-1);
	double l = 0, r = 1e15;
	while (r - l > eps) {
		double mid = (l + r) / 2;
		if (cal(mid,0) > 0) l = mid;
		else r = mid;
	}
	printf("%0.10f\n",l);
	return 0;
}
