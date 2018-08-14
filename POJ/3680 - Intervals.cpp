#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge {
	int u,v,f,c;
	int next;
}e[2005];
int head[405];
int ecnt;
void _AddEdge(int u,int v,int f,int c) {
	e[ecnt].u = u;
	e[ecnt].v = v;
	e[ecnt].f = f;
	e[ecnt].c = c;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
void AddEdge(int u,int v,int f,int c) {
	_AddEdge(u,v,f,c);
	_AddEdge(v,u,0,-c);
}
int pre[405];
int dis[405];
bool inq[405];
bool spfa(int s,int t) {
	memset(dis,0x3f,sizeof(dis));
	memset(pre,-1,sizeof(pre));
	memset(inq,false,sizeof(inq));
	queue <int> q;
	q.push(s);
	dis[s] = 0;
	inq[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i=head[u];i != -1;i = e[i].next) {
			if (e[i].f > 0 && dis[u] + e[i].c < dis[e[i].v]) {
				dis[e[i].v] = dis[u] + e[i].c;
				pre[e[i].v] = i;
				if (!inq[e[i].v]) {
					q.push(e[i].v);
					inq[e[i].v] = true;
				}
			}
		}
	}
	return dis[t] != INF;
}
void MCMF(int s,int t,int &f,int &c) {
	f = 0;
	c = 0;
	while (spfa(s,t)) {
		int curFlow = INF;
		for (int i=pre[t];i != -1;i = pre[e[i].u]) curFlow = min(curFlow,e[i].f);
		for (int i=pre[t];i != -1;i = pre[e[i].u]) {
			e[ i ].f -= curFlow;
			e[i^1].f += curFlow;
		}
		f += curFlow;
		c += curFlow * dis[t];
	}
}
struct interval {
	int a,b,w;
}inter[205];
int lsarr[405];
int lscnt;
/*
编号规则：
	源点：0
	离散后区间位置：1~lscnt
	汇点：lscnt + 1
*/
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		ecnt = 0;
		lscnt = 0;
		memset(head,-1,sizeof(head));
		int n,k;
		scanf("%d%d",&n,&k);
		for (int i=0;i<n;i++) {
			scanf("%d%d%d",&inter[i].a,&inter[i].b,&inter[i].w);
			lsarr[lscnt++] = inter[i].a;
			lsarr[lscnt++] = inter[i].b;
		}
		sort(lsarr,lsarr+lscnt);
		lscnt = unique(lsarr,lsarr+lscnt) - lsarr;
		AddEdge(0,1,k,0);
		for (int i=1;i<lscnt;i++) AddEdge(i,i+1,k,0);
		AddEdge(lscnt,lscnt+1,k,0);
		for (int i=0;i<n;i++) {
			int x = lower_bound(lsarr,lsarr+lscnt,inter[i].a) - lsarr;
			int y = lower_bound(lsarr,lsarr+lscnt,inter[i].b) - lsarr;
			AddEdge(x+1,y+1,1,-inter[i].w);
		}
		int flow,cost;
		MCMF(0,lscnt+1,flow,cost);
		printf("%d\n",-cost);
	}
	return 0;
}
