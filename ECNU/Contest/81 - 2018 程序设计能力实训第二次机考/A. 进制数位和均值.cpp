#include <bits/stdc++.h>
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		long long n;
		scanf("%lld",&n);
		long long fz = 0;//分子
		long long fm = 0;//分母
		for (int i=2;i<n;i++) {
			long long tmp = n;
			while (tmp) {
				fz += tmp % i;
				tmp /= i;
			}
			fm ++;
		}
		long long gcdab = gcd(fz,fm);
		printf("%lld/%lld\n",fz/gcdab,fm/gcdab);
	}
	return 0;
}