#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long d[101];
long long s[101];
long long f[101][101];
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		memset(f,0x3f,sizeof(f));
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%lld",&d[i]);
			s[i] = s[i-1] + d[i];
			f[i][i] = 0;
		}
		for (int len=2;len<=n;len++) {
			for (int i=1;i+len-1<=n;i++) {
				int j = i + len - 1;
				f[i][j] = min(f[i][j],f[i+1][j]+d[i]*(len-1));
				for (int mid=i+1;mid<=j-1;mid++) {
					f[i][j] = min(f[i][j],f[i][mid-1] + f[mid+1][j] + (s[j]-s[mid])*(mid-i) + d[mid]*(len-1));
				}
				f[i][j] = min(f[i][j],f[i][j-1]+d[j]*(len-1));
			}
		}
		printf("Case #%d: %lld\n",cas,f[1][n]);
	}
	return 0;
}
