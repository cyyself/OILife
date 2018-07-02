#include <bits/stdc++.h>
int n;
int a[1005];
int main() {
	scanf("%d",&n);
	int sum = 0;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if (n == 1) {
		printf("-1\n");
		return 0;
	}
	if (n == 2 && a[0] == a[1]) {
		printf("-1\n");
		return 0;
	}
	int sum2 = a[0];
	int j = 0;
	for (int i=1;i<n;i++) {
		if (sum2 != sum - sum2) break;
		j = i;
		sum2 += a[i];
	}
	printf("%d\n",j+1);
	for (int i=0;i<=j;i++) {
		if (i != 0) printf(" ");
		printf("%d",i+1); 
	}
	printf("\n");
	return 0;
}