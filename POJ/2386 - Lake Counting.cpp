#include <cstdio>
char g[105][105];
const int dx[8] = {1,1,1,0,0,-1,-1,-1};
const int dy[8] = {1,0,-1,1,-1,1,0,-1};
int n,m;
void dfs(int x,int y) {
	g[x][y] = '.';
	for (int i=0;i<8;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (g[nx][ny] == 'W') dfs(nx,ny);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	int ans = 0;
	for (int i=0;i<n;i++) scanf("%s",&g[i][0]);
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (g[i][j] == 'W') {
		dfs(i,j);
		ans ++;
	}
	printf("%d\n",ans);
	return 0;
}
