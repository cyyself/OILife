#include <bits/stdc++.h>
using namespace std;
long long getc(long long n,long long k) {
	if (k > ( (n+1) / 2)) k = n - k;
	if (k == 0) return 1;
	long long z = n;
	long long m = 1;
	long long ans = z / m;
	for (long long i=2;i<=k;i++) {
		m ++;
		z --;
		ans = (ans * z) / m;
	}
	return ans;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		long long n,k;
		scanf("%lld%lld",&n,&k);
		if (k > n) printf("Case %d: 0\n",c);
		else {
			long long ans = getc(n,k);
			ans *= ans;
			for (long long i=2;i<=k;i++) ans *= i;
			printf("Case %d: %lld\n",c,ans);
		}
	}
	return 0;
}
