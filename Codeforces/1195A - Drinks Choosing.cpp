#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		a[x] ++;
	}
	int ans = 0;
	int rem = (n + 1) / 2;
	for (int i=k;i>=1;i--) {
		ans += (a[i]/2)*2;
		rem -= a[i]/2;
	}
	ans += rem;
	printf("%d\n",ans);
	return 0;
}
