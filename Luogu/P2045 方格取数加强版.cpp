#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x7f7f7f7f
using namespace std;

struct Edge{
	int u;//大多数算法在邻接表中并不需要这个，但费用流比较例外
	int v;
	int f;//残量 
	int c;//费用 
	int next;
}e[25005];//网络流的题目都要记得边数开两倍，因为还有反向弧
int head[5005];
int n,k,s,t;
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
inline void Add(int _u,int _v,int _f,int _c) {
	AddEdge(_u,_v,_f,_c);
	AddEdge(_v,_u,0,-_c);
}

int dis[5005];
bool inq[5005];
int pre[5005];
bool SPFA() {
	queue <int> q;
	q.push(s);
	memset(dis,0x7f,sizeof(dis));
	memset(inq,0,sizeof(inq));
	memset(pre,-1,sizeof(pre));
	inq[s] = true;
	dis[s] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		inq[cur] = false;
		for (int i = head[cur];i != -1;i = e[i].next) {
			if (e[i].f != 0 && dis[e[i].v] > dis[cur] + e[i].c) {
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
	while (SPFA()) {
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
/*
节点编号规则：
源点：0
矩阵节点(入)：n*x+y+1
矩阵节点(出)：n*n+n*x+y+1
汇点：2*n*n+1
*/
int g[55][55];
inline int hashin(int x,int y) {
	return n*x+y+1;
}
inline int hashout(int x,int y) {
	return n*n + n * x + y + 1;
}
int main() {
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&k);
	int x,y,v;
	for (int i=0;i<n;i++) 
		for (int j=0;j<n;j++) scanf("%d",&g[i][j]);
	s = 0;
	t = 2 * n * n + 1;
	Add(s,1,k,0);
	Add(2*n*n,t,k,0);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) {
			int in = hashin(i,j);
			int out = hashout(i,j);
			Add(in,out,k-1,0);//邻接表中后插入的先遍历，卡常，f=1是因为只可能再经过一次
			Add(in,out,1,-g[i][j]);
			if (i != n - 1) Add(out,hashin(i+1,j),k,0);
			if (j != n - 1) Add(out,hashin(i,j+1),k,0);
		}
	int f,c;
	MICMAF(f,c);
	printf("%d\n",-c);
	return 0;
}