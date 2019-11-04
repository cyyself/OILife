#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10005;
int head[maxn];
struct Edge {
	int v,w;
	int next;
}e[maxn*3];
int ecnt;
void addedge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int n;
 
bool inq[maxn];
int dis[maxn];
int cnt[maxn];

bool spfa() {
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(inq,0,sizeof(inq));
	dis[0] = 0;
	queue <int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		cnt[u] ++;
		for (register int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			int w = e[i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (!inq[v]) {
					if (cnt[v] >= n) {
						return false;
					}
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
	return true;
}
int main() {
	while (scanf("%d",&n) == 1) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		for (int i=0;i<n;i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			addedge(a,b+1,-2);
		}
		for (int i=0;i<=10000;i++) {
			addedge(i,i+1,0);
			addedge(i+1,i,1);
		}
		spfa();
		printf("%d\n",-dis[10001]);
	}
	return 0;
}
