#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int n;
int head[20005];
struct edge {
	int v;
	int next;
}e[40005];
int ecnt;
void AddEdge(int u,int v) {
	e[ecnt].v = v;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int suf[20005];
bool vis[20005];
int ans;
int ans_node;
void dfs(int u) {
	vis[u] = true;
	int subtree = 0;
	for (int i=head[u];i != -1;i=e[i].next) {
		int v = e[i].v;
		if (!vis[v]) {
			dfs(v);
			suf[u] += suf[v] + 1;
			subtree = max(subtree,suf[v] + 1);
		}
	}
	subtree = max(subtree,n-suf[u]-1);
	if (subtree < ans || (subtree == ans && u < ans_node) ) {
		ans_node = u;
		ans = subtree;
	}
}
int main() {
	int t;
	scanf("%d",&t);
	while (t --) {
		memset(head,-1,sizeof(head));
		memset(suf,0,sizeof(suf));
		memset(vis,false,sizeof(vis));
		ecnt = 0;
		scanf("%d",&n);
		for (int i=1;i<n;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			AddEdge(u,v);
			AddEdge(v,u);
		}
		ans = INF;
		dfs(1);
		printf("%d %d\n",ans_node,ans);
	}
	return 0;
}
