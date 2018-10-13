#include <cstdio>
#include <map>
using namespace std;
map <int,bool> h;
int g[5][5];
int cnt;
const int dx[] = {1,0,0,-1};
const int dy[] = {0,1,-1,0};
void dfs(int x,int y,int dep,int path) {
	if (dep == 6) {
		if (!h[path]) {
			h[path] = true;
			cnt ++;
		}
	}
	else {
		for (int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
			dfs(nx,ny,dep+1,path*10 + g[x][y]);
		}
	}
}
int main() {
	for (int i=0;i<5;i++) for (int j=0;j<5;j++) scanf("%d",&g[i][j]);
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++) dfs(i,j,0,0);
	printf("%d\n",cnt);
	return 0;
}
