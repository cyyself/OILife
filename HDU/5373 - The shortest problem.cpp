#include <bits/stdc++.h>
using namespace std;
long long getsum(long long x) {
	long long ret = 0;
	while (x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}
long long cnt(long long x) {
	long long ret = 0;
	while (x) {
		ret ++;
		x /= 10;
	}
	return ret;
}
int main() {
	long long n,t;
	int c = 0;
	long long sum = 0;
	while (scanf("%lld%lld",&n,&t) == 2) {
		if (n == -1) break;
		sum = getsum(n);
		n %= 11;
		c ++;
		for (int i=0;i<t;i++) {
			long long d = sum;
			n *= pow(10,cnt(d));
			n += d;
			n %= 11;
			sum += getsum(d);
		}
		if (n == 0) printf("Case #%d: Yes\n",c);
		else printf("Case #%d: No\n",c);
	}
	return 0;
}
