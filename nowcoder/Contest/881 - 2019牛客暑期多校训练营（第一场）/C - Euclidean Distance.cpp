#include <bits/stdc++.h>
using namespace std;
int n;
long long a[10005];
long long check(long long x) {
	long long ret = 0;
	for (int i=1;i<=n;i++) if (a[i] > x) ret += a[i] - x;
	return ret;
}
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
void sim(long long &a,long long &b) {
	long long g = gcd(a,b);
	a /= g;
	b /= g;
}
int main() {
	long long m;
	while (scanf("%d%lld",&n,&m) == 2) {
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		long long l = -1e9, r = 1e9;
		long long ans;
		long long rem;
		while (l <= r) {
			long long mid = (l + r) / 2;
			long long val = m - check(mid);
			if (val >= 0) {
				ans = mid;
				rem = val;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		//printf("(debug)%lld %lld\n",ans,rem);
		long long k = 0;
		for (int i=1;i<=n;i++) if (a[i] >= ans) k ++;
		long long fz = 0;
		long long fm = 1;
		for (int i=n;i>=1;i--) {
			long long curfz,curfm;
			if (a[i] >= ans) {
				if (k) {
					curfz = ans * ans * k * k - 2 * ans * k * rem + rem * rem;
					curfm = k * k;
				}
				else {
					curfz = ans * ans;
					curfm = 1;
				}
			}
			else {
				curfz = a[i] * a[i];
				curfm = 1;
			}
			fz = curfz * fm + fz * curfm;
			fm *= curfm;
			sim(fz,fm);
		}
		fm *= m * m;
		sim(fz,fm);
		if (fm != 1) printf("%lld/%lld\n",fz,fm);
		else printf("%lld\n",fz);
	}
	return 0;
}