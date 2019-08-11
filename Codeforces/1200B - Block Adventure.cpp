#include <bits/stdc++.h>
using namespace std;
int h[105];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for (int i=1;i<=n;i++) scanf("%d",&h[i]);
		bool flag = true;
		for (int i=1;i<n && flag;i++) {
			if (h[i] < h[i+1] - k) {
				int need = h[i+1] - k - h[i];
				if (need <= m) m -= need;
				else flag = false;
			}
			else {
				m += h[i] - max(h[i+1] - k,0);
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
