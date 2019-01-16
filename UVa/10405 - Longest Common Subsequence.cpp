#include <bits/stdc++.h>
using namespace std;
char s1[1005],s2[1005];
int f[1005][1005];
namespace cyy {
	bool gets(char *s) {
		char c = getchar();
		if (c == EOF) return false;
		while (c != '\n' && c != EOF) {
			*s = c;
			s ++;
			c = getchar();
		}
		*s = '\0';
		return true;
	}
}
int main() {
	while (cyy::gets(s1+1) && cyy::gets(s2+1)) {
		memset(f,0,sizeof(f));
		int i,j;
		for (i=1;s1[i] != 0;i++)
			for (j=1;s2[j] != 0;j++) {
				if (s1[i] == s2[j]) f[i][j] = f[i-1][j-1] + 1;
				f[i][j] = max(f[i][j],max(f[i-1][j],f[i][j-1]));
			}
		printf("%d\n",f[i-1][j-1]);
	}
	return 0;
}
