#include <bits/stdc++.h>
using namespace std;
long long c[4001][4001];
int main() {
	c[0][0] = 1;
	for (int i=1;i<=4000;i++) {
		c[i][0] = 1;
		c[i][i] = 1;
		for (int j=1;j<i;j++) {
			c[i][j] = c[i-1][j-1] + c[i-1][j];
			if (c[i][j] >= 1000000007) c[i][j] -= 1000000007;
		}
	}
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		printf("%lld\n",(c[2*(n+m)][n+m]-(n-1<0?0:c[2*(n+m)][n-1])-(m-1<0?0:c[2*(n+m)][m-1])+2*1000000007LL)%1000000007);
	}
	return 0;
}