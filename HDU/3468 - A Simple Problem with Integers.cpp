#include <cstdio>
#include <algorithm>
using namespace std;
//两倍空间公式 {
#define node ((l+r) | (l!=r))
#define mid ((l+r)>>1)
#define lson ((l+mid) | (l != mid))
#define rson ((mid+1+r) | (mid+1 != r))
//两倍空间公式 }
long long a[100005];
struct DATA {
	long long sum;
	long long lazy;
}tr[200005];
void build_tree(int l,int r) {
	if (l == r) {
		tr[node].sum = a[l];
		tr[node].lazy = 0;
	}
	else {
		build_tree(l,mid);
		build_tree(mid+1,r);
		tr[node].sum = tr[lson].sum + tr[rson].sum;
		tr[node].lazy = 0;
	}
}
void update(int l,int r,int L,int R,long long d) {
	tr[node].sum += (R - L + 1) * d;
	if (l == L && r == R) tr[node].lazy += d;
	else {
		if (L <= mid) update(l,mid,L,min(R,mid),d);
		if (R > mid) update(mid+1,r,max(mid+1,L),R,d);
	}
}
long long query(int l,int r,int L,int R) {
	if (l == L && r == R) {
		return tr[node].sum;
	}
	else {
		if (tr[node].lazy) {
			tr[lson].lazy += tr[node].lazy;
			tr[lson].sum += tr[node].lazy * (mid - l + 1);
			tr[rson].lazy += tr[node].lazy;
			tr[rson].sum += tr[node].lazy * (r - (mid + 1) + 1);
			tr[node].lazy = 0;
		}
		long long ans = 0;
		if (L <= mid) ans += query(l,mid,L,min(R,mid));
		if (R > mid) ans += query(mid+1,r,max(mid+1,L),R);
		return ans;
	}
}
int main() {
	int n,q;
	while(scanf("%d%d",&n,&q) == 2) {
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		build_tree(1,n);
		while (q --) {
			char o;
			int a,b;
			scanf(" %c%d%d",&o,&a,&b);
			if (o == 'C') {
				long long c;
				scanf("%lld",&c);
				update(1,n,a,b,c);
			}
			else {
				printf("%lld\n",query(1,n,a,b));
			}
		}
	}
	return 0;
}
