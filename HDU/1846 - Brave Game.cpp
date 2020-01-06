#include <bits/stdc++.h>
using namespace std;
bool f[1005];
int main() {
	int c;
	scanf("%d",&c);
	while (c --) {
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=0;i<=n;i++) f[i] = false;
		for (int i=0;i<=n;i++) {
			if (!f[i]) for (int j=1;j<=m && i + j <= n;j++) f[i+j] = true;
		}
		if (f[n]) printf("first\n");
		else printf("second\n");
	}
	return 0;
}
