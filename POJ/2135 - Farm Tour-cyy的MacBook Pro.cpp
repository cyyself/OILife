#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using std::queue;
using std::min;
const int INF = 0x7f7f7f7f;
struct Edge {
	int u,v;
	int f,c;
	int next;
} e[40050];
int head[1005];
int ecnt = 0;
int s,t;
inline void addedge(int u,int v,int f,int c) {
	e[ecnt].next = head[u];
	head[u] = ecnt;
	e[ecnt].u = u;
	e[ecnt].v = v;
	e[ecnt].f = f;
	e[ecnt].c = c;
	ecnt ++;
}
inline void add(int u,int v,int f,int c) {
	addedge(u,v,f,c);
	addedge(v,u,0,-c);
}
int pre[1005];
int dis[1005];
bool inq[1005];
inline bool spfa() {
	memset(pre,-1,sizeof(pre));
	memset(dis,0x7f,sizeof(dis));
	memset(inq,false,sizeof(inq));
	queue <int> q;
	q.push(s);
	dis[s] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		inq[cur] = false;
		for (int i=head[cur];i != -1;i = e[i].next) {
			if (e[i].f > 0 && dis[cur] + e[i].c < dis[e[i].v]) {
				dis[e[i].v] = dis[cur] + e[i].c;
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
void MICMAF(int &flow,int &cost) {
	flow = cost = 0;
	while (spfa()) {
		int minF = INF;
		for (int i=pre[t];i != -1;i=pre[e[i].u]) minF = min(minF,e[i].f);
		flow += minF;
		for (int i=pre[t];i != -1;i=pre[e[i].u]) {
			e[i].f -= minF;
			e[i^1].f += minF;
		}
		cost += minF * dis[t];
	}
}
int main() {
	memset(head,-1,sizeof(head));
	int n,m;
	scanf("%d%d",&n,&m);
	while (m--) {
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		add(u,v,1,c);
		add(v,u,1,c);
	}
	s = 0;
	t = n + 1;
	add(0,1,2,0);
	add(n,n+1,2,0);
	int f,c;
	MICMAF(f,c);
	printf("%d\n",c);
	return 0;
}
