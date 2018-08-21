#include <bits/stdc++.h>
using namespace std;
double f[100005];
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int n;
		scanf("%d",&n);
		f[1] = 1;
		for (int i=2;i<=n;i++) {
			f[i] = f[i-1] + (double)n/(n-(i-1));
		}
		printf("Case %d: %0.10lf\n",c,f[n]);
	}
	return 0;
}
