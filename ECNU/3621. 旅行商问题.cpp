#include <bits/stdc++.h>
using namespace std;
int f[10005];
inline int find(int x) {
	if (f[x] == x) return x;
	else {
		f[x] = find(f[x]);
		return f[x];
	}
}
inline void uni(int x,int y) {
	f[find(x)] = find(y);
}
struct Edge {
	int u,v,w;
	friend bool operator < (const Edge &a,const Edge &b){
		return a.w < b.w;
	}
}e[100005];
int c[10005];
int main() {
	int n,p;
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++) f[i] = i;
	int ans;
	for (int i=1;i<=n;i++) {
		scanf("%d",&c[i]);
		if (i == 1) ans = c[i];
		else ans = min(ans,c[i]);
	}
	for (int i=0;i<p;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i] = (Edge){u,v,c[u]+c[v]+w*2};
	}
	sort(e,e+p);
	int cnt = 0;
	for (int i=0;i<p;i++) {
		if (cnt == n-1) break;
		if (find(e[i].u) != find(e[i].v)) {
			cnt ++;
			uni(e[i].u,e[i].v);
			ans += e[i].w;
		}
	}
	printf("%d\n",ans);
	return 0;
}
