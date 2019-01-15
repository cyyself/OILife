#include <bits/stdc++.h>
using namespace std;
vector<pair <int,int> > in;
vector <int> g[105];
bool vis[105];//
bool dfs(int u,int dst) {
	vis[u] = true;
	for (int i=0;i<in.size();i++) {
		if (i == u) continue;
		if ((in[i].first < in[u].first && in[u].first < in[i].second) || (in[i].first < in[u].second && in[u].second < in[i].second)) {
			int v = i;
			if (v == dst) return true;
			if (!vis[v] && dfs(v,dst)) return true;
		}
	}
	return false;
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int type,l,r;
		scanf("%d%d%d",&type,&l,&r);
		if (type == 1) {
			int num = in.size();
			for (unsigned int i=0;i<num;i++) {
				auto x = in[i];
				if ((x.first < l && l < x.second) || ((x.first < r && r < x.second))) {
					g[i].push_back(num);
					g[num].push_back(i);
				}
			}
			in.push_back(make_pair(l,r));
		}
		else {
			memset(vis,false,sizeof(vis));
			if (dfs(l-1,r-1)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
