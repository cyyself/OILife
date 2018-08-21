#include <bits/stdc++.h>
using namespace std;
double w[105];
double p[105];//到这里的概率
double e[105];//到这里的期望值
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%lf",&w[i]);
			p[i] = 0;
			e[i] = 0;
		}
		p[1] = 1;
		for (int i=1;i<=n;i++) {
			int dis = min(n-i,6);
			e[i] += p[i] * w[i];
			for (int j=i+1;j<=i+dis;j++) {
				p[j] += p[i] / dis;
				e[j] += e[i] / dis;
			}
		}
		printf("Case %d: %0.10lf\n",c,e[n]);
	}
	return 0;
}
