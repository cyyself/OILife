#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1005;
const int maxe = 6005;
int dfn[maxn],low[maxn],rt[maxn],sz[maxn],ts,scc;
bool vis[maxn];
stack <int> s;
int head[maxn];
struct Edge {
	int v,next;
}e[maxe];
int ecnt;
void addedge(int u,int v) {
	e[ecnt].v = v;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++ts;
	vis[u] = true;
	s.push(u);
	for (int i=head[u];~i;i=e[i].next) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if (vis[v]) low[u] = min(low[u],dfn[v]);
	}
	if (dfn[u] == low[u]) {
		scc ++;
		while (!s.empty()) {
			int v = s.top();
			s.pop();
			rt[v] = scc;
			sz[scc] ++;
			vis[v] = false;
			if (v == u) break;
		}
	}
}
vector <int> g[maxn];
int ind[maxn];
bool topo() {
	queue <int> q;
	for (int i=1;i<=scc;i++) if (ind[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front();
		if (q.size() > 1) return false;
		q.pop();
		for (int i=0;i<g[u].size();i++) {
			int v = g[u][i];
			ind[v] --;
			if (ind[v] == 0) q.push(v);
		}
	}
	return true;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,m;
		scanf("%d%d",&n,&m);
		memset(head,-1,sizeof(head));
		ecnt = 0;
		ts = 0;
		scc = 0;
		for (int i=1;i<=n;i++) dfn[i] = low[i] = rt[i] = sz[i] = 0;
		for (int i=0;i<m;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
		if (scc == 1) printf("Yes\n");
		else {
			for (int i=1;i<=scc;i++) {
				g[i].clear();
				ind[i] = 0;
			}
			for (int u=1;u<=n;u++) {
				for (int i=head[u];~i;i=e[i].next) {
					int v = e[i].v;
					if (rt[u] != rt[v]) {
						g[rt[u]].push_back(rt[v]);
						ind[rt[v]] ++;
					}
				}
			}
			if (topo()) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
