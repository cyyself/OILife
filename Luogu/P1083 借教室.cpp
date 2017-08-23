#include <bits/stdc++.h>
struct tree{
	int MIN;//单调减，就写的不那么严谨了
	int flag;//懒人标记
}tr[4000005];
int a[1000005];
inline int max(int a,int b) {
	if (a > b) return a;
	return b;
}
inline int min(int a,int b) {
	if (a < b) return a;
	return b;
}
inline void push_up(int n) {
	tr[n].MIN = min(tr[n<<1].MIN,tr[n<<1|1].MIN);
}
inline void push_down(int n) {
	tr[n<<1].flag += tr[n].flag;
	tr[n<<1|1].flag += tr[n].flag;
	tr[n<<1].MIN += tr[n].flag;
	tr[n<<1|1].MIN += tr[n].flag;
	tr[n].flag = 0;
}
void build_tree(int n,int l,int r) {
	if (r > l) {
		int mid = (l + r) >> 1;
		build_tree(n<<1,l,mid);
		build_tree(n<<1|1,mid+1,r);
		push_up(n);
	}
	else tr[n].MIN = a[l];
}
long long update(int l,int r,int d,int L,int R,int n) {//L、R为树节点区间
	if (l <= L && r >= R) {
		tr[n].MIN += d;
		tr[n].flag += d;
		return tr[n].MIN;
	}
	else {
		int mid = (L + R) >> 1;
		if (tr[n].flag != 0) push_down(n);
		if (l <= mid) update(l,r,d,L,mid,n<<1);
		if (r > mid) update(l,r,d,mid+1,R,n<<1|1);
		push_up(n);
		return tr[n].MIN;
	}
}
inline int read() {
	int sum = 0;
	int f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		sum = sum * 10 + c - '0';
		c = getchar();
	}
	return sum;
}
int main() {
	int n,m;
	n=read();
	m=read();
	for (int i=1;i<=n;i++) a[i] = read();
	build_tree(1,1,n);
	for (int i=1;i<=m;i++) {
		int d=read(),s=read(),j=read();
		if (update(s,j,-d,1,n,1) < 0) {
			printf("-1\n%d\n",i);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}