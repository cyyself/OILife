#include <bits/stdc++.h>
using namespace std;
bool judge[1000005];
vector <long long> primes;
inline void getprime(int x) {
	judge[1] = true;
	for (int i=2;i<=x;i++) {
		if (!judge[i]) primes.push_back(i);
		for (auto p:primes) {
			if (i * p > x) break;
			judge[i*p] = true;
			if (i % p == 0) break;
		}
	}
}
long long a,b;
int cnt(long long x) {
	int ret = 1;
	for (auto p:primes) {
		if (x < p) break;
		int cnt = 1;
		while (x % p == 0) {
			x /= p;
			cnt ++;
		}
		ret *= cnt;
	}
	if (x > 1) ret *= 2;
	return ret;
}
int main() {
	getprime(1000000);
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		scanf("%lld%lld",&a,&b);
		int ans = 0;
		if (b * b <= a) {//b的范围是假的
			ans = cnt(a);
			ans /= 2;
			for (int i=1;i<b;i++) if (a % i == 0) ans --;
		}
		printf("Case %d: %d\n",c,ans);
	}
	return 0;
}
