/*
这题比较坑，存在区间l>r的数据
update的时候用异或的方式来记录这个点是否有数字比较妥
*/
#include <bits/stdc++.h>
using namespace std;
int bs;
int a[50005];
int last[50005];
int exist[50005];//这个位置有没有数字
struct query {
	int l,r,x,id;
	friend bool operator < (const query &u,const query &v) {
		if (u.l/bs != v.l/bs) return u.l/bs < v.l/bs;
		if (u.r/bs != v.r/bs) return u.r/bs < v.r/bs;
		return u.x < v.x;
	}
}q[50000];
int qcnt;
struct modify {
	int pos,last,val;
}M[50000];
int mcnt;
int ans[50000];
int cnt[1000005];
int l,r,sum;
void update(int x) {
	if (exist[x]) {
		if (--cnt[a[x]] == 0) sum --;
	}
	else {
		if (++cnt[a[x]] == 1) sum ++;
	}
	exist[x] ^= 1;
}
void change(int mi) {
	int x = M[mi].pos;
	if (exist[x]) {
		update(x);
		a[x] = M[mi].val;
		update(x);
	}
	else a[x] = M[mi].val;
}
void restore(int mi) {
	int x = M[mi].pos;
	if (exist[x]) {
		update(x);
		a[x] = M[mi].last;
		update(x);
	}
	else a[x] = M[mi].last;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	bs = sqrt(n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		last[i] = a[i];
	}
	for (int i=0;i<m;i++) {
		char o;
		int x,y;
		scanf(" %c%d%d",&o,&x,&y);
		x ++;
		if (o == 'Q') {
			q[qcnt] = (query){x,y,mcnt-1,qcnt};
			qcnt ++;
		}
		else {
			M[mcnt++] = (modify){x,last[x],y};
			last[x] = y;
		}
	}
	sort(q,q+qcnt);
	l=1,r=0;
	int mi=-1;
	for (int i=0;i<qcnt;i++) {
		while (mi < q[i].x) change(++mi);
		while (mi > q[i].x) restore(mi--);
		while (r < q[i].r) update(++r);
		while (r > q[i].r) update(r--);
		while (l < q[i].l) update(l++);
		while (l > q[i].l) update(--l);
		ans[q[i].id] = sum;
	}
	for (int i=0;i<qcnt;i++) printf("%d\n",ans[i]);
	return 0;
}
