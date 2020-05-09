#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector <pair<int,int> > g[maxn];
int ans[maxn];
int main() {
	int n;
	scanf("%d",&n);
	memset(ans,-1,sizeof(ans));
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back({v,i});
		g[v].push_back({u,i});
	}
	int cur = 0;
	for (int i=1;i<=n;i++) if (g[i].size() >= 3) {
		for (int j=0;j<3;j++) ans[g[i][j].second] = j;
		cur = 3;
		break;
	}
	for (int i=1;i<n;i++) {
		if (ans[i] == -1) ans[i] = cur ++;
		printf("%d\n",ans[i]);
	}
	return 0;
}
