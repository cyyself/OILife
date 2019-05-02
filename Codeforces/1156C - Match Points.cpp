#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
	int n,z;
	scanf("%d%d",&n,&z);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int p1 = (n-1) / 2;
	int p2 = n - 1;
	int mid = p1;
	int ans = 0;
	while (p1 >= 0 && p2 > mid) {
		if (a[p2] - a[p1] < z) p1 --;
		else {
			ans ++;
			p2 --;
			p1 --;
		}
	}
	printf("%d\n",ans);
	return 0;
}
