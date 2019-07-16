#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		double v1,v2,r,d;
		scanf("%lf%lf%lf%lf",&v1,&v2,&r,&d);
		double _time = r / v1 * asin(v1 / v2);
		if (_time * v2 <= d) puts("Wake up to code");
		else puts("Why give up treatment");
	}
	return 0;
}
