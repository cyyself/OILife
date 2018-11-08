
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000;
long long qpow(long long a,long long b) {
	long long base = a;
	base %= 1000;
	long long ret = 1;
	while (b) {
		if (b & 1) {
			ret *= base;
			ret %= 1000;
		}
		b >>= 1;
		base *= base;
		base %= 1000;
	}
	return ret;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		long long n,k;
		scanf("%lld%lld",&n,&k);
		long double tmp = log10(n);
		tmp *= k;
		long double yxsz = tmp - floor(tmp);//有效数字
		int zs = floor(tmp);
		int pre = pow(10,yxsz) * pow(10,min(2,zs));
		long long suf = qpow(n,k);
		printf("Case %d: %d %03lld\n",c,pre,suf);
	}
	return 0;
}
