#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int v,w;
	int next;
}e[20005];
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
int ecnt;
int head[105];
void AddEdge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int dis[105];
void getdis(int s) {
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	priority_queue <p> q;
	q.push(p(s,dis[s]));
	while (!q.empty()) {
		p cur = q.top();
		q.pop();
		int u = cur.u;
		if (dis[u] < cur.dis) continue;
		for (int i=head[u];i != -1;i=e[i].next) {
			int v = e[i].v;
			int w = e[i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(p(v,dis[v]));
			}
		}
	}
}
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		if (n == 0 && m == 0) break;
		memset(head,-1,sizeof(head));
		ecnt = 0;
		while (m --) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			AddEdge(u,v,w);
			AddEdge(v,u,w);
		}
		getdis(1);
		printf("%d\n",dis[n]);
	}

	return 0;
}
