#include <bits/stdc++.h>
using namespace std;
int a[12];
int main() {
	int k;
	cin >> k;
	for (int i=0;i<12;i++) cin >> a[i];
	sort(a,a+12);
	int cur = 0;
	int cnt = 0;
	for (int i=11;i>=0 && cur < k;i--) {
		cur += a[i];
		cnt ++;
	}
	if (cur < k) cout << -1 << endl;
	else cout << cnt << endl;
	return 0;
}
