#include <bits/stdc++.h>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		long long ret = exgcd(b,a%b,y,x);
		y -= x * (a / b);
		return ret;
	}
}
int main() {
	long long a,b;
	scanf("%lld%lld",&a,&b);
	long long x,y;
	exgcd(a,b,x,y);
	printf("%lld %lld\n",x,y);
	return 0;
}
