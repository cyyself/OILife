#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge {
	int u,v,f,c;
	int next;
}e[30005];
int head[1005];
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
int pre[1005];
int dis[1005];
bool inq[1005];
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
/*
编号规则：
	源点：	0
	每个x：	1~n
	每个y：	n+(1~n)
	汇点：	2n+1
*/
int main() {
	int n,k;
	while (scanf("%d%d",&n,&k) == 2) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=1;i<=n;i++) {
			AddEdge(0,i,1,0);
			AddEdge(n+i,n*2+1,1,0);
		}
		for (int i=0;i<k;i++) {
			int r,c;
			scanf("%d%d",&r,&c);
			AddEdge(r,n+c,1,0);
		}
		int flow,cost;
		MCMF(0,n*2+1,flow,cost);
		printf("%d\n",flow);
	}
	return 0;
}
