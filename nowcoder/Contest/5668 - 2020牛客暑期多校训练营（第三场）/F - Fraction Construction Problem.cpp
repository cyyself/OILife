#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
const int maxb = 2e6+5;
bool judge[maxb];
vector <long long> primes;
long long pre[maxb];
inline void getprime(int x) {
	judge[1] = true;
	for (int i=2;i<=x;i++) {
		if (!judge[i]) primes.push_back(i);
		for (auto p:primes) {
			if (i * p > x) break;
			judge[i*p] = true;
			pre[i*p] = p;
			if (i % p == 0) break;
		}
	}
}
long long qpow(long long a,long long b) {
	long long ret = 1;
	while(b) {
		if(b & 1) ret *= a;
		a *= a;
		b >>= 1;
	}
	return ret;
}
long long exgcd(long long a,long long b,long long &x,long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		long long t = exgcd(b,a%b,y,x);
		y -= x*(a/b);
		return t;
	}
}
int main() {
	getprime(2e6);
	int T;
	scanf("%d",&T);
	while (T --) {
		long long a,b;
		scanf("%lld%lld",&a,&b);
		long long g = gcd(a,b);
		if (g == 1) {
			map <long long,int> cnt;
			long long bb = b;
			while (pre[bb]) {
				cnt[pre[bb]] ++;
				bb /= pre[bb];
			}
			cnt[bb] ++;
			if (cnt.size() <= 1) printf("-1 -1 -1 -1\n");
			else {
				long long d = qpow(cnt.begin()->first,cnt.begin()->second);
				long long f = b / d;
				long long c,e;
				exgcd(f,d,c,e);
				long long dis = max(0ll,max((-c+d-1)/d,(e+f-1)/f));
				c += dis * d;
				e -= dis * f;
				c *= a;
				e *= a;
				printf("%lld %lld %lld %lld\n",c,d,-e,f);
			}
		}
		else {
			printf("%lld %lld %lld %lld\n",2*a/g,b/g,a/g,b/g);
		}
	}
	return 0;
}
