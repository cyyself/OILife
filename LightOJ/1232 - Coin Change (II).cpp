#include <bits/stdc++.h>
using namespace std;
int f[10005];
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int n,k;
		scanf("%d%d",&n,&k);
		memset(f,0,sizeof(f));
		f[0] = 1;
		while (n --) {
			int x;
			scanf("%d",&x);
			if (x > k) continue;
			for (int i=x;i<=k;i++) {
				f[i] += f[i-x];
				f[i] %= 100000007;
			}
		}
		printf("Case %d: %d\n",c,f[k]);
	}
	return 0;
}
