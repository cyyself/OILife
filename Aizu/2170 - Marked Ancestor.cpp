#include <bits/stdc++.h>
using namespace std;
int  f[100005];
bool m[100005];
int main() {
	int n,q;
	m[1] = true;
	while (scanf("%d%d",&n,&q) == 2 && n) {
		for (int i=2;i<=n;i++) {
			scanf("%d",&f[i]);
			m[i] = false;
		}
		long long ans = 0;
		while (q --) {
			char o;
			int v;
			scanf(" %c%d",&o,&v);
			if (o == 'M') m[v] = true;
			else {
				while (!m[v]) v = f[v];
				ans += v;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
