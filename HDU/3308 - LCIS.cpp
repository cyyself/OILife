#include <bits/stdc++.h>
using namespace std;
//两倍空间公式 {
#define node ((l+r) | (l!=r))
#define mid ((l+r)>>1)
#define lson ((l+mid) | (l != mid))
#define rson ((mid+1+r) | (mid+1 != r))
//两倍空间公式 }
struct DATA{
	int pre,suf;//左起向右连续长度，右起向左连续长度
	int ans;//最长的长度
}tr[200005];
int a[100005];
void push_up(int l,int r) {
	tr[node].ans = max(tr[lson].ans,tr[rson].ans);
	tr[node].pre = tr[lson].pre;
	tr[node].suf = tr[rson].suf;
	if (a[mid] < a[mid+1]) {
		//合并
		tr[node].ans = max(tr[node].ans,tr[lson].suf + tr[rson].pre);
		if (tr[lson].pre == (mid - l + 1)) tr[node].pre += tr[rson].pre;
		if (tr[rson].suf == (r - (mid+1) + 1)) tr[node].suf += tr[lson].suf;
	}
}
void build(int l,int r) {
	if (l == r) {
		tr[node].pre = 1;
		tr[node].suf = 1;
		tr[node].ans = 1;
	}
	else {
		build(l,mid);
		build(mid+1,r);
		push_up(l,r);
	}
}
void update(int l,int r,int x,int d) {
	if (l == r && l == x) {
		a[l] = d;
	}
	else {
		if (x <= mid) update(l,mid,x,d);
		else update(mid+1,r,x,d);
		push_up(l,r);
	}
}
int query(int l,int r,int L,int R) {
	if (l == L && r == R) {
		return tr[node].ans;
	}
	else {
		if (R <= mid) return query(l,mid,L,R);
		else if (L > mid) return query(mid+1,r,L,R);
		else {
			int ans = query(l,mid,L,mid);
			ans = max(ans,query(mid+1,r,mid+1,R));
			if (a[mid] < a[mid+1]) {
				int lsuf = min(tr[lson].suf,mid-L + 1);
				int rpre = min(tr[rson].pre,R-(mid+1)+1);
				ans = max(ans,lsuf+rpre);
			}
			return ans;
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		build(1,n);
		while (m --) {
			char c;
			int a,b;
			scanf(" %c%d%d",&c,&a,&b);
			if (c == 'Q') {
				a ++;
				b ++;
				printf("%d\n",query(1,n,a,b));
			}
			else {
				a ++;
				update(1,n,a,b);
			}
		}
	}
	return 0;
}
