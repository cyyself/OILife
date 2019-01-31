#include <cstdio>
const double eps = 1e-10;
double a;
int n;
double check(double x) {
	double pre_1 = x,pre_2 = a;
	for (int i=3;i<=n;i++) {
		double c = 2 * pre_1 - pre_2 + 2;
		if (c < 0) return -1;
		pre_2 = pre_1;
		pre_1 = c;
	}
	return pre_1;
}
int main() {
	while (scanf("%d%lf",&n,&a) == 2) {
		double l = 0;
		double r = a;
		double ans = -1;
		while (r-l > eps) {
			double mid = (l + r) / 2;
			double cur = check(mid);
			if (cur >= 0) {
				ans = cur;
				r = mid;
			}
			else l = mid;
		}
		printf("%0.2f\n",ans);//lf会wa，不知道为啥
	}
	return 0;
}
