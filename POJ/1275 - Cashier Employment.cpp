#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 25;
const int maxe = 1000;
int head[maxn];
struct Edge {
	int v,w1,w2;
	int next;
}e[maxe];
int ecnt;
void addedge(int u,int v,int w1,int w2) {
	e[ecnt].v = v;
	e[ecnt].w1 = w1;
	e[ecnt].w2 = w2;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int n;
bool inq[maxn];
int dis[maxn];
int cnt[maxn];

bool spfa(int mid) {
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(inq,0,sizeof(inq));
	dis[24] = 0;
	queue <int> q;
	q.push(24);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		cnt[u] ++;
		for (register int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			int w = e[i].w1 + e[i].w2 * mid;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (!inq[v]) {
					if (cnt[v] >= maxn) {
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
	int T;
	scanf("%d",&T);
	while (T --) {
		int need[24];
		int cnt[24];
		memset(cnt,0,sizeof(cnt));
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=0;i<=23;i++) scanf("%d",&need[i]);
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			int t;
			scanf("%d",&t);
			cnt[t] ++;
		}
		for (int i=0;i<=23;i++) addedge(i==0?24:i-1,i,0,0);
		for (int i=0;i<=23;i++) addedge(i,i==0?24:i-1,cnt[i],0);
		addedge(24,23,0,-1);
		for (int i=0;i<=23;i++) {
			if (i >= 8) addedge(i-8,i,-need[i],0);
			else addedge(24-8+i,i,-need[i],1);
		}
		int ans = -1;
		int l = 0, r = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (spfa(mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (ans == -1) printf("No Solution\n");
		else printf("%d\n",ans);
	}
	return 0;
}
