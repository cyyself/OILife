#include <bits/stdc++.h>
using namespace std;
struct edge {
	int v,w;
	edge (int _v,int _w) {
		v = _v;
		w = _w;
	}
};
int cut1,cut2;
vector <edge> g[1000005];
int sum;
int w[1000005];
bool vis[1000005];
int suf[1000005];
void dfs(int u) {
	vis[u] = true;
	int cursum = w[u];
	for (auto e:g[u]) {
		int v = e.v;
		int w = e.v;
		if (!vis[v]) {
			dfs(v);
			if (u != 0 && suf[v] == sum && cut2 == -1) {
				if (cut1 == -1) cut1 = v;
				else cut2 = v;
			}
			else cursum += suf[v];
		}
	}
	suf[u] = cursum;
}
int main() {
	int n;
	scanf("%d",&n);
	for (int u=1;u<=n;u++) {
		int v,_w;
		scanf("%d%d",&v,&_w);
		sum += _w;
		w[u] = _w;
		g[u].push_back(edge(v,_w));
		g[v].push_back(edge(u,_w));
	}
	if (sum % 3 != 0) {
		printf("-1\n");
		return 0;
	}
	cut1 = -1;
	cut2 = -1;
	sum /= 3;
	dfs(0);
	if (cut2 == -1) printf("-1\n");
	else printf("%d %d\n",cut1,cut2);
	return 0;
}
