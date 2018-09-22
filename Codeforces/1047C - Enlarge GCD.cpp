#include <bits/stdc++.h>
using namespace std;
vector <int> primes;
bool judge[4005];
void GetPrimes(int range) {
	judge[1] = true;
	for (int i=2;i<=range;i++) {
		if (!judge[i]) primes.push_back(i);
		for (auto p:primes) {
			if (i * p > range) break;
			judge[i*p] = true;
			if (i % p == 0) break;
		}
	}
}
int arr[300005];
int gcd(int a,int b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}
int ans;
map <int,int> cnt;
int n;
void work(int x) {
	for (auto prime:primes) {
		if (x == 1) break;
		if (x % prime == 0) {
			cnt[prime] ++;
			ans = min(ans,n-cnt[prime]);
			while (x % prime == 0) x /= prime;
		}
	}
	if (x > 1) {
		cnt[x] ++;
		ans = min(ans,n-cnt[x]);
	}
}
int main() {
	GetPrimes(sqrt(15000000)+0.5);
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	int base = arr[0];
	for (int i=1;i<n && base != 1;i++) base = gcd(base,arr[i]);
	ans = n;
	for (int i=0;i<n;i++) {
		work(arr[i]/base);
	}
	if (ans == n) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
