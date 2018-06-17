#include <bits/stdc++.h>
using namespace std;
int f[205][205];
int n,m;
int main() {
	while (scanf("%d%d",&n,&m) == 2) {
		memset(f,-1,sizeof(f));
		for (int i=1;i<=n;i++) f[i][i] = 0;
		while (m --) {
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			f[a][b] = max(f[a][b],v);
		}
		for (int k=1;k<=n;k++) 
			for (int i=1;i<=n;i++) {
				if (f[i][k] == -1) continue;
				for (int j=1;j<=n;j++) {
					if (f[k][j] == -1) continue;
					f[i][j] = max(f[i][k]+f[k][j],f[i][j]);
				}
			}
		
		int q;
		scanf("%d",&q);
		while (q --) {
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d\n",f[a][b]);
		}
	}
	return 0;
}
