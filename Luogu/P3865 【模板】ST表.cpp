#include <bits/stdc++.h>
using namespace std;
int n,m;
int st[100005][20];
inline int pow2(int x) {
	return 1 << x;
}
inline int rmq(int l,int r) {
	int len = log(r-l+1) / log(2);
	return max(st[l][len],st[r-pow2(len)+1][len]);
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&st[i][0]);
	for (int i=1;i<=log(n)/log(2);i++) 
		for (int j=0;j<n-pow2(i)+1;j++) st[j][i] = max(st[j][i-1],st[j+pow2(i-1)][i-1]);
	while (m--) {
		int l,r;
		scanf("%d%d",&l,&r);
		l --;
		r --;
		printf("%d\n",rmq(l,r));
	}
	return 0;
}
