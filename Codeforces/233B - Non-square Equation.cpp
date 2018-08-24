#include <bits/stdc++.h>
using namespace std;
long long cal(long long x) {
	long long s = 0;
	while (x) {
		s += x % 10;
		x /= 10;
	}
	return s;
}
int main() {
	long long n;
	cin >> n;
	long long ans = -1;
	for (int s=1;s<=81;s++) {
		long long x = sqrt(s*s/4 + n) + 0.5 - s/2;
		if (x*(x+s) != n || cal(x) != s) continue;
		if (ans == -1 || x < ans) ans = x;
	}
	cout << ans << endl;
	return 0;
}
