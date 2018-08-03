#include <bits/stdc++.h>
using std::max;
int len;
char s[105];
int f[105][105];//f[i][j]表示第i个字符到第j个字符中回文子串的长度
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		scanf("%s",s);
		len = strlen(s);
		memset(f,0,sizeof(f));
		for (int i=1;i<=len;i++) f[i][i] = 1;//自己到自己的长度为1
		for (int d=2;d<=len;d++) {
			for (int i=1;i+d-1<=len;i++) {
				int j = i + d - 1;
				f[i][j] = max(f[i][j],f[i][j-1]);//多扩展一个可能不如不扩展
				for (int k=i;k<j;k++) if (s[k-1] == s[j-1]) f[i][j] = max(f[i][j],f[k+1][j-1]+2);
			}
		}
		printf("Case %d: %d\n",c,len-f[1][len]);
	}
	return 0;
}
