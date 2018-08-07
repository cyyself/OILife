#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int b[10005];
int nxt[10005];
void getnext() {
	nxt[1] = 0;
	int k = 0;
	for (int i=2;i<=m;i++) {
		while (k != 0 && b[i] != b[k+1]) k = nxt[k];
		if (b[i] == b[k+1]) k++;
		nxt[i] = k;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=m;i++) scanf("%d",&b[i]);
		getnext();
		int k = 0;
		int ans = -1;
		for (int i=1;i<=n;i++) {
			while (k != 0 && a[i] != b[k+1]) k = nxt[k];
			if (a[i] == b[k+1]) k++;
			if (k == m) {
				ans = i - m + 1;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
