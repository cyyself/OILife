#include <bits/stdc++.h>
using namespace std;
struct Pos {
	int x,y;
	friend double operator - (Pos &a,Pos &b) {
		int dx = abs(a.x - b.x);
		int dy = abs(a.y - b.y);
		return dx + dy;
	}
	void read() {
		scanf("%d%d",&x,&y);
	}
}c1,c0,s[1005];
vector <int> hate[1005],love[1005];
vector <int> g[2005];
int n;
bool vis[2005];
int dfn[2005],low[2005],root[2005];
int rootcnt;
int timestamp;
stack <int> st;
void tarjan(int u) {
	dfn[u] = low[u] = ++timestamp;
	vis[u] = true;
	st.push(u);
	for (auto v:g[u]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else {
			if (vis[v]) low[u] = min(low[u],dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		rootcnt ++;
		while (!st.empty()) {
			int v = st.top();
			st.pop();
			root[v] = rootcnt;
			vis[v] = false;
			if (v == u) break;
		}
	}
}
bool check(int x) {
	rootcnt = 0;
	timestamp = 0;
	for (int i=1;i<=2*n;i++) {
		g[i].clear();
		dfn[i] = 0;
	}
	for (int u=1;u<=n;u++) {
		for (auto v:hate[u]) {
			g[u].push_back(n+v);
			g[n+u].push_back(v);
			g[v].push_back(n+u);
			g[n+v].push_back(u);
		}
		for (auto v:love[u]) {
			g[u].push_back(v);
			g[n+u].push_back(n+v);
			g[v].push_back(u);
			g[n+v].push_back(n+u);
		}
	}
	for (int u=1;u<=n;u++) {
		int u0 = c0 - s[u];
		int u1 = c1 - s[u];
		for (int v=1;v<u;v++) {
			int v0 = c0 - s[v];
			int v1 = c1 - s[v];
			if (u0 + v0 > x) {
				g[u+n].push_back(v);
				g[v+n].push_back(u);
			}
			if (u1 + v1 > x) {
				g[u].push_back(n+v);
				g[v].push_back(n+u);
			}
			if (u0 + v1 + (c1 - c0) > x) {
				g[u+n].push_back(v+n);
				g[v].push_back(u);
			}
			if (u1 + v0 + (c1 - c0) > x) {
				g[u].push_back(v);
				g[v+n].push_back(u+n);
			}
		}
	}
	for (int i=1;i<=2*n;i++) if (!dfn[i]) tarjan(i);
	for (int i=1;i<=n;i++) if (root[i] == root[i+n]) return false;
	return true;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int A,B;
		scanf("%d%d%d",&n,&A,&B);
		c1.read();
		c0.read();
		for (int i=1;i<=n;i++) {
			hate[i].clear();
			love[i].clear();
			s[i].read();
		}
		for (int i=0;i<A;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			hate[u].push_back(v);
		}
		for (int i=0;i<B;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			love[u].push_back(v);
		}
		int ans = -1;
		int l = 0;
		int r = 1e7;
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
