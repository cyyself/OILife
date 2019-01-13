#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,k;
		scanf("%d%d",&n,&k);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		int ans = 0;
		for (int i=0;i<k;i++) ans += a[n-1-i] - a[i];
		printf("%d\n",ans);
	}
	return 0;
}
