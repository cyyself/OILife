#include <bits/stdc++.h>
using namespace std;
long double getc(unsigned long long n,unsigned long long k) {
	if (k > ( (n+1) / 2)) k = n - k;
	if (k == 0) return 1;
	unsigned long long z = n;
	unsigned long long m = 1;
	long double ans = z / m;
	for (unsigned long long i=2;i<=k;i++) {
		m ++;
		z --;
		ans /= m;
		ans *= z;
	}
	return ans;
}
int main() {
	unsigned long long p,q,r,s;
	while (scanf("%llu%llu%llu%llu",&p,&q,&r,&s) == 4) {
		long double c1 = getc(p,q);
		long double c2 = getc(r,s);
		printf("%0.5Lf\n",c1/c2);
	}
	return 0;
}
