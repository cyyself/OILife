#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
struct Edge{
	int to;
	long long w;
	Edge(int _to,long long _w):to(_to),w(_w){}
};
vector <Edge> g1[1000005];
vector <Edge> g2[1000005];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int u,v;
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		g1[u].push_back(Edge(v,w));
		g2[v].push_back(Edge(u,w));
	}
	long long ans = 0;
	bool vis[1000005];
	int dis[1000005];
	memset(vis,0,sizeof(vis));
	memset(dis,0x7f,sizeof(dis));
	dis[1] = 0;
	queue <int> q;
	q.push(1);
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		vis[curr] = false;
		for (int i=0;i<g1[curr].size();i++) {
			Edge e = g1[curr][i];
			if (dis[curr] + e.w < dis[e.to]) {
				dis[e.to] = dis[curr] + e.w;
				if (!vis[e.to]) {
					vis[e.to] = true;
					q.push(e.to);
				}
			}
		}
	}
	for (int i=2;i<=n;i++) ans += dis[i];
	memset(vis,0,sizeof(vis));
	memset(dis,0x7f,sizeof(dis));
	dis[1] = 0;
	q.push(1);
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		vis[curr] = false;
		for (int i=0;i<g2[curr].size();i++) {
			Edge e = g2[curr][i];
			if (dis[curr] + e.w < dis[e.to]) {
				dis[e.to] = dis[curr] + e.w;
				if (!vis[e.to]) {
					vis[e.to] = true;
					q.push(e.to);
				}
			}
		}
	}
	for (int i=2;i<=n;i++) ans += dis[i];
	printf("%lld",ans);
	return 0;
}