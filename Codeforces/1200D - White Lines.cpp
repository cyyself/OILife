#include <bits/stdc++.h>
using namespace std;
char g[2005][2005];
int cntx[2005],cnty[2005],prex[2005],prey[2005];
bool l[2005][2005],r[2005][2005],u[2005][2005],d[2005][2005];
int prel[2005][2005],preu[2005][2005];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		scanf("%s",&g[i][1]);
		for (int j=1;j<=n;j++) {
			if (g[i][j] == 'W') {
				cntx[i] ++;
				cnty[j] ++;
			}
		}
	}
	int o_ans = 0;
	for (int i=1;i<=n;i++) {
		prex[i] = prex[i-1];
		if (cntx[i] == n) {
			o_ans ++;
			prex[i] ++;
		}
	}
	for (int i=1;i<=n;i++) {
		prey[i] = prey[i-1];
		if (cnty[i] == n) {
			o_ans ++;
			prey[i] ++;
		}
	}
	for (int i=1;i<=n;i++) {
		l[i][0] = true;
		for (int j=1;j<=n;j++) {
			if (g[i][j] == 'B') break;
			l[i][j] = true;
		}
	}
	for (int i=1;i<=n;i++) {
		r[i][n+1] = true;
		for (int j=n;j>=1;j--) {
			if (g[i][j] == 'B') break;
			r[i][j] = true;
		}
	}
	for (int j=1;j<=n;j++) {
		u[0][j] = true;
		for (int i=1;i<=n;i++) {
			if (g[i][j] == 'B') break;
			u[i][j] = true;
		}
	}
	for (int j=1;j<=n;j++) {
		d[n+1][j] = true;
		for (int i=n;i>=1;i--) {
			if (g[i][j] == 'B') break;
			d[i][j] = true;
		}
	}
	for (int j=1;j+k-1<=n;j++) {
		int rr = j + k - 1;
		for (int i=1;i<=n;i++) {
			prel[i][j] = prel[i-1][j] + (l[i][j-1] && r[i][rr+1]);
		}
	}
	for (int i=1;i+k-1<=n;i++) {
		int dd = i + k - 1;
		for (int j=1;j<=n;j++) {
			preu[i][j] = preu[i][j-1] + (u[i-1][j] && d[dd+1][j]);
		}
	}
	int ans = o_ans;
	for (int uu=1;uu+k-1<=n;uu++) {
		int dd = uu + k - 1;
		for (int ll=1;ll+k-1<=n;ll++) {
			int rr = ll+k-1;
			int dx = prel[dd][ll] - prel[uu-1][ll] - (prex[dd] - prex[uu-1]);
			int dy = preu[uu][rr] - preu[uu][ll-1] - (prey[rr] - prey[ll-1]);
			ans = max(ans,o_ans+dx+dy);
		}
	}
	printf("%d\n",ans);
	return 0;
}
