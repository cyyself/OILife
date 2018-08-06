#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int f[1<<15];
int d[15][15];
int health[15];
int n;
int dfs(int stat) {//还没被消灭的是1，已经消灭的是0
	if (__builtin_popcount(stat) == 0) return 0;
	if (f[stat] != INF) return f[stat];
	for (int i=0;i<n;i++) {
		if (stat & (1 << i)) {
			//i还没被消灭
			int maxd = 1;
			for (int j=0;j<n;j++) if ( (stat & (1 << j) )== 0) maxd = max(d[j][i],maxd);
			f[stat] = min(f[stat],dfs(stat^(1<<i))+(int)ceil(1.0*health[i]/maxd));
		}
	}
	return f[stat];
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		memset(f,0x3f,sizeof(f));
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&health[i]);
		for (int i=0;i<n;i++) {
			long long tmp;
			scanf("%lld",&tmp);
			for (int j=n-1;j>=0;j--) {
				d[i][j] = tmp % 10;
				tmp /= 10;
			}
		}
		printf("Case %d: %d\n",c,dfs((1<<n)-1));
	}
	return 0;
}
