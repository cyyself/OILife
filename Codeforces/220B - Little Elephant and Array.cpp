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
}q[100005];
int ans[100005];
int n,m;
unordered_map <int,int> cnt;
int cur;
void add(int x) {
	if (cnt[a[x]] == a[x]) cur --;
	cnt[a[x]] ++;
	if (cnt[a[x]] == a[x]) cur ++;
}
void del(int x) {
	if (cnt[a[x]] == a[x]) cur --;
	cnt[a[x]] --;
	if (cnt[a[x]] == a[x]) cur ++;
}
int main() {
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
	for (int i=0;i<m;i++) printf("%d\n",ans[i]);
	return 0;
}
