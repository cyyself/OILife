#include <cstdio>
long long exgcd(long long a,long long b,long long &x,long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		long long t = exgcd(b,a%b,y,x);
		y -= x * (a / b);
		return t;
	}
}
int main() {
	long long x[205];
	int T;
	scanf("%d",&T);
	for (long long i=1;i<2*T;i+=2) scanf("%lld",&x[i]);
	for (int a=0;a<=10000;a++) {//search a
		long long c = x[3] - a * a * x[1];
		long long k,b;
		long long g = exgcd(-10001,a+1,k,b);
		if (c % g != 0) continue;
		b = b * c / g;
		bool judge = true;
		for (int i=2;i<=2*T;i++) {//check
			if (i % 2) {
				if (x[i] != (a * x[i-1] + b) % 10001) {
					judge = false;
					break;
				}
			}
			else x[i] = (a * x[i-1] + b) % 10001;
		}
		if (judge) break;
	}
	for (int i=2;i<=2*T;i+=2) printf("%lld\n",x[i]);
	return 0;
}