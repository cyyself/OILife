#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
long long mul(long long a,long long b,long long mod){
	long long ret=0;
	while(b) {
		if(b & 1) {
			ret += a;
			ret %= mod;
		}
		a <<= 1;
		a %= mod;
		b >>= 1;
	}
	return ret;
}
long long qpow(long long a,long long b,long long mod) {
	long long ret = 1;
	while(b) {
		if(b & 1) ret = mul(ret,a,mod);
		a = mul(a,a,mod);
		b >>= 1;
	}
	return ret;
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
bool check(long long a,long long n){
	long long x = n - 1;
	int t = 0;
	while((x & 1) == 0) {
		x >>= 1;
		t ++;
	}
	x = qpow(a,x,n);
	long long y;
	for(int i=1;i<=t;i++) {
		y = mul(x,x,n);
		if(y == 1 && x != 1 && x != n - 1) return true;
		x = y;
	}
	if(y != 1) return true;
	return false;
}
bool Miller_Rabin(long long n) {
	if(n == 2) return true;
	if(n == 1 || !(n & 1)) return false;
	const int arr[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
	for(int i = 0; i < 12; i++) {
		if (arr[i] >= n) break;
		if(check(arr[i], n)) return false;
	}
	return true;
}
long long Pollard_rho(long long n,int c) {
	long long i=1,k=2,x,y,d;
	y = x = rand() % n;
	while (true) {
		i ++;
		x = (mul(x,x,n) + c) % n;
		d = gcd(y-x,n);
		if (d > 1 && d < n) return d;
		if (y == x) break;
		if (i == k) {
			y = x;
			k <<= 1;
		}
	}
	return true;
}
void factorize(long long n,map<long long,int> &cnt,int c = 107) {
	if (n == 1) return;
	if (Miller_Rabin(n)) {
		cnt[n] ++;
		return;
	}
	long long p = n;
	while (p >= n) p = Pollard_rho(p,c--);
	factorize(p,cnt,c);
	factorize(n/p,cnt,c);
}
long long exgcd(long long a,long long b,long long &x,long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		long long ret = exgcd(b,a%b,y,x);
		y -= x * (a/b);
		return ret;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n;
		scanf("%lld",&n);
		n *= 2;
		map <long long,int> cnt;
		factorize(n,cnt);
		vector <long long> fac;
		for (auto x:cnt) fac.push_back(qpow(x.first,x.second));
		long long ans = n-1;
		for (int i=0;i<(1<<fac.size());i++) {
			long long a = 1;
			for (int j=0;j<fac.size();j++) if (i & (1 << j)) a *= fac[j];
			long long b = n / a;
			long long x,y;
			exgcd(a,b,x,y);
			y = -y;
			y = ( (y % a) + a) % a;
			if (y == 0) y = a;
			ans = min(ans,y*b);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
