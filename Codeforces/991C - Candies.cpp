#include <bits/stdc++.h>
using namespace std;
long long n;
bool check(long long k) {
	long long c = n;
	long long ans = 0;
	while (c) {
		ans += min(k,c);
		c -= min(k,c);
		c -= c / 10;
	}
	if (ans * 2 >= n) return true;
	else return false;
}
int main() {
	cin >> n;
	long long l = 1;
	long long r = n;
	while (l < r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l << endl;
	return 0;
}