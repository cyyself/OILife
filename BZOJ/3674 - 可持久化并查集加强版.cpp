#include <bits/stdc++.h>
using namespace std;
struct Node {
	int lc,rc;
	int sum;
}t[10000005];//数组改小了就能过，之前开80000005一直T
int ptr;
void build_tree(int rt,int l,int r) {
	if (l == r) t[rt].sum = l;
	else {
		int mid = (l + r) >> 1;
		t[rt].lc = ptr ++;
		build_tree(t[rt].lc,l,mid);
		t[rt].rc = ptr ++;
		build_tree(t[rt].rc,mid+1,r);
	}
}
int query(int rt,int l,int r,int x) {
	if (l == r) return t[rt].sum;
	else {
		int mid = (l + r) >> 1;
		if (x <= mid) return query(t[rt].lc,l,mid,x);
		else return query(t[rt].rc,mid+1,r,x);
	}
}
void update(int rt,int l,int r,int x,int d) {
	if (l == r) t[rt].sum += d;
	else {
		int mid = (l + r) >> 1;
		if (x <= mid) {
			t[ptr] = t[t[rt].lc];
			t[rt].lc = ptr ++;
			update(t[rt].lc,l,mid,x,d);
		}
		else {
			t[ptr] = t[t[rt].rc];
			t[rt].rc = ptr ++;
			update(t[rt].rc,mid+1,r,x,d);
		}
	}
}
int ts[200005];
int curtime;
int n;
void modify(int x,int val) {
	update(ts[curtime],1,n,x,val-query(ts[curtime],1,n,x));
}
pair<int,int> find2(int x) {//记录到根的深度，然后浅的合并到深的上，不然会TLE
	int res = query(ts[curtime],1,n,x);
	if (res == x) return make_pair(res,0);
	else {
		pair<int,int> ret = find2(res);
		ret.second += 1;
		return ret;
	}
}
int find(int x) {
	int res = query(ts[curtime],1,n,x);
	if (res == x) return res;
	else return find(res);
}
void uni(int x,int y) {
	pair<int,int> rx = find2(x);
	pair<int,int> ry = find2(y);
	if (rx.second >= ry.second) modify(ry.first,rx.first);
	else modify(rx.first,ry.first);
}
int read() {
	int f = 1;
	int res = 0;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res *= 10;
		res += c - '0';
		c = getchar();
	}
	return res * f;
}
int main() {
	int m;
	n = read();
	m = read();
	ts[0] = ptr ++;
	build_tree(ts[0],1,n);
	curtime = 0;
	int lastans = 0;
	while (m --) {
		curtime ++;
		int o;
		o = read();
		if (o == 1) {
			t[ptr] = t[ts[curtime-1]];
			ts[curtime] = ptr ++;
			int a=read(),b=read();
			a ^= lastans;
			b ^= lastans;
			uni(a,b);
		}
		else if (o == 2) {
			int k = read();
			k ^= lastans;
			ts[curtime] = ts[k];
		}
		else {
			ts[curtime] = ts[curtime-1];
			int a=read(),b=read();
			a ^= lastans;
			b ^= lastans;
			lastans = find(a) == find(b);
			printf("%d\n",lastans);
		}
	}
	return 0;
}
