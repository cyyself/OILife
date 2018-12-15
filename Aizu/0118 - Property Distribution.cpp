#include <bits/stdc++.h>
using namespace std;
char g[105][105];
bool vis[105][105];
const int dx[4] = {1,0,0,-1};
const int dy[4] = {0,1,-1,0};
int h,w;
void dfs(int x,int y) {
	vis[x][y] = true;
	for (int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
		if (vis[nx][ny]) continue;
		if (g[nx][ny] != g[x][y]) continue;
		dfs(nx,ny);
	}
}
int main() {
	while (scanf("%d%d",&h,&w) == 2 && h) {
		for (int i=0;i<h;i++) scanf("%s",&g[i][0]);
		memset(vis,false,sizeof(vis));
		int cnt = 0;
		for (int i=0;i<h;i++) for (int j=0;j<w;j++) if (!vis[i][j]) {
			dfs(i,j);
			cnt ++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
