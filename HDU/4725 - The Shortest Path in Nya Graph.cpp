#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct edge {
	int v,w;
	int next;
}e[1000005];
int head[300005];
int ecnt;
void addedge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
void add(int u,int v,int w) {
	addedge(u,v,w);
	addedge(v,u,w);
}
struct node {
	int num;
	int layer;
	friend bool operator < (const node &a,const node &b) {
		return a.layer < b.layer;
	}
}l[100005];
struct layer {
	int val;
	vector <int> ch;
};
vector <layer> lay;
struct DATA {
	int u;
	long long dis;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.dis > b.dis;
	}
};
long long dis[300005];
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
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		int n,m,c;
		scanf("%d%d%d",&n,&m,&c);
		for (int i=0;i<n;i++) {
			scanf("%d",&l[i].layer);
			l[i].num = i + 1;
		}
		sort(l,l+n);
		layer tmp;
		tmp.val = l[0].layer;
		for (int i=0;i<n;i++) {
			if (l[i].layer != tmp.val) {
				lay.push_back(tmp);
				tmp.ch.clear();
				tmp.val = l[i].layer;
			}
			tmp.ch.push_back(l[i].num);
		}
		lay.push_back(tmp);

		for (unsigned int i=1;i<lay.size();i++) {
			if (lay[i].val == lay[i-1].val + 1) {
				for (auto x:lay[i-1].ch) {
					addedge(x,n+i*2-1,c);
					addedge(n+i*2,x,c);
				}
				for (auto x:lay[ i ].ch) {
					addedge(n+i*2-1,x,c);
					addedge(x,n+i*2,c);
				}
			}
		}

		while (m --) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w*2);
		}

		dijkstra(1);

		if (dis[n] == INF) printf("Case #%d: -1\n",cas);
		else printf("Case #%d: %lld\n",cas,dis[n]/2);

		lay.clear();
	}
	return 0;
}
