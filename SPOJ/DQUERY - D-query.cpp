#include <bits/stdc++.h>
using namespace std;
int a[30005];
int pos[30005];
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
}q[200000];
int ans[200000];
int n,m;
int cnt[1000005];
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
	scanf("%d",&n);
	int bs = sqrt(n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		pos[i] = i / bs;
	}
	scanf("%d",&m);
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
	for (int i=0;i<m;i++) printf("%d\n",ans[i]);
	return 0;
}
