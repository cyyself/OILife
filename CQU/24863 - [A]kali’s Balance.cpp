#include <bits/stdc++.h>
int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		int n;
		scanf("%d",&n);
		int ans = 0;
		while (n--) {
			int tmp;
			scanf("%d",&tmp);
			if (tmp & 1) ans ++;
			else ans --;
		}
		if (ans) printf("U\n");
		else printf("B\n");
	}
	return 0;
}
