#include <bits/stdc++.h>
using namespace std;
int y[50005];
int rain[50005];
//两倍空间公式 {
#define node (l+r) | (l!=r)
#define mid (l+r)/2
#define lson (l+mid) | (l != mid)
#define rson (mid+1+r) | (mid+1 != r)
//两倍空间公式 }
struct segtree {
	int max;
}tr[100005];
void build_tree(int l,int r) {
	if (l == r) {
		tr[node].max = rain[l];
	}
	else {
		build_tree(l,mid);
		build_tree(mid+1,r);
		tr[node].max = max(tr[lson].max,tr[rson].max);
	}
}
int query_max(int l,int r,int L,int R) {
	if (R < L) return 0;
	if (l == L && r == R) {
		return tr[node].max;
	}
	else {
		if (L > mid) return query_max(mid+1,r,L,R);
		if (R <= mid) return query_max(l,mid,L,R);
		return max(query_max(l,mid,L,mid),query_max(mid+1,r,mid+1,R));
	}
}
map <int,int> mem;
int n;
int check(int a,int b) {
	int L = upper_bound(y+1,y+1+n,a) - y;
	int R = lower_bound(y+1,y+1+n,b) - y;
	int lmax = query_max(1,n,L,R-1);
	int LR = rain[mem[a]];
	int RR = rain[mem[b]];
	if (RR != 0 && lmax >= RR) return 0;
	if (LR != 0 && (lmax >= LR || RR > LR)) return 0;
	if (LR == 0 || RR == 0) return 2;
	if (R - (L-1) != b - a) return 2;
	return 1;
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d%d",&y[i],&rain[i]);
		mem[y[i]] = i;
	}
	build_tree(1,n);
	int m;
	scanf("%d",&m);
	while (m --) {
		int a,b;
		scanf("%d%d",&a,&b);
		int v = check(a,b);
		if (v == 0) puts("false");
		else if (v == 1) puts("true");
		else puts("maybe");
	}
	return 0;
}
