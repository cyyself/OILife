#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int ans = 0x3f3f3f3f;
	int x = 0;
	for (int i=1;i<=100;i++) {
		int cur = 0;
		for (int j=0;j<n;j++) if (abs(a[j]-i) > 1) cur += abs(a[j]-i) - 1;
		if (cur < ans) {
			ans = cur;
			x = i;
		}
	}
	printf("%d %d\n",x,ans);
	return 0;
}
