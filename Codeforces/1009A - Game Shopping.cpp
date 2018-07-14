#include <bits/stdc++.h>
int n,m;
int c[1005];
int a[1005];
int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&c[i]);
	for (int i=0;i<m;i++) scanf("%d",&a[i]);
	int j = 0;
	int ans = 0;
	for (int i=0;i<n && j < m;i++) {
		if (c[i] <= a[j]) {
			j ++;
			ans ++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
