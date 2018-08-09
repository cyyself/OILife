#include <bits/stdc++.h>
using namespace std;
unsigned long long n;
unsigned long long qpow(unsigned long long a,unsigned long long b,unsigned long long mo) {
	if (b == 0) return 1;
	if (b == 1) return a % mo;
	unsigned long long tmp = qpow(a % mo,b/2,mo);
	if (b & 1) return (((tmp * tmp) % mo) * a)% mo;
	else return (tmp * tmp) % mo;
}
int main() {
	int c = 1;
	while (scanf("%llu",&n) == 1) {
		if (n == 0) break;
		bool pretest = true;
		bool ans = true;
		for (int i=0;i<10;i++) {
			int a = 2+rand()%(n-2);
			if (qpow(a,n,n) != a) pretest = false;
		}
		if (pretest) {
			for (int i=2;i<=(sqrt(n)+0.5);i++) {
				if (n % i == 0) ans = false;
			}
		}
		else ans = false;
		if (pretest == ans) printf("%llu is normal.\n",n);
		else printf("The number %llu is a Carmichael number.\n",n);
	}
	return 0;
}
