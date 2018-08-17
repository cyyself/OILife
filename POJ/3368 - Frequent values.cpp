#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct segtree {
	int lcnt,mcnt,rcnt;
	int lval   ,  rval;
}tr[1<<18];
int init[100005];
void build_tree(int n,int l,int r) {
	if (l == r) {
		tr[n].lval = tr[n].rval = init[l];
		tr[n].lcnt = tr[n].mcnt = tr[n].rcnt = 1;
	}
	else {
		int mid = (l + r) >> 1;
		int lson = n<<1;
		int rson = n<<1|1;
		build_tree(lson,l,mid);
		build_tree(rson,mid+1,r);
		//处理区间两端
		tr[n].lval = tr[lson].lval;
		tr[n].lcnt = tr[lson].lcnt;
		tr[n].rval = tr[rson].rval;
		tr[n].rcnt = tr[rson].rcnt;
		//区间合并
		if (tr[lson].lval == tr[rson].lval) tr[n].lcnt = tr[lson].lcnt + tr[rson].lcnt;
		if (tr[rson].rval == tr[lson].rval) tr[n].rcnt = tr[rson].rcnt + tr[lson].rcnt;
		//处理区间最大值
		if (tr[lson].rval == tr[rson].lval) tr[n].mcnt = tr[lson].rcnt + tr[rson].lcnt;
		else tr[n].mcnt = 0;
		tr[n].mcnt = max(tr[n].mcnt,max(tr[lson].mcnt,tr[rson].mcnt));
		tr[n].mcnt = max(tr[n].mcnt,max(tr[n].lcnt,tr[n].rcnt));
	}
}
int query(int n,int l,int r,int L,int R) {
	if (L == l && R == r) return tr[n].mcnt;
	else {
		int mid = (l + r) >> 1;
		int lson = n<<1;
		int rson = n<<1|1;
		if (R <= mid) return query(lson,l,mid,L,R);
		if (L >= mid + 1) return query(rson,mid+1,r,L,R);
		int ans = 0;
		if (tr[lson].rval == tr[rson].lval) ans = min(mid-L+1,tr[lson].rcnt) + min(R-mid,tr[rson].lcnt);
		ans = max(ans,max(query(lson,l,mid,L,mid),query(rson,mid+1,r,mid+1,R)));
		return ans;
	}
}
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		for (int i=1;i<=n;i++) scanf("%d",&init[i]);
		build_tree(1,1,n);
		while (m --) {
			int i,j;
			scanf("%d%d",&i,&j);
			printf("%d\n",query(1,1,n,i,j));
		}
	}
	return 0;
}
