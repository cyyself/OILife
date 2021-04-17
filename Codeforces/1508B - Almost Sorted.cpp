#include <bits/stdc++.h>
using namespace std;
//两倍空间公式 {
#define node (l+r) | (l!=r)
#define mid (l+r)/2
#define lson (l+mid) | (l != mid)
#define rson (mid+1+r) | (mid+1 != r)
//两倍空间公式 }
int sum[200005];
void build_tree(int l,int r) {
	if (l == r) {
		sum[node] = 1;
	}
	else {
		build_tree(l,mid);
		build_tree(mid+1,r);
		sum[node] = sum[lson] + sum[rson];
	}
}
void update(int x,int l,int r,int d) {
	if (l == x && r == x) {
		sum[node] += d;
	}
	else {
		if (x <= mid) update(x,l,mid,d);
		else update(x,mid+1,r,d);
		sum[node] = sum[lson] + sum[rson];
	}
}
int query_kpos(int l,int r,int k) {
	if (l == r) return l;
	else {
		if (k <= sum[lson]) return query_kpos(l,mid,k);
		else return query_kpos(mid+1,r,k-sum[lson]);
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n,k;
		scanf("%lld%lld",&n,&k);
		k --;
		if (n <= 61 && 1ll << (n - 1) <= k) {
			printf("-1\n");
			continue;
		}
		else {
			build_tree(1,n);
			for (int i=1;i<=n;i++) {
				int kth = 1;
				int bit_pos = n - i - 1;
				while (bit_pos <= 61 && (k & (1ll << bit_pos))) {
					kth ++;
					bit_pos --;
				}
				//printf("kth=%d\n",kth);
				int value = query_kpos(1,n,kth);
				if (kth != 1) k -= (1ll << (n - i - 1));
				printf("%d",value);
				update(value,1,n,-1);
				if (i == n) printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
