#include <bits/stdc++.h>
using namespace std;
int a[105];
int s[105];
int f[105][105];
int n;
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			s[i] = s[i-1] + a[i];
			f[i][i] = a[i];
		}
		for (int l=2;l<=n;l++)
			for (int i=0;i+l-1<n;i++) {
				int j = i + l - 1;
				f[i][j] = s[j] - s[i-1];
				for (int k=i;k<j;k++) f[i][j] = max(f[i][j],max(s[k]-s[i-1]-f[k+1][j],s[j]-s[k]-f[i][k]));
			}
		printf("Case %d: %d\n",c,f[0][n-1]);
	}
	return 0;
}
