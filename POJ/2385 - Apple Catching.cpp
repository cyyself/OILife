#include <cstdio>
#include <algorithm>
using std::max;
const int MAXT = 1005;
const int MAXW = 35;
int f[MAXT][MAXW][2];//f[i][j][k]表示前i次掉落，用j次移动，最后位置在k(编号-1)
int fall[MAXT];
int main() {
	int T,W;
	scanf("%d%d",&T,&W);
	for (int j=0;j<=W;j++) f[0][j][1] = 0x80000000;
	for (int i=1;i<=T;i++) {
		scanf("%d",&fall[i]);
		fall[i] --;
	}
	for (int i=1;i<=T;i++) {
		for (int j=0;j<=W;j++) {
			f[i][j][0] = f[i-1][j][0] + (fall[i] == 0);
			f[i][j][1] = f[i-1][j][1] + (fall[i] == 1);
			if (j != 0) {
				f[i][j][0] = max(f[i][j][0],f[i][j-1][0]);
				f[i][j][1] = max(f[i][j][1],f[i][j-1][1]);
				//考虑move情况 {
				f[i][j][0] = max(f[i][j][0],f[i-1][j-1][1]+(fall[i] == 0));
				f[i][j][1] = max(f[i][j][1],f[i-1][j-1][0]+(fall[i] == 1));
				//考虑move情况 }
			}

		}
	}
	printf("%d\n",max(f[T][W][0],f[T][W][1]));
	return 0;
}
