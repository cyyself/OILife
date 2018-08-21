#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct p {
	int u;
	int dis;
	friend bool operator < (const p &a,const p &b) {
		return a.dis > b.dis;
	}
	p (int _u,int _dis) {
		u = _u;
		dis = _dis;
	}
};
struct edge {
	int v,w;
	int next;
}e[2005];
int head[205];
int ecnt;
void AddEdge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int dis[205];
void getdis(int s) {
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	priority_queue <p> q;
	q.push(p(s,0));
	while (!q.empty()) {
		p cur = q.top();
		q.pop();
		int u = cur.u;
		if (cur.dis > dis[u]) continue;
		for (int i=head[u];i != -1;i=e[i].next) {
			int v = e[i].v;
			int w = e[i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push(p(v,dis[v]));
			}
		}
	}
}
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=0;i<m;i++) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			AddEdge(u,v,w);
			AddEdge(v,u,w);
		}
		int s,t;
		scanf("%d%d",&s,&t);
		getdis(s);
		if (dis[t] == INF) printf("-1\n");
		else printf("%d\n",dis[t]);
	}

	return 0;
}
