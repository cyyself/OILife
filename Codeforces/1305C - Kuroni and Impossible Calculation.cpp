#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
long long a[maxn],pre[maxn];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	if (n > 1000) printf("0\n");
	else {
		sort(a+1,a+1+n);
		long long ans = 1;
		for (int i=1;i<=n;i++) {
			for (int j=i+1;j<=n;j++) {
				ans *= (a[j] - a[i]) % m;
				ans %= m;
			}
		}
		ans %= m;
		printf("%lld\n",ans);
	}
	return 0;
}
