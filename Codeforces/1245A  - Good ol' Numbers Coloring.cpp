#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int a,b;
		scanf("%d%d",&a,&b);
		if (gcd(a,b) == 1) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}
