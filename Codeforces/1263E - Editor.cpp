#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
const int inf = 0x3f3f3f3f;
const int ninf = 0x80000000;
char s[maxn];
int d[maxn];
//两倍空间公式 {
#define node (l+r) | (l!=r)
#define mid (l+r)/2
#define lson (l+mid) | (l != mid)
#define rson (mid+1+r) | (mid+1 != r)
//两倍空间公式 }
struct Seg {
	int MIN,MAX;
	int lazy;
}t[maxn*2];
void push_down(int l,int r) {
	if (t[node].lazy) {
		t[lson].MIN += t[node].lazy;
		t[lson].MAX += t[node].lazy;
		t[lson].lazy += t[node].lazy;
		t[rson].MIN += t[node].lazy;
		t[rson].MAX += t[node].lazy;
		t[rson].lazy += t[node].lazy;
		t[node].lazy = 0;
	}
}
void push_up(int l,int r) {
	t[node].MIN = min(t[lson].MIN,t[rson].MIN);
	t[node].MAX = max(t[lson].MAX,t[rson].MAX);
}
void update(int l,int r,int L,int R,int x) {
	if (L <= l && r <= R) {
		t[node].MIN += x;
		t[node].MAX += x;
		t[node].lazy += x;
	}
	else {
		push_down(l,r);
		if (L <= mid) update(l,mid,L,R,x);
		if (R > mid) update(mid+1,r,L,R,x);
		push_up(l,r);
	}
}
int query_min(int l,int r,int L,int R) {
	if (L <= l && r <= R) {
		return t[node].MIN;
	}
	else {
		push_down(l,r);
		int res = inf;
		if (L <= mid) res = min(res,query_min(l,mid,L,R));
		if (R > mid) res = min(res,query_min(mid+1,r,L,R));
		return res;
	}
}
int query_max(int l,int r,int L,int R) {
	if (L <= l && r <= R) {
		return t[node].MAX;
	}
	else {
		push_down(l,r);
		int res = ninf;
		if (L <= mid) res = max(res,query_max(l,mid,L,R));
		if (R > mid) res = max(res,query_max(mid+1,r,L,R));
		return res;
	}
}
int main() {
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	int pos = 1;
	for (int i=0;i<n;i++) {
		if (s[i] == 'L') {
			if (pos >= 2) pos --;
		}
		else if (s[i] == 'R') pos ++;
		else if (s[i] == '(') {
			update(1,1e6+1,pos,1e6+1,1-d[pos]);
			d[pos] = 1;
		}
		else if (s[i] == ')') {
			update(1,1e6+1,pos,1e6+1,-1-d[pos]);
			d[pos] = -1;
		}
		else {
			update(1,1e6+1,pos,1e6+1,-d[pos]);
			d[pos] = 0;
		}
		if (query_min(1,1e6+1,1,1e6+1) == 0 && query_min(1,1e6+1,1e6+1,1e6+1) == 0) printf("%d%c",query_max(1,1e6+1,1,1e6+1),i==n-1?'\n':' ');
		else printf("-1%c",i==n-1?'\n':' ');
	}
	return 0;
}
