#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long pre[200005];
vector <long long> ls;
int n,k;
struct Seg {
#define node (l+r) | (l!=r)
#define mid (l+r)/2
#define lson (l+mid) | (l != mid)
#define rson (mid+1+r) | (mid+1 != r)
	int MAX[200005<<1];
	void clear(int n) {
		for (int i=2;i<=2*n+1;i++) MAX[i] = 0x80000000;
		update(1,n,lower_bound(ls.begin(),ls.end(),0)-ls.begin()+1,0);
	}
	int query_max(int l,int r,int L,int R) {
		if (R < L) return 0x80000000;
		if (l == L && r == R) return MAX[node];
		else {
			int ret = 0x80000000;
			if (L <= mid) ret = max(ret,query_max(l,mid,L,min(R,mid)));
			if (R > mid) ret = max(ret,query_max(mid+1,r,max(L,mid+1),R));
			return ret;
		}
	}
	void update(int l,int r,int pos,int x) {
		if (l == pos && r == pos) MAX[node] = max(x,MAX[node]);
		else {
			if (pos <= mid) update(l,mid,pos,x);
			else update(mid+1,r,pos,x);
			MAX[node] = max(MAX[lson],MAX[rson]);
		}
	}
#undef node
#undef mid
#undef lson
#undef rson
}seg;
bool check(long long x) {
	seg.clear(n+1);
	for (int i=1;i<=n;i++) {
		int lspos = lower_bound(ls.begin(),ls.end(),pre[i]-x) - ls.begin() + 1;
		int ans = seg.query_max(1,n+1,lspos,n+1) + 1;
		seg.update(1,n+1,lower_bound(ls.begin(),ls.end(),pre[i])-ls.begin()+1,ans);
	}
	return seg.query_max(1,n+1,1,n+1) >= k;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d%d",&n,&k);
		ls.clear();
		ls.push_back(0);
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			pre[i] = pre[i-1] + a[i];
			ls.push_back(pre[i]);
		};
		sort(ls.begin(),ls.end());
		ls.erase(unique(ls.begin(),ls.end()),ls.end());
		long long l = -200000000000000, r = 200000000000000,ans = -1;
		while (l <= r) {
			long long mid = (l + r) / 2;
			if (check(mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
