#include <bits/stdc++.h>
using namespace std;
bool f[105][205];
int d[105];
int n,k,l;
int getp(int t) {
	if (t <= k) return t;
	else return k - (t - k);
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d%d%d",&n,&k,&l);
		for (int i=1;i<=n;i++) scanf("%d",&d[i]);
		for (int i=1;i<=n;i++) for (int j=0;j<2*k;j++) f[i][j] = false;
		for (int j=0;j<2*k;j++) f[0][j] = true;
		bool ans = false;
		for (int i=0;i<=n-1;i++) {
			if (i) {
				for (int j=0;j<2*k;j++) if (f[i][j]) {
					int jj = (j + 1) % (2 * k);
					while (jj != j && !f[i][jj] && (d[i] + getp(jj) <= l)) {
						f[i][jj] = true;
						jj = (jj + 1) % (2 * k);
					}
				}
			}
			for (int j=0;j<2*k;j++) if (f[i][j]) {
				if (d[i+1] + getp((j+1)%(2*k)) <= l) f[i+1][(j+1)%(2*k)] = true;
			}
		}
		for (int j=0;j<2*k;j++) ans |= f[n][j];
		if (ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
