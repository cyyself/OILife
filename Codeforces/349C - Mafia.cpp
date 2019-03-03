#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int n;
bool check(long long x) {
	long long s = 0;
	for (int i=0;i<n && s < x;i++) {
		s += x - a[i];
	}
	return s >= x;
}
int main() {
	scanf("%d",&n);
	long long l = 1;
	long long r = 0x3fffffffffffffff;
	for (int i=0;i<n;i++) {
		scanf("%lld",&a[i]);
		l = max(l,a[i]);
	}
	sort(a,a+n);
	long long ans = -1;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%lld\n",ans);
	return 0;
}
