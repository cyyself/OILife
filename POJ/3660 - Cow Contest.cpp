#include <cstdio>
#include <bitset>
using namespace std;
bitset <105> g1[105];
bitset <105> g2[105];
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		for (int i=1;i<=n;i++) {
			g1[i].reset();
			g2[i].reset();
		}
		for (int i=0;i<m;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			g1[u].set(v);
			g2[v].set(u);
		}
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++) {
					if (g1[i][k] && g1[k][j]) g1[i].set(j);
					if (g2[i][k] && g2[k][j]) g2[i].set(j);
				}
		int ans = 0;
		for (int i=n;i>=1;i--) 
			if (g1[i].count() + g2[i].count() == n-1) ans ++;
		printf("%d\n",ans);
	}
	return 0;
}
