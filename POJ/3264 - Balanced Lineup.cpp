#include <cstdio>
#include <algorithm>
using namespace std;
struct segtree {
	int min;
	int max;
}tr[1<<17];
int init[50005];
void push_up(int node) {
	tr[node].min = min(tr[node<<1].min,tr[node<<1|1].min);
	tr[node].max = max(tr[node<<1].max,tr[node<<1|1].max);
}
void build_tree(int node,int l,int r) {
	if (l == r) {
		tr[node].min = init[l];
		tr[node].max = init[l];
	}
	else {
		int mid = (l + r) >> 1;
		build_tree(node<<1,l,mid);
		build_tree(node<<1|1,mid+1,r);
		push_up(node);
	}
}
int query_min(int node,int l,int r,int L,int R) {
	if (l == L && r == R) {
		return tr[node].min;
	}
	else {
		int mid = (l + r) / 2;
		if (R <= mid) return query_min(node<<1,l,mid,L,R);
		if (L >= mid + 1) return query_min(node<<1|1,mid+1,r,L,R);
		return min(query_min(node<<1,l,mid,L,mid),query_min(node<<1|1,mid+1,r,mid+1,R));
	}
}
int query_max(int node,int l,int r,int L,int R) {
	if (l == L && r == R) {
		return tr[node].max;
	}
	else {
		int mid = (l + r) / 2;
		if (R <= mid) return query_max(node<<1,l,mid,L,R);
		if (L >= mid + 1) return query_max(node<<1|1,mid+1,r,L,R);
		return max(query_max(node<<1,l,mid,L,mid),query_max(node<<1|1,mid+1,r,mid+1,R));
	}
}
int main() {
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&init[i]);
	build_tree(1,1,n);
	while (q--) {
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query_max(1,1,n,l,r)-query_min(1,1,n,l,r));
	}
	return 0;
}
