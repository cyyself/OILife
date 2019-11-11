#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 16*16+2;
const int maxe = maxn*maxn;
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
inline void _addedge(int _u,int _v,int _f,int _c) {
	e[ecnt].next = head[_u];
	head[_u] = ecnt;
	e[ecnt].u = _u;
	e[ecnt].v = _v;
	e[ecnt].f = _f;
	e[ecnt].c = _c;
	ecnt++;
}
inline void addedge(int _u,int _v,int _f,int _c) {
	_addedge(_u,_v,_f,_c);
	_addedge(_v,_u,0,-_c);
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
int main() {
	memset(head,-1,sizeof(head));
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%d%d",&n,&m);
	n ++;
	m ++;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m-1;j++) {
			int x;
			scanf("%d",&x);
			addedge(id(i,j),id(i,j+1),1,-x);
			addedge(id(i,j),id(i,j+1),INF,0);
		}
	}
	for (int j=0;j<m;j++) {
		for (int i=0;i<n-1;i++) {
			int x;
			scanf("%d",&x);
			addedge(id(i,j),id(i+1,j),1,-x);
			addedge(id(i,j),id(i+1,j),INF,0);
		}
	}
	for (int i=0;i<a;i++) {
		int k,x,y;
		scanf("%d%d%d",&k,&x,&y);
		addedge(n*m,id(x,y),k,0);
	}
	for (int i=0;i<b;i++) {
		int r,x,y;
		scanf("%d%d%d",&r,&x,&y);
		addedge(id(x,y),n*m+1,r,0);
	}
	int f,c;
	MICMAF(n*m,n*m+1,f,c);
	printf("%d\n",-c);
	return 0;
}
