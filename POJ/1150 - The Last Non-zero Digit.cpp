#include <cstdio>
#include <algorithm>
using namespace std;
int cnt(int n,int x) {
	int res = 0;
	while (n) {
		res += n / x;
		n /= x;
	}
	return res;
}
int g(int n,int x) {
	if (n == 0) return 0;
	return n / 10 + ((n % 10) >= x) + g(n/5,x);
}
int f(int n,int x) {
	if (n == 0) return 0;
	return g(n,x) + f(n/2,x);
}
int qpow(int a,int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
			res %= 10;
		}
		b >>= 1;
		a *= a;
		a %= 10;
	}
	return res;
}
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		int cnt2 = cnt(n,2) - cnt(n-m,2);
		int cnt3 = f(n,3) - f(n-m,3);
		int cnt5 = cnt(n,5) - cnt(n-m,5);
		int cnt7 = f(n,7) - f(n-m,7);
		int cnt9 = f(n,9) - f(n-m,9);
		int dec = min(cnt2,cnt5);
		cnt2 -= dec;
		cnt5 -= dec;
		printf("%d\n",(qpow(2,cnt2)*qpow(3,cnt3)*qpow(5,cnt5)*qpow(7,cnt7)*qpow(9,cnt9))%10);
	}
	return 0;
}