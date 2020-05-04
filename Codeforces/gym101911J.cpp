#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}
int main() {
	long long a,b,x,y;
	scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
	long long g = gcd(x,y);
	x /= g;
	y /= g;
	long long ans = min(a/x,b/y);
	printf("%lld\n",ans);
	return 0;
}
