#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
	int min;
	int max;
	node():min(0),max(0){}
}tree[4*1000005];
void update(int node,int l,int r,int v,int lv,int rv) {
	if (l == r) {
		tree[node].max = v;
		tree[node].min = v;
	}
	if (lv == rv) return;
	int mid = (lv + rv) >> 1;
	if (r < mid + 1) {
		update(2*node+1,l,r,v,lv,mid);
	}
	else if (l > mid) {
		update(2*node+2,l,r,v,mid+1,rv);
	}
	else {
		update(2*node+1,l,mid,v,lv,mid);
		update(2*node+2,mid+1,r,v,mid+1,rv);
	}
	tree[node].max = max(tree[2*node+1].max,tree[2*node+2].max);
	tree[node].min = min(tree[2*node+1].min,tree[2*node+2].min);
}
int query_max(int node,int l,int r,int lv,int rv) {
	if (lv == l && rv == r) return tree[node].max;
	else {
		int mid = (lv + rv) >> 1;
		if (r < mid + 1) return query_max(2*node+1,l,r,lv,mid);
		else if (l > mid) return query_max(2*node+2,l,r,mid+1,rv);
		else return max(query_max(2*node+1,l,mid,lv,mid),query_max(2*node+2,mid+1,r,mid+1,rv));
	}
}
int query_min(int node,int l,int r,int lv,int rv) {
	if (lv == l && rv == r) return tree[node].min;
	else {
		int mid = (lv + rv) >> 1;
		if (r < mid + 1) return query_min(2*node+1,l,r,lv,mid);
		else if (l > mid) return query_min(2*node+2,l,r,mid+1,rv);
		else return min(query_min(2*node+1,l,mid,lv,mid) , query_min(2*node+2,mid+1,r,mid+1,rv));
	}
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int x;
	for (int i=1;i<=n;i++) {
		scanf("%d",&x);
		update(0,i,i,x,1,n);
	}
	for (int i=k;i<=n;i++) {
		if (i != k) printf(" ");
		printf("%d",query_min(0,i-k+1,i,1,n));
	}
	printf("\n");
	for (int i=k;i<=n;i++) {
		if (i != k) printf(" ");
		printf("%d",query_max(0,i-k+1,i,1,n));
	}
	printf("\n");
	return 0;
}