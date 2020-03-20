#include <bits/stdc++.h>
using namespace std;
int pos[200005];
vector <int> all;
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		int t;
		scanf("%d",&t);
		pos[t] = i;
	}
	long long val = 0;
	for (int i=n;i>n-k;i--) {
		all.push_back(pos[i]);
		val += i;
	}
	sort(all.begin(),all.end());
	long long ans = 1;
	for (int i=1;i<all.size();i++) {
		ans *= all[i] - all[i-1];
		ans %= 998244353;
	}
	printf("%lld %lld\n",val,ans);
	return 0;
}
