#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
int main() {
	int n;
	long long T;
	cin >> n >> T;
	for (int i=1;i<=n;i++) cin >> a[i];
	long long ans = 0;
	long long cnt;
	while (1) {
		cnt = 0;
		long long cost = 0;
		for (int i=1;i<=n;i++) if (a[i] <= T - cost) {
			cnt ++;
			cost += a[i];
		}
		if (cost == 0) break;
		long long circle = T / cost;
		ans += circle * cnt;
		T -= cost * circle;
	}
	cout << ans << endl;
	return 0;
}
