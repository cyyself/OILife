#include <bits/stdc++.h>
const long double eps = 4e-16;
const int mod = 1e9+1;
int gcd(int a,int b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}
int main() {
	//srand(unsigned(time(0)));
	long double a;
	scanf("%Lf",&a);
	while (1) {
		int q = rand() % mod;
		int p = q * a;
		for (int i=p-10;i<=p+10;i++) {
			if (fabs((long double)i/q - a) < eps) {
				int g = gcd(i,q);
				printf("%d %d\n",i/g,q/g);
				return 0;
			}
		}
	}
	return 0;
}
