#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge {
	int u,v,f,c;
	int next;
}e[805];
int head[205];
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
int pre[205];
int dis[205];
bool inq[205];
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
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {//真的是多组数据
		memset(head,-1,sizeof(head));
		ecnt = 0;
		while (n --) {
			int u,v,f;
			scanf("%d%d%d",&u,&v,&f);
			AddEdge(u,v,f,1);
		}
		int flow,cost;
		MCMF(1,m,flow,cost);
		printf("%d\n",flow);
	}
	return 0;
}
