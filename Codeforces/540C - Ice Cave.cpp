#include <bits/stdc++.h>
using namespace std;
bool g[505][505];
char s[505];
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
int n,m;
int tx,ty;
bool ans = false;
int step = 0;
int limit = 100000000;
void dfs(int x,int y) {
	step ++;
	g[x][y] = false;
	vector <pair<int,int> > v;
	for (int i=0;i<4 && !ans && step < limit;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
		if (!g[nx][ny] && nx == tx && ny == ty) ans = true;
		if (!g[nx][ny]) continue;
		dfs(nx,ny);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%s",&s[1]);
		for (int j=1;j<=m;j++) {
			if (s[j] == '.') g[i][j] = 1;
		}
	}
	int sx,sy;
	scanf("%d%d",&sx,&sy);
	scanf("%d%d",&tx,&ty);
	dfs(sx,sy);
	if (ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}
