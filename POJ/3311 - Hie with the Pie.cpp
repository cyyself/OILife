#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
int f[1<<10][11];
int dis[11][11];
int main() {
	int n;
	while (scanf("%d",&n) == 1 && n) {
		for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) scanf("%d",&dis[i][j]);
		for (int k=0;k<=n;k++) for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) 
			if (dis[i][k] + dis[k][j] < dis[i][j]) dis[i][j] = dis[i][k] + dis[k][j];
		for (int s=0;s<(1<<n);s++) for (int i=1;i<=n;i++) if (s & (1 << (i - 1))) {//经过i点
			if (s == (1 << (i-1))) f[s][i] = dis[0][i];//只经过i点
			else {
				f[s][i] = INF;
				for (int j=1;j<=n;j++) 
					if (s & (1 << (j-1)) && j != i)
						f[s][i] = min(f[s^(1<<(i-1))][j]+dis[j][i],f[s][i]);
				
			}
		}
		int ans = INF;
		for (int i=1;i<=n;i++) ans = min(ans,f[(1<<n)-1][i]+dis[i][0]);
		printf("%d\n",ans);
	}
	return 0;
}