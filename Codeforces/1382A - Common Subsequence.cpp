#include <bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=m;i++) scanf("%d",&b[i]);
		bool ok = false;
		for (int i=1;i<=n && !ok;i++) for (int j=1;j<=m && !ok;j++) if (a[i] == b[j]) {
			printf("YES\n%d %d\n",1,a[i]);
			ok = true;
		}
		if (!ok) printf("NO\n");
	}
	return 0;
}
