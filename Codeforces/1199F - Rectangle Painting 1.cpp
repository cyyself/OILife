#include <bits/stdc++.h>
using namespace std;
int f[50][50][50][50];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		char c;
		scanf(" %c",&c);
		f[i][j][i][j] = (c == '#');
	}
	for (int h=1;h<=n;h++) for (int w=1;w<=n;w++) if (h + w != 2) {
		for (int u=0;u+h-1<n;u++) for (int l=0;l+w-1<n;l++) {
			int d = u + h - 1;
			int r = l + w - 1;
			f[u][l][d][r] = max(h,w);
			if (h > 1) for (int i=u;i<d;i++) f[u][l][d][r] = min(f[u][l][d][r],f[u][l][i][r]+f[i+1][l][d][r]);
			if (w > 1) for (int i=l;i<r;i++) f[u][l][d][r] = min(f[u][l][d][r],f[u][l][d][i]+f[u][i+1][d][r]);
		}
	}
	printf("%d\n",f[0][0][n-1][n-1]);
	return 0;
}
