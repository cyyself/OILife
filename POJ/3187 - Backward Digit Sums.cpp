#include <cstdio>
#include <algorithm>
using namespace std;
int f[15][15];
int ans[15];
int main() {
	for (int i=0;i<=11;i++) {
		f[i][0] = 1;
		for (int j=1;j<=i;j++) f[i][j] = f[i-1][j] + f[i-1][j-1];
	}
	int n,sum;
	scanf("%d%d",&n,&sum);
	for (int i=0;i<n;i++) ans[i] = i + 1;
	do {
		int cur = 0;
		for (int i=0;i<n;i++) cur += ans[i] * f[n-1][i];
		if (cur == sum) {
			for (int i=0;i<n;i++) {
				if (i != 0) printf(" ");
				printf("%d",ans[i]);
			}
			printf("\n");
			break;
		}
	} while (next_permutation(ans,ans+n));
	return 0;
}
