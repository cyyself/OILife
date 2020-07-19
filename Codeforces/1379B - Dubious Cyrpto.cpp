#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long l,r,m;
		scanf("%lld%lld%lld",&l,&r,&m);
		bool ok = false;
		for (long long a=l;a<=r && !ok;a++) {
			long long b_mines_c = m % a;
			long long st = ((l - r) % a + a) % a;
			long long d = 0;
			if (b_mines_c >= st) d = b_mines_c - st;
			else d = (a - st) + b_mines_c;
			b_mines_c = l - r + d;
			if (b_mines_c == m) b_mines_c += a;
			if (l - r <= b_mines_c && b_mines_c <= r - l) {
				ok = true;
				for (long long b=l;b<=r;b++) {
					long long c = b - b_mines_c;
					if (l <= c && c <= r) {
						printf("%lld %lld %lld\n",a,b,c);
						break;
					}
				}
			}
		}
	}
	return 0;
}
