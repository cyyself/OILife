#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int> > ans[105];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	for (i=1;i<=m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		ans[a].push_back({i,a});
		ans[b].push_back({i,b});
	}
	for (int j=1;j<=n;j++) if (ans[j].size() == 0) {
		ans[j].push_back({i,j});
		i ++;
	}
	for (int j=1;j<=n;j++) {
		printf("%lu\n",ans[j].size());
		for (auto x:ans[j]) printf("%d %d\n",x.first,x.second);
	}
	return 0;
} 
