#include <bits/stdc++.h>
using namespace std;
double f[100005];
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int n;
		scanf("%d",&n);
		f[0] = 1;
		int i;
		for (i=1;i<=n;i++) {
			f[i] = (double)(n-i)/n * f[i-1];
			if (f[i] <= 0.5) break;
		}
		printf("Case %d: %d\n",c,i);
	}
	return 0;
}
