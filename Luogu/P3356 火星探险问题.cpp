#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 35*35*2;
const int maxe = maxn * 8;
struct Edge{
	int u;
	int v;
	int f;
	int c;
	int next;
}e[maxe];
int head[maxn];
int pre[maxn];
int ecnt;
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
int dis[maxn];
bool inq[maxn];
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
int n,m;
int id(int x,int y) {
	return x * m + y;
}
vector <int> flows[40][40];//拆点之间的两点所连的边
int cnt[40][40];
void dfs(int h,int x,int y) {
	if (x == n - 1 && y == m - 1) return;
	if (cnt[x+1][y]) {
		printf("%d %d\n",h,0);
		cnt[x+1][y] --;
		dfs(h,x+1,y);
		return;
	}
	if (cnt[x][y+1]) {
		printf("%d %d\n",h,1);
		cnt[x][y+1] --;
		dfs(h,x,y+1);
		return;
	}
}
int main() {
	memset(head,-1,sizeof(head));
	int f;
	scanf("%d%d%d",&f,&m,&n);
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
		int x;
		scanf("%d",&x);
		if (x == 2) {
			Add(id(i,j),n*m+id(i,j),1,-1);
			flows[i][j].push_back(ecnt-1);
			Add(id(i,j),n*m+id(i,j),f-1,0);
			flows[i][j].push_back(ecnt-1);
		}
		else if (x == 0) {
			Add(id(i,j),n*m+id(i,j),f,0);
			flows[i][j].push_back(ecnt-1);
		}
		if (i < n - 1) Add(n*m+id(i,j),id(i+1,j),f,0);
		if (j < m - 1) Add(n*m+id(i,j),id(i,j+1),f,0);
	}
	int ff,cc;
	MICMAF(id(0,0),n*m+id(n-1,m-1),ff,cc);
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) 
		for (auto x:flows[i][j]) cnt[i][j] += e[x].f;
	/*
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) printf("%d\t",cnt[i][j]);
		printf("\n");
	}
	*/
	for (int i=1;i<=f;i++) dfs(i,0,0);
	return 0;
}
