#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,p,a,b;
double f[1<<10][30];//f[i][j]表示使用车票状态为i(1为使用过)，现在在j点所需的花费
double t[10];
double dis[30][30];
int g[30][30];
const double INF = 1e9;
double DFS(int stat,int heading) {
	if (f[stat][heading] < INF) return f[stat][heading];
	if (n - __builtin_popcount(stat) < g[heading][b]) return INF;
	for (int i=0;i<n;i++) {
		if ( (stat & (1 << i)) == 0) {
			//这张票还没使用过
			for (int j=0;j<m;j++) {
				if (dis[heading][j] >= INF) continue;
				f[stat][heading] = min(f[stat][heading],dis[heading][j]/t[i] + DFS(stat|(1<<i),j));
			}
		}
	}
	return f[stat][heading];
}
int main() {
	while (scanf("%d%d%d%d%d",&n,&m,&p,&a,&b) == 5) {
		if (n == 0 && m == 0 && p == 0 && a == 0 && b == 0) break;
		a --;
		b --;
		for (int i=0;i<(1<<n);i++) {
			for (int j=0;j<m;j++) {
				f[i][j] = 1e9;
				if (j == b) f[i][j] = 0;
			}
		}
		for (int i=0;i<m;i++) for (int j=0;j<m;j++) dis[i][j] = 1e9;
		memset(g,0x3f,sizeof(g));
		//init ok
		for (int i=0;i<n;i++) scanf("%lf",&t[i]);
		while (p--) {
			int x,y;
			double z;
			scanf("%d%d%lf",&x,&y,&z);
			x --;
			y --;
			dis[x][y] = min(dis[x][y],z);
			dis[y][x] = dis[x][y];
			g[x][y] = 1;
			g[y][x] = 1;
		}
		for (int k=0;k<m;k++)
			for (int i=0;i<m;i++)
				for (int j=0;j<m;j++) g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
		float ans = DFS(0,a);//用double会WA
		if (ans >= INF) printf("Impossible\n");
		else printf("%0.5f\n",ans);
	}
	return 0;
}
