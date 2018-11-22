#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
struct edge {
	int v,w;
	int next;
}e[4005];
int head[1005];
int ecnt;
void addedge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
struct DATA {
	int u;
	int dis;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.dis > b.dis;
	}
};
int dis[1005];
void dijkstra(int s) {
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
			if (dis[u] + e[i].w < dis[v]) {
				dis[v] = dis[u] + e[i].w;
				q.push((DATA){v,dis[v]});
			}
		}
	}
}
int main() {
	int t,n;
	while (scanf("%d%d",&t,&n) == 2) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		while (t --) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		dijkstra(1);
		printf("%d\n",dis[n]);
	}
	return 0;
}
