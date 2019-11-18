#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long ans[200005];
long long pre[200005];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) pre[i] = pre[i-1] + a[i];
	for (int i=1;i<=m;i++) {
		int l = 1;
		int r = i;
		long long cur = 0;
		while (r <= n) {
			cur += pre[r] - pre[l-1];
			ans[r] = cur;
			r += m;
		}
	}
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}
