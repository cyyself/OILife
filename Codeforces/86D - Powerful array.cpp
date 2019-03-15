#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int pos[200005];
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
long long ans[200000];
int n,t;
long long cnt[1000005];
long long cur;
void add(int x) {
	cur += a[x] * (1LL + cnt[a[x]] * 2LL);
	cnt[a[x]] ++;
}
void del(int x) {
	cur -= a[x] * (cnt[a[x]] * 2LL - 1LL);
	cnt[a[x]] --;
}
int main() {
	scanf("%d%d",&n,&t);
	int bs = sqrt(n);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		pos[i] = i / bs;
	}
	for (int i=0;i<t;i++) q[i].read(i);
	sort(q,q+t);
	int l=1,r=0;
	for (int i=0;i<t;i++) {
		while (l < q[i].l) del(l++);
		while (l > q[i].l) add(--l);
		while (r < q[i].r) add(++r);
		while (r > q[i].r) del(r--);
		ans[q[i].id] = cur;
	}
	for (int i=0;i<t;i++) printf("%lld\n",ans[i]);
	return 0;
}
