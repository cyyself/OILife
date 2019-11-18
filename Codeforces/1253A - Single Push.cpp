#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn],b[maxn],d[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		bool ans = true, exist = false;
		for (int i=1;i<=n && ans;i++) {
			d[i] = b[i] - a[i];
			if (d[i] < 0) ans = false;
			if (d[i] > 0) {
				if (d[i-1] == 0) {
					if (exist) ans = false;
				}
				else if (d[i-1] != d[i]) ans = false;
				exist = true;
			}
		}
		if (ans) puts("YES");
		else puts("NO");
	}
	return 0;
}
