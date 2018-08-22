#include <bits/stdc++.h>
using namespace std;
vector <int> g[100005];
int suf[100005];
int n;
double t;
void dfs(int u) {
	if (g[u].size() == 0) suf[u] = 1;
	else {
		vector <int> cnt;
		for (auto v:g[u]) {
			dfs(v);
			cnt.push_back(suf[v]);
		}
		int need = ceil(g[u].size()*t);
		sort(cnt.begin(),cnt.end());
		for (int i=0;i<need;i++) suf[u] += cnt[i];
	}
}
int main() {
	while (scanf("%d%lf",&n,&t) == 2) {
		t /= 100.0;
		if (n == 0) break;
		memset(suf,0,sizeof(suf));
		for (int v=1;v<=n;v++) {
			int u;
			scanf("%d",&u);
			g[u].push_back(v);
		}
		dfs(0);
		printf("%d\n",suf[0]);
		for (int i=0;i<=n;i++) g[i].clear();
	}
	return 0;
}
