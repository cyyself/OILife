#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
long long w[maxn];
int main() {
	int n;
	long long p;
	scanf("%d%lld",&n,&p);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&w[i]);
	}
	sort(w+1,w+1+n);
	long long ans = 0;
	for (int i=1;i<=n;i++) {
		long long a = p;
		long long b = w[i];
		int l = max(a-b+1,b-a+1);
		int r = a+b - 1;
		int posl = lower_bound(w+1,w+1+n,l) - w;
		if (posl == n + 1) continue;
		int posr = upper_bound(w+1,w+1+n,r) - w;
		posr --;
		if (posl <= posr) {
			ans += posr - posl + 1;
			if (posl <= i && posr >= i) ans --;
		}
	}
	printf("%lld\n",ans>>1);
	return 0;
}
