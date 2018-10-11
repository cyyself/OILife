#include <bits/stdc++.h>
using namespace std;
double f[1000][1002];
double p[1000];
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%lf",&p[i]);
	f[0][0] = 1 - p[0];
	f[0][1] = p[0];
	for (int i=1;i<n;i++) {
		for (int j=0;j<=m;j++) {
			f[i][j+1] += f[i-1][j] * p[i];
			f[i][j]   += f[i-1][j] * (1-p[i]);
		}
	}
	printf("%0.5lf\n",f[n-1][m]);
	return 0;
}
