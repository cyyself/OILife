#include <bits/stdc++.h>
char T[1005];
char P[1005];
int jump[1005];
int n,m,q;
void getnext() {
	jump[1] = 0;
	int k = 0;
	for (int i=2;i<=m;i++) {
		while (k != 0 && P[i] != P[k+1]) k = jump[k];
		if (P[i] == P[k+1]) k ++;
		jump[i] = k;
	}
}
bool v[1005];
int sum[1005];
int main() {
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s%s",T+1,P+1);
	getnext();
	int k = 0;
	for (int i=1;i<=n;i++) {
		while (k != 0 && T[i] != P[k+1]) k = jump[k];
		if (T[i] == P[k+1]) k++;
		if (k == m) {
			v[i-m+1] = true;
		}
	}
	for (int i=1;i<=n;i++) sum[i] = sum[i-1] + v[i];
	while (q--) {
		int l,r;
		scanf("%d%d",&l,&r);
		r -= m - 1;
		if (r < l) printf("0\n");
		else printf("%d\n",sum[r]-sum[l-1]);
	}
	return 0;
}
