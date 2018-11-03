#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge {
	int v;
	int next;
}e[205];
int ecnt;
int head[105];
void add(int u,int v) {
	e[ecnt].v = v;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int w[105];
int f[105][205][2];//f[u][i][stat] stat:0:不回到u 1:回到u
bool vis[105];
int n,k;
void debug() {

}
void dfs(int u) {
	for (int i=0;i<=k;i++) f[u][i][0] = f[u][i][1] = w[u];
	vis[u] = true;
	for (int ed=head[u];~ed;ed=e[ed].next) {
		int v = e[ed].v;
		if (vis[v]) continue;
		if (u == 1) {
			debug();
		}
		dfs(v);
		for (int i=k;i>=1;i--) {
			for (int j=1;j<=i;j++) {//用在下一层的花费
				f[u][i][0] = max(f[u][i][0],f[u][i-j][1]+f[v][j-1][0]);
				if (j >= 2) {
					f[u][i][1] = max(f[u][i][1],f[u][i-j][1]+f[v][j-2][1]);
					f[u][i][0] = max(f[u][i][0],f[u][i-j][0]+f[v][j-2][1]);
				}
			}
		}
	}
}
int main() {
	while (scanf("%d%d",&n,&k) == 2) {
		memset(head,-1,sizeof(head));
		memset(f,0,sizeof(f));
		memset(vis,false,sizeof(vis));
		ecnt = 0;
		for (int i=1;i<=n;i++) scanf("%d",&w[i]);
		for (int i=1;i<n;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(1);
		printf("%d\n",f[1][k][0]);
	}
	return 0;
}
