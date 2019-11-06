#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 405*2;
const int maxe = 405*405*2;
const double eps = 1e-5;
int head[maxn];
struct Edge {
	int v;
	double w;
	int next;
}e[maxe];
int ecnt;
void add(int u,int v,double w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int n,m;
 
double dis[maxn];

bool ins[maxn];
bool vis[maxn];
bool dfs(int u) {
	vis[u] = true;
	if (ins[u]) return false;
	ins[u] = true;
	for (int i=head[u];~i;i=e[i].next) {
		int v = e[i].v;
		double w = e[i].w;
		if (dis[u] + w + eps < dis[v]) {
			dis[v] = dis[u] + w;
			if (!dfs(v)) return false;
		}
	}
	ins[u] = false;
	return true;
}
bool spfa() {
	for (int i=0;i<n+m;i++) {
		dis[i] = 0;
		ins[i] = 0;
		vis[i] = 0;
	}
	for (int i=0;i<n+m;i++) {
		if (!vis[i] && !dfs(i)) return false;
	}
	return true;
}
double mt[405][405];
int main() {
	double l,u;
	while (scanf("%d%d%lf%lf",&n,&m,&l,&u) == 4) {
		for (int i=0;i<n+m;i++) head[i] = -1;
		ecnt = 0;
		l = log(l);
		u = log(u);
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
			scanf("%lf",&mt[i][j]);
			mt[i][j] = log(mt[i][j]);
		}
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
			double x = mt[i][j];
			add(i,n+j,mt[i][j] - l);
			add(n+j,i,u - mt[i][j]);
		}
		if (spfa()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
