#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		double r,n;
		scanf("%lf%lf",&r,&n);
		double s = sin(pi/n);
		printf("%0.10lf\n",r*s/(1+s));
	}
	return 0;
}
