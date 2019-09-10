#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int ten[10];
int a[200005];
//两倍空间公式 {
#define node (l+r) | (l!=r)
#define mid (l+r)/2
#define lson (l+mid) | (l != mid)
#define rson (mid+1+r) | (mid+1 != r)
//两倍空间公式 }
struct Seg {
	int pos;
	struct Node {
		int MIN[2];
		void clear() {
			memset(MIN,0x3f,sizeof(MIN));
		}
		void insert(int x) {
			if (x <= MIN[0]) {
				MIN[1] = MIN[0];
				MIN[0] = x;
			}
			else if (x <= MIN[1]) {
				MIN[1] = x;
			}
		}
	}tr[200005<<1];
	void push_up(int l,int r) {
		tr[node].clear();
		tr[node].insert(tr[lson].MIN[0]);
		tr[node].insert(tr[lson].MIN[1]);
		tr[node].insert(tr[rson].MIN[0]);
		tr[node].insert(tr[rson].MIN[1]);
	}
	void build(int l,int r) {
		if (l == r) {
			tr[node].clear();
			if ((a[l] / ten[pos]) % 10) tr[node].insert(a[l]);
		}
		else {
			build(l,mid);
			build(mid+1,r);
			push_up(l,r);
		}
	}
	void update(int l,int r,int pos,int val) {
		if (l == r) {
			tr[node].clear();
			tr[node].insert(val);
		}
		else {
			if (pos <= mid) update(l,mid,pos,val);
			else update(mid+1,r,pos,val);
			push_up(l,r);
		}
	}
	pair<int,int> query(int l,int r,int L,int R) {
		if (l == L && r == R) {
			return {tr[node].MIN[0],tr[node].MIN[1]};
		}
		else {
			Node res;
			res.clear();
			if (L <= mid) {
				pair <int,int> tmp = query(l,mid,L,min(R,mid));
				res.insert(tmp.first);
				res.insert(tmp.second);
			}
			if (R > mid) {
				pair <int,int> tmp = query(mid+1,r,max(L,mid+1),R);
				res.insert(tmp.first);
				res.insert(tmp.second);
			}
			return {res.MIN[0],res.MIN[1]};
		}
	}
}seg[10];
int main() {
	ten[0] = 1;
	for (int i=1;i<10;i++) {
		ten[i] = ten[i-1] * 10;
	}
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<10;i++) {
		seg[i].pos = i;
		seg[i].build(1,n);
	}
	while (m --) {
		int o;
		scanf("%d",&o);
		if (o == 1) {
			int i,x;
			scanf("%d%d",&i,&x);
			for (int j=0;j<10;j++) {
				if ((x / ten[j]) % 10) seg[j].update(1,n,i,x);
				else seg[j].update(1,n,i,INF);
			}
		}
		else {
			int l,r;
			scanf("%d%d",&l,&r);
			int ans = 0x7fffffff;
			for (int j=0;j<10;j++) {
				pair <int,int> res = seg[j].query(1,n,l,r);
				if (res.second == INF) continue;
				ans = min(ans,res.first+res.second);
			}
			if (ans != 0x7fffffff) printf("%d\n",ans);
			else printf("-1\n");
		}
	}
	return 0;
}
