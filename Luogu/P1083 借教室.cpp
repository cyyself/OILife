//卡常卡掉一个点，Vijos可过
#include <bits/stdc++.h>
const int maxn = 1000005;
const int maxm = 1000005;
int a[maxn];
struct tree{
	int MIN;
	int add;//lazy flag
}tr[maxn<<2];
inline int min(int a,int b) {
	if (a > b) return b;
	return a;
}
inline void PushUp(int node) {
	tr[node].MIN = min(tr[node<<1].MIN,tr[node<<1|1].MIN);
}
inline void build_tree(int node,int L,int R) {
	if (L == R) {
		tr[node].MIN = a[L];
		return;
	}
	int mid = (L + R) >> 1;
	build_tree(node<<1,L,mid);
	build_tree(node<<1|1,mid+1,R);
	PushUp(node);
}
inline void PushDown(int node) {
	tr[node<<1].add += tr[node].add;
	tr[node<<1].MIN += tr[node].add;
	tr[node<<1|1].add += tr[node].add;
	tr[node<<1|1].MIN += tr[node].add;
	tr[node].add = 0;
}
inline int query(int node,int l,int r,int L,int R) {
	if (L == l && R == r) return tr[node].MIN;
	if (tr[node].add) PushDown(node);
	int mid = (L + R) >> 1;
	if (r <= mid) return query(node<<1,l,r,L,mid);
	if (l > mid) return query(node<<1|1,l,r,mid+1,R);
	return min(query(node<<1,l,mid,L,mid),query(node<<1|1,mid+1,r,mid+1,R));
}
inline void insert(int node,int l,int r,int L,int R,int d) {
	if (l == L && R == r) {
		tr[node].add += d;
		tr[node].MIN += d;
	}
	else {
		int mid = (L + R) >> 1;
		PushDown(node);
		if (r <= mid) insert(node<<1,l,r,L,mid,d);
		else if (l > mid) insert(node<<1|1,l,r,mid+1,R,d);
		else {
			insert(node<<1,l,mid,L,mid,d);
			insert(node<<1|1,mid+1,r,mid+1,R,d);
		}
		PushUp(node);
	}
}
inline int read() {
	int f = 1;
	int ret = 0;
	char c = getchar();
	while (!(c >= '0' && c <='9')) {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <='9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret * f;
}
int main() {
	int n,m;
	//scanf("%d%d",&n,&m);
	n = read();
	m = read();
	//for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) a[i] = read();
	build_tree(1,1,n);
	int i;
	for (i=1;i<=m;i++) {
		int d,s,t;
		d = read();
		s = read();
		t = read();
		//scanf("%d%d%d",&d,&s,&t);
		if (query(1,s,t,1,n) >= d) insert(1,s,t,1,n,-d);
		else break;
	}
	if (i == m+1) printf("0\n");
	else printf("-1\n%d\n",i);
	return 0;
}
