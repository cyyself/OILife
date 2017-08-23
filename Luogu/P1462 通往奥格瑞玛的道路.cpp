#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Edge {
	int to;
	long long w;
	Edge(int _to,long long _weight):to(_to),w(_weight){}
};
vector <Edge> g[10005];
int n,m,b;
long long tip[10005];
bool check(long long maxtip) {
	bool vis[10005] = {0};
	bool disable[10005] = {0};
	long long dis[10005];
	memset(dis,0x7f,sizeof(dis));
	dis[1] = 0;
	for (int i=1;i<=n;i++) if (tip[i] > maxtip) disable[i] = true;
	queue <int> q;
	q.push(1);
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		vis[curr] = false;
		for (int i=0;i<g[curr].size();i++) {
			Edge e = g[curr][i];
			if (disable[e.to]) continue;
			if (dis[curr] + e.w < dis[e.to]) {
				dis[e.to] = dis[curr] + e.w;
				if (!vis[e.to]) {
					vis[e.to] = true;
					q.push(e.to);
				}
			}
		}
	}
	if (dis[n] < b) return true;
	else return false;
}
int main() {
	scanf("%d%d%d",&n,&m,&b);
	long long maxtip = 0;
	for (int i=1;i<=n;i++) {
		scanf("%lld",&tip[i]);
		maxtip = max(maxtip,tip[i]);
	}
	for (int i=0;i<m;i++) {
		int u,v;
        long long w;
		scanf("%d%d%lld",&u,&v,&w);
		g[u].push_back(Edge(v,w));
		g[v].push_back(Edge(u,w));
	}
	int l = 0;
	int r = maxtip;
	int ans = -1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	if (ans == -1) printf("AFK\n");
	else printf("%d\n",ans);
	return 0;
}