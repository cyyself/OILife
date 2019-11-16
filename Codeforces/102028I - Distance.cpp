#include <bits/stdc++.h>
using namespace std;
unsigned long long pos[100005];
unsigned long long pre[100005],suf[100005];
int n;
unsigned long long cal(int x,int l,int r) {
	return (pos[x] * l - pre[l]) + (suf[r] - (n - r + 1) * pos[x]);
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		pos[1] = 0;
		for (int i=2;i<=n;i++) {
			unsigned long long x;
			scanf("%llu",&x);
			pos[i] = pos[i-1] + x;
		}
		suf[n+1] = 0;
		pre[0] = 0;
		for (int i=1;i<=n;i++) {
			pre[i] = pre[i-1] + pos[i];
		}
		for (int i=n;i>=1;i--) {
			suf[i] = suf[i+1] + pos[i];
		}
		printf("0 %llu",pos[n]);
		int l = 1;
		int r = n;
		unsigned long long ans = pos[n];
		while (r - l > 1) {
			unsigned long long dl = cal(l+1,l,r);
			unsigned long long dr = cal(r-1,l,r);
			if (dl >= dr) {
				ans += dl;
				l ++;
			}
			else {
				ans += dr;
				r --;
			}
			printf(" %llu",ans);
		}
		printf("\n");
	}
	return 0;
}
