#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 105;
const int maxe = maxn*maxn;
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
int indeg[maxn];
int outdeg[maxn];
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		ts = 0;
		scc = 0;
		for (int i=1;i<=n;i++) dfn[i] = low[i] = rt[i] = sz[i] = 0;
		for (int u=1;u<=n;u++) {
			int v;
			while (scanf("%d",&v) == 1 && v) addedge(u,v);
		}
		for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
		for (int i=1;i<=scc;i++) indeg[i] = outdeg[i] = 0;
		for (int u=1;u<=n;u++) {
			for (int i=head[u];~i;i=e[i].next) {
				int v = e[i].v;
				if (rt[u] != rt[v]) {
					indeg[rt[v]] ++;
					outdeg[rt[u]] ++;
				}
			}
		}
		int ans1 = 0, ans2 = 0;
		for (int i=1;i<=scc;i++) if (indeg[i] == 0) ans1 ++;
		for (int i=1;i<=scc;i++) if (outdeg[i] == 0) ans2 ++;
		if (scc == 1) printf("1\n0\n");
		else printf("%d\n%d\n",ans1,max(ans1,ans2));
	}
	return 0;
}
