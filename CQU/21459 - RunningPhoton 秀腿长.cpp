#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
int a[1000005];
int n;
int main() {
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++) {
		scanf("%d",&n);
		int ans = inf;
		int d = 0;
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			d = max(d,a[i]-a[i-1]);
		}
		for (int i=2;i<=n-1;i++) ans = min(ans,a[i+1]-a[i-1]);
		printf("Case %d: %d\n",t,max(ans,d));
	}
	return 0;
}
