#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Edge {
	int u,v,f,c;
	int next;
}e[300];
int ecnt;
int head[50];
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
int dis[50];
int pre[50];
bool inq[50];
bool spfa(int s,int t) {
	memset(dis,0x3f,sizeof(dis));
	memset(inq,false,sizeof(inq));
	memset(pre,-1,sizeof(pre));
	dis[s] = 0;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i=head[u];i != -1;i=e[i].next) {
			int v = e[i].v;
			if (e[i].f > 0 && dis[u] + e[i].c < dis[v]) {
				dis[v] = dis[u] + e[i].c;
				pre[v] = i;
				if (!inq[v]) {
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}
	return dis[t] != INF;
}
void mcmf(int u,int v,int &f,int &c) {
	f = 0;
	c = 0;
	while (spfa(u,v)) {
		int curflow = INF;
		for (int i=pre[v];i != -1;i = pre[e[i].u]) curflow = min(e[i].f,curflow);
		for (int i=pre[v];i != -1;i = pre[e[i].u]) {
			e[ i ].f -= curflow;
			e[i^1].f += curflow;
		}
		f += curflow;
		c += curflow * dis[v];
	}
}
/*
编号规则：
	源点:0
	男生：1->n
	女生：n+1->n*2
	汇点：n*2+1
边数：2*n+n*n(源点->男生->女生->汇点)
*/
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int n;
		scanf("%d",&n);
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=1;i<=n;i++) AddEdge(0,i,1,0);//源点流向男生
		for (int j=1;j<=n;j++) AddEdge(n+j,n*2+1,1,0);//女生流向汇点
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				int t;
				scanf("%d",&t);
				AddEdge(i,n+j,1,-t);
			}
		}
		int f,cost;
		mcmf(0,n*2+1,f,cost);
		printf("Case %d: %d\n",c,-cost);
	}
	return 0;
}
