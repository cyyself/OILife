#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005],pre[100005],pre_cnt[100005];
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long query(int l,int r) {
	if (r < l) return 0;
	return pre[r] - pre[l-1];
}
long long query_cnt(int l,int r) {
	if (r < l) return 0;
	return pre_cnt[r] - pre_cnt[l-1];
}
long long work(int x) {
	int l = 1,r = 0;
	long long sum = 0;
	long long ans = 0;
	while (l <= n) {
		sum += a[++r];
		while (sum % x != 0) sum += a[++r];
		long long cur = inf;
		for (int i=l;i<=r;i++) {
			cur = min(cur,query_cnt(l,i-1)*i-query(l,i-1)+query(i+1,r)-query_cnt(i+1,r)*i);
		}
		ans += cur;
		l = r + 1;
		sum = 0;
	}
	return ans;
}
bool judge[100005];
vector <int> primes;
void getprime(int x) {
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
	scanf("%d",&n);
	int sum = 0;
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		sum += a[i];
		pre[i] = pre[i-1] + (a[i]==1?i:0);
		pre_cnt[i] = pre_cnt[i-1] + a[i];
	}
	getprime(sum);
	long long ans = inf;
	for (auto x:primes) {
		if (sum % x == 0) ans = min(ans,work(x));
	}
	if (ans == inf) printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}
