#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge {
	int u,v,f,c;
	int next;
}e[40605];
int head[402];
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
int pre[402];
int dis[402];
bool inq[402];
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
	源点：0
	食物：1~100
	奶牛左：101~200
	奶牛右：201~301
	（不拆点可能存在的一种情况是多个食物流向一头牛，然后再从多个饮料流出）
	饮料：301~400
	终点：401
流向：源点->食物->奶牛->饮料->终点
*/
int main() {
	memset(head,-1,sizeof(head));
	ecnt = 0;
	int n,f,d;
	scanf("%d%d%d",&n,&f,&d);
	for (int i=1;i<=f;i++) AddEdge(0,i,1,1);//源点流向食物
	for (int i=101;i<=100+n;i++) {
		int fi,di;
		scanf("%d%d",&fi,&di);
		while (fi --) {
			int tmp;
			scanf("%d",&tmp);
			AddEdge(tmp,i,1,1);//食物流向奶牛左
		}
		AddEdge(i,i+100,1,1);//奶牛左流向奶牛右
		while (di --) {
			int tmp;
			scanf("%d",&tmp);
			AddEdge(100+i,300+tmp,1,1);//奶牛右流向饮料
		}
	}
	for (int i=301;i<=300+d;i++) AddEdge(i,401,1,1);
	int flow,cost;
	MCMF(0,401,flow,cost);
	printf("%d\n",flow);
	return 0;
}
