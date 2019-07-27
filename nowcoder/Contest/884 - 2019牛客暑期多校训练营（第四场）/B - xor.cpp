#include <bits/stdc++.h>
using namespace std;
struct LB {
	unsigned int r[32];
	LB() {for (int i=0;i<=31;i++) r[i] = 0;}
	bool insert(unsigned int x) {
		for (int i=31;i>=0;i--) if ((x >> i) & 1) {
			if (r[i] == 0) { r[i] = x; return true; }
			else x ^= r[i];
		}
		return false;
	}
	bool check(unsigned int x) {
		for (int i=31;i>=0;i--) if ((x >> i) & 1) {
			if (r[i] == 0) return false;
			x ^= r[i];
		}
		return true;
	}
	static LB intersect(const LB &a,const LB &b) {
		LB all,d,ret;
		for (int i=31;i>=0;i--) {
			all.r[i] = a.r[i];
			d.r[i] = 1 << i;
		}
		for (int i=31;i>=0;i--) if (b.r[i]) {
			unsigned int v = b.r[i],k = 0;
			bool flag = true;
			for (int j=31;j>=0;j--) if ((v >> j) & 1) {
				if (all.r[j]) { v ^= all.r[j]; k ^= d.r[j];}
				else { flag = false; all.r[j] = v; d.r[j] = k; break; }
			}
			if (flag) {
				unsigned int tmp = 0;
				for (int j=31;j>=0;j--) if ((k >> j) & 1) tmp ^= a.r[j];
				ret.insert(tmp);
			}
		}
		return ret;
	}
};

struct Seg {
	#define node (l+r) | (l!=r)
	#define mid (l+r)/2
	#define lson (l+mid) | (l != mid)
	#define rson (mid+1+r) | (mid+1 != r)
	LB tr[2*50005];
	void build(int l,int r) {
		if (l == r) {
			tr[node] = LB();
			unsigned int n;
			scanf("%u",&n);
			while (n --) {
				int x;
				scanf("%d",&x);
				tr[node].insert(x);
			}
		}
		else {
			build(l,mid);
			build(mid+1,r);
			tr[node] = LB::intersect(tr[lson],tr[rson]);
		}
	}
	bool query(int l,int r,int L,int R,unsigned int x) {
		if (l == L && r == R) return tr[node].check(x);
		else {
			bool lf = true, rf = true;
			if (L <= mid) lf &= query(l,mid,L,min(R,mid),x);
			if (R  > mid) rf &= query(mid+1,r,max(L,mid+1),R,x);
			return lf && rf;
		}
	}
}seg;
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	seg.build(1,n);
	while (m --) {
		int l,r;
		unsigned int x;
		scanf("%d%d%u",&l,&r,&x);
		if (seg.query(1,n,l,r,x)) puts("YES");
		else puts("NO");
	}
	return 0;
}