#include <bits/stdc++.h>
using std::min;
const double eps = 1e-8;
double w[105];
double p[105];//到这里的概率
double e[105];//到这里的期望值
bool equal(double a,double b) {
	if (fabs(a-b) <= eps) return true;
	else return false;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			p[i] = 0;
			e[i] = 0;
		}
		p[1] = 1;
		for (int i=1;i<=n;i++) scanf("%lf",&w[i]);
		for (int i=1;i<=n;i++) {
			e[i] += p[i] * w[i];
			int len = min(n - i,6);
			for (int d=1;d<=len;d++) {
				p[i+d] += p[i] * (1.0/(double)len);
				e[i+d] += e[i] * (1.0/(double)len);
			}
		}
		printf("Case %d: %0.10lf\n",c,e[n]);
	}
	return 0;
}
