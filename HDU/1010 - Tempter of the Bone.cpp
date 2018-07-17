#include <bits/stdc++.h>
bool vis[10][10];
char s[10][10];
int n,m,t;
int s_x,s_y;
int d_x,d_y;
bool ans;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
void dfs(int dep,int x,int y) {
	int disdiff = dep - abs(d_x-x) - abs(d_y-y);
	if (disdiff < 0 || disdiff % 2 == 1) return;
	if (dep == 0) {
		if (s[x][y] == 'D') ans = true;
	}
	else {
		for (int i=0;i<4 && !ans;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (s[nx][ny] != '.' && s[nx][ny] != 'D') continue;
			if (vis[nx][ny]) continue;
			vis[nx][ny] = true;
			dfs(dep-1,nx,ny);
			vis[nx][ny] = false;
		}
	}
}
int main() {
	while (scanf("%d%d%d",&n,&m,&t) == 3) {
		memset(vis,false,sizeof(vis));
		ans = false;
		if (n * m * t == 0) break;
		for (int i=0;i<n;i++) scanf("%s",&s[i][0]);
		s_x = -1;
		s_y = -1;
		d_x = -1;
		d_y = -1;
		int wall = 0;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++) {
				switch(s[i][j]) {
					case 'S':
						s_x = i;
						s_y = j;
						break;
					case 'D':
						d_x = i;
						d_y = j;
						break;
					case 'X':
						wall ++;
				}
			}
		if ( (s_x == -1 && s_y == -1) || (d_x == -1 && d_y == -1) ) {
			printf("NO\n");
		}
		else {
			vis[s_x][s_y] = true;
			dfs(t,s_x,s_y);
			if (ans) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}