#include <bits/stdc++.h>
using namespace std;
struct hole {//其实也用来存那两只虫子了
	double x,y,z;
	double r;
}h[105];
double getdis(int i,int j) {
	double dx = h[i].x - h[j].x;
	double dy = h[i].y - h[j].y;
	double dz = h[i].z - h[j].z;
	double dis = sqrt(dx*dx + dy*dy + dz*dz) - h[i].r - h[j].r;
	if (dis < 0) return 0;
	return dis;
}
struct edge {
	int v;
	double w;
};
vector <edge> g[105];
/*
编号规则：
	0：Amelia
	1->n：洞
	n+1：另一只mite
*/
int n;
double dis[105];
bool inq[105];
void spfa(int s) {
	for (int i=0;i<=n+1;i++) dis[i] = 1e8;
	memset(inq,false,sizeof(inq));
	queue <int> q;
	q.push(s);
	inq[s] = true;
	dis[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (auto e:g[u]) {
			if (dis[u] + e.w < dis[e.v]) {
				dis[e.v] = dis[u] + e.w;
				if (!inq[e.v]) {
					q.push(e.v);
					inq[e.v] = true;
				}
			}
		}
	}
}
int main() {
	int c = 1;
	while (scanf("%d",&n) == 1 && ~n) {
		for (int i=0;i<=n+1;i++) g[i].clear();
		for (int i=1;i<=n;i++) scanf("%lf%lf%lf%lf",&h[i].x,&h[i].y,&h[i].z,&h[i].r);
		scanf("%lf%lf%lf",&h[0].x,&h[0].y,&h[0].z);
		h[0].r = 0;
		scanf("%lf%lf%lf",&h[n+1].x,&h[n+1].y,&h[n+1].z);
		h[n+1].r = 0;
		for (int i=0;i<=n+1;i++) 
			for (int j=0;j<i;j++) {
				g[i].push_back((edge){j,getdis(i,j)});
				g[j].push_back((edge){i,getdis(i,j)});
			}
		spfa(0);
		printf("Cheese %d: Travel time = %d sec\n",c++,int(dis[n+1]*10+0.5));
	}
	return 0;
}
