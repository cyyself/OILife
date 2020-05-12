#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int f[maxn];
int s[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			f[i] = 0;
			scanf("%d",&s[i]);
		}
		int ans = 1;
		for (int i=n;i>=1;i--) {
			f[i] = max(f[i],1);
			ans = max(ans,f[i]);
			if (s[1] < s[i]) f[1] = max(f[1],f[i]+1);
			for (int j=2;j*j<=i;j++) if (i % j == 0) {
				int yz1 = j;
				int yz2 = i / j;
				if (s[i/yz1] < s[i]) f[i/yz1] = max(f[i/yz1],f[i]+1);
				if (s[i/yz2] < s[i]) f[i/yz2] = max(f[i/yz2],f[i]+1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
