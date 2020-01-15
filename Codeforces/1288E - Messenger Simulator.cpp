#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5+5;

int p_min[maxn],p_max[maxn],last[maxn];
int seq[maxn];
namespace segtree {
	#define mid ((l+r) >> 1)
	struct Node {
		int sum;
		Node *l,*r;
	}tr[maxn*30];
	int nodecnt;
	Node* nodecpy(Node *src) {
		Node *ret = &tr[++nodecnt];
		ret->l = src->l;
		ret->r = src->r;
		ret->sum = src->sum;
		return ret;
	}
	void push_up(Node *node) {
		node->sum = node->l->sum + node->r->sum;
	}
	void insert(Node *node,int l,int r,int x,int d) {
		if (l == r) {
			node->sum += d;
		}
		else {
			if (x <= mid) {
				node->l = nodecpy(node->l);
				insert(node->l,l,mid,x,d);
			}
			else {
				node->r = nodecpy(node->r);
				insert(node->r,mid+1,r,x,d);
			}
			push_up(node);
		}
	}
	int query(Node *node,int l,int r,int L,int R) {
		if (R < L) return 0;
		if (L <= l && r <= R) return node->sum;
		else {
			int res = 0;
			if (L <= mid) res += query(node->l,l,mid,L,R);
			if (R > mid) res += query(node->r,mid+1,r,L,R);
			return res;
		}
	}
	#undef mid
};
using namespace segtree;
Node* rt[maxn];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		seq[i] = n - i + 1;
		p_min[i] = i;
		p_max[i] = i;
	}
	for (int i=n+1;i<=n+m;i++) {
		scanf("%d",&seq[i]);
		p_min[seq[i]] = 1;
	}
	tr[0].l = &tr[0];
	tr[0].r = &tr[0];
	rt[0] = &tr[0];
	for (int i=1;i<=n+m;i++) {
		rt[i] = nodecpy(rt[i-1]);
		if (!last[seq[i]]) {
			insert(rt[i],1,n+m,i,1);
			last[seq[i]] = i;
		}
		else {
			insert(rt[i],1,n+m,last[seq[i]],-1);
			insert(rt[i],1,n+m,i,1);
			p_max[seq[i]] = max(p_max[seq[i]],query(rt[i-1],1,n+m,last[seq[i]]+1,i-1)+1);
			//printf("(debug)%d\n",query(rt[i-1],1,n+m,last[seq[i]]+1,i-1));
			last[seq[i]] = i;
		}
	}
	for (int i=1;i<=n;i++) {
		if (last[i]) {
			p_max[i] = max(p_max[i],query(rt[n+m],1,n+m,last[i]+1,n+m)+1);
			//printf("(debug)%d %d\n",i,query(rt[n+m],1,n+m,last[i]+1,n+m));
		}
	}
	for (int i=1;i<=n;i++) printf("%d %d\n",p_min[i],p_max[i]);
	return 0;
}
