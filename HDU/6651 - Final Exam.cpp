#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n,m,k;
		scanf("%lld%lld%lld",&n,&m,&k);
		long long need = n - k + 1;
		long long MIN = (m + 1) / need;
		if ((m + 1) % need) {
			MIN ++;
		}
		printf("%lld\n",MIN * (k - 1) + m + 1);
	}
	return 0;
}
