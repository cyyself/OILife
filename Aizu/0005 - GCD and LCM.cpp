#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a,unsigned long long b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}
int main() {
	unsigned long long a,b;
	while (scanf("%llu%llu",&a,&b) == 2) {
		unsigned long long g = gcd(a,b);
		printf("%llu %llu\n",g,a*b/g);
	}
	return 0;
}
