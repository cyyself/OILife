#include <bits/stdc++.h>
int main() {
	int t;
	scanf("%d",&t);
	while (t --) {
		int n;
		scanf("%d",&n);
		int sum = 0;
		for (int i=0;i<n;i++) {
			int t;
			scanf("%d",&t);
			sum += t;
		}
		printf("%d\n\n",sum);
	}
	return 0;
}
