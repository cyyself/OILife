#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct Edge{
	int u;
	int v;
	int f;
	int c;
	int next;
}e[30005];
int head[128];
int pre[128];
int n,m;
int ecnt = 0;
inline void AddEdge(int _u,int _v,int _f,int _c) {
	e[ecnt].next = head[_u];
	head[_u] = ecnt;
	e[ecnt].u = _u;
	e[ecnt].v = _v;
	e[ecnt].f = _f;
	e[ecnt].c = _c;
	ecnt++;
}
inline void add(int _u,int _v,int _f,int _c) {
	AddEdge(_u,_v,_f,_c);
	AddEdge(_v,_u,0,-_c);
}

int dis[128];
bool inq[128];
bool SPFA(int s,int t) {
	queue <int> q;
	q.push(s);
	memset(dis,0x3f,sizeof(dis));
	memset(inq,0,sizeof(inq));
	memset(pre,-1,sizeof(pre));
	inq[s] = true;
	dis[s] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		inq[cur] = false;
		for (int i = head[cur];i != -1;i = e[i].next) {
			if (e[i].f > 0 && dis[e[i].v] > dis[cur] + e[i].c) {
				dis[e[i].v] = dis[cur] + e[i].c;
				pre[e[i].v] = i;
				if (!inq[e[i].v]) {
					inq[e[i].v] = true;
					q.push(e[i].v);
				}
			}
		}
	}
	return dis[t] != INF;
}
void MICMAF(int s,int t,int &flow,int &cost) {
	flow = 0;
	cost = 0;
	while (SPFA(s,t)) {
		int minF = INF;
		for (int i=pre[t];i != -1;i=pre[e[i].u]) minF = min(minF,e[i].f);
		flow += minF;
		for (int i=pre[t];i != -1;i=pre[e[i].u]) {
			e[i].f -= minF;
			e[i^1].f += minF;
		}
		cost += dis[t] * minF;
	}
}
int main() {
	int cas = 0;
	while (scanf("%d%d",&n,&m) == 2 && n) {
		ecnt = 0;
		memset(head,-1,sizeof(head));
		for (int i=0;i<m;i++) {
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			add(u+64,v,1,c);
		}
		add(0,64,2,0);
		for (int i=1;i<=n-2;i++) add(i,64+i,1,0);
		int f,c;
		MICMAF(0,n-1,f,c);
		if (f != 2) printf("Instance #%d: Not possible\n",++cas);
		else printf("Instance #%d: %d\n",++cas,c);
	}
	return 0;
}
