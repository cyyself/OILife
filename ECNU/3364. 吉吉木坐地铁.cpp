#include <bits/stdc++.h>
using namespace std;
vector <int> g[100005];
int city[100005];
int city_len[100005];
int dis[100005];
int cnum;
void dfs(int head,int u,int pre,int path) {
	city[u] = cnum;
	dis[u] = path;
	for (auto v:g[u]) {
		if (v == pre) continue;
		if (v == head) {
			city_len[cnum] = path;
			continue;
		}
		dfs(head,v,u,path+1);
	}
}
int main() {
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=0;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i=1;i<=n;i++) {
		if (city[i] == 0) {
			cnum ++;
			dfs(i,i,0,0);
		}
	}
	while (q --) {
		int u,v;
		scanf("%d%d",&u,&v);
		if (city[u] == city[v]) {
			printf("%d\n",min(abs(dis[u]-dis[v]),city_len[city[u]]+1-abs(dis[u]-dis[v])));
		}
		else printf("-1\n");
	}
	return 0;
}
