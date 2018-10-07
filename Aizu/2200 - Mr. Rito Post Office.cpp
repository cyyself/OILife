#include <bits/stdc++.h>
using namespace std;
const int INF = 0x0f0f0f0f;
int l[205][205];
int s[205][205];
int p[1005];
int f[1005][205];//f[i][j]表示在第i个位置，船停在j的状态
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2 && (n || m)) {
		memset(l,0x0f,sizeof(l));
		memset(s,0x0f,sizeof(s));
		while (m --) {
			int x,y,t;
			char sl;
			scanf("%d%d%d %c",&x,&y,&t,&sl);
			if (sl == 'L') l[x][y] = l[y][x] = min(l[y][x],t);
			else s[x][y] = s[y][x] = min(s[y][x],t);
		}
		for (int i=1;i<=n;i++) l[i][i] = s[i][i] = 0;
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++) {
					l[i][j] = min(l[i][j],l[i][k]+l[k][j]);
					s[i][j] = min(s[i][j],s[i][k]+s[k][j]);
				}
		int r;
		scanf("%d",&r);
		for (int i=0;i<r;i++) scanf("%d",&p[i]);
		memset(f,0x0f,sizeof(f));
		for (int i=1;i<=n;i++) f[0][i] = s[p[0]][i] + l[p[0]][i];
		for (int i=1;i<r;i++) {
			for (int j=1;j<=n;j++)
				for (int k=1;k<=n;k++) 
					if (k != j) f[i][j] = min(f[i][j],f[i-1][k]+l[p[i-1]][k]+s[k][j]+l[j][p[i]]);
					else f[i][j] = min(f[i][j],f[i-1][k]+l[p[i-1]][p[i]]);
		}
		int ans = INF;
		for (int i=1;i<=n;i++) ans = min(ans,f[r-1][i]);
		printf("%d\n",ans);
	}

	return 0;
}
