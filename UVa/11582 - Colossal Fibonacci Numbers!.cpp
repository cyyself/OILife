#include <bits/stdc++.h>
using namespace std;
const int maxn=1000+10;
unsigned long long mo;
int f[maxn*maxn];

unsigned long long qpow(unsigned long long a,unsigned long long b) {
	if (b == 0) return 1;
	if (b == 1) return a % mo;
	unsigned long long tmp = qpow(a % mo,b/2);
	if (b & 1) return (((tmp * tmp) % mo) * a)% mo;
	else return (tmp * tmp) % mo;
}

int main() {
	int T;
	cin >> T;
	while (T --) {
		unsigned long long a,b,n;
		cin >> a >> b >> n;
		if (n == 1 || a == 0) {
			printf("0\n");
			continue;
		}
		f[1] = 1;
		f[2] = 1;
		for (int i=3;i<=n*n+10;i++) {//fibonacii在取mod的情况下会有循环节
			f[i] = f[i-1] + f[i-2];
			f[i] %= n;
			if (f[i] == f[2] && f[i-1] == f[1]) {
				mo = i - 2;
				break;
			}
		}
		int pos = qpow(a%mo,b);
		cout << f[pos] << endl;
	}
	return 0;
}
