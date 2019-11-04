#include <bits/stdc++.h>
using namespace std;
double w[100005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,k;
		scanf("%d%d",&n,&k);
		double sum = 0;
		for (int i=1;i<=n;i++) {
			scanf("%lf",&w[i]);
			sum += w[i];
		}
		double c = k;
		for (int i=1;i<=n;i++) {
			printf("%0.10f%c",w[i]+c*w[i]/sum,i==n?'\n':' ');
		}
	}
	return 0;
}
