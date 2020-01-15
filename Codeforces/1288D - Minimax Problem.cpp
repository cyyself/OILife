#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxn = 3e5+5;
const int maxm = 8;
int mt[maxn][maxm];
int ok[1<<8];
pair<int,int> check(int x) {
	for (int i=1;i<(1<<m);i++) ok[i] = 0;
	for (int i=0;i<n;i++) {
		int s = 0;
		for (int j=0;j<m;j++) if (mt[i][j] >= x) s |= 1 << j;
		ok[s] = i + 1;
	}
	for (int i=0;i<(1<<m);i++) if (ok[i])
		for (int j=0;j<=i;j++) if (ok[j] && (i | j) == (1 << m) - 1) return {ok[i],ok[j]};
	return {-1,-1};
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&mt[i][j]);
	int l = 0,r = 1e9;
	pair<int,int> ans = {-1,-1};
	while (l <= r) {
		int mid = (l + r) >> 1;
		auto res = check(mid);
		if (res != make_pair(-1,-1)) {
			ans = res;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	printf("%d %d\n",ans.first,ans.second);
	return 0;
}
