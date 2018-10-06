#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,L,a;
	scanf("%d%d%d",&n,&L,&a);
	int lasttime = 0;
	int ans = 0;
	for (int i=1;i<=n;i++) {
		int t,l;
		scanf("%d%d",&t,&l);
		ans += (t - lasttime) / a;
		lasttime = t + l;
	}
	ans += (L - lasttime) / a;
	printf("%d\n",ans);
	return 0;
}
