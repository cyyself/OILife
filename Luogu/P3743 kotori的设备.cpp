#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
const double zero = 0;
int n;
double a[100005];
double b[100005];
double p;
bool check(double time) {
	double tot = time * p;
	for (int i=0;i<n;i++) {
		tot -= max(a[i] * time - b[i],zero);
	}
	return tot >= 0;
}
int main() {
	scanf("%d%lf",&n,&p);
	double costsum = 0;
	for (int i=0;i<n;i++) {
		scanf("%lf%lf",&a[i],&b[i]);
		costsum += a[i];
	}
	if (costsum <= p) {
		printf("-1\n");
	}
	else {
		double l = 0;
		double r = 1;
		while (check(r)) {
			l = r;
			r *= 2;
		}
		while ((r-l) > eps) {
			double mid = (l+r)/2;
			if (check(mid)) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		printf("%lf\n",l);
	}
	return 0;
}
