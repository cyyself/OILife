#include <bits/stdc++.h>
using namespace std;
const int maxn = 100*100*11;
const int maxe = maxn * 5;
const int INF = 0x3f3f3f3f;
struct p {
	int u;
	int dis;
	friend bool operator < (const p &a,const p &b) {
		return a.dis > b.dis;
	}
	p(int _u,int _dis) {
		u = _u;
		dis = _dis;
	}
};
struct edge {
	int v,w;
	int next;
}e[maxe];
int head[maxn];
int ecnt;
void addedge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int dis[maxn];
void spfa(int s) {
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	priority_queue <p> q;
	q.push(p(s,0));
	while (!q.empty()) {
		p cur = q.top();
		q.pop();
		int u = cur.u;
		if (cur.dis > dis[u]) continue;
		for (int i=head[u];i != -1;i=e[i].next) {
			int v = e[i].v;
			int w = e[i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				q.push(p(v,dis[v]));
			}
		}
	}
}
int n;
int g[105][105];
int id(int x,int y,int z) {
	return x + y * n + z * n * n;
}
int main() {
	memset(head,-1,sizeof(head));
	ecnt = 0;
	int k,a,b,c;
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&c);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%d",&g[i][j]);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		for (int z=0;z<=k;z++) {
			if (z < k) {
				//直接走
				if (!g[i][j] || z == 0 ) {
					if (i + 1 < n) addedge(id(i,j,z),id(i+1,j,z+1),0);
					if (j + 1 < n) addedge(id(i,j,z),id(i,j+1,z+1),0);
					if (i - 1 >= 0)addedge(id(i,j,z),id(i-1,j,z+1),b);
					if (j - 1 >= 0)addedge(id(i,j,z),id(i,j-1,z+1),b);
				}
			}
			if (z != 0) {
				//加油
				addedge(id(i,j,z),id(i,j,0),a+c*(!g[i][j]));
			}
		}
	}
	spfa(id(0,0,0));
	int ans = INF;
	for (int z=0;z<=k;z++) ans = min(ans,dis[id(n-1,n-1,z)]);
	printf("%d\n",ans);
	return 0;
}
