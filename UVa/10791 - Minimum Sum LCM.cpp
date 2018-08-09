#include <bits/stdc++.h>
using namespace std;
map <long long,int> cnt;
int main() {
	long long n;
	int c = 1;
	while (scanf("%lld",&n) == 1) {
		if (n == 0) break;
		cnt.clear();
		long long tmp = n;
		for (int i=2;i<=sqrt(n) && tmp;i++) {
			while (tmp % i == 0 && tmp) {
				cnt[i] ++;
				tmp /= i;
			}
		}
		if (tmp > 1) cnt[tmp] ++;
		long long ans = 0;
		if (cnt.size() <= 1) ans = n + 1;
		else for (pair<long long,int> each:cnt) ans += pow(each.first,each.second);
		printf("Case %d: %lld\n",c++,ans);
	}
	return 0;
}
