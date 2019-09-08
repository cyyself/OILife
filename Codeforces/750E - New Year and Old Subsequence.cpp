#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
//两倍空间公式 {
#define node (l+r) | (l!=r)
#define mid (l+r)/2
#define lson (l+mid) | (l != mid)
#define rson (mid+1+r) | (mid+1 != r)
//两倍空间公式 }
int n, q;
char s[N];
struct Node {
	int m[5][5];
	void clear() {
		memset(m,0x3f,sizeof(m));
	}
}tr[N*2];
void push_up(int l,int r) {
	tr[node].clear();
	for (int i=0;i<5;i++) 
		for (int j=0;j<5;j++)
			for (int k=0;k<5;k++) tr[node].m[i][j] = min(tr[node].m[i][j],tr[lson].m[i][k]+tr[rson].m[k][j]);
}
void build(int l,int r) {
	if (l == r) {
		tr[node].clear();
		for (int i = 0; i < 5; ++i) tr[node].m[i][i] = 0;
		if (s[l] == '2') tr[node].m[0][1] = 0, tr[node].m[0][0] = 1;
		if (s[l] == '0') tr[node].m[1][2] = 0, tr[node].m[1][1] = 1;
		if (s[l] == '1') tr[node].m[2][3] = 0, tr[node].m[2][2] = 1;
		if (s[l] == '6') tr[node].m[3][3] = 1, tr[node].m[4][4] = 1;
		if (s[l] == '7') tr[node].m[3][4] = 0, tr[node].m[3][3] = 1;
		return;
	}
	build(l,mid);
	build(mid+1, r);
	push_up(l,r);
}
Node query(int L,int R,int l,int r) {
	if (L <= l && r <= R) return tr[node];
	if (R <= mid) return query(L,R,l,mid);
	else if (L > mid) return query(L,R,mid+1,r);
	else {
		Node ql = query(L,R,l,mid);
		Node qr = query(L,R,mid+1,r);
		Node ret;
		ret.clear();
		for (int i=0;i<5;i++) 
			for (int j=0;j<5;j++)
				for (int k=0;k<5;k++) ret.m[i][j] = min(ret.m[i][j],ql.m[i][k]+qr.m[k][j]);
		return ret;
	}
}
int main() {
	scanf("%d%d%s",&n,&q,s+1);
	build(1,n);
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = query(l, r, 1, n).m[0][4];
		if(ans == INF) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}
