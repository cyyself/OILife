#include <bits/stdc++.h>
using std::max;
char s[2][35];
int f[35][35];
long long cnt[75][35][35];
int len[2];
int getlcs() {
	for (int i=0;i<=len[0];i++)
		for (int j=0;j<=len[1];j++) {
			if (i * j == 0) f[i][j] = 0;
			else {
				if (s[0][i-1] == s[1][j-1]) f[i][j] = f[i-1][j-1] + 1;
				else f[i][j] = max(f[i-1][j],f[i][j-1]);
			}
		}
	return f[len[0]][len[1]];
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		memset(cnt,0,sizeof(cnt));
		scanf("%s",s[0]);
		scanf("%s",s[1]);
		len[0] = strlen(s[0]);
		len[1] = strlen(s[1]);
		int ans = len[0] + len[1] - getlcs();
		cnt[0][0][0] = 1;
		for (int k=0;k<=ans;k++)
			for (int i=0;i<=len[0];i++)
				for (int j=0;j<=len[1];j++) {
					if (cnt[k][i][j]) {
						if (s[0][i] == s[1][j]) cnt[k+1][i+1][j+1] += cnt[k][i][j];
						else {
							cnt[k+1][i][j+1] += cnt[k][i][j];
							cnt[k+1][i+1][j] += cnt[k][i][j];
						}
					}
				}
		printf("Case %d: %d %lld\n",c,ans,cnt[ans][len[0]][len[1]]);
	}
	return 0;
}
