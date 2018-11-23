#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct edge {
	int v;
	double r,c;
	int next;
}e[205];
int ecnt;
int head[105];
void addedge(int u,int v,double r,double c) {
	e[ecnt].v = v;
	e[ecnt].r = r;
	e[ecnt].c = c;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
double dis[105];
bool inq[105];
bool spfa(int s) {
	memset(inq,false,sizeof(inq));
	queue <int> q;
	q.push(s);
	inq[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			if (dis[u] > e[i].c && (dis[u] - e[i].c) * e[i].r > dis[v]) {
				dis[v] = (dis[u] - e[i].c) * e[i].r;
				if (v == s) return true;
				if (!inq[v]) {
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	return false;
}
int main() {
	int n,m,s;
	double v;
	while (scanf("%d%d%d%lf",&n,&m,&s,&v) == 4) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=0;i<m;i++) {
			int a,b;
			double r1,c1,r2,c2;
			scanf("%d%d%lf%lf%lf%lf",&a,&b,&r1,&c1,&r2,&c2);
			addedge(a,b,r1,c1);
			addedge(b,a,r2,c2);
		}
		memset(dis,0,sizeof(dis));
		dis[s] = v;
		if (spfa(s)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
