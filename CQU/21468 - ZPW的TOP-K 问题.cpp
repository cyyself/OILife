#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		int n,k;
		scanf("%d%d",&n,&k);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		printf("%d\n",a[n-k]);
	}
	return 0;
}
