#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct Edge1{
	int u,v,w;
	friend bool operator < (const Edge1 &a,const Edge1 &b) {
		if (a.w > b.w) return true;
		else return false;
	}
}ie[100005];//input edge
int head[10005];
struct Edge {
	int v;
	long long w;
	int next;
}e[20005];
int ecnt = 0;
void AddEdge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int f[10005];
int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}
inline void uni(int u,int v) {
	f[find(u)] = find(v);
}
int up[10005][15];
long long lim[10005][15];
int dep[10005];
bool vis[10005];
void dfs(int u) {
	vis[u] = true;
	for (int i=1,len=1;len<=dep[u];i++,len<<=1) {
		up[u][i] = up[up[u][i-1]][i-1];
		lim[u][i] = min(lim[up[u][i-1]][i-1],lim[u][i-1]);
	}
	for (int i=head[u];i != -1;i=e[i].next) {
		int v = e[i].v;
		if (!vis[v]) {
			dep[v] = dep[u] + 1;
			up[v][0] = u;
			lim[v][0] = e[i].w;
			dfs(v);
		}
	}
}
int query(int u,int v) {
	if (dep[u] > dep[v]) swap(u,v);
	int diff = dep[v] - dep[u];
	long long MIN = INF;
	for (int i=0,bin=1;diff != 0;bin <<=1,i++) {
		if (diff & bin) {
			MIN = min(MIN,lim[v][i]);
			v = up[v][i];
			diff -= bin;
		}
	}
	for (int i=log(dep[u])/log(2);i>=0;i--) {
		if (up[u][i] != up[v][i]) {
			MIN = min(MIN,min(lim[u][i],lim[v][i]));
			u = up[u][i];
			v = up[v][i];
		}
	}
	if (u == v) return MIN;
	else return min(MIN,min(lim[u][0],lim[v][0]));
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for (int i=1;i<=n;i++) f[i] = i;
	for (int i=0;i<m;i++) {
		scanf("%d%d%d",&ie[i].u,&ie[i].v,&ie[i].w);
	}
	sort(ie,ie+m);
	for (int i=0;i<m;i++) {
		if (find(ie[i].u) != find(ie[i].v)) {
			AddEdge(ie[i].u,ie[i].v,ie[i].w);
			AddEdge(ie[i].v,ie[i].u,ie[i].w);
			uni(ie[i].u,ie[i].v);
		}
		if (ecnt / 2 == n - 1) break;
	}
	for (int i=1;i<=n;i++) if (!vis[i]) dfs(i);
	int q;
	scanf("%d",&q);
	while (q--) {
		int u,v;
		scanf("%d%d",&u,&v);
		if (find(u) != find(v)) printf("-1\n");
		else printf("%d\n",query(u,v));
	}
	return 0;
}
