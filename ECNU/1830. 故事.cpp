#include <bits/stdc++.h>
using namespace std;
long long qpow(long long a,long long b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	long long tmp = qpow(a,b/2);
	if (b & 1) return tmp * tmp * a;
	return tmp * tmp;
}
int main() {
	long long n;
	while (scanf("%lld",&n) == 1) {
		if (n == -1) break;
		if (n == 1) {
			printf("no answer\n");
			continue;
		}
		long long ans = 0x7fffffffffffffff;
		for (int x=1;x<=30;x++) {
			double p = pow(n,1.0/x);
			p += 0.5;
			if (qpow(p,x) == n) {
				if (x % 2 == 0) ans = min(ans,(long long)-p);
				else ans = min(ans,(long long)p);
			}
		}
		if (ans == 0x7fffffffffffffff) printf("no answer\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
