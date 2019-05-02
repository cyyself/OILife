#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[105];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int ans = 0;
	for (int i=0;i<n-1 && ans < INF;i++) {
		if (a[i] == 1) {
			if (a[i+1] == 1) ans = INF;
			else if (a[i+1] == 2) ans += 3 - (i >= 1 && a[i-1] == 3);
			else ans += 4;
		}
		else if (a[i] == 2) {
			if (a[i+1] == 1) ans += 3;
			else ans = INF;
		}
		else if (a[i] == 3) {
			if (a[i+1] == 1) ans += 4;
			else ans = INF;
		}
	}
	if (ans >= INF) printf("Infinite\n");
	else printf("Finite\n%d\n",ans);
	return 0;
}
