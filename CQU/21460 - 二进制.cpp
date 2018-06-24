#include <bits/stdc++.h>
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		int n;
		scanf("%d",&n);
		int ans = 0;
		for (int i=31;i>=0;i--) if (n & (1 << i)) ans ++;
		printf("%d\n",ans);
	}
	return 0;
}
