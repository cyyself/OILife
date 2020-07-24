#include <bits/stdc++.h>
using namespace std;
char s[4000005];
bool edge[405][405];
int last[160005];
int w[405][405];
int lastcnt;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) scanf("%d",&w[i][j]);
		while (q --) {
			lastcnt ++;
			int x0,y0;
			scanf("%d%d%s",&x0,&y0,s);
			int xmin = x0, xmax = x0;
			int ymin = y0, ymax = y0;
			int x = x0, y = y0;
			for (int i=0;s[i];i++) {
				if (s[i] == 'L') x --;
				else if (s[i] == 'R') x ++;
				else if (s[i] == 'D') y --;
				else if (s[i] == 'U') y ++;
				else assert(false);
				xmin = min(xmin,x);
				ymin = min(ymin,y);
				xmax = max(xmax,x);
				ymax = max(ymax,y);
			}
			xmin ++;
			ymin ++;
			for (int i=xmin;i<=xmax;i++)
				for (int j=ymin;j<=ymax;j++) edge[i][j] = false;
			x = x0;
			y = y0;
			for (int i=0;s[i];i++) {
				if (s[i] == 'L') {
					edge[x][y+1] ^= 1;
					x --;
				}
				else if (s[i] == 'R') {
					x ++;
					edge[x][y+1] ^= 1;
				}
				else if (s[i] == 'D') y --;
				else if (s[i] == 'U') y ++;
				else assert(false);
			}
			int ans = 0;
			for (int i=xmin;i<=xmax;i++) {
				bool in_poly = false;
				for (int j=ymin;j<=ymax;j++) {
					in_poly ^= edge[i][j];
					edge[i][j] = false;
					if (in_poly) {
						if (last[w[i][j]] != lastcnt) {
							last[w[i][j]] = lastcnt;
							ans ++;
						}
					}
				}
				edge[i][ymax+1] = false;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
