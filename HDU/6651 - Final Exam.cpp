#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n,m,k;
		scanf("%lld%lld%lld",&n,&m,&k);
		long long need = n - k + 1;
		long long MIN = (m + 1 + (need - 1) ) / need;//向上取整
		printf("%lld\n",MIN * (k - 1) + m + 1);
	}
	return 0;
}
