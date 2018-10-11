#include <bits/stdc++.h>
using namespace std;
long long g[255][255];
long long s[255][255];
int n,m;
long long k;
int find(int x1,int x2,int y) {
	long long base = - s[x2][y-1] + s[x1-1][y-1];
	int l = y - 1;
	int r = m;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (s[x2][mid] - s[x1-1][mid] + base <= k) l = mid;
		else r = mid - 1;
	}
	return l - y;
}
int main() {
	scanf("%d%d%lld",&n,&m,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) {
			scanf("%lld",&g[i][j]);
			g[i][j] += g[i][j-1];//把g变为存储行前缀和
			s[i][j] = g[i][j] + s[i-1][j];
		}
	int ans = -1;
	for (int x1=1;x1<=n;x1++)
		for (int x2=x1;x2<=n;x2++) 
			for (int y=1;y<=m;y++) ans = max(ans,(find(x1,x2,y)+1)*(x2-x1+1));
	printf("%d\n",ans?ans:-1);
	return 0;
}
