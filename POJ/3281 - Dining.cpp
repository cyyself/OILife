#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
int n,f,d;
const int s = 0;
const int t = 401;
int head[405];
int nexte[16005];
int to[16005];
int c[16005];
int ecnt = 0;
inline void AddEdge(int _from,int _to,int _cap) {
	//不含反向弧
	nexte[ecnt] = head[_from];
	head[_from] = ecnt;
	to[ecnt] = _to;
	c[ecnt] = _cap;
	ecnt ++;
}
inline void AddFlow(int _from,int _to,int _cap) {
	AddEdge(_from,_to,_cap);
	AddEdge(_to,_from,0);
	//debug {
	//printf("added:%d->%d\n",_from,_to);
	//debug }
}
/*
编号规则：
s:0
food从1..f
drink从101..100+d
连接f的牛从201..200+n
连接d的牛从301..300+n
t:401
*/
int dis[405];
bool bfs() {
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int en = head[cur];en != -1; en = nexte[en]) {
			int v = to[en];
			if (c[en] != 0 && dis[v] == INF) {
				dis[v] = dis[cur] + 1;
				q.push(v);
			}
		}
	}
	return dis[t] != INF;
}
int dfs(int u,int curflow) {
	if (u == t) return curflow;
	if (dis[u] >= dis[t]) return 0;
	for (int en = head[u]; en != -1;en = nexte[en]) {
		int v = to[en];
		int flow;
		if (c[en] != 0 && dis[v] == dis[u] + 1 && (flow = dfs(v,min(curflow,c[en])))) {
			c[en] -= flow;
			c[en ^ 1] += flow;
			return flow;
		}
	}
	return 0;
}
int dinic() {
	int ans = 0;
	int flow;
	while(bfs()) while(flow = dfs(s,INF)) ans += flow;
	return ans;
}
int main() {
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&f,&d);
	for (int i=1;i<=f;i++) AddFlow(0,i,1);
	for (int i=101;i<=100+d;i++) AddFlow(i,401,1);
	for (int i=201;i<=200+n;i++) {
		int fi,di;
		scanf("%d%d",&fi,&di);
		AddFlow(i,i+100,1);
		for (int j=0;j<fi;j++) {
			int _f;
			scanf("%d",&_f);
			AddFlow(_f,i,1);
		}
		for (int j=0;j<di;j++) {
			int _d;
			scanf("%d",&_d);
			AddFlow(i+100,_d+100,1);
		}
	}
	printf("%d\n",dinic());
	return 0;
}