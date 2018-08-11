#include <bits/stdc++.h>
using namespace std;
const long long mo = 1000000007;
long long qpow(long long a,long long b) {
	if (b == 0) return 1;
	if (b == 1) return a % mo;
	long long tmp = qpow(a,b/2);
	if (b & 1) return (((tmp * tmp) % mo) * a) % mo;
	else return (tmp * tmp) % mo;
}
int main() {
	int n,m,k;
	cin >> n >> m >> k;
	if (k > n) cout << qpow(m,n) << endl;
	else {
		if (k == 1) cout << qpow(m,n) << endl;
		else {
			if (k == n) cout << qpow(m,(n+1)/2) << endl;
			else {
				//k < n
				if (m == 1) cout << 1 << endl;
				else {
					cout << m * (k%2?m:1) << endl;
				}
			}
		}
	}
	return 0;
}
