#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 205;
const int MAXE = 105 * 105;
const int INF = 0x3f3f3f3f;
struct edge {
	int u,v;
	int f,c;
	int next;
}e[MAXE*2];
int head[MAXN];
int ecnt;
inline void _add(int u,int v,int f,int c) {
	e[ecnt].u = u;
	e[ecnt].v = v;
	e[ecnt].f = f;
	e[ecnt].c = c;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
inline void add(int u,int v,int f,int c) {
	_add(u,v,f,c);
	_add(v,u,0,-c);
}
struct pos {
	int x,y;
}p[105],h[105];
int pcnt,hcnt;
int dis[205];
int pre[205];
bool inq[205];
bool spfa(int s,int t) {
	memset(dis,0x3f,sizeof(dis));
	memset(pre,-1,sizeof(pre));
	memset(inq,false,sizeof(inq));
	dis[s] = 0;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		inq[u] = false;
		q.pop();
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
		c += maxflow * dis[t];
	}
}
char s[105];
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2 && n && m) {
		memset(head,-1,sizeof(head));
		ecnt = pcnt = hcnt = 0;
		for (int i=0;i<n;i++) {
			scanf("%s",s);
			for (int j=0;j<m;j++) 
				if (s[j] == 'H') h[++hcnt] = (pos){i,j};
				else if (s[j] == 'm') p[++pcnt] = (pos){i,j};
		}
		for (int i=1;i<=pcnt;i++) add(0,i,1,0);
		for (int i=1;i<=hcnt;i++) add(100+i,201,1,0);
		for (int i=1;i<=pcnt;i++) {
			for (int j=1;j<=hcnt;j++) {
				int dx = abs(p[i].x - h[j].x);
				int dy = abs(p[i].y - h[j].y);
				add(i,100+j,1,dx + dy);
			}
		}
		int f,c;
		mcmf(0,201,f,c);
		printf("%d\n",c);
	}
	return 0;
}
