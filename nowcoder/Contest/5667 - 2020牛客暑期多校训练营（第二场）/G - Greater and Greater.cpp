#include <bits/stdc++.h>
using namespace std;
const int maxn = 150005;
const int maxm = 40005;
bitset <maxm> s[maxm];
int a[maxn],b[maxm],id[maxm];
int belong[maxn];//每个Ai对应的Si
bool cmp(int x,int y) {
	return b[x] < b[y];
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=m;i++) {
		scanf("%d",&b[i]);
		id[i] = i;
	}
	sort(id,id+m+1,cmp);
	for (int i=1;i<=m;i++) {
		s[i] = s[i-1];
		s[i].set(id[i]-1);
	}
	for (int i=0;i<n;i++) {
		int l = 0, r = m;
		int p = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (b[id[mid]] <= a[i]) {
				p = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		belong[i] = p;
		assert(p != -1);
		assert(s[p+1] != s[p]);
	}
	bitset <maxm> cur;
	int ans = 0;
	for (int i=n-1;i>=0;i--) {
		cur >>= 1;
		cur.set(m-1);
		cur &= s[belong[i]];
		ans += cur[0];
	}
	printf("%d\n",ans);
	return 0;
}
