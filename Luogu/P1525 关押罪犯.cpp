#include <cstdio>
#include <algorithm>
using namespace std;
struct criminal {
	int u,v,w;
	friend bool operator < (const criminal &a,const criminal &b) {
		if (a.w > b.w) return true;
		else return false;
	}
}c[100005];
int n,m;
int f[50005];
int ct[50005];
inline int find(int x) {
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}
inline bool check(int a,int b) {
	if (find(a) == find(b)) return true;
	else return false;
}
inline void uni(int a,int b) {
	f[find(a)] = find(b);
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i] = i;
	for (int i=1;i<=m;i++) scanf("%d%d%d",&c[i].u,&c[i].v,&c[i].w);
	sort(c+1,c+m+1);
	bool found = false;
	for (int i=1;i<=m;i++) {
		if (check(c[i].u,c[i].v)) {
			printf("%d\n",c[i].w);
			found = true;
			break;
		}
		else {
			if (ct[c[i].u] == 0) ct[c[i].u] = c[i].v;
			else uni(ct[c[i].u],c[i].v);
			if (ct[c[i].v] == 0) ct[c[i].v] = c[i].u;
			else uni(ct[c[i].v],c[i].u);
		}
	}
	if (!found) printf("0\n");
	return 0;
}