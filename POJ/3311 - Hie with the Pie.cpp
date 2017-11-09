/*
题意：给一张邻接矩阵，求从0号点出发经历所有点再回到0号点的最短路径
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
int g[11][11];
int f[1<<10][11];
int main() {
	int n;
	while (scanf("%d",&n) == 1 && n) {
		for (int i=0;i<=n;i++)
			for (int j=0;j<=n;j++)
				scanf("%d",&g[i][j]);
		//floyd
		for (int k=0;k<=n;k++)
			for (int i=0;i<=n;i++)
				for (int j=0;j<=n;j++) 
					g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
		/*
		f[k][i]表示在k状态下，最后一次经过节点为i时的最短路径
		状态k是经过的点的状态压缩，k&(i-1)表示是否经过i号点
		由于0号点不在我们的考虑范围之内，所以以k的第0位表示1号点
		*/
		for (int k=0;k<(1<<n);k++)
			for (int i=1;i<=n;i++) 
				if (k & (1 << (i-1)) ) {//该状态是否经过i号点
					if (k == (1 << (i-1))) f[k][i] = g[0][i];//该状态首次经过i号点，便距离为从0号节点出发
					else {
						f[k][i] = inf;
						for (int j=1;j<=n;j++) {
							if (j != i && k & (1 << (j-1))) {//找一个点，看看从这个点过来是否更优
								f[k][i] = min(f[k][i],f[k^(1 << (i-1))][j]+g[j][i]);
							}
						}
					}
				}
		int ans = inf;
		for (int i=1;i<=n;i++) ans = min(ans,f[(1<<n)-1][i]+g[i][0]);
		printf("%d\n",ans);
	}
	return 0;
}
