#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n,k;
		scanf("%lld%lld",&n,&k);
		long long a = n;
		for (long long i=2;i*i<=n;i++) if (n % i == 0) {
			a = i;
			break;
		}
		n += a;
		n += 2 * (k - 1);
		printf("%lld\n",n);
	}
	return 0;
}
