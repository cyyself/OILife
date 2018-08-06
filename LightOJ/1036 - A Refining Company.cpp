#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0;
	int f = 1;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret;
}
int u[505][505];
int r[505][505];
int usum[505][505];
int rsum[505][505];
int f[505][505];//f[i][j]表示第i行的前j个格子向左移动
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		memset(usum,0,sizeof(usum));
		memset(rsum,0,sizeof(rsum));
		memset(f,0,sizeof(f));
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) u[i][j] = read();
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) r[i][j] = read();
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) usum[i][j] = usum[i][j-1] + u[i][j];
		for (int i=1;i<=n;i++) for (int j=m;j>=1;j--) rsum[i][j] = rsum[i][j+1] + r[i][j];
		int i = 1;
			for (int j=0;j<=m;j++) f[i][j] = usum[i][j]+rsum[i][j+1];
		for (int i=2;i<=n;i++)
			for (int j=0;j<=m;j++) {
				for (int k=0;k<=j;k++) f[i][j] = max(f[i][j],f[i-1][k] + usum[i][j] + rsum[i][j+1]);
			}
		int ans = 0;
		for (int j=0;j<=m;j++) ans = max(f[n][j],ans);
		printf("Case %d: %d\n",c,ans);
	}
	return 0;
}
