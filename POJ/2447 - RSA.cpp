#include <cstdio>
#include <cstdlib>
long long abs(long long x) {
	if (x < 0) return -x;
	return x;
}
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
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}
long long qmul(long long a,long long b,long long mod) {
	long long ret = 0;
	while (b) {
		if (b&1) ret = (ret + a) % mod;
		a = (a << 1) % mod;
		b >>= 1;
	}
	return ret;
}
long long qpow(long long a,long long b,long long mod) {
	if (b == 0) return 1 % mod;
	long long t = qpow(a,(b>>1),mod);
	t = qmul(t,t,mod);
	if (b&1) t = qmul(t,a,mod);
	return t;
}
long long getp(long long n) {
	//这个函数我也不是很懂，我也是抄过来的
	if ((n&1) == 0) return 2;
	while (true) {
		long long x = abs((long long)rand()) % n;
		long long y = x;
		long long c = abs((long long)rand()) % n;
		if (c == 0 || c == 2) c = 1;
		for (int i=1,k=2;;i++) {
			x = qmul(x,x,n);
			if (x >= c) x -= c;
			else x += n - c;
			if (x == n) x = 0;
			if (x == 0) x = n - 1;
			else x --;
			long long d = gcd(abs(x-y),n);
			if (d == n) break;
			if (d != 1) return d;
			if (i == k) {
				y = x;
				k <<= 1;
			}
		}
	}
}
/*
long long getp(long long x) {
	for (int i=2;i<=x;i++) {
		if (x % i == 0) return i;
	}
	return -1;
}
*/
int main() {
	long long C,E,N;
	while (scanf("%lld%lld%lld",&C,&E,&N) == 3) {
		long long P = getp(N);
		long long Q = N / P;
		long long T = (P-1) * (Q-1);
		long long D,y;
		exgcd(E,T,D,y);
		D = (D + T) % T;
		printf("%lld\n",qpow(C,D,N));
	}
	return 0;
}