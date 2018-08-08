#include <bits/stdc++.h>
using namespace std;
int f[105][105];
map <int,int> ls;
int read() {
	int n = 0;
	ls.clear();
	memset(f,0x3f,sizeof(f));
	int u,v;
	while (true) {
		scanf("%d%d",&u,&v);
		if (u == 0 || v == 0) break;
		if (ls[u] == 0) ls[u] = ++n;
		if (ls[v] == 0) ls[v] = ++n;
		f[ls[u]][ls[v]] = 1;
	}
	for (int i=1;i<=n;i++) f[i][i] = 0;
	return n;
}
int main() {
	int c = 1;
	while (true) {
		int n = read();
		if (n == 0) break;
		int num = n * (n - 1);
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++) {
					f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
				}
		double sum = 0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) sum += f[i][j];
		printf("Case %d: average length between pages = %0.3lf clicks\n",c++,sum/(n*(n-1)));
	}
	return 0;
}
