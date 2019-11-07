#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
//莫名其妙的题目，不给数据范围
const int maxn = 10005;
const int maxe = 100005;
int head[maxn];
struct Edge {
	int v,w;
	int next;
}e[maxe];
int ecnt;
void addedge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int n;
 
bool inq[maxn];
int dis[maxn];
int cnt[maxn];

bool spfa() {
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(inq,0,sizeof(inq));
	dis[0] = 0;
	queue <int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		cnt[u] ++;
		for (register int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			int w = e[i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (!inq[v]) {
					if (cnt[v] >= n) {
						return false;
					}
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
	return true;
}
int t[maxn];
int main() {
	int cas = 0;
	while (scanf("%d",&n) == 1 && n) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=1;i<=n;i++) {
			scanf("%d",&t[i]);
			addedge(0,i,0);
		}
		char buf[10];
		while (scanf("%s",buf) == 1) {
			if (buf[0] == '#') break;
			int u,v;
			scanf("%d%d",&u,&v);
			if (buf[0] == 'S') {
				if (buf[2] == 'S') {
					addedge(v,u,0);
				}
				else if (buf[2] == 'F') {
					addedge(v,u,-t[v]);
				}
				else assert(false);
			}
			else if (buf[0] == 'F') {
				if (buf[2] == 'S') {
					addedge(v,u,t[u]);
				}
				else if (buf[2] == 'F') {
					addedge(v,u,t[u]-t[v]);
				}
				else assert(false);
			}
			else assert(false);
		}
		printf("Case %d:\n",++cas);
		if (spfa()) {
			for (int i=1;i<=n;i++) printf("%d %d\n",i,-dis[i]);
		}
		else printf("impossible\n");
		printf("\n");
	}
	return 0;
}
