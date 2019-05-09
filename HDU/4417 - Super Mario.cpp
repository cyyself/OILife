#include <bits/stdc++.h>
using namespace std;
struct Node {
	long long sum;
	long long lazy;
	int lc,rc;
}arr[2500005];
int ptr;
long long query(int node,int L,int R,int l,int r) {
	if (l == L && r == R) return arr[node].sum;
	else {
		int mid = (l + r) / 2;
		long long res = 0;
		if (L <= mid) res += query(arr[node].lc,L,min(mid,R),l,mid);
		if (R > mid) res += query(arr[node].rc,max(mid+1,L),R,mid+1,r);
		return res + arr[node].lazy * (R - L + 1);
	}
}
void insert(int node,int L,int R,long long d,int l,int r) {
	arr[node].sum += d * (R - L + 1);
	if (l == L && r == R) arr[node].lazy += d;
	else {
		int mid = (l + r) / 2;
		if (L <= mid) {
			arr[ptr] = arr[arr[node].lc];
			arr[node].lc = ptr ++;
			insert(arr[node].lc,L,min(mid,R),d,l,mid);
		}
		if (R > mid) {
			arr[ptr] = arr[arr[node].rc];
			arr[node].rc = ptr ++;
			insert(arr[node].rc,max(mid+1,L),R,d,mid+1,r);
		}
	}
}
int ls[100005];
int lscnt;
int a[100005];
int rt[100005];
int main() {
	int T;
	scanf("%d",&T);
	int cas = 0;
	while (T --) {
		ptr = 0;
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			ls[i] = a[i-1];
		}
		sort(ls,ls+n);
		lscnt = unique(ls,ls+n) - ls;
		rt[0] = ptr ++;
		for (int i=1;i<=n;i++) {
			rt[i] = ptr ++;
			arr[rt[i]] = arr[rt[i-1]];
			int rank = lower_bound(ls,ls+lscnt,a[i]) - ls + 1;
			insert(rt[i],rank,rank,1,1,lscnt);
		}
		printf("Case %d:\n",++cas);
		while (m --) {
			int l,r,h;
			scanf("%d%d%d",&l,&r,&h);
			l ++;
			r ++;
			int hrank = upper_bound(ls,ls+lscnt,h) - ls;
			if (hrank < 1) puts("0");
			else {
				int ans = query(rt[r],1,hrank,1,lscnt) - query(rt[l-1],1,hrank,1,lscnt);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
