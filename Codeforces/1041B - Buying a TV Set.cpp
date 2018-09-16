#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
int main() {
	long long a,b,x,y;
	scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
	long long div = gcd(x,y);
	x /= div;
	y /= div;
	printf("%lld\n",min(a/x,b/y));
	return 0;
}
