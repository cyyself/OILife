#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		int n;
		scanf("%d",&n);
		printf("Case #%d:\n",cas);
		int maxrow = 1;
		while (1 << (maxrow - 1) < n) maxrow ++;
		n -= maxrow;
		bool pos = false;//0:left,1:right
		int rem = 0;
		for (int i=1;i<=maxrow;i++) {
			printf("%d %d\n",i,pos?i:1);
			if (n & (1 << (i - 1))) {
				if (pos) {
					for (int j=i-1;j>=1;j--) printf("%d %d\n",i,j);
				}
				else {
					for (int j=2;j<=i;j++) printf("%d %d\n",i,j);
				}
				rem ++;
				pos ^= 1;
			}
		}
		for (int i=maxrow+1;i<=maxrow+rem;i++) printf("%d %d\n",i,pos?i:1);
	}
	return 0;
}
