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
}e[400005];//网络流的题目都要记得边数开两倍，因为还有反向弧
int head[5005];
int n,m,s,t;
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
inline int hashin(int x,int y) {
	return n * x + y + 1;
}
inline int hashout(int x,int y) {
	return n * m + n * x + y + 1;
}
//之前写成m*x交了半天一直无法AC
int main() {
	memset(head,-1,sizeof(head));
	scanf("%d%d",&m,&n);
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++) {
			int c;
			scanf("%d",&c);
			Add(hashin(i,j),hashout(i,j),1,-c);
			if ((i == 0 && j == 0) || (i == m - 1 && j == n - 1)) Add(hashin(i,j),hashout(i,j),2,-c);
			//注意第一个点和最后一个点拆点要特判，当然直接用第一个点的出点和最后一个点的入点作源点和汇点也行
		}
	s = 1;
	t = 2 * n * m;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++) {
			int out = hashout(i,j);
			if (i != m - 1) Add(out,hashin(i+1,j),1,0);
			if (j != n - 1) Add(out,hashin(i,j+1),1,0);
		}
	int f,c;
	MICMAF(f,c);
	printf("%d\n",-c);
	return 0;
}