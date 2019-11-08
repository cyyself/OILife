#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cassert>
const int maxn = 26*26;
const int maxe = 200000;
const double eps = 1e-5;
struct Edge {
	int v;
	double w;
	int next;
}e[maxe];
int ecnt;
int head[maxn];
void addedge(int u,int v,double w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
bool ins[maxn];
double dis[maxn];
bool vis[maxn];
double mid;
bool dfs(int u) {
	vis[u] = true;
	if (ins[u]) return false;
	ins[u] = true;
	for (int i=head[u];~i;i=e[i].next) {
		int v = e[i].v;
		double w = e[i].w - mid;
		if (dis[u] + w > dis[v]) {
			dis[v] = dis[u] + w;
			if (!dfs(v)) return false;
		}
	}
	ins[u] = false;
	return true;
}
bool spfa() {
	for (int i=0;i<maxn;i++) {
		dis[i] = 0;
		ins[i] = 0;
		vis[i] = 0;
	}
	for (int i=0;i<maxn;i++) {
		if (!dfs(i)) return true;
	}
	return false;
}
char buf[1005];
int main() {
	int n;
	while (scanf("%d",&n) == 1 && n) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=1;i<=n;i++) {
			scanf("%s",buf);
			int len = strlen(buf);
			if (len < 2) {
				assert(false);
				break;
			}
			addedge((buf[0]-'a') + (buf[1]-'a') * 26,(buf[len-2]-'a') + (buf[len-1]-'a') * 26,len);
		}
		double l = 0, r = 1000;
		bool ans = false;
		while (r - l > eps) {
			mid = (l + r) / 2;
			if (spfa()) {
				ans = true;
				l = mid;
			}
			else {
				r = mid;
			}
		}
		if (ans) printf("%0.2f\n",l+eps);
		else printf("No solution.\n");
	}
	return 0;
}
