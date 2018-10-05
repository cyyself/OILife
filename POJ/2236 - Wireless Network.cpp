#include <cstdio>
#include <utility>
using namespace std;
pair <int,int> pos[1005];
int f[1005];
bool ok[1005];
int find(int x) {
	return f[x] == x ? x : f[x]=find(f[x]);
}
void uni(int x,int y) {
	f[find(x)] = find(y);
}
int getdis(int u,int v) {
	int dx = pos[u].first  - pos[v].first;
	int dy = pos[u].second - pos[v].second;
	return dx*dx + dy*dy;
}
int main() {
	int n,d;
	scanf("%d%d",&n,&d);
	for (int i=1;i<=n;i++) f[i] = i;
	for (int i=1;i<=n;i++) scanf("%d%d",&pos[i].first,&pos[i].second);
	char o;
	while (scanf(" %c",&o) == 1) {
		if (o == 'O') {
			int p;
			scanf("%d",&p);
			ok[p] = true;
			for (int i=1;i<=n;i++) if (i != p && ok[i] && getdis(i,p) <= d*d) uni(i,p);
		}
		else {
			int p,q;
			scanf("%d%d",&p,&q);
			if (find(p) == find(q)) printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
	return 0;
}
