#include <bits/stdc++.h>
using std::max;
char s[65];
int len;
long long f[65][65];
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		scanf("%s",s+1);
		len = strlen(s+1);
		memset(f,0,sizeof(f));
		for (int i=1;i<=len;i++) f[i][i] = 1;
		for (int d=2;d<=len;d++) {
			for (int i=1;i+d-1<=len;i++) {
				int j = i + d - 1;
				f[i][j] = f[i][j-1] + f[i+1][j] - f[i+1][j-1];//容斥
				if (s[i] == s[j]) f[i][j] += f[i+1][j-1] + 1;//相当于[i+1][j-1]范围的子串都可以前后加相同的字符，所以增加了方案数，然后s[i]、s[j]又可以组合成一个回文串，所以再+1
			}
		}
		printf("Case %d: %lld\n",c,f[1][len]);
	}
	return 0;
}
