#include <bits/stdc++.h>
using namespace std;
long long cal(long long n,long long blk) {
	if (blk == n) return cal(n,blk-1ll) + 1ll;
	return 2ll * (n - 1ll) * blk - blk*(blk-1ll);
}
int getblk(int n,long long x) {
	int l = 1, r = n;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (x <= cal(n,mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		long long l,r;
		scanf("%d%lld%lld",&n,&l,&r);
		int bl = getblk(n,l);
		long long pos = bl + (l - cal(n,bl-1ll)+1ll) / 2ll;
		long long p = l;
		int stat = (l - cal(n,bl-1ll) - 1ll) & 1;
		for (int i=bl;i<=n-1 && p <= r;i++) {
			for (int j=(i==bl?pos:i+1);j<= n && p <= r;j++) {
				for (int k=( i==bl && j==pos? stat:0);k<=1 && p <= r;k++) {
					if (k == 0) printf("%d ",i);
					else printf("%d ",j);
					p ++;
				}
			}
		}
		if (p <= r) printf("1 ");
		printf("\n");
	}
	return 0;
}
