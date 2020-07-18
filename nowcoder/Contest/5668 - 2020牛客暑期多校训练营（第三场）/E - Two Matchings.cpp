#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int a[maxn];
long long f[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			f[i] = inf;
		}
		sort(a+1,a+1+n);
		f[0] = 0;
		for (int i=4;i<=n;i++) {
			f[i] = min(f[i],f[i-4]+2*(a[i]-a[i-3]));
			if (i >= 6) f[i] = min(f[i],f[i-6] + 2 * (a[i] - a[i-5]));
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}
