#include <bits/stdc++.h>
using namespace std;
int ls[200005],c[200005],cnt;//离散值与离散后的color
vector <int> g[200005];
int sz[200005],sum[200005];
long long ans;
long long cn2(long long n) {
	return (n * (n - 1LL)) / 2;
}
long long dfs(int u,int rt) {
	sz[u] = 1;
	int blk = 0;
	for (auto v:g[u]) {
		if (v == rt) continue;
		int pre = sum[c[u]];
		sz[u] += dfs(v,u);
		int delta = sum[c[u]] - pre;
		blk += sz[v] - delta;//去掉块内贡献
		ans += cn2(sz[v] - delta);
	}
	sum[c[u]] += blk + 1;
	return sz[u];
}
int main() {
	int cas = 1;
	int n;
	while (scanf("%d",&n) == 1) {
		cnt = 0;
		for (int i=1;i<=n;i++) {
			ls[i] = -1;
			g[i].clear();
		}
		for (int i=1;i<=n;i++) {
			int x;
			scanf("%d",&x);
			if (ls[x] == -1) ls[x] = cnt ++;
			c[i] = ls[x];
		}
		for (int i=0;i<cnt;i++) sum[i] = 0;
		for (int i=1;i<n;i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if (cnt == 1) {
			printf("Case #%d: %lld\n",cas++,cn2(n));
		}
		else {
			ans = 0;
			dfs(1,-1);
			for (int i=0;i<cnt;i++) ans += cn2(n-sum[i]);
			printf("Case #%d: %lld\n",cas++,cnt*cn2(n)-ans);
		}
	}
	return 0;
}
