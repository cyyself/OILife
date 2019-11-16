//奶一波这个代码能AC
#include <bits/stdc++.h>
using namespace std;
int f[200005];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
int cnt[200005];
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i] = i;
	for (int i=0;i<m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		u = find(u);
		v = find(v);
		if (u > v) swap(u,v);
		f[u] = v;
	}
	int i = 1;
	int ans = 0;
	while (i <= n) {
		for (int j=i+1;j<find(i);j++) {
			int u = find(i);
			int v = find(j);
			if (u > v) swap(u,v);
			if (u != v) {
				f[u] = v;
				ans ++;
			}
		}
		i = find(i) + 1;
	}
	printf("%d\n",ans);
	return 0;
}
