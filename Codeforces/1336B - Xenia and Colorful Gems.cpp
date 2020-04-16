#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
long long arr[3*maxn];
long long r[maxn],g[maxn],b[maxn];
long long cal(long long i,long long j,long long k) {
	return (i - j) * (i - j) + (j - k) * (j - k) + (k - i) * (k - i);
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int rn,gn,bn;
		scanf("%d%d%d",&rn,&gn,&bn);
		for (int i=1;i<=rn;i++) {
			scanf("%lld",&r[i]);
			arr[i] = r[i];
		}
		for (int i=1;i<=gn;i++) {
			scanf("%lld",&g[i]);
			arr[rn+i] = g[i];
		}
		for (int i=1;i<=bn;i++) {
			scanf("%lld",&b[i]);
			arr[rn+gn+i] = b[i];
		}
		sort(r+1,r+1+rn);
		sort(g+1,g+1+gn);
		sort(b+1,b+1+bn);
		sort(arr+1,arr+1+rn+gn+bn);
		long long ans = 0x3f3f3f3f3f3f3f3f;
		int pr = 1, pg = 1, pb = 1;
		for (int p=1;p<=rn+gn+bn;p++) {
			int base = arr[p];
			while (pr < rn && abs(r[pr+1]-base) <= abs(r[pr] - base)) pr ++;
			while (pg < gn && abs(g[pg+1]-base) <= abs(g[pg] - base)) pg ++;
			while (pb < bn && abs(b[pb+1]-base) <= abs(b[pb] - base)) pb ++;
			long long rs[2] = {r[pr],0}, rscnt = 1;
			long long gs[2] = {g[pg],0}, gscnt = 1;
			long long bs[2] = {b[pb],0}, bscnt = 1;
			if (rs[0] < base && pr < rn) rs[rscnt++] = r[pr+1];
			if (rs[0] > base && pr > 1) rs[rscnt++] = r[pr-1];
			if (gs[0] < base && pg < gn) gs[gscnt++] = g[pg+1];
			if (gs[0] > base && pg > 1) gs[gscnt++] = g[pg-1];
			if (bs[0] < base && pb < bn) bs[bscnt++] = b[pb+1];
			if (bs[0] > base && pb > 1) bs[bscnt++] = b[pb-1];
			for (int i=0;i<rscnt;i++) for (int j=0;j<gscnt;j++) for (int k=0;k<bscnt;k++) {
				ans = min(ans,cal(rs[i],gs[j],bs[k]));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
