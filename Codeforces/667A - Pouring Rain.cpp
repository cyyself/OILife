#include <bits/stdc++.h>
using namespace std;
int main() {
	double PI = atan(1) * 4;
	double d,h,v,e;
	cin >> d >> h >> v >> e;
	double r = d/2;
	v /= (r * r) * PI;
	if (v < e) printf("NO\n");
	else printf("YES\n%0.12lf\n",h/(v-e));
	return 0;
}
