#include <bits/stdc++.h>
int a[105];
int b[105];
int ans[105][105];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int sum_a = 0;
	int sum_b = 0;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		sum_a ^= a[i];
	}
	for (int i=0;i<m;i++) {
		scanf("%d",&b[i]);
		sum_b ^= b[i];
	}
	if (sum_a == sum_b) {
		printf("YES\n");
		int sum_tmp = 0;
		for (int i=1;i<n;i++) {
			ans[i][0] = a[i];
			sum_tmp ^= a[i];
		}
		for (int i=1;i<m;i++) ans[0][i] = b[i];
		ans[0][0] = sum_tmp ^ b[0];
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				if (j != 0) printf(" ");
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
	else printf("NO\n");
	return 0;
}
