#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int getdis(int dx,int dy) {
	return max(abs(dx),abs(dy));
}
char s[25][25];
int dis[20][20];
int f[1<<16][20];//f[i][j]代表在i状态下（1为经过），从j点开始
vector < pair<int,int> > g;
int totnum;

int dfs(int stat,int heading) {
	if (__builtin_popcount(stat) == totnum) return dis[heading][0];
	if (f[stat][heading] != INF) return f[stat][heading];
	for (int i=1;i<totnum;i++) 
		if ( (stat & (1 << i)) == 0) f[stat][heading] = min(f[stat][heading],dfs(stat^(1<<i),i)+dis[heading][i]);
	return f[stat][heading];
}
/*
节点编号：
	x->0
	g->1->15
	共16个点
*/
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		g.clear();
		memset(dis,0x3f,sizeof(dis));
		memset(f,0x3f,sizeof(f));
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) scanf("%s",&s[i][0]);
		int s_x = -1;
		int s_y = -1;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++) {
				if (s[i][j] == 'x') {
					s_x = i;
					s_y = j;
				}
				else {
					if (s[i][j] == 'g') {
						g.push_back(make_pair(i,j));
					}
				}
			}
		totnum = g.size() + 1;
		for (int i=0;i<g.size();i++) {
			dis[0][i+1] = getdis(s_x-g[i].first,s_y-g[i].second);
			dis[i+1][0] = dis[0][i+1];
			for (int j=0;j<=i;j++) {
				dis[i+1][j+1] = getdis(g[i].first-g[j].first,g[i].second-g[j].second);
				dis[j+1][i+1] = dis[i+1][j+1];
			}
		}
		for (int k=0;k<totnum;k++)
			for (int i=0;i<totnum;i++)
				for (int j=0;j<totnum;j++)
					dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
		int ans = dfs(1,0);
		if (ans >= INF) ans = 0;//坑死人，感谢uDebug
		printf("Case %d: %d\n",c,ans);
	}
	return 0;
}
