#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
int main() {
	long long n,m,q;
	scanf("%lld%lld%lld",&n,&m,&q);
	bool rev = false;
	if (m > n) {
		rev = true;
		swap(n,m);
	}
	long long g = gcd(n,m);
	if (g == 1) for (int i=0;i<q;i++) printf("YES\n");
	else {
		long long b1 = n / g;
		long long b2 = m / g;
		for (int i=0;i<q;i++) {
			long long sx,sy,ex,ey;
			scanf("%lld%lld%lld%lld",&sx,&sy,&ex,&ey);
			sx --;
			ex --;
			if (rev) {
				sx ^= 1;
				ex ^= 1;
			}
			long long pos1 = (sx==0?(sy-1)/b1:(sy-1)/b2);
			long long pos2 = (ex==0?(ey-1)/b1:(ey-1)/b2);
			if (pos1 == pos2) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
