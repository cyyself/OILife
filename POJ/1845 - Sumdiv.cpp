#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
using namespace std;
const long long mo = 9901;
long long qpow(long long a,long long b) {
	long long base = a % mo;
	long long ret = 1;
	while (b) {
		if (b & 1) {
			ret *= base;
			ret %= mo;
		}
		b >>= 1;
		base *= base;
		base %= mo;
	}
	return ret;
}
long long sum(long long a,long long n) {//后面存在除法，无法直接套快速幂用数列求和公式
	if (n == 0) return 1;
	if (n & 1) return (sum(a,n/2) * (1 + qpow(a,(n+1)/2)))%mo;
	else return (sum(a,n-1) + qpow(a,n))%mo;
	
}
bool judge[10005];
vector <int> primes;
inline void getprime(int x) {
	judge[1] = true;
	for (int i=2;i<=x;i++) {
		if (!judge[i]) primes.push_back(i);
		for (int j=0;j<primes.size();j++) {
			int p = primes[j];
			if (i * p > x) break;
			judge[i*p] = true;
			if (i % p == 0) break;
		}
	}
}
map <int,int> cnt;
int main() {
	getprime(10000);
	long long a,b;
	scanf("%lld%lld",&a,&b);
	for (int i=0;i<primes.size();i++) {
		int p = primes[i];
		if (p > a) break;
		while (a % p == 0) {
			a /= p;
			cnt[p] ++;
		}
	}
	if (a > 1) cnt[a] ++;
	long long ans = 1;
	for (map<int,int>::iterator it = cnt.begin();it != cnt.end();it++) {
		pair<int,int> x = *it;
		ans *= sum(x.first,x.second*b);
		ans %= mo;
	}
	printf("%lld\n",ans);
	return 0;
}
