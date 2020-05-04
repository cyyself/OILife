#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5+5;
long long a[maxn],b[maxn];
long long n,m;
long long check(long long x) {
	map <long long,long long> cnt[2];
	for (long long i=0;i<n;i++) {
		long long blk = a[i] / x;
		cnt[blk&1][a[i]%x] ++;
	}
	for (long long i=0;i<m;i++) {
		long long blk = b[i] / x;
		cnt[(blk&1)^1][b[i]%x] ++;
	}
	long long ans = 0;
	for (long long i=0;i<2;i++) {
		for (auto sel:cnt[i]) ans = max(ans,sel.second);
	}
	return ans;
}
int main() {
	long long y1;
	cin >> n >> y1;
	for (long long i=0;i<n;i++) cin >> a[i];
	long long y2;
	cin >> m >> y2;
	for (long long i=0;i<m;i++) cin >> b[i];
	long long ans = min(2ll,n+m);
	for (long long i=1;i<=(1ll<<31);i<<=1) {
		ans = max(ans,check(i));
	}
	cout << ans << endl;
	return 0;
}
