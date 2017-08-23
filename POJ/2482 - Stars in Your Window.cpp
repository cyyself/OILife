#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node {
	int sum;
	int MAX;
	int lan;
}tree[80005];
struct line {
	long long y1;
	long long y2;
	long long x;
	int w;//亮度
	line(){}
	line(long long _y1,long long _y2,long long _x,int _w):y1(_y1),y2(_y2),x(_x),w(_w){}
}l[20005];
long long hash_table[20005];
inline bool comp(const line &a,const line &b) {
	if (a.x < b.x) return true;
	if (a.x == b.x && a.w < b.w) return true;
	return false;
}
inline void PushUp(int n,int nodeL,int nodeR) {
	if (nodeL == nodeR) tree[n].MAX = tree[n].sum;
	else tree[n].MAX = max(tree[2*n].MAX,tree[2*n+1].MAX) + tree[n].lan;
}
void update(int n,int l,int r,int v,int nodeL,int nodeR) {
	tree[n].sum += v * (r-l+1);
	if (nodeL != nodeR) {
		if (l == nodeL && r == nodeR) tree[n].lan += v;
		else {
			int mid = (nodeL + nodeR) >> 1;
			if (r <= mid) update(2*n,l,r,v,nodeL,mid);
			else if (l > mid) update(2*n+1,l,r,v,mid+1,nodeR);
			else {
				update(2*n,l,mid,v,nodeL,mid);
				update(2*n+1,mid+1,r,v,mid+1,nodeR);
			}
		}
	}
	PushUp(n,nodeL,nodeR);
}
int main() {
	int n,w,h;
	while (scanf("%d%d%d",&n,&w,&h) == 3) {
		memset(tree,0,sizeof(tree));
		for (int i=0;i<n;i++) {
			long long x,y,c;
			scanf("%lld%lld%lld",&x,&y,&c);
			x *= 2;
			y *= 2;
			hash_table[i*2] = y - h;
			hash_table[i*2+1] = y + h - 1;
			l[i*2] = line(y-h,y+h-1,x-w,c);
			l[i*2+1] = line(y-h,y+h-1,x+w,-c); 
		}
		sort(hash_table,hash_table+n*2);
		sort(l,l+n*2,comp);
		int ans = 0;
		for (int i=0;i<2*n;i++) {
			int left = lower_bound(hash_table,hash_table + 2*n,l[i].y1) - hash_table;
			int right = lower_bound(hash_table,hash_table + 2*n,l[i].y2) - hash_table;
			update(1,left,right,l[i].w,0,2*n);
			ans = max(ans,tree[1].MAX);
		}
		printf("%d\n",ans);
	}
	return 0;
}
