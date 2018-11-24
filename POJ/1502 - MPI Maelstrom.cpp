#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct edge {
	int v,w;
	int next;
}e[10005];
int head[105];
int ecnt;
void addedge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
struct DATA {
	int u;
	int dis;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.dis > b.dis;
	}
};
int dis[105];
void dijkstra(int s) {
	priority_queue <DATA> q;
	memset(dis,0x3f,sizeof(dis));
	q.push((DATA){s,0});
	dis[s] = 0;
	while (!q.empty()) {
		DATA cur = q.top();
		q.pop();
		int u = cur.u;
		if (cur.dis > dis[u]) continue;
		for (int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			if (dis[u] + e[i].w < dis[v]) {
				dis[v] = dis[u] + e[i].w;
				q.push((DATA){v,dis[v]});
			}
		}
	}
}
int read() {
	int ret = 0;
	int f = 1;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) {
		if (c == 'x') return -1;
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret * f;
}
int main() {
	memset(head,-1,sizeof(head));
	ecnt = 0;
	int n = read();
	for (int i=2;i<=n;i++) {
		for (int j=1;j<i;j++) {
			int t = read();
			if (t == -1) continue;
			addedge(i,j,t);
			addedge(j,i,t);
		}
	}
	dijkstra(1);
	int ans = 0;
	for (int i=2;i<=n;i++) ans = max(ans,dis[i]);
	printf("%d\n",ans);
	return 0;
}
