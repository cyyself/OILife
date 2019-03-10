#include <bits/stdc++.h>
using namespace std;
char a[102];
char b[102];
int f[101][101];
int g[101];
int main() {
	while (scanf("%s%s",a+1,b+1) == 2) {
		memset(f,0x3f,sizeof(f));
		int n = strlen(a+1);
		for (int i=1;i<=n;i++) f[i][i] = 1;
		for (int len=2;len<=n;len++) for (int i=1;i+len-1<=n;i++) {
			int j = i + len - 1;
			for (int mid=i;mid<j;mid++) f[i][j] = min(f[i][j],f[i][mid]+f[mid+1][j] - (b[i] == b[j]));
		}
		for (int i=1;i<=n;i++) {
			g[i] = f[1][i];
			if (a[i] == b[i]) g[i] = g[i-1];
			else for (int j=1;j<i;j++) g[i] = min(g[i],g[j]+f[j+1][i]);
		}
		printf("%d\n",g[n]);
	}
	return 0;
}
