#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int rem = k;
	int ans = 0;
	for (int i=n-1;i>=0 && m > 0;i--) {
		if (rem - a[i] < 0) {
			rem = k;
			m --;
		}
		if (m <= 0 || rem < a[i]) break;
		rem -= a[i];
		ans ++;
	}
	printf("%d\n",ans);
	return 0;
}
