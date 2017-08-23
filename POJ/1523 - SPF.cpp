#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
int head[1005];
int next[1000005];
int to[1000005];
int dfn[1005];
int low[1005];
int subnet[1005];
int edgecnt = 0;
int dfscnt = 0;
int n,m;
void addedge(int u,int v) {
	edgecnt ++;
	next[edgecnt] = head[u];
	head[u] = edgecnt;
	to[edgecnt] = v;
}
void tarjan(int u,int r) {
	int son = 0;
	dfn[u] = low[u] = ++dfscnt;
	for (int edge=head[u];edge!=0;edge=next[edge]) {
		int v = to[edge];
		if (!dfn[v]) {
			tarjan(v,r);
			low[u]=min(low[u],low[v]);
            son ++;
			if ( (low[v] >= dfn[u] && u != r) || (u == r && son >= 2) ) subnet[u] ++;
		}
		low[u] = min(low[u],dfn[v]);
	}
}
int main() {
	int network = 0;
	while (true) {
		network ++;
		dfscnt = 0;
		edgecnt = 0;
		memset(head,0,sizeof(head));
		memset(subnet,0,sizeof(subnet));
		memset(low,0,sizeof(subnet));
		memset(dfn,0,sizeof(subnet));
		int u,v;
		while (scanf("%d",&u) == 1 && u) {
			scanf("%d",&v);
			addedge(u,v);
			addedge(v,u);
		}
		if (edgecnt == 0) break;
		for (int i=1;i<=1000;i++) if (!dfn[i]) tarjan(i,i);
		printf("Network #%d\n",network);
		bool existspf = false;
		for (int i=1;i<=1000;i++) if (subnet[i]) {
			printf("  SPF node %d leaves %d subnets\n",i,subnet[i]+1);
			existspf = true;
		}
		if (!existspf) printf("  No SPF nodes\n");
		printf("\n");
	}
	return 0;
}