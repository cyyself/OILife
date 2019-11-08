#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;
const int maxe = maxn * maxn;
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
struct DATA {
	int id,val;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.val < b.val;
	}
}a[1005];
int main() {
	int d;
	while (scanf("%d%d",&n,&d) == 2 && (n || d)) {
		for (int i=1;i<=n;i++) head[i] = -1;
		ecnt = 0;
		for (int i=1;i<=n;i++) {
			a[i].id = i;
			scanf("%d",&a[i].val);
		}
		sort(a+1,a+1+n);
		for (int i=1;i<n;i++) {
			if (a[i+1].id > a[i].id) addedge(a[i].id,a[i+1].id,d);
			else addedge(a[i+1].id,a[i].id,d);
		}
		for (int i=2;i<=n;i++) addedge(i,i-1,-1);
		if (a[1].id < a[n].id) {
			if (!spfa(a[1].id) || dis[a[n].id] == INF) printf("-1\n");
			else printf("%d\n",dis[a[n].id]);
		}
		else {
			if (!spfa(a[n].id) || dis[a[1].id] == INF) printf("-1\n");
			else printf("%d\n",dis[a[1].id]);
		}

	}
	return 0;
}
