#include <bits/stdc++.h>
using namespace std;
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
int main() {
	while (scanf("%d",&n) == 1) {
		for (int i=1;i<=2*n;i++) {
			dfn[i] = 0;
			g[i].clear();
		}
		int m;
		scanf("%d",&m);
		for (int i=0;i<m;i++) {
			int a1,a2,c1,c2;
			scanf("%d%d%d%d",&a1,&a2,&c1,&c2);
			g[a1+n*c1].push_back(a2+n*(c2^1));
			g[a2+n*c2].push_back(a1+n*(c1^1));
		}
		for (int i=1;i<=2*n;i++) if (!dfn[i]) tarjan(i);
		bool ans = true;
		for (int i=1;i<=n;i++) if (root[i] == root[i+n]) {
			ans = false;
			break;
		}
		if (ans) puts("YES");
		else puts("NO");
	}
	return 0;
}
