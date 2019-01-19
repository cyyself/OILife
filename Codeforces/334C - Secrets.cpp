#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n;
	scanf("%lld",&n);
	long long x = 1;
	while (n % x == 0) x *= 3;
	printf("%lld\n",(n+x-1)/x);
	return 0;
}
