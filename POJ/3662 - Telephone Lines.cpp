#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge {
	int v,w;
	int next;
}e[20005];
int head[1005];
int ecnt;
void add(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int n,p,k;
struct DATA {
	int u;
	int len;
	DATA (int _u,int _len) {
		u = _u;
		len = _len;
	}
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.len > b.len;
	}
};
int dis[1005];
bool check(int x) {
	memset(dis,0x3f,sizeof(dis));
	priority_queue <DATA> q;
	dis[1] = 0;
	q.push(DATA(1,0));
	while (!q.empty()) {
		DATA cur = q.top();
		q.pop();
		int u = cur.u;
		if (dis[u] < cur.len) continue;
		for (int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			int w = e[i].w <=x ? 0:1;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(DATA(v,dis[v]));
			}
		}
	}
	return dis[n] <= k;
}
int main() {
	while (scanf("%d%d%d",&n,&p,&k) == 3) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		int l = 0;
		int r = 0;
		for (int i=0;i<p;i++) {
			int a,b,l;
			scanf("%d%d%d",&a,&b,&l);
			r = max(r,l);
			add(a,b,l);
			add(b,a,l);
		}
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
