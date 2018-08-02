#include <bits/stdc++.h>
using std::max;
int f[10005][10005];
char s[2][10005];
int len[2];
int main() {
	while (scanf("%s%s",s[0],s[1]) == 2) {
		len[0] = strlen(s[0]);
		len[1] = strlen(s[1]);
		for (int i=0;i<=len[0];i++)
			for (int j=0;j<=len[1];j++) {
				if (i*j == 0) {
					f[i][j] = 0;
					continue;
				}
				if (s[0][i-1] == s[1][j-1]) f[i][j] = f[i-1][j-1] + 1;
				else f[i][j] = max(f[i-1][j],f[i][j-1]);
			}
		printf("%d\n",f[len[0]][len[1]]);
	}
	return 0;
}
