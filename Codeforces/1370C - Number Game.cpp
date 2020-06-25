#include <bits/stdc++.h>
using namespace std;
long long mul(long long a,long long b,long long mod){
	long long ret=0;
	while(b) {
		if(b & 1) {
			ret += a;
			ret %= mod;
		}
		a <<= 1;
		a %= mod;
		b>>=1;
	}
	return ret;
}
long long pow(long long a,long long b,long long mod) {
	long long ret=1;
	while(b) {
		if(b & 1) ret = mul(ret,a,mod);
		a = mul(a,a,mod);
		b >>= 1;
	}
	return ret;
}
bool check(long long a,long long n){
	long long x=n - 1;
	int t=0;
	while((x & 1) == 0) {
		x >>= 1;
		t++;
	}
	x = pow(a,x,n);
	long long y;
	for(int i=1;i<=t;i++) {
		y = mul(x,x,n);
		if(y == 1 && x != 1 && x != n - 1) return true;
		x=y;
	}
	if(y != 1) return true;
	return false;
}
bool Is_Prime(long long n) {
	if(n == 2) return true;
	if(n == 1 || !(n & 1)) return false;
	const int arr[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
	for(int i = 0; i < 12; i++) {
		if (arr[i] >= n) break;
		if(check(arr[i], n)) return false;
	}
	return true;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n;
		scanf("%lld",&n);
		if (n == 1) printf("FastestFinger\n");
		else if (n == 2) printf("Ashishgup\n");
		else {
			if ((n & 1) == 1) printf("Ashishgup\n");
			else {
				bool ok = false;
				for (long long i=2;i*i<=n && !ok;i++) {
					if (n % i == 0) {
						if (i & 1) ok = true;
						else if ((n / i) & 1) ok = true;
					}
				}
				if (ok) {
					if ((n/2) & 1) {
						if (Is_Prime(n/2)) printf("FastestFinger\n");
						else printf("Ashishgup\n");
					}
					else {
						printf("Ashishgup\n");
					}
				}
				else printf("FastestFinger\n");
			}
		}
	}
	return 0;
}
