#include <bits/stdc++.h>
using namespace std;
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
char a[35],b[35];
int lena,lenb;
int f[35][35];
int g[35][35];
int main() {
	int T;
	scanf("%d",&T);
	cyy::gets(a+1);//skip \n
	for (int cas=1;cas<=T;cas++) {
		cyy::gets(a+1);
		cyy::gets(b+1);
		lena = strlen(&a[1]);
		lenb = strlen(&b[1]);
		g[0][0] = 1;
		for (int i=1;i<=lena;i++) g[i][0] = 1;
		for (int j=1;j<=lenb;j++) g[0][j] = 1;
		for (int i=1;i<=lena;i++) for (int j=1;j<=lenb;j++) {
			f[i][j] = 0;
			g[i][j] = 0;
			if (a[i] == b[j]) {
				f[i][j] = f[i-1][j-1] + 1;
				g[i][j] += g[i-1][j-1];
			}
			else {
				if (f[i][j-1] >= f[i][j]) {
					if (f[i][j-1] > f[i][j]) g[i][j] = 0;
					f[i][j] = f[i][j-1];
					g[i][j] += g[i][j-1];
				}
				if (f[i-1][j] >= f[i][j]) {
					if (f[i-1][j] > f[i][j]) g[i][j] = 0;
					f[i][j] = f[i-1][j];
					g[i][j] += g[i-1][j];
				}
			}
		}
		printf("Case #%d: %d %d\n",cas,lena+lenb-f[lena][lenb],g[lena][lenb]);
	}
	return 0;
}
