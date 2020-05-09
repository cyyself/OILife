#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e+5;
int a[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		int ans = unique(a,a+n) - a;
		printf("%d\n",ans);
	}
	return 0;
}
