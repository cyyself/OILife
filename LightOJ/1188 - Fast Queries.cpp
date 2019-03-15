#include <bits/stdc++.h>
using namespace std;
int a[100005];
int pos[100005];
struct query {
	int l,r,id;
	void read(int _id) {
		scanf("%d%d",&l,&r);
		id = _id;
	}
	friend bool operator < (const query &a,const query &b) {
		if (pos[a.l] == pos[b.l]) return a.r < b.r;
		return pos[a.l] < pos[b.l];
	}
}q[50000];
int ans[50000];
int n,m;
int cnt[100005];
int cur;
void add(int x) {
	cnt[a[x]] ++;
	if (cnt[a[x]] == 1) cur ++;
}
void del(int x) {
	cnt[a[x]] --;
	if (cnt[a[x]] == 0) cur --;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		memset(cnt,0,sizeof(cnt));
		cur = 0;
		scanf("%d%d",&n,&m);
		int bs = sqrt(n);
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			pos[i] = i / bs;
		}
		for (int i=0;i<m;i++) q[i].read(i);
		sort(q,q+m);
		int l=1,r=0;
		for (int i=0;i<m;i++) {
			while (l < q[i].l) del(l++);
			while (l > q[i].l) add(--l);
			while (r < q[i].r) add(++r);
			while (r > q[i].r) del(r--);
			ans[q[i].id] = cur;
		}
		printf("Case %d:\n",cas);
		for (int i=0;i<m;i++) printf("%d\n",ans[i]);
	}
	return 0;
}
