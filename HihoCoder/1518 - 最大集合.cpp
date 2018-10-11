#include <bits/stdc++.h>
using namespace std;
int v[100005];
int c[100005];
int dfs(int x,int r) {
	if (x == r) return 0;
	if (c[x]) return c[x];
	return c[x] = dfs(v[x],r) + 1;
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&v[i]);
	int ans = 0;
	for (int i=1;i<=n;i++) {
		if (c[i] == 0) {
			c[i] = dfs(v[i],i) + 1;
			ans = max(ans,c[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
