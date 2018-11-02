#include <bits/stdc++.h>
using namespace std;
bitset<105> f[105][105];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	while (m --) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		f[a][b].set(c);
		f[b][a].set(c);
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) f[i][j] |= f[i][k] & f[k][j];
	int q;
	scanf("%d",&q);
	while (q --) {
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%lu\n",f[u][v].count());
	}
	return 0;
}
