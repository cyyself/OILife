#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;
const int maxe = 20005+maxn;
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

bool spfa(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(inq,0,sizeof(inq));
	dis[s] = 0;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		cnt[u] ++;
		for (int i=head[u];~i;i=e[i].next) {
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
int cal() {
	if (!spfa(1)) return -1;
	else {
		if (dis[n] == INF) return -2;
		else return dis[n];
	}
}
int main() {
	int T;
	scanf("%d",&T);
	int x,y;
	while (T --) {
		scanf("%d%d%d",&n,&x,&y);
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=0;i<x;i++) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			addedge(a,b,c);
		}
		for (int i=0;i<y;i++) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			addedge(b,a,-c);
		}
		int ans = cal();
		for (int i=1;i<=n;i++) addedge(0,i,0);
		if (!spfa(0)) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
