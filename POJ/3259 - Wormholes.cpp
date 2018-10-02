#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct Edge {
	int v,w;
	int next;
}e[6005];
int head[505];
int ecnt;
void addedge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int n;
int dis[505];
bool inq[505];
int cnt[505];
bool spfa(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(inq,false,sizeof(inq));
	memset(cnt,0,sizeof(cnt));
	queue <int> q;
	q.push(s);
	dis[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		inq[u] = false;
		cnt[u] ++;
		if (cnt[u] > n) return false;
		q.pop();
		for (int i=head[u];i != -1;i=e[i].next) {
			int v = e[i].v;
			int w = e[i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
	return true;
}
int main() {
	int F;
	scanf("%d",&F);
	while (F --) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		int m,w;
		scanf("%d%d%d",&n,&m,&w);
		while (m --) {
			int u,v,t;
			scanf("%d%d%d",&u,&v,&t);
			addedge(u,v,t);
			addedge(v,u,t);
		}
		while (w --) {
			int u,v,t;
			scanf("%d%d%d",&u,&v,&t);
			addedge(u,v,-t);
		}
		if (spfa(1)) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
