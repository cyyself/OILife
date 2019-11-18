#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int v;
	long long w;
	int next;
}e[600005];
int head[100005];
int ecnt;
void addedge(int u,int v,long long w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
struct DATA {
	int u;
	long long dis;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.dis > b.dis;
	}
};
long long dis[100005];
priority_queue <DATA> q;
int n,m,k;
void dijkstra() {
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=k;i++) {
		dis[i] = 0;
		q.push({i,0});
	}
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		int u = cur.u;
		if (cur.dis > dis[u]) continue;
		for (int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			if (dis[u] + e[i].w < dis[v]) {
				dis[v] = dis[u] + e[i].w;
				q.push({v,dis[v]});
			}
		}
	}
}
struct edge {
	int u,v;
	long long w;
	friend bool operator < (const edge &a,const edge &b) {
		return a.w < b.w;
	}
}es[600005];
int f[100005];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
map <int,long long> g[100005];
namespace LCA {
	int vis[100005];
	int up[100005][25];
	int dep[100005];
	long long f[100005][25];//子树边的最小值
	void dfs(int u) {
		vis[u] = true;
		for (int i=1,len=1;len<=dep[u];i++,len <<= 1) {
			up[u][i] = up[up[u][i-1]][i-1];
			f[u][i] = max(f[up[u][i-1]][i-1],f[u][i-1]);
		}
		for (auto x:g[u]) {
			int v = x.first;
			long long w = x.second;
			if (vis[v]) continue;
			dep[v] = dep[u] + 1;
			up[v][0] = u;
			f[v][0] = w;
			dfs(v);
		}
	}
	int query(int u,int v) {
		//u <= v,v更深
		if (dep[u] > dep[v]) swap(u,v);
		int diff = dep[v] - dep[u];
		for (int i=0,two=1;diff != 0;two <<= 1,i++) {
			if (diff & two) {
				v = up[v][i];
				diff -= two;
			}
		}
		if (u == v) return u;
		for (int i=log(dep[u])/log(2);i>=0;i--) {
			if (up[u][i] != up[v][i]) {
				u = up[u][i];
				v = up[v][i];
			}
		}
		return up[u][0];
	}
	long long query_f(int u,int v) {
		long long ans = 0;
		if (dep[u] > dep[v]) swap(u,v);
		int diff = dep[v] - dep[u];
		for (int i=0,two=1;diff != 0;two <<= 1,i++) {
			if (diff & two) {
				ans = max(ans,f[v][i]);
				v = up[v][i];
				diff -= two;
			}
		}
		if (u == v) return ans;
		for (int i=log(dep[u])/log(2);i>=0;i--) {
			if (up[u][i] != up[v][i]) {
				ans = max(ans,max(f[u][i],f[v][i]));
				u = up[u][i];
				v = up[v][i];
			}
		}
		return max(ans,max(f[u][0],f[v][0]));
	}
};
int main() {
	int q;
	memset(head,-1,sizeof(head));
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for (int i=0;i<m;i++) {
		int u,v;
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	dijkstra();
	int ec = 0;
	for (int u=1;u<=n;u++) {
		for (int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			long long w = e[i].w;
			es[ec++] = {u,v,dis[u]+dis[v]+w};
		}
	}
	sort(es,es+ec);
	for (int u=1;u<=n;u++) f[u] = u;
	int cnt = 0;
	for (int i=0;i<ec && cnt < n;i++) {
		int u = es[i].u;
		int v = es[i].v;
		long long w = es[i].w;
		if (find(u) == find(v)) continue;
		g[u][v] = w;
		g[v][u] = w;
		cnt ++;
		f[find(u)] = find(v);
	}
	LCA::dfs(1);
	while (q --) {
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%lld\n",LCA::query_f(u,v));
	}
	return 0;
}
