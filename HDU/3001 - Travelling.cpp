#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int tri[11];
int dig[60000][11];
int g[11][11];
int f[60000][11];
int main() {
	tri[0] = 1;
	for (int i=1;i<=10;i++) tri[i] = 3 * tri [i-1];
	for (int i=0;i<tri[10];i++) {
		int t = i;
		for (int j=0;j<10;j++) {
			dig[i][j] = t % 3;
			t /= 3;
		}
	}
	//三进制终于做完了
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		memset(g,0x3f,sizeof(g));
		memset(f,0x3f,sizeof(f));
		for (int i=0;i<m;i++) {
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			g[u-1][v-1] = min(g[u-1][v-1],w);
			g[v-1][u-1] = min(g[v-1][u-1],w);
		}
		for (int i=0;i<n;i++) f[tri[i]][i] = 0;//只有本身的情况
		int ans = INF;
		for (int i=0;i<tri[n];i++) {
			bool allexist = true;
			//因为只要有一个就可以成立，所以不能像二进制一样在最后状态取min
			//考虑到时间的优化，这里每次做到全部存在的状态时就计算ans
			for (int j=0;j<n;j++) {
				if (dig[i][j] == 0) allexist = false;
				if (f[i][j] != INF) 
					for (int k=0;k<n;k++) 
						if (g[j][k] != INF && dig[i][k] < 2) 
							f[i+tri[k]][k] = min(f[i][j]+g[j][k],f[i+tri[k]][k]);
			}
			if (allexist) for (int j=0;j<n;j++) ans = min(ans,f[i][j]);
		}
		if (ans == INF) ans = -1;
		printf("%d\n",ans);
	}
	return 0;
}