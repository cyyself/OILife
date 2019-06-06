#include <bits/stdc++.h>
using namespace std;
long long a[300005];
long long suf[300005];
int n,k;
int main() {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=n;i>=1;i--) suf[i] = suf[i+1] + a[i];
	sort(suf+2,suf+n+1);
	long long ans = suf[1];
	for (int i=n;i>n-k+1;i--) ans += suf[i];
	printf("%lld\n",ans);
	return 0;
}
