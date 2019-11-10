#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int nn,m;
		scanf("%d%d",&nn,&m);
		int cnt0 = 0;
		int n = 0;
		for (int i=1;i<=nn;i++) {
			int x;
			scanf("%d",&x);
			if (x == 0) cnt0 ++;
			else a[++n] = x;
		}
		m -= cnt0;
		if (m == n) printf("Richman\n");
		else if (m < 0) printf("Impossible\n");
		else {
			long long ans = 0;
			int mm = 0x3f3f3f3f;
			for (int i=1;i<=m;i++) ans += a[i];
			for (int i=m+1;i<=n;i++) mm = min(mm,a[i]);
			ans += mm - 1;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
