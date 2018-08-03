#include <bits/stdc++.h>
using namespace std;
int f[105][105];
int main() {
	int t;
	scanf("%d",&t);
	for (int c=1;c<=t;c++) {
		memset(f,0,sizeof(f));
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n*2-1;i++){
			if (i <= n) for (int j=1;j<=i;j++) scanf("%d",&f[i][j]);
			else for (int j=1;j<=2*n-i;j++) scanf("%d",&f[i][j]);
		}
		for (int i=2;i<=n*2-1;i++) {
			if (i <= n) {
				for (int j=1;j<=i;j++) f[i][j] += max(f[i-1][j],f[i-1][j-1]);
			}
			else {
				for (int j=1;j<=2*n-i;j++) f[i][j] += max(f[i-1][j],f[i-1][j+1]);
			}
		}
		printf("Case %d: %d\n",c,f[n*2-1][1]);
	}
	return 0;
}
