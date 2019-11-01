#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e9+7;
long long fac[100005],inv[100005];
long long qpow(long long a,long long b) {
	long long ret = 1;
	while (b) {
		if (b & 1) {
			ret *= a;
			ret %= mo;
		}
		b >>= 1;
		a *= a;
		a %= mo;
	}
	return ret;
}
long long c(long long n,long long m) {
	if (n < 0 || m < 0 || m > n) return 0;
	return (((fac[n] * inv[m]) % mo) * inv[n-m]) % mo;
}
void init() {
	fac[0] = 1;
	for (int i=1;i<=100000;i++) {
		fac[i] = fac[i-1] * i;
		fac[i] %= mo;
	}
	inv[100000] = qpow(fac[100000],mo-2);
	for (int i=100000-1;i>=0;i--) {
		inv[i] = inv[i+1] * (i + 1LL);
		inv[i] %= mo;
	}
}
long long cal(int len) {
	long long ans = 0;
	for (int i=0;i<=len/2;i++) {
		ans += c(len-i,i);
		ans %= mo;
	}
	return ans;
}
char s[100005];
int main() {
	init();
	scanf("%s",s+1);
	int n = strlen(s+1);
	for (int i=1;i<=n;i++) {
		if (s[i] == 'w' || s[i] == 'm') {
			printf("0\n");
			return 0;
		}
	}
	int cnt = 0;
	long long ans = 1;
	for (int i=1;i<=n+1;i++) {
		if ( (s[i] == 'u' && s[i-1] == 'u') || (s[i] == 'n' && s[i-1] == 'n')) {
			cnt ++;
		}
		else {
			ans *= cal(cnt);
			ans %= mo;
			if (s[i] == 'u' || s[i] == 'n') cnt = 1;
			else cnt = 0;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
