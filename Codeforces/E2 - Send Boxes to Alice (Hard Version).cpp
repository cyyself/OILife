#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000005],b[1000005];
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long work(long long x) {
	for (int i=1;i<=n;i++) b[i] = a[i] % x;
	long long ans = 0;
	for (int i=1;i<=n;i++) {
		b[i+1] += b[i];
		b[i+1] = (b[i+1] + x) % x;
		if (b[i] <= x - b[i]) ans += b[i];
		else ans += x - b[i];
	}
	return ans;
}
namespace Pollard_Rho {
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
};
int main() {
	scanf("%d",&n);
	long long sum = 0;
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		sum += a[i];
	}
	map <long long,int> cnt;
	Pollard_Rho::factorize(sum,cnt);
	long long ans = inf;
	for (auto x:cnt) if (sum % x.first == 0) ans = min(ans,work(x.first));
	if (ans == inf) printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}
