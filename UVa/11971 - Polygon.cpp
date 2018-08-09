#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a,unsigned long long b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}
void sim(unsigned long long &a,unsigned long long &b) {
	unsigned long long g = gcd(a,b);
	a /= g;
	b /= g;
}
int main() {
	int T;
	scanf("%d",&T);
	int c = 1;
	while (T --) {
		unsigned long long n,k;
		scanf("%llu%llu",&n,&k);
		unsigned long long fz = (1LL << k) - (1 + k);
		unsigned long long fm = (1LL << k);
		sim(fz,fm);
		printf("Case #%d: %llu/%llu\n",c++,fz,fm);
	}
	return 0;
}
