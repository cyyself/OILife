/*
这题比较容易WA的一个地方在于一个点经过多次回到相同的位置是可能更优的
以及n==1时要输出0

参考资料：https://blog.csdn.net/lyy289065406/article/details/6689310

资料里的样例：
6 5
1 2 1 10 10
2 3 4 10 100
2 4 2 15 15
4 1 1 12 12
3 6 6 10 10
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int n;
int f[1<<10][10];//f[i][j]表示已经经过了i状态，现在在j点（所有节点编号-1）
int vis[1<<10][10];
int g[10][10][10];
int dfs(int stat,int heading) {
	if (stat & (1 << (n-1)) ) return 0;
	if (f[stat][heading] != INF) return f[stat][heading];
	for (int i=0;i<n;i++) {
		if (vis[stat|(1 << i)][i] > n) continue;
		int cost = g[heading][i][heading];
		for (int k=0;k<n;k++) if (stat & (1 << k)) cost = min(cost,g[heading][i][k]);
		if (cost == INF) continue;
		vis[stat|(1 << i)][i] ++;
		f[stat][heading] = min(f[stat][heading],cost + dfs(stat|(1 << i),i));
		vis[stat|(1 << i)][i] --;
	}
	return f[stat][heading];
}
int main() {
	int m;
	while (scanf("%d%d",&n,&m) == 2) {
		memset(g,0x3f,sizeof(g));
		memset(vis,0,sizeof(vis));
		while (m--) {
			int a,b,c,pi,ri;
			scanf("%d%d%d%d%d",&a,&b,&c,&pi,&ri);
			a --;
			b --;
			c --;
			g[a][b][a] = min(g[a][b][a],ri);
			g[a][b][c] = min(g[a][b][c],pi);
		}
		memset(f,0x3f,sizeof(f));
		int ans = dfs(0,0);
		if (n == 1) {//坑
			printf("0\n");
			continue;
		}
		if (ans == INF) printf("impossible\n");
		else printf("%d\n",ans);
	}
	return 0;
}
