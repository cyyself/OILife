#include <bits/stdc++.h>
int a[110];
int n;
int main() {
	scanf("%d",&n);
	int avg = 0;
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		avg += a[i];
	}
	avg /= n;
	int ans = 0;
	for (int i=1;i<=n-1;i++) {
		if (a[i] == avg) continue;
		else {
			ans ++;
			a[i+1] += a[i] - avg;
		}
	}
	printf("%d\n",ans);
	return 0;
}
