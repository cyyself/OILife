#include <bits/stdc++.h>
using namespace std;
int main() {
	long long b;
	scanf("%lld",&b);
	long long ans = 0;
	for (long long i=1;i*i<=b;i++) {
		if (b % i == 0) {
			ans ++;
			if (i * i != b) ans ++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
