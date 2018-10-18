#include <bits/stdc++.h>
using namespace std;
struct DATA {
	int rem;
	int cur;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.rem < b.rem;
	}
}a[100005];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i].cur);
		if (a[i].cur % 10 != 0) a[i].rem = 10 - (a[i].cur % 10);
	}
	sort(a,a+n);
	int ans = 0;
	for (int i=0;i<n;i++) {
		if (a[i].rem <= k) {
			a[i].cur += a[i].rem;
			k -= a[i].rem;
			a[i].rem = 0;
		}
	}
	for (int i=0;i<n;i++) {
		int avail = min(k/10,10-(a[i].cur/10));
		k -= 10 * avail;
		a[i].cur += avail * 10;
		ans += a[i].cur / 10;
	}
	printf("%d\n",ans);
	return 0;
}
