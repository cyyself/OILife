#include <bits/stdc++.h>
using namespace std;
int f[105][105][25];
int g[105][105];
int cnt[105][105];
const int dx[4] = {-1,0,-2,0};
const int dy[4] = {0,-1,0,-2};
int getcnt(int x) {
	int cnt = 0;
	while (x % 2 == 0 && x > 0) {
		cnt ++;
		x /= 2;
	}
	return cnt;
}
int main() {
	int s,n,m,k;
	while (scanf("%d%d%d%d",&s,&n,&m,&k) == 4) {
		memset(f,0x3f,sizeof(f));
		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
			scanf("%d",&g[i][j]);
			if (g[i][j] != -1) cnt[i][j] = getcnt(g[i][j]);
		}
		for (int i=0;i<=k;i++) f[1][1][i] = getcnt(s) + cnt[1][1];
		if (g[1][1] == -1) f[1][1][0] = 0x3f3f3f3f;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) 
				for (int d=0;d<4;d++) {
					int lx = i + dx[d];
					int ly = j + dy[d];
					if (lx <= 0 || ly <= 0) continue;
					if (d >= 2 && g[lx][ly] != -1) continue;//若距离上是跳板跳过来而上个点并不是跳板
					if (g[i][j] == -1) {//这个点是跳板
						for (int p=0;p<=k;p++) {
							if (p > 0) f[i][j][p] = min(f[i][j][p],f[i][j][p-1]);
							f[i][j][p] = min(f[i][j][p],f[lx][ly][p-1]);//到这个点过p次等于在上个点的时候p-1次
						}
					}
					else {
						for (int p=0;p<=k;p++) {
							if (p > 0) f[i][j][p] = min(f[i][j][p],f[i][j][p-1]);
							f[i][j][p] = min(f[i][j][p],f[lx][ly][p]+cnt[i][j]);//由于不是跳板，加上cnt即可
						}
					}
				}
		if (f[n][m][k] == 0x3f3f3f3f) printf("-1\n");
		else if (s == 0) printf("0\n");
		else printf("%d\n",f[n][m][k]);
	}
	return 0;
}
