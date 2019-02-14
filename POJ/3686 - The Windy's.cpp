#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge {
	int u,v;
	int f,c;
	int next;
}e[255100];
int head[2552];
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
int dis[2552];
bool inq[2552];
int pre[2552];
bool spfa(int s,int t) {
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
		int curflow = INF;
		for (int i=pre[t];~i;i=pre[e[i].u]) curflow = min(curflow,e[i].f);
		for (int i=pre[t];~i;i=pre[e[i].u]) {
			e[ i ].f -= curflow;
			e[i^1].f += curflow;
		}
		f += curflow;
		c += curflow * dis[t];
	}
}
int w[50][50];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&w[i][j]);
		for (int i=0;i<n;i++) add(0,i+1,1,0);
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) for (int k=1;k<=n;k++) add(i+1,50+n*j+k,1,k*w[i][j]);
		for (int j=0;j<m;j++) for (int k=1;k<=n;k++) add(50+n*j+k,2551,1,0);
		int f,c;
		mcmf(0,2551,f,c);
		printf("%0.6f\n",(double)c/n);
	}
	return 0;
}
