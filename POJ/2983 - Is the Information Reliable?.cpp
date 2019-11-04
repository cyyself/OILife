#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;
const int maxe = 200005+maxn;
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
int main() {
	int m;
	while (scanf("%d%d",&n,&m) == 2) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=0;i<m;i++) {
			char opt;
			scanf(" %c",&opt);
			int a,b;
			scanf("%d%d",&a,&b);
			if (opt == 'P') {
				int x;
				scanf("%d",&x);
				addedge(b,a,-x);
				addedge(a,b,x);
			}
			else {
				addedge(b,a,-1);
			}
		}
		for (int i=1;i<=n;i++) addedge(0,i,0);
		if (spfa()) printf("Reliable\n");
		else printf("Unreliable\n");
	}
	return 0;
}
