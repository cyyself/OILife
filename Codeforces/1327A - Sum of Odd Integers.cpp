#include <bits/stdc++.h>
using namespace std;
int main() {
	vector <int> a;
	int sum = 0;
	int i = 1;
	while (sum <= 1e7) {
		sum += i;
		a.push_back(sum);
		i += 2;
	}
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,k;
		scanf("%d%d",&n,&k);
		if (k >= a.size()) {
			printf("NO\n");
			continue;
		}
		int cur = a[k - 1];
		if (cur <= n && (n - cur) % 2 == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
