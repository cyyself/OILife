#include <bits/stdc++.h>
using namespace std;
int main() {
	int c = 1;
	int n;
	double e;
	while (scanf("%d%lf",&n,&e) == 2) {
		if (e == 0) break;
		while (n--) {
			double p,l,v;
			scanf("%lf%lf%lf",&p,&l,&v);
			e -= l - 2 * l / v;
		}
		printf("Case %d: %0.3lf\n\n",c++,e);
	}
	return 0;
}
