#include <bits/stdc++.h>
using namespace std;
vector <int> ans;
int n;
int a[100005];
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=31;i>=0 && ans.size() == 0;i--) {
		int cur = 0x7fffffff;
		for (int j=0;j<n;j++) {
			if (a[j] & (1 << i)) {
				ans.push_back(a[j]);
				cur &= a[j];
			}
		}
		if (cur % (1 << i) != 0) ans.clear();
	}
	if (ans.size()) {
		printf("%lu\n",ans.size());
		bool first = true;
		for (int each:ans) {
			if (!first) printf(" ");
			else first = false;
			printf("%d",each);
		}
		printf("\n");
	}
	else {
		printf("1\n-1\n");
	}
	return 0;
}
