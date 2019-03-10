#include <bits/stdc++.h>
using namespace std;
const long long mo = 1000000007;
char s[700];
int mt[700];
long long f[700][700][3][3];//0:不染色 1:红色 2:蓝色
void dfs(int l,int r) {
	if (r - l == 1) {
		f[l][r][0][1] = 1;
		f[l][r][1][0] = 1;
		f[l][r][0][2] = 1;
		f[l][r][2][0] = 1;
	}
	else {
		if (mt[l] == r) {
			dfs(l+1,r-1);
			for (int i=0;i<3;i++) for (int j=0;j<3;j++) {
				if (j != 1) f[l][r][0][1] += f[l+1][r-1][i][j];
				if (j != 2) f[l][r][0][2] += f[l+1][r-1][i][j];
				if (i != 1) f[l][r][1][0] += f[l+1][r-1][i][j];
				if (i != 2) f[l][r][2][0] += f[l+1][r-1][i][j];
			}
			f[l][r][0][1] %= mo;
			f[l][r][0][2] %= mo;
			f[l][r][1][0] %= mo;
			f[l][r][2][0] %= mo;
		}
		else {
			dfs(l,mt[l]);
			dfs(mt[l]+1,r);
			for (int i=0;i<3;i++) for (int j=0;j<3;j++) {
				for (int x=0;x<3;x++) for (int y=0;y<3;y++) {
					if ( (x && y && x == y) || (x && y && x == y)) continue;
					f[l][r][i][j] += (f[l][mt[l]][i][x] * f[mt[l]+1][r][y][j]) % mo;
				}
				f[l][r][i][j] %= mo;
			}
		}
	}
}
int main() {
	scanf("%s",s);
	int n = strlen(s);
	stack <int> st;
	for (int i=0;i<n;i++) {
		if (s[i] == '(') st.push(i);
		else {
			int l = st.top();
			st.pop();
			mt[i] = l;
			mt[l] = i;
		}
	}
	dfs(0,n-1);
	long long ans = 0;
	for (int i=0;i<3;i++) for (int j=0;j<3;j++) {
		ans += f[0][n-1][i][j];
		ans %= mo;
	}
	printf("%lld\n",ans);
	return 0;
}
