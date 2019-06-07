#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int u,v,w;
	void read() {
		scanf("%d%d%d",&u,&v,&w);
	}
	friend bool operator < (const Edge &a,const Edge &b) {
		return a.w < b.w;
	}
}e[2000005];
int f[500005];
int find(int x) {
	return f[x] == x?x:f[x] = find(f[x]);
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;i++) e[i].read();
		sort(e,e+m);
		for (int i=1;i<=n;i++) f[i] = i;
		int ans = -1;
		for (int i=0;i<m;i++) {
			int x = find(e[i].u);
			int y = find(e[i].v);
			if (x == y) {
				ans = e[i].w;
				break;
			}
			else f[x] = y;
		}
		if (ans == -1) puts("No solution!");
		else printf("%d\n",ans);
	}
	return 0;
}
