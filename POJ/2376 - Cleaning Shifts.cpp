#include <cstdio>
#include <algorithm>
using namespace std;
struct DATA {
	int l,r;
	friend bool operator < (const DATA &a,const DATA &b) {
		if (a.l < b.l) return true;
		if (a.l == b.l && a.r < b.r) return true;
		return false;
	}
}d[25000];
int main() {
	int n,T;
	scanf("%d%d",&n,&T);
	for (int i=0;i<n;i++) scanf("%d%d",&d[i].l,&d[i].r);
	sort(d,d+n);
	d[n].l = 0x7fffffff;
	int last = 0;
	int tmp = 0;
	int ans = 0;
	bool flag = false;
	for (int i=0;i<n;i++) {
		if (d[i].l <= last + 1) {
			if (tmp < d[i].r) {
				tmp = d[i].r;
				flag = true;
			}
			if (d[i+1].l > last + 1 && flag) {
				last = tmp;
				ans ++;
				flag = 0;
			}
		}
	}
	if (last == T) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
