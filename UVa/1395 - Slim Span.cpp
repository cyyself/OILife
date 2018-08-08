#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge {
	int u,v,w;
	friend bool operator < (const edge &a,const edge &b) {
		return a.w > b.w;
	}
}e[5005];
int f[105];
int find(int x) {
	if (f[x] == x) return x;
	else {
		f[x] = find(f[x]);
		return f[x];
	}
}
void uni(int x,int y) {
	f[find(x)] = find(y);
}
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		if (n == 0 && m == 0) break;
		for (int i=0;i<m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		sort(e,e+m);
		int ans = INF;
		for (int i=0;i<m;i++) {
			for (int i=1;i<=n;i++) f[i] = i;
			int ans_min = INF;
			int ans_max = 0;
			int cnt = 0;
			for (int j=i;j<m;j++) {
				if (find(e[j].u) != find(e[j].v)) {
					uni(e[j].u,e[j].v);
					ans_min = min(ans_min,e[j].w);
					ans_max = max(ans_max,e[j].w);
					cnt ++;
					if (cnt == n - 1) break;
				}
			}
			if (cnt == n - 1) ans = min(ans,ans_max-ans_min);
		}
		if (ans != INF) printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}
