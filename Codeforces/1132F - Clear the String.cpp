#include <bits/stdc++.h>
using namespace std;
int f[505][505];
char s[505];
int main() {
	memset(f,0x3f,sizeof(f));
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++) f[i][i] = 1;
	for (int len=2;len<=n;len++) {
		for (int i=0;i<n;i++) {
			int j = i + len - 1;
			if (j >= n) break;
			for (int m=i;m<j;m++) {
				f[i][j] = min(f[i][j],f[i][m]+f[m+1][j]-(s[i]==s[j]));
			}
		}
	}
	printf("%d\n",f[0][n-1]);
	return 0;
}
