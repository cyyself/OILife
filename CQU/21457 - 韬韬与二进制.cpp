#include <bits/stdc++.h>
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		long long x;
		scanf("%lld",&x);
		for (int i=31;i>=0;i--) {
			if (x & (1LL << i)) printf("1");
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}
