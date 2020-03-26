#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long f[55][1005];
long long cal(int b,int c) {//b个球，扔c次，可以达到的最大区间
	if (b == 1) return c + 1;
	if (c == 0) return 1;
	if (~f[b][c]) return f[b][c];
	f[b][c] = 0;
	for (int i=1;i<=c;i++) f[b][c] += cal(b-1,c-i);
	f[b][c] = max(f[b][c],1ll<<min(b,c));
	return f[b][c];
}
void debug() {
	int b,m;
	while (scanf("%d%d",&b,&m) == 2) {
		printf("%lld\n",cal(b,m));
	}
}
int main() {
	memset(f,-1,sizeof(f));
	int T;
	scanf("%d",&T);
	while (T --) {
		int cas,b,m;
		scanf("%d%d%d",&cas,&b,&m);
		int l = 0, r = m;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (cal(b,mid) >= m) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		printf("%d %d\n",cas,ans);
	}
	return 0;
}
