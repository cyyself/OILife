#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
bool f[maxn];
 
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		f[n] = 1;
		for (int i=n-1;i>=1;i--) {
			if (f[i+1]) {
				if (a[i] == 1) f[i] = 0;
				else f[i] = 1;
			}
			else {
				if (a[i] == 1) f[i] = 1;
				else f[i] = 1;
			}
		}
		if (f[1]) printf("First\n");
		else printf("Second\n");
	}
	return 0;
}
