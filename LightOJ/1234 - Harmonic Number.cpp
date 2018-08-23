#include <bits/stdc++.h>
using namespace std;
double sum[1000005];
int main() {
	for (int i=100;i<=100000000;i+=100) {
		double cur = sum[i/100-1];
		for (int j=i-99;j<=i;j++) cur += (double)1.0/j;
		sum[i/100] = cur;
	}
	int T;
	scanf("%d",&T);
	int c = 1;
	while (T --) {
		int n;
		scanf("%d",&n);
		double ans = sum[n/100];
		for (int i=(n/100)*100+1;i<=n;i++) ans += (double)1.0/i;
		printf("Case %d: %0.10lf\n",c++,ans);
	}
	return 0;
}
