#include <bits/stdc++.h>
using namespace std;
vector <int> ans;
int main() {
	int n;
	long long k;
	scanf("%d%lld",&n,&k);
	int last = 0;
	while (last < n && last / 2 <= k) {
		k -= last / 2;
		last ++;
		ans.push_back(last);
	}
	if (k) {
		for (int i=last+2;i<last*2;i++) {
			int c = (last - (i - last) + 1) / 2;
			if (c == k) {
				ans.push_back(i);
				k -= c;
				break;
			}
		}
	}
	int fill = 1e8;
	while (ans.size() < n) {
		ans.push_back(fill);
		fill += n * 2;
	}
	if (ans.size() == n && k == 0) {
		for (auto x:ans) printf("%d ",x);
		printf("\n");
	}
	else printf("-1\n");
	return 0;
}
