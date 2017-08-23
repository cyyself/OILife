#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 0x7f7f7f7f 
using std::queue;
using std::min;
struct Edge{
	int u,v;
	int c,f;
	int next;
}e[40025];
int head[1005];
int pre[1005];
int ecnt = 0;
int s,t;
void AddEdge(int u,int v,int f,int c) {
	e[ecnt].next = head[u];
	head[u] = ecnt;
	e[ecnt].u = u;
	e[ecnt].v = v;
	e[ecnt].c = c;
	e[ecnt].f = f;
	ecnt ++;
}
void Add(int u,int v,int f,int c) {
	AddEdge(u,v,f,c);
	AddEdge(v,u,0,-c);
}
int dis[1005];
bool inq[1005];
bool spfa() {
	queue <int> q;
	q.push(s);
	memset(dis,0x7f,sizeof(dis));
	memset(inq,0,sizeof(inq));
	memset(pre,-1,sizeof(pre));
	inq[s] = true;
	dis[s] = 0;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		inq[cur] = false;
		for (int i=head[cur];i != -1;i = e[i].next) {
			if (e[i].f!=0 && dis[e[i].v] > dis[cur] + e[i].c) {
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
void MICMAF(int &flow,int &cost) {
	flow = 0;
	cost = 0;
	while(spfa()) {
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
	memset(head,-1,sizeof(head));
	int n,m;
	scanf("%d%d",&n,&m);
	s = 0;
	t = n+1;
	for (int i=0;i<m;i++) {
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		Add(u,v,1,c);
		Add(v,u,1,c);
	}
	Add(0,1,2,0);
	Add(n,n+1,2,0);
	int f,c;
	MICMAF(f,c);
	printf("%d\n",c);
	return 0;
}
