#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Edge{
	int u;
	int v;
	int f;
	int c;
	int next;
}e[40005];
int head[10001];
int pre[10001];
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

int dis[10001];
bool inq[10001];
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
void mcmf(int s,int t,int &flow,int &cost) {
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
int n;
int getnum(int x,int y) {
	return x * n + y + 1;
}
int main() {
	memset(head,-1,sizeof(head));
	int k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		int v;
		scanf("%d",&v);
		add(getnum(i,j),5000+getnum(i,j),1,-v);
		add(getnum(i,j),5000+getnum(i,j),k-1,0);
		if (j < n - 1) add(5000+getnum(i,j),getnum(i,j+1),k,0);
		if (i < n - 1) add(5000+getnum(i,j),getnum(i+1,j),k,0);
	}
	add(0,getnum(0,0),k,0);
	int f,c;
	mcmf(0,5000+getnum(n-1,n-1),f,c);
	printf("%d\n",-c);
	return 0;
}
