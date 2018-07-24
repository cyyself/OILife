#include <bits/stdc++.h>
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		int sum = 0;
		for (int i=0;i<n;i++) {
			int t;
			scanf("%d",&t);
			sum += t;
		}
		printf("%d\n",sum);
	}
	return 0;
}
