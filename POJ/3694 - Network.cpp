#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
const int maxe = 500005;
struct DATA {
	int v,next;
}e[maxe];
int ecnt;
int head[maxn];
void addedge(int u,int v) {
	e[ecnt].v = v;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int dfn[maxn],low[maxn],f[maxn];
int ts;
bool br[maxn];
int brcnt;
void tarjan(int u,int r) {
	dfn[u] = low[u] = ++ts;
	for (int i=head[u];~i;i=e[i].next) {
		int v = e[i].v;
		if (v == r) continue;
		if (!dfn[v]) {
			f[v] = u;
			tarjan(v,u);
			if (low[v] > dfn[u]) {
				br[v] = true;
				brcnt ++;
			}
			low[u] = min(low[u],low[v]);
		}
		else low[u] = min(low[u],dfn[v]);
	}
}
int main() {
	int n,m;
	int cas = 0;
	while (scanf("%d%d",&n,&m) == 2 && n) {
		memset(head,-1,sizeof(head));
		for (int i=1;i<=n;i++) dfn[i] = low[i] = br[i] = f[i] = 0;
		ts = 0;
		for (int i=0;i<m;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i,i);
		printf("Case %d:\n",++cas);
		int q;
		scanf("%d",&q);
		while (q --) {
			int u,v;
			scanf("%d%d",&u,&v);
			while (u != v) {
				if (dfn[u] > dfn[v]) {
					brcnt -= br[u];
					br[u] = false;
					u = f[u];
				}
				else {
					brcnt -= br[v];
					br[v] = false;
					v = f[v];
				}
			}
			printf("%d\n",brcnt);
		}
		printf("\n");
	}
	return 0;
}
