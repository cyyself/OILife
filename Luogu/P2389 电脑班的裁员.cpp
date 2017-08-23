#include <cstdio>
#include <algorithm>
using namespace std;
int s[505];
int sum[505];
int f[505][505];
int n,k;
int main() {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		scanf("%d",&s[i]);
		sum[i] = sum[i-1] + s[i];
	}
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=k;j++) {
			f[i][j] = f[i-1][j];
			for (int cut=0;cut<i;cut++)
				f[i][j] = max(f[i][j],f[cut][j-1]+sum[i]-sum[cut]);
		}
	printf("%d\n",f[n][k]);
	return 0;
}