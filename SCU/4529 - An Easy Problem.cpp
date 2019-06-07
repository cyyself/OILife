#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> g1[1005];//缩点前的图
int low[1005],dfn[1005],rt[1005],ts,subg;
void tarjan(int u) {
	static stack <int> s;
	static bool ins[1005];
	dfn[u] = low[u] = ts++;
	s.push(u);
	ins[u] = true;
	for (auto v:g1[u]) {
		if (dfn[v] == -1) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if (ins[v]) low[u] = min(low[u],dfn[v]);
	}
	if (low[u] == dfn[u]) {
		subg ++;
		while (!s.empty()) {
			int cur = s.top();
			s.pop();
			ins[cur] = false;
			rt[cur] = subg;
			if (cur == u) break;
		}
	}
}

vector <int> g2[1005];//缩点后的图
int pre[1005];
bool vis[1005];
bool dfs(int u) {
	for (auto v:g2[u]) {
		if (!vis[v]) {
			vis[v] = true;
			if (pre[v] == -1 || dfs(pre[v])) {
				pre[v] = u;
				return true;
			}
		}
	}
	return false;
}
int match() {
	for (int i=1;i<=subg;i++) pre[i] = -1;
	int ans = 0;
	for (int i=1;i<=subg;i++) {
		for (int j=1;j<=subg;j++) vis[j] = false;
		if (dfs(i)) ans ++;
	}
	return ans;
}
set <pair<int,int> > exist;
void bfs(int s) {
	queue <int> q;
	q.push(s);
	static bool vis[1005];
	for (int i=1;i<=subg;i++) vis[i] = false;
	vis[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v:g2[u]) {
			if (!vis[v]) {
				q.push(v);
				vis[v] = true;
			}
			if (exist.find(make_pair(s,v)) == exist.end()) {
				g2[s].push_back(v);
				exist.insert(make_pair(s,v));
			}
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		ts = 0;
		subg = 0;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) {
			g1[i].clear();
			g2[i].clear();
			rt[i] = -1;
			dfn[i] = -1;
			low[i] = -1;
		}
		for (int i=0;i<m;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			g1[u].push_back(v);
		}
		for (int i=1;i<=n;i++) if (rt[i] == -1) tarjan(i);
		exist.clear();
		for (int u=1;u<=n;u++) {
			int x = rt[u];
			for (auto v:g1[u]) {
				int y = rt[v];
				if (x != y && exist.find(make_pair(x,y)) == exist.end()) {
					exist.insert(make_pair(x,y));
					g2[x].push_back(y);
				}
			}
		}
		for (int i=1;i<=subg;i++) bfs(i);
		printf("Case %d: %d\n",cas,subg-match());
	}
	return 0;
}
