#include <bits/stdc++.h>
using namespace std;
const int maxn = 2505;
struct Edge {
	int v,w;
	int next;
}e[10005];
int head[maxn],ecnt;
void add(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int cnt[maxn];
int dis[maxn];
bool inq[maxn];
int n,m,p;
vector <int> g2[maxn];
bool avail[maxn];
void bfs(int s) {
	queue <int> q;
	q.push(s);
	avail[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v:g2[u]) {
			if (!avail[v]) {
				q.push(v);
				avail[v] = true;
			}
		}
	}
}
bool spfa(int s) {
	memset(dis,0x3f,sizeof(int)*(n+1));
	memset(cnt,0,sizeof(int)*(n+1));
	queue <int> q;
	dis[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cnt[u] ++;
		if (cnt[u] > n) return false; 
		inq[u] = false;
		for (int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			if (!avail[v]) continue;
			if (dis[u] + e[i].w < dis[v]) {
				dis[v] = dis[u] + e[i].w;
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
	memset(head,-1,sizeof(head));
	ecnt = 0;
	scanf("%d%d%d",&n,&m,&p);
	for (int i=0;i<m;i++) {
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		add(u,v,-c+p);
		g2[v].push_back(u);
	}
	bfs(n);
	if (spfa(1)) printf("%d\n",max(-dis[n],0));
	else printf("-1\n");
	return 0;
}
