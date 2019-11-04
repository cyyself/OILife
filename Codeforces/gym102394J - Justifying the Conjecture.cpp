#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n;
		scanf("%lld",&n);
		if (n >= 6) {
			if (n & 1) printf("%lld %lld\n",3ll,n-3);
			else printf("%lld %lld\n",2ll,n-2);
		}
		else printf("-1\n");
	}
	return 0;
}
