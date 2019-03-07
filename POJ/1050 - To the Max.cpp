#include <cstdio>
#include <algorithm>
using namespace std;
int a[101][101];
long long s[101][101];
int main() {
	int n;
	scanf("%d",&n);
	for (register int i=1;i<=n;i++) for (register int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for (register int i=1;i<=n;i++) for (register int j=1;j<=n;j++) {
		s[i][j] = s[i-1][j] + a[i][j] + s[i][j-1] - s[i-1][j-1];
	}
	long long ans = 0;
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++)
			for (register int k=i;k<=n;k++)
				for (register int l=j;l<=n;l++) {
					register long long sum = s[k][l] - s[k][j-1] - s[i-1][l] + s[i-1][j-1];
					ans = max(sum,ans);
				}
	printf("%lld\n",ans);
	return 0;
}
