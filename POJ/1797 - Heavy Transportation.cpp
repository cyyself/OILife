#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge {
	int u,v,w;
	friend bool operator < (const edge &a,const edge &b) {
		return a.w > b.w;
	}
}e[100005];
int f[1005];
int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) f[i] = i;
		for (int i=0;i<m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		sort(e,e+m);
		int ans = 0;
		for (int i=0;i<m && find(1) != find(n);i++) {
			f[find(e[i].u)] = find(e[i].v);
			ans = e[i].w;
		}
		printf("Scenario #%d:\n%d\n\n",c,ans);
	}
	return 0;
}
