#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n,m,k,l;
	cin >> n >> m >> k >> l;
	//需要给大于k种
	l += k;
	if (l > n) {
		printf("-1\n");
		return 0;
	}
	long long need = l / m;
	if (l % m) need ++;
	long long sum = need * m;
	if (sum > n) printf("-1\n");
	else printf("%lld\n",need);
	return 0;
}
