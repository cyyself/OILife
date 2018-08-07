#include <cstdio>
#include <algorithm>
using namespace std;
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
struct edge {
	int u,v,w;
	friend bool operator < (const edge &a,const edge &b) {
		return a.w < b.w;
	}
}e[10005];
int ecnt;
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		ecnt = 0;
		for (int i=1;i<=n;i++) f[i] = i;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) {
				scanf("%d",&e[ecnt].w);
				e[ecnt].u = i;
				e[ecnt].v = j;
				ecnt ++;
			}
		sort(e,e+ecnt);
		int ans = 0;
		int cnt = 0;
		for (int i=0;i<ecnt;i++) {
			if (find(e[i].u) != find(e[i].v)) {
				uni(e[i].u,e[i].v);
				cnt ++;
				ans += e[i].w;
				if (cnt == n - 1) break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
