#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int f[25][3];
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		memset(f,0x3f,sizeof(f));
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++) for (int j=0;j<3;j++) scanf("%d",&f[i][j]);
		for (int i=1;i<n;i++) {
			for (int j=0;j<3;j++) {
				int d = INF;
				for (int k=0;k<3;k++) if (k != j) d = min(d,f[i-1][k]);
				f[i][j] += d;
			}
		}
		int ans = INF;
		for (int j=0;j<3;j++) ans = min(ans,f[n-1][j]);
		printf("Case %d: %d\n",c,ans);
	}
	return 0;
}
