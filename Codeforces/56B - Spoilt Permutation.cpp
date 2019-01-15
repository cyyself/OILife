#include <bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		b[i] = i;
	}
	int l = 0;
	int r = 0;
	for (int i=1;i<n;i++) if (a[i] > a[i+1]) {
		l = i;
		break;
	}
	if (l) {
		for (int i=l+1;i<n;i++) {
			if (a[i] < a[i+1]) {
				r = i;
				break;
			}
		}
		if (!r) r = n;
	}
	reverse(a+l,a+r+1);
	bool flag = true;
	for (int i=1;i<=n && flag;i++) if (a[i] != b[i]) flag = false;
	if (flag) printf("%d %d\n",l,r);
	else printf("0 0\n");
	return 0;
}
