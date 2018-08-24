#include <bits/stdc++.h>
using namespace std;
long long n,k;
bool judge(long long v) {
	long long cnt = 0;
	long long fm = 1;
	while (v/fm) {
		cnt += v / fm;
		fm *= k;
	}
	return cnt >= n;
}
int main() {
	cin >> n >> k;
	long long l = 1;
	long long r = 2;
	while (!judge(r)) r <<= 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (judge(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
