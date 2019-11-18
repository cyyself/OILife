#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
	int n;
	scanf("%d",&n);
	set <int> s;
	set <int> exist;
	vector <int> ans;
	bool ok = true;
	for (int i=1;i<=n && ok;i++) {
		int x;
		scanf("%d",&x);
		if (x > 0) {
			if (exist.find(x) == exist.end()) {
				s.insert(x);
				exist.insert(x);
			}
			else ok = false;
		}
		else {
			x = -x;
			if (s.find(x) != s.end()) {
				s.erase(x);
			}
			else ok = false;
			if (s.empty()) {
				exist.clear();
				ans.push_back(i);
			}
		}
	}
	ok = ok && s.empty();
	if (ok) {
		printf("%d\n",(int)ans.size());
		int last = 0;
		for (auto x:ans) {
			printf("%d ",x-last);
			last = x;
		}
		printf("\n");
	}
	else printf("-1\n");
	return 0;
}
