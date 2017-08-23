#include <cstdio>
#include <algorithm>
using namespace std;
struct Edge{
	int u,v,w;
}e[20005];
bool comp(Edge a,Edge b) {
	if (a.w < b.w) return true;
	return false;
}
int family[10005];
int find(int x) {
	int result = -1;
	if (family[x] == x) result = x;
	else {
		result = find(family[x]);
	}
	return result;
}
inline void uni(int x,int y) {
	family[find(x)] = find(y);
}
int main() {
	int n,m,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (int i=0;i<m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e,e+m,comp);
	for (int i=1;i<=n;i++) family[i] = i;
	int ans = -1;
	for (int i=0;i<m;i++) {
		ans = e[i].w;
		uni(e[i].u,e[i].v);
		if (find(s) == find(t)) break;
	}
	printf("%d\n",ans);
	return 0;
}