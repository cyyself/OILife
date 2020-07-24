#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int maxm = 21;
char a[maxn],b[maxm];
int nxt[26][maxn];
int f[maxm][maxm];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%s%s",a,b);
		int n = strlen(a);
		int m = strlen(b);
		for (int i=0;i<26;i++) nxt[i][n] = n;
		for (int i=n-1;i>=0;i--) {
			for (int j=0;j<26;j++) nxt[j][i] = nxt[j][i+1];
			nxt[a[i]-'a'][i] = i;
		}
		int q;
		scanf("%d",&q);
		while (q --) {
			int l,r;
			scanf("%d%d",&l,&r);
			l --;
			r --;
			f[0][0] = l - 1;
			int lcs = 0;
			for (int i=1;i<=m;i++) {
				f[i][0] = l - 1;
				f[i-1][i] = n;
				for (int j=1;j<=i;j++) {
					f[i][j] = min(nxt[b[i-1]-'a'][min(f[i-1][j-1]+1,n)],f[i-1][j]);
					if (f[i][j] <= r) lcs = max(lcs,j);
				}
			}
			printf("%d\n",r-l+1+m-2*lcs);
		}
	}
	return 0;
}
