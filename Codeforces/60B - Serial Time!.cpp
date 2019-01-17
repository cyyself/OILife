#include <bits/stdc++.h>
using namespace std;
int ans;
int k,n,m;
char s[10][10][11];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dfs(int z,int x,int y) {
	s[z][x][y] = '#';
	ans ++;
	if (z < k-1) if (s[z+1][x][y] == '.') dfs(z+1,x,y);
	for (int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (s[z][nx][ny] == '.') dfs(z,nx,ny);
	}
	if (z > 0) if (s[z-1][x][y] == '.') dfs(z-1,x,y);
}
int main() {
	scanf("%d%d%d",&k,&n,&m);
	for (int i=0;i<k;i++) for (int j=0;j<n;j++) scanf("%s",&s[i][j][0]);
	int x,y;
	scanf("%d%d",&x,&y);
	x --;
	y --;
	dfs(0,x,y);
	printf("%d\n",ans);
	return 0;
}
