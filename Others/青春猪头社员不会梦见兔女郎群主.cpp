#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int g[55][55];
struct edge {
	int u,v;
	int f,c;
	int next;
}e[40005];
int head[5005];
int ecnt;
void _add(int u,int v,int f,int c) {
	e[ecnt].u = u;
	e[ecnt].v = v;
	e[ecnt].f = f;
	e[ecnt].c = c;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
void add(int u,int v,int f,int c) {
	_add(u,v,f,c);
	_add(v,u,0,-c);
}
bool inq[5005];
int dis[5005];
int pre[5005];
bool spfa(int s,int t) {
	memset(inq,false,sizeof(inq));
	memset(dis,0x3f,sizeof(dis));
	memset(pre,-1,sizeof(pre));
	queue <int> q;
	q.push(s);
	dis[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			if (e[i].f > 0 && dis[u] + e[i].c < dis[v]) {
				dis[v] = dis[u] + e[i].c;
				pre[v] = i;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
	return dis[t] != INF;
}
void mcmf(int s,int t,int &f,int &c) {
	f = c = 0;
	while (spfa(s,t)) {
		int maxflow = INF;
		for (int i=pre[t];~i;i=pre[e[i].u]) maxflow = min(maxflow,e[i].f);
		for (int i=pre[t];~i;i=pre[e[i].u]) {
			e[ i ].f -= maxflow;
			e[i^1].f += maxflow;
		}
		f += maxflow;
		c += dis[t] * maxflow;
	}
}
/*
节点编号规则：
源点：0
拆点1：n*x+y+1
拆点2：2500+n*x+y+1
汇点：5001
边数：
一个节点出去两条边：2500*2
一个节点自身连接：2500*2
源点到起点1
总边数需求：40k可过
*/
int n;
int getnum1(int x,int y) {
	return x * n + y + 1;
}
int getnum2(int x,int y) {
	return 2500 + x * n + y + 1;
}
int main() {
	memset(head,-1,sizeof(head));
	ecnt = 0;
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%d",&g[i][j]);
	add(0,getnum1(0,0),m,0);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		//拆点自身连接
		add(getnum1(i,j),getnum2(i,j),1,-g[i][j]);//取女装
		add(getnum1(i,j),getnum2(i,j),m,0);//不取女装
		if (i < n - 1) add(getnum2(i,j),getnum1(i+1,j),m,0);//可以向下走
		if (j < n - 1) add(getnum2(i,j),getnum1(i,j+1),m,0);//可以向右走
	}
	add(getnum2(n-1,n-1),5001,m,0);
	int f,c;
	mcmf(0,5001,f,c);
	printf("%d\n",-c);
	return 0;
}
