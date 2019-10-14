#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
char s[500005];
int a[500005];
struct Node {
	int l,r,sum;
}t[maxn*20];
int cnt;
int rt[500005];
int cpy(int src) {
	int ret = ++cnt;
	t[ret].l = t[src].l;
	t[ret].r = t[src].r;
	t[ret].sum = t[src].sum;
	return ret;
}
void push_up(int node) {
	int l = t[node].l , r = t[node].r;
	t[node].sum = t[l].sum + t[r].sum;
}
void insert(int node,int l,int r,int pos) {
	if (l == r) {
		t[node].sum ++;
	}
	else {
		int mid = (l + r) >> 1;
		if (pos <= mid) {
			t[node].l = cpy(t[node].l);
			insert(t[node].l,l,mid,pos);
		}
		else {
			t[node].r = cpy(t[node].r);
			insert(t[node].r,mid+1,r,pos);
		}
		push_up(node);
	}
}
int query(int x,int y,int l,int r,int L,int R) {
	if (l == L && r == R) return t[y].sum - t[x].sum;
	else {
		int mid = (l + r) >> 1;
		int ret = 0;
		if (L <= mid) ret += query(t[x].l,t[y].l,l,mid,L,min(mid,R));
		if (R > mid) ret += query(t[x].r,t[y].r,mid+1,r,max(mid+1,L),R);
		return ret;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		cnt = 0;
		scanf("%s",s+1);
		s[0] = '$';
		int len = strlen(s+1);
		int id = 0, mx = 0;
		for (int i=1;i<=len;i++) {
			if (i < mx) a[i] = min(a[2*id-i],mx-i);
			else a[i] = 1;
			while (s[i-a[i]] == s[i+a[i]]) a[i] ++;
			if (mx < i+a[i]) {
				id = i;
				mx = i + a[i];
			}
		}
		for (int i=1;i<=len;i++) a[i] --;
		for (int i=1;i<=len;i++) {
			if (a[i] == 0) rt[i] = rt[i-1];
			else {
				rt[i] = cpy(rt[i-1]);
				insert(rt[i],1,len,i-a[i]);
			}
		}
		long long ans = 0;
		for (int i=1;i<=len;i++) {
			if (a[i] == 0) continue;
			ans += query(rt[i],rt[i+a[i]],1,len,1,i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
