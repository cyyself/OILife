#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n --) {
		int x;
		cin >> x;
		int cnt = 0;
		for (int i=30;i>=0;i--) if (x & (1 << i)) cnt ++;
		int ans = 1 << cnt;
		cout << ans << endl;
	}
	return 0;
}
