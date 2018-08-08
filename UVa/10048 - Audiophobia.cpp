#include <bits/stdc++.h>
using namespace std;
int f[105][105];
int main() {
	int c,s,q;
	int casen = 1;
	while (scanf("%d%d%d",&c,&s,&q) == 3) {
		if (c == 0 && s == 0 && q == 0) break;
		memset(f,0x3f,sizeof(f));
		for (int i=1;i<=c;i++) f[i][i] = 0;
		while (s--) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			f[u][v] = min(f[u][v],w);
			f[v][u] = min(f[v][u],w);
		}
		for (int k=1;k<=c;k++)
			for (int i=1;i<=c;i++)
				for (int j=1;j<=c;j++) {
					f[i][j] = min(f[i][j],max(f[i][k],f[k][j]));
				}
		if (casen >= 2) printf("\n");
		printf("Case #%d\n",casen++);
		while (q--) {
			int u,v;
			scanf("%d%d",&u,&v);
			if (f[u][v] == 0x3f3f3f3f) printf("no path\n");
			else printf("%d\n",f[u][v]);
		}
	}
	return 0;
}
