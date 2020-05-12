#include <bits/stdc++.h>
using namespace std;
map <int,vector<int> > cnt;
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int t;
		scanf("%d",&t);
		map <int,int> cur;
		for (int j=2;j*j<=t;j++) while (t % j == 0) {
			cur[j] ++;
			t /= j;
		}
		if (t > 1) cur[t] ++;
		for (auto x:cur) {
			cnt[x.first].push_back(x.second);
		}
	}
	long long ans = 1;
	for (auto &x:cnt) {
		vector <int> &y = x.second;
		if (y.size() >= n - 1) {
			sort(y.begin(),y.end());
			reverse(y.begin(),y.end());
			for (int i=0;i<y[n-2];i++) ans *= x.first;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
