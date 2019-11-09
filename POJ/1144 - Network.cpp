#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 10005;
const int maxe = 50005;
int head[maxn];
struct Edge {
	int v,next;
}e[maxe];
int ecnt;
void addedge(int u,int v) {
	//printf("(debug)%d %d\n",u,v);
	e[ecnt].v = v;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int dfn[maxn],low[maxn],ts;
bool cut[maxn];
void tarjan(int u,int r) {
	int rc = 0;
	dfn[u] = low[u] = ++ts;
	for (int i=head[u];~i;i=e[i].next) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v,r);
			low[u]=min(low[u],low[v]);
			if (low[v] >= dfn[u] && u != r) cut[u] = true;
			if (u == r) rc++;
		}
		low[u] = min(low[u],dfn[v]);
	}
	if (u == r && rc >= 2) cut[r] = true;
}
bool read(int &x) {
	x = 0;
	int f = 1;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) c = getchar();
	while (c >= '0' && c <= '9') {
		x *= 10;
		x += c - '0';
		c = getchar();
	}
	return c != '\n';
}
int main() {
	int n;
	while (read(n),n) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		ts = 0;
		for (int i=1;i<=n;i++) dfn[i] = low[i] = cut[i] = 0;
		int u;
		while (read(u),u) {
			while (true) {
				int v;
				bool b = read(v);
				addedge(u,v);
				addedge(v,u);
				if (!b) break;
			}
		}
		for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i,i);
		int ans = 0;
		for (int i=1;i<=n;i++) if (cut[i]) ans ++;
		printf("%d\n",ans);
	}
	return 0;
}
