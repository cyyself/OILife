#include <bits/stdc++.h>
using namespace std;
inline long long lowbit(long long x) {
	return x & (-x);
}
long long b[200005];
unordered_map <long long,long long> cnt;
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&b[i]);
		cnt[lowbit(b[i])]++;
	}
	long long ans = 0;
	long long bit;
	for (auto x:cnt) if (x.second > ans) {
		ans = x.second;
		bit = x.first;
	}
	printf("%lld\n",n-ans);
	for (int i=1;i<=n;i++) {
		if (lowbit(b[i]) == bit) continue;
		printf("%lld ",b[i]);
	}
	return 0;
}
