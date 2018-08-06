#include <bits/stdc++.h>
using namespace std;
double f[505][505];//f[i][j]表示有i个红球j个蓝球
int main() {
	for (int i=0;i<=500;i++) f[0][i] = 1;
	for (int i=1;i<=500;i++)
		for (int j=2;j<=500;j++) f[i][j] = (double)i/(i+j) * f[i-1][j-1] + (double)j/(i+j) * f[i][j-2];
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int x,y;
		scanf("%d%d",&x,&y);
		printf("Case %d: %0.10lf\n",c,f[x][y]);
	}
	return 0;
}
