#include <bits/stdc++.h>
using namespace std;
int a[1005];
bool vis[1005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int ans = 0;
	int cnt = 0;
	while (cnt < n) {
		bool first = true;
		int last;
		for (int i=0;i<n;i++) {
			if (vis[i]) continue;
			if (first) {
				last = a[i];
				first = false;
				vis[i] = true;
				cnt ++;
			}
			else {
				if (a[i] > last) {
					ans ++;
					vis[i] = true;
					cnt ++;
					last = a[i];
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
