#include <cstdio>
#include <cstring>
int g[25][25];
int h,w;
int ans;
bool dfs(int dep,int x,int y) {
	if (dep == 0) return false;
	int nx,ny;
	//向上移动
	if (x > 0 && g[x-1][y] != 1) {
		nx = x;
		ny = y;
		while (nx > 0) {
			if (g[nx-1][ny] != 0) {
				if (g[nx-1][ny] == 1) {
					g[nx-1][ny] = 0;
					if (dfs(dep-1,nx,ny)) return true;
					g[nx-1][ny] = 1;
					break;
				}
				else if (g[nx-1][ny] == 3) return true;
			}
			nx --;
		}
	}

	//向下移动
	if (x < h - 1 && g[x+1][y] != 1) {
		nx = x;
		ny = y;
		while (nx < h - 1) {
			if (g[nx+1][ny] != 0) {
				if (g[nx+1][ny] == 1) {
					g[nx+1][ny] = 0;
					if (dfs(dep-1,nx,ny)) return true;
					g[nx+1][ny] = 1;
					break;
				}
				else if (g[nx+1][ny] == 3) return true;
			}
			nx ++;
		}
	}
	//向左移动
	if (y > 0 && g[x][y-1] != 1) {
		nx = x;
		ny = y;
		while (ny > 0) {
			if (g[nx][ny-1] != 0) {
				if (g[nx][ny-1] == 1) {
					g[nx][ny-1] = 0;
					if (dfs(dep-1,nx,ny)) return true;
					g[nx][ny-1] = 1;
					break;
				}
				else if (g[nx][ny-1] == 3) return true;
			}
			ny --;
		}
	}
	//向右移动
	if (y < w - 1 && g[x][y+1] != 1) {
		nx = x;
		ny = y;
		while (ny < w - 1) {
			if (g[nx][ny+1] != 0) {
				if (g[nx][ny+1] == 1) {
					g[nx][ny+1] = 0;
					if (dfs(dep-1,nx,ny)) return true;
					g[nx][ny+1] = 1;
					break;
				}
				else if (g[nx][ny+1] == 3) return true;
			}
			ny ++;
		}
	}

	return false;
}
int main() {
	while (scanf("%d%d",&w,&h) == 2 && w && h) {
		int sx = 0;
		int sy = 0;
		for (int i=0;i<h;i++) for (int j=0;j<w;j++) {
			scanf("%d",&g[i][j]);
			if (g[i][j] == 2) {
				sx = i;
				sy = j;
			}
		}
		int curdep = 1;
		while (!dfs(curdep,sx,sy)) {
			if (curdep == 10) {
				curdep = -1;
				break;
			}
			else curdep ++;
		}
		printf("%d\n",curdep);
	}
	return 0;
}
