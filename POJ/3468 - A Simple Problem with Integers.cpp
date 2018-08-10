#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
struct segtree {
	long long sum;
	long long lazy;
}tr[1<<18];
long long init[100005];
inline void push_up(int node) {
	tr[node].sum = tr[node<<1].sum + tr[node<<1|1].sum;
}
inline void push_down(int node,int l,int r) {
	int mid = (l + r) >> 1;
	tr[node<<1].lazy += tr[node].lazy;
	tr[node<<1].sum += (mid - l + 1) * tr[node].lazy;
	tr[node<<1|1].lazy += tr[node].lazy;
	tr[node<<1|1].sum += (r - mid) * tr[node].lazy;
	tr[node].lazy = 0;
}
void build_tree(int node,int l,int r) {
	if (l == r) {
		tr[node].sum = init[l];
	}
	else {
		int mid = (l + r) >> 1;	
		build_tree(node<<1,l,mid);
		build_tree(node<<1|1,mid+1,r);
		push_up(node);
	}
}
long long sum(int node,int l,int r,int L,int R) {//小写的l和r是当前节点区间，大写的L和R是要操作的区间
	if (l == L && r == R) return tr[node].sum;
	else {
		int mid = (l + r) >> 1;
		if (R <= mid) return (R - L + 1LL) * tr[node].lazy + sum(node<<1,l,mid,L,R);
		if (L >= mid + 1) return (R - L + 1LL) * tr[node].lazy + sum(node<<1|1,mid+1,r,L,R);
		return (R - L + 1LL) * tr[node].lazy + sum(node<<1,l,mid,L,mid) + sum(node<<1|1,mid+1,r,mid+1,R);
	}
}
void add(int node,int l,int r,int L,int R,int d) {
	tr[node].sum += (R - L + 1) * d;
	if (l == L && r == R) {
		tr[node].lazy += d;
	}
	else {
		int mid = (l + r) >> 1;
		if (R <= mid) {
			add(node<<1,l,mid,L,R,d);
		}
		else if (L >= mid + 1) {
			add(node<<1|1,mid+1,r,L,R,d);
		}
		else {
			add(node<<1,l,mid,L,mid,d);
			add(node<<1|1,mid+1,r,mid+1,R,d);
		}
	}
}
long long read() {
	long long ret = 0;
	long long f = 1;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret * f;
}
int main() {
	int n,q;
	while (scanf("%d%d",&n,&q) == 2) {
		for (int i=1;i<=n;i++) init[i] = read();
		build_tree(1,1,n);
		while (q --) {
			char cmd[10];
			scanf("%s",cmd);
			if (cmd[0] == 'Q') {
				int a = read();
				int b = read();
				printf("%lld\n",sum(1,1,n,a,b));
			}
			else {
				int a,b;
				long long c;
				a = read();
				b = read();
				c = read();
				add(1,1,n,a,b,c);
			}
		}
	}
	return 0;
}
