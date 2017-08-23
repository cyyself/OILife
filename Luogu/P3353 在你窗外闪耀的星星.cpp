#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
	node *l;
	node *r;
	int lv;
	int rv;
	int sum;
	int lan;//懒人标记，其下子节点加上的数
	node():l(NULL),r(NULL),lv(0),rv(0),sum(0),lan(0){}
}root;
void build_tree(node *n,int l,int r) {
	n->lv = l;
	n->rv = r;
	if (l == r) return;
	int mid = (l + r) >> 1;
	n->l = new node;
	build_tree(n->l,l,mid);
	n->r = new node;
	build_tree(n->r,mid+1,r);
}
void update(node *n,int l,int r,int v) {
	n->sum += v * (r-l+1);
	if (n->lv == n->rv) return;
	if (l == n->lv && r == n->rv) n->lan += v;
	else {
		int mid = (n->lv + n->rv) >> 1;
		if (r < mid + 1) update(n->l,l,r,v);
		else if (l > mid) update(n->r,l,r,v);
		else {
			update(n->l,l,mid,v);
			update(n->r,mid+1,r,v);
		}
	}
}
int query(node *n,int l,int r) {
	if (n->lv == l && n->rv == r) return n->sum;
	else {
		int mid = (n->lv + n->rv) >> 1;
		if (r < mid + 1) return n->lan * (r-l+1) + query(n->l,l,r);
		else if (l > mid) return n->lan * (r-l+1) + query(n->r,l,r);
		else return n->lan * (r-l+1) + query(n->l,l,mid) + query(n->r,mid+1,r);
		
	}
}
int main() {
	build_tree(&root,1,100000);
	int N,W;
	scanf("%d%d",&N,&W);
	if (W == 0) {
		printf("0\n");
		return 0;
	}
	for (int i=0;i<N;i++) {
		int X,B;
		scanf("%d%d",&X,&B);
		update(&root,max(X-(W-1)/2,1),min(X+(W-1)/2,100000),B);
	}
	int ans = 0;
	for (int i=1;i<=100000;i++) ans = max(query(&root,i,i),ans);
	printf("%d\n",ans);
	return 0;
}
