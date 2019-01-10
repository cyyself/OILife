#include <cstdio>
#include <cmath>
double l[10000];
long long n,k;
bool check(double p) {
	int cnt = 0;
	for (int i=0;i<n && cnt < k;i++) {
		cnt += l[i] / p;
	}
	return cnt >= k;
}
int main() {
	while (scanf("%lld%lld",&n,&k) == 2) {
		for (int i=0;i<n;i++) scanf("%lf",&l[i]);
		double l = 0;
		double r = 2e9;
		while (r - l > 1e-4) {
			double mid = (l + r) / 2;
			if (check(mid)) l = mid;
			else r = mid;
		}
		printf("%0.2f\n",floor((l+0.0001)*100.0)/100);
		//要是没看discuss我估计要因为精度WA一辈子
	}
	return 0;
}
