#include <bits/stdc++.h>
int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		long long xs,ys,xe,ye;
		scanf("%lld%lld%lld%lld",&xs,&ys,&xe,&ye);
		long long odd = 0;//奇数行的个数
		long long even = 0;//偶数行的个数
		if (xs & 1) odd ++;
		if (xe & 1 && xe != xs) odd ++;
		odd += ( xe - xs - (xs&1) ) / 2;

		if ( (xs&1) == 0) even ++;
		if ( (xe&1) == 0 && xe != xs) even ++;
		even += (xe - xs - (!(xe&1) ) ) / 2;

		long long ans = 0;
		if ( (ys&1) == 0) {
			ans += even;
			ys ++;
		}
		if (ye&1) {
			ans += odd;
			ye --;
		}
		ans += ((ye-ys+1)/2) * (odd+even);

		printf("%lld\n",ans);
	}
	return 0;
}
