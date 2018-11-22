#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge {
	int v,w;
	int next;
}e[10005];
int head[105];
int grade[105];
int ecnt;
void addedge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int m,n;
int dis[105];
struct DATA {
	int u;
	int dis;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.dis > b.dis;
	}
};
void dijkstra(int s,int lower,int upper) {
	priority_queue <DATA> q;
	memset(dis,0x3f,sizeof(dis));
	q.push((DATA){s,0});
	dis[s] = 0;
	while (!q.empty()) {
		DATA cur = q.top();
		q.pop();
		int u = cur.u;
		if (cur.dis > dis[u]) continue;
		for (int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			if (grade[v] < lower || grade[v] > upper) continue;
			if (dis[u] + e[i].w < dis[v]) {
				dis[v] = dis[u] + e[i].w;
				q.push((DATA){v,dis[v]});
			}
		}
	}
}
int main() {
	while (scanf("%d%d",&m,&n) == 2) {
		memset(head,-1,sizeof(head));
		ecnt = 0;

		for (int s=1;s<=n;s++) {
			int p,x;
			scanf("%d%d%d",&p,&grade[s],&x);
			addedge(0,s,p);
			while (x --) {
				int t,x;
				scanf("%d%d",&t,&x);
				addedge(t,s,x);
			}
		}

		int ans = INF;

		int ls[105];
		for (int i=0;i<n;i++) ls[i] = grade[i+1];
		sort(ls,ls+n);
		int cnt = unique(ls,ls+n) - ls;
		for (int i=0;i<cnt;i++) {
			if (ls[i] <= grade[1] && ls[i] + m >= grade[1]) {
				dijkstra(0,ls[i],ls[i] + m);
				ans = min(ans,dis[1]);
			}
		}

		printf("%d\n",ans);
	}
	return 0;
}
