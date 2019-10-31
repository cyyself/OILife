#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n,p;
	scanf("%lld%lld",&n,&p);
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i=1;i<=10000;i++) {
		long long cur = n - i * p;
		if (cur > 0 && cur >= i && __builtin_popcount(cur) <= i) ans = min(ans,1ll*i);
	}
	if (ans == 0x3f3f3f3f3f3f3f3f) printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}
