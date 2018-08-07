#include <cstdio>
#include <algorithm>
using namespace std;
int f[20005];
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
		return a.w > b.w;
	}
}e[50005];
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		int n,m,r;
		scanf("%d%d%d",&n,&m,&r);
		for (int i=0;i<n+m;i++) f[i] = i;
		for (int i=0;i<r;i++) {
			int u,v,w;
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
			e[i].v += n;
		}
		sort(e,e+r);
		int ans = (n+m)*10000;
		int cnt = 0;
		for (int i=0;i<r;i++) {
			if (find(e[i].u) != find(e[i].v)) {
				uni(e[i].u,e[i].v);
				cnt ++;
				ans -= e[i].w;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
