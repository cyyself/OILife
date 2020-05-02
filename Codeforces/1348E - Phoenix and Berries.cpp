#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int maxk = 505;
int a[maxn],b[maxn];
bool f[maxn][maxk];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	long long sum = 0;
	for (int i=1;i<=n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		sum += a[i] + b[i];
	}
	f[0][0] = true;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<k;j++) {
			f[i][j] = f[i-1][(k+j-a[i]%k)%k];
			for (int l=0;l<=min(a[i],k-1);l++) {
				if ((a[i]-l)%k+b[i] >= k) f[i][j] |= f[i-1][(k+j-l)%k];
			}
		}
	}
	long long ans = 0;
	for (int i=0;i<k;i++) if (f[n][i]) ans = max(ans,(sum-i)/k);
	printf("%lld\n",ans);
	return 0;
}
