#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
int a[25];
int main() {
	int n;
	scanf("%d",&n);
	int ans = inf;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		for (int j=0;j<i;j++) ans = min(ans,abs(a[i]-a[j]));
	}
	printf("%d\n",ans);
	return 0;
}