#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int s[105];
int f[105];
int dp[2][200005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&s[i],&f[i]);
	int center = 1000 * n + 1;
	int range = 2 * 1000 * n + 1;
	//waste dp[0]
	memset(dp,0x80,sizeof(dp));
	dp[1][center] = 0;
	int ans = 0;
	for (int i=0;i<n;i++) {
		int l = max(0,s[i]);//s[i] > 0
		int r = min(range,(range)+s[i]);// s[i] < 0
		for (int j=l;j<=r;j++) {
			dp[i&1][j] = max(dp[(i&1)^1][j],dp[(i&1)^1][j-s[i]]+f[i]);
			if (j >= center && dp[i&1][j] > 0) ans = max(ans,j-center+dp[i&1][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
