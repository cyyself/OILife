#include <bits/stdc++.h>
using namespace std;
long long pre[100005];
int pos[100005];
int bs;
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
}q[100000];
int n,m,k;
long long ans[100000];
long long cnt[1<<20];//保存当前每一个前缀的数量
long long cur;
void add(int x) {
	cur += cnt[pre[x] ^ k];
	cnt[pre[x]] ++;
}
void del(int x) {
	cnt[pre[x]] --;
	cur -= cnt[pre[x] ^ k];
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	bs = sqrt(n);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&pre[i]);
		pre[i] ^= pre[i-1];
		pos[i] = i / bs;
	}
	for (int i=0;i<m;i++) q[i].read(i);
	sort(q,q+m);
	int l=0,r=0;
	cnt[0] = 1;
	for (int i=0;i<m;i++) {
		while (l+1< q[i].l) del(l++);
		while (l+1> q[i].l) add(--l);
		while (r < q[i].r) add(++r);
		while (r > q[i].r) del(r--);
		ans[q[i].id] = cur;
	}
	for (int i=0;i<m;i++) printf("%lld\n",ans[i]);
	return 0;
}
