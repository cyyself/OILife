
#include <bits/stdc++.h>
using namespace std;
int tr[400005];
//两倍空间公式 {
#define node (l+r) | (l!=r)
#define mid (l+r)/2
#define lson (l+mid) | (l != mid)
#define rson (mid+1+r) | (mid+1 != r)
//两倍空间公式 }
void update(int l,int r,int x,int d) {
	if (l == r) {
		tr[node] = d;
	}
	else {
		if (x <= mid) update(l,mid,x,d);
		else update(mid+1,r,x,d);
		tr[node] = max(tr[lson],tr[rson]);
	}
}
int query(int l,int r,int L,int R) {
	if (l == L && r == R) {
		return tr[node];
	}
	else {
		int ans = 0;
		if (L <= mid) ans = max(ans,query(l,mid,L,min(R,mid)));
		if (R > mid) ans = max(ans,query(mid+1,r,max(mid+1,L),R));
		return ans;
	}
}
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		for (int i=1;i<=n;i++) {
			int x;
			scanf("%d",&x);
			update(1,n,i,x);
		}
		while (m --) {
			char o;
			int a,b;
			scanf(" %c%d%d",&o,&a,&b);
			if (o == 'U') update(1,n,a,b);
			else printf("%d\n",query(1,n,a,b));
		}
	}
	return 0;
}
