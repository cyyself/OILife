#include <bits/stdc++.h>
using namespace std;
struct segtree {
	int cnt;
	int lazy;
	long long sum[8];
}tr[1 << 18];
long long init[100005];
inline void push_up(int node) {
	for (int i=0;i<8;i++) tr[node].sum[i] = tr[node<<1].sum[i] + tr[node<<1|1].sum[i];
}
void build_tree(int node,int l,int r) {
	tr[node].cnt = 0;
	tr[node].lazy = 0;
	if (l == r) {
		tr[node].sum[0] = init[l];
		for (int i=1;i<8;i++) tr[node].sum[i] = sqrt((double)tr[node].sum[i-1]);
	}
	else {
		int mid = (l + r) >> 1;
		build_tree(node<<1,l,mid);
		build_tree(node<<1|1,mid+1,r);
		push_up(node);
	}
}
inline void push_down(int node) {
	tr[node<<1].lazy += tr[node].lazy;
	tr[node<<1|1].lazy += tr[node].lazy;
	tr[node<<1].cnt += tr[node].lazy;
	tr[node<<1|1].cnt += tr[node].lazy;
	tr[node].lazy = 0;
}
void insert(int node,int l,int r,int L,int R) {
	if (l == L && r == R) {
		tr[node].cnt ++;
		tr[node].lazy ++;
	}
	else {
		int mid = (l + r) >> 1;
		if (tr[node].lazy) push_down(node);
		if (R <= mid) insert(node<<1,l,mid,L,R);
		else if (L >= mid + 1) insert(node<<1|1,mid+1,r,L,R);
		else {
			insert( node<<1 , l ,mid, L ,mid);
			insert(node<<1|1,mid+1,r,mid+1,R);
		}
	}
}
long long query(int node,int l,int r,int L,int R) {
	if (l == L && r == R) {
		if (tr[node].cnt >= 8) tr[node].cnt = 7;
		if (tr[node].cnt == 7 || l == r) return tr[node].sum[tr[node].cnt];
		else {
			if (tr[node].lazy) push_down(node);
			int mid = (l + r) >> 1;
			return query(node<<1,l,mid,L,mid) + query(node<<1|1,mid+1,r,mid+1,R);
		}
	}
	else {
		int mid = (l + r) >> 1;
		if (tr[node].lazy) push_down(node);
		if (R <= mid) {
			return query(node<<1,l,mid,L,R);
		}
		else {
			if (L >= mid +1) {
				return query(node<<1|1,mid+1,r,L,R);
			}
			else {
				return query(node<<1,l,mid,L,mid) + query(node<<1|1,mid+1,r,mid+1,R);
			}
		}
	}
}
int main() {
	int n;
	int c = 1;
	while (scanf("%d",&n) == 1) {
		for (int i=1;i<=n;i++) scanf("%lld",&init[i]);
		build_tree(1,1,n);
		printf("Case #%d:\n",c++);
		int m;
		scanf("%d",&m);
		while (m --) {
			int t,x,y;
			scanf("%d%d%d",&t,&x,&y);
			if (x > y) swap(x,y);
			if (t == 0) {
				insert(1,1,n,x,y);
			}
			else {
				printf("%lld\n",query(1,1,n,x,y));
			}
		}
		printf("\n");
	}
	return 0;
}
