#include <bits/stdc++.h>
int main() {
	double a;
	scanf("%lf",&a);
	long long b = *((long long *)&a);
	for (int i=56;i>=0;i-=8) {
		long long t = (b >> i) & (0xff);
		if (i != 56) printf("-");
		printf("%02X",t);
	}
	return 0;
}