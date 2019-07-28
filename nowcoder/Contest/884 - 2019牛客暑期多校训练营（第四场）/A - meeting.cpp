#include <bits/stdc++.h>
using namespace std;
const int ninf = 0x80000000;
pair <int,int> f[100005];
pair <int,int> MAX[100005][2];
bool exist[100005];
int ans[100005];
vector <int> g[100005];
void dfs(int u,int rt) {
	for (auto v:g[u]) {
		if (v == rt) continue;
		dfs(v,u);
		if (make_pair(f[v].first+1,v) > MAX[u][0]) {
			MAX[u][1] = MAX[u][0];
			MAX[u][0] = make_pair(f[v].first+1,v);
		}
		else if (make_pair(f[v].first+1,v) > MAX[u][1]) {
			MAX[u][1] = make_pair(f[v].first+1,v);
		}
		f[u] = max(f[u],make_pair(f[v].first+1,v));
	}	  
}
void dfs2(int up,int u,int rt) {
	ans[u] = max(up,f[u].first);
	for (auto v:g[u]) {
		if (v == rt) continue;
		dfs2(
			max(exist[u]?1:ninf,
				max(up+1,(MAX[u][0].second!=v?MAX[u][0].first:MAX[u][1].first)+1)
		),v,u);
	}
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(f,0x80,sizeof(f));
	memset(MAX,0x80,sizeof(MAX));
	while (k --) {
		int x;
		scanf("%d",&x);
		exist[x] = true;
		f[x] = make_pair(0,x);
		MAX[x][0] = f[x];
	}
	dfs(1,-1);
	dfs2(ninf,1,-1);
	int out = 0x7fffffff;
	for (int i=1;i<=n;i++) out = min(out,ans[i]);
	printf("%d\n",out);
	return 0;
}
