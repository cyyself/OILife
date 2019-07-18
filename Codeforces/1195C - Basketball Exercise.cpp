#include <bits/stdc++.h>
using namespace std;
long long h[100005][2];
long long f[100005][2];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&h[i][0]);
	for (int i=1;i<=n;i++) scanf("%lld",&h[i][1]);
	for (int i=1;i<=n;i++) {
		f[i][0] = max(f[i-1][0],f[i-1][1]+h[i][0]);
		f[i][1] = max(f[i-1][1],f[i-1][0]+h[i][1]);
	}
	printf("%lld\n",max(f[n][0],f[n][1]));
	return 0;
}
