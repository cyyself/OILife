#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Edge {
	int v;
	int next;
}e[12005];
int head[6005];
int w[6005];
int ind[6005];
int ecnt;
void AddEdge(int u,int v) {
	e[ecnt].v = v;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int f[6005][2];
void dfs(int u) {
	f[u][1] = w[u];
	for (int i=head[u];i != -1;i=e[i].next) {
		int v = e[i].v;
		dfs(v);
		f[u][1] += f[v][0];
		f[u][0] += max(f[v][0],f[v][1]);
	}
}
int main() {
	memset(head,-1,sizeof(head));
	ecnt = 0;
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	int x,y;
	while (scanf("%d%d",&x,&y) == 2) {
		if (x*y == 0) break;
		AddEdge(y,x);
		ind[x] ++;
	}
	for (int i=1;i<=n;i++) if (ind[i] == 0) AddEdge(0,i);
	dfs(0);
	printf("%d\n",max(f[0][0],f[0][1]));
	return 0;
}
