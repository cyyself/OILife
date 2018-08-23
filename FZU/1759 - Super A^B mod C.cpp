#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
bool NotPrime[500005];
vector <long long> Prime;
void GetPrime(long long x) {
	memset(NotPrime,false,sizeof(NotPrime));
	NotPrime[1] = true;
	for (long long i=2;i<=x;i++) {
		if (!NotPrime[i]) Prime.push_back(i);
		for (unsigned long j=0;j<Prime.size();j++) {
			long long p = Prime[j];
			if (i * p > x) break;
			NotPrime[i*p] = true;
			if (i % p == 0) break;
		}
	}
}
long long getphi(long long x) {
	long long ret = x;
	/*
	被注释掉的这段不知道为啥错，感觉和底下那段是等价的
	for (unsigned long i=0;i<Prime.size() && Prime[i] * Prime[i] <= x;i++) {
		long long cur = Prime[i];
		if (x % cur == 0) {
			ret /= cur;
			ret *= (cur-1);
			while (x % cur == 0) x /= cur;
		}
	}
	*/
	// {
	for (long long i=2;i*i<=x;i++) {
		if (!NotPrime[i]) {
			if (x % i == 0) {
				ret /= i;
				ret *= (i-1);
				while (x % i == 0) x /= i;
			}
		}
	}
	// }
	if (x > 1) {
		ret /= x;
		ret *= (x - 1);
	}
	return ret;
}
long long qpow(long long a,long long b,long long mod) {
	long long base = a;
	long long ret = 1;
	while (b) {
		if (b & 1) {
			ret *= base;
			ret %= mod;
		}
		base *= base;
		base %= mod;
		b >>= 1;
	}
	return ret % mod;
}
char s[1000005];
int main() {
	GetPrime(500000);
	long long a,c;
	while (cin >> a >> s >> c) {
		long long phi = getphi(c);
		int len = strlen(s);
		long long b = 0;
		for (int i=0;i<len;i++) {
			b *= 10;
			b += s[i] - '0';
			b %= phi;
		}
		if (b < phi) cout << qpow(a,b,c) << endl;
		else cout << qpow(a,b+phi,c) << endl;
	}
	return 0;
}
