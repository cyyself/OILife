#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int> > e;
bool vis[300005];
int deg[300005];
int n,m;
bool work1() {
	vector <int> ans;
	for (int i=0;i<e.size() && ans.size() < n;i++) {
		auto x = e[i];
		if (!vis[x.first] && !vis[x.second]) {
			vis[x.first] = vis[x.second] = true;
			ans.push_back(i+1);
		}
	}
	if (ans.size() == n) {
		printf("Matching\n");
		for (auto x:ans) printf("%d ",x);
		printf("\n");
		return true;
	}
	return false;
}
bool work2() {
	vector <int> ans;
	for (int i=1;i<=3*n && ans.size() < n;i++) if (!vis[i]) ans.push_back(i);
	if (ans.size() == n) {
		printf("IndSet\n");
		for (auto x:ans) printf("%d ",x);
		printf("\n");
		return true;
	}
	return false;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		e.clear();
		scanf("%d%d",&n,&m);
		for (int i=1;i<=3*n;i++) {
			vis[i] = false;
		}
		for (int i=0;i<m;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			deg[u] ++;
			deg[v] ++;
			e.push_back({u,v});
		}
		if (!work1() && !work2()) printf("Impossible\n");
	}
	return 0;
}
