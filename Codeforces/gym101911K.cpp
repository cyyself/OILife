#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int a[maxn];
int f[maxn];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(f,0x80,sizeof(f));
	f[0] = 0;
	for (int i=1;i<=n;i++) {
		int cnt[2] = {0,0};
		for (int j=i;j>=1;j--) {
			if (a[j] < m) cnt[0] ++;
			else cnt[1] ++;
			if (cnt[1] > cnt[0]) {
				f[i] = max(f[i],f[j-1]+1);
			}
		}
	}
	printf("%d\n",max(f[n],0));
	return 0;
}
