#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n;
		scanf("%lld",&n);
		long long cnt3 = 2;
		while (cnt3 * (cnt3+1LL) / 2LL <= n) cnt3 ++;
		long long rem = n - cnt3 * (cnt3-1) / 2;
		printf("1");
		for (long long i=0;i<cnt3-2;i++) printf("3");
		for (long long i=0;i<rem;i++) printf("1");
		printf("337\n");
	}
	return 0;
}
