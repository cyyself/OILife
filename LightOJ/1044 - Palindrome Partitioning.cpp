#include <bits/stdc++.h>
using namespace std;
char s[1005];
bool jud[1005][1005];
int f[1005];
int len;
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		memset(jud,false,sizeof(jud));
		memset(f,0x3f,sizeof(f));
		f[0] = 0;
		scanf("%s",s);
		len = strlen(s);
		for (int i=0;i<len;i++) jud[i][i] = true;
		for (int i=1;i<len-1;i++) {//odd
			int l = i - 1;
			int r = i + 1;
			while (l >= 0 && r < len && s[l] == s[r]) {
				jud[l][r] = true;
				l --;
				r ++;
			}
		}
		for (int i=0;i<len-1;i++) {//even
			int l = i;
			int r = i + 1;
			while (l >= 0 && r < len && s[l] == s[r]) {
				jud[l][r] = true;
				l --;
				r ++;
			}
		}
		for (int i=1;i<=len;i++) 
			for (int j=1;j<=i;j++) if (jud[j-1][i-1]) f[i] = min(f[i],f[j-1]+1);
		printf("Case %d: %d\n",c,f[len]);
	}
	return 0;
}
