#include <bits/stdc++.h>
using namespace std;
char g[10][11];
bool forbid_x[10];
bool forbid_y[10];
int main() {
	int r,c;
	scanf("%d%d",&r,&c);
	for (int i=0;i<r;i++) {
		scanf("%s",&g[i][0]);
		for (int j=0;j<c;j++) if (g[i][j] == 'S') {
			forbid_x[i] = true;
			forbid_y[j] = true;
		}
	}
	int ans = 0;
	for (int i=0;i<r;i++) {
		if (!forbid_x[i]) {
			for (int j=0;j<c;j++) if (g[i][j] == '.') {
				ans ++;
				g[i][j] = 'S';
			}
		}
	}
	for (int i=0;i<c;i++) {
		if (!forbid_y[i]) {
			for (int j=0;j<r;j++) if (g[j][i] == '.') {
				ans ++;
				g[j][i] = 'S';
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
