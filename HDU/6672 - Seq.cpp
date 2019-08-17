#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n;
		scanf("%lld",&n);
		if (n % 6 == 0) {
			printf("%lld\n",n/2);
		}
		else if (n % 6 == 1) {
			printf("%lld\n",1+4*(n-1)/6);
		}
		else if (n % 6 == 2) {
			printf("%lld\n",1+3*(n-2)/6);
		}
		else if (n % 6 == 3) {
			printf("%lld\n",(n-3)/6);
		}
		else if (n % 6 == 4) {
			printf("%lld\n",3+6*(n-4)/6);
		}
		else if (n % 6 == 5) {
			printf("%lld\n",(n-5)/6);
		}
	}
	return 0;
}
