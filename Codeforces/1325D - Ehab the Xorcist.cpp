#include <bits/stdc++.h>
using namespace std;
int main() {
	long long u,v;
	scanf("%lld%lld",&u,&v);
	if (u > v || ((v - u) & 1) == 1) {
		printf("-1\n");
	}
	else if (u == v) {
		if (u == 0) printf("0\n");
		else printf("1\n%lld\n",u);
	}
	else {
		long long d = v - u;
		d >>= 1;
		if ((u & d) == 0) printf("2\n%lld %lld\n",u|d,d);
		else printf("3\n%lld %lld %lld\n",u,d,d);
	}
	return 0;
}
