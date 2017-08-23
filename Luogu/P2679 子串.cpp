#include <bits/stdc++.h>
using namespace std;
char a[1005];
char b[205];
int f[205][205];
int ans[205][205];
int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",a+1);
	scanf("%s",b+1);
	ans[0][0] = 1;
	for (int i=1;i<=n;i++)
		for (int j=m;j > 0;j--) 
			for (int l=k;l > 0;l--) {
				if (a[i] != b[j]) f[j][l] = 0;
				else {
					f[j][l] = (f[j-1][l] + ans[j-1][l-1]) % 1000000007;
					ans[j][l] = (f[j][l] + ans[j][l]) % 1000000007;
				}
			}
	printf("%d\n",ans[m][k]);
	return 0;
}