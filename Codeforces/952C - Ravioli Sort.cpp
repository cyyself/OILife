#include <bits/stdc++.h>
namespace cyy {
	int abs(int x) {
		if (x < 0) return -x;
		return x;
	}
}
int main() {
	int n;
	scanf("%d",&n);
	int last;
	scanf("%d",&last);
	for (int i=1;i<n;i++) {
		int cur;
		scanf("%d",&cur);
		if (cyy::abs(cur-last) >= 2) {
			printf("NO\n");
			return 0;
		}
		last = cur;
	}
	printf("YES\n");
	return 0;
}