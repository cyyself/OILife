#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000;
double f[2][maxn][2];
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		int n,s;
		scanf("%d%d",&n,&s);
		int y = s - 2 * n;
		int no = n - y;
		memset(f,0,sizeof(f));
		for (int i=n-1;i>=0;i--) {
			int cur = i & 1;
			int nxt = (i & 1) ^ 1;
			for (int j=max(i-no,0);j<=min(i,y);j++) {
				double py = (double)(y - j) / (n - i);
				double pn = (double)(no - i + j) / (n - i);
				f[cur][j][1] = (j+1<=y ? py*f[nxt][j+1][1]:0) + pn * (f[nxt][j][0] + 1);
				f[cur][j][0] = (j+1<=y ? (py*(f[nxt][j+1][1]+1)):0) + pn * f[nxt][j][0];
			}
		}
		printf("Case %d: %0.10lf\n",cas,f[0][0][1]);
	}
	return 0;
}
