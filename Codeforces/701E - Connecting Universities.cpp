#include <bits/stdc++.h>
using namespace std;
int cnt[200005];
bool vis[200005];
int n,k;
vector <int> g[200005];
long long ans;
void dfs(int u) {
	vis[u] = true;
	for (auto v:g[u]) {
		if (vis[v]) continue;
		dfs(v);
		cnt[u] += cnt[v];
	}
	ans += min(cnt[u],2*k-cnt[u]);
}
int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<2*k;i++) {
		int pos;
		scanf("%d",&pos);
		cnt[pos] ++;
	}
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
