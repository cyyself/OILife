#include <bits/stdc++.h>
using namespace std;
struct p {
	int u;
	double dis;
	friend bool operator < (const p &a,const p &b) {
		return a.dis < b.dis;//让dis大的排前面,pq是大根堆
	}
	p (int _u,int _dis) {
		u = _u;
		dis = _dis;
	}
};
double g[1005][1005];
double dis[1005];
int n;
void getdis(int s) {
	for (int i=1;i<=n;i++) dis[i] = 0;
	dis[s] = 1;
	priority_queue <p> q;
	q.push(p(s,1));
	while (!q.empty()) {
		p cur = q.top();
		q.pop();
		int u = cur.u;
		if (dis[u] < cur.dis) continue;
		for (int v=1;v<=n;v++) {
			if (v == u) continue;
			if (dis[u] * g[u][v] > dis[v]) {
				dis[v] = dis[u] * g[u][v];
				q.push(p(v,dis[v]));
			}
		}
	}
}
int main() {
	while (scanf("%d",&n) == 1) {
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) scanf("%lf",&g[i][j]);
		int q;
		scanf("%d",&q);
		while (q --) {
			int u,v;
			scanf("%d%d",&u,&v);
			getdis(u);
			if (dis[v] == 0) printf("What a pity!\n");
			else printf("%0.3lf\n",dis[v]);
		}
	}
	return 0;
}
