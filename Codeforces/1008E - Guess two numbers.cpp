#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n;
	cin >> n;
	long long a = 0;
	long long b = 0;
	long long sa = 1;
	long long sb = 1;
	while (1) {
		cout << a + sa << " " << b + sb << endl;
		fflush(stdout);
		int ans;
		cin >> ans;
		switch(ans) {
			case 0:
				return 0;
			case 1:
				a += sa;
				sa <<= 1;
				if (a + sa > n) sa = n - a;
				break;
			case 2:
				b += sb;
				sb <<= 1;
				if (b + sb > n) sb = n - b;
				break;
			case 3:
				sa = max(1LL,sa>>1);
				sb = max(1LL,sb>>1);
		}
	}
	return 0;
}
