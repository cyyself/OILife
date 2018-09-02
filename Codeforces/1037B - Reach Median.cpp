#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
	int n,s;
	scanf("%d%d",&n,&s);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	long long ans = 0;
	int mid = n / 2;
	for (int i=0;i<n;i++) {
		if (i < mid) if (a[i] > s) ans += a[i] - s;
		if (i == mid) ans += abs(a[i]-s);
		if (i > mid) if (a[i] < s) ans += s - a[i];
	}
	cout << ans << endl;
	return 0;
}
