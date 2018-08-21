#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}
void sim(long long &a,long long &b) {
	long long g = gcd(a,b);
	a /= g;
	b /= g;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int n;
		scanf("%d",&n);
		long long suc = 0;//可以走出去的个数
		long long sum = 0;
		for (int i=0;i<n;i++) {
			long long xi;
			scanf("%lld",&xi);
			if (xi >= 0) {
				suc ++;
				sum += xi;
			}
			else {
				sum += -xi;
			}
		}
		if (suc == 0) {
			printf("Case %d: inf\n",c);
			continue;
		}
		else {
			sim(sum,suc);
			printf("Case %d: %lld/%lld\n",c,sum,suc);
		}
	}
	return 0;
}
