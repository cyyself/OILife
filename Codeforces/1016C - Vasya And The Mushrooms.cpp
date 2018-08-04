
 #include <bits/stdc++.h>
using namespace std;
long long pre[300005];
long long a[3][300005];
long long f[300005];
int main() {
	int n;
	cin >> n;
	for (int i=1;i<=2;i++)
		for (int j=1;j<=n;j++) cin >> a[i][j];
	for (int i=1;i<=n;i++) pre[i] = pre[i-1] + a[1][i] + a[2][i];
	int x = 1;
	int y = 2;
	for (int t=1;t<=n*2-1;t++) {
		f[0] += a[x][y] * t;
		if (t >= n) y --;
		else y ++;
		if (y == n + 1) {
			x = 2;
			y --;
		}
	}
	x = 2;
	y = 1;
	for (int t=1;t<=n*2-1;t++) {
		f[1] += a[x][y] * t;
		if (t >= n + 1) y --;
		else y ++;
		if (y == n + 1) {
			x = 1;
			y --;
		}
		
	}
	long long ans = max(f[0],f[1]);
	for (int i=2;i<=n-1;i++) {
		f[i] = f[i-2] + (pre[n]-pre[i-1]) * 2 - (a[2-i%2][i-1] + a[2-i%2][i]) * (n - i + 1) * 2;
		ans = max(ans,f[i]);
	}
	cout << ans << endl;
	return 0;
}
