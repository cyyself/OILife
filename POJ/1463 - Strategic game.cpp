#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Edge {
	int v;
	int next;
}e[2250005];
int head[1505];
int ecnt;
void AddEdge(int u,int v) {
	e[ecnt].v = v;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int read() {
	int f = 1;
	int ret = 0;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret * f;
}
int n;
int f[1505][2];//0:不放,1:放
bool vis[1505];
int cnt;
void dfs(int u) {
	f[u][1] = 1;
	for (int i=head[u];i != -1;i=e[i].next) {
		int v = e[i].v;
		if (!vis[v]) {
			vis[v] = true;
			dfs(v);
			f[u][1] += min(f[v][0],f[v][1]);
			f[u][0] += f[v][1];
		}
	}
}
int main() {
	while (scanf("%d",&n) == 1) {
		memset(vis,0,sizeof(vis));
		memset(head,-1,sizeof(head));
		memset(f,0,sizeof(f));
		ecnt = 0;
		for (int i=0;i<n;i++) {
			int u = read();
			int ch = read();
			while (ch --) {
				int v = read();
				AddEdge(u,v);
				AddEdge(v,u);
			}
		}
		vis[0] = true;
		dfs(0);
		printf("%d\n",min(f[0][0],f[0][1]));
	}
	return 0;
}
