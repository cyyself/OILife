#include <bits/stdc++.h>
using namespace std;
int a[1000005];
long long gauss(long long x) {
	return (x * (x + 1)) >> 1;
}
int ans[1000005];
bool used[1000005];
int n;
long long check(long long rem) {
	for (int i=1;i<=n;i++) {
		used[i] = false;
		ans[i] = 0;
	}
	for (int i=1;i<=n;i++) {
		long long c = (n - i + 1) - i;
		if (c < 0) break;
		if (i != 1 && c + 1 <= rem && !used[n - (i - 1) + 1]) {
			rem -= c + 1;
			used[n - (i - 1) + 1] = true;
			ans[i] = n - (i - 1) + 1;
		}
		else if (c <= rem && c != 0) {
			rem -= c;
			used[n-i+1] = true;
			ans[i] = n - i + 1;
		}
	}
	int j = 1;
	for (int i=1;i<=n;i++) {
		if (ans[i] == 0) {
			while (used[j]) j ++;
			ans[i] = j;
			j ++;
		}
	}
	return rem;
}
int main() {
	long long k;
	scanf("%d%lld",&n,&k);
	long long maxk = 2 * (gauss(n) - gauss((n+1)/2)) + gauss((n+1)/2);
	if (k < gauss(n)) printf("-1\n");
	else {
		printf("%lld\n",k-check(k-gauss(n)));
		for (int i=1;i<=n;i++) printf("%d%c",i,i==n?'\n':' ');
		for (int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	}
	return 0;
}
