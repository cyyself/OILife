#include <bits/stdc++.h>
using namespace std;
int op[200005],p[200005],x[200005];
int a[200005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int q;
	scanf("%d",&q);
	for (int i=1;i<=q;i++) {
		scanf("%d",&op[i]);
		if (op[i] == 1) scanf("%d%d",&p[i],&x[i]);
		else scanf("%d",&x[i]);
	}
	int suf = 0;
	for (int i=q;i>=1;i--) {
		if (op[i] == 2) suf = max(suf,x[i]);
		else x[i] = max(x[i],suf);
	}
	for (int i=1;i<=n;i++) a[i] = max(suf,a[i]);
	for (int i=1;i<=q;i++) if (op[i] == 1) a[p[i]] = x[i];
	printf("%d",a[1]);
	for (int i=2;i<=n;i++) printf(" %d",a[i]);
	printf("\n");
	return 0;
}
