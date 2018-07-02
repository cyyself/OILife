#include <bits/stdc++.h>
using namespace std;
const unsigned long long mod = 1000000007;
unsigned long long qpow(unsigned long long a,unsigned long long b) {
	if (b == 0) return 1;
	if (b == 1) return a % mod;
	unsigned long long tmp = qpow(a,b/2) % mod;
	if (b % 2) return ( ( (tmp * tmp) % mod ) * a ) % mod;
	else return ( tmp * tmp ) % mod;
}
int main() {
	unsigned long long x,k;
	cin >> x >> k;
	if (x == 0) cout << 0 << endl;
	else {
		unsigned long long ans = x * 2 - 1;
		ans %= mod;
		ans = (ans * qpow(2,k) + 1) % mod;
		cout << ans << endl;
	}
	return 0;
}