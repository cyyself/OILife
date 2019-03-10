#include <bits/stdc++.h>
using namespace std;
int c[100];
int f[100][100];
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		memset(f,0x3f,sizeof(f));
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			scanf("%d",&c[i]);
			f[i][i] = 1;
		}
		for (int len=2;len<=n;len++) {
			for (int i=0;i+len-1<n;i++) {
				int j = i + len - 1;
				for (int mid=i;mid<j;mid++) {
					f[i][j] = min(f[i][j],f[i][mid]+f[mid+1][j] - (c[i] == c[j]));
				}
			}
		}
		printf("Case %d: %d\n",cas,f[0][n-1]);
	}
	return 0;
}
