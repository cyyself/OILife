#include <bits/stdc++.h>
using namespace std;
//两倍空间公式 {
#define node (l+r) | (l!=r)
#define mid (l+r)/2
#define lson (l+mid) | (l != mid)
#define rson (mid+1+r) | (mid+1 != r)
//两倍空间公式 }
int a[1005];
int n;
struct segtree {
	int min;
}tr[2005];
void build_tree(int l,int r) {
	if (l == r) {
		tr[node].min = l;
	}
	else {
		build_tree(l,mid);
		build_tree(mid+1,r);
		if (a[tr[lson].min] <= a[tr[rson].min]) tr[node].min = tr[lson].min;
		else tr[node].min = tr[rson].min;
	}
}
int query_min(int l,int r,int L,int R) {
	if (l == L && r == R) {
		return tr[node].min;
	}
	else {
		if (L > mid) return query_min(mid+1,r,L,R);
		if (R <= mid) return query_min(l,mid,L,R);
		int ll = query_min(l,mid,L,mid);
		int rr = query_min(mid+1,r,mid+1,R);
		if (a[ll] <= a[rr]) return ll;
		else return rr;
	}
}
bool read() {
	char c = getchar();
	n = 0;
	while (!(c >= '0' && c <= '9')) {
		if (c == EOF) return false;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		a[++n] = c - '0';
		c = getchar();
	}
	return true;
}
char out[1005];
int main() {
	while (read()) {
		int m;
		scanf("%d",&m);
		build_tree(1,n);
		int rem = m + 1;
		int s = 1;
		int ptr = 0;
		bool non_zero = false;
		while (rem <= n) {
			int x = query_min(1,n,s,rem);
			if (a[x] != 0) non_zero = true;
			if (non_zero) out[ptr++] = '0' + a[x];
			s = x + 1;
			rem ++;
		}
		if (ptr ==0) out[ptr++] = '0';
		out[ptr] = '\0';
		printf("%s\n",out);
	}
	return 0;
}
