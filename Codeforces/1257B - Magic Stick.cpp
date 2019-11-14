#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long x,y;
		scanf("%lld%lld",&x,&y);
		long long mx = x;
		for (int i=0;i<200 && mx < y;i++) {
			if (x % 2 == 0) x = (x / 2ll) * 3ll;
			else x = x - 1;
			mx = max(mx,x);
		}
		if (mx >= y) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
