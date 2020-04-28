#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
const long long mo = 998244353;
char s[maxn],t[maxn];
long long f[maxn][maxn];
int main() {
	scanf("%s%s",s+1,t+1);
	int n = strlen(s+1), m = strlen(t+1);
	for (int i=1;i<=m;i++) f[i][i] = (s[1] == t[i]) * 2;
	for (int i=m+1;i<=n;i++) f[i][i] = 2;
	for (int len=2;len<=n;len++) {
		for (int l=1;l+len-1<=n;l++) {
			int r = l + len - 1;
			f[l][r] += (s[len]==t[l] || l > m) * f[l+1][r];
			f[l][r] += (s[len]==t[r] || r > m) * f[l][r-1];
			f[l][r] %= mo;
		}
	}
	long long ans = 0;
	for (int i=m;i<=n;i++) {
		ans += f[1][i];
		ans %= mo;
	}
	printf("%lld\n",ans);
	return 0;
}
