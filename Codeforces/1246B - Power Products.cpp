#include <bits/stdc++.h>
using namespace std;
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
long long pow(long long a,long long b,long long mod) {
	long long ret = 1;
	while(b) {
		if(b & 1) ret = mul(ret,a,mod);
		a = mul(a,a,mod);
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
	x = pow(a,x,n);
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

long long c[100005];
long long ans,cur;
map <long long,int> cnt;
void dfs(map<long long,int>::iterator it,long long val) {
	if (it == cnt.end()) {
		long long a = val;
		long long b = cur / val;
		if (a <= 100000 && b <= 100000 && c[a] && c[b]) {
			if (a == b) ans += c[a] * (c[a] - 1);
			else ans += c[a] * c[b];
		}
	}
	else {
		map<long long,int>::iterator nit = it;
		nit ++;
		for (int i=0;i<=it->second;i++) {
			dfs(nit,val);
			val *= it->first;
		}
	}
}
bool judge[100005];
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
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	if (k == 2) {
		map <long long,long long> all;
		getprime(100000);
		for (int i=1;i<=n;i++) {
			int t;
			scanf("%d",&t);
			cnt.clear();
			for (auto x:primes) {
				if (x > t) break;
				while (t % x == 0) {
					cnt[x] ++;
					t /= x;
				}
			}
			long long h = 1;
			for (auto x:cnt) if (x.second & 1) h *= x.first;
			all[h] ++;
		}
		for (auto x:all) {
			ans += x.second * (x.second-1) / 2;
		}
	}
	else {
		for (int i=1;i<=n;i++) {
			int t;
			scanf("%d",&t);
			c[t] ++;
		}
		long long x = 1;
		cur = 1;
		bool f = true;
		do {
			cnt.clear();
			factorize(cur,cnt);
			dfs(cnt.begin(),1);
			cur = 1;
			x ++;
			for (int j=1;j<=k;j++) {
				cur *= x;
				if (cur > 1e10) f = false;
			}
		}
		while (f);
		ans /= 2;
	}
	printf("%lld\n",ans);
	return 0;
}
