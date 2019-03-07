#include <bits/stdc++.h>
using namespace std;
//两倍空间公式 {
#define node (l+r) | (l!=r)
#define mid (l+r)/2
#define lson (l+mid) | (l != mid)
#define rson (mid+1+r) | (mid+1 != r)
//两倍空间公式 }
int n,k;
int a[200005];
int ma[400005];
void build_tree(int l,int r) {
	if (l == r) {
		ma[node] = a[l];
	}
	else {
		build_tree(l,mid);
		build_tree(mid+1,r);
		ma[node] = max(ma[lson],ma[rson]);
	}
}
int query_max(int l,int r,int L,int R) {
	if (l == L && r == R) {
		return ma[node];
	}
	else {
		if (L > mid) return query_max(mid+1,r,L,R);
		if (R <= mid) return query_max(l,mid,L,R);
		return max(query_max(l,mid,L,mid),query_max(mid+1,r,mid+1,R));
	}
}
bool check(int m) {
	int sum = 0;
	int len = n / m;
	for (int i=1;i<=m;i++) {
		sum += query_max(1,n,1+len*(i-1),len*i);
	}
	/*
	for (int i=1;i+m-1<=n && sum <= k;i+=m) {
		sum += query_max(1,n,i,i+m-1);
	}
	*/
	return sum > k;
}
int main() {
	while (scanf("%d%d",&n,&k) == 2 && n > 0) {
		int maxa = 0;
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			maxa = max(maxa,a[i]);
		}
		build_tree(1,n);
		int L = 1;
		int R = n;
		int ans = -1;
		while (L <= R) {
			int m = (L + R) >> 1;
			if (check(m)) {
				ans = m;
				R = m - 1;
			}
			else L = m + 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
